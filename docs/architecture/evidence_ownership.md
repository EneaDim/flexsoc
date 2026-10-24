# Qualification evidence ownership

`meta/<pdk>/evidence_integrity.json` schema 2 stores separate, sealed
inventories: `sources` maps paths to SHA-256 values; `generated` maps paths to
`{sha256, stage}`. This applies to RTL qualification and higher qualification
levels alike. Technology-level files under `syn/<pdk>`, `signoff/<pdk>`
and `impl/<pdk>` are covered by the same hash contract. It is independent of extensions, tool output names and PDKs.

Ownership is established from the generated entries of canonical lifecycle
provenance (`meta/provenance.json` and `meta/<pdk>/provenance.json`). Directory
entries cover their descendants. A file with no recorded producer is immutable by default. A generated
output may also be consumed by subsequent stages without losing its producer. RTL/CSR/constraints are
never downgraded by an output declaration.

Requalification checks **all** sealed inputs and requires previously sealed
outputs to exist. It permits changed outputs and new files only where their
producer is recorded. After writing a qualification report, the manifest is
resealed; subsequent `status`, load and package validation use exact hashes.
The existing source ownership survives resealing even if provenance changes.

Schema 1 packages are read conservatively. Their existing hash baseline is
retained; only outputs that are independently identifiable through available
lifecycle provenance may change. If a legacy package lacks such provenance,
FlexSoC refuses to guess ownership. Rebuild/requalify that release with proper
stage provenance rather than bypassing integrity or mutating its old manifest.

This manifest describes integrity, not stage success: freshness and outcomes
are still evaluated through the qualification policy and lifecycle provenance.
