# Multi-clock IP development guide ⏱️

> 🧰 **Shell setup used in this guide**
>
> Install/sync dependencies once, then activate the project environment:
>
> ```bash
> uv sync
> source .venv/bin/activate
> ```
>
> After activation, run commands directly with `fx ...`.

This guide shows the multi-clock IP flow using the same mental model as the single-clock IP flow: generate register descriptions, run regtool, generate an RTL scaffold, edit the core, refresh the top wrapper from the core, lint early, then build model and verification collateral.

The example IP is `tri_stream_dsp`.

## 1. Architecture goal

`tri_stream_dsp` has three explicit clock domains:

| Domain | Clock | Reset | Purpose |
| --- | --- | --- | --- |
| cfg | `cfg_clk_i` | `cfg_rst_ni` | software register access and global control |
| rx | `rx_clk_i` | `rx_rst_ni` | input stream capture |
| dsp | `dsp_clk_i` | `dsp_rst_ni` | compute datapath and DSP status |

It has two register maps:

| Regmap | File | Domain | Purpose |
| --- | --- | --- | --- |
| cfg | `data/tri_stream_dsp_cfg.hjson` | cfg | enable, soft reset, clock-gate intent, cfg status |
| dsp | `data/tri_stream_dsp_dsp.hjson` | dsp | operation select, threshold, result, DSP status |

The scaffolded datapath is intentionally small but realistic:

- RX domain accepts input samples.
- RX→DSP crossing uses `prim_fifo_async`.
- DSP domain computes MAC, absolute difference, or energy estimate.
- Clock-gating intent is represented with `prim_clk_gate`.
- Status and result registers are driven through `hw2reg` paths.

## 2. Create the run

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart
fx setup
```

## 3. Generate only the multi-clock HJSON files

```bash
fx hjson_multi --force
```

This creates:

```text
workspace/runs/tri_stream_dsp/dev/data/
├── tri_stream_dsp_cfg.hjson
└── tri_stream_dsp_dsp.hjson
```

Edit the HJSON files before running regtool. Use `cfg` for global/software-facing control and `dsp` for datapath-local control/status.

## 4. Generate register RTL and docs

Generate all regmaps:

```bash
fx reg_multi doc_multi --force
```

Generate only one changed regmap:

```bash
fx reg_multi doc_multi --set REGMAP=cfg
fx reg_multi doc_multi --set REGMAP=dsp
```

Without `--force`, `reg_multi` and `doc_multi` are incremental: they skip outputs that are newer than their HJSON source.

`regtool` still generates each register block with local ports named `clk_i` and `rst_ni`. The generated wrapper maps those local ports to the real domain clocks, for example `cfg_clk_i` and `dsp_clk_i`.

## 5. Generate RTL from the regmaps

```bash
fx rtl_stub_multi --force
```

This creates:

```text
rtl/tri_stream_dsp_core.sv
rtl/tri_stream_dsp.sv
```

The split is the same idea as the single-clock flow:

- `tri_stream_dsp_core.sv` is the user-editable design file.
- `tri_stream_dsp.sv` is the generated wrapper.

The wrapper instantiates:

```systemverilog
tri_stream_dsp_cfg_reg_top u_cfg_reg_top (...);
tri_stream_dsp_dsp_reg_top u_dsp_reg_top (...);
tri_stream_dsp_core        u_core (...);
```

The core uses explicit regmap structs:

```systemverilog
input  tri_stream_dsp_cfg_reg2hw_t cfg_reg2hw_i,
output tri_stream_dsp_cfg_hw2reg_t cfg_hw2reg_o,
input  tri_stream_dsp_dsp_reg2hw_t dsp_reg2hw_i,
output tri_stream_dsp_dsp_hw2reg_t dsp_hw2reg_o,
```

Reggen path rule:

```systemverilog
// Multi-field register:
cfg_reg2hw_i.ctrl.enable.q

// Single-field register:
cfg_reg2hw_i.gain.q

// Hardware-updated single-field register:
dsp_hw2reg_o.result.d
```

Do not use `.value.q` or `.value.d` for single-field registers.

## 6. Refresh the wrapper after editing the core

Edit only the core when you change datapath logic or add/remove external ports:

```text
rtl/tri_stream_dsp_core.sv
```

Then refresh the wrapper:

```bash
fx top_from_core_multi --force
```

This regenerates only:

```text
rtl/tri_stream_dsp.sv
```

It preserves the multi-clock structure: cfg TL-UL window, dsp TL-UL window, reg2hw/hw2reg wiring, and all non-register core ports exposed at the top level.

## 7. Generate filelists and lint before modelling

Before modelling or verification, build the filelists and lint the generated RTL:

```bash
fx flist lint --force
fx lint_latch lint_width lint_unconnected lint_undriven lint_unused
```

This stage intentionally comes before modelling. It catches syntax errors, broken regmap paths, missing domain ports, FIFO wiring issues and obvious reset/clocking mistakes while the design is still small.

Focused lint logs are written under:

```text
logs/lint/
├── <top>_lint_width_ip.log
└── raw/<top>_lint_width_raw.log
```

The terminal shows a compact summary. Use `--live` only when you want full tool output:

```bash
fx lint_width --live
```

## 8. Generate the multi-clock model and vector tests

```bash
fx setup_model_multi --force
```

This creates an editable model:

```text
model/model_tri_stream_dsp_multiclock.py
```

Generate vector tests explicitly from that model:

```bash
fx tests_gen_multi
fx test_gen_multi --set TEST_NAME=my_new_case
```

Generated vector tests live here:

```text
tb/tests/<test>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

The model is the only source of the vector tests. Simulators do not call the model at runtime; they consume the generated files.

Example `config.regs`:

```text
cfg.CTRL 0x00000001
cfg.GAIN 0x00000001
dsp.DSP_CTRL 0x00000000
dsp.THRESHOLD 0x00000010
```

Example `data_in.vec`:

```text
0 rx_sample_i 0x0003
0 rx_coeff_i 0x0004
0 rx_valid_i 0x1
```

Example `data_out.vec`:

```text
0 dsp_result_o 0x0000000d
0 dsp_valid_o 0x1
0 dsp_overflow_o 0x0
```

For the default multi-clock scaffold, the first column is a transaction index. The SV and cocotb scaffolds check outputs by order because exact cycle alignment across async domains is not a stable contract.

## 9. Generate verification scaffolds

The verification collateral is split like the single-clock flow, so you can regenerate only the piece you need:

```bash
fx setup_tb_multi --force
fx setup_cocotb_multi --force
```

These targets only create the verification scaffolds. They do not regenerate
`tb/tests/*`; run `tests_gen_multi` or `test_gen_multi` when the model or a
specific vector test changes.

SystemVerilog files:

```text
tb/include_tri_stream_dsp_tb.sv
tb/drivers/tri_stream_dsp_tlul_driver.svh
tb/drivers/tri_stream_dsp_vec_driver.svh
tb/drivers/tri_stream_dsp_vec_monitor.svh
tb/tri_stream_dsp_tb.sv
```

cocotb files:

```text
tb/cocotb/Makefile
tb/cocotb/tri_stream_dsp_cocotb_tb.sv
tb/cocotb/drivers/__init__.py
tb/cocotb/drivers/reg_driver.py
tb/cocotb/drivers/vec_driver.py
tb/cocotb/drivers/vec_monitor.py
tb/cocotb/tri_stream_dsp_multiclock_test.py
```

Both SV and cocotb instantiate the real top-level wrapper `tri_stream_dsp`, not `tri_stream_dsp_core`. The tests therefore exercise the generated cfg/dsp TL-UL register blocks plus the editable core. If you want a core-only testbench, make the core the selected `TOP` explicitly.

Regenerate selectively:

```bash
# Config/model changed and tests must be regenerated:
fx setup_model_multi --force
fx tests_gen_multi

# SV verification changed or was deleted:
fx setup_tb_multi --force

# cocotb verification changed or was deleted:
fx setup_cocotb_multi --force

# Core ports changed, but verification files are still valid:
fx top_from_core_multi --force
```

`fx sim` and `fx sim_tests` do not regenerate scaffolds. They compile and run the existing testbench against generated vector files. Waveforms are written through the standard `+VCD=...` plusarg under `sim/`, so `fx view` can open the latest SV waveform after simulation.

## 10. List and run tests

```bash
fx tests
fx sim --set TEST_NAME=mac_smoke
fx cocotb --set TEST_NAME=mac_smoke
```

Run all generated tests:

```bash
fx sim_tests
fx cocotb_tests
```

Regenerate only the pieces you changed:

```bash
# HJSON changed:
fx reg_multi doc_multi --set REGMAP=dsp
fx rtl_stub_multi --force
fx flist lint --force

# Core ports changed:
fx top_from_core_multi --force
fx flist lint --force

# Model changed:
fx tests_gen_multi
fx test_gen_multi --set TEST_NAME=my_new_case
fx tests

# Testbench scaffold changed or was deleted:
fx setup_tb_multi setup_cocotb_multi --force
```

## 11. Constraints and signoff

Generate the IP-level multi-clock SDC:

```bash
fx sdc_multi --force
```

The SDC lives under:

```text
pnr_openroad/tri_stream_dsp.sdc
```

It defines IP-boundary clocks and asynchronous relationships. Review it manually; CDC and generated-clock intent must be explicit.

Then run synthesis/signoff:

```bash
fx syn --force
fx sdf
fx sta_corners
fx power_corners
```

## 12. SoC compliance

A SoC must connect both register windows and every clock/reset explicitly:

- cfg register window: `cfg_tl_i` / `cfg_tl_o`
- dsp register window: `dsp_tl_i` / `dsp_tl_o`
- cfg domain: `cfg_clk_i` / `cfg_rst_ni`
- rx domain: `rx_clk_i` / `rx_rst_ni`
- dsp domain: `dsp_clk_i` / `dsp_rst_ni`

Do not blindly copy the IP SDC into a SoC. The SoC owns top-level clock names, generated clocks, clock groups, IO delays and hierarchy-specific CDC exceptions. Use the IP SDC as the authoring contract, then adapt it at the SoC boundary.

## 13. Full clean sequence

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart
fx setup
fx hjson_multi --force
fx reg_multi doc_multi --force
fx rtl_stub_multi --force
fx top_from_core_multi --force
fx flist lint --force
fx lint_latch lint_width lint_unconnected lint_undriven lint_unused
fx setup_model_multi --force
fx tests_gen_multi
fx setup_tb_multi setup_cocotb_multi --force
fx tests
fx sim --set TEST_NAME=mac_smoke
fx cocotb --set TEST_NAME=mac_smoke
fx sdc_multi --force
fx syn sdf sta_corners power_corners --force
```

The compatibility shortcut is still available:

```bash
fx multiclock_scaffold --force
```

It runs the decomposed generation steps in the correct order.


## Unified generic targets

Set the run mode once, then use the same target names as the single-clock flow:

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist lint --force
fx setup_model --force
fx tests_gen
fx setup_tb setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

The explicit `_multi` targets still exist, but the generic names dispatch to them
when `CLOCK_MODE=multi` or `MULTICLOCK=1` is set.

The model scaffold owns vector generation. `setup_tb` and `setup_cocotb` only
create verification infrastructure. Regmap helper files are regenerated beside
the model:

```text
model/model_tri_stream_dsp_multiclock.py
model/regmap_tri_stream_dsp.py
```

Use `write("REG", value)` for config writes and `expect("STATUS", value)` for
simple status read/check rows in `config.regs`.
