from __future__ import annotations
import argparse
from src.io_utils import read_text, write_text
from src.gold_context import format_gold_context
from src.auto_filter import infer_gold_filter

def fill_template(template: str, **kwargs) -> str:
    out = template
    for k, v in kwargs.items():
        out = out.replace("{{" + k + "}}", v)
    return out

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--spec", required=True, help="path spec NL, es data/inbox/spec.txt")
    ap.add_argument("--prompt_template", default="prompts/extract_json.txt", help="template prompt")
    ap.add_argument("--use_gold_as_context", type=int, default=0, help="max golden da includere")
    ap.add_argument("--gold_char_budget", type=int, default=12000, help="budget caratteri per golden (0=disabilita)")
    ap.add_argument("--gold_filter", type=str, default="", help="keyword manuali (override)")
    ap.add_argument("--auto_gold_filter", action="store_true", help="inferisci keyword dalla spec")
    ap.add_argument("--auto_gold_rank", action="store_true", help="ordina golden per BM25 sulla spec")
    ap.add_argument("--out", default="", help="se dato, salva il prompt su file")
    args = ap.parse_args()

    spec_text = read_text(args.spec)
    template = read_text(args.prompt_template)

    gold_filter = args.gold_filter.strip() or None
    auto_rank = False

    if gold_filter is None and args.auto_gold_filter:
        inferred = infer_gold_filter(spec_text)
        gold_filter = inferred or None
        if gold_filter:
            print("AUTO gold_filter =", gold_filter)
        else:
            print("AUTO gold_filter = (nessuno)")

    if gold_filter is None and args.auto_gold_rank:
        auto_rank = True
        print("AUTO gold_rank = BM25 (locale)")

    gold_context = format_gold_context(
        limit=args.use_gold_as_context,
        gold_filter=gold_filter,
        auto_rank=auto_rank,
        rank_query=spec_text,
        char_budget=args.gold_char_budget,
    )

    prompt = fill_template(template, SPEC=spec_text, GOLD_CONTEXT=gold_context)

    if args.out:
        write_text(args.out, prompt)
        print("Prompt salvato in:", args.out)
    else:
        print(prompt)

if __name__ == "__main__":
    main()
