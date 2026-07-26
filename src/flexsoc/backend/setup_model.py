"""Generate the editable model that owns FlexSoC vector tests."""

from __future__ import annotations

import argparse
import importlib.util
import re
from pathlib import Path
from textwrap import dedent
from typing import Any

try:
    import hjson  # type: ignore
except ImportError:  # pragma: no cover - uv sync installs it for normal use.
    hjson = None


WRITABLE_SWACCESS = {"rw", "wo", "w1c", "w1s", "rw1c", "rw1s", "rw0c", "rw0w1c"}


def _load_hjson(path: Path | None) -> dict[str, Any]:
    """Load a reggen HJSON file when it exists."""

    if path is None or not path.exists():
        return {}
    text = path.read_text(encoding="utf-8")
    if hjson is not None:
        return dict(hjson.loads(text))
    text = re.sub(r"([{,]\s*)([A-Za-z_]\w*)\s*:", r'\1"\2":', text)
    text = re.sub(r",\s*([}\]])", r"\1", text)
    return dict(__import__("ast").literal_eval(text))


def _clock(hj: dict[str, Any], reg: dict[str, Any]) -> str:
    """Return the clock name used in config.regs keys."""

    value = reg.get("clock") or reg.get("clk") or reg.get("clock_primary") or hj.get("clock_primary")
    if isinstance(value, dict):
        value = value.get("name")
    if isinstance(value, (list, tuple)):
        value = value[0] if value else None
    return str(value or "clk_i")


def _writable(reg: dict[str, Any]) -> bool:
    """Return true when software can write a register."""

    if str(reg.get("swaccess", "")).lower() in WRITABLE_SWACCESS:
        return True
    return any(
        str(field.get("swaccess", "")).lower() in WRITABLE_SWACCESS
        for field in reg.get("fields", []) or []
        if isinstance(field, dict)
    )


def _register_map(hjson_path: Path | None) -> dict[str, int]:
    """Extract clock-qualified writable register names and offsets."""

    hj = _load_hjson(hjson_path)
    regs: dict[str, int] = {}
    offset = 0
    for reg in hj.get("registers", []) or []:
        if not isinstance(reg, dict) or "name" not in reg:
            continue
        current = int(str(reg.get("offset", offset)), 0) if reg.get("offset") is not None else offset
        if _writable(reg):
            regs[f"{_clock(hj, reg)}.{str(reg['name']).upper()}"] = current
        offset = current + 4
    return regs


def _ports(rtl_dir: Path | None, top: str) -> tuple[list[str], list[str]]:
    """Parse simple scalar/vector DUT ports for generated vector examples."""

    if rtl_dir is None:
        return ["valid_i", "data_i", "coeff_i"], ["data_o", "valid_o"]
    path = rtl_dir / f"{top}.sv"
    if not path.exists():
        return ["valid_i", "data_i", "coeff_i"], ["data_o", "valid_o"]
    text = path.read_text(encoding="utf-8", errors="ignore")
    header = text.split(");", 1)[0]
    ins, outs = [], []
    for raw in header.splitlines():
        line = re.sub(r"//.*", "", raw).strip().rstrip(",")
        if not line.startswith(("input ", "output ")):
            continue
        direction = "input" if line.startswith("input ") else "output"
        body = line[len(direction) :].replace("logic", " ").replace("wire", " ").strip()
        body = re.sub(r"\[[^\]]+\]", " ", body)
        names = [name.strip() for name in body.split(",") if name.strip()]
        for name in names:
            if name in {"tl_i", "tl_o", "reg_req_i", "reg_rsp_o"} or "clk" in name or "rst" in name:
                continue
            (ins if direction == "input" else outs).append(name)
    return ins or ["valid_i", "data_i", "coeff_i"], outs or ["data_o", "valid_o"]


def _model_text(top: str, registers: dict[str, int], inputs: list[str], outputs: list[str]) -> str:
    """Render an editable model that writes config and vector files."""

    return dedent(
        f'''\
        """Editable FlexSoC reference model and vector generator for {top}.

        Edit this file for real IPs: Cordic, FFT, UART, custom accelerators, etc.
        The simulator never imports this model. It only consumes the files produced here:
        config.regs, data_in.vec, and data_out.vec.
        """

        from __future__ import annotations

        import random
        from pathlib import Path


        # ------------------------------------------------------------------
        # Test catalogue and generated interface metadata.
        # ------------------------------------------------------------------
        # TESTS controls which folders are created by `fx tests_gen`.
        TESTS = ("smoke", "corners", "random", "reconfig")
        # Create or rewrite one ad-hoc test with: fx test_gen --set TEST_NAME=my_case
        # Vector cycles describe when inputs are sampled; the starter core responds one cycle later.
        LATENCY = 1
        # REGISTERS is inferred from the HJSON regmap and used only to write config.regs.
        REGISTERS = {registers!r}
        # INPUTS and OUTPUTS are inferred from the generated top-level RTL.
        INPUTS = {inputs!r}
        OUTPUTS = {outputs!r}


        # ------------------------------------------------------------------
        # Small formatting helpers.
        # ------------------------------------------------------------------
        def hx(value: int) -> str:
            """Format one value as the 32-bit hexadecimal syntax used by vector files."""

            return f"0x{{value & 0xFFFFFFFF:08x}}"


        def has_reg(name: str) -> bool:
            """Return true when a clock-qualified register key exists in this IP regmap."""

            return name in REGISTERS


        # ------------------------------------------------------------------
        # Register configuration.
        # ------------------------------------------------------------------
        def config(test: str, phase: str = "initial") -> list[tuple[str, int]]:
            """Return the minimal register writes needed before or during one test.

            For large regmaps, keep this intentionally small: only write what the
            scenario needs. Runtime reconfiguration uses the same function with a
            different phase and is emitted as an @cfg row in data_in.vec.
            """

            mode = {{"smoke": 0, "corners": 1, "random": 2, "reconfig": 0}}.get(test, 0)
            if phase == "xor_mode":
                mode = 1
            rows = [
                ("clk_i.CTRL", 0x00000003),
                ("clk_i.MODE", mode),
                ("clk_i.OPERAND_A", 0x00000001),
                ("clk_i.OPERAND_B", 0x00000002),
                ("clk_i.SCALE", 0x00000001),
            ]
            return [(name, value) for name, value in rows if not REGISTERS or has_reg(name)]


        # ------------------------------------------------------------------
        # Input stimulus and reference behavior.
        # ------------------------------------------------------------------
        def stimulus(test: str) -> list[tuple[int, dict[str, int]]]:
            """Return cycle-indexed input transactions for data_in.vec.

            Each dictionary contains the signals driven together on that cycle.
            Add IP-specific inputs here for Cordic, FFT, UART, custom blocks, etc.
            Unknown ad-hoc test names intentionally fall back to the smoke pattern.
            """

            if test == "corners":
                values = [(0, 0, 1), (1, 0xFFFFFFFF, 1), (2, 0x80000000, 2), (3, 0x7FFFFFFF, 3)]
            elif test == "random":
                rng = random.Random("{top}:" + test)
                values = [(i, rng.getrandbits(16), rng.getrandbits(8)) for i in range(8)]
            elif test == "reconfig":
                values = [(0, 3, 1), (1, 4, 2), (5, 7, 3), (6, 8, 5)]
            else:
                values = [(0, 1, 1), (1, 4, 2), (2, 7, 3), (3, 8, 5)]
            return [(cycle, {{"valid_i": 1, "data_i": data, "coeff_i": coeff}}) for cycle, data, coeff in values]


        def mode_at(test: str, cycle: int) -> int:
            """Return the active MODE value used by expected() at one cycle."""

            if test == "corners":
                return 1
            if test == "random":
                return 2
            if test == "reconfig" and cycle >= 4:
                return 1
            return 0


        def expected(test: str, cycle: int, values: dict[str, int]) -> dict[str, int]:
            """Return expected outputs for one transaction.

            This is the main IP-specific reference function. For a Cordic, for
            example, this is where angle/vector math should be modeled.
            """

            data = values.get("data_i", 0)
            coeff = values.get("coeff_i", 0)
            mode = mode_at(test, cycle)
            if mode == 1:
                result = data ^ coeff
            elif mode == 2:
                result = data << 1
            else:
                result = data + coeff
            return {{"data_o": result, "valid_o": values.get("valid_i", 1)}}


        # ------------------------------------------------------------------
        # File writers. Simulators consume only the files produced below.
        # ------------------------------------------------------------------
        def write_config(path: Path, rows: list[tuple[str, int]]) -> None:
            """Write one config.regs file consumed by SV and cocotb register drivers."""

            lines = [
                "# format: <CLOCK.REG_NAME> <DATA> [MASK] [WAIT_CYCLES] [NOTE]",
                "# write is implicit; keep only the writes this test needs.",
            ]
            lines += [f"# map {{name}} 0x{{addr:08x}}" for name, addr in sorted(REGISTERS.items())]
            lines += [f"{{name}} {{hx(value)}}" for name, value in rows]
            path.write_text("\\n".join(lines) + "\\n", encoding="utf-8")


        def write_test(root: str | Path, test: str) -> None:
            """Write the complete folder for one TEST_NAME.

            Output layout:
              tb/tests/<test>/config.regs
              tb/tests/<test>/data_in.vec
              tb/tests/<test>/data_out.vec
            """

            folder = Path(root) / test
            folder.mkdir(parents=True, exist_ok=True)
            write_config(folder / "config.regs", config(test))

            data_in = [
                "# format: <CYCLE> <SIGNAL> <VALUE>",
                "# repeat the same CYCLE on multiple rows to drive signals together",
                "# config change: <CYCLE> @cfg <PATH_TO_CONFIG.REGS>",
            ]
            reconfig_path = None
            if test == "reconfig":
                reconfig_path = folder / "config_xor.regs"
                write_config(reconfig_path, config(test, "xor_mode"))

            data_out = [
                "# format: <CYCLE> <SIGNAL> <EXPECTED>",
                "# repeat the same CYCLE on multiple rows to check signals together",
            ]
            reconfigured = False
            for cycle, values in stimulus(test):
                if reconfig_path is not None and not reconfigured and cycle >= 4:
                    data_in.append(f"4 @cfg {{reconfig_path.resolve()}}")
                    reconfigured = True
                in_pairs = [(name, values[name]) for name in INPUTS if name in values]
                out_pairs = [(name, value) for name, value in expected(test, cycle, values).items() if name in OUTPUTS]
                for name, value in in_pairs:
                    data_in.append(f"{{cycle}} {{name}} {{hx(value)}}")
                for name, value in out_pairs:
                    data_out.append(f"{{cycle + LATENCY}} {{name}} {{hx(value)}}")

            (folder / "data_in.vec").write_text("\\n".join(data_in) + "\\n", encoding="utf-8")
            (folder / "data_out.vec").write_text("\\n".join(data_out) + "\\n", encoding="utf-8")


        def write_all_tests(root: str | Path, tests: list[str] | tuple[str, ...] | None = None) -> None:
            """Write requested tests, or every test listed in TESTS when omitted."""

            for test in (tests or TESTS):
                write_test(root, test)


        def main() -> int:
            """Command-line entry point used by setup_model to regenerate vectors."""

            import argparse
            parser = argparse.ArgumentParser(description="Generate FlexSoC vector tests from the editable model.")
            parser.add_argument("--tests-dir", default="../tb/tests")
            parser.add_argument("--test", action="append", default=[], help="Generate only this TEST_NAME. May be repeated.")
            parser.add_argument("--list", action="store_true", help="Print the TESTS catalogue and exit.")
            args = parser.parse_args()
            if args.list:
                for test in TESTS:
                    print(test)
                return 0
            write_all_tests(args.tests_dir, args.test or None)
            return 0


        if __name__ == "__main__":
            raise SystemExit(main())
        '''
    )


def write_model(top: str, output: Path, hjson_path: Path | None, rtl_dir: Path | None, *, force: bool) -> Path:
    """Create or preserve the editable model file."""

    output.mkdir(parents=True, exist_ok=True)
    path = output / f"model_{top}.py"
    if force or not path.exists():
        registers = _register_map(hjson_path)
        inputs, outputs = _ports(rtl_dir, top)
        path.write_text(_model_text(top, registers, inputs, outputs), encoding="utf-8")
    return path


def _load_model(path: Path):
    """Import the generated/editable model from its path."""

    spec = importlib.util.spec_from_file_location(path.stem, path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"cannot import model: {path}")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)  # type: ignore[union-attr]
    return module


def generate_tests(model_path: Path, tests_dir: Path) -> None:
    """Regenerate vector tests by calling the editable model."""

    model = _load_model(model_path)
    if not hasattr(model, "write_all_tests"):
        raise SystemExit(f"ERROR: {model_path} must define write_all_tests(root)")
    tests_dir.mkdir(parents=True, exist_ok=True)
    model.write_all_tests(tests_dir)


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    """Parse setup_model options."""

    parser = argparse.ArgumentParser(description="Generate an editable model scaffold.")
    parser.add_argument("--top", required=True)
    parser.add_argument("--output-dir", default="model")
    parser.add_argument("--tests-dir", default=None, help=argparse.SUPPRESS)
    parser.add_argument("--hjson", default=None)
    parser.add_argument("--rtl-dir", default=None)
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Write the editable model scaffold."""

    args = parse_args(argv)
    model_path = write_model(
        args.top,
        Path(args.output_dir),
        Path(args.hjson) if args.hjson else None,
        Path(args.rtl_dir) if args.rtl_dir else None,
        force=args.force,
    )
    # Vector tests are generated by running model_<top>.py via tests_gen/test_gen.
    print(f"Model: {model_path.resolve()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
