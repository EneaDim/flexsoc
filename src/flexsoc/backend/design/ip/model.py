"""Reference-model, model-test and regmap-test scaffold generation."""

from __future__ import annotations

import re
from pathlib import Path
from textwrap import dedent

from flexsoc.backend.core import ClockConfig

from .regs import RegsFlow
from .rtl import RtlFlow

SHARED_SCENARIO_TESTS = (
    "smoke",
    "corners",
    "random_seed_1",
    "random_seed_2",
    "reconfig",
)
SHARED_VECTOR_TESTS = (*SHARED_SCENARIO_TESTS, "auto_toggle")
NCLOCK_DESIGN_TESTS = ("mac_smoke", "absdiff", "energy", "clock_gate")


class ModelFlow:
    def __init__(self, project_root: Path):
        self.project_root = Path(project_root).resolve()
    """Create reference-model and authored model-test scaffolds."""

    def init_reference(
        self,
        top: str,
        output: Path,
        rtl_dir: Path | None = None,
        *,
        force: bool = False,
        clocks=None,
    ) -> Path:
        """Create the reference model for the active clock topology."""

        clocks = clocks or ClockConfig.from_values()
        if clocks.multiclock:
            output.mkdir(parents=True, exist_ok=True)
            return ModelFlow._write_text(
                output / f"{top}_model.py",
                ModelFlow.render_nclock_model(top),
                force=force,
            )
        return ModelFlow.write_model(top, output, rtl_dir, force=force)

    def init_model_tests(
        self,
        top: str,
        output: Path,
        *,
        force: bool = False,
        clocks=None,
    ) -> Path:
        """Create the editable model-driven scenario source."""

        clocks = clocks or ClockConfig.from_values()
        if clocks.multiclock:
            path = ModelFlow._write_text(
                output / f"{top}_tests.py",
                ModelFlow.render_nclock_tests(top),
                force=force,
            )
            path.chmod(0o755)
            return path
        return ModelFlow.write_tests(top, output, force=force)

    def setup_regmap_tests(
        self,
        top: str,
        output: Path,
        *,
        clocks=None,
    ) -> Path:
        """Refresh machine-owned CSR tests from the active clock intent."""

        clocks = clocks or ClockConfig.from_values()
        return ModelFlow.write_regmap_tests(top, output, safe_controls=clocks.multiclock)

    def setup(
        self,
        top: str,
        data_dir: Path,
        output: Path,
        rtl_dir: Path | None = None,
        *,
        force: bool = False,
        clocks=None,
    ) -> tuple[Path, Path, Path, Path]:
        """Prepare regmap, model and both test scaffolds."""

        clocks = clocks or ClockConfig.from_values()
        regmap = RegsFlow.generate(top, data_dir, output, force=force)
        model = self.init_reference(top, output, rtl_dir, force=force, clocks=clocks)
        tests = self.init_model_tests(top, output, force=force, clocks=clocks)
        regmap_tests = self.setup_regmap_tests(top, output, clocks=clocks)
        return regmap, model, tests, regmap_tests

    @staticmethod
    def _ports(rtl_dir: Path | None, top: str) -> tuple[list[str], list[str]]:
        """Return non-infrastructure top-level inputs and outputs."""

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
                if RtlFlow.is_register_bus_port(name) or "clk" in name.lower() or "rst" in name.lower():
                    continue
                (inputs if direction == "input" else outputs).append(name)

        return inputs, outputs

    @staticmethod
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

    @staticmethod
    def _is_starter_rtl(inputs: list[str], outputs: list[str]) -> bool:
        """Return true for the functional interface emitted by ``rtl_stub_gen``."""

        return {"data_i", "coeff_i", "valid_i"}.issubset(inputs) and {
            "data_o",
            "valid_o",
        }.issubset(outputs)

    @staticmethod
    def _model_text(top: str, inputs: list[str], outputs: list[str]) -> str:
        """Render the editable behavioral-model scaffold from its template."""

        from flexsoc.backend.core.render.templates import templates

        pipeline_map = ModelFlow._default_pipeline_map(inputs, outputs)
        starter_rtl = ModelFlow._is_starter_rtl(inputs, outputs)
        return templates.render(
            "design/model/reference_model.py.j2",
            top=top,
            top_repr=repr(top),
            inputs_repr=repr(tuple(inputs)),
            outputs_repr=repr(tuple(outputs)),
            latency=2 if starter_rtl else 1,
            starter_rtl=repr(starter_rtl),
            pipeline_map_repr=repr(pipeline_map),
        )

    @staticmethod
    def _tests_text(top: str) -> str:
        """Render the editable test-catalogue/vector-generator scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render(
            "design/model/tests.py.j2",
            top=top, tests_repr=repr(SHARED_SCENARIO_TESTS),
        )

    @staticmethod
    def _regmap_tests_text(top: str, *, safe_controls: bool = False) -> str:
        """Render generated CSR/input toggle stimulus."""

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
                disruptive = {"SOFT_RESET", "CLK_EN", "CLK_GATE_EN"} if SAFE_CONTROLS else set()
                for field in register.fields:
                    if field.name in disruptive:
                        continue
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

    @staticmethod
    def render_nclock_model(top: str) -> str:
        """Render the editable N-clock behavioral model scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render("design/model/nclock_reference_model.py.j2", top=top)

    @staticmethod
    def render_nclock_tests(top: str) -> str:
        """Render the editable N-clock model-driven test scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render("design/model/nclock_tests.py.j2", top=top)

    @staticmethod
    def write_regmap_tests(
        top: str, output: Path, *, safe_controls: bool = False
    ) -> Path:
        """Regenerate machine-owned coverage stimulus."""

        output.mkdir(parents=True, exist_ok=True)
        path = output / f"{top}_regmap_tests.py"
        path.write_text(ModelFlow._regmap_tests_text(top, safe_controls=safe_controls), encoding="utf-8")
        return path

    @staticmethod
    def _write_text(path: Path, text: str, *, force: bool) -> Path:
        """Write one generated scaffold, preserving it unless ``force`` is set."""

        if force or not path.exists():
            path.write_text(text, encoding="utf-8")
        return path

    @staticmethod
    def write_model(
        top: str,
        output: Path,
        rtl_dir: Path | None,
        *,
        force: bool,
    ) -> Path:
        """Create or preserve ``<top>_model.py``."""

        output.mkdir(parents=True, exist_ok=True)
        inputs, outputs = ModelFlow._ports(rtl_dir, top)
        return ModelFlow._write_text(
            output / f"{top}_model.py",
            ModelFlow._model_text(top, inputs, outputs),
            force=force,
        )

    @staticmethod
    def write_tests(top: str, output: Path, *, force: bool) -> Path:
        """Create or preserve ``<top>_tests.py``."""

        output.mkdir(parents=True, exist_ok=True)
        return ModelFlow._write_text(
            output / f"{top}_tests.py",
            ModelFlow._tests_text(top),
            force=force,
        )
