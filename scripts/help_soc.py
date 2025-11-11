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

- FUSESOC
  • Run "make fsoc_init" to initialize the .core file for your IP.

- FETCH
  • Run "make fetch VENDOR=lowrisc_ip" and
    "make fetch VENDOR=lowrisc_ibex" to fetch IPs via the vendor mechanism.

- XBAR
  • Run "make xbar" to define the crossbar using IBEX, RAM, UART, and your IP.
    Check the SOC_MEMORY_MAP variable in config.mk.
  • Under the hood it runs "make xbar_init" to initialize the HJSON description
    of the crossbar, and "make xbar_build" to generate the xbar .sv file.

- SoC BUILD
  • Run "make soc_build" to generate:
      -- SoC configuration file for FuseSoC.
      -- SoC wrapper in SystemVerilog.
      -- SoC top Verilator wrapper in SystemVerilog.
      -- SoC top Verilator wrapper in C++.

- SoC SIM
  • Run "make soc_sim" to run the simulation target with FuseSoC.

- SoC RUN
  • Run "make soc_run" to compile sw/hello.c with GCC and start Verilator.

- SoC VIEW
  • Run "make soc_view" to view the simulation waveforms with GTKWave.
"""

if __name__ == "__main__":
    sys.stdout.write(colorize(HELP))
