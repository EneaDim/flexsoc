# Coding Guidelines

- Prefer fully object-oriented code with one meaningful responsibility per class.
- Keep code, files, and abstraction layers to the minimum needed for correct, complete behavior.
- Avoid speculative factories, wrappers, duplicated state, and premature generalization.
- Keep backend interfaces protocol-agnostic; implement protocol-specific behavior inside the IP package.
- Use readable names, explicit dependencies, and modern SystemVerilog; reuse shared primitives without copying them.
- Extend existing verification suites when possible; do not commit generated caches, logs, or fix-specific test clutter.
