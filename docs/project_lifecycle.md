# 🔄 FlexSoC project lifecycle

This document describes **what happens during the life of a FlexSoC project** and why each stage exists. It is intentionally narrative: it explains the evolution of design intent, generated collateral, qualification evidence, technology branches, and reusable IP over time.

For exact commands and step-by-step execution, use the [IP development guide](ip_development_guide.md). For syntax and target options, use the [command reference](command_reference.md). For implementation details of FlexSoC itself, use [Architecture](architecture.md).

> **Lifecycle rule:** edit the owning source of truth, regenerate the smallest derived boundary that became stale, and rerun every downstream gate whose assumptions changed.
>
> FlexSoC treats a **digital IP contract** as the versioned combination of authored design intent, generated integration views, qualification evidence, and provenance needed to decide whether an IP is releasable. RTL alone is never the release artifact.

---

## 1. A project starts from design intent

A FlexSoC project begins before synthesis or simulation. The first stable assets are the design facts that other stages will consume:

- functional requirements and operating modes;
- software-visible CSR/register intent;
- RTL behavior and external interfaces;
- clock/reset domains and reset polarity;
- performance, power, area, test, and verification goals;
- a behavioral model, scenarios, and formal properties for the important invariants.

FlexSoC deliberately keeps authored intent separate from generated collateral. Generated files can be recreated; authored intent must remain reviewable and stable.

The main ownership model is:

| Design fact | Owner |
| --- | --- |
| CSR addresses, fields, access policy | HJSON |
| Core behavior and interfaces | authored RTL core |
| Control-register transport | `REG_ITF` (`tlul`, `reg_iface`, `axi_lite`) |
| Functional expectations | model + authored scenarios |
| Formal intent | authored/generated properties |
| Clock/reset topology | bootstrap domain/reset metadata |
| Timing intent | `constraints/<TOP>.sdc` |
| Technology mapping | selected PDK + synthesis configuration |
| Physical implementation | selected implementation branch |

One design fact should not be maintained in two independent places.

`REG_ITF` is the external control-interface intent. The register semantics remain independent of that transport. `tlul` generates a TL-UL register device, while `reg_iface` exposes the canonical register request/response transport directly. `axi_lite` exposes a flat AXI4-Lite subordinate interface while keeping the generated CSR transport as `reg_iface`; the protocol boundary is therefore `AXI4-Lite → reg_iface → generated register file`, never `AXI4-Lite → TL-UL`. FlexSoC uses PULP `axi_lite_to_reg` for that boundary rather than maintaining a custom protocol converter.

The AXI4-Lite path vendors only the required upstream subsets and pins their release revisions in the FlexSoC vendor manifests. Fetch them before filelist/lint/simulation generation:

```bash
fx fetch --set VENDOR=pulp_common_cells --force
fx fetch --set VENDOR=pulp_axi --force
fx fetch --set VENDOR=pulp_register_interface --force
```

The vendor utility writes lock files containing the resolved upstream commit. The same HJSON CSR source, generated register package/top, Python regmap, CSR formal collateral, `config.regs`, and functional scenarios are reused across `tlul`, `reg_iface`, and `axi_lite`; changing the external transport must not create a second register-map source of truth.


---

## 2. Bootstrap creates a workspace, not a finished design

`fx setup` creates the canonical run layout under:

```text
<WORKDIR>/runs/<RUN_TOP>/<RUN_ID>/
```

The run identity remains stable while the design moves through verification and multiple technology branches.

Early generators then materialize the first derived boundaries:

```text
HJSON
  ↓
register RTL / docs / Python regmap

RTL core
  ↓
generated top wrapper
  ↓
ordered filelists
```

`top_from_core` is the integration boundary around the authored core. It is where FlexSoC adds project-level infrastructure that should not be duplicated inside each IP. For reset handling, each clock domain receives an asynchronous-assert/synchronous-release reset path implemented directly with the reusable `prim_ff_2sync` primitive. A single-clock design therefore has one reset synchronizer; an N-clock design has one per reset/clock domain.

This keeps reset policy outside the core while avoiding wrapper-only RTL primitives.

---

## 3. Structural cleanliness comes before timing-aware verification

The first quality gate is elaboration and lint. At this point the goal is not functional correctness; it is to establish that the reachable hierarchy, widths, connections, and basic RTL structure are sound enough for every later tool to consume.

Once RTL/lint are structurally clean, the project establishes its **single authored timing contract**:

```text
constraints/<TOP>.sdc
```

Bootstrap clock metadata exists to initialize this file and to preserve reset-domain information that ordinary SDC does not express. After the SDC exists, clock timing and relationships are authored there rather than maintained in a parallel settings database.

The same SDC becomes the timing source of truth for:

- functional clock generation;
- CDC clock relationships;
- synthesis I/O environment and clock optimization inputs;
- OpenROAD implementation;
- pre-route and post-route STA;
- SDF/GLS timing context.

A technology switch does not create another authored SDC.

---

## 4. CDC/RDC turns clock/reset intent into structural obligations

After lint and SDC authoring, FlexSoC extracts a technology-independent structural graph and analyzes clock/reset crossings.

The lifecycle purpose is not merely to count crossings. It is to answer whether each crossing has an intentional implementation pattern and whether reset release is safe for each domain.

The public evidence is intentionally small:

```text
analysis/cdc_rdc/
├── design.json      raw structural evidence
├── summary.json     machine-readable analysis result
├── cdc_rdc.rpt      human-readable report
└── extract.ys       reproducible extraction setup

logs/analysis/cdc_rdc/
└── extract.log      raw tool log
```

Detailed classifications and obligations live in `summary.json` instead of being duplicated across many small JSON files.

A clock/reset topology change invalidates this analysis. A pure data-path RTL change may change the structural graph and therefore normally reruns it as well.

---

## 5. Functional and formal verification mature together

After the structural boundary is stable, the project develops two complementary verification views.

### Functional verification

The reference model and authored scenarios define expected behavior. Generated vectors and SV/cocotb harnesses are derived from them. Both simulation backends use the same timing contract for clock phase, duty cycle, source latency, and reproducible clock uncertainty/jitter.

Coverage answers **what was exercised**; simulation PASS answers **what matched the model for the exercised scenarios**. They are related evidence, not substitutes for one another.

### Formal verification

Generated CSR properties cover register semantics while authored properties capture design-specific invariants, safety requirements, and reachability goals.

Formal and simulation are intentionally independent. A simulation-heavy project can still miss a rare invariant violation; a proof can still omit a scenario that matters to end-to-end behavior.

The project is ready for synthesis only when the verification evidence is understood, not merely because individual commands returned zero.

---

## 6. Technology selection creates a branch, not a new project

The run remains one logical design while technology-dependent collateral is partitioned by PDK:

```text
syn/<pdk>/
impl/<pdk>/
signoff/<pdk>/
meta/<pdk>/
```

Shared RTL, DV, formal intent, the authored `<TOP>.sdc`, and common design intent remain technology independent.

Selecting SKY130 or IHP therefore changes mapping and sign-off views, not the design sources of truth.

---

## 7. Synthesis produces an implementation candidate

Synthesis consumes the ordered RTL hierarchy, selected Liberty view, and the authored timing/I/O environment.

For Yosys/ABC, FlexSoC derives the small `abc.constr` boundary from the SDC. Output load is converted from the Liberty capacitance unit to the femtofarad convention expected by ABC. If the SDC is edited, regenerated synthesis setup follows that authored value instead of a hardcoded backend default.

Synthesis PASS proves that the RTL can be mapped. It does **not** prove behavioral preservation or timing closure.

The next lifecycle gate is therefore equivalence.

---

## 8. Equivalence protects the RTL-to-netlist handoff

EQY checks that the mapped netlist still implements the authored RTL behavior under the selected formal view.

A synthesis optimization that improves timing or area but breaks equivalence is not an acceptable implementation. Conversely, an equivalence PASS does not prove that the implementation meets timing, power, or physical requirements.

The project now has a technology-mapped candidate that is ready for pre-layout sign-off.

---

## 9. Pre-layout sign-off establishes the baseline

Before physical implementation, FlexSoC evaluates the mapped design with ideal-clock/no-extracted-interconnect assumptions.

Typical evidence includes:

- SDF generation;
- pre-layout STA across selected Liberty corners;
- post-synthesis GLS;
- vectorless power estimate;
- activity-based power from GLS;
- timing/power fusion for aligned workloads.

Pre-layout hold and asynchronous recovery/removal observations are useful diagnostics, but clock-tree and routing effects do not yet exist. The project should still require clean setup timing and complete timing coverage; post-route closure is the final authority for routed hold/recovery/removal behavior.

The reset synchronizer is particularly important here: the external asynchronous reset should reach only the synchronizer stages, while the rest of the domain sees synchronous release.

---

## 10. Physical implementation turns logical timing into routed timing

OpenROAD/ORFS consumes the synthesized netlist and the same authored timing contract.

The physical branch adds information that does not exist pre-layout:

```text
floorplan
→ placement
→ clock-tree synthesis
→ routing
→ extracted parasitics
```

Clock-tree synthesis and routing can materially change hold/recovery/removal behavior. The post-route flow therefore does not merely repeat pre-layout STA; it evaluates a different physical model while preserving the same design intent.

Implementation evidence belongs under `impl/<pdk>/`; routed sign-off evidence belongs under `signoff/<pdk>/post_pnr/`.

---

## 11. Post-route sign-off is the closure gate

Post-PnR qualification uses the final implementation artifacts selected deterministically from the canonical ORFS branch.

The important distinction is:

```text
pre-layout
  mapped netlist + Liberty + authored SDC

post-route
  final netlist + SPEF + propagated clock + authored SDC
```

The authored timing contract does not change merely because the design was routed.

At this stage setup, hold, recovery/removal, electrical constraints, SDF/GLS behavior, activity power, and physical checks are evaluated as final implementation evidence. A violation here should not be hidden by relaxing generic flow policy; it must be traced to timing intent, reset architecture, implementation, or the design itself.

---

## 12. Evidence becomes progressively more compact

FlexSoC keeps detailed raw evidence without forcing users to read every raw report for normal review.

The intended hierarchy is:

```text
raw evidence
  tool logs / timing.rpt / power.rpt / waveforms / SPEF / SDF
        ↓
analysis JSON
  sta.json / power summary / fusion summary / CDC-RDC summary / GLS summaries
        ↓
metrics.json
  normalized cross-analysis snapshot
        ↓
fx check
  human-readable colored lifecycle dashboard
```

`fx metrics` **collects and writes** the current snapshot to:

```text
meta/<pdk>/metrics.json
```

It does not render the dashboard.

`fx check` is read-only with respect to that snapshot: it loads the saved `metrics.json` and presents the lifecycle in a structured terminal view. If the project changes after the snapshot was collected, run `fx metrics` again before using `fx check` to review the new state.

`manifest.json` answers a different question: **what exact environment/configuration produced this run?**

---

## 13. Failure is part of the lifecycle

A failed gate sends the project back to the owner of the violated assumption.

Examples:

```text
lint failure
  → RTL/interface/filelist owner

CDC/RDC failure
  → crossing/reset architecture or clock relationship owner

functional mismatch
  → RTL/model/scenario owner

formal counterexample
  → RTL/property/assumption owner

equivalence failure
  → synthesis/formal-view/RTL owner

setup failure
  → architecture/constraints/synthesis/implementation owner

post-route hold failure
  → implementation or real short-path/reset issue

power problem
  → workload/activity/architecture/implementation owner
```

The important rule is to fix the source, not the report. Generated RTL, netlists, reports, and implementation outputs are evidence or derived artifacts; they are not the normal place for permanent fixes.

---

## 14. Changes propagate by dependency, not by habit

Different edits invalidate different parts of the lifecycle.

The first contract kernel is deliberately small: provenance-bearing stages are declared once in the Python `STAGE_CONTRACTS` registry with only their semantic configuration and parent lineage. Existing provenance hashes the effective input files, generated artifacts, configuration, and parent fingerprints; a changed source or parent therefore makes dependent setup collateral stale without introducing a second graph format or database. Runtime evidence stages will reuse the same model as the contract graph expands.

The run-level `meta/design_intent.json` is the technology-independent identity snapshot for authored IP intent. Its `ip_intent_sha256` hashes only semantic IP settings plus canonical authored sources (CSR HJSON, authored RTL, functional model/scenarios, formal properties, and the authored SDC). Run identity, PDK selection, synthesis optimization, generated wrappers/register views, and generated Python regmaps are intentionally excluded. This keeps one IP intent stable across workspaces and technology branches while still changing when an owning source of truth changes.

### CSR-only change

Regenerate register collateral, test/regmap derivatives, and any wrapper/filelist boundary affected by new ports. Rerun structural, functional, formal, synthesis, equivalence, and downstream sign-off gates that consume the changed design.

### RTL behavior change

Preserve the authored model/properties as independent specifications where appropriate, update them only when the intended behavior changed, and rerun every verification and implementation gate downstream of RTL.

### Port change

Regenerate the top/filelist boundary and review `<TOP>.sdc` because I/O timing intent may need to change.

### Clock/reset topology change

Update bootstrap domain/reset metadata, regenerate the top reset-domain integration, intentionally regenerate/review `<TOP>.sdc`, then rerun every clock/reset-aware stage.

### Timing-only change

Edit `constraints/<TOP>.sdc` directly. Do not change a parallel clock-period setting. Regenerate only setup collateral that consumes the changed timing intent and rerun the relevant analyses.

### PDK change

Keep shared design/DV/SDC state. Rebuild the technology branch from synthesis onward.

---

## 15. Reusable IP is a qualified snapshot of design intent plus evidence

`ip_save` packages reusable authored/generated source collateral together with the selected technology branch and qualification evidence.

A package has one common design identity and may accumulate multiple PDK branches:

```text
<ip>/
├── constraints/<TOP>.sdc
├── data/
├── rtl/
├── dv/
├── analysis/cdc_rdc/
├── syn/
│   ├── sky130/
│   └── ihp-sg13g2/
├── impl/
│   ├── sky130/
│   └── ihp-sg13g2/
├── signoff/
│   ├── sky130/
│   └── ihp-sg13g2/
└── meta/
    ├── design_intent.json
    ├── sky130/
    └── ihp-sg13g2/
```

Saving one PDK branch must not destroy another. Loading an IP restores its authored timing contract rather than regenerating a generic SDC.

A loaded IP still needs to be qualified in its new workspace because generated setup scripts contain workspace- and technology-specific paths.

---

## 16. Release means traceable closure, not just a green command

A release candidate should answer all of these questions:

- Which authored sources define the behavior?
- Which `<TOP>.sdc` defines timing intent?
- Which PDK and Liberty views were used?
- Did lint, CDC/RDC, functional DV, coverage, formal, synthesis, equivalence, and sign-off reach their intended status?
- Which final netlist/SPEF/SDF correspond to the routed branch?
- Are metrics and manifest snapshots retained?
- Is provenance clean or intentionally validated?
- Can another workspace load the IP and reproduce its setup?

`fx check` is the human closure view, but it does not replace the underlying analysis evidence.

---

## 17. Lifecycle at a glance

```text
requirements / HJSON / RTL / model / properties
                    ↓
           bootstrap + generated boundaries
                    ↓
                  lint
                    ↓
        authored constraints/<TOP>.sdc
                    ↓
                CDC / RDC
                    ↓
        functional DV + coverage + formal
                    ↓
                select PDK
                    ↓
             synthesis → EQY
                    ↓
      pre-layout STA / GLS / power / fusion
                    ↓
                 PnR / CTS
                    ↓
     post-route STA / GLS / power / physical
                    ↓
             manifest + metrics
                    ↓
                 fx check
                    ↓
               qualified IP
```

The detailed command sequence for each transition is maintained in the [IP development guide](ip_development_guide.md), not duplicated here.


## Digital IP Contract status and release levels

FlexSoC uses the same provenance manifest for generated setup collateral and successful runtime evidence. `STAGE_CONTRACTS` is the single dependency DAG: every tracked stage declares only semantic configuration, parent stages, and canonical evidence. No graph database or second lifecycle description is used.

After a successful tracked command, FlexSoC records SHA256 snapshots of its effective inputs and evidence. If an input, configuration value, generated setup, or upstream stage changes, dependent evidence is reported as `STALE`; unrelated branches remain valid. Existing `MODIFIED`, `VALIDATED_OVERRIDE`, and `INVALID` semantics continue to apply.

`fx status` evaluates this graph live without running EDA and reports the current authored `IP_INTENT_SHA256`, stage states, and the highest fully closed release level:

```text
0  Contract Valid
1  RTL Qualified
2  Netlist Qualified
3  Technology Qualified
4  Physical Qualified
```

The levels are intentionally hierarchical. A later technology or physical result does not hide a missing earlier qualification stage. EQY remains part of `Netlist Qualified`; while equivalence closure is intentionally deferred, `fx status` therefore stops at the highest earlier level that is fully evidenced.

Runtime evidence currently covers the canonical lifecycle: Slang/Verilator lint suites, CDC/RDC, functional regression, individual formal BMC/prove/cover stages, synthesis, EQY, SDF/STA/vectorless power, post-synthesis SV GLS, PnR, physical sign-off, and routed SDF/STA/power/SV GLS. Composite commands such as `fx lint_suite`, `fx formal`, `fx signoff`, and `fx signoff_post_pnr` are compositions of those same canonical stages, so aggregate and manual execution produce the same contract evidence.
