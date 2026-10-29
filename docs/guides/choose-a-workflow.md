# Choose and verify an engineering workflow

**Purpose:** decide what to execute and what to inspect after a hardware or configuration change. This is a decision guide, not a replacement for tool-specific commands.

## Before you start

Confirm the design top, the selected project/run, source and constraint versions, available EDA tools, and the output directory. See the [quickstart](../quickstart.md) for environment setup and the [command reference](../command_reference.md) for exact syntax.

## Decide what needs new evidence

```mermaid
flowchart TD
    A([Something changed]) --> B{What changed?}
    B -->|RTL or hierarchy| C[Review lint, elaboration, DV and downstream consumers]
    B -->|Clock, reset or timing intent| D[Review CDC/RDC, timing constraints and affected downstream stages]
    B -->|Register map or interface| E[Review generated collateral, integration tests and interface contracts]
    B -->|Requirement, testplan or Python model| F[Review traceability, model tests and affected RTL vectors]
    B -->|Only docs| G[Validate documentation links and examples]
    C --> H[Inspect dependencies and freshness]
    D --> H
    E --> H
    F --> H
    G --> I([Finish when docs checks pass])
    H --> J{Required evidence current?}
    J -->|No or unknown| K[Select affected stage in CLI reference]
    J -->|Yes| L[Inspect result and qualification obligations]
    K --> M[Execute, inspect logs and artifacts]
    M --> L
    L --> N([Record outcome and remaining obligations])
```

This is a conservative *investigation heuristic*, not a complete or automatic invalidation dependency graph. Use the actual [project lifecycle](../project_lifecycle.md) to determine stage dependencies. For changed requirements or model expectations, check `fx trace`, then execute `fx mtest` and/or `fx tests_gen` plus RTL regression as the impact requires. Model PASS never replaces RTL evidence.

## Follow the evidence, not just the exit code

```mermaid
sequenceDiagram
    autonumber
    actor Engineer
    participant Config as Project inputs
    participant CLI as FlexSoC CLI
    participant EDA as Tool backend
    participant Results as Evidence and logs
    Engineer->>Config: Inspect design and selected run
    Engineer->>CLI: Choose target from verified reference
    CLI->>EDA: Invoke configured stage
    EDA-->>CLI: Outcome and outputs
    CLI-->>Results: Stage result and provenance (if supported)
    Engineer->>Results: Inspect logs, artifacts, freshness
    alt Evidence is missing or stale
        Engineer->>CLI: Investigate dependencies and rerun as needed
    else Evidence is current
        Engineer->>Results: Review coverage and qualification criteria
    end
```

This sequence is explanatory; stage implementations vary. Check exact output behavior in the backend and command reference.

## Checklist

- [ ] I identified the authored inputs and run configuration.
- [ ] I checked the **installed** `fx` interface rather than guessing command flags.
- [ ] I identified which stage results may depend on the changed input.
- [ ] I inspected the original tool log and output artifacts.
- [ ] I checked provenance/freshness independently from PASS/FAIL.
- [ ] I recorded missing evidence, remaining risks and next steps.

For diagnosis use [Reading run results](reading-run-results.md); for specific failure classes use the [failure-driven command playbook](../command_reference.md#8-failure-driven-command-playbook).
