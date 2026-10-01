# FlexSoC: Open IP Integration, Transport Normalization, and SoC Qualification

## Status

**Architecture direction / implementation roadmap**

This document defines the intended direction for FlexSoC as a framework that can:

1. develop and qualify FlexSoC-owned reusable IP;
2. fetch and pin third-party open-source RTL;
3. wrap external host/device IP behind well-defined transport adapters;
4. generate SoC fabrics and top-level integration;
5. qualify both individual IP releases and complete SoC compositions;
6. preserve provenance, reproducibility, and technology-specific evidence.

The immediate implementation target is a minimal Ibex-based TL-UL SoC assembled from already-qualified FlexSoC peripherals.

---

## 1. Vision

FlexSoC should not be only an RTL generator or an EDA command wrapper.

The target is a **reproducible hardware composition and qualification framework** with three first-class release objects:

- **IP release** — one reusable device or host, with a defined interface contract and qualification evidence;
- **adapter release** — a protocol/transport adapter with its own verification and qualification scope;
- **SoC release** — a composition of qualified IP, adapters, memories, generated interconnect, address map, software collateral, and system-level evidence.

The same lifecycle should apply regardless of whether RTL originates inside FlexSoC or from an upstream project.

```text
upstream or FlexSoC RTL
        |
        v
native endpoint
        |
        v
transport adapter / wrapper
        |
        v
qualified interface release
        |
        v
generated fabric + address map
        |
        v
SoC composition
        |
        v
SoC qualification + release
```

---

## 2. Core architectural principles

### 2.1 Provenance before modification

External RTL is not copied into a release with unclear origin.

Every fetched dependency must identify at minimum:

- upstream project;
- upstream repository;
- pinned revision or tag;
- resolved commit SHA;
- license;
- fetch recipe;
- local patches, if any;
- configuration parameters used to instantiate the IP.

A release must be reproducible from this information.

Third-party source should be treated as **vendored/pinned source**, not as FlexSoC-authored RTL.

### 2.2 FlexSoC owns integration semantics

FlexSoC may consume an upstream specification, but it owns the **integration contract** used for a FlexSoC release.

For an imported CPU this integration contract can include:

- exact upstream revision;
- architectural/configuration parameters;
- clock and reset assumptions;
- boot address;
- native memory interface assumptions;
- interrupt inputs;
- debug policy;
- selected transport wrapper;
- outstanding transaction restrictions;
- supported address width and data width;
- error behavior;
- integration-level DV and formal properties;
- qualification scope.

This keeps upstream architectural claims separate from claims that FlexSoC has actually verified.

### 2.3 Wrappers stay thin

A FlexSoC wrapper should not become a second implementation of the upstream IP.

It should normally perform only:

- protocol adaptation;
- parameter/configuration binding;
- clock/reset adaptation when explicitly required;
- interrupt and external signal normalization;
- integration assertions;
- file-list and generated-collateral binding.

Large protocol engines should be reused from maintained upstream libraries where practical.

### 2.4 Generated text belongs to generators/templates

Static protocol boilerplate and generated interconnect RTL belong to the relevant generator or template.

Python orchestration owns:

- semantic configuration;
- provenance;
- dependency resolution;
- lifecycle;
- command construction;
- qualification policy;
- release packaging.

### 2.5 A failed optional check is still negative evidence

Optional evidence is not the same as irrelevant evidence.

Current qualification semantics should remain:

```text
optional check absent       -> does not block
optional check WAIVED       -> does not block
optional check PASS         -> preserved as positive evidence
optional check FAILED       -> preserved as negative evidence and may block
```

For EQY specifically, runtime equivalence is not a mandatory automatic L3/L4 gate, but an explicitly executed `FAILED` result remains negative evidence from L3 upward.

---

## 3. Release levels

FlexSoC currently uses a five-level release model.

| Level | Meaning | Intended claim |
|---|---|---|
| L1 | Contract Valid | specification/integration contract is structurally valid |
| L2 | RTL Qualified | RTL-level required evidence passes |
| L3 | Netlist Qualified | synthesis/netlist evidence passes |
| L4 | Technology Qualified | post-synthesis technology evidence passes |
| L5 | Physical / Signoff Complete | implementation and post-implementation evidence passes |

For reusable canonical IP, **L4 is the normal pre-PnR release point**.

An L4 package must not retain stale L5 evidence such as:

- implementation directories;
- `post_pnr`;
- `post_impl`;
- post-implementation GLS results.

Synthesis recipes, synthesis output, post-synthesis timing/power/SDF evidence, EQY setup collateral, and release metadata remain legitimate L4 collateral.

---

## 4. IP classes

FlexSoC should explicitly distinguish at least four kinds of hardware components.

### 4.1 Device IP

Memory-mapped peripherals or accelerators that accept transactions.

Examples:

- UART;
- GPIO;
- RV timer;
- SPI host control/status plane;
- imported OpenTitan peripherals;
- DSP/control accelerators.

A device may expose one or more qualified transport releases:

```text
uart
  tlul
  reg_iface
  axi_lite
```

The semantic core should remain transport-independent where practical.

### 4.2 Host IP

Components that initiate memory transactions.

Examples:

- Ibex;
- CVA6;
- VexRiscv;
- DMA engines;
- debug/system controllers.

A host has a **native endpoint** and one or more qualified host adapters.

### 4.3 Adapter IP

Adapters are reusable, independently testable hardware.

Examples:

```text
ibex_native -> tlul_host
ibex_native -> axi_lite_host
reg_iface   -> tlul
axi_lite    -> reg_iface
axi         -> axi_lite
```

Adapters must not be hidden as incidental glue if they materially affect transaction semantics.

They should have:

- a documented source and destination protocol;
- explicit restrictions;
- protocol assertions;
- dedicated functional tests;
- synthesis/technology qualification if shipped as reusable release RTL.

### 4.4 Fabric IP

A fabric is generated or parameterized interconnect.

Initial supported profiles should be:

- TL-UL crossbar;
- AXI4-Lite crossbar;
- RegIface mux/demux fabric;
- later, full AXI for higher-performance systems.

The fabric generator should consume a common SoC topology/address description rather than forcing users to author protocol-specific connectivity manually.

---

## 5. Transport strategy

### 5.1 TL-UL

TL-UL is the first SoC fabric target because FlexSoC already has TL-UL infrastructure and OpenTitan provides mature reusable building blocks.

OpenTitan's `tlgen` consumes an HJSON crossbar description containing host/device nodes, address ranges, clock/reset information, and connectivity. It generates crossbar RTL and DV connectivity collateral.

This is a strong reference model for FlexSoC:

```text
FlexSoC SoC manifest
        |
        v
TL-UL fabric projection
        |
        v
tlgen-compatible HJSON
        |
        v
generated TL-UL crossbar
```

FlexSoC should own the semantic SoC description; `tlgen` remains an external tool.

OpenTitan/lowRISC TL-UL primitives also provide useful adapter patterns, including host-side adaptation between TL-UL and generic request/grant/read-valid memory interfaces.

#### Initial TL-UL target

```text
Ibex
  |
  +-- instruction native endpoint --+
  |                                  |
  +-- data native endpoint ----------+--> TL-UL host adapter(s)
                                         |
                                         v
                                      TL-UL xbar
                                         |
                    +--------------------+---------------------+
                    |                    |                     |
                    v                    v                     v
                  SRAM                 UART                  GPIO
                                                               |
                                                            RV timer
```

The final topology may use separate instruction/data address spaces or separate host nodes depending on integration requirements.

### 5.2 AXI4-Lite

AXI4-Lite should be the second fabric profile.

PULP's `axi` repository already provides:

- `axi_lite_xbar`;
- `axi_lite_mux`;
- AXI4-Lite register stages and utilities;
- `axi_to_axi_lite`;
- `axi_lite_to_axi`;
- full `axi_xbar`.

FlexSoC should therefore prefer **pinned upstream PULP components** over writing a new AXI-Lite crossbar.

The same semantic SoC manifest should project into an AXI-Lite fabric configuration.

AXI-Lite is appropriate for:

- control-plane SoCs;
- small processors with simple adapters;
- peripheral subsystems;
- systems without burst/out-of-order requirements.

It should not be treated as a universal replacement for full AXI.

### 5.3 RegIface

PULP `register_interface` provides a useful low-complexity register transport and already contains blocks such as:

- `axi_lite_to_reg`;
- `axi_to_reg_v2`;
- `reg_demux`;
- `reg_mux`;
- `reg_to_tlul`;
- `reg_to_axi`;
- `reg_cdc`;
- `reg_cut`.

RegIface is therefore attractive as a **small control/register fabric** and as a normalization layer around peripheral register planes.

It should not be used as the default transport for high-bandwidth memories or complex CPU memory systems.

### 5.4 Full AXI

Full AXI is a separate profile, not merely "large AXI-Lite".

It becomes important for:

- CVA6;
- caches;
- DRAM controllers;
- DMA;
- high-throughput accelerators;
- multiple outstanding transactions;
- burst traffic.

PULP's AXI library should be the primary reusable interconnect source unless a concrete reason emerges to use a different implementation.

---

## 6. CPU integration strategy

### 6.1 Ibex — first host target

Ibex is the first target because its instruction/data memory interfaces are relatively simple request/grant/response interfaces.

For the data side, the upstream interface includes signals such as request, grant, address, write enable, byte enable, write data, and response valid.

This maps well to the adapter pattern already used in lowRISC/OpenTitan systems.

#### Phase-1 Ibex release

The first FlexSoC CPU integration should define:

```text
source:
  project: lowRISC/ibex
  revision: pinned

variant:
  name: flexsoc_ibex_small
  parameters: explicit

native:
  instruction: ibex memory request interface
  data:        ibex memory request interface

transport:
  tlul: qualified first
```

Later variants can add:

```text
transport:
  axi_lite
  reg_iface   # only if the semantics are genuinely appropriate
```

A CPU-to-RegIface path should not be added merely for symmetry if it creates unnatural memory semantics.

### 6.2 CVA6 — AXI-native host

CVA6 should be integrated as an AXI-native host.

Its documented memory interface is AXI and supports features beyond AXI-Lite, including a richer transaction model.

Therefore the preferred path is:

```text
CVA6 -> full AXI -> AXI fabric
```

Peripheral control paths can still terminate behind AXI-to-AXI-Lite or AXI-to-RegIface bridges where appropriate.

Do **not** define "CVA6 AXI-Lite" as the canonical native integration unless a deliberately restricted configuration and adapter contract are verified.

### 6.3 VexRiscv

VexRiscv can follow after the Ibex and CVA6 integration models are proven.

Its configurable bus ecosystem already supports AXI, Avalon, and Wishbone-style integrations, which makes it useful for validating that FlexSoC's host abstraction is not tied to one CPU family.

The key requirement is to pin both:

- the generated CPU configuration;
- the SpinalHDL/source revision used to generate it.

The generated RTL is part of the reproducibility contract.

---

## 7. External IP ingestion

Fetching an upstream IP should be a lifecycle stage, not an ad-hoc copy.

Conceptually:

```text
fetch
  -> provenance validation
  -> source/config selection
  -> integration-spec creation/validation
  -> wrapper generation/binding
  -> RTL qualification
  -> synthesis
  -> technology qualification
  -> release packaging
```

### Upstream material

Where licensing allows, a fetched package may retain:

- selected RTL;
- upstream license;
- upstream revision metadata;
- source file list;
- selected upstream documentation/spec references.

### FlexSoC-authored material

FlexSoC adds:

- integration specification;
- wrapper/adapter;
- constraints;
- local DV;
- formal properties;
- generated tests;
- qualification metadata;
- release manifest;
- technology evidence.

### Patches

If an upstream project must be modified, patches should be explicit files tied to a pinned revision.

Avoid silently editing vendored source.

---

## 8. Qualification scope for external IP

An imported open-source core should not automatically inherit the claim "fully verified by FlexSoC".

A release should distinguish scopes such as:

```yaml
origin:
  kind: upstream
  project: lowRISC/ibex
  revision: <sha>

qualification_scope:
  upstream_design:
    status: referenced
  integration:
    status: PASS
  rtl_configuration:
    status: PASS
  technology:
    status: PASS
```

The exact schema can evolve, but the semantic distinction should remain.

Possible evidence sources include:

- upstream tests;
- FlexSoC integration tests;
- ISA tests;
- protocol assertions;
- formal checks;
- synthesis;
- post-synthesis GLS;
- timing;
- power;
- CDC/RDC;
- explicit equivalence;
- physical signoff.

A claim should identify which configuration and wrapper it applies to.

---

## 9. SoC description

FlexSoC should converge on one semantic SoC manifest.

Illustrative target:

```yaml
soc: ibex_min_soc

clock:
  name: core
  period_ns: 10

cpu:
  ip: ibex
  variant: flexsoc_ibex_small
  interface: tlul

memory:
  - name: sram
    kind: sram
    base: 0x00000000
    size: 0x00010000
    interface: tlul

devices:
  - name: uart0
    ip: uart
    interface: tlul
    base: 0x40000000
    size: 0x00001000

  - name: gpio0
    ip: gpio
    interface: tlul
    base: 0x40010000
    size: 0x00001000

  - name: timer0
    ip: rv_timer
    interface: tlul
    base: 0x40020000
    size: 0x00001000

fabric:
  kind: tlul
```

This manifest should be protocol-neutral where possible.

Protocol-specific generators derive their own collateral from it.

---

## 10. Generated SoC collateral

From one SoC manifest, FlexSoC should eventually generate or orchestrate generation of:

- address map;
- fabric configuration;
- fabric RTL;
- top-level RTL;
- file lists;
- clock/reset hookup;
- interrupt mapping;
- memory map documentation;
- C headers;
- linker memory description;
- simulation configuration;
- synthesis constraints;
- qualification contract;
- provenance manifest.

The goal is to eliminate divergence between RTL connectivity, documentation, software addresses, and qualification expectations.

---

## 11. SoC qualification

A SoC release is more than the sum of IP release statuses.

System-level qualification must verify integration-specific behavior.

### L1 — Contract Valid

- component versions resolve;
- address ranges are legal and non-overlapping;
- host/device interfaces are compatible;
- clock/reset topology is valid;
- required memories and interrupts resolve.

### L2 — RTL Qualified

- generated top compiles/lints;
- basic boot/smoke test;
- CPU reaches executable memory;
- peripheral access works through the fabric;
- interrupt path tests;
- system-level protocol assertions;
- relevant CDC/RDC;
- system-level formal where practical.

### L3 — Netlist Qualified

- synthesis passes;
- netlist is valid;
- post-synthesis timing baseline;
- selected post-synthesis simulation;
- optional equivalence evidence preserved when executed.

### L4 — Technology Qualified

- technology-specific post-synthesis timing;
- SDF;
- power estimate/analysis policy;
- bounded GLS matrix;
- technology-specific qualification evidence;
- reusable pre-PnR SoC release if desired.

### L5 — Physical / Signoff Complete

- PnR;
- physical checks;
- post-implementation STA/SDF/GLS/power;
- final signoff evidence.

---

## 12. First reference SoC

The first architecture proof should be deliberately small.

### `ibex_min_soc`

```text
CPU:
  Ibex

fabric:
  TL-UL

memory:
  SRAM

devices:
  UART
  GPIO
  RV timer
```

Success criteria:

1. Ibex source is reproducibly fetched and pinned.
2. The Ibex configuration is explicit.
3. Instruction/data host adaptation is explicit and testable.
4. TL-UL fabric is generated from configuration.
5. Existing qualified peripheral releases are reused.
6. Address map is generated once and reused by HW/SW collateral.
7. A small program boots from SRAM.
8. Software can access UART/GPIO/timer.
9. Interrupts can be exercised.
10. The complete SoC progresses through FlexSoC qualification.

This SoC becomes the reference for later AXI-Lite and multi-CPU work.

---

## 13. Roadmap

### Phase 0 — repository cleanup

- remove obsolete `pwm_ramp`;
- keep TinySoC, SPI Host, CORDIC/cache wrapper, and FFT Core untouched until catalog policy is established;
- classify remaining experimental blocks later instead of deleting them opportunistically.

### Phase 1 — upstream host ingestion

- audit existing Ibex fetch support;
- audit existing TL-UL host wrapper;
- restore/pin Ibex fetch;
- add provenance metadata;
- define Ibex integration specification;
- qualify the Ibex TL-UL host wrapper.

### Phase 2 — `ibex_min_soc` TL-UL

- define SoC manifest;
- generate TL-UL crossbar configuration;
- generate top integration;
- add SRAM;
- reuse UART/GPIO/RV timer releases;
- add software smoke program;
- qualify the SoC.

### Phase 3 — AXI-Lite fabric

- vendor/pin PULP `axi`;
- model `axi_lite_xbar` as an external fabric backend;
- add appropriate host adapter;
- project the same semantic SoC into AXI-Lite;
- qualify the AXI-Lite composition.

### Phase 4 — RegIface fabric

- vendor/pin PULP `register_interface`;
- reuse `reg_mux`/`reg_demux` and protocol adapters;
- build a small register-oriented fabric profile;
- qualify the composition.

### Phase 5 — CVA6

- fetch/pin CVA6;
- select one concrete verified configuration;
- preserve its AXI-native memory contract;
- integrate full PULP AXI fabric;
- bridge peripheral control traffic as required;
- qualify a CVA6-based SoC.

### Phase 6 — VexRiscv

- pin source/generator revision and CPU configuration;
- produce reproducible generated RTL;
- bind one native transport;
- qualify another SoC composition.

### Phase 7 — larger SoCs

- multiple hosts;
- DMA;
- multiple clock domains;
- more complex interrupt topology;
- memory hierarchy;
- larger peripheral catalog;
- L5 physical releases where useful.

---

## 14. Catalog policy

Not every directory under `hw/ips` should imply the same maturity.

The catalog should eventually distinguish states such as:

```text
experimental
integration
qualified
retained
deprecated
```

A future catalog command should be able to answer:

- Is this FlexSoC-authored or upstream?
- Which revision?
- Host, device, adapter, or fabric?
- Which transports are available?
- Which qualification level has each transport reached?
- Which PDKs have evidence?
- Is the package canonical/reusable?
- What is the license?
- Which SoCs currently consume it?

This is preferable to using directory presence as the only indication of support.

---

## 15. Non-goals

The immediate roadmap does **not** require:

- rewriting OpenTitan TL-UL primitives;
- rewriting PULP AXI or register-interface fabrics;
- forcing every CPU onto every transport;
- claiming complete verification of third-party IP merely because integration passes;
- running PnR for every reusable IP release;
- retaining stale implementation evidence in an L4 package;
- supporting every legacy experimental IP before the new architecture is proven.

---

## 16. Upstream references

The initial architecture is intentionally based on existing maintained open-source infrastructure:

- OpenTitan `tlgen` — generated TL-UL crossbar from HJSON host/device topology and address configuration: https://opentitan.org/book/util/tlgen/index.html
- OpenTitan TL-UL documentation: https://opentitan.org/book/hw/ip/tlul/index.html
- PULP `register_interface` — generic register interface and protocol adapters: https://github.com/pulp-platform/register_interface
- PULP `axi` — AXI/AXI-Lite interconnect and adapters: https://github.com/pulp-platform/axi
- Ibex documentation — native instruction/data memory interface: https://ibex-core.readthedocs.io/
- CVA6 documentation — AXI-native application-class RISC-V core: https://docs.openhwgroup.org/projects/cva6-user-manual/
- VexRiscv: https://github.com/SpinalHDL/VexRiscv

Upstream revisions used by actual FlexSoC releases must be pinned independently of these documentation links.

---

## 17. Immediate next implementation milestone

The next implementation milestone is **not** "support every CPU and every bus".

It is:

```text
FETCH Ibex
  -> PIN provenance
  -> BIND one explicit Ibex configuration
  -> QUALIFY native-to-TLUL host integration
  -> GENERATE ibex_min_soc TL-UL fabric
  -> BOOT from SRAM
  -> ACCESS UART/GPIO/RV timer
  -> QUALIFY complete SoC
```

Only after that path is reproducible should the same composition model be projected onto AXI-Lite and RegIface.

That sequence proves the central FlexSoC architecture: reusable qualified IP plus pinned external hosts plus generated interconnect plus system-level qualification.
