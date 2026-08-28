# FlexSoC methodology

This directory contains user-facing engineering methodology for authored
FlexSoC design collateral.

These guides are intentionally different from the command reference and the
architecture documentation. They explain **how to write the source files that
remain under designer control**, which contracts those files should express,
and how the generated FlexSoC flow consumes them.

A methodology guide is added here only after the corresponding workflow has
been exercised and its contract is understood well enough to document without
guessing.

The goal is therefore not to document every lifecycle stage in advance. The
goal is to build a small set of reliable guides that an IP author can follow.

## Current guides

### [HJSON register description](hjson.md)

How to author the software-visible register contract, including:

- the canonical scaffold/header structure;
- required identity, clocking, bus, and register fields;
- `swaccess` / `hwaccess` ownership patterns;
- `hwext` and write-event (`qe`) use;
- field naming, bit allocation, and description discipline;
- validation through RTL, documentation, Python regmap, and C driver generation.

### [Formal verification](formal_verification.md)

How to write and maintain design-specific formal properties, including:

- authored property ownership;
- separation between automatic CSR formal and design formal;
- binding properties to the correct design boundary;
- reset-aware temporal assertions;
- correct use of `$past()`;
- BMC, prove, and cover responsibilities;
- shallow qualification cover versus deeper reachability work;
- reading compilation failures and counterexamples at the right layer.

## Planned methodology areas

Additional guides should be added only after their contracts have been validated
through real IP development. Expected areas include:

```text
RTL/core structure
functional reference model
functional scenario/test generation
```

These are intentionally not documented here yet.

## Relationship to the rest of the documentation

Use:

- [`../project_lifecycle.md`](../project_lifecycle.md) for the canonical FlexSoC lifecycle;
- [`../command_reference.md`](../command_reference.md) for exact CLI behavior;
- [`../ip_development_guide.md`](../ip_development_guide.md) for the broader IP-development workflow;
- [`../architecture.md`](../architecture.md) for backend/contributor internals.

The files in this directory focus specifically on **designer-authored engineering
methodology**.
