# Workspace & Patches

- Lavorare su run isolati; trattare i risultati di run precedenti come evidenze immutabili.
- Per modifiche condivise, preparare patch verificabili e idempotenti (`check`, `apply`, `verify`), senza backup paralleli: Git gestisce il rollback.
- Separare sorgenti versionati, workspace generati e artefatti temporanei. Non committare `__pycache__`, `.pyc`, log o risultati non richiesti.
- Eseguire controlli reali prima di dichiarare una modifica completa; non riscrivere report per simulare un PASS.
