#!/usr/bin/env python3
r"""
\file help_soc.py
\brief Print the project's HELP banner.
\details
  Minimal script that prints a help message for SoC integration:
    - FuseSoC init and IP fetching,
    - crossbar generation,
    - SoC build/sim/run/view targets.

  Coloring is automatic when stdout is a TTY. Set NO_COLOR to disable.
"""

import sys
from common import colorize  # shared color helper

HELP = """
*************************************************************

****************            HELP             ****************

*************************************************************

##################     SoC INTEGRATION     ##################

- CONFIG 
  • Check the memory mapping configuration for each IP in config.mk .

- FETCH IPs
  • Run "make fetch VENDOR=lowrisc_ip" and
    "make fetch VENDOR=lowrisc_ibex" to fetch IPs via the vendor mechanism.

- LOAD IPs
  • Run "make ip_load TOP={ip_name}" for each internal IP you need
    to load IPs via the vendor mechanism.

- XBAR
  • Run "make xbar" to define the crossbar using IBEX, RAM, UART, and your IP.
    Check the SOC_MEMORY_MAP variable in config.mk.
  • Under the hood it runs "make xbar_init" to initialize the HJSON description
    of the crossbar, and "make xbar_build" to generate the xbar .sv file.

- SoC BUILD
  • Run "make soc" to generate:
      -- SoC configuration file for FuseSoC.
      -- SoC wrapper in SystemVerilog.
      -- SoC top Verilator wrapper in SystemVerilog.
      -- SoC top Verilator wrapper in C++.

- SoC SIM
  • Run "make setup_tb TOP=soc" to setup a testbench.
  • Run "make sim view TOP=soc" to run the testbench.

- SoC SIM with IBEX
  • Run "make soc_sim" to run the simulation target with FuseSoC.

- SoC RUN with IBEX
  • Run "make soc_run" to compile sw/hello.c with GCC and start Verilator.

- SoC VIEW with IBEX
  • Run "make soc_view" to view the simulation waveforms with GTKWave.
"""

if __name__ == "__main__":
    sys.stdout.write(colorize(HELP))
