"""Generate the editable Python reference-model scaffold.

``setup_model`` creates two independent pieces:

* ``regmap_<top>.py``: generated CSR structure derived from HJSON;
* ``model_<top>.py``: editable behavioral stimulus/reference code.

The model can freely mix functional-port stimulus/checks with CSR-driven
stimulus/checks.  CSR serialization and field layout always come from the
regmap module; behavioral meaning stays in the model.
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path
from textwrap import dedent

from .setup_model_regmap import generate as generate_regmap


_IGNORED_PORTS = {"tl_i", "tl_o", "reg_req_i", "reg_rsp_o"}


def _ports(rtl_dir: Path | None, top: str) -> tuple[list[str], list[str]]:
    """Return non-infrastructure top-level inputs and outputs.

    Empty lists are intentional for CSR-only IPs.  The scaffold must not invent
    functional ports when the RTL exposes only a register/bus interface.
    """

    if rtl_dir is None:
        return [], []
    path = rtl_dir / f"{top}.sv"
    if not path.exists():
        return [], []

    text = path.read_text(encoding="utf-8", errors="ignore")
    header = text.split(");", 1)[0]
    inputs: list[str] = []
    outputs: list[str] = []

    for raw in header.splitlines():
        line = re.sub(r"//.*", "", raw).strip().rstrip(",")
        if not line.startswith(("input ", "output ")):
            continue
        direction = "input" if line.startswith("input ") else "output"
        body = line[len(direction) :].strip()
        body = re.sub(r"\b(?:logic|wire|reg|signed|unsigned)\b", " ", body)
        body = re.sub(r"\[[^\]]+\]", " ", body)

        for chunk in body.split(","):
            tokens = chunk.split()
            if not tokens:
                continue
            name = re.sub(r"\[[^\]]+\]$", "", tokens[-1])
            if name in _IGNORED_PORTS or "clk" in name.lower() or "rst" in name.lower():
                continue
            (inputs if direction == "input" else outputs).append(name)

    return inputs, outputs


def _model_text(top: str, inputs: list[str], outputs: list[str]) -> str:
    """Render a transport-neutral editable model scaffold.

    Each generated scenario owns three explicit sections: initial CSR config,
    input vectors, and output checks. The scaffold exercises both model
    transports when available: direct functional ports and generated CSR
    objects. The CSR probe is intentionally conservative and only uses fields
    that are software ``rw`` and hardware ``hro``.
    """

    return dedent(
        f'''\
        """Editable FlexSoC reference model and vector generator for {top}.

        Behavioral policy belongs here. Register names, offsets, field layouts,
        reset values and access modes belong to ``regmap_{top}.py`` and can be
        refreshed independently with ``fx regmap_py --force``.

        Every test is split explicitly into:

        * ``config``: initial CSR writes -> ``config.regs``;
        * ``data_in``: functional input drives and/or CSR ``@write`` rows;
        * ``data_out``: functional output checks and/or CSR ``@read`` rows.

        The starter scenarios intentionally exercise both transport types when
        the IP exposes them. Replace the generic 0/1 functional expectations
        with real IP behavior while keeping the same test structure.
        """

        from __future__ import annotations

        import random
        from dataclasses import dataclass
        from pathlib import Path

        import regmap_{top} as regmap


        TOP = {top!r}
        CSR = regmap.PRIMARY
        TESTS = ("smoke", "corners", "random", "reconfig")
        INPUTS = {tuple(inputs)!r}
        OUTPUTS = {tuple(outputs)!r}

        # Generic starter assumptions for direct functional ports. They keep
        # the scaffold executable but should be replaced with the IP's actual
        # idle/reset behavior when the model is specialized.
        INPUT_IDLE = {{name: 0 for name in INPUTS}}
        OUTPUT_IDLE = {{name: 0 for name in OUTPUTS}}


        @dataclass
        class TestCase:
            """All files generated for one named model scenario."""

            config: list[str]
            data_in: list[str]
            data_out: list[str]


        def hx(value: int) -> str:
            """Format one vector value as a 32-bit hexadecimal word."""

            return f"0x{{value & 0xFFFF_FFFF:08x}}"


        def drive(cycle: int, signal: str, value: int) -> str:
            """Format one direct DUT-input drive row."""

            if signal not in INPUTS:
                raise KeyError(f"unknown functional input {{signal!r}}; known: {{INPUTS}}")
            return f"{{cycle}} {{signal}} {{hx(value)}}"


        def check(cycle: int, signal: str, expected: int) -> str:
            """Format one direct DUT-output check row."""

            if signal not in OUTPUTS:
                raise KeyError(f"unknown functional output {{signal!r}}; known: {{OUTPUTS}}")
            return f"{{cycle}} {{signal}} {{hx(expected)}}"


        def drive_inputs(cycle: int, value: int | None = None) -> list[str]:
            """Drive every functional input at one cycle."""

            if value is None:
                return [drive(cycle, name, INPUT_IDLE[name]) for name in INPUTS]
            return [drive(cycle, name, value) for name in INPUTS]


        def check_outputs(cycle: int) -> list[str]:
            """Check every functional output against the starter idle value."""

            return [check(cycle, name, OUTPUT_IDLE[name]) for name in OUTPUTS]


        def csr_probe() -> tuple[regmap.Register, int] | None:
            """Return a conservative software-owned RW register and field mask.

            This lets a fresh scaffold demonstrate config writes plus vector
            writes/reads without hardcoding any register or field name. The
            selected bits are limited to HJSON fields with ``swaccess=rw`` and
            ``hwaccess=hro`` so hardware-owned status/result fields are avoided.
            """

            for register in CSR:
                fields = [
                    field
                    for field in register.fields
                    if field.swaccess == "rw" and field.hwaccess == "hro"
                ]
                if fields:
                    mask = 0
                    for field in fields:
                        mask |= field.mask
                    return register, mask & 0xFFFF_FFFF
            return None


        def csr_config() -> list[str]:
            """Return a safe starter ``config.regs`` write when one is available."""

            probe = csr_probe()
            if probe is None:
                return []
            register, mask = probe
            return [register.write(register.reset, mask=mask)]


        def csr_roundtrip(write_cycle: int, read_cycle: int) -> tuple[list[str], list[str]]:
            """Exercise generated CSR ``@write`` and ``@read`` serialization."""

            probe = csr_probe()
            if probe is None:
                return [], []
            register, mask = probe
            return (
                [register.vector_write(write_cycle, register.reset, mask=mask)],
                [register.vector_read(read_cycle, register.reset, mask=mask)],
            )


        def smoke_test() -> TestCase:
            """Basic functional-port + CSR transport smoke test."""

            config = csr_config()
            csr_in, csr_out = csr_roundtrip(4, 12)
            data_in = [
                *drive_inputs(0),
                *csr_in,
            ]
            data_out = [
                *check_outputs(12),
                *csr_out,
            ]
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def corners_test() -> TestCase:
            """Starter 0/1 functional corners plus a CSR write/read check."""

            config = csr_config()
            csr_in, csr_out = csr_roundtrip(20, 28)
            data_in = [
                *drive_inputs(0, 0),
                *drive_inputs(8, 1),
                *drive_inputs(16, 0),
                *csr_in,
            ]
            data_out = [
                *check_outputs(16),
                *csr_out,
            ]
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def random_test() -> TestCase:
            """Deterministic starter port stimulus plus CSR transport coverage."""

            config = csr_config()
            rng = random.Random(f"{{TOP}}:random")
            data_in: list[str] = []
            for cycle in range(0, 32, 8):
                for signal in INPUTS:
                    data_in.append(drive(cycle, signal, rng.getrandbits(1)))

            csr_in, csr_out = csr_roundtrip(36, 44)
            data_in.extend(csr_in)
            data_out = [
                *check_outputs(44),
                *csr_out,
            ]
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def reconfig_test() -> TestCase:
            """Show initial config plus runtime CSR reconfiguration in one test."""

            config = csr_config()
            first_in, first_out = csr_roundtrip(8, 16)
            second_in, second_out = csr_roundtrip(24, 32)
            data_in = [
                *drive_inputs(0),
                *first_in,
                *drive_inputs(20, 1),
                *second_in,
            ]
            data_out = [
                *first_out,
                *check_outputs(32),
                *second_out,
            ]
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def test_case(test: str) -> TestCase:
            """Build one named scenario with explicit config/in/out sections."""

            scenarios = {{
                "smoke": smoke_test,
                "corners": corners_test,
                "random": random_test,
                "reconfig": reconfig_test,
            }}
            try:
                return scenarios[test]()
            except KeyError as exc:
                raise ValueError(f"unknown test {{test!r}}; choose one of {{TESTS}}") from exc


        def write_test(root: str | Path, test: str) -> None:
            """Write ``config.regs``, ``data_in.vec`` and ``data_out.vec``."""

            case = test_case(test)
            folder = Path(root) / test
            folder.mkdir(parents=True, exist_ok=True)
            regmap.write_config(folder / "config.regs", case.config)

            data_in = [
                f"# {{TOP}}/{{test}} input stimulus: ports + CSR writes.",
                "# <cycle> <signal> <value> or <cycle> @write <reg> <value> [mask]",
                *case.data_in,
            ]
            data_out = [
                f"# {{TOP}}/{{test}} output checks: ports + CSR reads.",
                "# <cycle> <signal> <expected> or <cycle> @read <reg> <expected> [mask]",
                *case.data_out,
            ]
            (folder / "data_in.vec").write_text("\\n".join(data_in) + "\\n", encoding="utf-8")
            (folder / "data_out.vec").write_text("\\n".join(data_out) + "\\n", encoding="utf-8")


        def write_all_tests(
            root: str | Path,
            tests: list[str] | tuple[str, ...] | None = None,
        ) -> None:
            """Write requested tests, or every test listed in ``TESTS``."""

            for test in (tests or TESTS):
                write_test(root, test)


        def main() -> int:
            import argparse

            parser = argparse.ArgumentParser(
                description="Generate FlexSoC vector tests from the editable model."
            )
            parser.add_argument("--tests-dir", default="../tb/tests")
            parser.add_argument(
                "--test",
                action="append",
                default=[],
                help="Generate only this TEST_NAME. May be repeated.",
            )
            parser.add_argument(
                "--list",
                action="store_true",
                help="Print the TESTS catalogue and exit.",
            )
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

def write_model(
    top: str,
    output: Path,
    rtl_dir: Path | None,
    *,
    force: bool,
) -> Path:
    """Create or preserve the editable behavioral model file."""

    output.mkdir(parents=True, exist_ok=True)
    path = output / f"model_{top}.py"
    if force or not path.exists():
        inputs, outputs = _ports(rtl_dir, top)
        path.write_text(_model_text(top, inputs, outputs), encoding="utf-8")
    return path


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate an editable model scaffold.")
    parser.add_argument("--top", required=True)
    parser.add_argument("--output-dir", default="model")
    parser.add_argument("--data-dir", required=True)
    parser.add_argument("--rtl-dir", default=None)
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    output_dir = Path(args.output_dir)

    regmap_path = generate_regmap(
        args.top,
        Path(args.data_dir),
        output_dir,
        force=args.force,
    )
    model_path = write_model(
        args.top,
        output_dir,
        Path(args.rtl_dir) if args.rtl_dir else None,
        force=args.force,
    )
    print(f"Regmap: {regmap_path.resolve()}")
    print(f"Model:  {model_path.resolve()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
