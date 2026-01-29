from __future__ import annotations
import os, sys, shutil, time, json

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
sys.path.insert(0, PROJECT_ROOT)

from src.io_utils import write_text, write_json
from src.llm_client import llm_complete
from src.json_coerce import coerce_json
from src.pipeline import run_pipeline
from src.render import render_outputs_csv, render_transitions_txt


def abspath_from_cwd(p: str) -> str:
    return p if os.path.isabs(p) else os.path.abspath(p)

ORANGE = "\033[38;5;208m"
BOLD = "\033[1m"
DIM = "\033[2m"
RESET = "\033[0m"

def banner(export_dir: str, fsm_name: str) -> None:
    print(f"{ORANGE}{BOLD}FSM Agent REPL{RESET} {DIM}(auto-export ON){RESET}")
    print(f"{DIM}Scrivi la specifica in linguaggio naturale (multi-linea).{RESET}")
    print(f"{DIM}Comandi:{RESET}")
    print(f"{DIM}  .            => esegui generazione col testo scritto finora{RESET}")
    print(f"{DIM}  :q           => esci{RESET}")
    print(f"{DIM}  :name <nome> => cambia nome FSM per export{RESET}")
    print(f"{DIM}  :show        => mostra la spec bufferizzata{RESET}")
    print(f"{DIM}  :clear       => svuota buffer spec{RESET}")
    print("")
    print(f"{DIM}Export dir :{RESET} {export_dir}")
    print(f"{DIM}FSM name   :{RESET} {fsm_name}")
    print(f"{DIM}Suggerimento:{RESET} termina con '.' su una riga da sola.\n")

def main():
    EXPORT_DIR = os.environ.get("FSM_EXPORT_DIR", "fsm_gen/inputs")
    FSM_NAME = os.environ.get("FSM_NAME", "unnamed")

    prompts_dir = os.path.join(PROJECT_ROOT, "prompts")
    spec_path = os.path.join(PROJECT_ROOT, "data", "inbox", "spec.txt")
    out_prefix = os.path.join(PROJECT_ROOT, "data", "inbox", "out")

    banner(EXPORT_DIR, FSM_NAME)
    buf: list[str] = []

    def do_run(spec: str) -> None:
        nonlocal FSM_NAME
        write_text(spec_path, spec)
        print(f"\n{DIM}[run] Generazione...{RESET}\n")
        t0 = time.time()

        # Save stage1/2 raw for debug (manual, not required by pipeline)
        p1 = open(os.path.join(prompts_dir, "step1_extract_entities.txt"), "r", encoding="utf-8").read().replace("{{SPEC}}", spec)
        raw1 = llm_complete(p1)
        write_text(out_prefix + ".step1.raw.txt", raw1)
        try:
            entities = coerce_json(raw1)
            write_json(out_prefix + ".entities.json", entities)
        except Exception as e:
            write_text(out_prefix + ".entities_parse_error.txt", repr(e))

        # Run full pipeline (will re-run LLM calls, but keeps REPL simple)
        fsm = run_pipeline(spec_text=spec, prompts_dir=prompts_dir)
        write_json(out_prefix + ".fsm.json", fsm)
        write_text(out_prefix + ".txt", render_transitions_txt(fsm))
        write_text(out_prefix + ".csv", render_outputs_csv(fsm))

        export_dir_abs = abspath_from_cwd(EXPORT_DIR)
        os.makedirs(export_dir_abs, exist_ok=True)
        dst_txt = os.path.join(export_dir_abs, f"{FSM_NAME}.txt")
        dst_csv = os.path.join(export_dir_abs, f"{FSM_NAME}.csv")

        if not (fsm.get("transitions") or []):
            print(f"{ORANGE}{BOLD}[warn]{RESET} transitions è vuoto. Non esporto.")
            print(f"{DIM}Debug locali:{RESET}")
            print("  -", out_prefix + ".step1.raw.txt")
            print("  -", out_prefix + ".entities.json (se parsabile)")
            print("  -", out_prefix + ".fsm.json")
            print("  -", out_prefix + ".txt / .csv (vuoti)")
            print("")
            return

        shutil.copyfile(out_prefix + ".txt", dst_txt)
        shutil.copyfile(out_prefix + ".csv", dst_csv)

        dt = time.time() - t0
        print(f"{ORANGE}{BOLD}[done]{RESET} timing {dt:.2f}s")
        print(f"{DIM}Export:{RESET}")
        print("  -", dst_txt)
        print("  -", dst_csv)
        print("")

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
