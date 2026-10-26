# Practical guides: choose your next task

Guides are **task-oriented**: follow prerequisites, run a procedure, inspect the outcome, and use troubleshooting when reality differs. If you need a conceptual explanation, start with [Core concepts](../concepts/README.md); if you need exact flags, consult the [Command reference](../command_reference.md).

| You need to… | Start here | Then inspect |
| --- | --- | --- |
| Bring up FlexSoC for the first time | [Quickstart](../quickstart.md) | [Command reference](../command_reference.md) |
| Develop and qualify an IP | [IP development guide](../ip_development_guide.md) | [Digital IP Contract](../digital_ip_contract.md) |
| Follow an ASIC-oriented flow | [ASIC flow](../flexsoc_asic_flow_guide.md) | [Architecture](../architecture.md) |
| Investigate a failed, missing, or stale run | [Read run results](reading-run-results.md) | [Evidence lifecycle](../concepts/evidence-lifecycle.md) |
| Investigate CDC or formal methodology | [Methodology index](../methodology/README.md) | [Traceability](../methodology/ip_traceability.md) |
| Extend FlexSoC | [Developer integration](../developer_integration_guide.md) | [System map](../architecture/system-map.md) |

New to the command interface? Start with [CLI essentials](../reference/cli-essentials.md), then use the full reference only when needed.

For pre-synthesis through physical sign-off, follow the [ASIC workflow navigator](asic-flow-navigation.md) to distinguish documented execution stages from the roadmap.

## Diagnose unexpected results

Use the [run-results investigation procedure](reading-run-results.md) for missing outputs, failed tools, stale provenance or unclear qualification. Its decision model is maintained there rather than repeated in this index.

## Guide quality convention

Future guides should provide: required workspace/configuration, exact supported command, expected outputs, a verification checkpoint, failure diagnosis, and links to underlying reference. Examples are not authoritative until checked against an actual toolchain.

## Decision guide

Start with [Choose and verify an engineering workflow](choose-a-workflow.md) if you know what changed but do not know which stage or evidence to inspect next.
