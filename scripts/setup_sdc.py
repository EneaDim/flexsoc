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
    ap.add_argument("-rtldir", "--rtldir", type=str, required='True', 
    help="Define the directory of source files of the design")
    ap.add_argument("-clk", "--clk", type=int, required='True', 
    help="Define the clock period in ns")
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    top = args.get("top")
    rtldir = args.get("rtldir")
    clk_period = args.get("clk")
    output_folder = args.get("output")
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

# WRITE SDC
try:
    # Define the output folder
    if output_folder:
        path = './' + output_folder + '/'
    else:
        path = './'
    # Find inputs and outputs to generate SDC
    with open('./'+rtldir+'/'+top+'.sv', 'r') as f:
        content = f.readlines()

    clk = []
    rst = []
    inputs = []
    outputs = []
    content1 = ''.join(''.join(content).split(');')[0]).split('\n')
    for line in content1:
        flag = False
        comment_flag = False
        if ('//') in line:
          if not 'input' and not 'output' in line:
            comment_flag = True
          else:
            line = ''.join(line.split('//')[:-1])
        if comment_flag:
            continue
        if 'input ' in line:
            inp  = ''.join(line.split('input')).strip()
            inp2 = inp.split()
            if 'clk_' in inp2[-1]:
              clk.append(inp2[-1][:-1])
            if 'rst_' in inp2[-1]:
              rst.append(inp2[-1][:-1])
            for i in inp2:
              if ',' in i:
                inputs.append(i[:-1])
                flag = True
            if not(flag):
                inputs.append(inp2[-1])
        if 'output ' in line:
            out  = ''.join(line.split('output')).strip()
            out2 = out.split()
            for i in out2:
              if ',' in i:
                outputs.append(i[:-1])
                flag = True
            if not(flag):
                outputs.append(out2[-1])
    # Write SDC file
    with open(path+top+'.sdc', 'w') as f:
        mystr = ''
        for c in clk:
          mystr += 'create_clock -name '+str(c[:-2])+' -period '+str(clk_period)+' {'+str(c)+'}\n'
        if len(clk) == 2:
          # Assume Write CLK before, then Read CLK
          for i in inputs:
            if not 'clk_' in i:
              if 'w' in i:
                  mystr += 'set_input_delay   3 -clock '+str(clk[0][:-2])+' {'+str(i)+'}\n'
              if 'r' and not('w') in i:
                  mystr += 'set_input_delay   3 -clock '+str(clk[1][:-2])+' {'+str(i)+'}\n'
          for i in outputs:
            if not 'clk_' in i:
              if 'w' in i:
                  mystr += 'set_output_delay  3 -clock '+str(clk[0][:-2])+' {'+str(i)+'}\n'
              if 'r' and not('w') in i:
                  mystr += 'set_output_delay  3 -clock '+str(clk[1][:-2])+' {'+str(i)+'}\n'
        else:
          for i in inputs:
            if not 'clk_' in i:
              mystr += 'set_input_delay  3 -clock '+str(clk[0][:-2])+' {'+str(i)+'}\n'
          for i in outputs:
            mystr += 'set_output_delay 3 -clock '+str(clk[0][:-2])+' {'+str(i)+'}\n'
        f.write(mystr)
        
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

