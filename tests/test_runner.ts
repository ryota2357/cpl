import { parse } from "https://deno.land/std@0.193.0/toml/mod.ts";
import { dirname, join } from "https://deno.land/std@0.192.0/path/mod.ts";
import { exists } from "https://deno.land/std@0.193.0/fs/mod.ts";
import { ensure, is } from "https://deno.land/x/unknownutil@v3.2.0/mod.ts";

const libPath = Deno.args[0];
const textDecoder = new TextDecoder("utf-8");
const __dirname = new URL("../", import.meta.url).pathname;

async function main() {
  for await (const entry of Deno.readDir(libPath)) {
    if (entry.isDirectory === false) continue;

    const info_toml = join(libPath, entry.name, "info.toml");
    if (!(await exists(info_toml))) {
      console.error(`Not found info.toml in ${entry.name}`);
      continue;
    }
    const info = parse(textDecoder.decode(await Deno.readFile(info_toml)));

    const name = ensure(info["name"], is.String);
    const tests = ensure(info["tests"], is.ArrayOf(is.RecordOf(is.String)));
    for (const test of tests) {
      const solver = join(dirname(info_toml), test["solver"]);
      const cases = join(
        __dirname,
        "tests",
        "cases",
        ...test["cases"].split("/"),
      );
      const checker = join(
        __dirname,
        "tests",
        "checker",
        `${test["checker"]}.rb`,
      );
      exec_checker(name, checker, solver, cases);
    }
  }
}

async function exec_checker(
  test_name: string,
  checker: string,
  solver_cpp: string,
  test_case_dir: string,
) {
  const compiler = "clang++ -std=c++17 -stdlib=libc++ -Wall -O2";
  const cache_dir = join(__dirname, ".cache");
  if (!(await exists(cache_dir))) {
    Deno.mkdir(cache_dir, { recursive: true });
  }

  const command = new Deno.Command("ruby", {
    args: [checker, cache_dir, compiler, test_name, solver_cpp, test_case_dir],
  });
  const { code, stdout, stderr } = await command.output();

  console.log(textDecoder.decode(stdout));
  if (code != 0) {
    console.error(textDecoder.decode(stderr));
    Deno.exit(1);
  }
}

await main();
