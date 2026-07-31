# 🔄 Project lifecycle and change propagation

FlexSoC is designed around the way a **real digital-design project changes**.
The project is not just RTL: it is a dependency graph connecting register
specifications, generated register logic, interfaces, behavioral models, tests,
formal properties, filelists, synthesis, timing, power, and eventually physical
implementation.

> 🔑 **Core rule:** edit the real source of truth, regenerate the smallest
> derived boundary, then rerun every closure stage whose assumptions changed.

The goal is not to run every command after every edit. The goal is to know
**exactly what became stale**.

## 1. 🧬 Project dependency graph

```text
register specification (HJSON)
        │
        ├── register RTL + docs
        ├── generated Python CSR/regmap API
        ├── automatic CSR formal properties
        └── software-visible metadata
                 │
                 ▼
RTL core / wrapper / generated register RTL
        │
        ├── Slang elaboration → rtl_common.f + rtl_ip.f
        │       ├── lint
        │       ├── RTL simulation
        │       ├── cocotb simulation
        │       ├── functional coverage
        │       ├── formal properties
        │       └── synthesis
        │
        └── interface + clock/reset architecture
                ├── generated testbench wiring
                ├── timing constraints
                └── CDC/RDC structural analysis       [planned]

behavioral model + test catalogue
        │
        └── tests_gen
              ├── config.regs
              ├── data_in.vec
              └── data_out.vec
                    ├── SV backend
                    └── cocotb backend

synthesized mapped netlist
        │
        ├── EQY RTL ↔ synthesis equivalence
        ├── SDF
        ├── post-synthesis simulation
        ├── STA
        ├── power estimate
        └── PnR / post-layout closure
```

This graph is the practical meaning of orchestration: the dependency edges
should live in repeatable targets, not in somebody's shell history.

## 2. ✍️ Authored source vs generated collateral

Before deciding what to regenerate, classify the file.

### ✍️ Authored source

Typical authored intent includes:

- HJSON register specifications;
- RTL core logic;
- a wrapper once it contains deliberate integration/adaptation logic;
- `<top>_model.py`;
- `<top>_tests.py`;
- authored SystemVerilog assertions/covers;
- intentional clock/reset/constraint policy;
- IP-specific integration code.

### ⚙️ Generated collateral

Typical derived files include:

- register RTL and register documentation;
- `<top>_regmap.py`;
- automatic CSR formal collateral;
- `rtl_common.f` / `rtl_ip.f`;
- materialized vector tests;
- generated SV/cocotb infrastructure;
- SBY/EQY configurations;
- synthesis/signoff scripts;
- logs, coverage databases, proof workdirs, and metrics.

This distinction determines whether `--force` is safe. `fx regmap_py --force`
should overwrite the generated regmap helper; `fx setup_model --force` is a
bootstrap/reset operation and should not be used casually once model/tests have
become authored project code.

## 3. 🏁 Normal IP lifecycle

A healthy IP normally progresses through these closure layers:

```text
specification
   ↓
RTL + hierarchy
   ↓
lint / static inspection
   ↓
functional DV
   ├── SV regression
   ├── cocotb regression
   └── code/toggle/branch/... coverage
   ↓
formal DV
   ├── CSR BMC / PROVE / COVER
   └── authored-property BMC / PROVE / COVER
   ↓
synthesis
   ↓
RTL ↔ synthesis equivalence
   ↓
implementation/signoff
   ├── SDF / post-synthesis simulation
   ├── STA
   ├── power estimate
   └── PnR / post-layout closure
```

For multi-clock designs, **CDC/RDC analysis is the next structural closure axis**
to add beside lint and formal. It is intentionally not represented as functional
coverage.

A compact single-clock bootstrap is:

```bash
fx settings TOP=test RUN_TOP=test RUN_ID=dev HOST=uart CLOCK_MODE=single
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
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
fx metrics check --force
```

## 4. 🧾 When the register map changes

This is the most important propagation example because one HJSON edit crosses
hardware, model, tests, formal, and implementation boundaries.

Suppose a field/register is added, removed, renamed, resized, moved, or changes
access/reset semantics.

### What becomes stale

| Layer | Why |
| --- | --- |
| Register RTL/docs | They are direct HJSON products. |
| `<top>_regmap.py` | Python CSR names, fields, masks, offsets, resets changed. |
| CSR-oriented tests | Register serialization or expected semantics may change. |
| Automatic CSR formal | Assertions/covers are derived from register semantics. |
| RTL filelists | Generated register RTL can change hierarchy/sources. |
| Synthesis + EQY | Hardware implementation may have changed. |
| STA/power/SDF | Netlist/timing can change after synthesis. |

### Safe regeneration path

```bash
# HJSON-derived hardware + documentation
fx reg doc --force

# HJSON-derived model API; preserve authored model/tests
fx regmap_py --force

# Update <top>_model.py / <top>_tests.py only if semantics changed.
# Never duplicate offsets/field positions manually.

fx tests_gen --force
fx flist --force
fx lint_suite
fx regression
fx coverage_detail

# Regenerate/rerun register semantics and authored properties.
fx formal

# Re-close implementation if the hardware representation changed.
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
fx metrics check --force
```

A documentation-only HJSON edit does not necessarily require the full tail; a
field-width/access/reset change normally does.

## 5. 🔌 When IP inputs/outputs change

A port change is not just an RTL edit. It changes every layer that names or wires
the interface.

### What to inspect

- Is `<top>.sv` still generated, or has it become authored integration logic?
- Does the behavioral model accept/return the same transaction shape?
- Do test scenarios drive/check the new interface?
- Do generated SV/cocotb testbenches need new wiring?
- Do authored formal properties or bind points reference renamed signals?
- Did the clock/reset interface change?
- Do SDC constraints need new clocks, generated clocks, or I/O delays?

### Propagation path

```bash
# Edit rtl/<top>_core.sv.
fx top_from_core --force      # only if the wrapper is still generated

# Update authored model/tests/properties as required.
fx tests_gen --force
fx setup_tb setup_cocotb --force
fx flist --force
fx lint_suite
fx regression
fx coverage_detail
fx formal

fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
```

Once the wrapper contains deliberate custom glue, stop regenerating it and edit
it as authored source.

## 6. 🧠 When behavior changes but interfaces do not

Typical examples are an arithmetic fix, FSM change, pipeline latency change, or
new protocol corner case.

Update together:

```text
RTL implementation
↕
behavioral model
↕
test catalogue
↕
authored assertions/covers
```

Then run the smallest relevant slice:

```bash
fx flist --force          # only if hierarchy/source dependencies changed
fx lint_suite
fx tests_gen --force      # if scenarios/expectations changed
fx regression
fx coverage_detail
fx formal
```

If the RTL changed, synthesis/equivalence is stale even when all functional tests
still pass:

```bash
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
```

This distinction matters: regression proves the tested behaviors still work;
EQY proves synthesis preserved the RTL representation.

## 7. ⏱️ When latency/timing behavior changes

A pipeline stage may be added without changing ports or CSR layout. In that case:

- update the model if architectural latency is part of its contract;
- update test timing/event policy in `<top>_tests.py`;
- regenerate vectors;
- rerun both functional backends;
- revisit timing constraints only if the clock/interface assumptions changed;
- rerun synthesis, EQY, STA, and power because the implementation changed.

```bash
fx tests_gen --force
fx regression
fx formal
fx syn --force
fx equiv --force
fx sta power_estimate --force
```

## 8. 🧱 When hierarchy/package dependencies change

`fx flist` uses Slang as the hierarchy/dependency source of truth and regenerates:

```text
rtl/rtl_common.f
rtl/rtl_ip.f
```

After adding/removing an instantiated module, package, interface, include root,
or changing hierarchy:

```bash
fx flist --force
fx lint_suite
```

Every consumer of those filelists can now be stale: simulation, formal,
synthesis, and therefore EQY/signoff. Rerun whichever layers are relevant to the
change.

## 9. 🌐 When a clock/reset domain changes

This is the highest-impact IP-local change because it changes architecture, DV,
formal assumptions, and timing together.

Examples:

- add a second asynchronous clock;
- move a register block to another domain;
- add an async FIFO/synchronizer;
- change reset polarity or reset-domain ownership;
- introduce/remove a generated clock.

For a multi-clock run:

```bash
fx settings CLOCK_MODE=multi
fx reg doc --force
fx regmap_py --force
fx top_from_core --force      # only if still generated
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

Planned CDC/RDC targets will sit naturally after hierarchy/static checks and
before declaring multi-clock closure complete:

```text
lint / hierarchy
   ↓
CDC + RDC              [planned]
   ↓
functional + formal
   ↓
synthesis + EQY + timing
```

EQY may also become more expensive around async FIFO/CDC state. A partial EQY
percentage is therefore reported separately from a true counterexample or
engine error; it must not be confused with functional code coverage.

## 10. 🧪 When only tests change

If RTL/model/register structure did not change and you are only adding a new
scenario:

```bash
edit <top>_tests.py
fx tests_gen --force
fx regression
fx coverage_detail
```

No synthesis or EQY rerun is required because the design representation did not
change. The new regression may, however, expose an RTL/model bug that starts a
larger propagation cycle.

## 11. 🧾 When only authored formal properties change

If the DUT did not change but assertions/covers did:

```bash
fx formal
fx metrics check --force
```

Functional regression, synthesis, and EQY remain valid unless the property edit
also required an RTL change.

## 12. 🏗️ When constraints change

An SDC change does not invalidate RTL functional coverage, but it does invalidate
timing/signoff assumptions.

Typical rerun:

```bash
fx setup_sdc --force          # or fx sdc_multi --force
fx setup_signoff --force
fx sdf sta power_estimate --force
```

If the constraints affect synthesis optimization in the selected flow, rerun:

```bash
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
```

## 13. 🛠️ When the toolchain changes

A new Verilator/Yosys/SBY/EQY/OpenSTA version can change warnings, coverage
instrumentation, synthesis mapping, solver behavior, or timing interpretation
without any source edit.

Treat a meaningful tool upgrade as a **requalification event**:

```bash
fx doctor
fx lint_suite
fx regression
fx coverage_detail
fx formal
fx syn --force
fx equiv --force
fx sdf sta power_estimate --force
fx manifest metrics check --force
```

The manifest records the run/tool identity so results can be compared with the
previous qualified run.

## 14. ♻️ From developing an IP to reusing it

A validated IP becomes reusable source under:

```text
hw/ips/<top>/
```

The reusable source tree can then be:

- loaded standalone with `fx ip_load` for regression/requalification;
- staged unchanged below another `RUN_TOP`;
- integrated into a SoC whose top-level RTL, software, constraints, and signoff
  assumptions belong to the SoC run.

The IP keeps ownership of its internal implementation/model/tests. The SoC owns
integration-level intent.

## 15. 📋 Change-impact matrix

Use this as the fast project-engineering checklist.

| Change | Reg collateral | Model/tests | TB | flist/lint | Functional | Formal | Syn | EQY | SDF/STA/power |
| --- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| HJSON field/access/reset | ✅ | inspect | — | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Functional port | — | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| RTL behavior | — | ✅ | maybe | maybe | ✅ | ✅ | ✅ | ✅ | ✅ |
| New test only | — | ✅ | — | — | ✅ | — | — | — | — |
| Formal property only | — | — | — | — | — | ✅ | — | — | — |
| Hierarchy/package | — | maybe | maybe | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Clock/reset domain | maybe | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |
| Timing constraint only | — | — | — | — | — | — | maybe | maybe | ✅ |
| Toolchain upgrade | — | — | — | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

`inspect` and `maybe` are deliberate: not every structural edit changes
behavior, but the engineer must evaluate the dependency instead of assuming it
is still valid.

## 16. 🎯 Practical rule

When something changes, ask in this order:

1. **What is the authored source of truth?**
2. **Which generated files directly depend on it?**
3. **Which verification representations became stale?**
4. **Did the hardware/netlist change?** If yes, synthesis and EQY are stale.
5. **Did clocks/constraints/netlist change?** If yes, signoff is stale.
6. **Can I regenerate only that boundary without overwriting authored work?**

That is the project lifecycle FlexSoC is trying to make explicit.
