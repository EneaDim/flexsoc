# 🚀 FlexSoC quickstart

This is the shortest practical path through FlexSoC's controlled build and
qualification lifecycle for digital IP. It uses the same command vocabulary and
run model as the reference IPs and project CI.

The canonical engineering contract and release policy are in
[Project lifecycle](project_lifecycle.md). Scaffold ownership and stage-by-stage
implementation guidance are in [IP development guide](ip_development_guide.md).
Exact syntax and the complete target catalogue are in
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
more expensive behavioral gates.

### 4.1 Linting

```bash
fx lint_suite
```

### 4.2 CDC/RDC

```bash
fx cdc_rdc
```

The default output is a summary plus the detailed log path. Use `--live` for
all domains, checks, findings, and obligations.

### 4.3 Property formal

```bash
fx formal
```

This runs automatic CSR checks and authored BMC/prove/cover stages.

### 4.4 Functional regression

Generate the model/test workspace once:

```bash
fx setup_model --force
```

After it contains authored work, use `fx regmap_py --force` for routine CSR-only
updates instead of recreating the complete model workspace.

```bash
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail
```

Open a waveform when needed:

```bash
fx view
fx view_cocotb
```

## 5. Constraints and synthesis

```bash
fx setup_signoff --force
fx syn --force
```

## 6. RTL-to-netlist equivalence

```bash
fx eqy --force
```

EQY selects a solver portfolio automatically:

```text
single clock: SAT → PDR → SMTBMC
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

## 7. Post-synthesis analysis

```bash
fx sdf sta power_estimate --force
```

Optional post-synthesis gate simulation:

```bash
fx compile_post_syn --force
fx sim_post_syn --force
```

## 8. OpenROAD implementation

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

## 9. Consolidated status

```bash
fx manifest --force
fx manifest_show
fx metrics --force
fx check --force
```

## 10. Common update loops

### 10.1 Add or change a CSR

```bash
# edit HJSON
fx reg doc regmap_py tests_gen --force
fx flist --force
fx lint_suite
fx cdc_rdc
fx regression
fx formal
fx syn eqy --force
```

### 10.2 Change RTL behavior

```bash
# edit RTL, model, tests, and properties together
fx flist --force
fx lint_suite
fx cdc_rdc
fx tests_gen --force
fx formal
fx regression
fx syn eqy --force
```

### 10.3 Change RTL ports

```bash
# edit <top>_core.sv
fx top_from_core flist setup_tb setup_cocotb --force
fx lint_suite
fx cdc_rdc
fx regression
fx formal
fx syn eqy --force
```

### 10.4 Change clock domains

```bash
# update N_CLOCKS, CLOCK_DOMAINS, CLOCK_RELATIONSHIPS
fx setup_tb setup_cocotb setup_formal setup_syn setup_eqy setup_signoff --force
fx flist --force
fx lint_suite
fx cdc_rdc
fx regression
fx formal
fx syn eqy --force
fx sdf sta power_estimate --force
```

## 11. Existing reusable IP

```bash
fx setup --force
fx ip_load --force
fx flist --force
fx lint_suite
fx cdc_rdc
fx tests_gen --force
fx formal
fx regression
fx syn eqy --force
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
