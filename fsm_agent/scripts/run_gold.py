from __future__ import annotations
import argparse
from src.validate import load_fsm_json, validate_fsm_object, validate_rendered_text
from src.render import render_fsm_text

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--name", required=True, help="es: example_001 (senza estensione)")
    args = ap.parse_args()

    json_path = f"data/gold/json/{args.name}.json"
    fsm = load_fsm_json(json_path)

    obj_errors = validate_fsm_object(fsm)
    text = render_fsm_text(fsm)
    txt_errors = validate_rendered_text(text, fsm.states)

    print(text)
    if obj_errors or txt_errors:
        print("\nVALIDATION_ERRORS:")
        for e in obj_errors + txt_errors:
            print("-", e)

if __name__ == "__main__":
    main()
