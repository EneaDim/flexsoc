# Multi-clock IP development guide

The multi-clock flow uses the same high-level `fx` commands as the single-clock
flow. Set `CLOCK_MODE=multi`; FlexSoC routes the applicable commands to the
multi-clock backend.

## 1. Configure the run

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi
```

## 2. Create the run and HJSON maps

```bash
fx setup --force
fx hjson --force
```

A multi-clock design can generate multiple HJSON register maps, for example:

```text
data/tri_stream_dsp_cfg.hjson
data/tri_stream_dsp_dsp.hjson
```

## 3. Generate register RTL and docs

All selected maps:

```bash
fx reg doc --force
```

The explicit multi-clock targets remain available when one domain must be
selected directly:

```bash
fx reg_multi doc_multi --set REGMAP=cfg
fx reg_multi doc_multi --set REGMAP=dsp
```

## 4. Generate and edit RTL

```bash
fx rtl_stub --force
```

Edit the generated core. If its ports change and the wrapper remains generated
collateral:

```bash
fx top_from_core --force
```

## 5. Filelists and lint

```bash
fx flist --force
fx lint
fx lint_latch
fx lint_width
fx lint_unconnected
fx lint_undriven
fx lint_unused
```

## 6. Bootstrap the multi-clock model

```bash
fx setup_model --force
```

With `CLOCK_MODE=multi`, this generates the editable multi-clock model:

```text
model/model_tri_stream_dsp_multiclock.py
```

The current multi-clock scaffold owns its register configuration directly in
that model. It is a separate implementation from the single-clock
`regmap_<top>.py` object API described in the single-clock and existing-IP
guides.

Treat `setup_model --force` as a reset of the editable multi-clock model. After
customizing it, update the model deliberately when HJSON register names or
semantics change rather than blindly regenerating it.

## 7. Generate vector tests

```bash
fx tests_gen
fx tests
```

One test:

```bash
fx test_gen --set TEST_NAME=my_case
```

Generated files use the same common layout:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Register names in `config.regs` are domain-qualified, for example:

```text
cfg.GAIN 0x00000001
dsp.DSP_CTRL 0x00000000
cfg.CTRL 0x00000001
```

## 8. Generate verification infrastructure

```bash
fx setup_tb --force
fx setup_cocotb --force
```

The multi-clock testbench includes the required domain-specific clock/reset and
register-interface handling. Behavioral expectations remain in the generated
vector tests.

## 9. Run verification

```bash
fx sim_tests
fx cocotb_tests
```

One selected test:

```bash
fx sim --set TEST_NAME=mac_smoke
fx cocotb --set TEST_NAME=mac_smoke
```

## 10. Constraints and signoff

Generate the multi-clock SDC scaffold:

```bash
fx sdc_multi --force
```

Then run:

```bash
fx syn sdf sta power --force
```

Corner-oriented targets are also available:

```bash
fx sta_corners
fx power_corners
fx signoff_corners
```

## 11. Complete flow

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
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
fx sdc_multi --force
fx syn sdf sta power --force
```

## 12. E2E regression

The generated single-clock and multi-clock flows are exercised together by:

```bash
pytest -s tests/test_e2e_fx.py::test_fx_full_flow_debug --no-signoff
```

The test runs in an isolated `/tmp/flexsoc-full-e2e-...` workspace. Remove
`--no-signoff` to include synthesis/signoff.
