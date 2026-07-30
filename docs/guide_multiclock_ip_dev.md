# ⏱️ Multi-clock IP development guide

The multi-clock flow keeps the same high-level ownership as the single-clock
flow while changing the parts that genuinely depend on clock domains: register
maps, synchronization, verification timing, constraints, and signoff.

Set `CLOCK_MODE=multi`; generic `fx` commands route to the multi-clock backend.

## 1. ⚙️ Configure the run

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi
```

## 2. 🧾 Create the run and register-domain specifications

```bash
fx setup --force
fx hjson --force
```

A multi-clock design can own multiple HJSON maps, for example:

```text
data/tri_stream_dsp_cfg.hjson
data/tri_stream_dsp_dsp.hjson
```

Generate derived register RTL/docs:

```bash
fx reg doc --force
```

Select one domain explicitly when needed:

```bash
fx reg_multi doc_multi --set REGMAP=cfg
fx reg_multi doc_multi --set REGMAP=dsp
```

## 3. 🛠️ Generate and edit RTL

```bash
fx rtl_stub --force
```

Edit the core. If the core ports change while the wrapper is still generated:

```bash
fx top_from_core --force
```

## 4. 🧭 Resolve hierarchy and lint

```bash
fx flist --force
fx lint_suite
```

The same Slang-backed `rtl_common.f` / `rtl_ip.f` contract is used as in the
single-clock flow.

Choose lint backend when needed:

```bash
fx lint_suite --set LINT_TOOL=slang
fx lint_suite --set LINT_TOOL=verilator
```

## 5. 🧠 Bootstrap model/regmap/tests

```bash
fx setup_model --force
```

The model directory uses the same canonical split:

```text
model/
├── tri_stream_dsp_model.py
├── tri_stream_dsp_regmap.py
└── tri_stream_dsp_tests.py
```

Ownership:

- `*_model.py`: editable behavioral/reference model;
- `*_regmap.py`: generated from all selected HJSON domains;
- `*_tests.py`: editable scenario/vector generation.

The generated regmap exposes domain-qualified objects such as:

```python
CFG = regmap.domain("cfg")
DSP = regmap.domain("dsp")
```

After an HJSON-only change:

```bash
fx reg doc --force
fx regmap_py --force
fx tests_gen --force
```

Do not reset model/tests unless their behavior actually changes.

## 6. ⏱️ Multi-clock verification timing

A multi-clock test must not pretend unrelated domains share one global cycle
count. The generated flow therefore keeps transaction order explicit and can
consume expected outputs when a domain-specific valid signal asserts.

For the generated DSP example, expected DSP rows are consumed when:

```text
dsp_valid_o == 1
```

That preserves the same test ownership as single-clock designs while matching
the real timing model of asynchronous domains.

## 7. 🧪 Generate vector tests

```bash
fx tests_gen --force
fx tests
```

One selected scenario:

```bash
fx test_gen --set TEST_NAME=my_case
```

Each scenario still materializes as:

```text
tb/tests/<TEST_NAME>/
├── config.regs
├── data_in.vec
└── data_out.vec
```

Serialized CSR paths remain domain-qualified, for example:

```text
cfg.GAIN 0x00000001
dsp.DSP_CTRL 0x00000000
cfg.CTRL 0x00000001
```

## 8. ✅ Generate and run verification

```bash
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

One test:

```bash
fx sim --set TEST_NAME=mac_smoke
fx cocotb --set TEST_NAME=mac_smoke
```

## 9. 🏗️ Multi-clock constraints and signoff

Generate the timing-constraint scaffold:

```bash
fx sdc_multi --force
```

Then run:

```bash
fx syn sdf sta power_estimate --force
```

Corner-oriented targets:

```bash
fx sta_corners
fx power_estimate_corners
fx signoff_corners
```

Clock-domain changes can affect synchronization logic, constraints, and timing,
so this is a good example of change propagation extending beyond RTL simulation.

## 10. 🔄 Complete development flow

```bash
fx settings TOP=tri_stream_dsp RUN_TOP=tri_stream_dsp RUN_ID=dev HOST=uart CLOCK_MODE=multi
fx setup --force
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
fx lint_suite
fx setup_model --force
fx tests_gen --force
fx tests
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
fx sdc_multi --force
fx syn sdf sta power_estimate --force
```

## 11. 🧪 E2E regression

```bash
pytest -s tests/test_e2e_fx.py::test_fx_full_flow_debug --no-signoff
```

Use another workspace base if desired:

```bash
pytest -s tests/test_e2e_fx.py::test_fx_full_flow_debug \
  --no-signoff \
  --e2e-root ~/flexsoc-e2e
```
