# 🧭 FlexSoC command reference

This is the complete user-facing reference for the `fx` command line and every backend target currently exposed by FlexSoC. It follows the same lifecycle as [Project lifecycle](project_lifecycle.md): configure the run, enter the IP, verify it, synthesize it, prove equivalence, analyze timing and power, implement it, and collect release evidence.

The reference explains what each command owns. The detailed step-by-step procedure is in [IP development guide](ip_development_guide.md), while repository/backend structure is in [Architecture](architecture.md). This reference does not replace tool logs or the underlying EDA manuals. Use `fx <command> --help` (also `-h`, `help`, or `info`) for dedicated command help, and `fx commands --json` when a script needs live metadata from the installed checkout.

> **Execution model:** `fx target_a target_b` launches exactly the requested backend targets in order. Execution targets are **run-only by default**: `fx syn` consumes an existing `syn --setup`, `fx eqy` consumes an existing `eqy --setup`, and sign-off/formal consumers behave the same way. Setup is generated explicitly once and then reused. Re-run the setup phase with `--force` only when regeneration is intentional. A failure in one explicitly listed top-level target does not suppress later targets; use a composite target or shell `&&` when the sequence itself must stop immediately.

---

## 1. Command-line model

```text
fx [pseudo-command | target ...] [global options]
```

Examples:

```bash
fx settings TOP=my_ip RUN_ID=dev
fx hjson reg doc --force
fx lint_suite
fx sdc --setup --force
fx cdc_rdc --setup --force
fx cdc_rdc
fx formal
fx regression
fx syn eqy --set EQY_JOBS=8 --live
fx signoff --setup --dry-run --script
```

Persistent settings are stored in `.flexsoc/settings.json`. One-shot `--set KEY=VALUE` overrides affect only the current invocation. `--workdir` selects the workspace while `--project-root` selects the FlexSoC project checkout.

### 1.1 Pseudo-commands

| Command | Purpose | Important behavior |
| --- | --- | --- |
| `fx`, `fx help`, `fx -h`, `fx --help` | Show the lifecycle-ordered IP guide. | Does not execute a lifecycle target. |
| `fx <command> --help` | Show dedicated help, examples, required setup, and accepted variables. | `fx <command> -h`, `fx <command> help`, `fx <command> info`, and `fx help <command>` are equivalent. |
| `fx commands` | List all backend targets, groups, descriptions, and accepted variables. | Add `--json` for machine-readable metadata. |
| `fx settings [KEY=VALUE ...]` | Show or update persistent project settings and derived run paths. | Supports `--set`, `--unset`, `--reset`, `--workdir`, and `--json`. Clock relationships are cleared automatically when domains change unless explicitly supplied. |
| `fx doctor` | Check Python, lock files, and installed EDA tools. | Add `--json` for CI or provisioning scripts. |
| `fx pdk list` | List known PDK profiles and local readiness. | `--json` returns the catalogue. |
| `fx pdk info <name>` | Show source, node, digital views, OpenROAD platform, and formal adapter. | `--set PDK_ROOT=...` inspects a non-default installation. |
| `fx pdk fetch <name>` | Fetch the configured PDK source/provider. | `--force` refreshes; `--set PDK_VERSION=...` selects a supported version. |
| `fx pdk use <name>` | Validate digital views and persist the active PDK. | Shared RTL, DV, formal, and the canonical authored `constraints/<TOP>.sdc` remain valid; regenerate only technology-dependent synthesis/sign-off collateral for the selected PDK. |
| `fx eqy_debug [partition]` | Summarize EQY closure or diagnose one unresolved partition. | Supports `--wave`, `--files`, `--json`, and reset overrides through `--set`. |
| `fx shell` | Open an interactive prompt with target completion and history. | `help`, `commands`, `exit`, and normal target lines are accepted. |

### 1.2 Global options

| Option | Scope | Meaning |
| --- | --- | --- |
| `--set KEY=VALUE`, `-s` | Any target; also settings | Add a one-shot FlexSoC setting override. Repeatable. |
| `--unset KEY` | `settings` | Remove a persisted setting. Repeatable. |
| `--reset` | `settings` | Reset persisted settings to defaults before applying updates. |
| `--project-root PATH` | Any command | Use another FlexSoC project checkout. |
| `--workdir PATH` | Any run command | Select the external workspace passed as `WORKSPACE`. |
| `--tool NAME` | Lint targets | Shortcut for `--set LINT_TOOL=NAME`. |
| `--user` / `--system` | Dependency targets only | Select rootless user or shared/system installation mode. |
| `--profile base|impl|riscv` | Dependency targets only | Select the pinned dependency profile. |
| `--jobs N` | Dependency targets only | Set dependency build jobs. EQY parallelism uses `--set EQY_JOBS=N`. |
| `--force`, `--overwrite` | Generated targets | Set `FORCE=1`; authored files should still be reviewed before regeneration. |
| `--dry-run` | Backend targets | Print the exact command without executing it. |
| `--script` | With `--dry-run` | Render the preview as a strict Bash script. |
| `--capture` | Backend targets | Capture stdout/stderr and save a per-command log. |
| `--live` | Backend targets | Stream complete tool output while retaining the command log and render generated script contents. Compact streaming targets show only their normal artifact lines unless `--live` is requested. |
| `--debug` | STA, power, fusion, and GLS targets | Read existing analysis artifacts and render filtered diagnostics without rerunning the target. |
| `--save-output PATH`, `-o PATH` | With `--debug` | Save the same filtered diagnostic view to a file or directory. |
| `--json` | Supported pseudo-commands and execution output | Emit machine-readable JSON. |
| `--info` | Backend targets | Describe selected targets and accepted variables instead of running them. |

### 1.2.1 Backend operation vocabulary

Backend Python APIs use `init_*` for designer-owned starter content, `setup_*` for machine-owned generated collateral, `run_*` for execution, `collect_*` for evidence collection, and `show_*`/`debug_*` for inspection. These are implementation method names, not CLI targets: the CLI exposes one canonical keyword with `--setup`, implicit run, and `--debug` where supported.

### 1.3 Explicit setup and run-only consumers

FlexSoC separates generated setup collateral from execution. Setup targets create canonical machine-owned files; execution targets consume those files without regenerating them.

| Execution family | Required setup |
| --- | --- |
| `syn`, `syn_v`, `syn_sv` | `syn --setup` |
| CSR formal execution targets | `formal_csr --setup` or the matching formal keyword with `--setup` |
| Design formal execution targets | `formal_prove formal_cover --setup`, or `formal --setup` for the complete formal setup |
| `eqy` | `eqy --setup` |
| `sdf`, `sta*`, `power_estimate*` | `signoff --setup` |
| `pnr`, `pnr_gui` | `pnr --setup` plus its upstream synthesis/sign-off results |
| `cdc_rdc` | `cdc_rdc --setup` |
| SV/cocotb execution | `tb --setup` / `cocotb --setup` as appropriate |

The normal pattern is therefore explicit and stable:

```bash
fx syn --setup
fx syn

fx eqy --setup
fx eqy

fx signoff --setup
fx sdf
fx sta
```

Calling `fx syn` does not rewrite `syn --setup`. Calling `fx syn --setup` again also preserves an existing valid setup. To regenerate it intentionally, use:

```bash
fx syn --setup --force
```

The same contract applies to every provenance-bearing setup phase.
#### Provenance and controlled setup regeneration

Generated setup collateral is tracked in `meta/<pdk>/provenance.json` using content hashes of effective inputs, semantic configuration, parent lineage, and generated files.

Before a run target executes, FlexSoC verifies the required setup lineage:

- `CLEAN`: generated files match the last canonical setup; execution is allowed.
- `MODIFIED`: a generated file changed after setup; execution is blocked until the exact edit is validated or the setup is force-regenerated.
- `VALIDATED_OVERRIDE`: the current manual edit was explicitly accepted for the current lineage; execution is allowed.
- `STALE`: source, configuration, or upstream lineage changed; regenerate with `fx <keyword> --setup --force`.
- `INVALID`: required provenance or generated/input artifacts are missing or inconsistent. If the setup has never been generated, run it once; otherwise repair the inputs and force-regenerate.

A setup phase itself follows the same policy:

```text
not recorded       → generate + record CLEAN
CLEAN              → reuse, no rewrite
VALIDATED_OVERRIDE → reuse, no rewrite
MODIFIED           → block; validate_override or setup --force
STALE              → block; setup --force
INVALID            → block if previously recorded; repair + setup --force
```

`validate_override` is only for intentional edits to generated collateral. It is not a substitute for regenerating setup after a configuration/source change.

For a persistent synthesis-profile change:

```bash
fx settings TARGET_OPT=delay1
fx syn --setup --force
fx syn
```

For a manual experiment on generated setup:

```bash
fx syn --setup
# edit the generated setup collateral
fx validate_override --set STAGE=syn --setup
fx syn
```

Execution targets must not rewrite setup collateral. Scenario-specific runtime files may be generated below scenario/report directories, while canonical setup files tracked by provenance remain immutable.

Composite lifecycle targets may list setup operations explicitly as part of their orchestration. Those setup operations still obey the reuse/`--force` policy; a composite flow therefore cannot silently erase a validated manual override.

After `ip_load`, and again after each `pdk use` before GLS, generate or refresh `tb --setup` and `cocotb --setup` explicitly when required by the current RTL/register/clock interface. Their generated trees are machine-owned and are reused while provenance remains valid.

### 1.4 Run identity, clock/reset bootstrap, and authored SDC

Use `fx settings` for persistent run identity and bootstrap configuration. `TOP`, `RUN_TOP`, and `RUN_ID` identify the logical run. `N_CLOCKS`, `CLOCK_DOMAINS`, and `CLOCK_RELATIONSHIPS` describe the initial domain/reset topology so FlexSoC can scaffold a new project before an authored SDC exists. The project-local settings live in `.flexsoc/settings.json`; runs snapshot common intent in `meta/design_intent.json` and effective technology values in `meta/<pdk>/settings.json`.

#### Single-clock bootstrap

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low
```

`CLOCK_DOMAINS` syntax is `name:clock_port:reset_port:period_ns[:low|high]`. The reset polarity defaults to `low` if omitted; `N_CLOCKS` must equal the number of entries.

#### N-clock bootstrap

```bash
fx settings \
  TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:20:low,rx:rx_clk_i:rx_rst_ni:16:low,dsp:dsp_clk_i:dsp_rst_ni:30:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

Relationships are explicit: `async:source:target`, `sync:source:target`, or `generated:source:target[:divide_by]`. FlexSoC does not infer that unrelated domains are asynchronous.

Inspect bootstrap/effective settings with:

```bash
fx settings
fx settings --json
```

#### Initialize the timing source of truth

After structural RTL/lint are clean, initialize the canonical SDC once:

```bash
fx sdc --setup --force
```

`constraints/<TOP>.sdc` is then designer-owned timing intent. Edit clock period/waveform, generated clocks, source latency, setup/hold uncertainty, clock transition, clock groups, I/O delay, drive/load, and reviewed exceptions there. Do not maintain the same timing fact in a parallel settings override after the SDC exists. `SDC_IO_DELAY_PCT` is a bootstrap/default phasing value used by the initial scaffold and generated vector drivers, not a replacement for authored SDC timing.

The shared `sdc.py` adapter parses only the subset required by non-STA consumers. Functional SV/cocotb use SDC period/waveform/source latency and model `set_clock_uncertainty` as bounded uniform jitter of `±max(setup_uncertainty, hold_uncertainty)`, quantized at 1 ps. The existing run `SEED` drives the same xorshift32 sequence in both backends, so clock phase, duty cycle, relative skew, and jitter are reproducible. `set_clock_transition` remains an STA/electrical constraint rather than an analog slew model. CDC/RDC reads clock relationships from the SDC and combines them with reset ownership/polarity from bootstrap metadata. Synthesis derives `abc.constr` drive/load collateral from the same file. OpenSTA sources it directly.

If the **domain/reset topology** changes, update bootstrap settings and intentionally regenerate/review `fx sdc --setup --force`. If only timing values or exceptions change, edit `<TOP>.sdc` directly and regenerate only the affected setup stages.

### 1.5 Changing technology inside one logical run

The run root, RTL, functional DV, property formal, and `constraints/<TOP>.sdc` are technology independent. `fx sdc --setup` initializes that authored timing contract once from the bootstrap clock/reset settings. After that, functional TB, CDC/RDC, synthesis and STA consume the same file; `syn --setup` derives `syn/<pdk>/abc.constr` drive/load collateral from it and `signoff --setup` only generates tool scripts. After `fx pdk use <name>`, do **not** regenerate HJSON, registers, RTL, models, model-derived tests, or `<TOP>.sdc`. Regenerate only technology-dependent synthesis/sign-off collateral. Run only:

```bash
# Generated collateral is explicit and persistent. Runs never regenerate it.
fx syn --setup
fx syn
fx eqy --setup
fx eqy
fx signoff --setup
fx sdf
fx sta
fx power_estimate
# compile_post_syn / sim_post_syn / power_analysis for every vector
fx manifest
fx metrics
fx check
```

Those outputs are isolated below `syn/<pdk>`, `impl/<pdk>`, `signoff/<pdk>`, `dv/functional/sim/post_syn/<pdk>`, and `meta/<pdk>`.

---

## 2. Lifecycle command map

| Lifecycle gate | Primary commands | Evidence produced |
| --- | --- | --- |
| Environment and technology | `fx doctor`, `fx deps-doctor`, `fx pdk info`, `fx pdk use` | Tool/PDK readiness |
| Requirements to CSR/RTL entry | `fx setup`, `fx hjson`, `fx reg`, `fx doc`, `fx rtl_stub`, `fx top_from_core` | Register collateral and authored RTL boundary |
| RTL elaboration and lint | `fx flist`, `fx lint_suite`, `fx slang_hier`, `fx slang_ast` | Reachable hierarchy and clean structural RTL |
| Timing intent | `fx sdc --setup` | single authored `constraints/<TOP>.sdc` |
| CDC/RDC | `fx cdc_rdc --setup`, `fx cdc_rdc` | `design.json`, `summary.json`, `cdc_rdc.rpt`, extraction setup/log |
| Property formal | `fx formal --setup`, `fx formal` | BMC/prove/cover closure |
| Functional DV | `fx model --setup`, `fx tests_gen`, `fx tb --setup`, `fx cocotb --setup`, `fx regression`, `fx coverage_detail` | Passing scenarios, waves, coverage |
| Sign-off setup | `fx signoff --setup` | OpenSTA Tcl families consuming `constraints/<TOP>.sdc` |
| Synthesis | `fx syn --setup`, `fx syn` | `syn/<pdk>/abc.constr`, Yosys scripts, mapped netlist, synthesis reports |
| Logical sign-off | `fx eqy --setup`, `fx eqy`, `fx eqy_debug` | RTL ↔ mapped-netlist equivalence |
| Post-synthesis sign-off | `fx signoff --setup`, `fx sdf`, `fx sta`, `fx power_estimate`, gate simulation targets | Timing, SDF/GLS, and power evidence |
| Physical implementation | `fx pnr --setup`, `fx pnr`, `fx pnr_gui` | Placed/routed implementation |
| Post-layout sign-off | `fx signoff_post_pnr --setup`, `fx sdf_post_pnr`, `fx sta_post_pnr`, routed GLS, `fx power_estimate_post_pnr`, activity/fusion post-PnR targets, `fx physical_signoff` | SPEF-aware timing, routed GLS/power/fusion, and physical evidence |
| Release | `fx manifest`, `fx metrics`, `fx check`, `fx ip_save` | Immutable identity + normalized metrics snapshot + human closure dashboard + reusable package |

The SV and cocotb vector drivers accept the same reset commands:

```text
<cycle> @reset <cycles>
<cycle> @reset <domain-or-reset-signal> <cycles>
```

The short form pulses every configured reset. The named form selects one `CLOCK_DOMAINS` domain or reset signal. Both backends honor the configured polarity and hold all selected resets concurrently for the requested number of their own clock edges; unknown selectors are errors.

---

## 3. Complete backend target catalogue

Every target below is accepted by the current Python API. The tables omit the common run identity, clock settings, workspace, and `FORCE`; the remaining target-specific overrides are shown explicitly. All variables are defined in the [variable reference](#4-variable-reference), while `fx <target> --help` remains the exact live source.

### 3.1 Dependencies

Prepare and inspect the pinned toolchain before running design targets.

**Main result:** Repository/tool installation; no IP run artifacts.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx deps-bootstrap` | Check/install prerequisites for a dependency profile. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |
| `fx deps` | Install pinned base, impl, or riscv profile. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |
| `fx deps-doctor` | Verify the selected pinned dependency profile. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Use `--info` for accepted overrides. |
| `fx deps-versions` | Show pinned tool versions and revisions. | Common run/clock settings only | Use `--info` for accepted overrides. |
| `fx deps-env` | Print shell exports for the pinned toolchain. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_JOBS` | Prefer `eval "$(fx deps-env)"`; installs also maintain the stable `~/.local/share/flexsoc/toolchain` symlink. |
| `fx deps-status` | Show current/obsolete managed prefixes, disk use, and duplicate command candidates. | `DEPS_MODE`, `DEPS_PROFILE` | Read-only; it does not remove system packages. |
| `fx deps-prune` | Preview or remove obsolete managed prefixes and optional build caches. | `DEPS_MODE`, `DEPS_PROFILE`, `DEPS_PRUNE_APPLY`, `DEPS_PRUNE_CACHE` | Dry-run by default; only FlexSoC-managed directories are eligible. |

#### One clean host toolchain

`fx deps` deliberately installs the exact lock under a versioned user prefix even when another `verilator`, `yosys`, or `iverilog` exists in `/usr/bin` or an OSS CAD Suite directory. It never overwrites those installations. Activate the managed prefix with:

```bash
eval "$(fx deps-env)"
```

Inspect duplicates and disk usage before deleting anything:

```bash
fx deps-status
```

Remove only obsolete FlexSoC prefixes, preserving the current lock:

```bash
fx deps-prune
fx deps-prune --set DEPS_PRUNE_APPLY=1
```

After a successful install, source/download build caches can also be removed without deleting installed tools:

```bash
fx deps-prune \
  --set DEPS_PRUNE_APPLY=1 \
  --set DEPS_PRUNE_CACHE=1
```

Do not uninstall distribution packages merely because a managed executable has the same name. Many are build prerequisites or dependencies shared by unrelated software. Remove a system/standalone EDA distribution only after `fx deps-status`, `type -a <tool>`, and a package-manager ownership check identify it as an independent copy.

#### Docker and CI

The complete ASIC toolchain is distributed as the immutable image recorded in `docker/ci/image.lock`. Normal project CI validates that lock, pulls the exact `repository@sha256:...` digest, mounts the current checkout, and runs `docker/scripts/run-ci.sh`; it does not rebuild EDA tools on ordinary source changes.

User-facing local execution is:

```bash
IMAGE_REF="$(bash -lc 'source docker/scripts/common.sh; validate_lock')"
docker pull "$IMAGE_REF"
docker/scripts/run-ci.sh
# Full E2E qualification:
FULL_E2E=1 docker/scripts/run-ci.sh
```

Maintainers refresh the toolchain image only when declared image inputs change:

```bash
docker/scripts/build.sh
docker/scripts/verify.sh

export GHCR_USER=<github-user>
read -rsp 'GHCR token: ' GHCR_TOKEN; echo
export GHCR_TOKEN
docker/scripts/publish.sh
unset GHCR_TOKEN

git add docker/ci/image.lock
```

The currently implemented helper set is `build.sh`, `verify.sh`, `publish.sh`, `run-ci.sh`, and shared `common.sh`; documentation must not reference removed helper scripts. See [`docker/README.md`](../docker/README.md) for image construction and CI details.

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

### 3.5 CDC/RDC structural analysis

Run clock/reset-domain analysis after linting and before functional regression. The
checker uses a pre-technology Slang/Yosys representation, builds one shared
sequential dependency graph, and applies CDC, RDC, setup, protocol,
reconvergence, and clock/reset glitch checks. It works for single-clock designs
too; a valid single-domain design normally reports zero raw CDC crossings rather
than skipping the stage.

| Target | Action | Main overrides | Notes |
| --- | --- | --- | --- |
| `fx cdc_rdc --setup` | Generate the pre-technology Yosys extraction script. | clock settings | Must exist and have valid provenance before `fx cdc_rdc` runs. |
| `fx cdc_rdc` | Extract, classify, report, and optionally gate CDC/RDC findings. | `CDC_RDC_HEARTBEAT`, `CDC_RDC_STRICT` | Run-only consumer of valid `cdc_rdc --setup` provenance. Normal order is `lint_suite` → authored `<TOP>.sdc` → `cdc_rdc --setup` → `cdc_rdc`. |

The checker executes the structural families in a fixed, readable order: (1) scalar and multi-bit CDC crossings, (2) async-FIFO candidates, (3) closed-loop handshakes, (4) synchronized reconvergence, (5) setup/domain and glitch checks, then (6) reset-domain crossings, (7) reset synchronizers, (8) asynchronous reset release, and (9) reset sequencing. This order is reflected directly in `cdc.py`; later checks reuse facts from earlier checks instead of re-discovering the design independently.

The checks cover scalar N-FF synchronizers and their integrity, multi-bit transfers, synchronized controls, Gray/coherency obligations, undeclared or inconsistent clock/reset intent, combinational clock/reset paths, and uncontrolled reset-domain crossings. Results use `SAFE`, `WARN`, `ERROR`, and `REVIEW`; `REVIEW` records a property that structural analysis alone cannot prove.

Canonical CDC/RDC evidence is intentionally compact:

```text
analysis/cdc_rdc/
├── extract.ys
├── design.json
├── summary.json
└── cdc_rdc.rpt

logs/analysis/cdc_rdc/
└── extract.log
```

`summary.json` carries the complete machine-readable classifications, findings, setup/glitch checks, reset checks, and obligations; `cdc_rdc.rpt` is the human report. The implementation is a custom FlexSoC checker; it does not yet implement the Accellera CDC/RDC interchange and hierarchical abstraction layer.

### 3.6 DV formal

Generate and execute automatic CSR checks and authored property BMC/prove/cover stages.

**Main result:** `dv/formal/` designer-owned prove/cover sources, generated configurations, proof logs, traces, and status files. `formal --setup` creates the initial design-property scaffold only when it is absent; loaded IP properties are preserved.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx formal --setup` | Create or preserve starter design assertions and covers. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_csr_prove --setup` | Generate shared CSR BMC/prove configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_csr_cover --setup` | Generate automatic CSR cover configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_csr_bmc` | Bounded-check automatic CSR assertions. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_csr_prove` | Prove automatic CSR semantics with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_csr_cover` | Reach automatic CSR cover points with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_csr` | Run CSR BMC, prove, then cover. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Composite target; use it for the standard ordered flow. |
| `fx formal` | Run all formal stages BMC, prove, then cover. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Composite target; use it for the standard ordered flow. |
| `fx formal_prove --setup` | Generate shared design BMC/prove configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_cover --setup` | Generate authored-property cover configuration. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx formal_bmc` | Bounded-check authored design assertions. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_prove` | Prove authored properties with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |
| `fx formal_cover` | Reach authored cover properties with SymbiYosys. | `SBY`, `FORMAL_DEPTH`, `FORMAL_BMC_DEPTH`, `FORMAL_BMC_APPEND`, `FORMAL_BMC_ENGINE`, `FORMAL_PROVE_ENGINE`, `FORMAL_COVER_ENGINE` | Use `--info` for accepted overrides. |

### 3.7 DV functional

Generate the reference-model environment, vectors, testbenches, simulations, regressions, and coverage.

**Main result:** `dv/functional/`, simulator build trees, waveforms, and coverage reports.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx tb --setup` | Generate a SystemVerilog testbench scaffold. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx cocotb --setup` | Generate a cocotb scaffold. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx model --setup` | Generate Python model, CSR regmap, and test scaffolds. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
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
| `fx regression` | Run every existing vector test on each selected backend, then merge Verilator coverage. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Composite target; use it for the standard ordered flow. |
| `fx coverage` | Merge and report existing Verilator coverage data. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |
| `fx coverage_detail` | Show uncovered Verilator coverage points. | `TESTBENCH`, `TEST_NAMES`, `TEST_NAME`, `REGCFG`, `DATA_IN`, `DATA_OUT`, `VSV`, `COMPILER`, `COCOTB_WAVES`, `SEED`, `REGRESSION_BACKENDS`, `COVERAGE`, `COVERAGE_DETAIL_LIMIT`, `WAVE_FORMAT`, `WAVE_FILE` | Use `--info` for accepted overrides. |


#### Functional-simulation selection and artifacts

Generate both environments before running a named test:

```bash
fx tests_gen
fx tb cocotb --setup
fx tests
```

One SystemVerilog test:

```bash
WORKSPACE="$HOME/flexsoc-workspace"
TOP=my_ip
RUN_TOP=my_ip
RUN_ID=dev
RUN="$WORKSPACE/runs/$RUN_TOP/$RUN_ID"

fx sim --live \
  --workdir "$WORKSPACE" \
  --set COMPILER=verilator \
  --set TEST_NAME=smoke \
  --set WAVE_FILE="$RUN/dv/functional/sim/rtl/${TOP}_tb_sv_smoke.fst"
```

The same test through cocotb:

```bash
fx cocotb --live \
  --workdir "$WORKSPACE" \
  --set COMPILER=verilator \
  --set TEST_NAME=smoke \
  --set COCOTB_WAVES=1 \
  --set WAVE_FILE="$RUN/dv/functional/sim/rtl/${TOP}_tb_cocotb_smoke.fst"
```

`fx sim_tests` and `fx cocotb_tests` run every existing vector test for one
backend. `fx regression` runs the same existing vectors on every backend in
`REGRESSION_BACKENDS`, clears only previous regression logs and coverage, and
merges coverage when `COMPILER=verilator`. Use `fx tests_gen` explicitly when the
editable test catalogue must be recreated. For a loaded IP, run `fx regmap_py` and
`fx tests_gen` before regression so authored scenarios and machine-owned CSR tests are
materialized in the current workspace. Cocotb sources are rebased from the current
RTL filelists at execution time.

```bash
fx regression --live --set 'REGRESSION_BACKENDS=sv cocotb'
fx coverage_detail
```

Regression waveforms are written as:

```text
dv/functional/sim/rtl/<testbench>_<backend>_<test>.<fst|vcd>
```

Regression logs are written under:

```text
logs/dv/functional/regression/<backend>/
```

`TEST_NAME` selects one test for `sim`, `cocotb`, `test_gen`, and gate-simulation
targets. It does not restrict `regression`; use a single-test target for a narrow
debug loop.

#### Deterministic waveform viewing

`fx view` and `fx view_cocotb` are convenience discovery commands. To inspect a
particular regression result, open its exact path:

```bash
find "$RUN/dv/functional/sim/rtl" \
  -maxdepth 1 -type f \( -name '*.fst' -o -name '*.vcd' \) \
  -printf '%f\n' | sort

gtkwave "$RUN/dv/functional/sim/rtl/${TOP}_tb_sv_smoke.fst" &
# or
surfer "$RUN/dv/functional/sim/rtl/${TOP}_tb_cocotb_smoke.fst" &
```

Set `WAVE_FILE` during the simulation when a stable, scriptable artifact name is
required. `COCOTB_WAVES=1` enables RTL cocotb dumping; post-synthesis cocotb GLS
manages its waveform owner automatically.

### 3.8 Viewing

Inspect waveforms and saved simulation or synthesis views without changing design state.

**Main result:** Interactive viewer sessions and saved debug bundles.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx view` | Open a waveform discovered in the default RTL simulation directory. | `WAVE_VIEWER`, `SURFER_BACKEND` | Convenience selection only; open an explicit regression path for deterministic test selection. |
| `fx view_cocotb` | Open a waveform discovered under the cocotb scaffold. | `WAVE_VIEWER`, `SURFER_BACKEND` | Convenience target for default cocotb outputs; explicit `WAVE_FILE` plus a direct viewer command is authoritative. |
| `fx view_syn` | Reserved synthesis waveform viewer target. | `WAVE_VIEWER`, `SURFER_BACKEND` | Reserved target; currently no implementation. |
| `fx plot_postsyn` | Open post-synthesis graph. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_presyn` | Open pre-synthesis graph. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_presyn_v` | Open pre-synthesis graph from Verilog. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx view_presyn_sv` | Open pre-synthesis graph from SV. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx tb_save` | Save testbench regression artifacts. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |
| `fx tb_view` | Open saved testbench waveform. | `WAVE_VIEWER`, `SURFER_BACKEND` | Use `--info` for accepted overrides. |

### 3.9 Synthesis

Generate Yosys/ABC scripts and map RTL to the selected PDK. FlexSoC synthesis uses `abc.constr` and a named ABC optimization profile; it does not parse the sign-off SDC.

`TARGET_OPT` selects one deterministic synthesis recipe:

| Family | Profiles | Intent |
| --- | --- | --- |
| Area | `area0`, `area1`, `area2`, `area3` | Progressively explore compact mapping through a balanced fanout-aware profile. |
| Delay | `delay0`, `delay1`, `delay2`, `delay3`, `delay4` | Progressively favor timing, with the later profiles applying stronger buffering/fanout repair. |

The default is `area0`. There is intentionally no claim that a higher index is universally better: compare the resulting synthesis area and STA slack for the design. The CORDIC E2E currently qualifies with `delay1`, the first timing profile verified in the real flow; the root Makefile can override it for exploration, for example `make test TESTS=cordic TARGET_OPT=delay3`.

Generated `.abc` files are intentionally self-documenting: every executable ABC command is immediately preceded by a plain-language comment. Delay profiles write the active clock target directly in picoseconds (for a 10 ns clock, for example `map -D 10000`). Yosys documents `{D}` substitution for its built-in ABC scripts; FlexSoC custom `-script <file>` recipes are ordinary ABC files, so they contain the numeric target instead.

**Main result:** `syn/<PDK>/` contains the selected `<TARGET_OPT>.abc` recipe, `abc.constr`, mapped netlists, logs, statistics, and checkpoints. The SDC is owned separately by `signoff --setup`.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx syn --setup` | Generate Yosys/ABC synthesis scripts and `abc.constr`; no SDC is consumed by synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx syn` | Run synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx syn_v` | Run Verilog synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx syn_sv` | Run SystemVerilog synthesis. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx yosys-vgen` | Convert SV to Verilog with Yosys. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |
| `fx sv2v` | Convert SV to Verilog with sv2v. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN` | Use `--info` for accepted overrides. |

### 3.10 Signoff

Prove RTL/netlist equivalence and generate or execute pre-layout timing, SDF, and power analysis.

**Main result:** `signoff/<pdk>/{equivalence,sta,sdf,power,fusion}/`.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx sta_corners` | Run STA setup/hold for each configured corner. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Writes every report and returns non-zero if any corner/mode violates timing. |
| `fx power_estimate_corners` | Estimate power for each corner using primary-input activity assumptions. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Runs all configured technology corners. |
| `fx signoff_corners` | Run SDF, multi-corner STA and estimated power. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Stops at STA when any configured corner/mode violates timing. |
| `fx eqy --setup` | Generate RTL-vs-post-synthesis EQY configuration. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN`, `SBY`, `EQY`, `EQY_SAT_DEPTH`, `EQY_TIMEOUT`, `EQY_QUICK_TIMEOUT`, `EQY_JOBS`, `EQY_USE_SAT`, `EQY_SPLITNETS`, `EQY_USE_PDR`, `EQY_PDR_ENGINE`, `EQY_SMT_ENGINE`, `EQY_SMT_DEPTH`, `EQY_XPROP`, `EQY_JOIN_OUTPUTS`, `EQY_STRATEGY_ORDER`, `PRIM`, `FORMAL_PDK_PROC` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx eqy` | Prove RTL equivalent to the post-synthesis netlist with EQY. | `PDK`, `PDK_ROOT`, `CLK_PERIOD`, `TARGET_SYN`, `TARGET_OPT`, `VSV`, `LIB_SYN`, `SBY`, `EQY`, `EQY_SAT_DEPTH`, `EQY_TIMEOUT`, `EQY_QUICK_TIMEOUT`, `EQY_JOBS`, `EQY_USE_SAT`, `EQY_SPLITNETS`, `EQY_USE_PDR`, `EQY_PDR_ENGINE`, `EQY_SMT_ENGINE`, `EQY_SMT_DEPTH`, `EQY_XPROP`, `EQY_JOIN_OUTPUTS`, `EQY_STRATEGY_ORDER`, `PRIM`, `FORMAL_PDK_PROC` | Use `--info` for accepted overrides. |
| `fx signoff --setup` | Generate sign-off Tcl families that consume the authored `constraints/<TOP>.sdc`. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx compile_syn` | Compile post-synthesis simulation. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx sim_syn` | Run post-synthesis simulation. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx sta` | Run static timing analysis. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Runs all resolved setup/hold scenarios and consolidates qualification into `signoff/<pdk>/sta/sta.rpt` plus `sta.json`; negative timing or unconstrained paths fail qualification. |
| `fx sdf` | Write SDF timing files. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx power_estimate` | Estimate power using primary-input activity assumptions. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx power_analysis` | Run workload-dependent OpenSTA power analysis for one qualified GLS trace in its aligned scenario. | `SIGNOFF_STAGE`, `POWER_TEST_NAME`, `POWER_GLS_BACKEND`, `POWER_TIMING_MODE`, `POWER_VCD_SCOPE`, `POWER_DUT_INSTANCE`, `MACRO_LIBS`, `SPEF_FILE` | Requires a passing direct GLS report and VCD/SAIF activity. |
| `fx power_analysis_all` | Run workload-dependent power analysis for all selected test/scenario pairs. | `POWER_TEST_NAMES`, `POWER_GLS_BACKENDS`, `POWER_GLS_BACKEND`, `POWER_TIMING_MODES`, `POWER_VCD_SCOPE`, `POWER_DUT_INSTANCE` | Treats SV/cocotb as alternative activity sources and selects one qualified backend per test/scenario. |
| `fx fusion_analysis` | Correlate timing and workload power for one qualified GLS trace. | Power-analysis selectors plus `STA_MODES`, `STA_ENDPOINT_PATH_LIMIT` and `POWER_TOP_INSTANCES` (default 20) | Uses staged public OpenSTA passes to report worst met/violated paths, gate fanout/capacitance/power, and the worst timing path through each top-power gate in one `fusion.rpt` per corner/mode. |
| `fx fusion_analysis_all` | Run fusion analysis for all selected test/scenario pairs. | Plural power-analysis selectors plus `STA_MODES`, `STA_ENDPOINT_PATH_LIMIT` and `POWER_TOP_INSTANCES` | Selects one qualified SV/cocotb source per test/scenario, then writes one fusion table per selected workload and one global JSON summary. |
| `fx sta_violators` | Report timing violators. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |
| `fx path_view` | Build interactive STA path view. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS` | Use `--info` for accepted overrides. |

### 3.11 Gate simulation

Compile and run mapped or post-route gate-level simulations, optionally with SDF annotation.

**Main result:** Gate-simulation executables, logs, and waveforms.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx compile_post_syn` | Compile post-synthesis gate-level simulation with Icarus. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sim_post_syn` | Run one post-synthesis gate-level simulation with optional SDF. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sim_post_syn_all` | Run all selected generated tests and timing modes with one GLS backend. | `TEST_NAMES`, `GLS_BACKEND`, `TIMING_MODES`, plus the `sim_post_syn` overrides | Defaults to all test directories, backend `sv`, and `zero unit min typ max`; run `sdf` explicitly first when timing modes require SDF. Run the command once with `GLS_BACKEND=sv` and once with `GLS_BACKEND=cocotb` when both drivers must be qualified. Results and `summary_<backend>.json` stay under `dv/functional/sim/post_syn/<pdk>/`. |
| `fx compile_post_pnr` | Compile post-PnR gate-level simulation with Icarus. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sdf_post_pnr` | Export post-PnR SDF from final netlist, the authored SDC, and SPEF. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |
| `fx sim_post_pnr` | Run post-PnR gate-level simulation with optional SDF. | `PDK`, `PDK_ROOT`, `LIBS`, `LIB_SYN`, `PRIM`, `WAVE_FORMAT`, `WAVE_FILE`, `GLS_SIMULATOR`, `GLS_BACKEND`, `TIMING_MODE`, `SDF_STRICT`, `SDF_FILE`, `SDF_CORNER`, `NETLIST`, `SPEF_FILE`, `PNR_SDC_FILE`, `POWER_ACTIVITY`, `POWER_DUTY`, `PATH_VIEW_FILE`, `NPATHS`, `TESTBENCH`, `TEST_NAME`, `TEST_ROOT`, `REGCFG`, `DATA_IN`, `DATA_OUT` | Use `--info` for accepted overrides. |


#### Post-synthesis timing modes

The CLI uses one terminal grammar for every target: `→ target: description` at start, orange labels for `[log]`, `[script]`, `[report]`, cyan/light-blue values and paths, and a green `✓ target: done` or red `✗ target: failed (...)` completion line. Default all-matrix logs use the concise target name (`sim_post_syn_all.log`, `power_analysis_all.log`, `fusion_analysis_all.log`); non-default selectors are appended only when they disambiguate the run.

Both `compile_post_syn` and `sim_post_syn` require Icarus. `sim_post_syn_all` invokes the same direct flow for every selected case. Select the driver with
`GLS_BACKEND=sv|cocotb` and the timing behavior with:

| `TIMING_MODE` | Cell-model behavior | SDF | Report model |
| --- | --- | --- | --- |
| `zero` | functional `#0`, `specify` disabled | forbidden | `functional-zero-delay` |
| `unit` | uniform requested `GLS_UNIT_DELAY`, normalized to cell-model precision; `specify` disabled | forbidden | `functional-unit-delay` |
| `min` | `specify` path delays, fastest corner | `<top>_ff.sdf` | `icarus-path-delay-only` |
| `typ` | `specify` path delays, nominal corner | `<top>_tt.sdf` | `icarus-path-delay-only` |
| `max` | `specify` path delays, slowest corner | `<top>_ss.sdf` | `icarus-path-delay-only` |

`min/typ/max` execute `$sdf_annotate` against the generated DUT instance. The
Icarus-compatible timing-model copy retains path delays but disables unsupported
setup/hold, recovery/removal, pulse-width, and notifier checks. This is real SDF
path-delay simulation, not full dynamic timing-check sign-off.

For practical sign-off work, start with `typ`, then run `min` and `max`; these
map respectively to the nominal, fastest (`ff`), and slowest (`ss`) generated
SDF views. `zero` is a fast netlist/elaboration and reset/protocol smoke test.
`unit` is an artificial uniform-delay stress test that exposes race,
ordering, and backend-sampling assumptions. Neither `zero` nor `unit` is a
technology corner or a production timing result. Keeping them in the full E2E
qualification is useful because they diagnose model/backend problems earlier,
but a focused sign-off rerun may select only `min,typ,max`.

Run one combination after setting the run identity and active PDK:

```bash
WORKSPACE="$HOME/flexsoc-workspace"
TOP=my_ip
RUN_TOP=my_ip
RUN_ID=dev
RUN="$WORKSPACE/runs/$RUN_TOP/$RUN_ID"
PDK=sky130

fx pdk use "$PDK"
fx sim_post_syn --live \
  --workdir "$WORKSPACE" \
  --set GLS_BACKEND=sv \
  --set TIMING_MODE=typ \
  --set TEST_NAME=smoke \
  --set SDF_STRICT=1 \
  --set WAVE_FORMAT=fst \
  --set WAVE_FILE="$RUN/dv/functional/sim/post_syn/$PDK/${TOP}_smoke_sv_tt.fst"
```

Artifacts:

```text
dv/functional/sim/post_syn/<pdk>/<testbench>_<test>_<backend>_<scenario>.<fst|vcd>
dv/functional/sim/post_syn/<pdk>/<top>_post_syn_<test>_<backend>_<scenario>.json
logs/dv/functional/post_syn/<pdk>/<top>_post_syn_<test>_<backend>_<scenario>.log
dv/functional/sim/post_syn/<pdk>/icarus_timing_models/manifest.json
```

The report records the selected netlist, SDF, waveform, log, timing model, and
annotation diagnostics. `SDF_STRICT=1` is the qualification default: missing
annotation markers and recognized SDF warnings/errors fail the run.
`SDF_STRICT=0` is diagnostic only.

Default waveform, report, executable, and log names include `TEST_NAME`,
`GLS_BACKEND`, and the user-facing scenario. `zero` and `unit` keep their names;
SDF-backed modes are named by PVT (`min→ff`, `typ→tt`, `max→ss`). The JSON
still records the exact technical `timing_mode` used by Icarus, so for example
`*_ss.json` contains `scenario=ss`, `timing_mode=max`, and `sdf_corner=ss`.
Each direct GLS execution therefore retains its own evidence without an
intermediate qualification manifest.

Post-PnR targets use the same driver/timing concepts but consume a final netlist
and corner-specific post-PnR SDF. `sdf_post_pnr` requires `TIMING_MODE=min|typ|max`
and explicit or discovered final netlist, SDC, and SPEF inputs.

### 3.12 Physical implementation

Generate OpenROAD configuration, implement the design, and inspect the physical result.

**Main result:** `impl/<PDK>/` implementation collateral and reports.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx pnr --setup` | Generate OpenROAD config. | `PDK`, `PDK_ROOT`, `ORS`, `ORS_TECH` | Generates configuration/scaffolding; it does not execute the final analysis unless a dependency does so. |
| `fx pnr` | Run OpenROAD physical implementation. | `PDK`, `PDK_ROOT`, `ORS`, `ORS_TECH` | Use `--info` for accepted overrides. |
| `fx pnr_gui` | Open OpenROAD GUI. | `PDK`, `PDK_ROOT`, `ORS`, `ORS_TECH` | Use `--info` for accepted overrides. |

### 3.13 Run metadata

Separate evidence collection from human rendering. Technology-scoped metadata lives under `meta/<pdk>/`.

**Main results:** `meta/<pdk>/manifest.json` and `meta/<pdk>/metrics.json`.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx metrics` | Collect lint, CDC/RDC, formal, functional, synthesis, implementation, and sign-off evidence into one normalized snapshot. | Common run/clock settings only | Writes `meta/<pdk>/metrics.json`; it does not render the closure dashboard. |
| `fx manifest` | Collect run/tool/PDK identity and lightweight qualification evidence. | Common run/clock settings only | Writes `meta/<pdk>/manifest.json`. |
| `fx manifest_show` | Show the current run manifest in color. | Common run/clock settings only | Read-only inspection of the saved manifest. |
| `fx validate_override` | Accept an intentional manual edit to generated setup collateral for the current lineage. | `STAGE=<keyword|stage-id>` | Only `MODIFIED` can be accepted. `STALE` means rerun `fx <keyword> --setup --force` with the intended effective settings; `INVALID` means repair missing/inconsistent inputs and rerun setup. |
| `fx check` | Render the saved metrics snapshot as the lifecycle-ordered colored dashboard. | `PDK` plus common run/clock settings | Read-only with respect to `metrics.json`; run `fx metrics` first whenever you want a new snapshot. |

### 3.14 IP load/save

Move authored IP sources between the reusable library and an isolated run workspace.

**Main result:** `hw/ips/<IP_NAME>/` and the selected run directories.

| Target | Action | Target-specific overrides | Notes |
| --- | --- | --- | --- |
| `fx ip_load` | Load an IP into a run workspace. | `IP_NAME` | Use `--info` for accepted overrides. |
| `fx ip_save` | Save the current PDK reusable implementation/sign-off collateral and qualification metadata into the IP package. | `IP_NAME`, `IP_LIBRARY_ROOT`; use `--force` to replace existing destinations | Without `--force`, performs an atomic preflight and refuses to overwrite any existing destination, listing every conflicting package path and changing nothing. With `--force`, replaces the current-PDK/source-backed destinations while preserving unrelated PDK branches and any optional branch unavailable in the current run. Results stay in their native hierarchy: post-synthesis GLS JSON under `dv/functional/sim/post_syn/<pdk>/`, coverage `summary.txt/json` under `dv/functional/coverage/`, final `.rpt`/`.json`/`.sdf` under `signoff/<pdk>/`, reusable `syn/<pdk>`, optional `impl/<pdk>`, EQY/SDC, exactly one canonical Tcl per sign-off family, and `meta/<pdk>` including `settings.json`; common `meta/design_intent.json` is retained once. Qualification also retains normalized lint evidence under `logs/lint/` and the compact CDC/RDC package contract `analysis/cdc_rdc/summary.json` + `cdc_rdc.rpt`; extraction/runtime logs are not duplicated into the reusable package. Scenario/corner/workload-local Tcl copies are runtime collateral and are not packaged. Logs, waveforms, hidden transient sign-off reports, diagnostic RTLIL checkpoints, `__pycache__`, and `*.pyc`/`*.pyo` are excluded. |

`ip_save` is intentionally non-destructive by default. A first save into missing destinations succeeds; if any destination that the current run would update already exists, the command exits before staging or replacing the package and prints the conflicting relative paths. Use `fx ip_save --force ...` only when those destinations are intended to be refreshed.

E2E tests set `IP_LIBRARY_ROOT` inside their temporary workspace and hash the repository-owned package before and after execution. Therefore `make test` cannot write into `hw/ips`.

The saved technology branches mirror the PDK-first run layout:

```text
hw/ips/<IP_NAME>/
├── constraints/<TOP>.sdc
├── analysis/cdc_rdc/
├── syn/<pdk>/
├── impl/<pdk>/
└── signoff/<pdk>/
    ├── equivalence/rtl_vs_syn/
    ├── sta/sta.tcl
    ├── sdf/write_sdf.tcl
    ├── power/
    │   ├── estimate/power_estimate.tcl
    │   └── analysis/power_analysis.tcl
    └── fusion/fusion_analysis.tcl
```

Each invocation replaces only the selected PDK branch and preserves scripts
already saved for other technologies. The Tcl files are exact generated script
snapshots; after `ip_load`, rerun the corresponding setup/analysis command to
bind paths to the new workspace and PDK installation.

### 3.15 SoC flow

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

### 3.16 FSM flow

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

### 3.17 Tutorials

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

### 3.18 Cleanup

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

### 3.19 Help

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
| `CLOCK_DOMAINS` | Bootstrap `name:clock:reset:period_ns:polarity` entries. After `<TOP>.sdc` exists, clock timing is authored in SDC; this metadata still owns reset-domain mapping. |
| `CLOCK_RELATIONSHIPS` | Bootstrap `async`, `sync`, or `generated` relationships used to initialize the SDC. Afterward edit clock relationships in `constraints/<TOP>.sdc`. |
| `SDC_IO_DELAY_PCT` | Bootstrap fraction used for initial single-clock SDC I/O delays and generated vector drive/sample phasing; default `0.2`. After SDC creation, timing intent itself is edited in `constraints/<TOP>.sdc`. |
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
| `WAVE_FILE` | Explicit waveform path for simulation or analysis. Use a unique path per test/backend/scenario when overriding the canonical test-scoped path. |
| `GLS_SIMULATOR` | Gate-level simulator selection; current post-synthesis/post-PnR GLS requires `iverilog`. |
| `GLS_BACKEND` | Gate-level driver: `sv` or `cocotb`; default `sv`. |
| `TIMING_MODE` | Technical gate timing selection: `zero`, `unit`, `min`, `typ`, or `max`; default `zero`. SDF-backed artifacts are named by aligned PVT scenario (`min→ff`, `typ→tt`, `max→ss`). |
| `GLS_UNIT_DELAY` | Requested physical primitive delay used only by `TIMING_MODE=unit`; default `1ps`. FlexSoC rounds it up to the coarsest precision declared by the selected cell models and passes Icarus a suffix-free numeric delay. Real technology timing uses `min/typ/max` SDF. |
| `SDF_STRICT` | When true (default `1`), missing annotation evidence or recognized SDF warnings/errors fail the simulation report. |
| `SDF_FILE` | Explicit SDF file for `min/typ/max` gate simulation. It is rejected in `zero/unit`; missing SDF is fatal in timed modes. |
| `SDF_CORNER` | Selected SDF process/timing corner. |
| `NETLIST` | Explicit mapped or final implementation netlist. |
| `SPEF_FILE` | Extracted parasitic file for post-route analysis. |
| `PNR_SDC_FILE` | Explicit exceptional SDC override for post-route timing/SDF. Normal FlexSoC sign-off keeps `constraints/<TOP>.sdc` as the authored source of truth and changes netlist/SPEF/clock propagation by stage. |
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
| `TARGET_OPT` | Yosys/ABC profile: `area0..area3` or `delay0..delay4`; default `area0`. |
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
| `COCOTB_WAVES` | Enable RTL cocotb waveform dumping, normally `1`. Post-synthesis cocotb GLS selects one waveform owner internally. |
| `SEED` | Reproducible regression seed; also drives the deterministic functional clock-jitter sequence derived from SDC uncertainty. |
| `REGRESSION_BACKENDS` | Space-separated RTL regression backends, normally `sv cocotb`. |
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

## 5. End-to-end pytest qualification

`tests/test_e2e_fx.py` contains five literal, ordered qualification pipelines:

```text
test_fx_single_clock_flow_debug
test_fx_multi_clock_flow_debug
test_fx_provenance_lifecycle_debug
test_fx_cordic_ip_load_debug
test_fx_uart_ip_load_debug
```

The dedicated provenance lifecycle E2E exercises the user-facing contract independently from the functional flow: one representative generated artifact per setup family is modified, its run consumer must reject `MODIFIED`, `validate_override` must permit the exact current edit, the consumer must leave the stage `VALIDATED_OVERRIDE`, and restoring the canonical bytes must return the stage to `CLEAN`. The normal single-/multi-clock flows therefore do not repeat exhaustive A→B→A override permutations; those combinations remain API-level regression coverage.

`make test` runs every pipeline without `--live`. Each `fx` invocation is written
explicitly in the test, so pytest prints the exact `uv run --no-sync fx ...`
command before executing it. The single-clock, multi-clock and saved-IP flow
qualifications create the logical RTL/DV/formal run once, then qualify isolated
technology branches in order; the dedicated provenance lifecycle test uses one
minimal scaffold and exercises only the stage families enabled by the E2E options.

```text
PDKs:        sky130, ihp-sg13g2
GLS mode:    typ
GLS backend: sv
GLS tests:   every generated shared/custom test, one after another, per PDK
```

```bash
make test E2E_ROOT="$HOME/flexsoc-e2e"
```

| Pytest option | Environment equivalent | Meaning |
| --- | --- | --- |
| `--e2e-root PATH` | `FLEXSOC_E2E_ROOT` | Base directory for isolated workspaces. |
| `--e2e-gls-modes VALUE` | `FLEXSOC_E2E_GLS_MODES` | One of `zero`, `unit`, `min`, `typ`, or `max`. |
| `--e2e-gls-backends VALUE` | `FLEXSOC_E2E_GLS_BACKENDS` | Primary backend (`sv` or `cocotb`) used for detailed GLS/power/fusion checks; the other backend is additionally exercised with `sim_post_syn_all`. |
| `--no-post-syn-gls` | none | Keep synthesis/signoff but skip the explicit GLS commands. |
| `--no-signoff` | none | Skip sign-off SDC setup, formal, synthesis, EQY, SDF, STA, power, and GLS. |

E2E workspaces are always preserved for inspection. To inspect one
failed target with its generated scripts and complete log, copy the exact command
printed by pytest and add `--live` manually.

Every `sim_post_syn` run writes direct, test-scoped evidence under:

```text
dv/functional/sim/post_syn/<pdk>/
├── <top>_post_syn_<test>_<backend>_<mode>.json
├── <top>_<test>_<backend>_<mode>.fst
└── ...
```

`fx sim_post_syn_all` discovers the generated test directories and runs the selected test × timing-mode matrix with the single backend chosen by `GLS_BACKEND`. It writes the same per-case JSON reports plus:

```text
dv/functional/sim/post_syn/<pdk>/summary_<backend>.json
```

Use `TEST_NAMES` and `TIMING_MODES` to restrict the matrix; each selector accepts whitespace/comma-separated values or `all`. `GLS_BACKEND` selects exactly one driver (`sv` or `cocotb`) per invocation.

There is no E2E qualification matrix or `matrix.json`. For `min`, `typ`, and
`max`, the E2E test immediately runs `fx power_analysis` for that exact GLS trace.
The source report records the test, backend, timing mode, netlist, SDF, waveform,
and observable annotation diagnostics, so stale or mismatched artifacts fail at
their direct command boundary.

---

## 6. Command selection by change type

### Add or change a CSR

```bash
fx reg doc regmap_py tests_gen --force
fx flist --force
fx lint_suite
fx cdc_rdc --setup --force
fx cdc_rdc
fx tb cocotb --setup --force
fx regression
fx formal_csr --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
```

### Change RTL behavior or latency

```bash
fx flist --force
fx lint_suite
fx cdc_rdc --setup --force
fx cdc_rdc
fx formal_prove formal_cover --setup --force
fx formal
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
fx signoff --setup --force
fx sdf
fx sta
fx power_estimate
fx sim_post_syn --set GLS_BACKEND=sv --set TIMING_MODE=zero --set TEST_NAME=smoke
fx sim_post_syn --set GLS_BACKEND=cocotb --set TIMING_MODE=typ --set TEST_NAME=smoke
```

### Change top-level ports

```bash
fx top_from_core flist --force
fx lint_suite
# review constraints/<TOP>.sdc if interface timing changed
fx cdc_rdc tb cocotb --setup --force
fx cdc_rdc
fx formal_prove formal_cover --setup --force
fx formal
fx regression
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
fx sim_post_syn --set GLS_BACKEND=sv --set TIMING_MODE=zero --set TEST_NAME=smoke
```

### Change clock/reset domains

```bash
fx settings N_CLOCKS=<n> CLOCK_DOMAINS=<domains> CLOCK_RELATIONSHIPS=<relations>
fx top_from_core flist --force
fx lint_suite
fx sdc --setup --force
# review/reapply authored constraints/<TOP>.sdc
fx tb cocotb cdc_rdc formal_prove formal_cover formal_csr_prove formal_csr_cover --setup --force
fx cdc_rdc
fx formal
fx regression
fx syn eqy signoff --setup --force
fx syn
fx eqy
fx sdf
fx sta
fx power_estimate
fx sim_post_syn --set GLS_BACKEND=sv --set TIMING_MODE=unit --set TEST_NAME=smoke
fx sim_post_syn --set GLS_BACKEND=cocotb --set TIMING_MODE=typ --set TEST_NAME=smoke
```

### Diagnose a failed target

For STA, power, fusion, and GLS, prefer artifact-oriented debug first:

```bash
fx <target> --debug
fx <target> --debug -o debug.txt
```

This reads existing artifacts and does not rerun the target. For deeper execution diagnosis:

```bash
fx <target> --live
fx <target> --dry-run --script
fx <target> --info
```

`fx check` is the global lifecycle dashboard for the last saved `metrics.json`; it is not a replacement for target-local debug.

For equivalence specifically:

```bash
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --wave <partition>
fx eqy_debug --files <partition>
```

---

## 7. Production-use rules

1. Persist stable run identity and clock intent; use one-shot overrides for experiments.
2. Regenerate only machine-owned collateral and review every `--force` change.
3. Treat lint, simulation, coverage, formal proof, equivalence, STA, power, and physical closure as different gates.
4. Use composite targets for the standard flow, but use explicit stage targets while debugging.
5. Keep PDK, tool versions, settings, logs, metrics, and manifests with every release candidate.
6. Preview destructive cleanup and generated scripts with `--dry-run` before production runs.
7. Use `fx commands --json` in automation instead of scraping terminal tables.

See [Project lifecycle](project_lifecycle.md) for the project narrative, [IP development guide](ip_development_guide.md) for the detailed procedure, and [Quickstart](quickstart.md) for the shortest runnable flow.


### 7.0 Pre-layout sign-off scenarios

FlexSoC keeps static sign-off and workload-dependent sign-off deliberately distinct.
STA remains exhaustive across every configured Liberty corner and both setup/hold
checks.  Activity-based power and fusion instead use one physically coherent
pre-layout scenario per SDF-backed GLS trace:

| Scenario corner | GLS SDF mode | Workload-dependent analyses |
| --- | --- | --- |
| `ff` | `min` | power on FF; fusion FF setup + hold |
| `tt` | `typ` | power on TT; fusion TT setup + hold |
| `ss` | `max` | power on SS; fusion SS setup + hold |

Thus `POWER_TIMING_MODE=typ` means the `tt/typ` scenario; it no longer causes the
same TT/typ waveform to be swept again through FF and SS Liberty views.
`POWER_TIMING_MODES=all` means all three aligned scenarios, not a timing-mode ×
corner Cartesian product.  `sim_post_syn_all` remains a DV matrix and can still
select `zero`, `unit`, `min`, `typ`, and `max`, while its SDF-backed files are
named `ff`, `tt`, and `ss`.  SDF generation, STA, and vectorless
`power_estimate` remain multi-corner (`ff`, `tt`, `ss`).

### 7.1 `fx power_analysis` and `fx power_analysis_all`

`power_estimate` is the vectorless reference based by default on primary-input activity and duty
cycle assumptions; global activity is used only when explicitly requested. `power_analysis` consumes one direct `min`, `typ`, or `max`
post-synthesis GLS report. The report itself identifies the waveform and proves
that `$sdf_annotate` was requested successfully; no matrix manifest is involved.
FlexSoC converts FST to VCD when needed, resolves the DUT scope, and runs OpenSTA
`read_vcd`/`read_saif`, compact activity-coverage reporting, and `report_power` only in
the Liberty corner aligned with that GLS scenario.  The primary `power.rpt` records
only the annotated percentage and the unannotated pin list; it deliberately omits the
full annotated-pin list.  Vectorless `power_estimate` has no VCD/SAIF annotation
section at all.

Analyze one GLS trace:

```bash
fx power_analysis \
  --set POWER_TEST_NAME=smoke \
  --set POWER_GLS_BACKEND=sv \
  --set POWER_TIMING_MODE=typ
```

Analyze all matching direct reports currently present:

```bash
fx power_analysis_all \
  --set POWER_GLS_BACKENDS=all \
  --set POWER_TIMING_MODES=all \
  --set POWER_TEST_NAMES=all
```

`power_analysis_all` discovers `<top>_post_syn_<test>_<backend>_<mode>.json`
files directly. For each selected `test × timing_mode`, SV and cocotb are
**alternative activity sources**, not two mandatory sign-off runs. FlexSoC validates
the available candidates (PASS report, scenario-aligned SDF annotation, non-empty
waveform) and selects one qualified backend. `POWER_GLS_BACKEND` is the preferred
backend when both qualify (default `sv`); `POWER_GLS_BACKENDS` restricts the
allowed alternatives. A missing or failed cocotb result therefore does not block a
scenario when the matching SV result is qualified, and vice versa. `zero` and
`unit` remain invalid for activity power. Repeated singular runs accumulate into
the same activity-power summary instead of overwriting previous test results.

Relevant variables are `POWER_TEST_NAME(S)`, `POWER_GLS_BACKEND(S)`,
`POWER_TIMING_MODE(S)`, `POWER_VCD_SCOPE`, `POWER_DUT_INSTANCE`, and `FST2VCD`.
Explicit OpenSTA scopes use `/`, for example `test_tb/u_test`. Automatic scope
resolution recognizes `u_<TOP>` and `u_dut`. Captured or converted VCD files are written under `signoff/<pdk>/power/activity/captures`.
The canonical Tcl lives at `signoff/<pdk>/power/analysis/power_analysis.tcl`.
Each execution rewrites that script for the selected aligned scenario-workload. The workload name encodes the PVT corner (`_<backend>_ff`, `_<backend>_tt`, or `_<backend>_ss`), so reports and logs live directly under `<workload>` with no redundant corner subdirectory.

Without `--live`, gate simulation and activity-power targets keep detailed output
in their logs and print only concise status information. With `--live`, FlexSoC
prints orange labels, cyan/light-blue paths and transcript text, and generated Tcl
with a light orange/cyan/blue syntax palette. Semantic PASS/FAIL still uses
green/red. ANSI escape sequences are stripped from saved log files, while
`NO_COLOR`, `TERM=dumb`, or `FLEXSOC_COLOR=never` produce the same blocks as
plain text.


## 8. Failure-driven command playbook

The target catalogue above answers “what command exists.” This section answers
“what should I run next when the current stage does not close.” The complete
scaffold architecture and ownership model are described in
[IP development guide](ip_development_guide.md).

### 8.1 Universal inspection sequence

Before changing source or adding an override:

```bash
fx <target> --info
fx <target> --dry-run --script
fx <target> --live
fx metrics
fx check
```

Use the generated script and stage log as the exact execution record. The
terminal summary is intentionally compact and may omit the first tool-level
error when quiet mode is active.

| Question | Command or artifact |
| --- | --- |
| Which variables can this target consume? | `fx <target> --info` |
| What exact shell/tool command will run? | `fx <target> --dry-run --script` |
| Where is the full output? | printed command-log path; pass `--live` to stream it |
| Which run/PDK/tool versions produced the artifact? | `fx manifest`, `fx manifest_show` |
| Which stage is the first incomplete gate? | `fx check` |
| Is the target missing, failed, or stale? | command log, generated report, and `metrics.json` |

### 8.2 Environment and PDK failures

```bash
fx doctor
fx deps-doctor
fx deps-status
fx pdk info <pdk>
fx pdk use <pdk>
```

| Symptom | Commands | Expected repair |
| --- | --- | --- |
| tool missing | `fx doctor`, `fx deps-status`, `type -a <tool>` | activate the pinned toolchain/image or rebuild it |
| wrong tool version | `fx manifest_show`, `fx deps-versions` | qualify with the locked image; do not mix release evidence |
| PDK view not found | `fx pdk info`, `fx settings --json` | correct `PDK`, `PDK_ROOT`, provider/version, and view path |
| Docker/WSL resource failure | `docker system df -v`, `docker info` | lower build jobs, free build cache, or increase WSL/Docker memory/swap |

### 8.3 CSR and register collateral failures

```bash
fx hjson --force
fx reg doc regmap_py --force
fx top_from_core flist --force
fx formal_csr
```

Use `hjson` only to bootstrap or intentionally replace the source specification.
After normal HJSON edits, regenerate `reg`, `doc`, and `regmap_py`; do not rerun
`model --setup --force` merely to refresh register metadata.

| Failure | Inspect | Repair command |
| --- | --- | --- |
| HJSON syntax/access error | `data/*.hjson`, `reg` log | fix HJSON, then `fx reg doc regmap_py --force` |
| stale CSR addresses in tests | generated `<top>_regmap.py` | remove handwritten constants, then `fx tests_gen --force` |
| wrapper lacks a register window | core ports and generated top | `fx top_from_core flist --force` |
| reset/access semantic mismatch | CSR formal counterexample | repair HJSON/RTL ownership, regenerate, rerun `fx formal_csr` |

### 8.4 RTL and hierarchy failures

```bash
fx top_from_core --force
fx flist --force
fx slang_hier
fx slang_ast
fx lint_suite
```

Use `rtl_stub` only for bootstrap. Once the core is authored, regenerate the top
wrapper from the core rather than regenerating the core.

| Failure | Best first command | Next action |
| --- | --- | --- |
| unresolved module/package | `fx slang_hier`, inspect `rtl_common.f`/`rtl_ip.f` | fix source/include/package order and regenerate `flist` |
| top port mismatch | `fx top_from_core --dry-run --script` | regenerate wrapper and both testbenches |
| latch/width/sign warning | `fx lint_suite --live` | repair authored RTL; avoid broad warning suppression |
| hierarchy differs between tools | compare generated filelists and tool scripts | make all stages consume the same ordered hierarchy |

### 8.5 Functional-DV failures

```bash
fx tests
fx test_gen --force --set TEST_NAME=<test>
fx tb cocotb --setup
fx sim --live --set TEST_NAME=<test>
fx cocotb --live --set TEST_NAME=<test>
```

Then rerun:

```bash
fx regression --set 'REGRESSION_BACKENDS=sv cocotb'
fx coverage_detail
```

| Symptom | Inspect first | Typical repair |
| --- | --- | --- |
| wrong expected value | model, test catalogue, requirement | update the source that owns expected behavior, regenerate vectors |
| wrong cycle/latency | model `LATENCY`, vector cycles, pipeline RTL | align architectural latency without backend-specific expectations |
| SV only or cocotb only fails | atomic same-cycle batches, reset, sample phase | regenerate both harnesses and compare the first differing event |
| CSR transaction timeout | generated regmap, protocol driver, reset/config | debug one named test with `--live` and wave |
| regression PASS but coverage weak | `coverage_detail`, scenario catalogue | add requirement-driven scenarios or properties, not percentage-only stimulus |

### 8.6 Formal failures

```bash
fx formal --setup --force
fx formal_bmc
fx formal_prove
fx formal_cover
```

| Result | Command path |
| --- | --- |
| short counterexample | start with BMC log/wave and earliest property divergence |
| unbounded proof timeout | simplify cone, add valid invariants, change engine/depth |
| unreachable cover | review reset/state assumptions and add activation covers |
| suspicious instant PASS | check vacuity and whether assumptions disable the property |

### 8.7 SDC and synthesis setup failures

```bash
# edit/review constraints/<TOP>.sdc first
fx syn --setup --force
fx syn --live
fx signoff --setup --force
fx sta --live
```

| Symptom | Inspect | Repair |
| --- | --- | --- |
| clock not found | `constraints/<TOP>.sdc`, top port, bootstrap topology if recently changed | correct the authored SDC; regenerate the scaffold from bootstrap settings only when the topology itself changed |
| unsupported RTL construct | synthesis log and ordered filelist | rewrite/explicitly lower while preserving behavior |
| unexpected area/cell count | synthesis statistics | review widths, inferred storage, sharing, and optimization strategy |
| netlist stale/wrong PDK | run path, manifest, PDK-specific synthesis leaf | rerun with explicit `PDK`/`PDK_ROOT` and correct run identity |

### 8.8 Equivalence failures

```bash
fx eqy --live
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --files <partition>
fx eqy_debug --wave <partition>
```

Classify before acting:

```text
mismatch     concrete design/model difference
TIMEOUT      solver nonclosure, not proof of mismatch
UNKNOWN      engine/modelling result is inconclusive
ERROR        generated configuration, source, or tool failure
```

Do not fix a timeout by changing RTL unless the proof cone reveals a real design
problem. Do not call a mismatch a timeout merely because another strategy does
not close.

### 8.9 SDF and GLS failures

Start with one named test:

```bash
fx sim_post_syn --live \
  --set GLS_BACKEND=sv \
  --set TIMING_MODE=zero \
  --set TEST_NAME=smoke
```

Then isolate timing/harness behavior:

```bash
fx sim_post_syn --live --set GLS_BACKEND=sv     --set TIMING_MODE=unit --set TEST_NAME=smoke
fx sim_post_syn --live --set GLS_BACKEND=cocotb --set TIMING_MODE=unit --set TEST_NAME=smoke
fx sim_post_syn --live --set GLS_BACKEND=sv     --set TIMING_MODE=typ  --set TEST_NAME=smoke --set SDF_STRICT=1
fx sim_post_syn --live --set GLS_BACKEND=cocotb --set TIMING_MODE=typ  --set TEST_NAME=smoke --set SDF_STRICT=1
```

| First failing mode | Primary suspicion |
| --- | --- |
| `zero` | missing cells/models, reset, netlist function, protocol/vector mismatch |
| `unit` only | race, delta-cycle dependency, atomic batching, sampling, model precision |
| `min/typ/max` only | SDF generation/corner mapping, annotation, supported path-model behavior |
| one backend only | generated harness semantics rather than expected design behavior |

`zero` and `unit` are diagnostic modes. `min`, `typ`, and `max` are the
SDF-backed path-delay modes used for timing-oriented qualification.

### 8.10 STA and power failures

```bash
fx sta --live
fx sta_violators
fx power_estimate --live
fx power_analysis --live --set POWER_TEST_NAME=smoke
fx power_analysis_all --live --set POWER_TEST_NAMES=all
```

| Failure | First checks |
| --- | --- |
| unconstrained paths | authored `constraints/<TOP>.sdc`, clocks, I/O delays, exceptions, linked top |
| negative slack | mode/corner, constraints, architecture, mapping, path report |
| vectorless power implausible | activity/duty, clocks, Liberty units/tables, netlist |
| `fst2vcd` failure | conversion log and selected qualified FST |
| VCD scope unresolved | VCD `$scope` tree; use `POWER_VCD_SCOPE=auto` |
| zero annotated activities | resolved DUT hierarchy and VCD/netlist naming; reject returned default power |

### 8.11 Release and CI failures

```bash
fx manifest
fx metrics
fx check

docker/scripts/run-ci.sh
# toolchain maintainers: docker/scripts/verify.sh
```

A stale or unpublished `docker/ci/image.lock` is a release error. Normal CI
pulls the recorded digest and intentionally does not rebuild the EDA toolchain.

---

## 9. Scaffold and artifact ownership map

| Command | Main output | Editable? | Regenerate when |
| --- | --- | --- | --- |
| `setup` | run directory tree | no | new run identity/workspace |
| `hjson` | `data/*.hjson` starter | yes after bootstrap | only when intentionally replacing the starter |
| `reg` | generated register RTL/packages | no | HJSON/interface changes |
| `doc` | generated register Markdown | no | HJSON changes |
| `regmap_py` | generated Python CSR API | no | HJSON changes |
| `rtl_stub` | starter core and top | core becomes authored | bootstrap only |
| `top_from_core` | generated top wrapper | no | core ports/register windows/clocks change |
| `flist` | ordered `rtl_common.f`, `rtl_ip.f` | no | hierarchy/include/package/source changes |
| `model --setup` | model, regmap, tests, auto-toggle scaffold | model/tests yes; generated files no | bootstrap or deliberate reset of functional workspace |
| `tests_gen` | `config.regs`, `data_in.vec`, `data_out.vec` | no | model/scenario/regmap changes |
| `tb --setup` | SV harness | no | ports, clocks, protocol, vector grammar change |
| `cocotb --setup` | cocotb harness/drivers | no | same owning changes as SV harness |
| `formal --setup` | formal configs/wrappers | generated config no; authored properties yes | hierarchy, clock/reset, CSR, property integration changes |
| `syn --setup` | synthesis scripts | no | hierarchy, PDK, SDC, strategy changes |
| `eqy --setup` | EQY configuration/adapters | no | RTL/netlist/reset/PDK/strategy changes |
| `signoff --setup` | SDF/STA/power/GLS scripts | no | PDK, netlist, authored SDC, corners, sign-off policy changes |
| `design intent` | `meta/design_intent.json` | evidence snapshot | refreshed from effective run intent |
| `technology settings` | `meta/<pdk>/settings.json` | evidence snapshot | refreshed by technology-bound targets |
| `manifest` | `meta/<pdk>/manifest.json` | no | refresh at release/evidence collection |
| `metrics` | `meta/<pdk>/metrics.json` | no | refresh after stages change |

The detailed file-by-file reasoning is in
[IP development guide](ip_development_guide.md).

---

## 10. Reference lifecycle command sequences

### 10.1 New single-clock IP

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev HOST=uart \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS=

fx setup hjson reg doc rtl_stub top_from_core flist --force
fx lint_suite
fx sdc --setup --force
# review/edit constraints/<TOP>.sdc
fx cdc_rdc --setup --force
fx cdc_rdc
fx model --setup --force
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx formal --setup --force
fx formal
fx pdk use sky130
fx syn --setup
fx syn
fx eqy --setup
fx eqy
fx signoff --setup
fx sdf
fx sta
fx power_estimate
fx manifest
fx metrics
fx check
```

### 10.2 Timing-oriented post-synthesis qualification

```bash
for mode in min typ max; do
  for backend in sv cocotb; do
    fx sim_post_syn \
      --set GLS_BACKEND="$backend" \
      --set TIMING_MODE="$mode" \
      --set TEST_NAME=smoke \
      --set SDF_STRICT=1
  done
done
```

Use `zero` before the loop for the fastest netlist/model diagnostic and `unit`
when race or sampling behavior must be qualified.

### 10.3 Full repository E2E qualification

```bash
make test E2E_ROOT="$HOME/flexsoc-e2e"
```

One pytest invocation always qualifies both `sky130` and `ihp-sg13g2`. The logical
RTL, functional DV, property formal, and SDC stages run once; after `fx pdk use`
only the PDK-scoped synthesis, EQY, sign-off, GLS activity-power, manifest, metrics,
and check stages are rerun. Backend and timing-mode sweeps remain separate CI jobs.

### 10.4 Final evidence refresh

```bash
fx manifest
fx metrics   # collect/write the snapshot
fx check     # render that saved snapshot
```

A PASS dashboard is the start of review, not the end: inspect warnings,
unconstrained paths, coverage, waivers, tool/PDK identity, and the production
sign-off limitations recorded in the lifecycle documents.


## 11. Frozen Docker toolchain and project CI

Docker environment creation and FlexSoC project qualification are separate workflows. The complete image contract is documented in [`docker/README.md`](../docker/README.md).

On a push to `main`, `.github/workflows/toolchain-image.yml` acts only as the toolchain gate:

```text
validate docker/ci/image.lock + immutable GHCR digest
    ├─ current  → no rebuild
    └─ changed  → build → verify tools → publish → freeze new digest
```

Once the frozen image is valid, `.github/workflows/ci.yml` runs the repository qualification inside that exact image. Toolchain construction does not run the project test suite; project CI does not rebuild EDA tools.

For local inspection of the Docker environment use the scripts under `docker/scripts/`; for normal development use the common root `Makefile` workflows or the direct `fx`/pytest commands documented above.

## 13. EQY protocol partitioning and reset normalization

For single-clock IPs, `fx eqy` now proves the normal post-reset hardware contract by default. The generated configuration initializes both gold and gate designs through the clock/reset declared in `CLOCK_DOMAINS` before partition proofs begin:

```bash
fx eqy --set EQY_RESET_NORMALIZE=1 --set EQY_RESET_CYCLES=2
```

Use `EQY_RESET_NORMALIZE=0` only when the design contract explicitly requires equivalence from arbitrary power-up state. Multi-clock runs keep normalization disabled by default because independent-domain reset sequencing must be reviewed rather than inferred.

Packed 66-bit TL-UL response ports are not treated as one monolithic partition. The formal-only protocol view keeps the packed response internal and exposes only bounded witnesses for `a_ready`, `d_valid`, D-channel control, data, and metadata. This detail matters because EQY partitions every public output: exposing both the raw response and the witnesses would create duplicate raw bit partitions such as `cfg_tl_o.0` in addition to the intended field witnesses. The original RTL and mapped netlist are not edited. This preserves the TL-UL care set while making timeout diagnosis field-specific.

The default PDR engine is `abc pdr`. `abc pdr -rfi` remains an explicit expert override, but it is not the default because some partitions can terminate with an engine error and no counterexample trace. An engine error is not a demonstrated mismatch; rerun the generated witness with the stable default or inspect it through `fx eqy_debug`.

When EQY still does not close:

1. inspect the partition names in the EQY log;
2. distinguish `FAIL` from `timeout`;
3. run `fx eqy_debug` on the first unresolved witness;
4. do not increase timeouts until reset normalization, protocol care-set handling, and synthesis-boundary diagnostics have been checked.


## PDK-first sign-off and analysis ownership

Technology-dependent outputs use one consistent PDK-first hierarchy:

```text
runs/<design>/<variant>/
├── syn/<pdk>/
├── impl/<pdk>/
└── signoff/<pdk>/
    ├── <top>.sdc
    ├── equivalence/rtl_vs_syn/
    ├── sta/<corner>/<setup|hold>/
    ├── sdf/<corner>/
    ├── power/
    │   ├── activity/captures/
    │   ├── estimate/<corner>/
    │   └── analysis/<workload>/
    └── fusion/<workload>/<setup|hold>/
```

`activity/` contains only VCD/SAIF captures and conversion logs. Each analysis
family owns one canonical Tcl under its stage root; scenario-workload/mode
directories contain the scenario-local script and its reports. There is no `activity/scripts` directory and
no additional activity manifest.

The backend ownership follows the lifecycle domains directly:

```text
syn/eqy.py        -> RTL-to-netlist equivalence
signoff/sdc.py    -> authored SDC adapter/scaffold
signoff/sta.py    -> STA and SDF
signoff/gls.py    -> gate-level simulation
signoff/power.py  -> vectorless and activity power
signoff/fusion.py -> timing/power correlation
impl/impl.py       -> ORFS/OpenROAD physical implementation only
```

The Python API dispatches directly to these flow objects. `FlexSoCTarget` owns lifecycle routing while each domain object owns its EDA semantics. The sign-off facade exposes the same
engines as `signoff.pre` and `signoff.post`, with ideal/no-SPEF timing before
implementation and propagated-clock/SPEF timing after routing.

The OpenSTA Tcl families are prepared by the explicit sign-off setup methods.
Static analyses execute concrete per-corner copies so setup-owned templates remain immutable. Workload
analyses run only after a qualified GLS report and VCD/SAIF exist.

STA is consolidated rather than published as one primary report per scenario: `signoff/<pdk>/sta/sta.rpt` is the human QoR artifact and `sta.json` is its machine-readable companion. Power keeps `power.rpt` for vectorless/workload analysis, and fusion keeps `fusion.rpt` plus one `fusion_table.rpt` per workload. Scenario-local STA reports remain diagnostic execution artifacts, not separate release contracts.

### OpenSTA compatibility boundary

Fusion uses public `report_wns`, `report_tns`, `report_checks`, `report_power`,
and `report_activity_annotation` commands. It deliberately avoids private SWIG
objects and does not claim per-path power attribution; timing paths and average
power are reported for the same netlist, corner, mode, constraints, and activity
trace.
