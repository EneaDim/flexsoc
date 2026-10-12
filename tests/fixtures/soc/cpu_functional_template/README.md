# CPU-driven SoC functional-DV template

Copy this directory as a complete `dv/functional/` seed. The layout deliberately mirrors IP functional DV: one Python catalogue owns many generated vector scenarios, while firmware remains real C/assembly source inside each test.

```text
model/
└── tests.py
tests/
└── smoke/
    ├── config.regs
    ├── data_in.vec
    ├── data_out.vec
    ├── sw/
    └── tb/
```

- `model/tests.py` is the editable Python scenario catalogue for all tests. It generates only `config.regs`, `data_in.vec`, and `data_out.vec`.
- `tests/<name>/sw/` contains real firmware sources; Python never embeds C. Add `.c`/`.h` files normally and let that test's Makefile build them.
- `<cycle> @wait_event <label> <value> [timeout]` waits for a design-owned firmware event and starts a new cycle-relative phase.
- `<cycle> @wait_signal <signal> <value> [timeout]` synchronizes to an observable signal and starts a new cycle-relative phase.
- The same vector synchronization contract is consumed by generated SystemVerilog and cocotb testbenches; no per-test TB source is required.

Use `fx test_gen --set TEST_NAME=<name>` after editing `model/tests.py`; use `fx tests_gen --check` to detect stale generated vector collateral.
