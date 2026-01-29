from __future__ import annotations

import argparse
import os
import sys
import traceback

# Project root (…/fsm_agent) solo per imports e prompts
PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, PROJECT_ROOT)

from src.io_utils import read_text, write_text, write_json
from src.pipeline import run_end_to_end_debug
from src.llm_client import LLMClient
from src.auto_filter import infer_gold_filter
from src.gold_context import format_gold_context
from src.render import render_outputs_csv, render_transitions_only

def abs_from_cwd(p: str) -> str:
    # Se relativo, è relativo alla cartella da cui lanci (es. root flexsoc)
    return p if os.path.isabs(p) else os.path.abspath(p)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--spec", required=True, help="path spec NL (relativo alla cwd o assoluto)")
    ap.add_argument("--out_prefix", default="fsm_agent/data/inbox/out",
                    help="prefix output (relativo alla cwd o assoluto)")
    ap.add_argument("--use_gold_as_context", type=int, default=6)
    ap.add_argument("--gold_char_budget", type=int, default=12000)
    ap.add_argument("--gold_filter", type=str, default="")
    ap.add_argument("--auto_gold_filter", action="store_true")
    ap.add_argument("--auto_gold_rank", action="store_true")
    args = ap.parse_args()

    spec_path = abs_from_cwd(args.spec)
    out_prefix = abs_from_cwd(args.out_prefix)

    extract_prompt_path = os.path.join(PROJECT_ROOT, "prompts", "extract_json.txt")
    fix_prompt_path = os.path.join(PROJECT_ROOT, "prompts", "fix_from_errors.txt")

    spec_text = read_text(spec_path)

    gold_filter = args.gold_filter.strip() or None
    auto_rank = False

    if gold_filter is None and args.auto_gold_filter:
        inferred = infer_gold_filter(spec_text)
        gold_filter = inferred or None
        print("AUTO gold_filter =", gold_filter or "(nessuno)")

    if gold_filter is None and args.auto_gold_rank:
        auto_rank = True
        print("AUTO gold_rank = BM25 (locale)")

    llm = LLMClient()

    try:
        fsm_json, fsm, text, errors, last_prompt, last_raw = run_end_to_end_debug(
            spec_text=spec_text,
            extract_prompt_path=extract_prompt_path,
            fix_prompt_path=fix_prompt_path,
            max_fix_iters=3,
            llm=llm,
            use_gold_as_context=args.use_gold_as_context,
            gold_filter=gold_filter,
            auto_gold_rank=auto_rank,
            gold_char_budget=args.gold_char_budget,
        )

        write_json(out_prefix + ".json", fsm_json)
        write_text(out_prefix + ".fsm.txt", text)
        write_text(out_prefix + ".transitions.txt", render_transitions_only(fsm))
        write_text(out_prefix + ".outputs.csv", render_outputs_csv(fsm))

        if errors:
            write_text(out_prefix + ".errors.txt", "\n".join(errors))
            print("Generato con errori. Vedi:", out_prefix + ".errors.txt")
        else:
            print("OK.")

        print("Local outputs:")
        print("  -", out_prefix + ".fsm.txt")
        print("  -", out_prefix + ".transitions.txt")
        print("  -", out_prefix + ".outputs.csv")
        print("  -", out_prefix + ".json")

    except Exception as e:
        out_prompt = out_prefix + ".last_prompt.txt"
        out_raw = out_prefix + ".raw_llm.txt"
        out_err = out_prefix + ".parse_error.txt"

        try:
            gold_context = format_gold_context(
                args.use_gold_as_context,
                gold_filter=gold_filter,
                auto_rank=auto_rank,
                rank_query=spec_text,
                char_budget=args.gold_char_budget,
            )
            template = read_text(extract_prompt_path)
            prompt = template.replace("{{SPEC}}", spec_text).replace("{{GOLD_CONTEXT}}", gold_context)
            write_text(out_prompt, prompt)
        except Exception:
            write_text(out_prompt, "SPEC:\n" + spec_text)

        write_text(out_raw, "Raw LLM non disponibile in questo handler.\n")
        err_text = "EXCEPTION:\n" + repr(e) + "\n\nTRACEBACK:\n" + traceback.format_exc()
        write_text(out_err, err_text)

        print("Errore durante generazione/parsing.")
        print("Debug salvato in:")
        print(" -", out_prompt)
        print(" -", out_raw)
        print(" -", out_err)
        raise

if __name__ == "__main__":
    main()
