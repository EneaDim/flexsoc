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
    ap.add_argument("-prj", "--prj", type=str, required='True', 
    help="Define the project name of the design")
    ap.add_argument("-top", "--top", type=str, required='True', 
    help="Define the TOP module in the design")
    ap.add_argument("-rtldir", "--rtldir", type=str, required='True', 
    help="Define the directory of source files of the design")
    ap.add_argument("-lintdir", "--lintdir", type=str, required='True', 
    help="Define the simulation directory where to put the .vcd file")
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    prj = args.get("prj")
    top = args.get("top")
    rtldir = args.get("rtldir")
    lintdir = args.get("lintdir")
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
    
    # Check for reg_pkg
    flag_reg_pkg = False
    files = os.listdir(rtldir)
    files = [f for f in files if not '.' == f[0]]
    files = [f for f in files if '.sv' == f[-3:]]
    for f in files:
      if (str(top)+'_reg_pkg.sv') == f:
        flag_reg_pkg = True  
    with open(path+top+'.core', 'w+') as f:
        mystr  = 'CAPI=2:\n'
        mystr += 'name: "'+str(prj)+':ip:'+str(top)+':0.1"\n'
        mystr += 'description: "'+str(top)+'"\n'
        mystr += 'filesets:\n'
        mystr += '  files_rtl:\n'
        mystr += '    depend:\n'
        mystr += '      - ips:dependecies:all\n'
        mystr += '    files:\n'
        #if flag_reg_pkg:
        #    mystr += '      - '+str(rtldir)+'/'+str(top)+'_reg_pkg.sv\n'
        #    mystr += '      - '+str(rtldir)+'/'+str(top)+'_reg_top.sv\n'
        for i in files:
            mystr += '      - '+str(rtldir)+'/'+str(i)+'\n'
        mystr += '    file_type: systemVerilogSource\n'
        mystr += '\n'
        mystr += '  files_verilator_waiver:\n'
        mystr += '    files:\n'
        mystr += '      - '+str(lintdir)+'/'+str(top)+'.vlt\n'
        mystr += '    file_type: vlt\n'
        mystr += '\n'
        mystr += 'targets:\n'
        mystr += '  default: &default_target\n'
        mystr += '    filesets:\n'
        mystr += '      - files_rtl\n'
        mystr += '      - tool_verilator   ? (files_verilator_waiver)\n'
        mystr += '    toplevel: '+str(top)+'\n'
        mystr += '\n'
        mystr += '  lint:\n'
        mystr += '    <<: *default_target\n'
        mystr += '    default_tool: verilator\n'
        mystr += '    tools:\n'
        mystr += '      verilator:\n'
        mystr += '        mode: lint-only\n'
        mystr += '        verilator_options:\n'
        mystr += '          - "-Wall"\n'
        mystr += '          - "-Wno-fatal"\n\n'

        f.write(mystr)

except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

