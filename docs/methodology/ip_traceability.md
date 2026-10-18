# IP specifications and executable traceability

## 1. Normative document chain

Every new IP (and subsequently every SoC package) is expressed as a forward engineering contract:

```text
spec/customer.md        Customer / Product Specification (CRS)
       ↓
spec/ip.md              Technical Design Specification (TDS)
       ↓
spec/requirements.yaml  Atomic architectural and technical obligations
       ↓
spec/testplan.yaml      Verification intent and planned scenarios
       ↓
model tests / RTL tests / formal properties
       ↓
actual execution evidence and qualification
```

`customer.md` is a **complete, self-contained product document**: business need, boundaries, use cases, numbered `CRS-nnn` requirements, acceptance expectations, exclusions, assumptions and approval state. It shall use a product/customer voice, not describe how the draft was discovered. A draft remains explicitly *pending stakeholder approval* until genuine approval exists; generated wording does not establish customer sign-off.

`ip.md` is a **complete, self-contained engineering document**: architecture, interfaces, software-visible behavior, reset and clock assumptions, timing/functional contracts, edge cases, exclusions and verification strategy. Its numbered `TDS-nnn` sections contain the normative technical detail, not just a short appendix duplicating other sections. Each TDS section has `Customer refs: CRS-nnn`. For a SoC the analogous document is `soc.md` under its owning package.

`requirements.yaml` is the single source of truth for atomic implementation obligations, each with stable ID, `category` (`architectural` or `technical`), `spec_refs` to TDS, statement, scope and status. The project retains YAML; it does **not** create parallel `requirements.json` files. `testplan.yaml` is the source of truth for requirements → testplan items → RTL scenarios (`tests`), formal properties (`properties`) and model checks (`model_cases`). It may evolve incrementally as a verification plan matures, while its omissions remain visible rather than being treated as passed tests.

The IP owns `<ip>_model.py`, `<ip>_tests.py`, the generated register API, and their vectors. Independent `<ip>_model_tests.py` checks exercise abstract model semantics using known answers and invariants, not results calculated by the same model. Scenario IDs are shared for traceability, but a model check does not prove pin-level RTL timing or handshake behavior. The traceability matrices are *generated views*, never separately authored normative files.

## 2. Workflow and gates

1. Draft `customer.md` and obtain product review/approval if applicable.
2. Allocate every customer intent to one or more fully specified `TDS-nnn` sections in `ip.md`.
3. Derive architectural and technical requirements from the TDS; assign stable IDs.
4. Allocate requirements to testplan items, verification methods and scenario IDs. Include planned checks even before their tests exist, distinguishing coverage intent from measured coverage.
5. Implement independent model tests and RTL/formal tests in the owning package; execute them and retain their actual results.
6. Generate both directions of traceability and evaluate qualification against recorded evidence for the specific configuration and toolchain.
7. Freeze the package only after required gates pass. A change to normative specifications invalidates earlier evidence fingerprints and requires reassessment.

The same artifacts support a new project progressing in this order or a legacy baseline being documented. **The normative documents describe the intended product and engineering contract, not the discovery procedure.** Only authentic customer approval or actual test execution may be claimed.

## 3. Commands and evidence

Run `fx trace hw/ips/<ip>/1.0.0 --set REG_ITF=tlul --json` to validate CRS↔TDS↔requirements↔testplan↔RTL/model links and produce both matrix directions. `MAPPED_NOT_EXECUTED` means links exist; it does **not** mean verification has passed.

Run `fx mtest hw/ips/<ip>/1.0.0 --set REG_ITF=tlul` to execute independent model checks through `CommandRequest → ToolRunner → Executor`. JUnit and `summary.json` are recorded in `<workspace>/model_tests/<ip>/<interface>/` for explicit package sources, or under a loaded run's `dv/functional/model_tests/`. The model result is only reused if source/spec fingerprints match; otherwise it is `STALE`. RTL regression results remain in `dv/functional/regression/summary.json`.

A customer statement can map to multiple technical clauses; a technical clause may satisfy multiple customer intents; a requirement can be covered by multiple testplan items. No manually maintained reverse mapping is permitted. The UART Master `UM-RESP-001` reply-format behavior remains **planned**, regardless of whether its standalone Python encoder passes: full RTL serial response verification is a separate acceptance gate.

## 4. Compatibility and release provenance

For older IP releases, `customer.md` may be absent: the validator records `NOT_CONFIGURED` rather than inventing a product requirement. When the file is present, it must be valid, is included in the package fingerprint and is frozen by release save. Updating normative documents for an existing release changes its contract fingerprint; the prior release evidence must not be silently reused. Generated matrices and reports do not authorize a release by themselves.

## Functional scenario contract

The IP owns `dv/functional/py/` containing its reference model, generated
CSR API, semantic `scenarios.py`, model checks (`<ip>_model_tests.py`),
and RTL vector generators (`<ip>_tests.py` and `<ip>_regmap_tests.py`).
The shared scenario ID/semantic configuration is the single test intent; model
execution uses functional parameters, RTL execution translates them into
register writes via the HJSON-generated API. Register transport, cycle-level
timing and firmware remain separate execution concerns.

`dv/functional/tests/` contains generated RTL vectors; stage results are
`model_tests/summary.json`, `regression/summary.json`, and
`coverage/summary.json`. `functional/summary.json` is an index only.
Runtime command logs are written under `logs/dv/functional/`. Scenarios and
model assertions are authored, never overwritten by setup. New scaffolds
start with skipped model checks until independent expected values are authored.
Explicit package-source model checks use `workspace/model_tests/<ip>/<interface>`
rather than modifying a frozen release.

## Requalification of an edited IP package

A frozen `1.0.0` interface release is validated strictly by normal `fx ip_load`.
Changing any normative specification invalidates that frozen specification fingerprint.
**Never repair this mismatch by editing the old `meta/contract.json` or replaying its
qualification reports.** For an explicitly new run, `fx ip_load --force` validates
the package identity and pinned RTL/CSR/constraint/formal source hashes, then stages
the *current* specification and authored sources without importing previously
frozen lint, CDC/RDC, formal, regression, synthesis, signoff or qualification
evidence. The loaded baseline is **UNQUALIFIED**; a fresh RTL filelist and all
required EDA stages must be regenerated and run. The same run cannot be force-loaded
a second time, to prevent silent overwrites. Normal `fx ip_load` remains strict.

Run `fx trace` and `fx mtest` without an explicit package path
after loading to use the run-local specification and Python sources. Model PASS
is not RTL PASS. `fx qualify --set QUAL_LEVEL=rtl` must reject missing, stale or
failing EDA evidence. Publication/versioning is a separate step performed only
after new qualification evidence has been collected.

## CLI model-test lifecycle

`fx model --setup` scaffolds the model and DV Python sources. On a loaded IP run,
`fx mtest --setup` creates only missing `scenarios.py` and `<ip>_model_tests.py`;
existing authored files are never overwritten (including with `--force`, which is
rejected). Edit them, then run `fx mtest`. Use `fx mtest --summary` for the compact
result, `fx mtest --show` for per-case links, and `fx mtest --check` to require
current, passing source/spec evidence without executing pytest. `STALE` requires
rerunning the tests; it must not be accepted as a valid result.

`fx trace --summary`, `fx trace --show` and `fx trace --json` are read-only views
of the same traceability contract. `fx validate --set STAGE=syn.setup` is a shorter
name for accepting intentional manual modifications of *generated setup* files
with unchanged inputs. It does not validate stale evidence or stale input lineage.
