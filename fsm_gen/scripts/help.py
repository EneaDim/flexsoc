# Simply print HELP message
msg='\033[38;5;214m\n\
\n ************************************************************* \n\
\n *************************** HELP **************************** \n\
\n ************************************************************* \n\
\n - CONFIG\
\n   .Define the parameters under the Makefile\n\
\n - STATE TRANSITION\
\n   .Describe the state transition with a txt file as\
\n    done in the example under examples/\n\
\n - OUTPUT VALUES\
\n   .Describe the output values for each state with a csv file as\
\n    done in the example under examples/\n\
\n - GENERATE SV FILE\
\n   .Run "make gen" to generate the systemverilog file of the FSM\n\
\n - PLOT\
\n   .Run "make plot" to plot the FSM \n\
\033[0;0m'
print(msg)
