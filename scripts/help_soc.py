# Simply print HELP message
msg='\033[38;5;214m\n\
\n *************************************************************\n\
\n *************************** HELP ****************************\n\
\n *************************************************************\n\n\
\n ********************* SoC INTEGRATION ***********************\n\
\n - FUSESOC\
\n   .Run "make fsoc_init" to initialize .core file for your IP\n\
\n - FETCH\
\n   .Run "make fetch VENDOR=lowrisc_ip" and "make fetch VENDOR=lowrisc_ibex"\
\n    to fetch IPs using vendor functionality\n\
\n - XBAR\
\n   .Run "make xbar" to define the crossbar using IBEX, RAM, UART, and your IP.\
\n    Check variable SOC_MEMORY_MAP  in config.mk\n\
\n   .Under the hood is running "make xbar_init" for initializing hjson description\n\
\n    of the xbar, and "make xbar_build" t generate the xbar .sv file\n\
\n - SoC BUILD\
\n   .Run "make soc_build" to generate:\
\n        --  SoC configuration file for FuseSoC.\
\n        --  SoC wrapper in SystemVerilog.\
\n        --  SoC top verilator wrapper in SystemVerilog.\
\n        --  SoC top verilator wrapper in C++.\n\
\n - SoC SIM\
\n   .Run "make soc_sim" to run simulation target with FuseSoC\n\
\n - SoC RUN\
\n   .Run "make soc_run" to run  GCC compilation of sw/hello.c and\
\n    start verilator sim.\n\
\n - SoC VIEW\
\n   .Run "make soc_view" to view the simulation waveforms with gtkwave.\n\
\033[0;0m'
print(msg)
