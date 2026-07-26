# Folder structure

FlexSoC keeps generated files inside a run directory:

```text
workspace/runs/<TOP>/<RUN_ID>/
```

For example:

```text
workspace/runs/test/dev/
workspace/runs/tri_stream_dsp/dev/
```

## Run directory

```text
workspace/runs/<TOP>/<RUN_ID>/
├── data/          # HJSON register descriptions
├── doc/           # generated register documentation
├── logs/          # compact logs, lint logs, verification logs, signoff logs
├── model/         # editable Python model and generated regmap helpers
├── pnr_openroad/  # SDC and physical/signoff collateral
├── rtl/           # generated register RTL, core, wrapper, filelists
├── sim/           # simulation outputs and waveforms
└── tb/            # verification scaffold and vector tests
```

## RTL

```text
rtl/
├── <top>.sv             # top wrapper; this is what the TB instantiates
├── <top>_core.sv        # user-editable core logic
├── rtl_common.f         # common packages/primitives/filelist
└── rtl_ip.f             # generated IP-local RTL/filelist
```

For multi-clock designs, the wrapper also instantiates the generated regblocks,
for example:

```text
rtl/<top>_cfg_reg_top.sv
rtl/<top>_dsp_reg_top.sv
rtl/<top>_core.sv
rtl/<top>.sv
```

## Model

```text
model/
├── model_<top>.py              # editable single-clock model
├── model_<top>_multiclock.py   # editable multi-clock model
└── regmap_<top>.py             # generated helper for register names/paths
```

`setup_model` creates the editable model scaffold and the generated regmap
helper. The model is then run by `tests_gen` or `test_gen` to create vector
files.

## Vector tests

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

These files are generated from the model. SystemVerilog and cocotb consume these
files only; they do not import the model during simulation.

## SystemVerilog testbench

Single-clock and multi-clock flows use the same layout. The reusable
SystemVerilog driver and monitor files live under `tb/drivers/`:

```text
tb/
├── include_<top>_tb.sv
├── <top>_tb.sv
├── drivers/
│   ├── <top>_vec_driver.svh
│   ├── <top>_vec_monitor.svh
│   └── <top>_tlul_driver.svh      # only when the generated TB needs TL-UL access
└── tests/
    └── <TEST_NAME>/
```

The testbench instantiates `<top>`, not `<top>_core`. To test the core directly,
set `TOP=<top>_core` explicitly.

## cocotb

```text
tb/cocotb/
├── Makefile
├── <top>_cocotb_tb.sv
├── <top>_test.py
└── drivers/
    ├── __init__.py
    ├── reg_driver.py
    ├── vec_driver.py
    └── vec_monitor.py
```

For multi-clock TL-UL designs, the cocotb wrapper exposes scalar proxy signals
instead of asking cocotb to drive packed struct fields directly.

## Logs

```text
logs/
├── lint/
│   ├── <top>_lint_all.log
│   ├── <top>_lint_width_ip.log
│   └── raw/
├── signoff/
│   ├── <top>_sdf.log
│   ├── <top>_sta_ss_setup.log
│   └── <top>_power_tt.log
└── verification/
    ├── <top>_sv_compile_<TEST_NAME>.log
    ├── <top>_sv_sim_<TEST_NAME>.log
    └── <top>_cocotb_<TEST_NAME>.log
```

The terminal shows compact progress by default. Use `--live` for full tool
output.
