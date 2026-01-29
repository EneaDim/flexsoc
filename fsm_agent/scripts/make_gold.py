from __future__ import annotations
import argparse
import shutil
from pathlib import Path

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", required=True, help="nome golden, es fsm_002")
    ap.add_argument("--nl", required=True, help="path NL spec")
    ap.add_argument("--json", required=True, help="path JSON canonico")
    ap.add_argument("--fsm", required=True, help="path FSM text finale")
    args = ap.parse_args()

    Path("data/gold/nl").mkdir(parents=True, exist_ok=True)
    Path("data/gold/json").mkdir(parents=True, exist_ok=True)
    Path("data/gold/fsm").mkdir(parents=True, exist_ok=True)

    shutil.copyfile(args.nl, f"data/gold/nl/{args.name}.txt")
    shutil.copyfile(args.json, f"data/gold/json/{args.name}.json")
    shutil.copyfile(args.fsm, f"data/gold/fsm/{args.name}.txt")

    print("Creato golden:", args.name)

if __name__ == "__main__":
    main()
