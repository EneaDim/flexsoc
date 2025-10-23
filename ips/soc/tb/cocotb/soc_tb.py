# SPDX-FileCopyrightText: © 2024 Tiny Tapeout
# SPDX-License-Identifier: Apache-2.0
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, Timer

# ----- UART helpers -----
baud = 115_200
bit_time_ps = int(round(1e12 / baud))  # ~ 8_680_555 ps
# helper che usa i PS interi
async def uart_send_bit(dut, bit_val):
    # RX idles high su cio_rx_i[0]
    curr = int(dut.cio_rx_i.value)
    if bit_val:
        dut.cio_rx_i.value = curr | 0x1
    else:
        dut.cio_rx_i.value = curr & ~0x1
    await Timer(bit_time_ps, unit="ps")

async def uart_send_byte(dut, byte):
    await uart_send_bit(dut, 0)  # start
    for i in range(8):           # data LSB-first
        await uart_send_bit(dut, (byte >> i) & 1)
    await uart_send_bit(dut, 1)  # stop

async def uart_send_word32(dut, word):
    for sh in (0, 8, 16, 24):
        await uart_send_byte(dut, (word >> sh) & 0xFF)

async def uart_write32(dut, addr, data, be):
    # A5 | 01 | 01(WRITE) | {0000,BE} | ADDR(4B LSB-first) | DATA(4B LSB-first)
    await uart_send_byte(dut, 0xA5)
    await uart_send_byte(dut, 0x01)
    await uart_send_byte(dut, 0x01)
    await uart_send_byte(dut, ((be & 0xF) | 0x00) & 0xFF)
    await uart_send_word32(dut, addr)
    await uart_send_word32(dut, data)

async def uart_read32(dut, addr):
    # A5 | 01 | 00(READ) | 0x0F | 00 | ADDR(4B LSB-first)
    await uart_send_byte(dut, 0xA5)
    await uart_send_byte(dut, 0x01)
    await uart_send_byte(dut, 0x00)
    await uart_send_byte(dut, 0x0F)
    await uart_send_byte(dut, 0x00)
    await uart_send_word32(dut, addr)

@cocotb.test()
async def test_uart_program_soc(dut):
    # ---- clock 10ns (100 MHz) – adatta se serve ----
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())

    # ---- init IOs ----
    dut.rst_ni.value = 0
    # cio_rx_i[0] = RX idle (1). Conserva gli altri bit di cio_rx_i.
    dut.cio_rx_i.value = int(dut.cio_rx_i.value) | 0x01
    dut.cio_gpio_i.value = 0
    dut.spi_sdio_i.value = 0

    await ClockCycles(dut.clk_i, 10)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 5)

    # ---- UART timing ----
    baud = 115_200  # cambia se vuoi
    bit_time_ns = 1e9 / baud  # ~8680 ns per 115200

    # ---- indirizzi di esempio: ADATTALI ai tuoi reali ----
    UART_BASE   = 0x8000_0000
    PWM_BASE    = 0x8002_0000
    PWM_EN_OFF    = 0x0000_0008
    PWM_CFG_OFF   = 0x0000_0004
    PWM_PHASE_OFF = 0x0000_0010
    UART_CTRL_OFF = 0x0000_0010

    # 1) abilita UART TX (e RX) via write al CTRL (placeholder)
    await uart_write32(dut, UART_BASE + UART_CTRL_OFF, 0x0000_0001, be=0xF)

    # 2) configura PWM (placeholder valori)
    await uart_write32(dut, PWM_BASE + PWM_CFG_OFF,   0xB800_0010, be=0xF)
    await uart_write32(dut, PWM_BASE + PWM_PHASE_OFF, 0x0000_7FFF, be=0xF)
    await uart_write32(dut, PWM_BASE + PWM_EN_OFF,    0x0000_0001, be=0xF)

    # attesa per propagazione
    await ClockCycles(dut.clk_i, 1000)

    # ---- check basilari su uscite wrapper ----

    # lascia RX in idle alto
    dut.cio_rx_i.value = int(dut.cio_rx_i.value) | 0x01

    # attesa per propagazione
    await ClockCycles(dut.clk_i, 10000)

