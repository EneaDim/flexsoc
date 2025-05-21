# Copyright 2025 Enea Dimroci
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import sys
import os
import argparse

# ARGUMENT PARSING
try:
    ap = argparse.ArgumentParser()
    ap.add_argument("-top", "--top", type=str, required='True', 
    help="Define the TOP module in the design")
    ap.add_argument("-topdir", "--topdir", type=str, required='True', 
    help="Define the TOP module directory in the design")
    ap.add_argument("-target", "--target", type=str, required='True', 
    help="Define if target is ASIC or FPGA")
    ap.add_argument("-liberty", "--liberty", type=str, required='True', 
    help="Link the liberty file of the technology used")
    ap.add_argument("-clk", "--clk", type=int, required='True', 
    help="Define the target optimization: area/delay")
    ap.add_argument("-sdcdir", "--sdcdir", type=str, required='False', 
    help="SDC file directory")
    ap.add_argument("-opt", "--opt", type=str, required='True', 
    help="Define the target optimization: area/delay")
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    top = args.get("top")
    topdir = args.get("topdir")
    target = args.get("target")
    liberty = args.get("liberty")
    sdcdir = args.get("sdcdir")
    clk_period = args.get("clk")
    opt = args.get("opt")
    output_folder = args.get("output")
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

try:
    # Define the output folder
    if output_folder:
        path = './' + output_folder + '/'
    else:
        path = './'
    # Open the file
    if target == 'asic':
        if opt == 'area':
            with open(path+'area.abc', 'w') as f:
                mystr = 'strash;                   # Convert logic network to a structurally hashed AIG (two-input AND + inverters)\n'
                mystr += '\n'
                mystr += '# Phase 1: Iterative logic optimization for structural sharing\n'
                mystr += 'balance;                  # Balance logic to minimize depth and enable restructuring\n'
                mystr += 'rewrite -l;               # Area-oriented rewriting (local)\n'
                mystr += 'rewrite -z -l;            # Zero-cost area rewriting to explore additional sharing\n'
                mystr += 'balance -l;               # Rebalance to clean up structure\n'
                mystr += 'refactor -l;              # Extract common logic using factored forms\n'
                mystr += 'resub -K 6 -l;            # Substitution using 6-input cuts\n'
                mystr += 'resub -K 6 -N 2 -l;       # Deep substitution with up to 2 tries\n'
                mystr += 'rewrite -l;               # Rewriting again to optimize after resubstitution\n'
                mystr += 'refactor -z -l;           # Zero-cost refactor for more aggressive sharing\n'
                mystr += 'resub -K 8 -N 2 -l;       # Larger cut-based substitution\n'
                mystr += 'rewrite -z -l;            # Final structural simplification pass\n'
                mystr += '\n'
                mystr += '# Phase 2: Technology mapping with area priority\n'
                mystr += 'map -a;                   # Map with area recovery (standard-cell mapping using gain-based algorithm)\n'
                mystr += '\n'
                mystr += 'topo;                     # Topological sort and cleanup\n'
                mystr += 'dnsize -c;                # Safely downsize gates if timing allows\n'
                mystr += 'stime -p;                 # Print delay metrics\n'
                mystr += 'print_stats -m;           # Area and delay stats\n'
                
                f.write(mystr)
        elif opt == 'delay':
            with open(path+'delay.abc', 'w') as f:
                mystr = 'strash;                # Convert logic network to structurally hashed AIG (canonical form)\n'
                mystr += '\n'
                mystr += '# Phase 1: Logic Restructuring and Depth Minimization (AIG Level)\n'
                mystr += 'balance;               # Balance logic levels for initial depth reduction\n'
                mystr += 'rewrite;               # DAG-aware rewriting to reduce AIG depth and size\n'
                mystr += 'refactor;              # Logic cone restructuring for better sharing\n'
                mystr += 'balance;               # Rebalance after refactoring\n'
                mystr += 'rewrite;               # Repeat rewriting to optimize reshaped structure\n'
                mystr += 'rewrite -z;            # Zero-cost rewrite to explore more equivalent forms\n'
                mystr += 'balance;               # Further depth balancing\n'
                mystr += 'refactor -z;           # Zero-cost refactoring to enable new optimizations\n'
                mystr += 'rewrite -z;            # Final zero-cost rewrite pass\n'
                mystr += 'balance;               # Final AIG-level balance before mapping\n'
                mystr += '\n'
                mystr += '# Phase 2: Initial Mapping and Retiming\n'
                mystr += 'map;                   # Perform delay-optimal standard cell mapping\n'
                mystr += 'retime -D 10;          # Aggressively retime to meet a 10-unit delay constraint\n'
                mystr += '\n'
                mystr += '# Phase 3: Post-Retiming Logic Optimization\n'
                mystr += '&get -n;               # Recover original names for easier debugging/analysis\n'
                mystr += 'st;                    # Convert back to AIG for further synthesis\n'
                mystr += "dch;                   # Perform logic optimization using DCH engine (don't-care-based simplification)\n"
                mystr += '\n'
                mystr += '# Phase 4: Final Mapping and Gate-Level Delay Optimization\n'
                mystr += 'map;                   # Final standard cell mapping\n'
                mystr += 'topo;                  # Remove dangling nodes and sort topologically\n'
                mystr += 'buffer -c;             # Add buffers along critical timing paths\n'
                mystr += 'upsize -c;             # Increase gate sizes on critical paths to reduce delay\n'
                mystr += 'dnsize -c;             # Safely downsize gates if timing allows\n'
                mystr += '\n'
                mystr += '# Phase 5: Reporting\n'
                mystr += 'stime -p;              # Print detailed timing report\n'
                mystr += 'print_stats -m;        # Print area/delay stats for the final mapped network\n'
                f.write(mystr)


        with open(path+'synth.ys', 'w') as f:
            mystr = '# read files\n'
            mystr += 'read_verilog '+str(topdir)+'/'+str(top)+'.v\n'
            mystr += '# basic synth\n'
            mystr += 'synth -top '+str(top)+' -flatten\n'
            mystr += 'show -width -format dot -prefix '+str(output_folder)+'/plots/'+str(top)+'_postsyn\n'
            mystr += '# map internal register types to the ones from the cell library\n'
            mystr += 'dfflibmap -liberty '+str(liberty)+'\n'
            mystr += '# mapping to internal cell library\n'
            mystr += 'abc -D '+str(clk_period*1000)+ ' \\'
            if opt == 'area':
                mystr += '\n    -liberty '+str(liberty)+' \\'
                mystr += '\n    -constr '+str(sdcdir)+'/'+str(top)+'.sdc \\'
                mystr += '\n    -script '+str(path)+'area.abc\n'
            elif opt == 'delay':
                mystr += '\n    -liberty '+str(liberty)+' \\'
                mystr += '\n    -constr '+str(sdcdir)+'/'+str(top)+'.sdc \\'
                mystr += '\n    -script '+str(path)+'delay.abc\n'
            elif opt == 'none':
                mystr += '\n-liberty '+str(liberty)+'\n'
            mystr += 'opt_clean -purge\n'
            mystr += 'stat -liberty '+str(liberty)+'\n'
            mystr += '# write verilog\n'
            mystr += 'write_verilog '+str(path)+str(top)+'_synth.v\n'
            mystr += '# write json\n'
            mystr += 'write_json '+str(path)+str(top)+'_synth.json\n'
            f.write(mystr)
    
    elif target == 'xilinx':
        with open(path+'synth.ys', 'w') as f:
            mystr = '# read files\n'
            mystr += 'read_verilog '+str(topdir)+'/'+str(top)+'.v\n'
            mystr += '# basic synth\n'
            mystr += 'synth_xilinx -top '+str(top)+' -flatten -edif '+str(path)+str(top)+'.edif\n'
            f.write(mystr)
        with open(path+'xilinx.tcl', 'w') as f:
            mystr = 'read_xdc '+str(top)+'.xdc\n'
            mystr += 'read_edif '+str(top)+'.edif\n'
            mystr += 'link_design -part xc7a35tcpg236-1 -top '+str(top)+'\n'
            mystr += 'opt_design\n'
            mystr += 'place_design\n'
            mystr += 'route_design\n'
            mystr += 'report_utilization\n'
            mystr += 'report_timing\n'
            mystr += 'write_bitstream -force '+str(top)+'.bit\n'
            f.write(mystr)

    elif target == 'ice40':
        with open(path+'synth.ys', 'w') as f:
            mystr = '# read files\n'
            mystr += 'read_verilog '+str(topdir)+'/'+str(top)+'.v\n'
            mystr += '# basic synth\n'
            mystr += 'synth_ice40 -top '+str(top)+' -json '+str(path)+str(top)+'.json\n'
            f.write(mystr)

except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()
