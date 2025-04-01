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
    ap.add_argument("-tb", "--tb", type=str, required='True', 
    help="Define the TB for vcd based power analysis")
    ap.add_argument("-rtldir", "--rtldir", type=str, required='True', 
    help="Define the directory of source files of the design")
    ap.add_argument("-libs", "--libs", nargs='+', type=str, required='True', 
    help="Link liberty files of the technology used")
    ap.add_argument("-clk", "--clk", type=int, required='True', 
    help="Define the clock period in ns")
    ap.add_argument("-activity", "--activity", type=int, required='True', 
    help="Define activity of inputs in percentage")
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    top = args.get("top")
    testbench = args.get("tb")
    rtldir = args.get("rtldir")
    libs = args.get("libs")
    for l in libs:
      if '_tt_' in l:
        lib_tt = l
      if '_ss_' in l:
        lib_ss = l
      if '_ff_' in l:
        lib_ff = l
    clk_period = args.get("clk")
    activity = args.get("activity")
    output_folder = args.get("output")
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

def init_opensta():
  # Define Corners ss tt ff
  mystr  = 'puts ""\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts "Define corners Slowest Typical Fastest"\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts ""\n'
  mystr += 'puts "define_corners Slowest Typical Fastest"\n'
  mystr += 'define_corners Slowest Typical Fastest'
  mystr += '\n'
  # Read Liberty Files
  mystr += 'puts ""\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts "Read liberty files"\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts ""\n'
  for k, v in corners.items():
    mystr += 'puts "read_liberty -corner '+str(k)+' '+str(v)+'"\n'
    mystr += 'read_liberty -corner '+str(k)+' '+str(v)+'\n'
  # Read post synthesis verilog netlist and link the top module
  mystr += 'puts ""\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts "Read verilog and link top module"\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts ""\n'
  mystr += 'puts "read_verilog syn/'+str(top)+'_synth.v"\n'
  mystr += 'puts "link_design '+str(top)+'"\n'
  mystr += 'read_verilog syn/'+str(top)+'_synth.v\n'
  mystr += 'link_design '+str(top)+'\n'
  # Read SDC
  mystr += 'puts ""\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts "Read SDC"\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts ""\n'
  mystr += 'puts "read_sdc '+str(output_folder)+'/'+str(top)+'.sdc"\n'
  mystr += 'read_sdc '+str(output_folder)+'/'+str(top)+'.sdc\n'
  mystr += 'puts ""\n'
  return mystr

def write_sdf(mystr):
  # Write the SDF files for each corner
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts "Write SDF files for each corner"\n'
  mystr += 'puts "==========================================================================="\n'
  mystr += 'puts ""\n'
  mystr += 'puts "write_sdf -corner Typical -divider . -include_typ '+str(output_folder)+'/sdf/'+str(top)+'_tt.sdf"\n'
  mystr += 'puts "write_sdf -corner Slowest -divider . -include_typ '+str(output_folder)+'/sdf/'+str(top)+'_ss.sdf"\n'
  mystr += 'puts "write_sdf -corner Fastest -divider . -include_typ '+str(output_folder)+'/sdf/'+str(top)+'_ff.sdf"\n'
  mystr += 'puts ""\n'
  mystr += 'write_sdf -corner Typical -divider . -include_typ '+str(output_folder)+'/sdf/'+str(top)+'_tt.sdf\n'
  mystr += 'write_sdf -corner Slowest -divider . -include_typ '+str(output_folder)+'/sdf/'+str(top)+'_ss.sdf\n'
  mystr += 'write_sdf -corner Fastest -divider . -include_typ '+str(output_folder)+'/sdf/'+str(top)+'_ff.sdf\n'
  f.write(mystr)

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
try:
    # Define the output folder
    if output_folder:
        path = './' + output_folder + '/'
    else:
        path = './'
    corners = {'Slowest' : lib_ss, 'Typical' : lib_tt, 'Fastest' : lib_ff}
    with open(path+'sta_violators.tcl', 'w') as f:
        mystr = init_opensta()
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Hold) report_checks -path_delay min"\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ===================================\n'
        mystr += '"\n'
        mystr += '    report_checks -slack_max -0.01 -path_delay min -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '    set ws [sta::format_time [sta::worst_slack_corner $corner "min"] 4]\n'
        mystr += '    puts "worst slack hold corner [$corner name]: $ws"\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Setup) report_checks -path_delay max"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ==================================="\n'
        mystr += '    report_checks -slack_max -0.01 -path_delay max -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '    set ws [sta::format_time [sta::worst_slack_corner $corner "max"] 4]\n'
        mystr += '    puts "worst slack setup corner [$corner name]: $ws"\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Unconstrained) report_checks -unconstrained"\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ===================================\n'
        mystr += '"\n'
        mystr += '    report_checks -slack_max -0.01 -unconstrained -fields {slew cap input nets fanout} -format full_clock_expanded -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_worst_slack -max (Setup)"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_worst_slack -max\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_worst_slack -min (Hold)"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_worst_slack -min\n'
        mystr += 'puts ""\n'
        f.write(mystr)
    with open(path+'sta.tcl', 'w') as f:
        mystr = init_opensta()
        # Core Script
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Hold) report_checks -path_delay min"\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ===================================\n'
        mystr += '"\n'
        mystr += '    report_checks -sort_by_slack -path_delay min -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '    set ws [sta::format_time [sta::worst_slack_corner $corner "min"] 4]\n'
        mystr += '    puts "worst slack hold corner [$corner name]: $ws"\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Setup) report_checks -path_delay max"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ==================================="\n'
        mystr += '    report_checks -sort_by_slack -path_delay max -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '    set ws [sta::format_time [sta::worst_slack_corner $corner "max"] 4]\n'
        mystr += '    puts "worst slack setup corner [$corner name]: $ws"\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Unconstrained) report_checks -unconstrained"\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ===================================\n'
        mystr += '"\n'
        mystr += '    report_checks -unconstrained -fields {slew cap input nets fanout} -format full_clock_expanded -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(All Violators) report_check_types -max_slew -max_cap -max_fanout -violators"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ==================================="\n'
        mystr += '    report_check_types -max_slew -max_capacitance -max_fanout -violators -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '    set net "NULL"\n'
        mystr += '    set violators 1\n'
        mystr += '    set min_max "max"\n'
        mystr += '    set slew_pins [sta::check_slew_limits $net $violators $corner $min_max]\n'
        mystr += '    puts "max slew violations count [$corner name]: [llength $slew_pins]"\n'
        mystr += '    set fanout_pins [sta::check_fanout_limits $net $violators $min_max]\n'
        mystr += '    puts "max fanout violations count [$corner name]: [llength $fanout_pins]"\n'
        mystr += '    set cap_pins [sta::check_capacitance_limits $net $violators $corner $min_max]\n'
        mystr += '    puts "max cap violations count [$corner name]: [llength $cap_pins]"\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_parasitic_annotation -report_unannotated"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_parasitic_annotation -report_unannotated\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "max slew violation count [sta::max_slew_violation_count]"\n'
        mystr += 'puts "max fanout violation count [sta::max_fanout_violation_count]"\n'
        mystr += 'puts "max cap violation count [sta::max_capacitance_violation_count]"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "check_setup -verbose -unconstrained_endpoints -multiple_clock -no_clock -no_input_delay -loops -generated_clocks"\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'check_setup -verbose -unconstrained_endpoints -multiple_clock -no_clock -no_input_delay -loops -generated_clocks\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'puts "(Clock Skew) report_clock_skew"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_clock_skew\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_tns"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_tns\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_wns"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_wns\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_worst_slack -max (Setup)"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_worst_slack -max\n'
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "report_worst_slack -min (Hold)"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'report_worst_slack -min\n'
        mystr += 'puts ""\n'
        f.write(mystr)
    with open(path+'power.tcl', 'w') as f:
        mystr = init_opensta()
        mystr += 'puts ""\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(Probability Power Analysis) report_power"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'puts "set_power_activity -input -activity .'+str(activity)+'"\n'
        mystr += 'puts "set_power_activity -input_port rst_ni -activity 0"\n' 
        mystr += 'set_power_activity -input -activity .'+str(activity)+'\n'
        mystr += 'set_power_activity -input_port rst_ni -activity 0\n' 
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ==================================="\n'
        mystr += '    report_power -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        mystr += 'puts "==========================================================================="\n'
        mystr += 'puts "(VCD Power Analysis) report_power"\n'
        mystr += 'puts "============================================================================"\n'
        mystr += 'puts "read_vcd -scope '+str(top)+'_tb/u_'+str(top)+' sim/dump_'+str(testbench)+'.vcd"\n'
        mystr += 'read_vcd -scope '+str(top)+'_tb/u_'+str(top)+' sim/dump_'+str(testbench)+'.vcd\n'
        mystr += 'foreach corner [sta::corners] {\n'
        mystr += '    puts ""\n'
        mystr += '    puts "======================= [$corner name] Corner ==================================="\n'
        mystr += '    report_power -corner [$corner name]\n'
        mystr += '    puts ""\n'
        mystr += '}\n'
        f.write(mystr)
    with open(path+'write_sdf.tcl', 'w') as f:
        mystr = init_opensta()
        write_sdf(mystr)
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

