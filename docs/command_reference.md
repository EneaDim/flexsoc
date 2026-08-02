# 🧭 FlexSoC command reference

This is the complete user-facing reference for the `fx` command line and every backend target currently exposed by FlexSoC. It follows the same lifecycle as [Project lifecycle](project_lifecycle.md): configure the run, enter the IP, verify it, synthesize it, prove equivalence, analyze timing and power, implement it, and collect release evidence.

The reference explains what each command owns. It does not replace tool logs or the underlying EDA manuals. Use `fx <target> --info` and `fx commands --json` when a script needs the live metadata from the installed checkout.

> **Execution model:** `fx target_a target_b` launches separate backend targets in the order written. Make prerequisites inside each target remain fail-fast, but a failure in one explicitly listed top-level target does not suppress later targets. Use a composite target or shell `&&` when the top-level sequence itself must stop immediately.

---

## 1. Command-line model

```text
fx [pseudo-command | target ...] [global options]
```

Examples:

```bash
fx settings TOP=my_ip RUN_ID=dev
fx hjson reg doc --force
fx lint_suite regression formal
fx syn eqy --set EQY_JOBS=8 --live
fx setup_signoff --dry-run --script
```

Persistent settings are stored in `.flexsoc/settings.json`. One-shot `--set KEY=VALUE` overrides affect only the current invocation. `--workdir` selects the workspace without changing the repository used as the Make working directory.

### 1.1 Pseudo-commands

| Command | Purpose | Important behavior |
| --- | --- | --- |
| `fx` / `fx --help` | Show the curated CLI guide. | Does not execute Make. |
| `fx commands` | List all backend targets, groups, descriptions, and accepted variables. | Add `--json` for machine-readable metadata. |
| `fx settings [KEY=VALUE ...]` | Show or update persistent project settings and derived run paths. | Supports `--set`, `--unset`, `--reset`, `--workdir`, and `--json`. Clock relationships are cleared automatically when domains change unless explicitly supplied. |
| `fx doctor` | Check Python, lock files, and installed EDA tools. | Add `--json` for CI or provisioning scripts. |
| `fx pdk list` | List known PDK profiles and local readiness. | `--json` returns the catalogue. |
| `fx pdk info <name>` | Show source, node, digital views, OpenROAD platform, and formal adapter. | `--set PDK_ROOT=...` inspects a non-default installation. |
| `fx pdk fetch <name>` | Fetch the configured PDK source/provider. | `--force` refreshes; `--set PDK_VERSION=...` selects a supported version. |
| `fx pdk use <name>` | Validate digital views and persist the active PDK. | Requires at least a typical Liberty and functional gate-level Verilog model. |
| `fx eqy_debug [partition]` | Summarize EQY closure or diagnose one unresolved partition. | Supports `--wave`, `--files`, `--json`, and reset overrides through `--set`. |
| `fx shell` | Open an interactive prompt with target completion and history. | `help`, `commands`, `exit`, and normal target lines are accepted. |

### 1.2 Global options

| Option | Scope | Meaning |
| --- | --- | --- |
| `--set KEY=VALUE`, `-s` | Any target; also settings | Add a one-shot Make/config override. Repeatable. |
| `--unset KEY` | `settings` | Remove a persisted setting. Repeatable. |
| `--reset` | `settings` | Reset persisted settings to defaults before applying updates. |
| `--project-root PATH` | Any command | Use another FlexSoC checkout as the repository/Make root. |
| `--workdir PATH` | Any run command | Select the external workspace passed as `WORKSPACE`. |
| `--tool NAME` | Lint targets | Shortcut for `--set LINT_TOOL=NAME`. |
| `--user` / `--system` | Dependency targets only | Select rootless user or shared/system installation mode. |
| `--profile base|impl|riscv` | Dependency targets only | Select the pinned dependency profile. |
| `--jobs N` | Dependency targets only | Set dependency build jobs. EQY parallelism uses `--set EQY_JOBS=N`. |
| `--force`, `--overwrite` | Generated targets | Set `FORCE=1`; authored files should still be reviewed before regeneration. |
| `--dry-run` | Backend targets | Print the exact command without executing it. |
| `--script` | With `--dry-run` | Render the preview as a strict Bash script. |
| `--capture` | Backend targets | Capture stdout/stderr and save a per-command log. |
| `--live` | Backend targets | Stream complete tool output while retaining the command log. |
| `--json` | Supported pseudo-commands and execution output | Emit machine-readable JSON. |
| `--info` | Backend targets | Describe selected targets and accepted variables instead of running them. |

### 1.3 Canonical run configuration

The variables below define the identity and clock model consumed by every backend:

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS=
```

For N-clock designs, list every domain and declare only real relationships. FlexSoC does not infer that all domains are asynchronous.

---

## 2. Lifecycle command map

| Lifecycle gate | Primary commands | Evidence produced |
| --- | --- | --- |
| Environment and technology | `fx doctor`, `fx deps-doctor`, `fx pdk info`, `fx pdk use` | Tool/PDK readiness |
| Requirements to CSR/RTL entry | `fx setup`, `fx hjson`, `fx reg`, `fx doc`, `fx rtl_stub`, `fx top_from_core` | Register collateral and authored RTL boundary |
| Structural RTL closure | `fx flist`, `fx lint_suite`, `fx slang_hier`, `fx slang_ast` | Reachable hierarchy and clean lint |
| Functional DV | `fx setup_model`, `fx tests_gen`, `fx setup_tb`, `fx setup_cocotb`, `fx regression`, `fx coverage_detail` | Passing scenarios, waves, coverage |
| Property formal | `fx setup_formal`, `fx formal` | BMC/prove/cover closure |
| Constraints and synthesis | `fx setup_sdc`, `fx setup_syn`, `fx syn` | SDC, mapped netlist, synthesis reports |
| Logical sign-off | `fx setup_eqy`, `fx eqy`, `fx eqy_debug` | RTL ↔ mapped-netlist equivalence |
| Post-synthesis sign-off | `fx setup_signoff`, `fx sdf`, `fx sta`, `fx power_estimate`, gate simulation targets | Timing, SDF/GLS, and power evidence |
| Physical implementation | `fx setup_pnr`, `fx pnr`, `fx pnr_gui` | Placed/routed implementation |
| Post-layout sign-off | `fx sdf_post_pnr`, `fx compile_post_pnr`, `fx sim_post_pnr`, external physical verification | Final timing-aware simulation and physical evidence |
| Release | `fx manifest`, `fx metrics`, `fx check`, `fx ip_save` | Traceable release metadata and reusable authored sources |

---

## 3. Complete backend target catalogue

Every target below is accepted by the current Python API. The tables omit the common run identity, clock settings, workspace, and `FORCE`; the remaining target-specific overrides are shown explicitly. All variables are defined in the [variable reference](#4-variable-reference), while `fx <target> --info` remains the exact live source.

### 3.1 Dependencies

Prepare and inspect the pinned toolchain before running design targets.

**Main result:** Repository/tool installation; no IP run artifacts.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx deps-bootstrap` | Check/install prerequisites for a dependency profile. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |
| `fx deps` | Install pinned base, impl, or riscv profile. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |
| `fx deps-doctor` | Verify the selected pinned dependency profile. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |
| `fx deps-versions` | Show pinned tool versions and revisions. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx deps-env` | Print shell exports for the pinned toolchain. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |

### 3.2 Setup

Create the run layout and initialize IP or SoC workspaces.

**Main result:** `<WORKSPACE>/runs/<RUN_TOP>/<RUN_ID>/`.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx setup` | Create the run directory tree. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx soc_cfg` | Render SoC configuration variables. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_start` | Initialize a SoC run from loaded IPs. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |

### 3.3 IP flow

Enter the IP specification, generate register collateral, maintain the RTL wrapper, and run composite IP flows.

**Main result:** `data/`, `rtl/`, `doc/`, generated drivers, and flow reports.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx hjson` | Generate an HJSON register template. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx hjson_gen` | Compatibility alias for HJSON generation. | `REG_ITF` | Compatibility alias; prefer `fx hjson`. |
| `fx reg` | Generate register RTL from HJSON. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx doc` | Generate register documentation. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx rtl_stub` | Generate RTL core and aligned top wrapper. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx top_from_core` | Regenerate top wrapper from edited core ports. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx flist` | Generate Slang-ordered common/IP RTL filelists. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx driver` | Generate C driver files from HJSON. | `REG_ITF` | Use `--info` for accepted overrides. |
| `fx fetch` | Fetch or update a vendored dependency. | `VENDOR`, `TARGET` | Use `--info` for accepted overrides. |
| `fx ip_start` | Bootstrap a complete IP run. | `REG_ITF`, `LINT_TOOL`, `LINT_PART`, `TARGET_SYN`, `TARGET_OPT` | Use `--info` for accepted overrides. |
| `fx ip_flow` | Run regression, formal, synthesis, signoff, and final reports. | `REG_ITF`, `LINT_TOOL`, `LINT_PART`, `TARGET_SYN`, `TARGET_OPT` | Composite target; use it for the standard ordered flow. |
| `fx ip_flow_noreg` | Run full closure without regenerating registers. | `REG_ITF` | Composite target; use it for the standard ordered flow. |
| `fx ip_flow_all` | Run full IP flow including PnR. | `REG_ITF`, `LINT_TOOL`, `LINT_PART`, `TARGET_SYN`, `TARGET_OPT` | Composite target; use it for the standard ordered flow. |

### 3.4 Linting

Elaborate the reachable hierarchy and detect structural RTL issues before simulation or synthesis.

**Main result:** Ordered filelists, hierarchy/AST reports, and lint logs.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx lint` | Run Slang lint first, then Verilator lint. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_slang` | Run Slang HDL lint. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_verilator` | Run Verilator HDL lint. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_slang_suite` | Run the full Slang lint suite. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_verilator_suite` | Run the full Verilator lint suite. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_suite` | Run full Slang suite, then full Verilator suite. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_v` | Run Verilog lint checks. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_sv` | Run SystemVerilog lint checks. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_latch` | Run latch-focused HDL lint diagnostics. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_undriven` | Run undriven-signal HDL lint diagnostics. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_width` | Run width-focused HDL lint diagnostics. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_unconnected` | Run unconnected-port HDL lint diagnostics. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx lint_unused` | Run unused-object HDL lint diagnostics. | `LINT_TOOL`, `LINT_PART`, `VSV` | Use `--info` for accepted overrides. |
| `fx _lint_run` | Internal lint dispatcher. | `LINT_TOOL`, `LINT_PART`, `VSV` | Internal dispatcher used by lint targets; do not call directly. |
| `fx slang_hier` | Generate hierarchy text with slang-hier. | `LINT_TOOL`, `LINT_PART`, `VSV`, `SLANG_ROOT`, `SLANG_TOP_FILE`, `SLANG_TOP`, `SLANG_ARGS`, `SLANG_SEARCH_ARGS`, `SLANG_AST_SCOPE` | Use `--info` for accepted overrides. |
| `fx slang_ast` | Generate Slang AST JSON. | `LINT_TOOL`, `LINT_PART`, `VSV`, `SLANG_ROOT`, `SLANG_TOP_FILE`, `SLANG_TOP`, `SLANG_ARGS`, `SLANG_SEARCH_ARGS`, `SLANG_AST_SCOPE` | Use `--info` for accepted overrides. |
| `fx slang_flist` | Generate a trimmed topological RTL filelist with Slang. | `LINT_TOOL`, `LINT_PART`, `VSV`, `SLANG_ROOT`, `SLANG_TOP_FILE`, `SLANG_TOP`, `SLANG_ARGS`, `SLANG_SEARCH_ARGS`, `SLANG_AST_SCOPE` | Use `--info` for accepted overrides. |

### 3.5 DV functional

Generate the reference-model environment, vectors, testbenches, simulations, regressions, and coverage.

**Main result:** `dv/functional/`, simulator build trees, waveforms, and coverage reports.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx setup_tb` | Generate a SystemVerilog testbench scaffold. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx setup_cocotb` | Generate a cocotb scaffold. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx setup_model` | Generate Python model, CSR regmap, and test scaffolds. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx regmap_py` | Regenerate only `<top>_regmap.py` from HJSON. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx tests_gen` | Generate all vector tests from `<top>_tests.py`. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx test_gen` | Generate one vector test selected by TEST_NAME. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx tests` | List generated vector tests. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx compile` | Compile the current testbench. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx compile_v` | Compile Verilog simulation. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx compile_sv` | Compile SystemVerilog simulation. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx sim` | Run simulation. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx sim_v` | Run Verilog simulation. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx sim_sv` | Run SystemVerilog simulation. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx sim_tests` | Run every generated SystemVerilog vector test. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx cocotb` | Run cocotb tests. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx cocotb_tests` | Run every generated cocotb vector test. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx regression` | Run all tests on selected backends with Verilator coverage. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Composite target; use it for the standard ordered flow. |
| `fx coverage` | Merge and report existing Verilator coverage data. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx coverage_detail` | Show uncovered Verilator coverage points. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |

### 3.6 Viewing

Inspect waveforms and saved simulation or synthesis views without changing design state.

**Main result:** Interactive viewer sessions and saved debug bundles.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx view` | Open latest waveform. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_cocotb` | Open latest cocotb waveform. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_syn` | Reserved synthesis waveform viewer target. | `WAVE_VIEWER`, `SURFER_BACKEND` | Reserved target; currently no implementation. |
| `fx plot_postsyn` | Open post-synthesis graph. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_presyn` | Open pre-synthesis graph. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_presyn_v` | Open pre-synthesis graph from Verilog. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_presyn_sv` | Open pre-synthesis graph from SV. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx tb_save` | Save testbench regression artifacts. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx tb_view` | Open saved testbench waveform. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |

### 3.7 DV formal

Generate and execute automatic CSR checks and authored property BMC/prove/cover stages.

**Main result:** `dv/formal/` configurations, proof logs, traces, and status files.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx setup_formal` | Prepare CSR formal and any authored design-property configurations. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx setup_formal_csr_prove` | Generate shared CSR BMC/prove configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx setup_formal_csr_cover` | Generate automatic CSR cover configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_csr_bmc` | Bounded-check automatic CSR assertions. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_csr_prove` | Prove automatic CSR semantics with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_csr_cover` | Reach automatic CSR cover points with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_csr` | Run CSR BMC, prove, then cover. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Composite target; use it for the standard ordered flow. |
| `fx formal` | Run all formal stages BMC, prove, then cover. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Composite target; use it for the standard ordered flow. |
| `fx setup_formal_prove` | Generate shared design BMC/prove configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx setup_formal_cover` | Generate authored-property cover configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_bmc` | Bounded-check authored design assertions. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_prove` | Prove authored properties with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_cover` | Reach authored cover properties with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |

### 3.8 Synthesis

Generate timing constraints and Yosys scripts, then map RTL to the selected PDK.

**Main result:** `constraints/` and `syn/<PDK>/` netlists, logs, statistics, and checkpoints.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx setup_sdc` | Generate timing constraints. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx setup_syn` | Generate Yosys synthesis scripts. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx syn` | Run synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx syn_v` | Run Verilog synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx syn_sv` | Run SystemVerilog synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx yosys-vgen` | Convert SV to Verilog with Yosys. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx sv2v` | Convert SV to Verilog with sv2v. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |

### 3.9 Signoff

Prove RTL/netlist equivalence and generate or execute pre-layout timing, SDF, and power analysis.

**Main result:** `signoff/equivalence/`, `signoff/sta/`, `signoff/sdf/`, and `signoff/power/`.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx sta_corners` | Run STA setup/hold for each configured corner. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Runs all configured technology corners. |
| `fx power_estimate_corners` | Estimate power for each corner using global activity. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Runs all configured technology corners. |
| `fx signoff_corners` | Run SDF, multi-corner STA and estimated power. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Runs all configured technology corners. |
| `fx setup_eqy` | Generate RTL-vs-post-synthesis EQY configuration. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN`, `SBY`, `EQY`, `EQY_SAT_DEPTH`, `EQY_DEPTH`, `EQY_ENGINE`, `EQY_TIMEOUT`, `EQY_QUICK_TIMEOUT`, `EQY_JOBS`, `EQY_USE_SAT`, `EQY_SPLITNETS`, `EQY_USE_PDR`, `EQY_PDR_ENGINE`, `EQY_SMT_ENGINE`, `EQY_SMT_DEPTH`, `EQY_XPROP`, `EQY_JOIN_OUTPUTS`, `EQY_STRATEGY_ORDER`, `PRIM`, `FORMAL_PDK_PROC` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx eqy` | Prove RTL equivalent to the post-synthesis netlist with EQY. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN`, `SBY`, `EQY`, `EQY_SAT_DEPTH`, `EQY_DEPTH`, `EQY_ENGINE`, `EQY_TIMEOUT`, `EQY_QUICK_TIMEOUT`, `EQY_JOBS`, `EQY_USE_SAT`, `EQY_SPLITNETS`, `EQY_USE_PDR`, `EQY_PDR_ENGINE`, `EQY_SMT_ENGINE`, `EQY_SMT_DEPTH`, `EQY_XPROP`, `EQY_JOIN_OUTPUTS`, `EQY_STRATEGY_ORDER`, `PRIM`, `FORMAL_PDK_PROC` | Use `--info` for accepted overrides. |
| `fx setup_signoff` | Generate signoff scripts. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx compile_syn` | Compile post-synthesis simulation. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx sim_syn` | Run post-synthesis simulation. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx sta` | Run static timing analysis. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx sdf` | Write SDF timing files. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx power_estimate` | Estimate power using global switching activity. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx sta_violators` | Report timing violators. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx path_view` | Build interactive STA path view. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |

### 3.10 Gate simulation

Compile and run mapped or post-route gate-level simulations, optionally with SDF annotation.

**Main result:** Gate-simulation executables, logs, and waveforms.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx compile_post_syn` | Compile post-synthesis gate-level simulation with Icarus. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sim_post_syn` | Run post-synthesis gate-level simulation with optional SDF. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx compile_post_pnr` | Compile post-PnR gate-level simulation with Icarus. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sdf_post_pnr` | Export post-PnR SDF from final netlist, SDC and SPEF. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sim_post_pnr` | Run post-PnR gate-level simulation with optional SDF. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `TIMING_MODE`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |

### 3.11 Place and route

Generate OpenROAD configuration, implement the design, and inspect the physical result.

**Main result:** `pnr_openroad/<PDK>/` implementation collateral and reports.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx setup_pnr` | Generate OpenROAD config. | `PDK`, `PDK_ROOT`, `ORS`, `ORS_TECH` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx pnr` | Run OpenROAD place and route. | `PDK`, `PDK_ROOT`, `ORS`, `ORS_TECH` | Use `--info` for accepted overrides. |
| `fx pnr_gui` | Open OpenROAD GUI. | `PDK`, `PDK_ROOT`, `ORS`, `ORS_TECH` | Use `--info` for accepted overrides. |

### 3.12 Run metadata

Consolidate run identity, metrics, and closure status for review and release.

**Main result:** `meta/manifest.json`, metrics, and status summaries.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx metrics` | Collect functional/formal/synthesis/signoff metrics. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx manifest` | Collect automatic run identity into meta/manifest.json. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx manifest_show` | Show the current run manifest in color. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx check` | Show complete current run closure status and metrics. | Common run/clock settings only | Use `--info` for accepted overrides. |

### 3.13 IP load/save

Move authored IP sources between the reusable library and an isolated run workspace.

**Main result:** `hw/ips/<IP_NAME>/` and the selected run directories.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx ip_load` | Load an IP into a run workspace. | `IP_NAME` | Use `--info` for accepted overrides. |
| `fx ip_save` | Save authored IP sources back to hw/ips. | `IP_NAME` | Use `--info` for accepted overrides. |

### 3.14 SoC flow

Compose loaded IPs into a small SoC, generate crossbar/FuseSoC collateral, build software, and simulate.

**Main result:** SoC RTL, crossbar files, FuseSoC metadata, software, simulator, and waveforms.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx soc_vendor_deps` | Fetch pinned lowRISC dependencies required by SoC simulation. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx fsoc_init` | Initialize FuseSoC metadata. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx fsoc` | Generate FuseSoC core file. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx xbar` | Generate crossbar artifacts. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx xbar_init` | Generate crossbar input config. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx xbar_build` | Run tlgen for crossbar RTL. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc` | Generate SoC RTL. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_stage_tops` | Stage SoC top-level files. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_flist` | Generate Slang-ordered SoC common/IP filelists. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_flow` | Generate crossbar, SoC RTL and filelist. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Composite target; use it for the standard ordered flow. |
| `fx soc_uart_gen` | Generate UART-host SoC artifacts. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_ibex_gen` | Generate Ibex-host SoC artifacts. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx sw_soc` | Generate SoC software scaffold. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_prepare` | Prepare SoC build directory. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_build_sw` | Build SoC software. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_sim` | Build SoC simulator. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_run` | Run SoC simulation. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |
| `fx soc_run_only` | Alias for SoC simulation run. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Alias for `fx soc_run`. |
| `fx soc_view` | Open SoC waveform. | `HOST`, `SOC_CFG_MODE`, `DEVLIST` | Use `--info` for accepted overrides. |

### 3.15 FSM flow

Generate, visualize, and install finite-state-machine RTL from the FSM workspace.

**Main result:** FSM RTL, diagrams, and installed IP collateral.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx fsm_init` | Create FSM workspace directories. | `FSM` | Use `--info` for accepted overrides. |
| `fx fsm_setup` | Set up the FSM generator. | `FSM` | Use `--info` for accepted overrides. |
| `fx fsm_example_load` | Load the FSM example inputs. | `FSM` | Use `--info` for accepted overrides. |
| `fx fsm_gen` | Generate FSM RTL. | `FSM` | Use `--info` for accepted overrides. |
| `fx fsm_plot` | Plot FSM diagrams. | `FSM` | Use `--info` for accepted overrides. |
| `fx fsm_flow` | Generate and plot FSM artifacts. | `FSM` | Composite target; use it for the standard ordered flow. |
| `fx fsm_install` | Install FSM artifacts into the IP run. | `FSM` | Use `--info` for accepted overrides. |
| `fx fsm2rtl` | Alias for FSM RTL installation. | `FSM` | Alias for `fx fsm_install`. |

### 3.16 Tutorials

Run reproducible tutorial workflows for IP, FSM, UART-host, and Ibex-host examples.

**Main result:** Tutorial-specific workspaces and normal run artifacts.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx soc_uart_tutorial` | Run UART-host SoC tutorial. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Composite tutorial workflow. |
| `fx soc_ibex_fetch` | Fetch Ibex tutorial dependencies. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Use `--info` for accepted overrides. |
| `fx soc_ibex_tutorial` | Run Ibex-host SoC tutorial. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Composite tutorial workflow. |
| `fx full_tutorial` | Run the full IP tutorial flow. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Composite tutorial workflow. |
| `fx fsm_tutorial` | Run the FSM tutorial flow. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Composite tutorial workflow. |
| `fx ip_tutorial` | Run the IP tutorial flow. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Composite tutorial workflow. |
| `fx soc_pless` | Run the tiny SoC tutorial flow. | `TUTORIAL_WS`, `TUTORIAL_RUN_ID` | Use `--info` for accepted overrides. |

### 3.17 Cleanup

Remove selected generated products while preserving authored sources unless the deep-clean target explicitly says otherwise.

**Main result:** Deleted run subtrees; inspect with `--dry-run` before broad cleanup.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx clean-pyc` | Remove Python caches. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_doc` | Remove generated docs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_log` | Remove logs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_rtl` | Remove generated RTL. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_sim` | Remove simulation outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_cocotb` | Remove cocotb outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_formal` | Remove property-formal proof outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_syn` | Remove synthesis outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_signoff` | Remove signoff outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_meta` | Remove run metadata. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_pnr` | Remove PnR outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_fsm` | Clean FSM generator outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_fsm_all` | Deep-clean FSM generator outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_agent` | Remove old agent outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_fsoc` | Remove FuseSoC build outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_soc` | Remove SoC build outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_sw` | Clean SoC software outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_vendor` | Remove vendored IP checkouts. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_subdir` | Clean helper subdirectories. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean` | Clean generated flow outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |
| `fx clean_all` | Remove all generated run outputs. | Common run/clock settings only | Destructive for generated outputs; preview broad cleanup with `--dry-run`. |

### 3.18 Help

Print backend help grouped for common development areas.

**Main result:** Terminal output only.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx help` | Show backend target help. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx help_ip` | Show IP-flow help. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx help_soc` | Show SoC-flow help. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx help_doc` | Show documentation-flow help. | Common run/clock settings only | Backend documentation help; the maintained documents are this reference, the lifecycle, and the quickstart. |
| `fx help_fsm` | Show FSM-flow help. | Common run/clock settings only | Use `--info` for accepted overrides. |

---

## 4. Variable reference

Variables can be persisted with `fx settings`, supplied for one invocation with `--set`, or derived automatically from the PDK and run layout. Not every target accepts every variable; `fx commands` and `fx <target> --info` are authoritative.

| Variable | Meaning |
| --- | --- |
| `TOP` | IP/module name used by generators and tool scripts. |
| `RUN_ID` | Configuration/run revision inside `runs/<RUN_TOP>/`. |
| `WORKSPACE` | External workspace root; set with `--workdir` for most CLI use. |
| `N_CLOCKS` | Number of declared clock domains. |
| `CLOCK_DOMAINS` | `name:clock:reset:period_ns:polarity` entries, comma-separated. |
| `CLOCK_RELATIONSHIPS` | Explicit `async`, `sync`, or `generated` domain relationships. |
| `RUN_TOP` | Run namespace; defaults to `TOP` when omitted. |
| `FORCE` | Overwrite machine-generated collateral where the target supports regeneration. |
| `HOST` | SoC host selection, normally `uart` or `ibex`. |
| `SOC_CFG_MODE` | SoC configuration source mode. |
| `DEVLIST` | IP/device list used for SoC composition. |
| `PDK` | Active PDK profile name. |
| `PDK_ROOT` | Root containing usable digital PDK views. |
| `LIBS` | Technology Liberty set used by sign-off. |
| `LIB_SYN` | Primary synthesis Liberty view. |
| `PRIM` | Technology primitive/formal model input. |
| `WAVE_FORMAT` | Waveform format: `fst` or `vcd`. |
| `WAVE_FILE` | Explicit waveform input for viewers, power, or simulation. |
| `GLS_SIMULATOR` | Gate-level simulator selection. |
| `TIMING_MODE` | Timing analysis mode, commonly `max` or `min`. |
| `SDF_FILE` | Explicit SDF file for gate simulation. |
| `SDF_CORNER` | Selected SDF process/timing corner. |
| `NETLIST` | Explicit mapped or final implementation netlist. |
| `SPEF_FILE` | Extracted parasitic file for post-route analysis. |
| `PNR_SDC_FILE` | Final implementation SDC for post-route timing/SDF. |
| `POWER_ACTIVITY` | Global switching activity assumption. |
| `POWER_DUTY` | Global duty-cycle assumption. |
| `PATH_VIEW_FILE` | Timing path data used by the interactive viewer. |
| `NPATHS` | Number of timing paths to report or visualize. |
| `REG_ITF` | Register interface style passed to register-generation targets. |
| `VENDOR` | Vendor/dependency identifier. |
| `TARGET` | Fetch/build target used by dependency or vendor commands. |
| `LINT_TOOL` | Selected lint backend or suite control. |
| `LINT_PART` | Optional lint diagnostic subset. |
| `TARGET_SYN` | Synthesis goal/profile. |
| `TARGET_OPT` | Synthesis optimization goal, such as area or timing. |
| `VSV` | Select Verilog (`v`) or SystemVerilog path where supported. |
| `SLANG_ROOT` | Root used for recursive Slang source discovery. |
| `SLANG_TOP_FILE` | Explicit top source file for Slang diagnostics. |
| `SLANG_TOP` | Top design unit for Slang diagnostics. |
| `SLANG_ARGS` | Additional Slang compiler arguments. |
| `SLANG_SEARCH_ARGS` | Additional include/library search arguments. |
| `SLANG_AST_SCOPE` | Optional AST scope filter. |
| `TESTBENCH` | Testbench module/file selection. |
| `TEST_NAMES` | Explicit list of generated tests. |
| `TEST_NAME` | One generated vector test to build or run. |
| `REGCFG` | Register configuration vector/input file. |
| `DATA_IN` | Stimulus data vector/input file. |
| `DATA_OUT` | Expected-output vector file. |
| `COMPILER` | Simulation compiler/backend selection. |
| `COCOTB_WAVES` | Enable cocotb waveform dumping. |
| `SEED` | Random or regression seed. |
| `REGRESSION_BACKENDS` | Simulation backends included in regression. |
| `COVERAGE` | Enable or configure coverage collection. |
| `COVERAGE_DETAIL_LIMIT` | Maximum uncovered items printed by detailed coverage. |
| `WAVE_VIEWER` | Waveform viewer executable. |
| `SURFER_BACKEND` | Surfer rendering/backend choice. |
| `CLK_PERIOD` | Fallback synthesis clock period; canonical domains normally derive it. |
| `SBY` | SymbiYosys executable. |
| `FORMAL_DEPTH` | Default authored-property proof depth. |
| `FORMAL_BMC_DEPTH` | Bounded model-check depth. |
| `FORMAL_BMC_APPEND` | Additional BMC depth/append control. |
| `FORMAL_BMC_ENGINE` | Engine used for authored-property BMC. |
| `FORMAL_PROVE_ENGINE` | Engine used for authored-property proof. |
| `FORMAL_COVER_ENGINE` | Engine used for cover reachability. |
| `EQY` | EQY executable. |
| `EQY_SAT_DEPTH` | SAT strategy induction depth. |
| `EQY_DEPTH` | Legacy/general EQY depth control. |
| `EQY_ENGINE` | Legacy/general EQY engine override. |
| `EQY_TIMEOUT` | Full strategy timeout in seconds. |
| `EQY_QUICK_TIMEOUT` | Fast-filter strategy timeout in seconds. |
| `EQY_JOBS` | Parallel EQY partition jobs. |
| `EQY_USE_SAT` | Enable the SAT strategy where compatible. |
| `EQY_SPLITNETS` | Control net splitting during equivalence preparation. |
| `EQY_USE_PDR` | Enable PDR/IC3 strategy. |
| `EQY_PDR_ENGINE` | PDR engine command, normally ABC PDR. |
| `EQY_SMT_ENGINE` | SMTBMC solver, normally Bitwuzla. |
| `EQY_SMT_DEPTH` | SMTBMC proof depth. |
| `EQY_XPROP` | Enable safe X-propagation handling. |
| `EQY_JOIN_OUTPUTS` | Join top-level output buses into one partition per bus. |
| `EQY_STRATEGY_ORDER` | Strategy portfolio order or `auto`. |
| `FORMAL_PDK_PROC` | PDK-specific formal adaptation script. |
| `TEST_ROOT` | Root containing gate-simulation vectors/collateral. |
| `ORS` | OpenROAD-flow-scripts root. |
| `ORS_TECH` | Selected OpenROAD platform/technology directory. |
| `IP_NAME` | Reusable IP library name. |
| `FSM` | FSM workspace or design name. |
| `TUTORIAL_WS` | Tutorial workspace root. |
| `TUTORIAL_RUN_ID` | Tutorial run identifier. |
| `DEPS_MODE` | Dependency installation mode: user or system. |
| `DEPS_PROFILE` | Pinned dependency profile: base, impl, or riscv. |
| `DEPS_JOBS` | Parallel dependency build jobs. |
| `PDK_VERSION` | Optional PDK fetch version/revision override. |
| `EQY_CLOCK` | Manual clock override for targeted EQY reset diagnostics. |
| `EQY_RESET` | Manual reset override for targeted EQY diagnostics. |
| `EQY_RESET_ACTIVE` | Manual reset polarity (`low` or `high`) for EQY diagnostics. |
| `EQY_RESET_CYCLES` | Number of reset cycles used by the EQY reset-state probe. |

---

## 5. Command selection by change type

### Add or change a CSR

```bash
fx reg doc regmap_py tests_gen --force
fx flist lint_suite
fx regression formal
fx syn eqy --force
```

### Change RTL behavior or latency

```bash
fx flist lint_suite --force
fx tests_gen regression --force
fx formal
fx syn eqy --force
fx sdf sta power_estimate --force
```

### Change top-level ports

```bash
fx top_from_core flist setup_tb setup_cocotb --force
fx lint_suite regression formal
fx syn eqy --force
```

### Change clock/reset domains

```bash
fx settings N_CLOCKS=<n> CLOCK_DOMAINS=<domains> CLOCK_RELATIONSHIPS=<relations>
fx setup_tb setup_cocotb setup_formal setup_sdc setup_syn setup_eqy setup_signoff --force
fx flist lint_suite regression formal
fx syn eqy sdf sta power_estimate --force
```

### Diagnose a failed target

```bash
fx <target> --live
fx <target> --dry-run --script
fx <target> --info
fx check
```

For equivalence specifically:

```bash
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --wave <partition>
fx eqy_debug --files <partition>
```

---

## 6. Production-use rules

1. Persist stable run identity and clock intent; use one-shot overrides for experiments.
2. Regenerate only machine-owned collateral and review every `--force` change.
3. Treat lint, simulation, coverage, formal proof, equivalence, STA, power, and physical closure as different gates.
4. Use composite targets for the standard flow, but use explicit stage targets while debugging.
5. Keep PDK, tool versions, settings, logs, metrics, and manifests with every release candidate.
6. Preview destructive cleanup and generated scripts with `--dry-run` before production runs.
7. Use `fx commands --json` in automation instead of scraping terminal tables.

See [Project lifecycle](project_lifecycle.md) for engineering rationale and [Quickstart](quickstart.md) for the shortest runnable flow.
