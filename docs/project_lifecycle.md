# 🔄 Project lifecycle and change propagation

FlexSoC is built around one practical problem: a digital design is a network of
artifacts, not a single RTL directory.

During development, one source change can invalidate several representations of
the design. FlexSoC makes those dependencies explicit so derived files can be
regenerated deliberately while authored files remain under the designer's
control.

> 🔑 **Core idea:** change the source of truth once, regenerate the smallest
> derived boundary, then rerun only the checks that depend on that boundary.

## 1. 🧬 The project dependency chain

A typical IP contains several layers:

```text
register specification (HJSON)
        │
        ├── register RTL
        ├── register documentation
        ├── model-side CSR API
        └── software-visible collateral

RTL source / generated register RTL
        │
        └── Slang hierarchy elaboration
                ├── rtl_common.f
                └── rtl_ip.f
                        │
                        ├── lint
                        ├── SystemVerilog simulation
                        ├── cocotb simulation
                        └── synthesis

behavioral model + test catalogue
        │
        └── vector generation
                ├── config.regs
                ├── data_in.vec
                └── data_out.vec
                        │
                        ├── SV testbench
                        └── cocotb testbench

constraints + synthesized design
        │
        ├── SDF
        ├── STA
        ├── power
        └── PnR-oriented flow
```

The main benefit of FlexSoC is that these edges are encoded in repeatable
commands instead of being implicit knowledge in the designer's shell history.

## 2. ✍️ Authored source versus derived collateral

The safest way to use the flow is to classify every file as one of two things.

### ✍️ Authored source

Files whose design intent belongs to the engineer, for example:

- an edited HJSON register specification;
- the RTL core;
- a deliberately custom top wrapper;
- `<top>_model.py`;
- `<top>_tests.py`;
- IP-specific constraints or integration code.

### ⚙️ Derived collateral

Files that should be reproducible from source intent, for example:

- register RTL generated from HJSON;
- register documentation;
- `<top>_regmap.py`;
- `rtl_common.f` and `rtl_ip.f` generated from hierarchy elaboration;
- generated vector-test directories;
- generated SV/cocotb infrastructure;
- synthesis/signoff scripts and logs.

This distinction controls when `--force` is safe. For example,
`fx regmap_py --force` is expected to overwrite a generated CSR helper, while
`fx setup_model --force` intentionally resets all three model scaffolds and is
therefore not the right command for a routine HJSON edit after behavioral code
has been customized.

## 3. 🆕 Starting a new IP

A normal single-clock start is:

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
fx setup_tb --force
fx setup_cocotb --force
fx sim_tests
fx cocotb_tests
```

At this point the project has explicit specifications, implementation, a
behavioral reference, vector tests, and two verification frontends.

Continue to implementation/signoff when required:

```bash
fx syn sdf sta power --force
```

## 4. 🧾 Change scenario: the register map changes

This is one of the most important examples because it crosses several file and
tool boundaries.

Suppose a field is added, removed, renamed, or changes width/access mode in:

```text
data/<top>.hjson
```

The safe propagation path is:

```bash
# 1. Regenerate hardware-visible and human-readable register collateral.
fx reg doc --force

# 2. Regenerate the model-side CSR API only.
fx regmap_py --force

# 3. Update authored RTL/model/test behavior if the semantic change requires it.
#    Do not duplicate offsets or field bit positions by hand.

# 4. Regenerate vectors from the test catalogue.
fx tests_gen --force

# 5. Re-elaborate the current RTL hierarchy.
fx flist --force

# 6. Recheck the relevant design layers.
fx lint_suite
fx sim_tests
fx cocotb_tests
```

If the register change affects implementation or timing, continue with:

```bash
fx syn sdf sta power --force
```

The important property is that `<top>_model.py` and `<top>_tests.py` are not
blindly overwritten by the register update. HJSON owns register structure;
`<top>_regmap.py` transports that structure into model/test code.

## 5. 🔌 Change scenario: a core port changes

If a generated IP core adds, removes, or renames a functional port:

```text
edit rtl/<top>_core.sv
        │
        ├── fx top_from_core --force   # only while wrapper is generated collateral
        ├── update <top>_model.py
        ├── update <top>_tests.py
        ├── fx flist --force
        ├── fx lint_suite
        ├── fx tests_gen --force
        ├── fx setup_tb --force
        ├── fx setup_cocotb --force
        ├── fx sim_tests
        └── fx cocotb_tests
```

Once a top wrapper contains deliberate custom adaptation or integration logic,
it becomes authored source. Stop regenerating it with `top_from_core`; that is
the same ownership rule used by existing IPs.

## 6. 🧠 Change scenario: only behavior or tests change

If RTL behavior changes but interfaces and registers do not:

```text
edit RTL
edit <top>_model.py
edit/add scenarios in <top>_tests.py
```

Then the short loop is usually:

```bash
fx flist --force          # if hierarchy/source dependencies changed
fx lint_suite
fx tests_gen --force
fx sim_tests
fx cocotb_tests
```

If only a new scenario is added and no RTL/hierarchy changed, even `flist` and
lint may be unnecessary; regenerate the vectors and run the relevant tests.

This is the intended speed-up: rerun the dependency slice affected by the
change, not every generator in the repository.

## 7. 🧱 Change scenario: hierarchy changes

`fx flist` uses Slang as the source of truth for hierarchy reachability and
source ordering. Starting from the selected top, it resolves only reachable
modules/packages/interfaces and emits:

```text
rtl/rtl_common.f
rtl/rtl_ip.f
```

The common/IP split is retained so every downstream tool sees a stable project
boundary while Slang owns dependency order.

After adding a new instantiated RTL source, changing package dependencies, or
restructuring the hierarchy:

```bash
fx flist --force
fx lint_suite
```

Then rerun simulation or synthesis depending on the scope of the change.

## 8. ♻️ Change scenario: move from IP to larger system

A validated IP becomes reusable source under:

```text
hw/ips/<top>/
```

This source tree is intentionally separate from a run workspace. It can be:

- loaded standalone for regression with `fx ip_load`;
- staged into another `RUN_TOP` as a reusable block;
- integrated into a SoC whose top-level RTL, software, constraints, and signoff
  assumptions are owned by the SoC run.

The value of the existing-IP flow is therefore reuse. It prevents a mature
block's custom RTL/model/tests from being replaced just because the same tools
are used to verify it again in isolation or integrate it into a larger system.

## 9. ⏱️ Single-clock versus multi-clock propagation

The ownership model is intentionally the same:

```text
<top>_model.py
<top>_regmap.py
<top>_tests.py
```

The timing semantics differ:

- a simple single-clock transaction can use `model.LATENCY` to check at
  `drive_cycle + LATENCY`;
- tests can alternatively wait for a named output-valid signal;
- multi-clock verification uses domain-aware/event-driven completion rather
  than pretending unrelated clocks share one absolute cycle count.

This keeps the project structure stable while allowing the verification model
to match the hardware timing model.

## 10. 🔗 Tool boundaries managed by FlexSoC

The same project representation is consumed by different tools:

```text
HJSON/reggen     -> register RTL/docs/metadata
Slang            -> elaboration, hierarchy, filelist, optional lint/analysis
Verilator        -> lint and SV simulation
cocotb           -> Python-driven simulation
Yosys + Slang    -> synthesis
OpenSTA          -> timing/power-oriented analysis
OpenROAD         -> physical-design flow
```

The orchestration layer matters because each tool has different command-line,
filelist, include, macro, output, and logging conventions. FlexSoC normalizes
those interfaces around the run workspace rather than asking each project to
reimplement them.

## 11. 🎯 Practical rule: regenerate the smallest derived boundary

When something changes, ask:

1. **What authored source changed?**
2. **Which generated representation directly depends on it?**
3. **Which verification/implementation stages consume that representation?**

Examples:

| Change | Regenerate first | Then recheck |
| --- | --- | --- |
| HJSON field/layout | `reg doc`, `regmap_py` | vectors, lint, sim; synth/signoff if implementation changed |
| RTL logic only | usually no generator | lint, sim/cocotb, then synth/signoff as needed |
| RTL hierarchy/instantiation | `flist` | lint, sim, synth |
| Core ports | generated wrapper if still owned by flow; TB scaffolds | lint + verification |
| Behavioral model | `tests_gen` | sim + cocotb |
| Test catalogue only | `tests_gen` | selected/all vector tests |
| Timing constraints | SDC/signoff collateral | STA/power/PnR-related stages |
| Reusable IP update | reload/stage the IP in the consumer run | consumer hierarchy + verification/signoff |

That selective propagation is the central workflow FlexSoC is designed to
make repeatable.
