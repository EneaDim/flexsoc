# SPDX-FileCopyrightText: © 2024 Tiny Tapeout
# SPDX-License-Identifier: Apache-2.0
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, FallingEdge, Timer
from cocotb.handle import Immediate

# ----- UART helpers -----
baud = 115_200
bit_time_ps = int(round(1e12 / baud))  # ~8_680_555 ps @115200

# shadow del pin RX (1 bit). Evita read-modify-write su 'Z'/'X'.
_rx_shadow = 1  # idle alto

async def _set_rx_bit(dut, bit_val: int):
    global _rx_shadow
    _rx_shadow = 1 if bit_val else 0
    dut.cio_rx_i.value = _rx_shadow
    await Timer(bit_time_ps, unit="ps")

async def uart_send_byte(dut, byte: int):
    # start
    await _set_rx_bit(dut, 0)
    # data LSB-first
    for i in range(8):
        await _set_rx_bit(dut, (byte >> i) & 1)
    # stop
    await _set_rx_bit(dut, 1)

async def uart_send_word32(dut, word: int):
    for sh in (0, 8, 16, 24):
        await uart_send_byte(dut, (word >> sh) & 0xFF)

async def uart_write32(dut, addr: int, data: int, be: int):
    # A5 | 01 | 01(WRITE) | {0000,BE} | ADDR(4B LSB-first) | DATA(4B LSB-first)
    await uart_send_byte(dut, 0xA5)
    await uart_send_byte(dut, 0x01)
    await uart_send_byte(dut, 0x01)
    await uart_send_byte(dut, ((be & 0xF) | 0x00) & 0xFF)
    await uart_send_word32(dut, addr)
    await uart_send_word32(dut, data)

async def uart_read32(dut, addr: int):
    # A5 | 01 | 00(READ) | 0x0F | 00 | ADDR(4B LSB-first)
    await uart_send_byte(dut, 0xA5)
    await uart_send_byte(dut, 0x01)
    await uart_send_byte(dut, 0x00)
    await uart_send_byte(dut, 0x0F)
    await uart_send_byte(dut, 0x00)
    await uart_send_word32(dut, addr)

@cocotb.test()
async def test_uart_program_soc(dut):
    # ---- init IOs (nessuna lettura: valori definiti subito) ----
    dut.rst_ni.value    = 0
    dut.cio_gpio_i.value = 0
    dut.cio_rx_i.value = Immediate(1)

    dut.clk_i.value    = Immediate(0)
    await Timer(10, unit="ns")

    # CLK
    cocotb.start_soon(Clock(dut.clk_i, 20, unit="ns").start())

    await ClockCycles(dut.clk_i, 10)
    await FallingEdge(dut.clk_i)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 10)
    await FallingEdge(dut.clk_i)
    dut.rst_ni.value = 0
    await ClockCycles(dut.clk_i, 10)
    await FallingEdge(dut.clk_i)
    dut.rst_ni.value = 1

    # ---- indirizzi di esempio (adatta ai tuoi reali) ----
    UART_BASE     = 0x8000_0000
    PWM_BASE      = 0x8002_0000
    PWM_EN_OFF    = 0x0000_0008
    PWM_CFG_OFF   = 0x0000_0004
    PWM_PHASE_OFF = 0x0000_0010
    UART_CTRL_OFF = 0x0000_0010

    # 1) abilita UART TX/RX (placeholder)
    await uart_write32(dut, UART_BASE + UART_CTRL_OFF, 0x0970_0001, be=0xF)

    # 2) configura PWM (placeholder valori)
    await uart_write32(dut, PWM_BASE + PWM_CFG_OFF,   0xB800_0010, be=0xF)
    await uart_write32(dut, PWM_BASE + PWM_PHASE_OFF, 0x0000_7FFF, be=0xF)
    await uart_write32(dut, PWM_BASE + PWM_EN_OFF,    0x0000_0001, be=0xF)

    # attesa per propagazione
    await ClockCycles(dut.clk_i, 1000)

    # lascia RX in idle alto
    dut.cio_rx_i.value = 1

    # attesa extra
    await ClockCycles(dut.clk_i, 10000)

