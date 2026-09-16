"""Small declarative target model used by backend lifecycle domains."""

from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True, slots=True)
class Target:
    """One backend operation with lifecycle metadata and one owning domain."""

    name: str
    action: str | None = None
    stage: str | None = None
    setup: tuple[str, ...] = ()
    sequence: tuple[str, ...] = ()
    debug: str | None = None
    show: str | None = None
    stream: bool = False
    quiet: bool = False
    domain: str = "signoff"

    @property
    def is_gls(self) -> bool:
        return self.action in {"gls_compile", "gls", "gls_all"}

    @property
    def is_activity(self) -> bool:
        return self.action in {"power_activity", "power_activity_all", "fusion", "fusion_all"}

    @property
    def technology(self) -> bool:
        return self.domain in {"signoff", "syn", "impl"}


SIGNOFF_TARGETS: dict[str, Target] = {
    "sdc.setup": Target("sdc.setup", "sdc_setup", "post_syn"),
    "signoff.setup": Target("signoff.setup", "setup", "post_syn"),
    "signoff_post_pnr.setup": Target("signoff_post_pnr.setup", "setup", "post_impl"),

    "sdf": Target("sdf", "sdf", "post_syn", ("signoff.setup",)),
    "sta": Target("sta", "sta", "post_syn", ("signoff.setup",), debug="sta", show="sta"),
    "sta_corners": Target("sta_corners", "sta", "post_syn", ("signoff.setup",), debug="sta", show="sta"),
    "power_estimate": Target(
        "power_estimate", "power_estimate", "post_syn", ("signoff.setup",),
        debug="power_estimate", show="power_estimate",
    ),
    "power_estimate_corners": Target(
        "power_estimate_corners", "power_estimate", "post_syn", ("signoff.setup",),
        debug="power_estimate", show="power_estimate",
    ),
    "power_analysis": Target(
        "power_analysis", "power_activity", "post_syn", ("signoff.setup",),
        debug="power_activity", show="power", quiet=True,
    ),
    "power_analysis_all": Target(
        "power_analysis_all", "power_activity_all", "post_syn", ("signoff.setup",),
        debug="power_activity", show="power", stream=True,
    ),
    "fusion_analysis": Target(
        "fusion_analysis", "fusion", "post_syn", ("signoff.setup",),
        debug="fusion", show="fusion", stream=True,
    ),
    "fusion_analysis_all": Target(
        "fusion_analysis_all", "fusion_all", "post_syn", ("signoff.setup",),
        debug="fusion", show="fusion", stream=True,
    ),
    "signoff": Target(
        "signoff", stage="post_syn", setup=("signoff.setup",),
        sequence=("sdf", "sta", "power_estimate"),
    ),
    "sta_violators": Target("sta_violators", "sta", "post_syn", ("signoff.setup",)),

    "compile_syn": Target("compile_syn", "gls_compile", "post_syn", quiet=True),
    "sim_syn": Target("sim_syn", "gls", "post_syn", debug="gls"),
    "compile_post_syn": Target("compile_post_syn", "gls_compile", "post_syn", quiet=True),
    "sim_post_syn": Target("sim_post_syn", "gls", "post_syn", debug="gls", quiet=True),
    "sim_post_syn_all": Target("sim_post_syn_all", "gls_all", "post_syn", debug="gls", show="gls_post_syn", stream=True),

    "sdf_post_pnr": Target("sdf_post_pnr", "sdf", "post_impl", ("signoff_post_pnr.setup",), quiet=True),
    "sta_post_pnr": Target(
        "sta_post_pnr", "sta", "post_impl", ("signoff_post_pnr.setup",),
        debug="sta", show="sta_post_pnr",
    ),
    "power_estimate_post_pnr": Target(
        "power_estimate_post_pnr", "power_estimate", "post_impl", ("signoff_post_pnr.setup",),
        debug="power_estimate", show="power_estimate_post_pnr",
    ),
    "power_analysis_post_pnr": Target(
        "power_analysis_post_pnr", "power_activity", "post_impl", ("signoff_post_pnr.setup",),
        debug="power_activity", show="power_post_pnr", quiet=True,
    ),
    "power_analysis_post_pnr_all": Target(
        "power_analysis_post_pnr_all", "power_activity_all", "post_impl", ("signoff_post_pnr.setup",),
        debug="power_activity", show="power_post_pnr", stream=True,
    ),
    "fusion_analysis_post_pnr": Target(
        "fusion_analysis_post_pnr", "fusion", "post_impl", ("signoff_post_pnr.setup",),
        debug="fusion", show="fusion_post_pnr", stream=True,
    ),
    "fusion_analysis_post_pnr_all": Target(
        "fusion_analysis_post_pnr_all", "fusion_all", "post_impl", ("signoff_post_pnr.setup",),
        debug="fusion", show="fusion_post_pnr", stream=True,
    ),
    "compile_post_pnr": Target("compile_post_pnr", "gls_compile", "post_impl", quiet=True),
    "sim_post_pnr": Target("sim_post_pnr", "gls", "post_impl", debug="gls", quiet=True),
    "sim_post_pnr_all": Target("sim_post_pnr_all", "gls_all", "post_impl", debug="gls", show="gls_post_pnr", stream=True),
    "signoff_post_pnr": Target(
        "signoff_post_pnr", stage="post_impl", setup=("signoff_post_pnr.setup",),
        sequence=(
            "sdf_post_pnr", "sta_post_pnr", "sim_post_pnr_all",
            "power_estimate_post_pnr", "power_analysis_post_pnr_all",
            "fusion_analysis_post_pnr_all",
        ),
    ),
    "physical_signoff": Target(
        "physical_signoff", "physical", "post_impl", show="physical_signoff",
    ),
    "path_view": Target("path_view", "path_view", "post_syn"),
}


DESIGN_TARGETS: dict[str, Target] = {
    "hjson": Target("hjson", "hjson", domain="design"),
    "reg": Target("reg", "reg_rtl", domain="design"),
    "doc": Target("doc", "reg_docs", domain="design"),
    "systemrdl": Target("systemrdl", "systemrdl", domain="design"),
    "driver": Target("driver", "driver", domain="design"),
    "regmap_py": Target("regmap_py", "regmap_py", domain="design"),
    "rtl_stub": Target("rtl_stub", "rtl_scaffold", domain="design"),
    "top_from_core": Target("top_from_core", "rtl_top", domain="design"),
    "flist": Target("flist", "filelists", domain="design"),
    "slang_flist": Target("slang_flist", "filelists", domain="design"),
    "fetch": Target("fetch", "fetch", domain="design"),
    "slang_hier": Target("slang_hier", "slang_hier", domain="design"),
    "slang_ast": Target("slang_ast", "slang_ast", domain="design"),
    "model.setup": Target("model.setup", "model_setup", domain="design"),
}


DV_TARGETS: dict[str, Target] = {
    # Model-owned vector generation.
    "tests_gen": Target("tests_gen", "tests_generate", domain="dv"),
    "test_gen": Target("test_gen", "test_generate", domain="dv"),
    "tests": Target("tests", "tests_list", domain="dv"),

    # Functional DV scaffold and execution.
    "tb.setup": Target("tb.setup", "tb_setup", domain="dv"),
    "cocotb.setup": Target("cocotb.setup", "cocotb_setup", domain="dv"),
    "compile": Target("compile", "functional_compile", setup=("tb.setup",), debug="functional", domain="dv"),
    "compile_v": Target("compile_v", "functional_compile", setup=("tb.setup",), debug="functional", domain="dv"),
    "compile_sv": Target("compile_sv", "functional_compile", setup=("tb.setup",), debug="functional", domain="dv"),
    "sim": Target("sim", "functional_sim", setup=("tb.setup",), debug="functional", domain="dv"),
    "sim_v": Target("sim_v", "functional_sim", setup=("tb.setup",), debug="functional", domain="dv"),
    "sim_sv": Target("sim_sv", "functional_sim", setup=("tb.setup",), debug="functional", domain="dv"),
    "sim_tests": Target("sim_tests", "functional_regression_sv", setup=("tb.setup",), debug="functional", show="regression", domain="dv"),
    "cocotb": Target("cocotb", "functional_cocotb", setup=("cocotb.setup",), debug="functional", domain="dv"),
    "cocotb_tests": Target("cocotb_tests", "functional_regression_cocotb", setup=("cocotb.setup",), debug="functional", show="regression", domain="dv"),
    "regression": Target("regression", "functional_regression", setup=("tb.setup", "cocotb.setup"), debug="functional", show="regression", domain="dv"),
    "coverage": Target("coverage", "coverage", debug="coverage", show="coverage", domain="dv"),
    "coverage_detail": Target("coverage_detail", "coverage_detail", debug="coverage", show="coverage", domain="dv"),

    "lint_slang": Target("lint_slang", "lint_slang", show="lint", domain="dv"),
    "lint_verilator": Target("lint_verilator", "lint_verilator", show="lint", domain="dv"),
    "lint_slang_suite": Target("lint_slang_suite", "lint_slang_suite", show="lint", domain="dv"),
    "lint_verilator_suite": Target("lint_verilator_suite", "lint_verilator_suite", show="lint", domain="dv"),
    "lint": Target("lint", sequence=("lint_slang_suite", "lint_verilator_suite"), show="lint", domain="dv"),
    "lint_suite": Target("lint_suite", sequence=("lint_slang_suite", "lint_verilator_suite"), show="lint", domain="dv"),
    "lint_v": Target("lint_v", "lint_verilator", show="lint", domain="dv"),
    "lint_sv": Target("lint_sv", "lint_verilator", show="lint", domain="dv"),
    "lint_latch": Target("lint_latch", "lint_focus", show="lint", domain="dv"),
    "lint_undriven": Target("lint_undriven", "lint_focus", show="lint", domain="dv"),
    "lint_width": Target("lint_width", "lint_focus", show="lint", domain="dv"),
    "lint_unconnected": Target("lint_unconnected", "lint_focus", show="lint", domain="dv"),
    "lint_unused": Target("lint_unused", "lint_focus", show="lint", domain="dv"),
    "_lint_run": Target("_lint_run", "lint_focus", show="lint", domain="dv"),
    "cdc_rdc.setup": Target("cdc_rdc.setup", "cdc_setup", domain="dv"),
    "cdc_rdc": Target("cdc_rdc", "cdc", setup=("cdc_rdc.setup",), show="cdc_rdc", domain="dv"),

    "formal.prove.setup": Target("formal.prove.setup", "formal_setup", stage="prove", domain="dv"),
    "formal.cover.setup": Target("formal.cover.setup", "formal_setup", stage="cover", domain="dv"),
    "formal.csr_prove.setup": Target("formal.csr_prove.setup", "formal_csr_setup", stage="prove", domain="dv"),
    "formal.csr_cover.setup": Target("formal.csr_cover.setup", "formal_csr_setup", stage="cover", domain="dv"),
    "formal_bmc": Target("formal_bmc", "formal_bmc", setup=("formal.prove.setup",), show="formal", domain="dv"),
    "formal_prove": Target("formal_prove", "formal_prove", setup=("formal.prove.setup",), show="formal", domain="dv"),
    "formal_cover": Target("formal_cover", "formal_cover", setup=("formal.cover.setup",), show="formal", domain="dv"),
    "formal_csr_bmc": Target("formal_csr_bmc", "formal_csr_bmc", setup=("formal.csr_prove.setup",), show="formal", domain="dv"),
    "formal_csr_prove": Target("formal_csr_prove", "formal_csr_prove", setup=("formal.csr_prove.setup",), show="formal", domain="dv"),
    "formal_csr_cover": Target("formal_csr_cover", "formal_csr_cover", setup=("formal.csr_cover.setup",), show="formal", domain="dv"),
    "formal_csr": Target(
        "formal_csr",
        setup=("formal.csr_prove.setup", "formal.csr_cover.setup"),
        sequence=("formal_csr_bmc", "formal_csr_prove", "formal_csr_cover"),
        show="formal", domain="dv",
    ),
    "formal": Target(
        "formal",
        setup=(
            "formal.prove.setup", "formal.cover.setup",
            "formal.csr_prove.setup", "formal.csr_cover.setup",
        ),
        sequence=(
            "formal_csr_bmc", "formal_bmc", "formal_csr_prove",
            "formal_prove", "formal_csr_cover", "formal_cover",
        ),
        show="formal", domain="dv",
    ),
}


SYN_TARGETS: dict[str, Target] = {
    "yosys-vgen": Target("yosys-vgen", "yosys_vgen", domain="syn"),
    "sv2v": Target("sv2v", "sv2v", domain="syn"),
    "syn.setup": Target("syn.setup", "syn_setup", domain="syn"),
    "syn": Target("syn", "syn", setup=("syn.setup",), show="syn", domain="syn"),
    "syn_v": Target("syn_v", "syn_v", setup=("syn.setup",), show="syn", domain="syn"),
    "syn_sv": Target("syn_sv", "syn_sv", setup=("syn.setup",), show="syn", domain="syn"),
    "eqy.setup": Target("eqy.setup", "eqy_setup", domain="syn"),
    "eqy": Target("eqy", "eqy", setup=("eqy.setup",), show="eqy", domain="syn"),
}


IMPL_TARGETS: dict[str, Target] = {
    "pnr.setup": Target("pnr.setup", "pnr_setup", domain="impl"),
    "pnr": Target("pnr", "pnr", setup=("pnr.setup",), show="implementation", domain="impl"),
    "pnr_gui": Target("pnr_gui", "pnr_gui", setup=("pnr.setup",), show="implementation", domain="impl"),
}


WORKSPACE_TARGETS: dict[str, Target] = {
    "setup": Target("setup", "setup", domain="workspace"),
    "view": Target("view", "view", domain="workspace"),
    "view_cocotb": Target("view_cocotb", "view", domain="workspace"),
    "view_syn": Target("view_syn", "view", domain="workspace"),
    "plot_postsyn": Target("plot_postsyn", "view", domain="workspace"),
    "view_presyn": Target("view_presyn", "view", domain="workspace"),
    "view_presyn_v": Target("view_presyn_v", "view", domain="workspace"),
    "view_presyn_sv": Target("view_presyn_sv", "view", domain="workspace"),
    "tb_save": Target("tb_save", "view", domain="workspace"),
    "tb_view": Target("tb_view", "view", domain="workspace"),
    "clean-pyc": Target("clean-pyc", "clean_pyc", domain="workspace"),
    "clean_doc": Target("clean_doc", "clean_doc", domain="workspace"),
    "clean_log": Target("clean_log", "clean_log", domain="workspace"),
    "clean_rtl": Target("clean_rtl", "clean_rtl", domain="workspace"),
    "clean_sim": Target("clean_sim", "clean_sim", domain="workspace"),
    "clean_cocotb": Target("clean_cocotb", "clean_cocotb", domain="workspace"),
    "clean_formal": Target("clean_formal", "clean_formal", domain="workspace"),
    "clean_syn": Target("clean_syn", "clean_syn", domain="workspace"),
    "clean_signoff": Target("clean_signoff", "clean_signoff", domain="workspace"),
    "clean_meta": Target("clean_meta", "clean_meta", domain="workspace"),
    "clean_pnr": Target("clean_pnr", "clean_pnr", domain="workspace"),
    "clean_fsm": Target("clean_fsm", "clean_fsm", domain="workspace"),
    "clean_fsm_all": Target("clean_fsm_all", "clean_fsm_all", domain="workspace"),
    "clean_agent": Target("clean_agent", "clean_agent", domain="workspace"),
    "clean_fsoc": Target("clean_fsoc", "clean_fsoc", domain="workspace"),
    "clean_soc": Target("clean_soc", "clean_soc", domain="workspace"),
    "clean_sw": Target("clean_sw", "clean_sw", domain="workspace"),
    "clean_vendor": Target("clean_vendor", "clean_vendor", domain="workspace"),
    "clean_subdir": Target("clean_subdir", "clean_subdir", domain="workspace"),
    "clean": Target("clean", "clean", domain="workspace"),
    "clean_all": Target("clean_all", "clean_all", domain="workspace"),
}


TOOLCHAIN_TARGETS: dict[str, Target] = {
    "deps-bootstrap": Target("deps-bootstrap", "bootstrap", domain="toolchain"),
    "deps": Target("deps", "install", domain="toolchain"),
    "deps-doctor": Target("deps-doctor", "doctor", domain="toolchain"),
    "deps-versions": Target("deps-versions", "versions", domain="toolchain"),
    "deps-env": Target("deps-env", "env", domain="toolchain"),
    "deps-status": Target("deps-status", "status", domain="toolchain"),
    "deps-prune": Target("deps-prune", "prune", domain="toolchain"),
}


SOC_TARGETS: dict[str, Target] = {
    "soc_cfg": Target("soc_cfg", "config", domain="soc"),
    "soc_start": Target("soc_start", "start", domain="soc"),
    "fsoc_init": Target("fsoc_init", "fusesoc_init", domain="soc"),
    "fsoc": Target("fsoc", "fusesoc_build", domain="soc"),
    "xbar_init": Target("xbar_init", "xbar_init", domain="soc"),
    "xbar_build": Target("xbar_build", "xbar_build", domain="soc"),
    "soc": Target("soc", "generate", domain="soc"),
    "soc_uart_gen": Target("soc_uart_gen", "generate_uart", domain="soc"),
    "soc_ibex_gen": Target("soc_ibex_gen", "generate_ibex", domain="soc"),
    "sw_soc": Target("sw_soc", "software", domain="soc"),
    "soc_prepare": Target("soc_prepare", "prepare", domain="soc"),
    "soc_build_sw": Target("soc_build_sw", "build_sw", domain="soc"),
    "soc_sim": Target("soc_sim", "sim_build", domain="soc"),
    "soc_run": Target("soc_run", "sim_run", domain="soc"),
    "soc_view": Target("soc_view", "view", domain="soc"),
}


FSM_TARGETS: dict[str, Target] = {
    "fsm_setup": Target("fsm_setup", "setup", domain="fsm"),
    "fsm_example_load": Target("fsm_example_load", "load_example", domain="fsm"),
    "fsm_gen": Target("fsm_gen", "generate", domain="fsm"),
    "fsm_plot": Target("fsm_plot", "plot", domain="fsm"),
    "fsm_install": Target("fsm_install", "install", domain="fsm"),
}


CORE_TARGETS: dict[str, Target] = {
    "spec": Target("spec", "spec", domain="qualification"),
    "ipxact": Target("ipxact", "ipxact", domain="package"),
    "metrics": Target("metrics", "metrics", show="metrics", domain="reporting"),
    "manifest": Target("manifest", "manifest", show="manifest", domain="reporting"),
    "manifest_show": Target("manifest_show", "show", show="manifest", domain="reporting"),
    "check": Target("check", "show", show="metrics", domain="reporting"),
    "status": Target("status", "status", show="qualification", domain="qualification"),
    "qualify": Target("qualify", "qualify", show="qualification", domain="qualification"),
    "ip_load": Target("ip_load", "load", domain="package"),
    "ip_save": Target("ip_save", "save", domain="package"),
}


BACKEND_TARGETS: dict[str, Target] = {
    **DESIGN_TARGETS,
    **DV_TARGETS,
    **SYN_TARGETS,
    **SIGNOFF_TARGETS,
    **IMPL_TARGETS,
    **WORKSPACE_TARGETS,
    **TOOLCHAIN_TARGETS,
    **SOC_TARGETS,
    **FSM_TARGETS,
    **CORE_TARGETS,
}


__all__ = [
    "Target", "DESIGN_TARGETS", "DV_TARGETS", "SYN_TARGETS", "SIGNOFF_TARGETS",
    "IMPL_TARGETS", "WORKSPACE_TARGETS", "TOOLCHAIN_TARGETS", "SOC_TARGETS",
    "FSM_TARGETS", "CORE_TARGETS", "BACKEND_TARGETS",
]
