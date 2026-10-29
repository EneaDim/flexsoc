# 🚀 FlexSoC quickstart

This is a **worked command sequence**, not a guarantee that a new checkout can run every EDA stage without toolchains, a PDK, and authored IP collateral. Start from the repository root and verify prerequisites before changing generated files. The narrative
of how a project evolves from design intent to qualified release is in
[Project lifecycle](project_lifecycle.md). The detailed step-by-step engineering
procedure is in [IP development guide](ip_development_guide.md). Exact syntax,
options, variables, and the complete target catalogue are in
[Command reference](command_reference.md).

## 1. Install

For the complete ASIC flow, use the immutable Docker toolchain image recorded by
the repository. A plain `uv sync` installs the Python package but does not install
Yosys, OpenSTA, OpenROAD, Verilator, Slang, formal solvers, and the rest of the
EDA stack.

From the repository root:

```bash
IMAGE_REF="$(bash -lc 'source docker/scripts/common.sh; validate_lock')"
docker pull "$IMAGE_REF"
docker run --rm -it \
  --pull=missing \
  --volume "$PWD:/workspace" \
  --workdir /workspace \
  --env PYTHONPATH=src \
  --env DEPS_MODE=system \
  "$IMAGE_REF" bash
```

Inside the container:

```bash
uv pip install --python "$VIRTUAL_ENV/bin/python" --no-deps --editable .
fx deps-doctor
fx doctor
fx commands
```

See the top-level [README](../README.md) for host-only development and
[Docker documentation](../docker/README.md) for image maintenance.

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

The commands below are identical for one or many clocks. The clock topology
changes generated CSR windows, RTL, model scenarios, SDC and CDC/RDC obligations;
it does not remove the specification, independent model-test, traceability or
RTL-regression gates.

## 3. Bootstrap specification and RTL

```bash
fx setup --force
fx spec
fx hjson --force
fx reg doc --force
fx rtl_stub --force
fx top_from_core --force
fx flist --force
```

The `--force` commands above are for a **new, disposable scaffold**; they can replace edited/generated content.
The scaffold is a starting point, not a complete specification or passing test.
After the commands, review and author the input files under the **active run root**
(`workspace/runs/<RUN_TOP>/<RUN_ID>/` by default):

```text
spec/customer.md                        customer requirements (CRS; authored)
spec/ip.md                              technical specification (TDS; scaffold then authored)
spec/requirements.yaml                 atomic engineering obligations
spec/testplan.yaml                     methods, RTL tests, properties and model_cases
csr/<top>.hjson                         canonical CSR/register specification
rtl/<top>_core.sv                       authored RTL behavior and interfaces
dv/functional/py/model/<top>_model.py   Python reference model (after fx model --setup)
dv/functional/py/model/scenarios.py     shared semantic scenario IDs
dv/functional/py/rtl/<top>_tests.py     authored RTL vector-generator source
dv/functional/py/model/<top>_model_tests.py  independent expected-value assertions
dv/formal/properties/                  authored assertions and covers
```

`fx spec` now writes **starter examples** for all four files: `customer.md`,
`ip.md`, `requirements.yaml` and `testplan.yaml`, with traceable CRS/TDS links,
`spec_refs` and `model_cases`. The example is **not a customer-approved contract**,
and mapped scenarios are **not executed evidence**. Edit and approve each
source before qualification; do not use `--force` to overwrite authored work.
The single authoritative, fully numbered command sequence (including GLS,
activity power, routed sign-off and release) is in the top-level
[README — Complete IP flow](../README.md#complete-ip-flow--all-commands-in-execution-order).
See [IP traceability](methodology/ip_traceability.md) for the contract details.

## 4. Design verification

Run verification in this order so structural problems are removed before the
more expensive behavioral gates and every clock-aware consumer sees the same
timing contract.

### 4.1 Linting

```bash
fx lint
```

### 4.2 Author the timing contract

Initialize the SDC once after RTL/lint are structurally clean:

```bash
fx sdc --setup --force
```

Review and edit `constraints/<TOP>.sdc`. It is the timing source of truth for
functional clock generation, CDC/RDC clock relationships, synthesis I/O drive/load
setup, implementation, and STA. The scaffold includes clocks, clock quality, I/O
timing, drive/load, and commented sections for false paths and multicycle paths.

### 4.3 CDC/RDC

```bash
fx cdc_rdc --setup --force
fx cdc_rdc
```

Canonical CDC/RDC evidence is intentionally small: `dv/cdc_rdc/design.json`
(raw structure), `summary.json` (machine-readable findings/obligations),
`cdc_rdc.rpt` (human report), plus the extraction script/log. Clock relationships
come from `<TOP>.sdc`; reset ownership and polarity remain bootstrap metadata.

### 4.4 Model, specification traceability and RTL regression

First create the editable model/test sources if not already present:

```bash
fx model --setup
```

**Authoring gate (required for real verification):** review the Python model,
`scenarios.py`, the vector generator, and independent model assertions. Author
`spec/customer.md` with `CRS-nnn` headings and link `TDS-nnn` sections in
`spec/ip.md` using `Customer refs:`. Map every technical requirement via
`spec_refs`, and map verification scenarios and independent `model_cases` in
`spec/testplan.yaml`. The initial `fx spec` files are deliberately incomplete for
this extended traceability contract.

Once these sources have been authored, run the *independent* checks:

```bash
fx trace --summary           # Read-only: validate CRS/TDS/requirement/testplan links
fx mtest --setup             # Create missing model-test sources without overwriting authored ones
fx mtest                     # Execute independent Python assertions (NOT RTL simulation)
fx mtest --check             # Require current PASS evidence without rerunning pytest
```

`fx mtest` is not a synonym for `fx tests_gen`: it executes Python assertions
against independently specified expected behavior. Generated assertions start
with `pytest.skip`, so an untouched scaffold cannot establish model PASS.
`fx trace` establishes mappings, not executed-test PASS; if customer traceability
has not been authored, it reports `NOT_CONFIGURED` and `fx mtest` cannot proceed.

Generate RTL vectors and run the separate simulation/regression gate:

```bash
fx tests_gen
fx tests_gen --check         # Detect edited/stale generated vectors
fx tb cocotb --setup
fx regression
fx coverage --summary
```

Before `fx tests_gen`, check that the vector generator exists at
`dv/functional/py/rtl/<TOP>_tests.py`. It is **not** the independent model-test
file, which remains under `py/model/`. If a prior scaffold has its generator
under `py/model/`, follow the [non-destructive migration steps](#existing-run-missing-rtl-vector-generator)
below instead of retrying regression or silently overwriting authored files.

Once you have authored work, use `fx regmap_py --force` for CSR-only updates
instead of regenerating the whole editable model workspace.

Both functional backends derive clock period, waveform, source latency, and clock
uncertainty from `<TOP>.sdc`. Clock uncertainty becomes bounded uniform jitter
with 1 ps resolution; the run `SEED` makes the SV and cocotb stimulus reproducible.
The waveform still owns duty cycle, and `set_clock_transition` remains an STA
electrical constraint rather than an analog slew model.

Open a waveform when needed:

```bash
fx view
fx view_cocotb
```

### 4.5 Property formal

```bash
fx formal --setup --force
fx formal
```

This runs automatic CSR checks and authored BMC/prove/cover stages from existing
setup collateral.

### Existing run: missing RTL vector generator

A legacy scaffold from the 2026-10-25 source snapshot may have
`py/model/<TOP>_tests.py` but not `py/rtl/<TOP>_tests.py`. The code fix moves
future generator output to `py/rtl` and fixes its model imports. **Applying the
source fix does not rewrite an already completed `model.setup` stage**: when
FlexSoC prints `state=CLEAN reuse=...`, it is reusing the old manifest.

For the `my_ip`/`dev` example, first inspect without changing anything:

```bash
RUN=workspace/runs/my_ip/dev
find "$RUN/dv/functional/py" -maxdepth 3 -name '*tests.py' -print
```

After applying the scaffold source fix, one safe route for a **disposable, newly
generated** model workspace is to make a backup and explicitly regenerate the
model setup. This can overwrite authored model files, so **do not use this on
customized sources without first reviewing and preserving them**:

```bash
RUN=workspace/runs/my_ip/dev
cp -a "$RUN/dv/functional/py" "$RUN/dv/functional/py.before-scaffold-fix"
fx model --setup --force
test -f "$RUN/dv/functional/py/rtl/my_ip_tests.py"
```

If you have already edited your model, scenarios or tests, **do not use
`--force`** as a migration shortcut. Preserve authored files and migrate the
vector generator (including imports for the adjacent `py/model` directory)
with a reviewed change instead. Never delete the legacy copy before diffing it.

When the expected generator exists, return to the normal flow:

```bash
fx tests_gen &&
fx tests_gen --check &&
fx tb cocotb --setup &&
fx regression &&
fx coverage &&
fx coverage --summary
```

Do not interpret a `tests_gen` failure followed by `regression` and missing
coverage reports as three independent failures. Fix vector generation first.

### 4.6 How the evidence paths fit together

```mermaid
sequenceDiagram
    autonumber
    actor Engineer
    participant Spec as Authored specifications
    participant FX as fx CLI
    participant Model as Python model checks
    participant RTL as RTL DV / EDA
    participant Release as Qualification
    Engineer->>FX: fx spec (starter files)
    Engineer->>Spec: Author CRS, TDS, requirements, testplan
    Engineer->>FX: fx model --setup; author scenarios and independent checks
    FX->>Spec: fx trace validates source mappings
    FX->>Model: fx mtest runs independent assertions
    FX->>RTL: fx tests_gen; regression; coverage
    FX->>RTL: lint; CDC/RDC; formal; synthesis; sign-off
    FX->>Release: fx qualify (evaluate required current evidence)
    Release-->>Engineer: Qualification or missing/failed/stale obligations
```

This diagram shows the relationship between **independent** evidence classes;
it is not a guarantee that every target runs successfully on a new scaffold.
The result of model testing does not substitute for RTL regression or timing.

## 5. Select technology and synthesize

The authored SDC is technology independent and is not regenerated on a PDK switch.

```bash
fx pdk use sky130
fx syn --setup
fx syn
```

`syn --setup` consumes `constraints/<TOP>.sdc` and derives the small Yosys/ABC
`abc.constr` drive/load boundary required by synthesis.

## 6. Prepare RTL-to-netlist equivalence

The scaffold prepares EQY collateral but does not automatically run equivalence:

```bash
fx eqy --setup
```

**Setup is not a passing proof.** The automatic scaffold E2E flow stops after EQY setup because equivalence strategies are IP- and interface-specific. To run the prepared proof **explicitly**, after confirming the RTL, mapped netlist, tool dependencies, and EQY configuration are suitable:

```bash
fx eqy
```

EQY uses a solver portfolio selected by clock configuration:

```text
single clock: SAT → SMTBMC → PDR
N clocks:     PDR → SMTBMC
```

Inspect the real outcome; neither a generated configuration nor a launched run demonstrates equivalence PASS. See the [EQY reference](command_reference.md) and the [evidence guide](guides/reading-run-results.md) for provenance and result interpretation.

Inspect unresolved or failing partitions after an explicit EQY run:

```bash
fx eqy --summary
fx eqy --show
fx eqy --debug
```

## 7. Post-synthesis analysis

```bash
fx signoff --setup
fx sdf
fx sta
fx power-estimate
```

STA sources `constraints/<TOP>.sdc` directly and writes the canonical human and
machine-readable timing evidence to `signoff/<pdk>/sta/sta.rpt` and `summary.json`.
The report is QoR-first: scenario status, WNS/TNS, minimum period/Fmax, constraint
coverage, electrical checks, and detailed setup/hold paths without duplicating
the same information across many public reports.

Optional post-synthesis gate simulation:

```bash
fx compile_post_syn --force
fx sim --post-syn --force
```

## 8. OpenROAD implementation

```bash
fx pnr --setup --force
fx pnr --force
fx pnr_gui
```

Post-implementation sign-off resolves the final netlist and SPEF from the canonical
implementation branch:

```bash
fx signoff_post_impl --setup --force
fx sdf_post_impl
fx sta --post-impl
fx compile_post_impl --force
fx sim --post-impl --force
```

Use explicit `NETLIST`/`SPEF_FILE` overrides only for intentional exceptional
analysis, not for the normal routed flow.

## 9. Consolidated status

```bash
fx manifest
fx manifest_show
fx metrics
fx check
```

`fx metrics` writes the current normalized snapshot to
`meta/<pdk>/metrics.json`. `fx check` reads that saved snapshot and renders the
colored lifecycle dashboard without recollecting metrics.

## 10. Common update loops

The rule is always the same: edit the owning authored source, regenerate only the
collateral whose inputs changed, then rerun downstream gates. Run targets do not
regenerate setup implicitly.

### 10.1 Add or change a CSR

```bash
# edit HJSON
fx reg doc regmap_py tests_gen --force
fx flist --force
fx lint
fx cdc_rdc --setup --force
fx cdc_rdc
fx tb cocotb --setup --force
fx regression
fx formal --csr --setup --force
fx formal --csr
fx syn --setup --force
fx syn
fx eqy --setup --force
# automatic scaffold E2E stops after EQY setup
```

### 10.2 Change RTL behavior

```bash
# edit RTL, model, tests, and properties together
fx flist --force
fx lint
fx cdc_rdc --setup --force
fx cdc_rdc
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx formal --prove --setup --force
fx formal --cover --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
# automatic scaffold E2E stops after EQY setup
```

### 10.3 Change RTL ports

```bash
# edit <top>_core.sv
fx top_from_core flist --force
fx lint
# review/update constraints/<TOP>.sdc if interface timing changed
fx cdc_rdc --setup --force
fx cdc_rdc
fx tb cocotb --setup --force
fx regression
fx formal --prove --setup --force
fx formal --cover --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
# automatic scaffold E2E stops after EQY setup
```

### 10.4 Change clock/reset architecture

Change bootstrap settings only when the domain/reset topology itself changes. Then
regenerate the SDC scaffold intentionally, reapply/review authored timing intent,
and regenerate every clock-derived setup.

The following is an example for three asynchronous domains. Replace the
names, periods and relationships with those of the actual design **before**
executing it:

```bash
fx settings N_CLOCKS=3 \
  'CLOCK_DOMAINS=cfg:cfg_clk_i:cfg_rst_ni:20:low,rx:rx_clk_i:rx_rst_ni:16:low,dsp:dsp_clk_i:dsp_rst_ni:30:low' \
  'CLOCK_RELATIONSHIPS=async:cfg:rx,async:cfg:dsp,async:rx:dsp'
fx top_from_core flist --force
fx lint
fx sdc --setup --force
# edit/review constraints/<TOP>.sdc before continuing
fx cdc_rdc --setup --force
fx cdc_rdc
fx tb cocotb --setup --force
fx regression
fx formal --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
# automatic scaffold E2E stops after EQY setup
fx signoff --setup --force
fx sdf
fx sta
fx power-estimate
```

If only timing values change (waveform, latency, uncertainty, I/O delays, drive/load,
exceptions), edit `constraints/<TOP>.sdc` directly; do not change a parallel clock
timing setting. Regenerate the affected TB/synthesis/sign-off setup and rerun CDC/RDC
when clock relationships changed.

## 11. Existing reusable IP

```bash
fx setup --force
fx ip_load --force
fx flist --force
fx lint
# the package-owned constraints/<TOP>.sdc remains authored timing intent
fx cdc_rdc --setup --force
fx cdc_rdc
fx tests_gen --force
fx tb cocotb --setup --force
fx regression
fx formal --setup --force
fx formal
fx syn --setup --force
fx syn
fx eqy --setup --force
# automatic scaffold E2E stops after EQY setup
```

Preserve the IP-owned HJSON, RTL, model, tests, and properties. Regenerate only
the explicitly derived collateral.

## 12. Complete IP flow — ordered checklist

No single `fx` command creates and qualifies an IP without authoring. After
completing [bootstrap](#3-bootstrap-specification-and-rtl) and the manual
specification, model, test and SDC work above, execute the required gates in
order. Run each group only after the previous group has actually passed.

**Structural, model and functional checks:**

```bash
fx lint &&
fx cdc_rdc --setup &&
fx cdc_rdc &&
fx trace --summary &&
fx mtest --setup &&
fx mtest &&
fx mtest --check &&
fx tests_gen &&
fx tests_gen --check &&
fx tb cocotb --setup &&
fx regression &&
fx coverage &&
fx coverage --summary
```

**Formal and synthesis:**

```bash
fx formal --setup &&
fx formal &&
fx syn --setup &&
fx syn &&
fx eqy --setup
```

`fx eqy --setup` is not a proof. After checking the profile, execute the
required equivalence proof with `fx eqy`.

**Post-synthesis and physical closure (when required by the target level):**

```bash
fx signoff --setup &&
fx sdf &&
fx sta &&
fx power-estimate &&
fx pnr --setup &&
fx pnr &&
fx physical_signoff &&
fx signoff_post_impl --setup &&
fx sdf_post_impl &&
fx sta --post-impl
```

**Inspect and release only after the required evidence is current and passing:**

```bash
fx manifest &&
fx metrics &&
fx check &&
fx qualify
```

Run `fx ip_save` only after successful qualification. Additional gate-level
simulations, power analyses and sign-off tasks depend on the selected
qualification level; consult the [ASIC flow guide](flexsoc_asic_flow_guide.md)
instead of assuming these commands alone establish every possible release.

### Verify the result before calling the flow complete

1. Check the exit status of each required command. A completed setup step is not a PASS for its execution stage.
2. Read the generated tool logs and summaries; keep failures and skipped checks visible.
3. Confirm that each result belongs to the active RTL, constraints, run configuration and tool invocation.
4. Use `fx check` to inspect lifecycle status, then review the qualification evidence required by the [Digital IP Contract](digital_ip_contract.md). Do not equate a successful command with release qualification.
5. For missing or stale results, follow [Reading run results](guides/reading-run-results.md).

## 13. Project regression

```bash
uv run pytest -q tests/regression/test_api.py
uv run pytest -s tests/e2e/test_fx.py --e2e-mode full --e2e-root ~/flexsoc-e2e
```

Formal-only iteration:

```bash
uv run pytest -s tests/e2e/test_fx.py --e2e-mode formal --e2e-root ~/flexsoc-e2e
```

Stop before PnR:

```bash
uv run pytest -s tests/e2e/test_fx.py --e2e-mode pre-pnr --e2e-root ~/flexsoc-e2e
```
