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
    ap.add_argument("-simdir", "--simdir", type=str, required='True', 
    help="Define the simulation directory where to put the .vcd file")
    ap.add_argument("-syndir", "--syndir", type=str, required='True', 
    help="Define the synthesis directory for the synthesis simulation")
    ap.add_argument("-prim", "--prim", nargs='+', type=str, required='True', 
    help="Define the primitive to be included for the synthesis simulation")
    ap.add_argument("-clk", "--clk", type=int, required='True', 
    help="Define the clock period in ns")
    ap.add_argument("-comp", "--comp", type=str, required='True', 
    help="Tell the compiler used Verilator/Iverilog")
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    top = args.get("top")
    rtldir = args.get("rtldir")
    simdir = args.get("simdir")
    syndir = args.get("syndir")
    prim = args.get("prim")
    clk_period = args.get("clk")
    compiler = args.get("comp")
    output_folder = args.get("output")
    parameters_flag = False
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
    # Source files under rtl
    sourcefiles = [f for f in os.listdir('rtl') if os.path.isfile(os.path.join('rtl', f))]
    sourcefiles = [f for f in sourcefiles if f[-3:]=='.sv']
    with open('./'+rtldir+'/'+top+'.sv', 'r') as f:
        content = f.readlines()
    clk = []
    rst = []
    inputs = []
    input_w = []
    outputs = []
    output_w = []
    parameters = []
    param_values = []
    localparams = []
    localparam_values = []
    content1 = ''.join(''.join(content).split(');')[0]).split('\n')    
    parameters_flag = False
    localparams_flag = False

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
        if 'parameter' in line:
            parameters_flag = True
            par  = line.split('=')[0].split()
            value = line.split('=')[1].split()[0]
            if ',' in value:
              value = value[:-1]
            parameters.append(par[-1])
            param_values.append(value)
        if 'localparam' in line:
            localparams_flag = True
            par  = line.split('=')[0].split()
            value = line.split('=')[1].split()[0]
            if ',' in value:
              value = value[:-1]
            localparams.append(par[-1])
            localparam_values.append(value)
        if 'input ' in line:
            inp  = ''.join(line.split('input')).strip()
            inp2 = inp.split()
            if inp2[0] == 'logic':
              inp2 = inp2[1:]
            if 'clk_' in inp2[-1]:
              clk.append(inp2[-1][:-1])
            if 'rst_' in inp2[-1]:
              rst.append(inp2[-1][:-1])
            if len(inp2)>1:
              input_w.append(inp2[0])
            else:
              input_w.append(1)
            for i in inp2:
              if ',' in i:
                inputs.append(i[:-1])
                flag = True
            if not(flag):
                inputs.append(inp2[-1])
        if 'output ' in line:
            out  = ''.join(line.split('output')).strip()
            out2 = out.split()
            if out2[0] == 'logic':
              out2 = out2[1:]
            if len(out2)>1:
              output_w.append(out2[0])
            else:
              output_w.append(1)
            for i in out2:
              if ',' in i:
                outputs.append(i[:-1])
                flag = True
            if not(flag):
                outputs.append(out2[-1])
    # Check for reg_pkg
    flag_reg_pkg = False
    files = os.listdir(rtldir)
    for f in files:
      if (str(top)+'_reg_pkg.sv') == f:
        flag_reg_pkg = True  

    # TLUL supported only with verilator
    if compiler == 'verilator':
        # Write tb structure
        with open(path+'tlul_if.sv', 'w+') as f:
            mystr ='`timescale 1ns/1ps\n'
            mystr +='\n'
            mystr +='interface tlul_if (\n'
            mystr +='  input  logic clk_i,\n'
            mystr +='  input  logic rst_ni\n'
            mystr +=');\n'
            mystr +='\n'
            mystr +='  import tlul_pkg::*;\n'
            mystr +='\n'
            mystr +='  // Host to Device\n'
            mystr +='  tl_h2d_t h2d /*verilator public*/;\n'
            mystr +='\n'
            mystr +='  // Device to Host\n'
            mystr +='  tl_d2h_t d2h /*verilator public*/;\n'
            mystr +='\n'
            mystr +='  // Modport for driver (testbench)\n'
            mystr +='  modport drv (\n'
            mystr +='    output h2d,\n'
            mystr +='    input  d2h\n'
            mystr +='  );\n'
            mystr +='\n'
            mystr +='  // Modport for DUT\n'
            mystr +='  modport dut (\n'
            mystr +='    input  h2d,\n'
            mystr +='    output d2h\n'
            mystr +='  );\n'
            mystr +='\n'
            mystr +='endinterface\n'
            f.write(mystr)

        with open(path+'tlul_utils.sv', 'w+') as f:
            mystr = 'class tlul_utils;\n'
            mystr += '\n'
            mystr += '  // Interface handle\n'
            mystr += '  virtual tlul_if drv_if;\n'
            mystr += '\n'
            mystr += '  // Constructor\n'
            mystr += '  function new(virtual tlul_if drv_if);\n'
            mystr += '    this.drv_if = drv_if;\n'
            mystr += '  endfunction\n'
            mystr += '\n'
            mystr += '  task automatic tlul_write(input logic [top_pkg::TL_AW-1:0]  addr,\n'
            mystr += '                            input logic [top_pkg::TL_DW-1:0]  data,\n'
            mystr += '                            input logic [top_pkg::TL_AIW-1:0] source);\n'
            mystr += '\n'
            mystr += '    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);\n'
            mystr += '\n'
            mystr += '    // Drive request\n'
            mystr += "    drv_if.h2d.d_ready   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_valid   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_opcode  = tlul_pkg::PutFullData;\n"
            mystr += "    drv_if.h2d.a_param   = 3'b000;\n"
            mystr += "    drv_if.h2d.a_size    = 2;\n"
            mystr += "    drv_if.h2d.a_source  = source;\n"
            mystr += "    drv_if.h2d.a_address = addr;\n"
            mystr += "    drv_if.h2d.a_mask    = 4'b1111;\n"
            mystr += "    drv_if.h2d.a_data    = data;\n"
            mystr += "    drv_if.h2d.a_user    = '0;\n"
            mystr += '\n'
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.a_ready);\n'
            mystr += '    drv_if.h2d.a_valid = 0;\n'
            mystr += '\n'
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.d_valid);\n'
            mystr += '\n'
            mystr += '    if (drv_if.d2h.d_error) begin\n'
            mystr += '      $display("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);\n'
            mystr += '    end else begin\n'
            mystr += '      $display("[%0t] TLUL WRITE DONE: Addr = 0x%08x", $time, addr);\n'
            mystr += '    end\n'
            mystr += '    #1;\n'
            mystr += '  endtask\n'
            mystr += '\n'
            mystr += '  task automatic tlul_read(input logic [top_pkg::TL_AW-1:0]  addr,\n'
            mystr += '                           input logic [top_pkg::TL_DW-1:0]  data,\n'
            mystr += '                           input logic [top_pkg::TL_AIW-1:0] source);\n'
            mystr += '\n'
            mystr += '    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);\n'
            mystr += '\n'
            mystr += "    drv_if.h2d.d_ready   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_valid   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_opcode  = tlul_pkg::Get;\n"
            mystr += "    drv_if.h2d.a_param   = 3'b000;\n"
            mystr += "    drv_if.h2d.a_size    = 2;\n"
            mystr += "    drv_if.h2d.a_source  = source;\n"
            mystr += "    drv_if.h2d.a_address = addr;\n"
            mystr += "    drv_if.h2d.a_mask    = 4'b1111;\n"
            mystr += "    drv_if.h2d.a_data    = '0;\n"
            mystr += "    drv_if.h2d.a_user    = '0;\n"
            mystr += '\n'
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.a_ready);\n'
            mystr += '    drv_if.h2d.a_valid = 0;\n'
            mystr += '\n'
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.d_valid);\n'
            mystr += '    data = drv_if.d2h.d_data;\n'
            mystr += '\n'
            mystr += '    if (drv_if.d2h.d_error) begin\n'
            mystr += '      $display("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);\n'
            mystr += '    end else begin\n'
            mystr += '      $display("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);\n'
            mystr += '    end\n'
            mystr += '    #1;\n'
            mystr += '  endtask\n'
            mystr += '\n'
            mystr += 'endclass\n'
            f.write(mystr)


            
        with open(path+'include_tb.sv', 'w+') as f:
            mystr = '// Include source files \n'
            mystr += '`include "ips/pkgs/top_pkg.sv"\n'
            mystr += '`include "ips/pkgs/prim_util_pkg.sv"\n'
            mystr += '`include "ips/pkgs/prim_mubi_pkg.sv"\n'
            mystr += '`include "ips/pkgs/prim_secded_pkg.sv"\n'
            mystr += '`include "ips/pkgs/tlul_pkg.sv"\n'
            mystr += '`include "tb/tlul_utils.sv"\n'
            mystr += '`include "tb/tlul_if.sv"\n'
            # May add reg_pkg
            if flag_reg_pkg:
              mystr += '`include "'+str(rtldir)+'/'+str(top)+'_reg_pkg.sv"\n'
            mystr += '`ifndef SYN\n'
            mystr += '  `include "'+str(rtldir)+'/'+str(top)+'.v"\n'
            mystr += '`else\n'
            # Add primitives
            for p in prim:
              mystr += '  `include "'+str(p)+'"\n'
            mystr += '  `include "'+str(syndir)+'/'+str(top)+'_synth.v"\n'
            mystr += '`endif\n'
            f.write(mystr)
    with open(path+top+'_tb.sv', 'w+') as f:
        mystr = '// Timescale \n'
        mystr += '`timescale 1ns/1ps \n'
        mystr += '// Include files \n'
        # TLUL supported only with verilator
        if compiler == 'verilator':
            mystr += '`include "tb/include_tb.sv"\n\n'
        else:
            if flag_reg_pkg:
              mystr += '`include "'+str(rtldir)+'/'+str(top)+'_reg_pkg.sv"\n'
            mystr += '`ifndef SYN\n'
            mystr += '  `include "'+str(rtldir)+'/'+str(top)+'.v"\n'
            mystr += '`else\n'
            # Add primitives
            for p in prim:
              mystr += '  `include "'+str(p)+'"\n'
            mystr += '  `include "'+str(syndir)+'/'+str(top)+'_synth.v"\n'
            mystr += '`endif\n'

        mystr += 'module '+str(top)+'_tb;\n'
        mystr += '  //Parameters\n'
        mystr += '  parameter int CLK_PERIOD = '+str(clk_period)+'; // Clock period in ns\n'
        if parameters_flag:
            for p, v in zip(parameters, param_values):
                mystr += '  parameter '+str(p)+' = '+str(v)+';\n'
        if localparams_flag:
            for p, v in zip(localparams, localparam_values):
                mystr += '  localparam '+str(p)+' = '+str(v)+';\n'
        mystr += '  // Inputs\n'
        for i in inputs:
            if input_w[inputs.index(i)] == 1:
               mystr += '  reg '+str(i)+';\n'
            else:
               if '[' in input_w[inputs.index(i)]:
                 mystr += '  reg '+str(input_w[inputs.index(i)])+' '+str(i)+';\n'
               else:
                 mystr += '  '+str(input_w[inputs.index(i)])+' '+str(i)+';\n'
        mystr += '  // Outputs\n'
        for o in outputs:
            if output_w[outputs.index(o)] == 1:
               mystr += '  wire '+str(o)+';\n'
            else:
               if '[' in output_w[outputs.index(o)]:
                 mystr += '  wire '+str(output_w[outputs.index(o)])+' '+str(o)+';\n'
               else:
                 mystr += '  '+str(output_w[outputs.index(o)])+' '+str(o)+';\n'
        mystr += '\n  integer error_count;\n\n'
        if compiler == 'verilator':
            mystr += '  // For TLUL read task and than display\n'
            mystr += '  //logic [top_pkg::TL_DW-1:0] read_data;\n\n'
            mystr += '  // Class instance always done because of error related to virtual interface\n'
            mystr += '  tlul_utils tl_utils_inst;\n'
            mystr += '  // Interface\n'
            mystr += '  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));\n'
  
        for p, name in enumerate(parameters):
            parameters[p] = name.split('=')[0].strip()
        for i, el in enumerate(inputs):
            inputs[i] = inputs[i].split()[-1]
        for i, el in enumerate(outputs):
            outputs[i] = outputs[i].split()[-1]
        mystr += '\n  // Device Under Test Instance\n'
        mystr += '  '+str(top)+'\n'
        if parameters_flag:
            mystr += '  `ifndef SYN\n    #(\n'
            if len(parameters)> 1:
              for p in parameters[:-1]:
                  mystr += '      .'+str(p)+'('+str(p)+'),\n'
              mystr += '      .'+str(parameters[-1])+'('+str(parameters[-1])+')\n    ) '
            else:
              mystr += '      .'+str(parameters[-1])+'('+str(parameters[-1])+')\n    ) '
            mystr += '\n  `endif\n'
        mystr += '  u_'+str(top)+' (\n'
        for i in inputs:
            if i == 'tl_i':
                mystr += '    .'+str(i)+',//(tl_if.h2d),\n'
            else:
                mystr += '    .'+str(i)+',\n'
        for o in outputs[:-1]:
            if o == 'tl_o':
                mystr += '    .'+str(o)+',//(tl_if.d2h),\n'
            else:
                mystr += '    .'+str(o)+',\n'
        mystr += '    .'+str(outputs[-1])+'\n'
        mystr += '  );\n\n'
        mystr += '  // Clock generation\n'
        for c in clk:
          mystr += '  initial begin\n'
          mystr += '    '+str(c)+' = 0;\n'
          mystr += '    forever #(CLK_PERIOD / 2) '+str(c)+' = ~'+str(c)+';\n'
          mystr += '  end\n\n'
        mystr += '  // Dump vcd file \n'
        mystr += '  initial begin\n'
        mystr += '    `ifndef SYN\n'
        mystr += '      $dumpfile("'+str(simdir)+'/dump_'+str(top)+'.vcd");\n'
        mystr += '    `else\n'
        mystr += '      $dumpfile("'+str(simdir)+'/dump_'+str(top)+'_syn.vcd");\n'
        mystr += '    `endif\n'
        mystr += '    $dumpvars(0, '+str(top)+'_tb);\n'
        mystr += '  end\n\n'
        mystr += '  // Error count\n'
        mystr += '  initial begin\n'
        mystr += '    error_count = 0;\n'
        mystr += '  end\n\n'
        mystr += '  initial begin\n'
        mystr += '    // Init inputs\n'
        for i in inputs[1:]:
            mystr += '    '+str(i)+' = 0;\n'
        mystr += '    // Asynch Reset\n'
        mystr += '    #(CLK_PERIOD);\n'
        mystr += '    '+str(inputs[1])+' = 1;\n'
        mystr += '    #(CLK_PERIOD);\n'
        mystr += '    // Start main test\n'
        mystr += '    $display("\\nRunning...\\n");\n'
        if compiler == 'verilator':
            mystr += '    //// Instantiate utility\n'
            mystr += '    //tl_utils_inst = new(tl_if); \n'
            mystr += '    //// Wait\n'
            mystr += '    //#(CLK_PERIOD*100);\n'
            mystr += '    //// Write\n'
            mystr += "    //tl_utils_inst.tlul_write(32'h0, 32'h1, 4'h0);\n"
            mystr += "    //tl_utils_inst.tlul_write(32'h4, 32'hF, 4'h1);\n"
            mystr += '    //#(CLK_PERIOD*100);\n'
            mystr += '    //// Read\n'
            mystr += "    //tl_utils_inst.tlul_read(32'h8, read_data, 4'h2);\n"
            mystr += '    //$display("Read data: %h", read_data);\n'
            mystr += '    //#(CLK_PERIOD*100);\n'
        mystr += '    // INSERT YOUR CODE\n\n\n'
        mystr += '    // Final Check\n'
        mystr += '    if (error_count == 0) begin\n'
        mystr += '      $display("Coverage: 100%%");\n'
        mystr += '    end\n'
        mystr += '    $display("\\nEnd.\\n");\n'
        mystr += '    $finish;\n'
        mystr += '  end\n'
        mystr += 'endmodule\n'
        f.write(mystr)
        
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()
