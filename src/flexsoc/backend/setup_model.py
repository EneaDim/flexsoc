"""Generate Python model, regmap, and functional-DV scaffolds.

``setup_model`` creates four files in ``dv/functional/model/``:

* ``<top>_model.py``: editable behavioral reference model for the RTL;
* ``<top>_regmap.py``: generated CSR metadata/API derived from HJSON;
* ``<top>_tests.py``: editable functional test catalogue;
* ``<top>_regmap_tests.py``: generated CSR/input toggle tests.

The split is intentional. Behavioral changes belong in the model, register-layout
changes are refreshed with ``fx regmap_py --force``, and new verification
scenarios can be added to the tests file without changing the behavioral model.
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path
from textwrap import dedent

from flexsoc.clocking import clock_config

from .setup_model_regmap import generate as generate_regmap


_IGNORED_PORTS = {"tl_i", "tl_o", "reg_req_i", "reg_rsp_o"}
SHARED_SCENARIO_TESTS = (
    "smoke",
    "corners",
    "random_seed_1",
    "random_seed_2",
    "reconfig",
)
SHARED_VECTOR_TESTS = (*SHARED_SCENARIO_TESTS, "auto_toggle")
NCLOCK_DESIGN_TESTS = ("mac_smoke", "absdiff", "energy")


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
        TESTS = {SHARED_SCENARIO_TESTS!r}
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


        def random_test(seed: int) -> TestCase:
            """Deterministic random stimulus for one explicit seed."""

            reference = model.ReferenceModel()
            rng = random.Random(f"{{TOP}}:random:{{seed}}")
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
            """Build one named scenario, including explicit random seeds."""

            if test.startswith("random_seed_"):
                try:
                    seed = int(test.removeprefix("random_seed_"))
                except ValueError as exc:
                    raise ValueError(f"invalid random test name {{test!r}}") from exc
                return random_test(seed)

            scenarios = {{
                "smoke": smoke_test,
                "corners": corners_test,
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

            seed_note = (
                f" random_seed={{test.removeprefix('random_seed_')}}"
                if test.startswith("random_seed_")
                else ""
            )
            data_in = [
                f"# {{TOP}}/{{test}}{{seed_note}} input stimulus: ports + CSR writes.",
                "# <cycle> <signal> <value> or <cycle> @write <reg> <value> [mask]",
                *case.data_in,
            ]
            data_out = [
                f"# {{TOP}}/{{test}}{{seed_note}} output checks: ports + CSR reads.",
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
            parser.add_argument("--tests-dir", default="../tests")
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


def _regmap_tests_text(top: str, *, safe_controls: bool = False) -> str:
    """Render generated CSR/input toggle stimulus.

    N-clock scaffolds avoid control registers whose writes may stop clocks or
    reset the DUT before the test can restore them.
    """

    return dedent(
        f'''\
        """Generated FlexSoC coverage stimulus for {top}.

        This file is machine-owned. It reads the current generated regmap at
        runtime, so HJSON/regmap changes are reflected by the next ``tests_gen``.
        """
        from __future__ import annotations

        import argparse
        from pathlib import Path

        import {top}_model as model
        import {top}_regmap as regmap


        TOP = {top!r}
        TEST = "auto_toggle"
        SAFE_CONTROLS = {safe_controls!r}


        def _toggle_mask(register: regmap.Register) -> int:
            """Return software-owned bits safe for repeated toggle writes."""

            if SAFE_CONTROLS and register.name == "CTRL":
                return 0
            mask = 0
            for field in register.fields:
                if field.swaccess == "rw" and field.hwaccess == "hro":
                    mask |= field.mask
            return mask & 0xFFFF_FFFF


        def _write_mask(register: regmap.Register) -> int:
            """Return TL-UL byte enables covering the declared register width."""

            byte_count = max(1, min(4, (register.mask.bit_length() + 7) // 8))
            return (1 << byte_count) - 1


        def _safe_config_rows() -> list[str]:
            """Return the non-disruptive control baseline required by N-clock traffic.

            The verification harness already resets the DUT before loading
            ``config.regs``. Runtime reset commands would clear these controls
            again, so the N-clock auto-toggle test establishes ENABLE here and
            then leaves reset/clock-gating controls untouched.
            """

            if not SAFE_CONTROLS:
                return []

            rows: list[str] = []
            for domain in regmap.DOMAINS.values():
                for register in domain.writable:
                    if register.name != "CTRL":
                        continue
                    field_names = {{field.name for field in register.fields}}
                    values: dict[str, int] = {{}}
                    if "ENABLE" in field_names:
                        values["ENABLE"] = 1
                    if "SOFT_RESET" in field_names:
                        values["SOFT_RESET"] = 0
                    if "CLK_GATE_EN" in field_names:
                        values["CLK_GATE_EN"] = 0
                    if values:
                        rows.append(register.write(**values))
            return rows


        def stimulus() -> list[str]:
            rows: list[str] = []
            cycle = 0

            for domain in regmap.DOMAINS.values():
                for register in domain.writable:
                    mask = _toggle_mask(register)
                    if not mask:
                        continue
                    base = register.reset & 0xFFFF_FFFF
                    write_mask = _write_mask(register)
                    for value in (base ^ mask, base, base ^ mask, base):
                        rows.append(register.vector_write(cycle, value, mask=write_mask))
                        cycle += 4

            for value in (0xFFFF_FFFF, 0x0000_0000, 0xFFFF_FFFF, 0x0000_0000):
                for name in model.INPUTS:
                    rows.append(f"{{cycle}} {{name}} 0x{{value:08x}}")
                if model.INPUTS:
                    cycle += 4

            if not SAFE_CONTROLS:
                rows.append(f"{{cycle}} @reset 2")
            return rows


        def write_test(root: str | Path) -> None:
            folder = Path(root) / TEST
            folder.mkdir(parents=True, exist_ok=True)
            regmap.write_config(folder / "config.regs", _safe_config_rows())
            (folder / "data_in.vec").write_text(
                "# Generated CSR/input toggle stimulus.\\n"
                + "\\n".join(stimulus())
                + "\\n",
                encoding="utf-8",
            )
            (folder / "data_out.vec").write_text(
                "# Coverage stimulus intentionally has no functional checks.\\n",
                encoding="utf-8",
            )


        def main() -> int:
            parser = argparse.ArgumentParser(description="Generate FlexSoC automatic coverage vectors.")
            parser.add_argument("--tests-dir", default="../tests")
            parser.add_argument("--test", action="append", default=[])
            args = parser.parse_args()
            unknown = [name for name in args.test if name != TEST]
            if unknown:
                raise SystemExit(f"unknown automatic test(s): {{', '.join(unknown)}}")
            write_test(args.tests_dir)
            return 0


        if __name__ == "__main__":
            raise SystemExit(main())
        '''
    )

def render_nclock_model(top: str) -> str:
    """Render the editable N-clock behavioral model."""

    return dedent(f'''\
    """Editable behavioral reference model for {top}.

    This module models the DSP transaction performed by the generated
    N-clock RTL scaffold. Test selection, vector serialization and CSR
    layout live in ``{top}_tests.py`` and ``{top}_regmap.py``.

    N-clock completion is event-driven: the generated verification
    infrastructure consumes expected outputs when ``dsp_valid_o`` asserts,
    rather than assuming one absolute latency across unrelated clocks.
    """

    from __future__ import annotations

    from dataclasses import dataclass


    INPUTS = ("rx_sample_i", "rx_coeff_i", "rx_valid_i")
    OUTPUTS = (
        "dsp_result_o",
        "dsp_valid_o",
        "dsp_above_threshold_o",
        "dsp_overflow_o",
    )


    @dataclass(frozen=True)
    class DspConfig:
        """Behavioral controls that affect one DSP transaction."""

        gain: int = 0
        op: int = 0
        saturate: bool = False
        threshold: int = 0


    @dataclass(frozen=True)
    class DspInput:
        """One accepted RX-domain payload."""

        sample: int
        coeff: int


    @dataclass(frozen=True)
    class DspOutput:
        """Expected DSP-domain result for one accepted payload."""

        result: int
        above_threshold: bool
        overflow: bool


    def i16(value: int) -> int:
        """Convert a value to signed 16-bit."""

        value &= 0xFFFF
        return value - 0x10000 if value & 0x8000 else value


    def u32(value: int) -> int:
        """Convert a value to unsigned 32-bit."""

        return value & 0xFFFF_FFFF


    class ReferenceModel:
        """Behavioral model of the generated DSP datapath."""

        def reset(self) -> None:
            """Reset model-owned state.

            The starter DSP is transaction-level and stateless, so there is
            nothing to clear. Stateful specializations can extend this method.
            """

            pass

        def compute(self, inputs: DspInput, config: DspConfig) -> DspOutput:
            """Return the DSP result associated with one accepted RX payload."""

            sample = i16(inputs.sample)
            coeff = i16(inputs.coeff)
            gain = i16(config.gain)

            if config.op == 1:
                raw = abs(sample - coeff)
            elif config.op == 2:
                raw = sample * sample + coeff * coeff
            else:
                raw = sample * coeff + gain

            overflow = raw > 0x7FFF_FFFF or raw < -0x8000_0000
            if config.saturate and raw > 0x7FFF_FFFF:
                raw = 0x7FFF_FFFF
            elif config.saturate and raw < -0x8000_0000:
                raw = -0x8000_0000

            result = u32(raw)
            return DspOutput(
                result=result,
                above_threshold=result > (config.threshold & 0xFFFF_FFFF),
                overflow=overflow,
            )
    ''')


def render_nclock_tests(top: str) -> str:
    """Render shared plus design-specific N-clock vector scenarios."""

    return dedent(f'''\
    """Editable N-clock test catalogue and vector generator for {top}.

    ``SHARED_TESTS`` mirrors the generated single-clock catalogue. The
    N-clock scaffold keeps those names and semantics, then appends scenarios
    that exercise the starter DSP architecture specifically.
    """

    from __future__ import annotations

    import argparse
    import random
    from dataclasses import dataclass
    from pathlib import Path

    import {top}_model as model
    import {top}_regmap as regmap


    TOP = {top!r}
    SHARED_TESTS = {SHARED_SCENARIO_TESTS!r}
    DESIGN_TESTS = {NCLOCK_DESIGN_TESTS!r}
    TESTS = (*SHARED_TESTS, *DESIGN_TESTS)
    CFG = regmap.domain("cfg")
    DSP = regmap.domain("dsp")


    @dataclass(frozen=True)
    class Step:
        """One optional runtime reconfiguration and/or RX transaction."""

        inputs: model.DspInput | None = None
        config: model.DspConfig | None = None


    @dataclass(frozen=True)
    class TestCase:
        """Initial configuration and ordered actions for one scenario."""

        config: model.DspConfig
        steps: tuple[Step, ...]


    def config_rows(config: model.DspConfig) -> list[str]:
        """Serialize initial domain-qualified CSR writes."""

        return [
            CFG.GAIN.write(VALUE=int(config.gain) & 0xFFFF),
            DSP.DSP_CTRL.write(OP=int(config.op), SATURATE=int(config.saturate)),
            DSP.THRESHOLD.write(VALUE=int(config.threshold) & 0xFFFF_FFFF),
            CFG.CTRL.write(ENABLE=1, SOFT_RESET=0, CLK_GATE_EN=0),
        ]


    def runtime_config_rows(step: int, config: model.DspConfig) -> list[str]:
        """Write and read back one runtime configuration."""

        gain = int(config.gain) & 0xFFFF
        ctrl = int(config.op) | (int(config.saturate) << 2)
        threshold = int(config.threshold) & 0xFFFF_FFFF
        return [
            CFG.GAIN.vector_write(step, gain),
            DSP.DSP_CTRL.vector_write(step, ctrl),
            DSP.THRESHOLD.vector_write(step, threshold),
            CFG.GAIN.vector_read(step, gain),
            DSP.DSP_CTRL.vector_read(step, ctrl),
            DSP.THRESHOLD.vector_read(step, threshold),
        ]


    def input_rows(step: int, inputs: model.DspInput) -> list[str]:
        """Serialize one ordered RX-domain input transaction."""

        return [
            f"{{step}} rx_sample_i 0x{{inputs.sample & 0xFFFF:04x}}",
            f"{{step}} rx_coeff_i 0x{{inputs.coeff & 0xFFFF:04x}}",
            f"{{step}} rx_valid_i 0x1",
        ]


    def output_rows(step: int, expected: model.DspOutput) -> list[str]:
        """Serialize one DSP-domain expectation consumed on ``dsp_valid_o``."""

        return [
            f"{{step}} dsp_result_o 0x{{expected.result:08x}}",
            f"{{step}} dsp_valid_o 0x1",
            f"{{step}} dsp_above_threshold_o 0x{{int(expected.above_threshold)}}",
            f"{{step}} dsp_overflow_o 0x{{int(expected.overflow)}}",
        ]


    def random_case(seed: int) -> TestCase:
        """Build deterministic random traffic for one explicit seed."""

        rng = random.Random(f"{{TOP}}:random:{{seed}}")
        config = model.DspConfig(
            gain=rng.randint(-8, 8),
            op=rng.randrange(3),
            saturate=bool(rng.randrange(2)),
            threshold=rng.getrandbits(12),
        )
        steps = tuple(
            Step(inputs=model.DspInput(rng.randint(-0x8000, 0x7FFF), rng.randint(-0x8000, 0x7FFF)))
            for _ in range(4)
        )
        return TestCase(config=config, steps=(*steps, Step(config=config)))


    def scenario(name: str) -> TestCase:
        """Return one shared or design-specific N-clock scenario."""

        if name.startswith("random_seed_"):
            try:
                return random_case(int(name.removeprefix("random_seed_")))
            except ValueError as exc:
                raise ValueError(f"invalid random test name {{name!r}}") from exc

        smoke = model.DspConfig(gain=1, op=0, saturate=False, threshold=0x10)
        scenarios = {{
            "smoke": TestCase(
                config=smoke,
                steps=(Step(config=smoke), Step(inputs=model.DspInput(3, 4))),
            ),
            "corners": TestCase(
                config=model.DspConfig(gain=1, op=0, saturate=True, threshold=0x7FFF_FFFF),
                steps=tuple(
                    Step(inputs=item)
                    for item in (
                        model.DspInput(0, 0),
                        model.DspInput(0x7FFF, 1),
                        model.DspInput(-0x8000, -1),
                        model.DspInput(-1, 0x7FFF),
                    )
                ),
            ),
            "reconfig": TestCase(
                config=smoke,
                steps=(
                    Step(inputs=model.DspInput(3, 4)),
                    Step(config=model.DspConfig(gain=0, op=1, threshold=4)),
                    Step(inputs=model.DspInput(9, 4)),
                    Step(config=model.DspConfig(gain=0, op=2, threshold=0x20)),
                    Step(inputs=model.DspInput(3, 4)),
                ),
            ),
            "mac_smoke": TestCase(
                config=smoke,
                steps=tuple(
                    Step(inputs=item)
                    for item in (
                        model.DspInput(3, 4),
                        model.DspInput(7, 2),
                        model.DspInput(-3, 5),
                    )
                ),
            ),
            "absdiff": TestCase(
                config=model.DspConfig(gain=0, op=1, threshold=4),
                steps=(
                    Step(inputs=model.DspInput(9, 4)),
                    Step(inputs=model.DspInput(-2, 8)),
                ),
            ),
            "energy": TestCase(
                config=model.DspConfig(gain=0, op=2, threshold=0x20),
                steps=(
                    Step(inputs=model.DspInput(3, 4)),
                    Step(inputs=model.DspInput(5, 12)),
                ),
            ),
        }}
        try:
            return scenarios[name]
        except KeyError as exc:
            raise ValueError(f"unknown test {{name!r}}; choose one of {{TESTS}}") from exc


    def write_test(root: str | Path, name: str) -> None:
        """Generate ``config.regs``, ``data_in.vec`` and ``data_out.vec``."""

        case = scenario(name)
        reference = model.ReferenceModel()
        out = Path(root) / name
        out.mkdir(parents=True, exist_ok=True)
        regmap.write_config(out / "config.regs", config_rows(case.config))

        data_in = [
            "# format: <STEP> <SIGNAL> <VALUE>",
            "# runtime CSR: <STEP> @write/@read <DOMAIN.REG> <VALUE> [MASK]",
            "# STEP records transaction order, not an absolute clock cycle.",
        ]
        data_out = [
            "# format: <STEP> <SIGNAL> <VALUE>",
            "# Expected rows are consumed in order when dsp_valid_o asserts.",
        ]
        active = case.config
        for step, action in enumerate(case.steps):
            if action.config is not None:
                active = action.config
                data_in.extend(runtime_config_rows(step, active))
            if action.inputs is not None:
                data_in.extend(input_rows(step, action.inputs))
                data_out.extend(output_rows(step, reference.compute(action.inputs, active)))

        (out / "data_in.vec").write_text("\\n".join(data_in) + "\\n", encoding="utf-8")
        (out / "data_out.vec").write_text("\\n".join(data_out) + "\\n", encoding="utf-8")


    def write_all_tests(
        root: str | Path,
        tests: list[str] | tuple[str, ...] | None = None,
    ) -> None:
        """Generate requested tests, or the complete catalogue when omitted."""

        for name in tests or TESTS:
            write_test(root, name)


    def main() -> int:
        """CLI entry point used by the unified vector-test targets."""

        parser = argparse.ArgumentParser(
            description="Generate shared and N-clock-specific vector tests."
        )
        parser.add_argument("--tests-dir", default="../tests")
        parser.add_argument("--test", action="append", default=[])
        parser.add_argument("--list", action="store_true")
        args = parser.parse_args()
        if args.list:
            for test in TESTS:
                print(test)
            return 0
        write_all_tests(args.tests_dir, args.test or None)
        return 0


    if __name__ == "__main__":
        raise SystemExit(main())
    ''')

# ---------------------------------------------------------------------------
# SystemVerilog verification scaffold
# ---------------------------------------------------------------------------



def write_regmap_tests(
    top: str, output: Path, *, safe_controls: bool = False
) -> Path:
    """Regenerate machine-owned coverage stimulus."""

    output.mkdir(parents=True, exist_ok=True)
    path = output / f"{top}_regmap_tests.py"
    path.write_text(_regmap_tests_text(top, safe_controls=safe_controls), encoding="utf-8")
    legacy = output / f"{top}_auto_tests.py"
    if legacy.exists():
        legacy.unlink()
    return path


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
    parser.add_argument("--output-dir", default="dv/functional/model")
    parser.add_argument("--data-dir", required=True)
    parser.add_argument("--rtl-dir", default=None)
    parser.add_argument("--force", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str] | None = None) -> int:
    """Generate the model owned by the active clock configuration."""

    args = parse_args(argv)
    output = Path(args.output_dir)
    if args.force:
        for name in (f"model_{args.top}.py", f"regmap_{args.top}.py"):
            path = output / name
            if path.exists():
                path.unlink()

    clocks = clock_config()
    if clocks.multiclock:
        from .setup_model_regmap import generate as generate_model_regmap
        generate_model_regmap(args.top, Path(args.data_dir), output, force=args.force)
        _write_text(output / f"{args.top}_model.py", render_nclock_model(args.top), force=args.force)
        tests = _write_text(output / f"{args.top}_tests.py", render_nclock_tests(args.top), force=args.force)
        tests.chmod(0o755)
    else:
        generate_regmap(args.top, Path(args.data_dir), output, force=args.force)
        write_model(args.top, output, Path(args.rtl_dir) if args.rtl_dir else None, force=args.force)
        write_tests(args.top, output, force=args.force)
    write_regmap_tests(args.top, output, safe_controls=clocks.multiclock)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
