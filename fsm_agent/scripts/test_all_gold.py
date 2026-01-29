from __future__ import annotations
import glob
from src.validate import load_fsm_json, validate_fsm_object, validate_rendered_text
from src.render import render_fsm_text

def main():
    json_files = sorted(glob.glob("data/gold/json/*.json"))
    any_fail = False
    for jf in json_files:
        name = jf.split("/")[-1].replace(".json","")
        fsm = load_fsm_json(jf)
        obj_err = validate_fsm_object(fsm)
        text = render_fsm_text(fsm)
        txt_err = validate_rendered_text(text, fsm.states)
        errs = obj_err + txt_err
        if errs:
            any_fail = True
            print(f"[FAIL] {name}")
            for e in errs:
                print("  -", e)
        else:
            print(f"[OK]   {name}")
    if any_fail:
        raise SystemExit(1)

if __name__ == "__main__":
    main()
