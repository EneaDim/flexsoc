# Digital IP Contract and qualification

FlexSoC treats a release as a contract plus reproducible evidence, not as a directory of tool outputs. The **Digital IP Contract** is the first concrete release contract, but the core model is intentionally design-scale independent: the same provenance, invalidation, evidence, qualification, and repeatability primitives apply to small IP, complex IP, subsystems, SoCs, and complex SoCs.

The core model is intentionally small:

1. **Digital IP Contract** — what the IP must do: identity, register interface, external interfaces, clocks/resets, CSR behavior, requirements, assumptions, limitations, and qualification target.
2. **Source of truth** — authoritative specification, requirements, test plan, CSR HJSON, authored RTL, properties, and constraints. Generated collateral is derived state.
3. **Provenance graph** — each tracked artifact/evidence records effective inputs, semantic configuration, real parents, relevant tool identity, canonical outputs, and hashes.
4. **Dependency / invalidation graph** — the `StageContract` fields define what becomes stale when upstream intent changes. FlexSoC invalidates the minimum correct downstream set rather than treating the flow as one monolithic build.
5. **Two independent lifecycle axes** — provenance freshness is `MISSING`, `CLEAN`, `STALE`, `INVALID`, `MODIFIED`, or `VALIDATED_OVERRIDE`; evidence outcome is `MISSING`, `PASS`, `FAILED`, `REVIEW`, `WAIVED`, `STALE`, or `INVALID`. A clean artifact is not automatically a successful EDA result, and a waiver is never a pass.
6. **Qualification policy** — defines the evidence required for each release level.
7. **Evidence** — lint, functional regression, requirement traceability, formal, CDC/RDC, synthesis, equivalence, STA, GLS, power, implementation, and physical checks.
8. **Unified validator** — `fx qualify` derives the maximum level actually supported by coherent non-stale evidence.
9. **Repeatability** — releases retain source/spec hashes, settings, tool/PDK identity, provenance, and qualification evidence sufficient to reproduce the qualification result.

## Design scale: IP to complex SoC

FlexSoC scales by adding authored contract facts and real dependencies, not by introducing a second orchestration architecture:

| Design scale | Typical contract additions | Core mechanisms that stay unchanged |
| --- | --- | --- |
| Small IP | CSR/interface behavior, clocks/resets, RTL, requirements | StageContract, provenance, qualification, release evidence |
| Complex IP / subsystem | multiple domains, CDC/RDC, protocols, memories, performance constraints | the same selective invalidation and evidence lifecycle |
| SoC | IP composition, memory map, interconnect, system clocks/resets, software-visible integration | the same source-of-truth, parent lineage, tool fingerprint, qualification policy |
| Complex SoC | hierarchy, reusable subsystems, multiple domains/technology branches and system-level sign-off | the same graph semantics; only the authored contract and stage dependencies grow |

The currently implemented frozen release primitive is `ip_save` / `ip_load`. SoC-specific package structure is an extension of this contract model; it must not duplicate provenance, scheduling, or qualification logic.

## StageContract and fingerprints

`STAGE_CONTRACTS` is the minimal dependency graph. Each tracked stage declares the information required to decide whether its evidence is still current:

- semantic configuration keys actually consumed by the stage;
- real parent stages;
- canonical owned evidence;
- storage scope (`run` for technology-independent evidence or `pdk` for technology-specific evidence);
- the relevant tool contract/fingerprint.

The stage fingerprint combines effective inputs, configuration, parent lineage, tool identity, and canonical outputs. Tool identity is stage-specific: changing OpenROAD must not invalidate a Yosys-only synthesis result, and changing PDK-specific implementation state must not invalidate RTL regression/formal evidence. Legacy provenance that predates tool fingerprints remains readable under its original fingerprint semantics.

## Qualification levels

| Level | Name | Minimum intent |
| --- | --- | --- |
| L1 | Contract Valid | baselined contract, interfaces, clock/reset, CSR, assumptions and qualification plan |
| L2 | RTL Qualified | L1 + RTL, lint, functional verification, requirement traceability, formal/CDC-RDC where required, limitations and release evidence |
| L3 | Netlist Qualified | L2 + synthesis, constraints, RTL/netlist equivalence, netlist checks, STA and preliminary PPA |
| L4 | Technology Qualified | L3 + declared PDK/library/macro assumptions/PVT and technology-specific evidence such as GLS, timing and power; implementation may be included when the policy requires it |
| L5 | Physical / Signoff Complete Digital Macro | L4 + the final physical/signoff checks required by the technology/customer, such as post-PnR STA, DRC/LVS, antenna, density/fill, equivalence, IR/EM/reliability and final layout views |

`signoff/` is the common release namespace for technology-dependent evidence. It is split by evidence maturity: `signoff/<pdk>/post_syn/` contains post-synthesis evidence, while `signoff/<pdk>/post_pnr/` contains routed/physical evidence using the same evidence names where applicable (`sta/`, `power/`, `fusion/`); physical-only checks may be grouped under `physical/`. The directory name alone does not imply Level 5: only a qualification policy with the complete required physical evidence may claim **Physical / Signoff Complete Digital Macro**.

## IP source and release layout

The authoritative specification is shared by every register-interface implementation:

```text
hw/ips/<IP>/
├── spec/
│   ├── ip.md
│   ├── requirements.yaml
│   └── testplan.yaml
└── interfaces/
    ├── reg_iface/
    ├── tlul/
    └── axi_lite/
```

`REG_ITF` is the only register-interface selection. `profile := REG_ITF` does not exist. The word *profile* remains available for a future real functional/configuration profile.

A frozen interface release is self-describing:

```text
interfaces/<REG_ITF>/
├── ip.json
├── contract/                 # hashed snapshot of spec/ used by this release
├── csr/
├── rtl/
├── analysis/
├── dv/
├── constraints/
├── syn/<pdk>/
├── impl/<pdk>/               # physical implementation artifacts when present
├── signoff/<pdk>/
│   ├── post_syn/             # post-synthesis technology evidence
│   │   ├── sta/
│   │   ├── power/
│   │   └── fusion/
│   └── post_pnr/             # routed/physical evidence
│       ├── sta/
│       ├── power/
│       ├── fusion/
│       └── physical/         # DRC/LVS/antenna/IR-EM/etc. when required
└── meta/<pdk>/
```

## Requirements and test plan

`spec/requirements.yaml` is normative and machine-readable. `spec/testplan.yaml` maps requirements to verification intent, concrete functional tests and formal properties. The generated traceability matrix is evidence/reporting, not another source of truth.

For existing IPs, requirements may initially be marked `origin: derived` when reconstructed from the implemented RTL/CSR/tests/properties. Once reviewed and committed with `status: baselined`, they become authoritative for subsequent releases.

## Scaffold specification

`fx spec` creates the minimal authoritative `spec/ip.md`, `spec/requirements.yaml`, and `spec/testplan.yaml` bundle for the current scaffold. It is intentionally small: the single-clock scaffold covers the starter CSR/datapath/reset contract, while the multi-clock scaffold adds explicit clock/reset ownership, CDC/FIFO, ready/valid, DSP operation and clock-gating requirements. These files are designer-owned after generation and are not silently overwritten unless `--force` is requested.

The generated test plan also defines the default qualification GLS sampling policy. GLS is not a replacement for RTL regression and is deliberately bounded:

- at most three representative functional tests;
- one SystemVerilog GLS backend (`sv`) only;
- exactly the declared `ss`, `tt`, and `ff` timing scenarios;
- the same selected GLS test/scenario matrix is the only activity source used by activity-based power and timing/power fusion;
- the policy applies independently to `post_syn` and `post_pnr` when those stages are part of the requested qualification.

The direct `sim_post_syn_all` / `sim_post_pnr_all` commands remain general-purpose selectors; qualification scripts consume the bounded policy recorded in `testplan.yaml` rather than running every RTL test at gate level.

## Save, load and validate

- `fx ip_load --set IP_NAME=<ip> --set REG_ITF=<itf>` loads exactly `interfaces/<itf>/` into a run and materializes package `signoff/<pdk>/post_syn/` evidence into the operational run layout.
- `fx qualify --set QUAL_LEVEL=<level>` validates the current run against the specification/test-plan policy and writes `meta/<pdk>/qualification.json`.
- `fx ip_save` always runs the same validator first, snapshots the contract, preserves the common IP-level `spec/`, writes provenance/qualification metadata, and atomically publishes only the selected interface/PDK branch. `QUAL_LEVEL=auto` records the maximum demonstrated level; an explicit target refuses publication if that level is not satisfied.
- Saving one PDK branch preserves previously published PDK branches. Release validation rechecks the common `spec/` against the frozen interface contract and recomputes multi-PDK qualification summaries from the per-PDK qualification reports instead of trusting a precomputed `ip.json` claim.

A release is valid only when its required evidence is present, coherent with current intent, and non-stale. Presence of a directory is never sufficient qualification evidence.

Qualification reports preserve the difference between a satisfied policy and an unwaived PASS:

- `maximum_level` is the highest level satisfied by `PASS` or explicitly `WAIVED` evidence;
- `maximum_pass_level` is the highest level satisfied without waivers;
- `qualification_status` is `PASS`, `WAIVED`, or `BLOCKED` for the highest reached level;
- `WAIVED` never becomes `PASS`; `FAILED` and `REVIEW` remain blocking unless an explicit policy records a waiver.

Requirement traceability is emitted machine-readably as `requirement -> testplan item -> methods/tests/properties`, so a release can identify not only that the test plan is complete but exactly which verification intent covers each normative requirement.

### Current EQY baseline

EQY support remains part of the Netlist Qualified policy. During the current scaffold-baseline phase FlexSoC generates EQY collateral with `fx eqy --setup` but does not run the proof by default. **Setup-only is not equivalence evidence**: the `eqy` stage remains `MISSING`, so qualification must not claim L3 until a real EQY run produces acceptable evidence (or an explicit future waiver policy is deliberately applied).

## Provenance scopes

FlexSoC keeps one dependency model and two storage scopes:

- RTL-scope evidence (lint, regression, CDC/RDC, formal, testbench setup) is stored once per run and is not invalidated by a PDK switch.
- Technology-scope evidence (synthesis, equivalence, STA, GLS, power, PnR and physical checks) is stored per PDK.

A stage fingerprint is meaningful only when it covers values actually consumed by the tool. Generated ORFS `config.mk` assignments are therefore passed as effective make overrides as well as hashed provenance inputs. Changing a PnR knob invalidates PnR and post-PnR descendants, not RTL or post-synthesis evidence.
