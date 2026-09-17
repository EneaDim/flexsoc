"""Stage contracts and provenance lifecycle policy.

The backend produces artifacts.  Lifecycle tracks whether those artifacts still
belong to the current inputs/configuration/tool contract and records runtime
outcomes independently from freshness.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Mapping, Sequence

from .provenance import Provenance
from ..runtime.toolchain import Toolchain


CLOCKS = ("N_CLOCKS", "CLOCK_DOMAINS", "CLOCK_RELATIONSHIPS")


@dataclass(frozen=True, slots=True)
class StageContract:
    """Semantic configuration, lineage, scope, tools and canonical evidence."""

    config: tuple[str, ...] = ()
    parents: tuple[str, ...] = ()
    evidence: tuple[str, ...] = ()
    scope: str = "run"
    tools: tuple[str, ...] = ()


STAGE_CONTRACTS: dict[str, StageContract] = {
    # Generated setup collateral.
    "model.setup": StageContract((*CLOCKS, "TOP")),
    "tb.setup": StageContract((*CLOCKS, "TOP", "REG_ITF", "CLK_PERIOD", "COMPILER", "VSV")),
    "cocotb.setup": StageContract((*CLOCKS, "TOP", "REG_ITF", "CLK_PERIOD", "COMPILER", "VSV")),
    "cdc_rdc.setup": StageContract((*CLOCKS, "TOP", "CLK_PERIOD")),
    "formal.prove.setup": StageContract((
        *CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_BMC_DEPTH", "FORMAL_BMC_APPEND",
        "FORMAL_BMC_ENGINE", "FORMAL_PROVE_ENGINE",
    )),
    "formal.cover.setup": StageContract((*CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_COVER_ENGINE")),
    "formal.csr_prove.setup": StageContract((
        *CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_BMC_DEPTH", "FORMAL_BMC_APPEND",
        "FORMAL_BMC_ENGINE", "FORMAL_PROVE_ENGINE",
    )),
    "formal.csr_cover.setup": StageContract((*CLOCKS, "TOP", "FORMAL_DEPTH", "FORMAL_COVER_ENGINE")),
    "syn.setup": StageContract((
        *CLOCKS, "TOP", "CLK_PERIOD", "TARGET_SYN", "TARGET_OPT", "LIB_SYN", "LIBS",
        "ORS", "ORS_TECH", "TIEHI_CELL_AND_PORT", "TIELO_CELL_AND_PORT", "MIN_BUF_CELL_AND_PORTS",
    ), scope="pdk"),
    "eqy.setup": StageContract((
        *CLOCKS, "TOP", "EQY_SAT_DEPTH", "EQY_USE_SAT",
        "EQY_SPLITNETS", "EQY_USE_PDR", "EQY_PDR_ENGINE", "EQY_SMT_ENGINE",
        "EQY_SMT_DEPTH", "EQY_XPROP", "EQY_JOIN_OUTPUTS", "EQY_STRATEGY_ORDER",
        "EQY_RESET_NORMALIZE", "EQY_RESET_CYCLES",
    ), ("syn.setup",), scope="pdk"),
    "sdc.setup": StageContract((*CLOCKS, "TOP", "SDC_IO_DELAY_PCT")),
    "signoff.setup": StageContract(
        (*CLOCKS, "TOP", "PDK", "CLK_PERIOD"), scope="pdk",
    ),
    "signoff_post_impl.setup": StageContract(
        (*CLOCKS, "TOP", "PDK", "CLK_PERIOD", "ORS_TECH"),
        ("pnr.setup",), scope="pdk",
    ),
    "pnr.setup": StageContract(
        (*CLOCKS, "TOP", "PDK", "ORS_TECH", "PNR_HOLD_SLACK_MARGIN"),
        ("syn.setup", "signoff.setup"), scope="pdk",
    ),

    # Runtime qualification evidence.
    "lint_slang_suite": StageContract(("TOP",), evidence=("dv/lint/slang/{top}_lint_slang_all.log",), tools=("SLANG",)),
    "lint_verilator_suite": StageContract(("TOP",), evidence=("dv/lint/verilator/{top}_lint_verilator_all.log",), tools=("VERILATOR",)),
    "cdc_rdc": StageContract((*CLOCKS, "TOP", "CDC_RDC_STRICT"), ("cdc_rdc.setup",), ("dv/cdc_rdc/summary.json",), tools=("SLANG", "YOSYS")),
    "regression": StageContract(
        (*CLOCKS, "TOP", "COMPILER", "REGRESSION_BACKENDS", "SEED", "RESET_SETTLE_CYCLES"),
        ("tb.setup", "cocotb.setup"),
        ("logs/dv/functional/regression", "dv/functional/coverage/sv", "dv/functional/coverage/cocotb"),
        tools=("IVERILOG", "VERILATOR"),
    ),
    "formal_csr_bmc": StageContract(("TOP", "FORMAL_BMC_DEPTH", "FORMAL_BMC_ENGINE"), ("formal.csr_prove.setup",), ("logs/dv/formal/csr/{top}_bmc.log",), tools=("SBY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "formal_bmc": StageContract(("TOP", "FORMAL_BMC_DEPTH", "FORMAL_BMC_ENGINE"), ("formal.prove.setup",), ("logs/dv/formal/properties/{top}_bmc.log",), tools=("SBY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "formal_csr_prove": StageContract(("TOP", "FORMAL_PROVE_ENGINE"), ("formal.csr_prove.setup", "formal_csr_bmc"), ("logs/dv/formal/csr/{top}_prove.log",), tools=("SBY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "formal_prove": StageContract(("TOP", "FORMAL_PROVE_ENGINE"), ("formal.prove.setup", "formal_bmc"), ("logs/dv/formal/properties/{top}_prove.log",), tools=("SBY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "formal_csr_cover": StageContract(("TOP", "FORMAL_COVER_ENGINE"), ("formal.csr_cover.setup",), ("logs/dv/formal/csr/{top}_cover.log",), tools=("SBY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "formal_cover": StageContract(("TOP", "FORMAL_COVER_ENGINE"), ("formal.cover.setup",), ("logs/dv/formal/properties/{top}_cover.log",), tools=("SBY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "syn": StageContract(
        ("TOP", "PDK", "TARGET_SYN", "TARGET_OPT", "ORS_TECH"),
        ("syn.setup",),
        ("syn/{pdk}/{top}_synth.v", "syn/{pdk}/{top}_synth.json", "syn/{pdk}/{top}_synth_repair.json"),
        scope="pdk", tools=("YOSYS", "OPENROAD", "ORFS"),
    ),
    "eqy": StageContract(("TOP", "PDK", "EQY_STRATEGY_ORDER"), ("eqy.setup", "syn"), ("signoff/{pdk}/equivalence/{top}_rtl_vs_syn",), scope="pdk", tools=("EQY", "YOSYS", "BITWUZLA", "BOOLECTOR")),
    "sdf": StageContract(("TOP", "PDK"), ("signoff.setup", "syn"), ("signoff/{pdk}/sdf",), scope="pdk", tools=("OPENSTA",)),
    "sta": StageContract(("TOP", "PDK"), ("signoff.setup", "syn"), ("signoff/{pdk}/sta/summary.json",), scope="pdk", tools=("OPENSTA",)),
    "power_estimate": StageContract(("TOP", "PDK"), ("signoff.setup", "syn"), ("signoff/{pdk}/power/estimate/summary.json",), scope="pdk", tools=("OPENSTA",)),
    "sim_post_syn_all": StageContract(
        ("TOP", "PDK", "GLS_BACKEND", "TIMING_MODES", "TEST_NAMES", "SDF_STRICT"),
        ("tb.setup", "syn", "sdf"), ("dv/functional/sim/post_syn/{pdk}/summary_sv.json",),
        scope="pdk", tools=("IVERILOG", "VERILATOR"),
    ),
    "power_analysis_all": StageContract(
        ("TOP", "PDK", "POWER_TEST_NAMES", "POWER_GLS_BACKENDS", "POWER_TIMING_MODES"),
        ("signoff.setup", "sim_post_syn_all"), ("signoff/{pdk}/power/analysis/summary.json",),
        scope="pdk", tools=("OPENSTA",),
    ),
    "fusion_analysis_all": StageContract(
        ("TOP", "PDK", "POWER_TEST_NAMES", "POWER_GLS_BACKENDS", "POWER_TIMING_MODES"),
        ("power_analysis_all",), ("signoff/{pdk}/fusion/summary.json",),
        scope="pdk", tools=("OPENSTA",),
    ),
    "pnr": StageContract(
        ("TOP", "PDK", "ORS", "ORS_TECH"), ("pnr.setup", "syn"),
        (
            "impl/{pdk}/results/{ors_tech}/{top}/base/6_final.v",
            "impl/{pdk}/results/{ors_tech}/{top}/base/6_final.sdc",
            "impl/{pdk}/results/{ors_tech}/{top}/base/6_final.spef",
            "impl/{pdk}/results/{ors_tech}/{top}/base/6_final.odb",
            "impl/{pdk}/results/{ors_tech}/{top}/base/6_final.gds",
        ),
        scope="pdk", tools=("ORFS", "OPENROAD"),
    ),
    "physical_signoff": StageContract(("TOP", "PDK", "ORS", "ORS_TECH"), ("pnr",), ("signoff/{pdk}/post_impl/physical/summary.json",), scope="pdk", tools=("ORFS", "OPENROAD", "KLAYOUT")),
    "sdf_post_impl": StageContract(("TOP", "PDK"), ("signoff_post_impl.setup", "pnr"), ("signoff/{pdk}/post_impl/sdf",), scope="pdk", tools=("OPENSTA",)),
    "sta_post_impl": StageContract(("TOP", "PDK"), ("signoff_post_impl.setup", "pnr"), ("signoff/{pdk}/post_impl/sta/summary.json",), scope="pdk", tools=("OPENSTA",)),
    "power_estimate_post_impl": StageContract(("TOP", "PDK"), ("signoff_post_impl.setup", "pnr"), ("signoff/{pdk}/post_impl/power/estimate/summary.json",), scope="pdk", tools=("OPENSTA",)),
    "sim_post_impl_all": StageContract(
        ("TOP", "PDK", "GLS_BACKEND", "TIMING_MODES", "TEST_NAMES", "SDF_STRICT"),
        ("tb.setup", "pnr", "sdf_post_impl"), ("dv/functional/sim/post_impl/{pdk}/summary_sv.json",),
        scope="pdk", tools=("IVERILOG", "VERILATOR"),
    ),
    "power_analysis_post_impl_all": StageContract(
        ("TOP", "PDK", "POWER_TEST_NAMES", "POWER_GLS_BACKENDS", "POWER_TIMING_MODES"),
        ("signoff_post_impl.setup", "sim_post_impl_all"), ("signoff/{pdk}/post_impl/power/analysis/summary.json",),
        scope="pdk", tools=("OPENSTA",),
    ),
    "fusion_analysis_post_impl_all": StageContract(
        ("TOP", "PDK", "POWER_TEST_NAMES", "POWER_GLS_BACKENDS", "POWER_TIMING_MODES"),
        ("power_analysis_post_impl_all",), ("signoff/{pdk}/post_impl/fusion/summary.json",),
        scope="pdk", tools=("OPENSTA",),
    ),
}

PROVENANCE_SETUPS = frozenset(stage for stage in STAGE_CONTRACTS if stage.endswith(".setup"))
RUNTIME_STAGES = frozenset(STAGE_CONTRACTS) - PROVENANCE_SETUPS

InputResolver = Callable[[str], Sequence[Path]]


@dataclass(slots=True)
class Lifecycle:
    """Apply StageContract policy to one run without knowing EDA implementations."""

    project_root: Path
    run_root: Path
    pdk_meta: Path
    values: Mapping[str, str]
    pdk: str
    top: str

    def store(self, stage: str) -> Provenance:
        contract = STAGE_CONTRACTS[stage]
        root = self.pdk_meta if contract.scope == "pdk" else self.run_root / "meta"
        return Provenance(root / "provenance.json", self.run_root)

    def config(self, stage: str) -> dict[str, str]:
        return {key: self.values.get(key, "") for key in STAGE_CONTRACTS[stage].config}

    def tools(self, stage: str) -> dict[str, dict[str, str]]:
        prefixes = STAGE_CONTRACTS[stage].tools
        if not prefixes:
            return {}
        lock = Toolchain.load_toolchain_lock(self.project_root)
        result: dict[str, dict[str, str]] = {}
        for prefix in prefixes:
            marker = prefix + "_"
            result[prefix] = {
                key[len(marker):].lower(): value
                for key, value in sorted(lock.items())
                if key.startswith(marker)
            }
        return result

    def evidence(self, stage: str) -> tuple[Path, ...]:
        values = {
            "pdk": self.pdk,
            "top": self.top,
            "ors_tech": self.values.get("ORS_TECH", self.pdk),
        }
        return tuple(
            self.run_root / pattern.format(**values)
            for pattern in STAGE_CONTRACTS[stage].evidence
        )

    def parents(self, stage: str, inputs_for: InputResolver) -> dict[str, str | None]:
        return {
            parent: self.store(parent).current_fingerprint(
                parent,
                inputs=inputs_for(parent),
                config=self.config(parent),
                parents=self.parents(parent, inputs_for),
                tools=self.tools(parent),
            )
            for parent in STAGE_CONTRACTS[stage].parents
        }

    def execution_inputs(self, stage: str, inputs_for: InputResolver) -> tuple[Path, ...]:
        paths = (*inputs_for(stage), *self.store(stage).generated(stage))
        return tuple(dict.fromkeys(path.absolute() for path in paths))

    def state(self, stage: str, inputs_for: InputResolver) -> str:
        return self.store(stage).state(
            stage,
            inputs=inputs_for(stage),
            config=self.config(stage),
            parents=self.parents(stage, inputs_for),
            tools=self.tools(stage),
        )

    def summary(self, inputs_for: InputResolver) -> dict[str, object]:
        states = {
            stage: self.state(stage, inputs_for)
            for stage in STAGE_CONTRACTS
            if stage in self.store(stage).stages()
        }
        return Provenance.summary(states)

    def contract_state(self, stage: str, inputs_for: InputResolver) -> str:
        if stage not in self.store(stage).stages():
            return "MISSING"
        return self.state(stage, inputs_for)

    def outcome(self, stage: str) -> str | None:
        return self.store(stage).outcome(stage)

    def record(
        self,
        stage: str,
        *,
        inputs_for: InputResolver,
        generated: Sequence[Path],
        outcome: str | None = None,
        returncode: int | None = None,
    ) -> None:
        runtime = stage in RUNTIME_STAGES
        self.store(stage).record(
            stage,
            inputs=inputs_for(stage),
            generated=generated,
            config=self.config(stage),
            parents=self.parents(stage, inputs_for),
            tools=self.tools(stage),
            outcome=outcome,
            returncode=returncode,
            allow_missing=runtime and outcome != "PASS",
        )

    def validate(self, stage: str, inputs_for: InputResolver) -> str:
        return self.store(stage).validate(
            stage,
            inputs=inputs_for(stage),
            config=self.config(stage),
            parents=self.parents(stage, inputs_for),
            tools=self.tools(stage),
        )
