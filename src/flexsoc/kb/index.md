# FlexSoC Knowledge Base (`kb`)

Knowledge e future skill operative per agenti che utilizzano FlexSoC lungo la pipeline IP/SoC.

## Organizzazione

Ogni dominio numerato segue il flusso di lavoro e contiene un `index.md`; le sottocartelle delimitano argomenti specifici. Gli index descrivono il **perimetro**, non pretendono di essere guide complete.

- **Knowledge**: principi, criteri, contratti ed evidenze.
- **Skills**: procedure eseguibili o riutilizzabili, da aggiungere solo quando sono stabili; eventuale `skill.md` nella cartella pertinente.
- **Sub-agent futuri**: potranno ricevere un dominio o una selezione di skill, senza dipendere da nomi o logica hardcoded nel backend.

## Domini

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

## Regole trasversali

L’ordine dei domini rappresenta le fasi prevalenti, non un grafo rigido: architettura, requirements, test, RTL, vincoli ed evidenze si raffinano iterativamente. Un test non eseguito non è un PASS; una deroga non equivale a un signoff completato.
