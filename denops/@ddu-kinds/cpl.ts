import {
  ActionFlags,
  Actions,
  BaseKind,
  DduItem,
} from "https://deno.land/x/ddu_vim@v2.8.4/types.ts";
import { Denops, fn } from "https://deno.land/x/ddu_vim@v2.8.4/deps.ts";
import { ActionData } from "../@ddu-sources/cpl.ts";

type Params = Record<never, never>;

export class Kind extends BaseKind<Params> {
  actions: Actions<Params> = {
    paste: async (args: { denops: Denops; items: DduItem[] }) => {
      const action = args.items[0]?.action as ActionData;
      const text = (await Deno.readTextFile(action.item.path)).split("\n");
      let start = 0, end = text.length;
      for (let i = 0; i < text.length; i++) {
        const line = text[i].replace(/ /g, "");
        if (line === "//[START]") start = i + 1;
        if (line === "//[END]") end = i;
      }
      const line = await fn.line(args.denops, ".");
      fn.append(args.denops, line, [...text.slice(start, end), ""]);
      return ActionFlags.None;
    },
  };

  params(): Params {
    return {};
  }
}
