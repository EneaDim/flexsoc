# Simply print HELP message
msg='\033[38;5;214m\n\
\n *************************************************************\n\
\n *************************** HELP ****************************\n\
\n *************************************************************\n\
\n - CONFIG\
\n   .Define the parameters under config.mk\n\
\n - SETUP\
\n   .Run "make setup" to setup the folder structure\
\n   .Write TOP?="top_name" parameter in the config.mk\
\n    file to properly set the TOP module\n\
\n - RTL CODING\
\n   .Write RTL in systemverilog under rtl/ folder\n\
\n - SV2V\
\n   .Run "make sv2v" to generate a single verilog file\
\n    from all files under rtl/\
\n   .Check for errors\n\
\n - LINTING\
\n   .Run "make lint" perform the linting\
\n   .Check for errors\n\
\n - TESTBENCH SETUP\
\n   .Run "make setup_vtb" to setup the verilog testbench\
\n    The verilog module generate by "sv2v" will be included\
\n    in the testbench\n\
\n - COMPILE\
\n   .Run "make compile" to compile the testbench and the top\
\n   .Check for errors\n\
\n - SIMULATION RUN\
\n   .Run "make sim" to run the verilog testbench\n\
\n - SIMULATION VIEW\
\n   .Run "make view" to view the simulation waveforms\n\
\n - TESTBENCH UPDATE\
\n   .Its time to update the testbench to trigger and\
\n    check what you want\n\
\n - VIEW PRE-SYN with YOSYS\
\n   .Run "make view_presyn" to view the graph that\
\n    describes the design you wrote\n\
\n - SYNTHESIS\
\n   .Run "make syn" to check if the design can be\
\n    synthetized correctly\n\
\n - SDF\
\n   .Run "make sdf" to generate sdf files\n\
\n - STATIC TIMING ANALYSIS\
\n   .Run "make sdf" to perform basic static timing\
\n    analysis with OpenSTA \n\
\n - PATH VIEW\
\n   .Run "make path view" to generate the paths netlist svg\
\n    files from STA output to take a look on them \n\
\n - POWER ANALYSIS\
\n   .Run "make power" to perform basic static power\
\n    analysis and vcd-based power analysis with OpenSTA\n\
\n - SYNTHESIS SIMULATION RUN\
\n   .Run "make sim_syn" to run the verilog testbench\n\
\n - SYNTHESIS SIMULATION VIEW\
\n   .Run "make view_syn" to view the simulation waveforms\n\
\n - REGRESSION\
\n   .Run "make regression" to run all testbench simulation you created\n\
\033[0;0m'
print(msg)
