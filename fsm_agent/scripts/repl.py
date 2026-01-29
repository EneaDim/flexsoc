from __future__ import annotations

import os
import sys
import shutil
import time
from typing import Optional

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, PROJECT_ROOT)

from src.io_utils import write_text, write_json
from src.pipeline import run_end_to_end_debug
from src.llm_client import LLMClient
from src.render import render_outputs_csv, render_transitions_only


def abspath_from_cwd(p: str) -> str:
    # export_dir deve essere relativo alla cwd (cioè dove lanci make)
    return p if os.path.isabs(p) else os.path.abspath(p)


def main():
    # FAST defaults per REPL (non dipendono da env, ma puoi sovrascrivere se vuoi)
    USE_GOLD = int(os.environ.get("FSM_USE_GOLD", "2"))          # REPL veloce: 0 golden
    GOLD_BUDGET = int(os.environ.get("FSM_GOLD_BUDGET", "4096")) # irrilevante se USE_GOLD=0
    AUTO_RANK = os.environ.get("FSM_AUTO_RANK", "0") == "1"      # REPL veloce: no ranking
    MAX_FIX_ITERS = int(os.environ.get("FSM_MAX_FIX_ITERS", "2"))# REPL veloce: fail-fast (1 chiamata LLM)

    # Export (AUTO)
    EXPORT_DIR = os.environ.get("FSM_EXPORT_DIR", "fsm_gen/inputs")
    FSM_NAME = os.environ.get("FSM_NAME", "unnamed")

    extract_prompt_path = os.path.join(PROJECT_ROOT, "prompts", "extract_json.txt")
    fix_prompt_path = os.path.join(PROJECT_ROOT, "prompts", "fix_from_errors.txt")

    spec_path = os.path.join(PROJECT_ROOT, "data", "inbox", "spec.txt")
    out_prefix = os.path.join(PROJECT_ROOT, "data", "inbox", "out")

    llm = LLMClient()

    print("FSM Agent REPL (auto-export ON)")
    print("Scrivi la specifica in linguaggio naturale (multi-linea).")
    print("Comandi:")
    print("  .                => esegui generazione col testo scritto finora")
    print("  :q               => esci")
    print("  :name <nome>     => cambia nome FSM per export")
    print("  :show            => mostra la spec bufferizzata")
    print("  :clear           => svuota buffer spec")
    print("")
    print(f"Export dir     : {EXPORT_DIR}")
    print(f"FSM name       : {FSM_NAME}")
    print(f"REPL config    : USE_GOLD={USE_GOLD} AUTO_RANK={int(AUTO_RANK)} MAX_FIX_ITERS={MAX_FIX_ITERS}")
    print("Suggerimento: termina con '.' su una riga da sola.\n")

    buf: list[str] = []

    def do_run(spec: str) -> None:
        nonlocal FSM_NAME

        # salva spec
        write_text(spec_path, spec)

        print("\n[run] Generazione...\n")
        t0 = time.time()

        last_prompt: Optional[str] = None
        last_raw: Optional[str] = None

        try:
            fsm_json, fsm, text, errors, last_prompt, last_raw = run_end_to_end_debug(
                spec_text=spec,
                extract_prompt_path=extract_prompt_path,
                fix_prompt_path=fix_prompt_path,
                max_fix_iters=MAX_FIX_ITERS,
                llm=llm,
                use_gold_as_context=USE_GOLD,
                gold_filter=None,
                auto_gold_rank=AUTO_RANK,
                gold_char_budget=GOLD_BUDGET,
            )

            # scrivi output locali
            write_json(out_prefix + ".json", fsm_json)
            write_text(out_prefix + ".fsm.txt", text)
            write_text(out_prefix + ".outputs.csv", render_outputs_csv(fsm))
            write_text(out_prefix + ".transitions.txt", render_transitions_only(fsm))

            if errors:
                write_text(out_prefix + ".errors.txt", "\n".join(errors))
                print("[done] Generato con errori:", out_prefix + ".errors.txt")
            else:
                print("[done] OK")

            # AUTO-EXPORT (nomi richiesti: <FSM_NAME>.txt e <FSM_NAME>.csv)
            export_dir_abs = abspath_from_cwd(EXPORT_DIR)
            os.makedirs(export_dir_abs, exist_ok=True)

            dst_trans = os.path.join(export_dir_abs, f"{FSM_NAME}.txt")
            dst_outs = os.path.join(export_dir_abs, f"{FSM_NAME}.csv")

            shutil.copyfile(out_prefix + ".transitions.txt", dst_trans)
            shutil.copyfile(out_prefix + ".outputs.csv", dst_outs)

            dt = time.time() - t0
            print(f"\n[timing] {dt:.2f}s\n")

            print("Local:")
            print("  -", out_prefix + ".fsm.txt")
            print("  -", out_prefix + ".outputs.csv")
            print("  -", out_prefix + ".transitions.txt")
            print("Export:")
            print("  -", dst_trans)
            print("  -", dst_outs)
            print("")

        except Exception as e:
            # debug
            write_text(out_prefix + ".last_prompt.txt", last_prompt or "")
            write_text(out_prefix + ".raw_llm.txt", last_raw or "")
            write_text(out_prefix + ".parse_error.txt", repr(e))

            dt = time.time() - t0
            print(f"[fail] errore: {repr(e)}")
            print(f"[timing] {dt:.2f}s")
            print("Debug:")
            print("  -", out_prefix + ".last_prompt.txt")
            print("  -", out_prefix + ".raw_llm.txt")
            print("  -", out_prefix + ".parse_error.txt\n")

    while True:
        try:
            line = input("> ")
        except EOFError:
            print()
            break

        s = line.strip()

        if s == ":q":
            break

        if s == ":show":
            print("\n--- SPEC BUFFER ---")
            print("\n".join(buf) if buf else "(vuoto)")
            print("--- END ---\n")
            continue

        if s == ":clear":
            buf = []
            print("(buffer svuotato)\n")
            continue

        if s.startswith(":name"):
            parts = s.split(maxsplit=1)
            if len(parts) == 2 and parts[1].strip():
                FSM_NAME = parts[1].strip()
                print(f"(FSM_NAME = {FSM_NAME})\n")
            else:
                print("(uso: :name my_fsm)\n")
            continue

        if s == ".":
            spec = "\n".join(buf).strip()
            buf = []
            if not spec:
                print("(spec vuota)\n")
                continue
            do_run(spec)
            continue

        buf.append(line)

    print("bye")


if __name__ == "__main__":
    main()

