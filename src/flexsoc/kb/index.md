# FlexSoC Knowledge Base

Engineering reference for delivering verifiable IP and SoC designs with FlexSoC.

## Core principles

- **Design from evidence:** link specifications, requirements, verification scenarios, and tool results.
- **Keep boundaries clear:** generic FlexSoC services stay protocol-independent; each IP owns its models, RTL, and testbench extensions.
- **Prefer the simplest complete solution:** readable object-oriented code, minimal duplication, and no unnecessary files or abstractions.
- **Release what has been verified:** `PASS`, `FAIL`, `NOT_RUN`, `BLOCKED`, and documented deferrals are different states.

## Engineering domains

- [00_repository](./00_repository/index.md) — Repository & Engineering Practices
- [01_spec_to_technical](./01_spec_to_technical/index.md) — Customer Spec → Technical Spec
- [02_requirements_and_testplan](./02_requirements_and_testplan/index.md) — Technical Spec → Requirements & Test Plan
- [03_models](./03_models/index.md) — Python Models & Model Tests
- [04_csr](./04_csr/index.md) — Control & Status Registers
- [05_rtl](./05_rtl/index.md) — RTL Development
- [06_structural_checks](./06_structural_checks/index.md) — Lint, Constraints & CDC/RDC
- [07_functional_dv](./07_functional_dv/index.md) — RTL Functional DV
- [08_formal_dv](./08_formal_dv/index.md) — Formal Design Verification
- [09_traceability](./09_traceability/index.md) — Requirements Traceability
- [10_synthesis](./10_synthesis/index.md) — Synthesis
- [11_post_synthesis](./11_post_synthesis/index.md) — Post-Synthesis Verification & Signoff
- [12_place_and_route](./12_place_and_route/index.md) — Place & Route
- [13_post_implementation](./13_post_implementation/index.md) — Post-Implementation Verification & Signoff
- [14_physical_signoff](./14_physical_signoff/index.md) — Physical Signoff
- [15_release](./15_release/index.md) — Qualification & Release

## Cross-stage handoffs

- Architecture produces interface and microarchitecture decisions; requirements define observable acceptance criteria.
- Models, RTL simulation, and formal verification produce complementary evidence, not interchangeable PASS states.
- Synthesis, implementation, GLS, STA, power analysis, and physical signoff consume versioned design and constraint baselines.

## Selected external references

- [PULP Platform](https://github.com/pulp-platform/pulp) — modular RISC-V SoC integration and IP dependency organization.
- [PULPissimo](https://github.com/pulp-platform/pulpissimo) — microcontroller-class SoC integration example.
- [lowRISC OpenTitan](https://opentitan.org/book/) — IP documentation, reusable primitives, and verification collateral.
- [OpenTitan register generator](https://opentitan.org/book/util/reggen/index.html) — CSR specification and generation patterns.

These are references for comparison, not mandatory FlexSoC architecture or tool dependencies.
