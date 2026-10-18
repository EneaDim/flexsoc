# GPIO — Technical Design Specification

**Document class:** TDS · **IP release:** 1.0.0 · **Status:** Engineering specification for qualification
**Upstream product contract:** [Customer Specification](customer.md) · **Derived obligations:** [Requirements](requirements.yaml) · **Verification allocation:** [Testplan](testplan.yaml)

## 1. Purpose and system boundary

The GPIO IP implements four digital channels, each with independently programmable output, output enable, synchronized input observation, optional input qualification, and interrupt-condition selection. Its externally visible digital signals are `cio_gpio_i[3:0]`, `cio_gpio_o[3:0]`, `cio_gpio_en_o[3:0]`, `intr_gpio_o[3:0]`, functional `clk_i` and active-low `rst_ni`.

The system owns physical pad cells, electrical characteristics, the input stimulus environment and the interrupt consumer. `tlul`, `reg_iface` and `axi_lite` are supported device-side CSR transports, qualified separately. Generated HJSON is authoritative for register offsets, widths and access policies.

## 2. Internal architecture

Each output and output-enable bit is retained as a software-programmed state. Each asynchronous input is synchronized and then optionally processed by a per-pin digital input filter to produce an *accepted* pin value. The accepted value is sampled for edge detection and used directly for level detection. Each pin's interrupt output ORs its individually enabled edge and level terms; this IP does not include a sticky interrupt-status register.

## 3. Detailed behavioral requirements

### TDS-001 — Output control, pad interface and reset

Customer refs: CRS-001

- The four-bit values in `DIRECT.GPIO_O` and `DIRECT.GPIO_OE` drive `cio_gpio_o` and `cio_gpio_en_o`, respectively.
- A valid corresponding software write updates each stored vector; absent a write strobe, its previous state is retained.
- Asserting active-low reset clears both stored vectors to zero. The subsequent output-enable state is therefore inactive until firmware configures it.
- `clk_i` is the single functional sampling clock. The pad-input synchronization path belongs to its reset family.

Allocated requirements: GPIO-RST-001, GPIO-OUT-001, GPIO-OE-001

### TDS-002 — Input sampling and readback

Customer refs: CRS-001

- `cio_gpio_i` is an asynchronous input and shall not be treated as a direct synchronous register value.
- Each input is passed through synchronization and optional filtering. `DATA_IN.GPIO_IN` exposes the accepted four-bit value, not the raw unsynchronized pad.
- Input behavior is sampled relative to `clk_i`; sub-cycle asynchronous pulses are not promised to be captured.

Allocated requirements: GPIO-IN-001

### TDS-003 — Programmable input filter

Customer refs: CRS-002

- `INTR_CTRL.EN_INPUT_FILTER` independently selects qualification for each input pin.
- The filter uses a four-bit stability/qualification counter with terminal value `0xF`. A short excursion is rejected and a sufficiently persistent state transition is eventually accepted.
- Disabling a pin's filter selects its synchronized value for normal observation; filtering of one pin shall not change any other pin's enable settings.
- The digital qualification interval is expressed in clocked samples, not a board-level debounce time in milliseconds.

Allocated requirements: GPIO-FILT-001

### TDS-004 — Edge-sensitive interrupt terms

Customer refs: CRS-003

- `EN_RISING` and `EN_FALLING` independently enable rising- and falling-edge interrupt conditions per pin.
- A rising term is asserted when consecutive accepted input samples transition 0→1; a falling term when they transition 1→0.
- The edge event relates to *accepted* values after synchronization/filtering, not raw asynchronous transitions; edge pulses are not specified as latched software state.

Allocated requirements: GPIO-INT-001, GPIO-INT-002

### TDS-005 — Level-sensitive interrupt terms and composition

Customer refs: CRS-003

- `EN_LVLHIGH` asserts the high-level term for an accepted one; `EN_LVLLOW` asserts the low-level term for an accepted zero.
- For every bit `i`, `intr_gpio_o[i]` is the OR of its enabled rising, falling, high and low terms. No cross-pin condition contributes.
- Level conditions can remain active while the selected level persists; the SoC interrupt consumer is responsible for any subsequent acknowledgement policy.

Allocated requirements: GPIO-INT-003, GPIO-INT-004

### TDS-006 — Transport-independent register semantics

Customer refs: CRS-004

- A register write/read has equivalent logical effect on `DIRECT`, `DATA_IN` and `INTR_CTRL` in all qualified `tlul`, `reg_iface` and `axi_lite` packages.
- CSR bit positions, field widths, access policies and reset values are defined only by the package HJSON/regmap.
- Transport-specific flow control and error signaling are separately verified at each adapter boundary.

Allocated requirements: GPIO-REG-001

## 4. Register and integration overview

| Register / field | Meaning |
|---|---|
| `DIRECT.GPIO_O` | Software output vector |
| `DIRECT.GPIO_OE` | Software output-enable vector |
| `DATA_IN.GPIO_IN` | Accepted synchronized / optionally filtered input |
| `INTR_CTRL.EN_INPUT_FILTER` | Per-pin filter selection |
| `EN_RISING`, `EN_FALLING` | Per-pin edge event enable |
| `EN_LVLHIGH`, `EN_LVLLOW` | Per-pin level event enable |

## 5. Verification and acceptance strategy

Directed RTL tests exercise reset, output hold and write operations, readback, qualification of short/stable input transitions, and level interrupts. Formal properties complement directed testing with edge detection and OR-equation invariants. Model checks cover selected accepted-level behavior but cannot prove synchronizer metastability handling or edge pulse timing. Record per-interface evidence for functional, lint, CDC/RDC and formal results rather than inferring it from testplan links.

Bounded post-synthesis GLS, where required by the release policy, exercises `smoke`, `interrupt_levels`, `input_filter` over `ss`, `tt`, `ff`. Post-PnR physical verification is not part of this TDS.

## 6. Limits, assumptions and changes

This is exactly four digital GPIOs and one functional clock. The SoC supplies clock/reset quality, pad buffers and protocol-correct CSR access. Open-drain, alternate-function multiplexing, drive-strength programming, persistent IRQ state, real-time debounce guarantees and pad-cell qualification are not promised. New behavior requires changes to this TDS, the matching requirements and testplan, followed by fresh evidence.
