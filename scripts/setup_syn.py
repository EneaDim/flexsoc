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
    help="Define the clock period in ns")
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    top = args.get("top")
    topdir = args.get("topdir")
    target = args.get("target")
    liberty = args.get("liberty")
    clk_period = args.get("clk")
    output_folder = args.get("output")
    print(topdir)
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
        with open(path+'synth.ys', 'w') as f:
            mystr = '# read files\n'
            mystr += 'read_verilog '+str(topdir)+'/'+str(top)+'.v\n'
            mystr += '# basic synth\n'
            mystr += 'synth -top '+str(top)+' -flatten\n'
            mystr += 'show -format dot\n'
            mystr += '# map internal register types to the ones from the cell library\n'
            mystr += 'dfflibmap -liberty '+str(liberty)+'\n'
            mystr += '# mapping to internal cell library\n'
            mystr += 'abc -D '+str(clk_period*1000)+' -liberty '+str(liberty)+'\n'
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
