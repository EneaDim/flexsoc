# FlexSoC test suite

The test tree is organized by responsibility so that focused checks remain easy to run while shared pytest configuration stays centralized.

```text
tests/
├── conftest.py
├── README.md
├── core/
│   └── test_effective_design_settings.py
├── regression/
│   └── test_api.py
├── soc/
│   ├── native/
│   │   ├── test_lint.py
│   │   ├── test_package_ownership.py
│   │   ├── test_prim_contract.py
│   │   ├── test_primitive_ownership.py
│   │   ├── test_rtl_closure.py
│   │   ├── test_sources.py
│   │   ├── test_stale_prim_cleanup.py
│   │   └── test_verilator.py
│   ├── test_m1_dependency_ownership.py
│   ├── test_m1_uart.py
│   ├── test_memory_layout.py
│   ├── test_release_contract.py
│   ├── test_sim_freshness.py
│   └── test_uart_smoke.py
├── fixtures/
│   └── soc/
│       ├── cpu_test_template/
│       ├── smoke/
│       ├── boot_smoke/
│       └── uart_smoke/
├── e2e/
│   └── test_fx.py
└── flows/
    └── flexsoc_ip_flow.sh
```

## Ownership

- `core/` contains focused tests for framework-wide contracts that are not owned by a specific design flow.
- `regression/` contains the broad historical API/backend regression suite. Keep this suite stable; split it only when a responsibility has a clear owner and the move is behavior-neutral.
- `soc/` contains SoC-specific contracts. `soc/native/` is limited to native source-closure, package-ownership, primitive, lint, and Verilator contracts.
- `fixtures/soc/` contains development-only SoC test collateral that can be copied explicitly into a run workspace; FlexSoC production code never stages these fixtures.
- `e2e/` contains tests that launch real `fx` commands and external tool flows. These are marked with `@pytest.mark.e2e` where appropriate and are not equivalent to unit/regression tests.
- `flows/` contains manually sourced qualification helpers. Files here are support scripts, not pytest modules.
- `conftest.py` stays at the root so shared CLI options and fixtures are visible to every subtree.

The directories intentionally do not contain `__init__.py`: the hierarchy is organizational, not a Python package API. Tests should import production code from `flexsoc`, not other test modules. Shared fixtures belong in the nearest common `conftest.py` only when actual reuse justifies them.

## Common commands

Run the normal test suite:

```bash
uv run pytest -q
```

Run the broad regression suite:

```bash
uv run pytest -q tests/regression/test_api.py
```

Run focused SoC tests:

```bash
uv run pytest -q tests/soc
uv run pytest -q tests/soc/native
```

Collect the E2E suite without executing external flows:

```bash
uv run pytest --collect-only -q tests/e2e/test_fx.py
```

Run E2E explicitly, for example:

```bash
uv run pytest -s tests/e2e/test_fx.py --e2e-mode formal
```

Source the reusable IP qualification helper from the repository root:

```bash
source tests/flows/flexsoc_ip_flow.sh
```

## Rules for new tests

Place a test under the smallest directory that owns the behavior. Prefer a focused file over adding unrelated cases to `regression/test_api.py`. Do not create a parallel test framework or duplicate production orchestration inside fixtures. Real EDA/tool execution belongs in `e2e/`; contract tests should use controlled runners/fakes and must not claim EDA PASS.

## SoC functional fixtures

Functional tests are workspace/package-owned. SoC functional DV mirrors the IP layout: one editable Python catalogue can define many scenarios, while each generated test directory owns its real firmware and optional testbench hooks.

```text
dv/functional/
├── model/
│   └── tests.py
└── tests/
    └── <name>/
        ├── config.regs
        ├── data_in.vec
        ├── data_out.vec
        └── sw/
```

`model/tests.py` generates only `config.regs`, `data_in.vec`, and `data_out.vec`. Firmware remains normal C/assembly under `tests/<name>/sw/`; the test Makefile owns any number of `.c`/`.h` sources. Test-specific SystemVerilog hooks are not part of the contract: synchronization and observation use the shared vector engine.

For development, copy a complete fixture into the active run explicitly:

```bash
RUN="$HOME/flexsoc-workspace/runs/soc/dev"
cp -a tests/fixtures/soc/uart/. "$RUN/dv/functional/"
fx test_gen --workdir "$HOME/flexsoc-workspace" --set TEST_NAME=uart_smoke
```

`fx tests_gen` materializes every scenario declared by the local catalogue; `fx test_gen --set TEST_NAME=<name>` materializes only that test; `fx tests_gen --check` detects stale generated vector collateral. Existing IPs keep using their established `<top>_tests.py` catalogues.

For CPU-driven synchronization, both cycle-vector interpreters support `<cycle> @wait_event <label> <value> [timeout]` and `<cycle> @wait_signal <signal> <value> [timeout]`. Each barrier starts a new cycle-relative phase, so stimulus and checks can synchronize to firmware and externally observable effects without guessing CPU latency. SystemVerilog and cocotb consume the same contract. Precise absolute-cycle checks remain available where timing itself is the behavior under test. Start a new SoC catalogue from `tests/fixtures/soc/cpu_functional_template/`; `tests/fixtures/soc/uart/` is the concrete RX/event/echo example.
