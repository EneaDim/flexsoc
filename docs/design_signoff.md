# ✅ Design sign-off

FlexSoC keeps sign-off technology-aware: the **flow name comes first**, and the
selected **PDK is a local subdirectory** only where the result depends on that
technology.

This lets one logical RTL/DV run carry multiple independent implementations
without duplicating the PDK-independent verification tree.

## 1. 🧭 Sign-off model

```text
Implementation / sign-off
├── syn/<pdk>/
├── signoff/
│   ├── equivalence/<pdk>/
│   ├── sta/<pdk>/
│   ├── power/<pdk>/
│   └── sdf/<pdk>/
├── dv/functional/sim/
│   ├── post_syn/<pdk>/
│   └── post_pnr/<pdk>/
└── pnr_openroad/<pdk>/
```

For example:

```text
syn/
├── ihp-sg13g2/
└── sky130/

signoff/equivalence/
├── ihp-sg13g2/
└── sky130/
```

There is deliberately **no `tech/` umbrella directory**.

## 2. 🧩 Select the implementation technology

Persistent selection:

```bash
fx pdk use ihp-sg13g2
fx settings
```

or one command only:

```bash
fx syn --force --set PDK=sky130
```

A PDK switch without an explicit `PDK_ROOT` resolves the managed installation
for the newly selected PDK. A stale absolute root from the previous technology
must never be reused.

`fx settings` shows the selected PDK and the derived implementation locations.

## 3. 🏗️ Synthesis

```bash
fx syn --force
```

With `PDK=sky130`:

```text
syn/sky130/
└── <top>_synth.v
```

With `PDK=ihp-sg13g2`:

```text
syn/ihp-sg13g2/
└── <top>_synth.v
```

The two implementations coexist. Running one must not overwrite the other.

## 4. 🔁 Equivalence checking

Equivalence is classified as **design sign-off** in FlexSoC. It is implemented
by `src/flexsoc/backend/setup_signoff.py`, not `setup_formal.py`.

Generate only the EQY configuration:

```bash
fx setup_eqy --force
```

Run equivalence:

```bash
fx eqy --force
```

The active PDK selects both the synthesized netlist and the destination:

```text
signoff/equivalence/<pdk>/rtl_vs_syn/
├── <top>_rtl_vs_syn.eqy
├── <top>_rtl_vs_syn/
│   ├── partition.list
│   └── strategies/...
└── optional formal_pdk.v
```

EQY deliberately normalizes **gold and gate through the same Yosys script**:

```text
hierarchy -check -top <top>
proc
prep -top <top> -flatten
memory -nomap
async2sync
```

This keeps asynchronous-reset and memory semantics aligned before matching. The gate side
prefers the functional standard-cell Verilog distributed **with the selected PDK**. Ciel/Open-PDKs
installs these models under `libs.ref/<stdcell>/verilog`, and IHP SG13G2 exposes the same
library-local `verilog` view. `fx pdk info <pdk>` reports whether FlexSoC discovered it.

For SKY130, `fx pdk fetch sky130` also installs the pinned `formal_pdk_proc.py` adapter from
the official YosysHQ/EQY SKY130 example under `.flexsoc/pdks/.flexsoc-tools/sky130/`. The
adapter rewrites SKY130 UDP and power primitives into Yosys-compatible functional models.
Liberty is used only as an explicit fallback when that adapter is unavailable; it remains the
canonical view for synthesis/STA, not the preferred functional proof model.

Single-clock strategy order is intentionally small and fast: Yosys SAT first, then ABC/PDR,
then bounded SMTBMC/Bitwuzla. A later strategy runs only when the previous one is inconclusive.

### 4.1 Interpret EQY closure

EQY is partition based. FlexSoC disables EQY's default all-name matching and
explicitly matches only the top-level ports discovered from the synthesized
netlist. Internal synthesis names remain available for debug but are not part of
the sign-off contract. Vector ports are intentionally left unjoined so EQY can
partition their bits into small proof cones. This keeps solver runtime bounded
without reopening synthesis-internal match points.

Keep these states distinct:

- `PASS` — partition proven equivalent;
- `FAIL` — concrete non-equivalence/counterexample;
- `ERROR` — tool/engine failure;
- `TIMEOUT` — bounded strategy exhausted its wall-clock budget;
- `UNKNOWN` — incomplete closure.

`248/249 + 1 FAIL` is a different engineering result from `248/249 + 1
TIMEOUT`.

### 4.2 Debug EQY

Use one debugger command for closure, counterexample explanation, and diagnosis:

```bash
fx eqy_debug
fx eqy_debug [partition]
```

For a concrete FAIL the command selects the strategy that owns the real trace, reports
basecase/induction and the first semantic gold/gate divergence, then follows only that
partition through reset and synthesis-boundary probes. Diagnostic runs use EQY setup mode
to regenerate matching/partitions without proving the full design, then execute only the
generated Make target for the selected partition. Results are cached below
`signoff/equivalence/<pdk>/rtl_vs_syn/diagnostics/` and never replace the primary sign-off
result.

Waveform and raw files are options of the same command:

```bash
fx eqy_debug --wave [partition]
fx eqy_debug --wave [partition] induction
fx eqy_debug --files [partition]
```

The current single-clock defaults are `clk_i`, active-low `rst_ni`, and one reset cycle;
they can be overridden with `EQY_CLOCK`, `EQY_RESET`, `EQY_RESET_ACTIVE`, and
`EQY_RESET_CYCLES`. The reset replay first makes hierarchy instances unique before
Yosys writeback, so the diagnostic remains independent of the selected standard-cell
library.

Interpret the probes narrowly: if the original FAIL disappears after reset initialization,
investigate pre-reset/state correspondence. If it survives, the same selected partition is
checked at generic synthesis and immediately after `dfflibmap`; this distinguishes frontend /
generic synthesis, sequential mapping, and later ABC/final mapping. The debugger is
diagnostic; it never recomputes design closure or turns a partial result into sign-off closure.

## 5. 🔬 Cross-PDK equivalence diagnosis

Because every implementation is retained side-by-side, the same RTL can be
mapped and checked with multiple PDKs without manual copying:

```bash
fx pdk use ihp-sg13g2
fx syn --force
fx eqy --force
fx eqy_debug

fx pdk use sky130
fx syn --force
fx eqy --force
fx eqy_debug
```

Interpretation:

```text
same partition fails on both PDKs
    → inspect frontend/synthesis normalization, reset/X semantics, RTL cone

failure follows only one PDK
    → inspect technology mapping, Liberty semantics, sequential-cell models
```

This is a diagnostic comparison, not a waiver mechanism.

## 6. 🎞️ Post-synthesis gate-level simulation

Functional RTL simulation remains PDK-independent. Gate-level simulation is
scoped by PDK because it consumes mapped netlists and cell models.

```bash
fx sim_post_syn
```

Default waveform format is FST:

```text
dv/functional/sim/post_syn/<pdk>/<testbench>.fst
```

Use VCD explicitly when needed:

```bash
fx sim_post_syn --set WAVE_FORMAT=vcd
```

Timed GLS uses Icarus and enables the generated SDF hooks only in the gate-level
profile; Verilator RTL/cocotb runs never parse `$sdf_annotate`.

## 7. 🧱 Place and route

```bash
fx pnr --force
```

Artifacts live under:

```text
pnr_openroad/<pdk>/
```

The PDK name is local to PnR; the rest of the run hierarchy remains unchanged.

## 8. ⏱️ SDF and STA

Generate/run sign-off scripts:

```bash
fx setup_signoff --force
fx sdf --force
fx sta --force
```

Artifacts are split by function and then PDK:

```text
signoff/
├── sdf/<pdk>/
└── sta/<pdk>/
```

The SDC/clock intent is stored separately under the logical run constraints and
is reused by the selected technology implementation.

## 9. ⚡ Power

```bash
fx power_estimate --force
```

Results live under:

```text
signoff/power/<pdk>/
```

Power estimation and STA are implementation results; they must never be merged
across PDKs in one artifact directory.

## 10. 🎞️ Post-PnR simulation

```bash
fx sdf_post_pnr
fx sim_post_pnr
```

The corresponding waveform lives under:

```text
dv/functional/sim/post_pnr/<pdk>/
```

If a valid SDF is unavailable, a zero-delay gate-level run may still be useful,
but it must not be reported as timing-backannotated closure.

## 11. 📊 Metrics and manifest

Technology-aware metadata is also PDK scoped:

```text
meta/<pdk>/
├── metrics.json
└── manifest.json
```

Therefore:

```bash
fx metrics
fx manifest
fx check
```

always describe the PDK selected for that invocation while reusing the shared
PDK-independent lint/regression/property-formal results.
