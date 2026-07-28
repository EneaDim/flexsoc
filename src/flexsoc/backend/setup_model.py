"""Generate the single-clock Python model scaffold.

``setup_model`` creates three independent files in ``model/``:

* ``<top>_model.py``: editable behavioral reference model for the RTL;
* ``<top>_regmap.py``: generated CSR metadata/API derived from HJSON;
* ``<top>_tests.py``: editable test catalogue and vector generator.

The split is intentional. Behavioral changes belong in the model, register-layout
changes are refreshed with ``fx regmap_py --force``, and new verification
scenarios can be added to the tests file without changing the behavioral model.
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

    Empty lists are intentional for CSR-only IPs. The generated scaffold must
    not invent functional ports when the RTL exposes only a register/bus
    interface.
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


def _default_pipeline_map(inputs: list[str], outputs: list[str]) -> dict[str, str]:
    """Infer conservative passthrough pairs from matching ``*_i``/``*_o`` names."""

    known_inputs = set(inputs)
    pairs: dict[str, str] = {}
    for output in outputs:
        if not output.endswith("_o"):
            continue
        candidate = f"{output[:-2]}_i"
        if candidate in known_inputs:
            pairs[output] = candidate
    return pairs


def _is_starter_rtl(inputs: list[str], outputs: list[str]) -> bool:
    """Return true for the functional interface emitted by ``rtl_stub_gen``."""

    return {"data_i", "coeff_i", "valid_i"}.issubset(inputs) and {
        "data_o",
        "valid_o",
    }.issubset(outputs)


def _model_text(top: str, inputs: list[str], outputs: list[str]) -> str:
    """Render the editable behavioral-model scaffold."""

    pipeline_map = _default_pipeline_map(inputs, outputs)
    starter_rtl = _is_starter_rtl(inputs, outputs)
    latency = 2 if starter_rtl else 1

    return dedent(
        f'''\
        """Editable behavioral reference model for {top}.

        This file models what the RTL does. Keep test selection, vector-file
        formatting and CSR layout out of this module; those belong in
        ``{top}_tests.py`` and ``{top}_regmap.py`` respectively.

        ``ReferenceModel.compute()`` models the functional transformation of one
        accepted transaction. ``LATENCY`` describes the default fixed pipeline
        delay used by the generated tests. Stateful models may keep internal
        state, while protocol-driven models can replace this simple contract.
        """

        from __future__ import annotations

        TOP = {top!r}
        INPUTS = {tuple(inputs)!r}
        OUTPUTS = {tuple(outputs)!r}

        # Fixed-latency contract used by the generated tests. The default
        # from-scratch RTL stub has two registered pipeline stages.
        LATENCY = {latency}

        # True when this model was generated for the standard ``rtl_stub``
        # interface. Other/custom interfaces fall back to conservative
        # ``*_i`` -> ``*_o`` passthrough pairs until specialized.
        STARTER_RTL = {starter_rtl!r}
        PIPELINE_MAP = {pipeline_map!r}


        class ReferenceModel:
            """Behavioral reference for one RTL transaction."""

            def __init__(self, *, enabled: bool = True, mode: int = 0, scale: int = 0):
                self.enabled = bool(enabled)
                self.mode = int(mode) & 0x3
                self.scale = int(scale) & 0x1F

            def reset(self) -> None:
                """Restore the starter RTL's model-side configuration defaults."""

                self.enabled = True
                self.mode = 0
                self.scale = 0

            def compute(self, inputs: dict[str, int]) -> dict[str, int]:
                """Return the transaction result before pipeline delay is applied.

                For the standard from-scratch RTL scaffold this mirrors
                ``rtl_stub_gen``: MODE 0 adds, MODE 1 XORs, MODE 2 shifts, and
                MODE 3 passes ``data_i`` through. ``CTRL.EN`` gates both the
                result and ``valid_o``. ``{top}_tests.py`` checks the returned
                outputs at ``drive_cycle + LATENCY``.

                Custom interfaces use the conservative ``PIPELINE_MAP`` until
                this model is specialized for the real RTL behavior.
                """

                unknown = set(inputs) - set(INPUTS)
                if unknown:
                    raise KeyError(f"unknown functional input(s): {{sorted(unknown)}}")

                if STARTER_RTL:
                    data = int(inputs.get("data_i", 0)) & 0xFFFF_FFFF
                    coeff = int(inputs.get("coeff_i", 0)) & 0xFFFF_FFFF
                    valid = int(inputs.get("valid_i", 0)) & 0x1
                    if self.mode == 0:
                        result = data + coeff
                    elif self.mode == 1:
                        result = data ^ coeff
                    elif self.mode == 2:
                        result = data << self.scale
                    else:
                        result = data
                    if not self.enabled:
                        result = 0
                    return {{
                        "data_o": result & 0xFFFF_FFFF,
                        "valid_o": valid & int(self.enabled),
                    }}

                return {{
                    output: inputs[source]
                    for output, source in PIPELINE_MAP.items()
                }}
        '''
    )


def _tests_text(top: str) -> str:
    """Render the editable test-catalogue/vector-generator scaffold."""

    return dedent(
        f'''\
        """Editable FlexSoC test catalogue and vector generator for {top}.

        Keep each scenario here as three explicit sections:

        * ``config`` -> initial CSR writes in ``config.regs``;
        * ``data_in`` -> functional input drives and/or CSR ``@write`` rows;
        * ``data_out`` -> functional output checks and/or CSR ``@read`` rows.

        Add or change tests in this file without modifying ``{top}_model.py``.
        Register names, fields, offsets and masks come only from
        ``{top}_regmap.py`` and can be refreshed with ``fx regmap_py --force``.
        """

        from __future__ import annotations

        import argparse
        import random
        from dataclasses import dataclass
        from pathlib import Path

        import {top}_model as model
        import {top}_regmap as regmap


        TOP = {top!r}
        CSR = regmap.PRIMARY
        TESTS = ("smoke", "corners", "random", "reconfig")
        INPUTS = model.INPUTS
        OUTPUTS = model.OUTPUTS


        @dataclass
        class TestCase:
            """All generated rows for one named test."""

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
            """Format one fixed-cycle DUT-output check row."""

            if signal not in OUTPUTS:
                raise KeyError(f"unknown functional output {{signal!r}}; known: {{OUTPUTS}}")
            return f"{{cycle}} {{signal}} {{hx(expected)}}"


        def check_when_valid(valid_signal: str, expected: dict[str, int]) -> str:
            """Format one event-driven output check guarded by ``valid_signal``.

            The first token replaces the numeric cycle in ``data_out.vec``.
            When that DUT output is high, the monitor consumes this row and
            checks every signal/value pair in ``expected`` on the same cycle.

            Example::

                data_valid_o data_o 0x0000002a

            The starter tests below intentionally use fixed ``LATENCY`` checks;
            this helper is ready for designs whose completion time is signaled
            by a valid output instead.
            """

            if valid_signal not in OUTPUTS:
                raise KeyError(
                    f"unknown valid output {{valid_signal!r}}; known: {{OUTPUTS}}"
                )
            unknown = set(expected) - set(OUTPUTS)
            if unknown:
                raise KeyError(f"unknown functional output(s): {{sorted(unknown)}}")
            if not expected:
                raise ValueError("event-driven check requires at least one output")
            pairs = " ".join(
                f"{{name}} {{hx(value)}}" for name, value in expected.items()
            )
            return f"{{valid_signal}} {{pairs}}"


        def functional_transaction(
            reference: model.ReferenceModel,
            *,
            drive_cycle: int,
            value: int,
        ) -> tuple[list[str], list[str]]:
            """Drive one transaction and check it after ``model.LATENCY`` cycles."""

            inputs = {{name: value for name in INPUTS}}
            outputs = reference.compute(inputs)
            data_in = [drive(drive_cycle, name, item) for name, item in inputs.items()]
            check_cycle = drive_cycle + model.LATENCY
            data_out = [
                check(check_cycle, name, outputs[name])
                for name in OUTPUTS
                if name in outputs
            ]
            return data_in, data_out


        def functional_transaction_when_valid(
            reference: model.ReferenceModel,
            *,
            drive_cycle: int,
            value: int,
            valid_signal: str,
        ) -> tuple[list[str], list[str]]:
            """Alternative event-driven transaction helper.

            Use this instead of ``functional_transaction`` when the DUT exposes
            a completion/valid output and latency is not fixed.
            """

            inputs = {{name: value for name in INPUTS}}
            outputs = reference.compute(inputs)
            data_in = [drive(drive_cycle, name, item) for name, item in inputs.items()]
            checks = {{name: value for name, value in outputs.items() if name != valid_signal}}
            data_out = [check_when_valid(valid_signal, checks)] if checks else []
            return data_in, data_out


        def _software_fields(register: regmap.Register) -> list[regmap.Field]:
            """Return software-owned RW fields safe for scaffold CSR examples."""

            return [
                field
                for field in register.fields
                if field.swaccess == "rw" and field.hwaccess == "hro"
            ]


        def csr_probe() -> tuple[regmap.Register, int] | None:
            """Return a conservative RW register for write/read transport checks.

            Prefer a register other than CTRL so an unrelated roundtrip does
            not disable or clear the generated datapath before functional checks.
            """

            candidates = [register for register in CSR if _software_fields(register)]
            candidates.sort(key=lambda register: register.name == "CTRL")
            for register in candidates:
                mask = 0
                for field in _software_fields(register):
                    mask |= field.mask
                return register, mask & 0xFFFF_FFFF
            return None


        def csr_config() -> list[str]:
            """Configure the starter datapath and demonstrate config.regs writes."""

            if CSR.has("CTRL"):
                ctrl = CSR.CTRL
                try:
                    en = ctrl.field("EN")
                except KeyError:
                    pass
                else:
                    return [ctrl.write(EN=1, mask=en.mask)]

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
            """Basic functional-port and CSR transport smoke test."""

            reference = model.ReferenceModel()
            config = csr_config()
            functional_in, functional_out = functional_transaction(
                reference, drive_cycle=0, value=0
            )
            csr_in, csr_out = csr_roundtrip(4, 12)
            data_in = [*functional_in, *csr_in]
            data_out = [*functional_out, *csr_out]
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def corners_test() -> TestCase:
            """Starter 0/1 functional corners plus a CSR write/read check."""

            reference = model.ReferenceModel()
            config = csr_config()
            data_in: list[str] = []
            data_out: list[str] = []
            for drive_cycle, value in ((0, 0), (12, 1)):
                tx_in, tx_out = functional_transaction(
                    reference,
                    drive_cycle=drive_cycle,
                    value=value,
                )
                data_in.extend(tx_in)
                data_out.extend(tx_out)
            csr_in, csr_out = csr_roundtrip(24, 32)
            data_in.extend(csr_in)
            data_out.extend(csr_out)
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def random_test() -> TestCase:
            """Deterministic functional stimulus plus CSR transport coverage."""

            reference = model.ReferenceModel()
            rng = random.Random(f"{{TOP}}:random")
            config = csr_config()
            data_in: list[str] = []
            data_out: list[str] = []
            for index, drive_cycle in enumerate(range(0, 32, 8)):
                value = rng.getrandbits(1)
                tx_in, tx_out = functional_transaction(
                    reference,
                    drive_cycle=drive_cycle,
                    value=value,
                )
                data_in.extend(tx_in)
                data_out.extend(tx_out)
            csr_in, csr_out = csr_roundtrip(36, 44)
            data_in.extend(csr_in)
            data_out.extend(csr_out)
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def reconfig_test() -> TestCase:
            """Show initial config and repeated runtime CSR access in one test."""

            reference = model.ReferenceModel()
            config = csr_config()
            first_in, first_out = csr_roundtrip(8, 16)
            functional_in, functional_out = functional_transaction(
                reference, drive_cycle=20, value=1
            )
            second_in, second_out = csr_roundtrip(24, 32)
            data_in = [*first_in, *functional_in, *second_in]
            data_out = [*first_out, *functional_out, *second_out]
            return TestCase(config=config, data_in=data_in, data_out=data_out)


        def test_case(test: str) -> TestCase:
            """Build one named scenario."""

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
                "# fixed: <cycle> <signal> <expected> or <cycle> @read <reg> <expected> [mask]",
                "# valid: <valid_signal> <signal> <expected> [<signal> <expected> ...]",
                *case.data_out,
            ]
            (folder / "data_in.vec").write_text("\\n".join(data_in) + "\\n", encoding="utf-8")
            (folder / "data_out.vec").write_text("\\n".join(data_out) + "\\n", encoding="utf-8")


        def write_all_tests(
            root: str | Path,
            tests: list[str] | tuple[str, ...] | None = None,
        ) -> None:
            """Write requested tests, or every test listed in ``TESTS``."""

            for test in tests or TESTS:
                write_test(root, test)


        def main() -> int:
            parser = argparse.ArgumentParser(
                description="Generate FlexSoC vectors from the editable test catalogue."
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


def _write_text(path: Path, text: str, *, force: bool) -> Path:
    """Write one generated scaffold, preserving it unless ``force`` is set."""

    if force or not path.exists():
        path.write_text(text, encoding="utf-8")
    return path


def write_model(
    top: str,
    output: Path,
    rtl_dir: Path | None,
    *,
    force: bool,
) -> Path:
    """Create or preserve ``<top>_model.py``."""

    output.mkdir(parents=True, exist_ok=True)
    inputs, outputs = _ports(rtl_dir, top)
    return _write_text(
        output / f"{top}_model.py",
        _model_text(top, inputs, outputs),
        force=force,
    )


def write_tests(top: str, output: Path, *, force: bool) -> Path:
    """Create or preserve ``<top>_tests.py``."""

    output.mkdir(parents=True, exist_ok=True)
    return _write_text(
        output / f"{top}_tests.py",
        _tests_text(top),
        force=force,
    )


def parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate behavioral model, CSR regmap, and test scaffolds."
    )
    parser.add_argument("--top", required=True)
    parser.add_argument("--output-dir", default="model")
    parser.add_argument("--data-dir", required=True)
    parser.add_argument("--rtl-dir", default=None)
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    output_dir = Path(args.output_dir)

    if args.force:
        for legacy_name in (f"model_{args.top}.py", f"regmap_{args.top}.py"):
            legacy_path = output_dir / legacy_name
            if legacy_path.exists():
                legacy_path.unlink()

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
    tests_path = write_tests(args.top, output_dir, force=args.force)

    print(f"Model:  {model_path.resolve()}")
    print(f"Regmap: {regmap_path.resolve()}")
    print(f"Tests:  {tests_path.resolve()}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
