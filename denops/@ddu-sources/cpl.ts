import { BaseSource, Item } from "https://deno.land/x/ddu_vim@v3.2.7/types.ts";
import { Denops } from "https://deno.land/x/ddu_vim@v3.2.7/deps.ts";
import { join, resolve } from "https://deno.land/std@0.192.0/path/mod.ts";

type Params = Record<never, never>;

type LibraryItem = {
  name: string;
  path: string;
};

export type ActionData = {
  item: LibraryItem;
};

export class Source extends BaseSource<Params> {
  kind = "cpl";

  gather(args: {
    denops: Denops;
  }): ReadableStream<Item<ActionData>[]> {
    return new ReadableStream({
      async start(controller) {
        const root = resolve(await args.denops.call("cpl#lib_path") as string);
        const items: Item<ActionData>[] = [];
        try {
          for await (const entry of Deno.readDir(root)) {
            if (entry.isDirectory === false) continue;
            if (entry.name[0] === "_") continue;
            items.push({
              word: entry.name,
              action: {
                item: {
                  name: entry.name,
                  path: join(root, entry.name, "index.hpp"),
                },
              },
            });
          }
        } catch (e) {
          console.log(e);
        }
        controller.enqueue(items);
        controller.close();
      },
    });
  }

  params(): Params {
    return {};
  }
}
