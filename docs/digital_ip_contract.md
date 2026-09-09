# Digital IP Contract and qualification

FlexSoC treats a release as a contract plus reproducible evidence, not as a directory of tool outputs.

The core model is intentionally small:

1. **Digital IP Contract** — what the IP must do: identity, register interface, external interfaces, clocks/resets, CSR behavior, requirements, assumptions, limitations, and qualification target.
2. **Source of truth** — authoritative specification, requirements, test plan, CSR HJSON, authored RTL, properties, and constraints. Generated collateral is derived state.
3. **Provenance graph** — each generated artifact/evidence records its effective inputs, configuration, parents, and hashes.
4. **Dependency / invalidation graph** — the existing `StageContract.parents` and stage inputs define what becomes stale when upstream intent changes. FlexSoC invalidates the minimum correct downstream set.
5. **Artifact/evidence states** — `MISSING`, `CLEAN`, `STALE`, `PASS`, `FAILED`, `WAIVED`, `INVALID`, `MODIFIED`, `VALIDATED_OVERRIDE`. A waiver is never a pass.
6. **Qualification policy** — defines the evidence required for each release level.
7. **Evidence** — lint, functional regression, requirement traceability, formal, CDC/RDC, synthesis, equivalence, STA, GLS, power, implementation, and physical checks.
8. **Unified validator** — `fx qualify` derives the maximum level actually supported by coherent non-stale evidence.
9. **Repeatability** — releases retain source/spec hashes, settings, tool/PDK identity, provenance, and qualification evidence sufficient to reproduce the qualification result.

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
- `fx ip_save` always runs the same validator first, snapshots the contract, writes provenance/qualification metadata, and atomically publishes only the selected interface/PDK branch. `QUAL_LEVEL=auto` records the maximum demonstrated level; an explicit target refuses publication if that level is not satisfied.

A release is valid only when its required evidence is present, coherent with current intent, and non-stale. Presence of a directory is never sufficient qualification evidence.

## Provenance scopes

FlexSoC keeps one dependency model and two storage scopes:

- RTL-scope evidence (lint, regression, CDC/RDC, formal, testbench setup) is stored once per run and is not invalidated by a PDK switch.
- Technology-scope evidence (synthesis, equivalence, STA, GLS, power, PnR and physical checks) is stored per PDK.

A stage fingerprint is meaningful only when it covers values actually consumed by the tool. Generated ORFS `config.mk` assignments are therefore passed as effective make overrides as well as hashed provenance inputs. Changing a PnR knob invalidates PnR and post-PnR descendants, not RTL or post-synthesis evidence.
