# Reference desk — find the authoritative detail

> **Reference navigation, not a new command specification.** All command syntax in the existing [command reference](../command_reference.md) must be checked against the installed `fx` CLI and matching repository revision. Do not infer support from a heading alone.

This page helps you locate commands by the engineering question you have. It deliberately links to existing canonical sections instead of duplicating command examples that could drift.

For a concise, code-checked starting point, read [CLI essentials](cli-essentials.md). The full command catalogue remains the single source of detailed CLI documentation.

For ASIC phases, use the [ASIC workflow navigator](../guides/asic-flow-navigation.md) before the full [ASIC flow guide](../flexsoc_asic_flow_guide.md).

## Choose by engineering intent

| You need to… | Consult | Then validate |
| --- | --- | --- |
| Find global syntax, flags and setup behavior | [CLI model](../command_reference.md#1-command-line-model) | `fx --help` and relevant subcommand help |
| Select a lifecycle target | [Lifecycle command map](../command_reference.md#2-lifecycle-command-map) | Project prerequisites and target status |
| Find the supported backend targets | [Backend target catalogue](../command_reference.md#3-complete-backend-target-catalogue) | Installed tools and target-specific help |
| Explore RTL viewing | [Viewing commands](../command_reference.md#38-viewing) | Current viewer implementation and its tests |
| Check parameters and variables | [Variable reference](../command_reference.md#4-variable-reference) | Configuration parser and actual project files |
| Choose commands after an RTL change | [Change-type guide](../command_reference.md#6-command-selection-by-change-type) | Affected evidence freshness |
| Diagnose an EDA failure | [Failure-driven playbook](../command_reference.md#8-failure-driven-command-playbook) | Raw log, run metadata, exit status |
| Understand who owns generated artifacts | [Artifact ownership](../command_reference.md#9-scaffold-and-artifact-ownership-map) | Authored versus generated paths |
| Look up full command sequences | [Lifecycle command sequences](../command_reference.md#10-reference-lifecycle-command-sequences) | Tool versions, PDK and design inputs |

## What reference is not

- A command listed in documentation is not proof that its required tool is installed.
- `PASS` is not proof that the evidence is still current.
- A proposed architecture is not a supported CLI interface.
- Viewing outputs do not replace analysis provenance.

For practical investigation see [Reading run results](../guides/reading-run-results.md). To understand freshness and qualification see [Evidence lifecycle](../concepts/evidence-lifecycle.md). For an end-to-end path see the [IP development guide](../ip_development_guide.md).
