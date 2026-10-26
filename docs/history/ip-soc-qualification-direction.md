> **Historical architecture proposal — not a description of implemented functionality.**
> This document preserves an earlier IP/SoC qualification direction, including aspirational CPU, transport, adapter and signoff plans. Check source code, CLI and tests before claiming any capability exists. For current conceptual guidance see [IP/SoC qualification model](../concepts/ip-soc-qualification.md).

---

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

### 2.6 Toolchain resolution is inventory-first

The native toolchain lock is the single version contract for FlexSoC-owned EDA tooling. Dependency installation must be inventory-first: before any network access or build, FlexSoC classifies each locked tool as exact in the current managed prefix, exact in an external host prefix, mismatched, or missing. User-mode installation may reuse an exact external tool; system/container installation must materialize the exact lock in the managed prefix. Only missing or mismatched tools may be fetched or rebuilt.

Yosys, SymbiYosys (SBY), and EQY form one compatibility family. They must resolve to the same locked release generation and installation prefix; a mismatch in any member causes the complete family to be installed together. This avoids loading EQY plugins against a different Yosys build or running SBY against an unqualified Yosys generation.

The Docker image consumes the same `toolchain.lock`; it is a reproducible system-mode materialization, not a second tool-version source. A toolchain generation is promoted in two stages: first install and qualify the native user-mode generation, then let `.github/workflows/toolchain-image.yml` build, verify, publish, and freeze the Docker image from the same lock in GitHub Actions. OpenROAD-flow-scripts remains independently pinned by its ORFS/OpenROAD revisions and must not silently inherit the host Yosys merely for version uniformity.

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
resolved SoCPlan
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
                                         v
                                       SRAM

M0 stops here. UART, GPIO, and RV timer are introduced only by later milestones.
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

The same semantic SoC plan should project into an AXI-Lite fabric configuration.

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

FlexSoC must have one semantic source of truth for a resolved composition. At the current milestone that source of truth is the Python model owned by the SoC subsystem:

- `SoCDevice` describes one resolved memory-mapped endpoint;
- `SoCPlan` describes the host, concrete fabric, and ordered devices;
- `SocFlow.resolve_plan()` is the sole resolver for that model.

Do **not** add a second user-facing YAML/HJSON SoC manifest while this model is sufficient. A declarative input format may be introduced later if a concrete use case requires it, but it must feed the same semantic model rather than create a parallel framework.

The resolved machine-readable artifact is `soc/plan.json` relative to the canonical run root (`workspace/runs/<RUN_TOP>/<RUN_ID>`). There is no additional literal `run/` directory beneath that root.

The same `SoCPlan` must drive the address map/fabric projection, top-level RTL, software memory map, FuseSoC metadata, and qualification evidence. Protocol-specific generators consume projections of the plan; they do not become a second source of truth. CPU reset-vector quirks are projections of the same plan rather than additional address constants. For Ibex, `boot_addr_i` is the vector-table base and the architectural reset PC is `boot_addr_i + 0x80`. M0 therefore renders `boot_addr_i = 0x00100000`, places the vector table at the SRAM base, and places the reset jump at `0x00100080`; the linker and RTL both derive these addresses from the same `SoCPlan` SRAM device.

For the first milestone, the resolved plan is deliberately only:

```text
host:   Ibex
fabric: TL-UL
device: SRAM @ 0x00100000, size 128 KiB
```

UART, GPIO, and RV timer are not implicit members of M0. They are added only in later milestones or when explicitly staged as reusable IP.

---

## 10. Generated SoC collateral

`fx soc --host ibex` is the single public generation entry point. `SocFlow` performs the internal sequence atomically from the user's perspective:

```text
resolve plan
  -> <run>/soc/plan.json
  -> <run>/soc/xbar.hjson
  -> tlgen -t <xbar.hjson> -o <run>
  -> <run>/rtl/autogen/...
  -> <run>/rtl/soc.sv
  -> <run>/soc.core
```

The `tlgen` output directory is the SoC run directory. FlexSoC consumes OpenTitan's native `rtl/autogen/` and `dv/autogen/` layout rather than forcing generated files into a custom location. External tool execution continues to use `CommandRequest -> ToolRunner -> Executor`.

The first compile/elaboration milestone remains behind the same public surface: `fx soc --host ibex --build` regenerates the composition and asks FuseSoC to setup/build the generated `soc.core` `lint` target with Verilator in `lint-only` mode. Generated SoC FuseSoC build state is disposable: each build action recreates its build root from the current `soc.core` and generated RTL/DV so a previous simulator binary cannot mask changes to a same-VLNV development design. This proves dependency resolution and RTL elaboration for the M0 integration; it is not by itself a SoC qualification claim and must not be reported as EDA PASS unless the command has actually executed successfully.

The first simulation milestone is likewise an action of the same `SocFlow`: `fx soc --host ibex --sim` regenerates the composition, builds the generated SystemVerilog functional testbench, and runs the selected SoC test (default `smoke`) through Verilator. The simulator emits `<run>/dv/functional/sim/soc_tb_<test>.fst`; `fx soc --host ibex --view` opens the latest waveform through the canonical FlexSoC viewer path.

SoC DV reuses the same generated functional-test contract as IP DV instead of maintaining a parallel simulator harness. The SoC owns `<run>/dv/functional/tb`, `<run>/dv/functional/tests`, `<run>/dv/functional/model`, and `<run>/dv/functional/sim`. Tests belonging to component IPs remain qualification evidence for those IP releases and are not copied into the SoC test namespace. The SoC tests qualify the resolved composition.

Each SoC functional catalogue lives at `dv/functional/model/tests.py`, mirroring the existing IP model where one Python file owns many named scenarios. `fx tests_gen` materializes the catalogue and `fx test_gen --set TEST_NAME=<name>` materializes one scenario under `dv/functional/tests/<name>/`. Python owns only verification intent and generated `config.regs`, `data_in.vec`, and `data_out.vec`; firmware remains real C/assembly under each test's `sw/` directory and is never embedded as Python strings. Test-specific SystemVerilog hooks are not part of the contract: IP and SoC tests reuse the same generated SystemVerilog/cocotb testbench structure and vector engine. All test collateral belongs to the workspace/package, not the backend.

Vector-driven tests keep the shared FlexSoC tokenizer/driver/monitor semantics. `@wait` advances to an explicit cycle. CPU-driven tests may additionally use `@wait_event`: the test-owned `tb_wait_event()` hook waits for a named firmware event and the following input-vector cycle numbers restart relative to that barrier. This prevents external stimulus from depending on guessed CPU latency. Fixed-cycle output checks should not span such a barrier; CPU-latency-dependent results use guarded/event-driven checks or a test-owned monitor. A test may therefore be vector-only, software-driven, or combine software execution with externally driven/checkable vectors without creating a second CPU-DV category.

`config.regs` remains the register-setup description generated by the Python scenario. For an IP test the existing verification transport can apply it directly. For a CPU-driven SoC, a non-empty configuration must have an explicit legitimate executor (normally CPU MMIO, or a declared external/debug host); the testbench must not gain an implicit backdoor bus master. The current UART CPU smoke therefore leaves `config.regs` empty and configures UART from firmware. A future CPU-config projection may translate the same symbolic setup into a firmware-consumed table, but it must preserve this ownership rule rather than duplicate configuration intent.

Software build outputs such as ELF/bin/VMEM files are generated artifacts, not maintained test inputs. The software build step is owned by the SoC subsystem, publishes the `SoCPlan` memory map to the test software, and presents a simulator-specific VMEM projection to the RTL SRAM while preserving the ELF as the canonical compiled program artifact; application behavior remains entirely test-owned.

The test-status word immediately below the software stack is a verification mailbox, not a functional CSR. Firmware may publish progress events there (for example `READY_RX`) and a final PASS signature. The SoC design contract exposes writes from the SoC-owned SRAM request boundary as one generic functional-DV event stream (`valid`, `value`, sequence); the shared SystemVerilog and cocotb vector engines consume that event source without knowing firmware event names or test semantics. This event/mailbox protocol makes cause/effect explicit: firmware publishes readiness, external vectors execute, externally visible behavior is checked, then firmware publishes completion.

The generated functional testbench remains data-driven and shared across IP/SoC, single-clock/multi-clock and SystemVerilog/cocotb backends: it owns clock/reset generation, loads `config.regs`, interprets `.vec` commands, checks expected outputs, and produces the waveform. Cycle-vector input and output interpreters run concurrently. `@wait_event <label> <value> [timeout]` and `@wait_signal <signal> <value> [timeout]` are generic barriers that restart the following numeric timeline relative to the observed cause, avoiding guessed CPU latency. Native Verilator compilation consumes the authoritative `run/rtl/rtl.f`; FuseSoC is not part of the runtime-authoritative build/simulation path. Simulation builds use Verilator `-Wno-fatal`: warnings remain visible diagnostic evidence, while real tool errors and nonzero execution failures remain blocking.

As later milestones mature, the same `SoCPlan` should also drive or constrain:

- software headers and linker memory description;
- interrupt mapping;
- simulation/build configuration;
- synthesis constraints;
- qualification contract and release provenance.

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

The first architecture proof is deliberately staged.

### M0 — `Ibex -> TL-UL -> SRAM`

M0 contains only Ibex, one generated TL-UL fabric, and 128 KiB SRAM at `0x00100000`. Its first acceptance criterion is framework-level reproducibility: one `fx soc --host ibex` invocation must coherently produce `plan.json`, `xbar.hjson`, native `tlgen` RTL, `soc.sv`, and one `soc.core`. `smoke` validates the generated functional-DV infrastructure; `boot_smoke` additionally builds C/assembly with the RISC-V GNU toolchain, derives ELF/bin/VMEM artifacts, boots from the SRAM vector table, and requires the firmware PASS signature. Compile, simulation, and boot remain separate evidence and must not be claimed until the corresponding commands have actually run.

IP software drivers are release-owned and base-relative. `fx driver` derives register offsets and field definitions from the IP HJSON/reggen source of truth and emits reusable C collateral under `sw/drivers`; it must not embed a SoC absolute base address or an `<IP>_BASE` macro. Every MMIO operation receives an explicit driver base/context. `ip_save` freezes that driver with the IP release, while SoC composition owns the instance base address and binds it later through SoC-generated software-visible memory-map collateral.

In development, saving the same IP release version atomically replaces the current interface snapshot; `ip_save` does not require a force-only overwrite mode. Qualification evidence stored in a loaded release is durable metadata: when the packaged contract snapshot still validates against the current specification, CSR, authored RTL, constraints, and formal property sources, missing or stale workspace runtime evidence may reuse the frozen qualification outcome. Current modified or invalid evidence always wins and invalidates the frozen baseline.

SoC software binding is generated from `SoCPlan`: `sw/include/soc_memory_map.h` contains only instance base addresses and sizes. IP register offsets and MMIO semantics remain exclusively in the staged release driver. SoC functional firmware compiles directly against `ips/<ip>/sw/drivers` and must not duplicate CSR offsets or rewrite the driver with SoC-specific addresses.

### M1 — UART

The M1 functional acceptance test is CPU-driven and pin-observed. `uart_smoke` compiles source-first firmware that programs the UART through MMIO at the address resolved by `SoCPlan`; the firmware publishes readiness, receives an externally injected UART byte, echoes it through the UART TX path, and publishes completion. The shared vector engine synchronizes to firmware events and to the external `tx_o` start bit, then checks the serialized frame through ordinary `data_out.vec` expectations. Observing only a software signature or only an internal UART transaction is insufficient M1 evidence.

After M0 compiles and boots reproducibly, add the qualified UART release through the same plan and fabric path. A reusable interface release is self-contained with respect to repository-local RTL: it carries its EDA integration contract (`<ip>.core`) beside `ip.json`, RTL, CSR, drivers, qualification evidence, and frozen repo-local dependencies under `rtl/deps/`. Pinned third-party RTL stays external only through explicit FuseSoC VLNV dependencies recorded in `rtl/fusesoc_deps.txt` and `<ip>.core`. `ip_save` rewrites canonical filelists to release-relative paths and generates the core from that frozen contract; `ip_load` stages the release unchanged into `<run>/ips/<name>/` and rejects filelists that escape the staged package. The SoC gives FuseSoC only the run root plus explicit pinned vendor roots required by the composition; it never scans the global `hw/ips` catalog and never depends on the legacy `ips:dependecies:all` aggregate core. Checkout-local mirrors of pinned third-party RTL are not release-owned sources: `ip_save` maps them back to their owning FuseSoC VLNV dependencies instead of freezing duplicate copies. Only FlexSoC-owned RTL is copied under `rtl/deps/flexsoc/`.

### M2 — GPIO + RV timer

Add the qualified GPIO and RV timer releases without changing the single-source-of-truth model.

### M3 — complete SoC qualification

Qualify the resulting SoC composition using only evidence FlexSoC actually produced.

Success criteria across these milestones are:

1. Ibex source is reproducibly fetched and pinned.
2. The Ibex configuration is explicit.
3. Instruction/data host adaptation is explicit and testable.
4. TL-UL fabric is generated from the resolved `SoCPlan`.
5. The address map is generated once and reused by downstream collateral.
6. M0 compiles, simulates, and boots from SRAM reproducibly.
7. M1/M2 reuse qualified peripheral releases rather than hidden demo RTL.
8. The complete composition progresses through FlexSoC qualification without overstating upstream or unexecuted evidence.

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

- M0: generate and qualify the framework contract for `Ibex -> TL-UL -> SRAM`;
- make M0 compile/sim/boot reproducibly;
- M1: add UART;
- M2: add GPIO and RV timer;
- M3: complete SoC qualification;
- keep `SoCPlan` as the single semantic source of truth and `plan.json` as its resolved artifact.

### Cross-cutting DV roadmap — reusable cocotb interface utilities / VIP

The generated cocotb testbench should progressively support reusable protocol utilities and verification IP without turning protocol-specific behavior into a second testbench framework. The current TL-UL flow remains the primary SoC path; this capability is a forward-looking extension for larger systems and additional external interfaces.

The intended model is:

- keep one generated cocotb lifecycle for IP and SoC, single-clock and multi-clock designs;
- keep `TestbenchModel` as the shared structural source for clocks, resets, ports, register transports, and stream discovery;
- allow optional Python-side interface helpers to bind reusable master/slave, source/sink, RAM/model, and monitor components to interfaces already represented by the design contract;
- prefer maintained ecosystem VIP over reimplementing standard protocols inside FlexSoC;
- keep every external VIP dependency explicit, pinned, optional, and activated only when the corresponding protocol is used;
- do not require AXI/APB/Ethernet/PCIe packages for the current TL-UL-only flow;
- preserve the existing vector/regression path as the generic baseline even when richer cocotb VIP is available.

AXI-Lite is the first planned standard-bus integration for this capability because it is also the next fabric profile. A first implementation should evaluate `cocotbext-axi` for AXI/AXI-Lite/AXI-Stream/APB utilities, including bus binding, masters/slaves, stream source/sink components, and memory models. Later protocols such as AHB, UART, Ethernet, and PCIe should be added only when a real FlexSoC design requires them and after selecting maintained compatible libraries.

The generated cocotb scaffold already has the necessary architectural insertion point: FlexSoC emits a local Python testbench package, adds it to `PYTHONPATH`, and generates register-transport-specific helpers separately from the common test lifecycle. Therefore no new public command or parallel testbench hierarchy is required. Future VIP support should extend that package with small optional interface bindings/factories rather than create protocol-specific `*Testbench` classes.

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
- cocotb `cocotb-bus` — reusable Python testbench components and bus interfaces: https://github.com/cocotb/cocotb-bus
- `cocotbext-axi` — cocotb AXI/AXI-Lite/AXI-Stream/APB masters, slaves, streams, and memory models: https://github.com/alexforencich/cocotbext-axi
- Ibex documentation — native instruction/data memory interface: https://ibex-core.readthedocs.io/
- CVA6 documentation — AXI-native application-class RISC-V core: https://docs.openhwgroup.org/projects/cva6-user-manual/
- VexRiscv: https://github.com/SpinalHDL/VexRiscv

Upstream revisions used by actual FlexSoC releases must be pinned independently of these documentation links.

---

## 17. Immediate next implementation milestone

The next implementation milestone is **not** "support every CPU and every bus".

It is:

```text
FETCH/PIN Ibex
  -> BIND one explicit Ibex configuration
  -> QUALIFY native-to-TLUL host integration
  -> M0 GENERATE Ibex -> TL-UL -> SRAM
  -> M0 COMPILE / SIMULATE / BOOT from SRAM
  -> M1 ADD UART
  -> M2 ADD GPIO + RV timer
  -> M3 QUALIFY complete SoC
```

Only after that path is reproducible should the same composition model be projected onto AXI-Lite and RegIface.

That sequence proves the central FlexSoC architecture: reusable qualified IP plus pinned external hosts plus generated interconnect plus system-level qualification.


### Native SoC source resolution

The authoritative SoC qualification path is converging on the same FlexSoC-owned
execution model used for reusable IP. FuseSoC core files may remain generated
interoperability/export artifacts, but they are not the intended authority for
FlexSoC qualification targets.

SoC RTL source membership must be deterministic and explicit. `SoCPlan`, staged
release file lists, and generated fabric/top collateral feed a native
`RtlSourceSet`; recursive directory scanning is not a source-resolution
contract. The SoC flow first materializes `rtl/rtl_soc.f` for the source closure
already owned by FlexSoC. A final tool-ready `rtl/rtl.f` is emitted only after
the host CPU dependency closure (beginning with Ibex) is represented by the
same explicit release/source contract.

Native FlexSoC targets will then consume that closed source set directly through
`CommandRequest -> ToolRunner -> Executor` for lint, CDC/RDC, functional
simulation, formal, synthesis, and later implementation/signoff.



The complete tool-ready `rtl/rtl.f` is generated by Slang from the generated
`soc.sv` top and a small set of explicit source roots: staged run-local IP
releases plus the pinned vendor roots required by the selected host and fabric.
Slang dependency trimming determines the actually elaborated module/include
closure; FlexSoC owns the source roots, tool invocation, output file list and
subsequent qualification targets. FuseSoC is not involved in this resolution.

For the native SoC flow, lowRISC virtual primitives are no longer selected by
FuseSoC and overlapping primitive libraries are never presented directly to
Slang. FlexSoC materializes one run-local `rtl/prim_native` library with explicit
precedence: frozen FlexSoC `hw/ips/prim_opentitan` sources win; pinned lowRISC
`prim_generic` implementations fill missing abstract primitive names; concrete
pinned lowRISC `ip/prim/rtl` sources and include headers fill only filenames that
remain missing. The direct vendor `ip/prim/rtl` directory is therefore not a
second Slang library root. This guarantees one owner per primitive definition
while preserving access to lowRISC primitives that FlexSoC does not freeze.

Native package ownership follows the same rule in `run/rtl/pkgs_native`.
FlexSoC-owned `hw/ips/pkgs` files win and missing pinned lowRISC `*_pkg.sv`
packages are copied from `ip/prim/rtl`. `top_pkg.sv` remains the explicit first
package seed for Slang and for the final `rtl/rtl.f`, ahead of dependent
packages such as `tlul_pkg.sv`. Staged release-private copies under
`rtl/deps/flexsoc/prim_opentitan` and `rtl/deps/flexsoc/pkgs` remain excluded
from the SoC ownership manifest.

The normal Ibex SoC instantiates `ibex_top` and resolves its native closure with
`SYNTHESIS`; RVFI/tracing is verification/debug collateral to be enabled
explicitly by a future tracing feature rather than an implicit requirement of
the production SoC source closure.

### Native SoC Verilator execution

SoC build and functional simulation consume the resolved `rtl/rtl.f` directly.
`fx soc --build` runs native Verilator lint/elaboration with top `soc`;
`fx soc --sim` builds the generated `soc_tb` with Verilator `--binary` and then
runs the existing FlexSoC functional-DV runtime. The Verilator work directory
is recreated for every SoC simulator build so generated RTL/TB changes cannot
be hidden by stale compiled collateral. FuseSoC core files may still be emitted
for interoperability, but FuseSoC is not part of the authoritative SoC build or
simulation execution path.

Generic RTL-consuming flows resolve one active `RtlSourceContract` from run state.
`run/soc/plan.json` selects the SoC contract (`top=soc`, `rtl/rtl.f`); without a
resolved SoC plan the IP contract remains (`top=<TOP>`,
`rtl/rtl_common.f + rtl/rtl_ip.f`). Presence of an unrelated or stale `rtl.f`
alone never changes design identity. Both contracts own the active run root as
the base for relative filelist entries. Lint and CDC/RDC already consume this
shared contract; formal and synthesis should migrate to the same resolver rather
than grow independent IP/SoC path selection.

Native SoC lint therefore reuses the canonical IP lint evidence pipeline while
changing only the resolved source contract. The same normalized diagnostics,
P0-P3 priority policy, per-tool summaries and aggregated `dv/lint/summary.json`
are used for both IP and SoC. No SoC-specific lint reporter or severity policy
exists.

Filelist paths are interpreted from the active run root. Slang, Verilator and
CDC/RDC structural extraction therefore execute with `run/` as their command
working directory while still flowing through
`CommandRequest -> ToolRunner -> Executor`. This keeps `rtl/...` and `ips/...`
entries portable and prevents the repository checkout or `dv/cdc_rdc/` from
becoming accidental second path roots. Verilator lint, like Slang lint, defines
`SYNTHESIS` so upstream RTL does not pull verification-only coverage macros into
the synthesis-oriented lint closure.

For Ibex SoCs the first-class design instantiates upstream `ibex_top`; the
`ibex_top_tracing` wrapper is simulation/debug collateral and is not part of the
normal SoC RTL closure. Structural CDC/RDC extraction consumes the same
authoritative `rtl.f` but applies a tool projection (`SYNTHESIS`, assertions
ignored, initial procedures ignored) rather than generating a second CDC
filelist. This keeps simulation-only initialization such as memory loaders out
of the structural graph without creating another source of truth.

The pinned Ibex checkout remains pristine upstream source. FlexSoC does not patch
`ibex_top.sv` to accommodate a particular frontend. Tool-specific SystemVerilog
compatibility belongs to the generated structural/tool projection; any future
upstream patch must be justified independently and tied explicitly to the pinned
revision.

### SoC functional-software ownership

CPU-driven functional tests are workspace/package content, not backend content.
FlexSoC does not own application-specific firmware such as `uart_smoke/main.c`,
startup code, linker scripts, or test Makefiles. A selected test may provide
`dv/functional/tests/<test>/sw/`; when present, the generic SoC DV mechanism
runs that test-owned Makefile through `CommandRequest -> ToolRunner -> Executor`,
requires `build/main.elf` and `build/main.bin`, derives `build/main.vmem`, and
passes the ELF/VMEM artifacts to the normal functional simulation. If `sw/` is
absent, the same functional-DV path runs as a pure external-vector test.

The generated `sw/include/soc_memory_map.h` remains a framework projection of
`SoCPlan`; it is mechanism, not application policy. Test-specific register
programming, UART behavior, signatures, linker layout, firmware source, and vectors
stay with the SoC workspace/package. Test-specific SystemVerilog hooks are not
part of the contract: observation and synchronization are expressed through the
shared vector engine and the design-owned event boundary. Development fixtures
under `tests/fixtures/soc/` are copied explicitly into the run workspace and are
not staged by production code.

### Active run design state

Persistent `.flexsoc/settings.json` values are user configuration, not the
authoritative identity of a resolved design. When the selected run contains
`soc/plan.json`, FlexSoC overlays that resolved design state onto the effective
settings used by CLI display and target execution:

- `DESIGN=soc`
- `HOST=<plan.host>`
- `FABRIC=<plan.fabric>`

The persistent settings file is not rewritten by this overlay. Generic targets
such as lint, CDC/RDC, formal and synthesis therefore operate on the resolved
SoC in the current run without turning `HOST` into a second source of truth.
