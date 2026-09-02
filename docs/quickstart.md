# 🚀 FlexSoC quickstart

This is the shortest practical path through the current IP flow. The narrative
of how a project evolves from design intent to qualified release is in
[Project lifecycle](project_lifecycle.md). The detailed step-by-step engineering
procedure is in [IP development guide](ip_development_guide.md). Exact syntax,
options, variables, and the complete target catalogue are in
[Command reference](command_reference.md).

## 1. Install

For the complete ASIC flow, use the immutable Docker toolchain image recorded by
the repository. A plain `uv sync` installs the Python package but does not install
Yosys, OpenSTA, OpenROAD, Verilator, Slang, formal solvers, and the rest of the
EDA stack.

From the repository root:

```bash
IMAGE_REF="$(bash -lc 'source docker/scripts/common.sh; validate_lock')"
docker pull "$IMAGE_REF"
docker run --rm -it \
  --pull=missing \
  --volume "$PWD:/workspace" \
  --workdir /workspace \
  --env PYTHONPATH=src \
  --env DEPS_MODE=system \
  "$IMAGE_REF" bash
```

Inside the container:

```bash
uv pip install --python "$VIRTUAL_ENV/bin/python" --no-deps --editable .
fx deps-doctor
fx doctor
fx commands
```

See the top-level [README](../README.md) for host-only development and
[Docker documentation](../docker/README.md) for image maintenance.

## 2. Configure the run

### Single clock

```bash
fx settings \
  TOP=my_ip RUN_TOP=my_ip RUN_ID=dev HOST=uart \
  N_CLOCKS=1 \
  CLOCK_DOMAINS=core:clk_i:rst_ni:10:low \
  CLOCK_RELATIONSHIPS=
```

### N clocks

```bash
fx settings \
  TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart \
  N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:20:low,rx:rx_clk_i:rx_rst_ni:16:low,dsp:dsp_clk_i:dsp_rst_ni:30:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
```

The commands below are identical for one or many clocks.

## 3. Bootstrap specification and RTL

```bash
fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
```

Edit the authored sources:

```text
data/<top>.hjson                 CSR/register specification
rtl/<top>_core.sv                RTL behavior and interfaces
dv/functional/model/<top>_model.py
dv/functional/model/<top>_tests.py
dv/formal/properties/            authored assertions and covers
```

## 4. Design verification

Run verification in this order so structural problems are removed before the
more expensive behavioral gates and every clock-aware consumer sees the same
timing contract.

### 4.1 Linting

```bash
fx lint_suite
```

### 4.2 Author the timing contract

Initialize the SDC once after RTL/lint are structurally clean:

```bash
fx sdc --setup --force
```

Review and edit `constraints/<TOP>.sdc`. It is the timing source of truth for
functional clock generation, CDC/RDC clock relationships, synthesis I/O drive/load
setup, implementation, and STA. The scaffold includes clocks, clock quality, I/O
timing, drive/load, and commented sections for false paths and multicycle paths.

### 4.3 CDC/RDC

```bash
fx cdc_rdc --setup --force
fx cdc_rdc
```

Canonical CDC/RDC evidence is intentionally small: `analysis/cdc_rdc/design.json`
(raw structure), `summary.json` (machine-readable findings/obligations),
`cdc_rdc.rpt` (human report), plus the extraction script/log. Clock relationships
come from `<TOP>.sdc`; reset ownership and polarity remain bootstrap metadata.

### 4.4 Property formal

```bash
fx formal --setup --force
fx formal
```

This runs automatic CSR checks and authored BMC/prove/cover stages from existing
setup collateral.

### 4.5 Functional regression

Generate the model/test workspace once:

```bash
fx model --setup --force
```

After it contains authored work, use `fx regmap_py --force` for routine CSR-only
updates instead of recreating the complete model workspace.

```bash
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx coverage_detail
```

Both functional backends derive clock period, waveform, source latency, and clock
uncertainty from `<TOP>.sdc`. Clock uncertainty becomes bounded uniform jitter
with 1 ps resolution; the run `SEED` makes the SV and cocotb stimulus reproducible.
The waveform still owns duty cycle, and `set_clock_transition` remains an STA
electrical constraint rather than an analog slew model.

Open a waveform when needed:

```bash
fx view
fx view_cocotb
```

## 5. Select technology and synthesize

The authored SDC is technology independent and is not regenerated on a PDK switch.

```bash
fx pdk use sky130
fx syn --setup
fx syn
```

`syn --setup` consumes `constraints/<TOP>.sdc` and derives the small Yosys/ABC
`abc.constr` drive/load boundary required by synthesis.

## 6. RTL-to-netlist equivalence

```bash
fx eqy --setup
fx eqy
```

EQY selects a solver portfolio automatically:

```text
single clock: SAT → SMTBMC → PDR
N clocks:     PDR → SMTBMC
```

Useful controls:

```bash
fx eqy --set EQY_JOBS=8
fx eqy --set EQY_STRATEGY_ORDER=pdr,smt
```

Debug unresolved or failing partitions:

```bash
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --wave <partition>
fx eqy_debug --files <partition>
```

## 7. Post-synthesis analysis

```bash
fx signoff --setup
fx sdf
fx sta
fx power_estimate
```

STA sources `constraints/<TOP>.sdc` directly and writes the canonical human and
machine-readable timing evidence to `signoff/<pdk>/sta/sta.rpt` and `sta.json`.
The report is QoR-first: scenario status, WNS/TNS, minimum period/Fmax, constraint
coverage, electrical checks, and detailed setup/hold paths without duplicating
the same information across many public reports.

Optional post-synthesis gate simulation:

```bash
fx compile_post_syn --force
fx sim_post_syn --force
```

## 8. OpenROAD implementation

```bash
fx pnr --setup --force
fx pnr --force
fx pnr_gui
```

Post-PnR sign-off resolves the final netlist and SPEF from the canonical
implementation branch:

```bash
fx signoff_post_pnr --setup --force
fx sdf_post_pnr
fx sta_post_pnr
fx compile_post_pnr --force
fx sim_post_pnr --force
```

Use explicit `NETLIST`/`SPEF_FILE` overrides only for intentional exceptional
analysis, not for the normal routed flow.

## 9. Consolidated status

```bash
fx manifest
fx manifest_show
fx metrics
fx check
```

`fx metrics` writes the current normalized snapshot to
`meta/<pdk>/metrics.json`. `fx check` reads that saved snapshot and renders the
colored lifecycle dashboard without recollecting metrics.

## 10. Common update loops

The rule is always the same: edit the owning authored source, regenerate only the
collateral whose inputs changed, then rerun downstream gates. Run targets do not
regenerate setup implicitly.

### 10.1 Add or change a CSR

```bash
# edit HJSON
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

### 10.2 Change RTL behavior

```bash
# edit RTL, model, tests, and properties together
fx flist --force
fx lint_suite
fx cdc_rdc --setup --force
fx cdc_rdc
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx formal_prove formal_cover --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
```

### 10.3 Change RTL ports

```bash
# edit <top>_core.sv
fx top_from_core flist --force
fx lint_suite
# review/update constraints/<TOP>.sdc if interface timing changed
fx cdc_rdc --setup --force
fx cdc_rdc
fx tb cocotb --setup --force
fx regression
fx formal_prove formal_cover --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
```

### 10.4 Change clock/reset architecture

Change bootstrap settings only when the domain/reset topology itself changes. Then
regenerate the SDC scaffold intentionally, reapply/review authored timing intent,
and regenerate every clock-derived setup.

```bash
fx settings N_CLOCKS=<n> CLOCK_DOMAINS=<domains> CLOCK_RELATIONSHIPS=<relations>
fx top_from_core flist --force
fx lint_suite
fx sdc --setup --force
# edit/review constraints/<TOP>.sdc before continuing
fx cdc_rdc --setup --force
fx cdc_rdc
fx tb cocotb --setup --force
fx regression
fx formal --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
fx signoff --setup --force
fx sdf
fx sta
fx power_estimate
```

If only timing values change (waveform, latency, uncertainty, I/O delays, drive/load,
exceptions), edit `constraints/<TOP>.sdc` directly; do not change a parallel clock
timing setting. Regenerate the affected TB/synthesis/sign-off setup and rerun CDC/RDC
when clock relationships changed.

## 11. Existing reusable IP

```bash
fx setup --force
fx ip_load --force
fx flist --force
fx lint_suite
# the package-owned constraints/<TOP>.sdc remains authored timing intent
fx cdc_rdc --setup --force
fx cdc_rdc
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx formal --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
fx eqy
```

Preserve the IP-owned HJSON, RTL, model, tests, and properties. Regenerate only
the explicitly derived collateral.

## 12. Complete automated flow

After the authored sources and tests are ready:

```bash
fx ip_flow --force
```

Include OpenROAD implementation:

```bash
fx ip_flow_all --force
```

For a flow that must not regenerate register RTL/docs:

```bash
fx ip_flow_noreg --force
```

## 13. Project regression

```bash
pytest -q tests/test_api.py
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```

Frontend-only iteration:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff --e2e-root ~/flexsoc-e2e
```
