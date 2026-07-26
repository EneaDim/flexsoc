#!/usr/bin/env python3
"""Generate the regmap helper imported by editable model scaffolds."""
from __future__ import annotations

import argparse
import re
from pathlib import Path


def _strip_comments(text: str) -> str:
    """Remove simple HJSON comments before lightweight name extraction."""
    out: list[str] = []
    for line in text.splitlines():
        line = re.sub(r"//.*$", "", line)
        line = re.sub(r"#.*$", "", line)
        out.append(line)
    return "\n".join(out)


def _register_names(path: Path) -> list[str]:
    """Extract register names from an HJSON-like file."""
    text = _strip_comments(path.read_text(encoding="utf-8"))
    names: list[str] = []
    for match in re.finditer(r"name\s*:\s*[\"']?([A-Za-z_][A-Za-z0-9_]*)", text):
        name = match.group(1).upper()
        if name not in {"RESERVED", "SKIPTO"} and name not in names:
            names.append(name)
    return names


def _regmaps(top: str, data_dir: Path, multi: bool) -> dict[str, list[str]]:
    """Return domain-to-register-name mappings."""
    if multi:
        maps: dict[str, list[str]] = {}
        for hjson in sorted(data_dir.glob(f"{top}_*.hjson")):
            domain = hjson.stem[len(top) + 1 :]
            maps[domain] = _register_names(hjson)
        return maps or {"cfg": [], "dsp": []}
    hjson = data_dir / f"{top}.hjson"
    return {"clk_i": _register_names(hjson) if hjson.exists() else []}


def _helper_text(top: str, maps: dict[str, list[str]], multi: bool) -> str:
    """Render helper Python source used by editable models."""
    default_domain = next(iter(maps), "clk_i")
    title = f"model_{top}_multiclock.py" if multi else f"model_{top}.py"
    return "\n".join([
        f"# Generated register helper for {title}.",
        "# Regenerate with setup_model/setup_model_multi after HJSON changes.",
        "from __future__ import annotations",
        "",
        "from dataclasses import dataclass",
        "from pathlib import Path",
        "",
        f"REGMAPS: dict[str, list[str]] = {maps!r}",
        f"DEFAULT_DOMAIN = {default_domain!r}",
        "",
        "@dataclass(frozen=True)",
        "class RegRef:",
        "    \"\"\"Reference one register by domain and name.\"\"\"",
        "",
        "    domain: str",
        "    name: str",
        "",
        "    @property",
        "    def path(self) -> str:",
        "        \"\"\"Return the config.regs path syntax.\"\"\"",
        "        return f\"{self.domain}.{self.name}\"",
        "",
        "def reg(name: str, domain: str | None = None) -> RegRef:",
        "    \"\"\"Return a checked register reference.\"\"\"",
        "    chosen = domain or (name.split(\".\", 1)[0] if \".\" in name else DEFAULT_DOMAIN)",
        "    reg_name = name.split(\".\", 1)[1] if \".\" in name else name",
        "    reg_name = reg_name.upper()",
        "    known = REGMAPS.get(chosen, [])",
        "    if known and reg_name not in known:",
        "        raise KeyError(f\"unknown register {chosen}.{reg_name}; known={known}\")",
        "    return RegRef(chosen, reg_name)",
        "",
        "def write(name: str, value: int, domain: str | None = None) -> str:",
        "    \"\"\"Return one config.regs write row.\"\"\"",
        "    ref = reg(name, domain)",
        "    return f\"{ref.path} 0x{value & 0xFFFFFFFF:08x}\"",
        "",
        "def expect(name: str, value: int, domain: str | None = None) -> str:",
        "    \"\"\"Return one config.regs read/check row.\"\"\"",
        "    ref = reg(name, domain)",
        "    return f\"expect {ref.path} 0x{value & 0xFFFFFFFF:08x}\"",
        "",
        "def write_config(path: str | Path, rows: list[str]) -> None:",
        "    \"\"\"Write config.regs rows with a stable header.\"\"\"",
        "    out = Path(path)",
        "    out.parent.mkdir(parents=True, exist_ok=True)",
        "    body = \"# format: <REG> <VALUE> or expect <REG> <VALUE>\\n\"",
        "    out.write_text(body + \"\\n\".join(rows) + \"\\n\", encoding=\"utf-8\")",
        "",
    ])


def _insert_import(model: Path, top: str, multi: bool) -> None:
    """Import the generated helper from an editable model when possible."""
    if not model.exists():
        return
    text = model.read_text(encoding="utf-8")
    helper = f"regmap_{top}"
    if f"from {helper} import" in text:
        return
    block = f"\n# Generated regmap helper from HJSON.\nfrom {helper} import REGMAPS, expect, reg, write, write_config\n"
    marker = "from pathlib import Path\n"
    text = text.replace(marker, marker + block, 1) if marker in text else block.lstrip() + "\n" + text
    model.write_text(text, encoding="utf-8")


def generate(top: str, data_dir: Path, model_dir: Path, multi: bool, force: bool) -> Path:
    """Generate regmap_<top>.py and import it from the editable model."""
    model_dir.mkdir(parents=True, exist_ok=True)
    helper = model_dir / f"regmap_{top}.py"
    if helper.exists() and not force:
        return helper
    helper.write_text(_helper_text(top, _regmaps(top, data_dir, multi), multi), encoding="utf-8")
    model_name = f"model_{top}_multiclock.py" if multi else f"model_{top}.py"
    _insert_import(model_dir / model_name, top, multi)
    print(helper.resolve())
    return helper


def main(argv: list[str] | None = None) -> int:
    """Command-line entry point."""
    parser = argparse.ArgumentParser(description="Generate model regmap helper from HJSON.")
    parser.add_argument("--top", required=True)
    parser.add_argument("--data-dir", required=True)
    parser.add_argument("--model-dir", required=True)
    parser.add_argument("--multi", action="store_true")
    parser.add_argument("--force", action="store_true")
    args = parser.parse_args(argv)
    generate(args.top, Path(args.data_dir), Path(args.model_dir), args.multi, args.force)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
