# 🚀 FlexSoC quickstart

This is the shortest practical path through the current IP flow. The complete
engineering rationale, quality gates, solver guidance, change workflows, and
release policy are in [Project lifecycle](project_lifecycle.md). Exact syntax,
options, variables, and the complete target catalogue are in
[Command reference](command_reference.md).

## 1. Install

```bash
uv sync
source .venv/bin/activate
fx doctor
fx commands
```

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
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:10:low,rx:rx_clk_i:rx_rst_ni:8:low,dsp:dsp_clk_i:dsp_rst_ni:6:low' \
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
fx lint_suite
```

Edit these sources:

```text
data/<top>.hjson                 CSR/register specification
rtl/<top>_core.sv                RTL behavior and interfaces
dv/functional/model/<top>_model.py
dv/functional/model/<top>_tests.py
dv/formal/properties/            authored assertions and covers
```

Generate the model/test workspace once:

```bash
fx setup_model --force
```

After it contains authored work, use `fx regmap_py --force` for routine CSR-only
updates instead of recreating the complete model workspace.

## 4. Functional verification

```bash
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail
```

Open the latest waveform when needed:

```bash
fx view
fx view_cocotb
```

## 5. Property formal

```bash
fx formal
```

This runs automatic CSR checks and authored BMC/prove/cover stages.

## 6. Constraints and synthesis

```bash
fx setup_sdc --force
fx syn --force
```

## 7. RTL-to-netlist equivalence

```bash
fx eqy --force
```

EQY selects a solver portfolio automatically:

```text
single clock: SAT → SMTBMC → PDR
N clocks:     PDR → SMTBMC
```

Useful controls:

```bash
fx eqy --force --set EQY_JOBS=8
fx eqy --force --set EQY_STRATEGY_ORDER=pdr,smt
```

Debug unresolved or failing partitions:

```bash
fx eqy_debug
fx eqy_debug <partition>
fx eqy_debug --wave <partition>
fx eqy_debug --files <partition>
```

## 8. Post-synthesis analysis

```bash
fx sdf sta power_estimate --force
```

Optional post-synthesis gate simulation:

```bash
fx compile_post_syn --force
fx sim_post_syn --force
```

## 9. OpenROAD implementation

```bash
fx setup_pnr --force
fx pnr --force
fx pnr_gui
```

Post-PnR SDF/GLS requires the final implementation outputs:

```bash
fx sdf_post_pnr --force \
  --set NETLIST=/path/to/final_netlist.v \
  --set SPEF_FILE=/path/to/final.spef \
  --set PNR_SDC_FILE=/path/to/final.sdc

fx compile_post_pnr --force --set NETLIST=/path/to/final_netlist.v
fx sim_post_pnr --force --set NETLIST=/path/to/final_netlist.v
```

## 10. Consolidated status

```bash
fx manifest --force
fx manifest_show
fx metrics --force
fx check --force
```

## 11. Common update loops

### Add or change a CSR

```bash
# edit HJSON
fx reg doc regmap_py tests_gen --force
fx flist --force
fx lint_suite
fx regression
fx formal
fx syn eqy --force
```

### Change RTL behavior

```bash
# edit RTL, model, tests, and properties together
fx flist --force
fx lint_suite
fx tests_gen --force
fx regression
fx formal
fx syn eqy --force
```

### Change RTL ports

```bash
# edit <top>_core.sv
fx top_from_core flist setup_tb setup_cocotb --force
fx lint_suite
fx regression
fx formal
fx syn eqy --force
```

### Change clock domains

```bash
# update N_CLOCKS, CLOCK_DOMAINS, CLOCK_RELATIONSHIPS
fx setup_tb setup_cocotb setup_formal setup_sdc setup_syn setup_eqy setup_signoff --force
fx flist --force
fx lint_suite
fx regression
fx formal
fx syn eqy --force
fx sdf sta power_estimate --force
```

## 12. Existing reusable IP

```bash
fx setup --force
fx ip_load --force
fx flist --force
fx lint_suite
fx tests_gen --force
fx regression
fx formal
fx syn eqy --force
```

Preserve the IP-owned HJSON, RTL, model, tests, and properties. Regenerate only
the explicitly derived collateral.

## 13. Complete automated flow

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

## 14. Project regression

```bash
pytest -q tests/test_api.py
pytest -s tests/test_e2e_fx.py --e2e-root ~/flexsoc-e2e
```

Frontend-only iteration:

```bash
pytest -s tests/test_e2e_fx.py --no-signoff --e2e-root ~/flexsoc-e2e
```
