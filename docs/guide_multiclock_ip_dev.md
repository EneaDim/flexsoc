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
dv/functional/model/
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
dv/functional/tests/<TEST_NAME>/
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

## 8. ✅ Functional verification and coverage

Generate both execution backends:

```bash
fx setup_tb setup_cocotb --force
```

Debug one test when needed:

```bash
fx sim --set TEST_NAME=mac_smoke
fx cocotb --set TEST_NAME=mac_smoke
```

For normal closure, run the complete catalogue and merged coverage:

```bash
fx regression
fx coverage_detail
```

The report uses the same scope × type matrix as single-clock designs:

```text
Scope          line   toggle   expr   branch   fsm   user   total
design          ...     ...     ...      ...    ...    ...     ...
registers       ...     ...     ...      ...    ...    ...     ...
common          ...     ...     ...      ...    ...    ...     ...
other           ...     ...     ...      ...    ...    ...     ...
all             ...     ...     ...      ...    ...    ...     ...
```

The difference is in timing semantics: expected transactions are consumed by
the relevant domain/event rather than pretending every interface shares one
cycle counter.

## 9. 🧠 Multi-clock formal verification

The formal structure is intentionally the same as for a single-clock IP:

```text
automatic CSR properties
  ├── BMC
  ├── PROVE
  └── COVER

authored design properties
  ├── BMC
  ├── PROVE
  └── COVER
```

Run:

```bash
fx formal
```

Clock-domain architecture makes assumptions more important. Assertions that
cross domains should model synchronization/protocol semantics deliberately
rather than assuming simultaneous edges on unrelated clocks.

Formal proof status remains separate from functional code coverage.

## 10. 🌐 CDC and RDC — next structural closure step

Multi-clock verification is incomplete if the project only checks functional
vectors and timing. FlexSoC therefore reserves explicit analysis ownership for:

```text
analysis/cdc/   # clock-domain crossing analysis
analysis/rdc/   # reset-domain crossing analysis
```

These targets are **planned, not implemented yet**. The intended implementation
layer is structural/static analysis using Slang/Yosys plus FlexSoC Python rules,
with the methodology informed by Accellera CDC/RDC guidance.

They will sit in the flow as a separate closure axis:

```text
hierarchy / lint
      ↓
CDC + RDC                    [planned]
      ↓
functional regression
      ↓
formal proof
      ↓
synthesis / EQY / timing
```

CDC/RDC findings will not be folded into Verilator coverage percentages.

## 11. 📐 Multi-clock constraints

Generate the timing-constraint scaffold:

```bash
fx sdc_multi --force
```

A clock-domain change must trigger a constraint review. In a real project,
inspect at least:

- primary clocks and periods;
- asynchronous clock relationships;
- generated clocks, when present;
- reset behavior and recovery/removal assumptions;
- input/output delays when the IP boundary owns them;
- synchronizer/async-FIFO exceptions only when architecturally justified.

Constraints are authored design intent once customized; do not blindly overwrite
project-specific timing policy.

## 12. 🏗️ Synthesis and EQY equivalence

Run synthesis first:

```bash
fx syn --force
```

Then compare RTL against the mapped netlist:

```bash
fx equiv --force
```

EQY can be more expensive for multi-clock designs even when the RTL is small.
Async FIFOs, synchronizer state, and independently clocked state can create a
few difficult equivalence partitions.

FlexSoC therefore reports partition closure explicitly:

```text
proven / total / percent
failed
engine errors
timeouts
unknown
```

A timeout or incomplete partition is **not** silently converted to PASS, but it
also should not be confused with a proven RTL/netlist mismatch. The E2E flow can
continue into SDF/STA/power so the rest of implementation closure remains
visible while the difficult partition is investigated.

## 13. 📊 SDF, STA, and power

Run:

```bash
fx sdf sta power_estimate --force
```

Corner-oriented targets remain available:

```bash
fx sta_corners
fx power_estimate_corners
fx signoff_corners
```

A multi-clock timing review must be read per clock relationship and per
setup/hold mode; a global “timing passed” label is only useful after those
relationships are correctly constrained.

## 14. 🔄 Change propagation in a multi-clock IP

### Add or remove a clock/reset domain

```bash
fx reg doc --force             # if domain register ownership changed
fx regmap_py --force
fx top_from_core --force       # only while wrapper is generated
fx flist --force
fx lint_suite
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail
fx formal
fx sdc_multi --force
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
```

When CDC/RDC targets land, they belong in this propagation path immediately
after hierarchy/lint.

### Move a CSR block between domains

This affects more than HJSON naming. Recheck:

- generated register RTL/domain bindings;
- generated Python regmap domain objects;
- transaction/test timing;
- automatic CSR formal semantics;
- synchronization around HW/SW-visible state;
- SDC clock ownership;
- synthesis/EQY/timing closure.

### Change async FIFO or synchronizer implementation

Rerun functional regression, formal, synthesis, and EQY even if the external
interface did not change. When available, CDC analysis should become mandatory
for this class of edit.

For the complete project-wide matrix, see
[Project lifecycle and change propagation](project_lifecycle.md).

## 15. 🔄 Complete development flow

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
fx setup_tb setup_cocotb --force
fx regression
fx coverage_detail
fx formal

# CDC / RDC will be inserted here when implemented.
fx sdc_multi --force
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
fx metrics check --force
```

## 16. 🧪 E2E regression

Run the project suite with:

```bash
make test E2E_ROOT=work
```

or target pytest directly:

```bash
pytest -s tests/test_e2e_fx.py --e2e-root work
```

The multi-clock E2E should expose every closure stage independently. A partial
EQY result may retain the workspace for investigation, but it must not hide the
SDF/STA/power results that follow.
