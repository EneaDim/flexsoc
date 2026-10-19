# Workspace & Patches

- Use isolated run workspaces; keep completed runs as immutable evidence.
- Validate changes before distribution; patches should support check, apply, and verify, be idempotent, and create no parallel backups.
- Use Git for rollback and selective commits; never rewrite simulator reports to manufacture a passing result.
