# Multi-clock IP development guide

This guide uses the same high-level target names as the single-clock flow. Set
`CLOCK_MODE=multi` once, then run the usual `hjson`, `reg`, `doc`, `rtl_stub`,
`top_from_core`, `setup_model`, `tests_gen`, `setup_tb`, and `setup_cocotb`
targets.

The explicit `_multi` target names remain available, but they are no longer the
preferred daily workflow.

## 1. Configure the run

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi
```

The selected `TOP` is the verification top. The SystemVerilog and cocotb
testbenches instantiate `tri_stream_dsp`, not `tri_stream_dsp_core`. To verify a
core directly, set `TOP=tri_stream_dsp_core` explicitly.

## 2. Create multi-regmap HJSON

```bash
fx setup --force
fx hjson --force
```

This creates multiple register maps, for example:

```text
data/tri_stream_dsp_cfg.hjson
data/tri_stream_dsp_dsp.hjson
```

Edit the HJSON files as the register interface evolves.

## 3. Generate register RTL and docs

All regmaps:

```bash
fx reg doc --force
```

One regmap only:

```bash
fx reg doc --set REGMAP=cfg
fx reg doc --set REGMAP=dsp
```

This lets you update one domain without regenerating unrelated collateral.

## 4. Generate RTL scaffold

```bash
fx rtl_stub --force
```

This creates:

```text
rtl/tri_stream_dsp_core.sv
rtl/tri_stream_dsp.sv
```

The wrapper instantiates the generated regblocks and the editable core. The core
contains the clock-domain logic, CDC examples, and datapath scaffold.

Edit:

```text
rtl/tri_stream_dsp_core.sv
```

If you change core ports, refresh only the wrapper:

```bash
fx top_from_core --force
```

## 5. Filelists and lint

Run lint before modelling and verification:

```bash
fx flist --force
fx lint
```

Focused lint:

```bash
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

The general lint log is cleanly named:

```text
logs/lint/tri_stream_dsp_lint_all.log
```

## 6. Model scaffold

```bash
fx setup_model --force
```

This creates:

```text
model/model_tri_stream_dsp_multiclock.py
model/regmap_tri_stream_dsp.py
```

The model file is editable and owns the behaviour, clock-domain assumptions, and
test catalog. The generated `regmap_*.py` helper keeps register names, offsets,
and helper functions near the model so a regmap change can be reflected without
manual duplication.

Recommended workflow after changing HJSON:

```bash
fx reg doc --force
fx setup_model --force
```

Then update the behavioural model and tests as needed.

## 7. Generate vector tests from the model

All model-defined tests:

```bash
fx tests_gen
```

One test only:

```bash
fx test_gen --set TEST_NAME=my_case
```

List tests:

```bash
fx tests
```

Generated tests live under:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

## 8. Register writes and register checks

Multi-clock tests can write multiple regmaps using qualified names:

```text
cfg.CTRL 0x00000000
cfg.GAIN 0x00000001
cfg.CTRL 0x00000001
dsp.MODE 0x00000000
```

Use register reads/checks for status-style verification where appropriate, for
example checking that a status bit or result register has been updated after a
transaction. Keep these checks in the model-generated test data so both SV and
cocotb use the same expected values.

## 9. Generate verification scaffold

```bash
fx setup_tb --force
fx setup_cocotb --force
```

The structure is intentionally aligned with the single-clock flow:

```text
tb/
├── include_tri_stream_dsp_tb.sv
├── tri_stream_dsp_tb.sv
├── drivers/
│   ├── tri_stream_dsp_tlul_driver.svh
│   ├── tri_stream_dsp_vec_driver.svh
│   └── tri_stream_dsp_vec_monitor.svh
├── tests/
└── cocotb/
    ├── Makefile
    ├── tri_stream_dsp_cocotb_tb.sv
    ├── tri_stream_dsp_multiclock_test.py
    └── drivers/
        ├── reg_driver.py
        ├── vec_driver.py
        └── vec_monitor.py
```

The cocotb wrapper instantiates the top-level DUT and exposes scalar proxy
signals for TL-UL fields so cocotb does not need to drive packed struct fields
directly.

## 10. Run verification

Single test:

```bash
fx sim --set TEST_NAME=mac_smoke
fx cocotb --set TEST_NAME=mac_smoke
```

All generated tests:

```bash
fx sim_tests
fx cocotb_tests
```

Waveforms:

```bash
fx view --set TEST_NAME=mac_smoke
fx view_cocotb --set TEST_NAME=mac_smoke
```

## 11. SDC and signoff

Generate the multi-clock SDC scaffold:

```bash
fx sdc_multi --force
```

Then run signoff:

```bash
fx syn sdf sta power --force
```

Corner targets are also available:

```bash
fx sta_corners
fx power_corners
fx signoff_corners
```

## 12. Full flow

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi
fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
fx lint
fx setup_model --force
fx tests_gen
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
fx sdc_multi --force
fx syn sdf sta power --force
```
