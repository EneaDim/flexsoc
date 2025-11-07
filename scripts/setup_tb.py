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
#!/usr/bin/env python3
import sys
import os
import argparse

# =========================
# ARGUMENT PARSING
# =========================
try:
    ap = argparse.ArgumentParser()
    ap.add_argument("-top",   "--top",   type=str, required=True,
                    help="Define the TOP module in the design")
    ap.add_argument("-rtldir","--rtldir",type=str, required=True,
                    help="Define the directory of source files of the design")
    ap.add_argument("-simdir","--simdir",type=str, required=True,
                    help="Define the simulation directory where to put the .vcd file")
    ap.add_argument("-syndir","--syndir",type=str, required=True,
                    help="Define the synthesis directory for the synthesis simulation")
    ap.add_argument("-prim",  "--prim",  nargs='+', type=str, required=True,
                    help="Define the primitive to be included for the synthesis simulation")
    ap.add_argument("-clk",   "--clk",   type=int, required=True,
                    help="Define the clock period in ns")
    ap.add_argument("-comp",  "--comp",  type=str, required=True,
                    help="Tell the compiler used Verilator/Iverilog")
    ap.add_argument("-itf",   "--itf",   type=str, required=True,
                    help="Define the register interface: supported reg_iface - tlul")
    ap.add_argument("-vsv",   "--vsv",   type=str, required=True,
                    help="Define the top file type: -verilog or -systemverilog")
    ap.add_argument("-o",     "--output",type=str, required=False,
                    help="Output Folder (base path for generated files)")
    args = vars(ap.parse_args())

    top          = args.get("top")
    rtldir       = args.get("rtldir")
    simdir       = args.get("simdir")
    syndir       = args.get("syndir")
    prim         = args.get("prim")
    clk_period   = args.get("clk")
    compiler     = args.get("comp")
    itf          = args.get("itf")
    vsv          = args.get("vsv")
    output_folder= args.get("output")
    parameters_flag = False
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit(1)

try:
    # =========================
    # PATHS
    # =========================
    # Base output path
    if output_folder:
        base_path = os.path.join('./', output_folder)
    else:
        base_path = './'

    os.makedirs(base_path, exist_ok=True)
    tb_path = base_path
    os.makedirs(tb_path, exist_ok=True)

    # =========================
    # PARSE TOP SV FOR PORTS/PARAMS
    # =========================
    with open(os.path.join('./', rtldir, top + '.sv'), 'r') as f:
        content = f.readlines()

    clk         = []
    rst         = []
    inputs      = []
    input_w     = []
    outputs     = []
    output_w    = []
    parameters  = []
    param_values= []
    localparams = []
    localparam_values = []

    hdr = ''.join(''.join(content).split(');')[0]).split('\n')
    parameters_flag   = False
    localparams_flag  = False

    for line in hdr:
        flag = False
        comment_flag = False
        if ('//') in line:
            # Strip trailing comments on lines with ports/params
            if not ('input' in line or 'output' in line or 'parameter' in line or 'localparam' in line):
                comment_flag = True
            else:
                line = ''.join(line.split('//')[:-1])
        if comment_flag:
            continue

        if 'parameter' in line and 'localparam' not in line:
            parameters_flag = True
            par   = line.split('=')[0].split()
            value = line.split('=')[1].split()[0]
            if ',' in value:
                value = value[:-1]
            parameters.append(par[-1])
            param_values.append(value)

        if 'localparam' in line:
            localparams_flag = True
            par   = line.split('=')[0].split()
            value = line.split('=')[1].split()[0]
            if ',' in value:
                value = value[:-1]
            localparams.append(par[-1])
            localparam_values.append(value)

        if 'input ' in line:
            inp  = ''.join(line.split('input')).strip()
            inp2 = inp.split()
            if len(inp2) == 0:
                continue
            if inp2[0] == 'logic':
                inp2 = inp2[1:]
            if len(inp2) == 0:
                continue
            # clock / reset tagging
            if 'clk_' in inp2[-1]:
                clk.append(inp2[-1][:-1] if inp2[-1].endswith(',') else inp2[-1])
            if 'rst_' in inp2[-1]:
                rst.append(inp2[-1][:-1] if inp2[-1].endswith(',') else inp2[-1])
            if len(inp2) > 1:
                input_w.append(inp2[0])
            else:
                input_w.append(1)
            for tok in inp2:
                if tok.endswith(','):
                    inputs.append(tok[:-1])
                    flag = True
            if not flag:
                inputs.append(inp2[-1])

        if 'output ' in line:
            out  = ''.join(line.split('output')).strip()
            out2 = out.split()
            if len(out2) == 0:
                continue
            if out2[0] == 'logic':
                out2 = out2[1:]
            if len(out2) == 0:
                continue
            if len(out2) > 1:
                output_w.append(out2[0])
            else:
                output_w.append(1)
            for tok in out2:
                if tok.endswith(','):
                    outputs.append(tok[:-1])
                    flag = True
            if not flag:
                outputs.append(out2[-1])

    # =========================
    # CHECK IF *_reg_pkg.sv EXISTS
    # =========================
    flag_reg_pkg = False
    for fname in os.listdir(rtldir):
        if (str(top) + '_reg_pkg.sv') == fname:
            flag_reg_pkg = True
            break

    # =========================
    # GENERATE INTERFACE FILES
    # =========================
    # TLUL path (unchanged)
    if compiler == 'verilator' and flag_reg_pkg and itf == 'tlul':
        with open(os.path.join(tb_path, 'tlul_if.sv'), 'w+') as f:
            mystr  = '`timescale 1ns/1ps\n\n'
            mystr += 'interface tlul_if (\n'
            mystr += '  input  logic clk_i,\n'
            mystr += '  input  logic rst_ni\n'
            mystr += ');\n\n'
            mystr += '  import tlul_pkg::*;\n\n'
            mystr += '  // Host to Device\n'
            mystr += '  tl_h2d_t h2d /*verilator public*/;\n\n'
            mystr += '  // Device to Host\n'
            mystr += '  tl_d2h_t d2h /*verilator public*/;\n\n'
            mystr += '  // Modport for driver (testbench)\n'
            mystr += '  modport drv (\n'
            mystr += '    output h2d,\n'
            mystr += '    input  d2h\n'
            mystr += '  );\n\n'
            mystr += '  // Modport for DUT\n'
            mystr += '  modport dut (\n'
            mystr += '    input  h2d,\n'
            mystr += '    output d2h\n'
            mystr += '  );\n\n'
            mystr += 'endinterface\n'
            f.write(mystr)

        with open(os.path.join(tb_path, 'tlul_utils.sv'), 'w+') as f:
            mystr  = 'class tlul_utils;\n\n'
            mystr += '  virtual tlul_if drv_if;\n\n'
            mystr += '  function new(virtual tlul_if drv_if);\n'
            mystr += '    this.drv_if = drv_if;\n'
            mystr += '  endfunction\n\n'
            mystr += '  task automatic tlul_write(input logic [top_pkg::TL_AW-1:0]  addr,\n'
            mystr += '                            input logic [top_pkg::TL_DW-1:0]  data,\n'
            mystr += '                            input logic [top_pkg::TL_AIW-1:0] source);\n\n'
            mystr += '    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);\n\n'
            mystr += "    drv_if.h2d.d_ready   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_valid   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_opcode  = tlul_pkg::PutFullData;\n"
            mystr += "    drv_if.h2d.a_param   = 3'b000;\n"
            mystr += "    drv_if.h2d.a_size    = 2;\n"
            mystr += "    drv_if.h2d.a_source  = source;\n"
            mystr += "    drv_if.h2d.a_address = addr;\n"
            mystr += "    drv_if.h2d.a_mask    = 4'b1111;\n"
            mystr += "    drv_if.h2d.a_data    = data;\n"
            mystr += "    drv_if.h2d.a_user    = '0;\n\n"
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.a_ready);\n'
            mystr += '    drv_if.h2d.a_valid = 0;\n\n'
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.d_valid);\n\n'
            mystr += '    if (drv_if.d2h.d_error) begin\n'
            mystr += '      $display("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);\n'
            mystr += '    end else begin\n'
            mystr += '      $display("[%0t] TLUL WRITE DONE: Addr = 0x%08x", $time, addr);\n'
            mystr += '    end\n'
            mystr += '    #1;\n'
            mystr += '  endtask\n\n'
            mystr += '  task automatic tlul_read(input  logic [top_pkg::TL_AW-1:0]  addr,\n'
            mystr += '                           output logic [top_pkg::TL_DW-1:0]  data,\n'
            mystr += '                           input  logic [top_pkg::TL_AIW-1:0] source);\n\n'
            mystr += '    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);\n\n'
            mystr += "    drv_if.h2d.d_ready   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_valid   = 1'b1;\n"
            mystr += "    drv_if.h2d.a_opcode  = tlul_pkg::Get;\n"
            mystr += "    drv_if.h2d.a_param   = 3'b000;\n"
            mystr += "    drv_if.h2d.a_size    = 2;\n"
            mystr += "    drv_if.h2d.a_source  = source;\n"
            mystr += "    drv_if.h2d.a_address = addr;\n"
            mystr += "    drv_if.h2d.a_mask    = 4'b1111;\n"
            mystr += "    drv_if.h2d.a_data    = '0;\n"
            mystr += "    drv_if.h2d.a_user    = '0;\n\n"
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.a_ready);\n'
            mystr += '    drv_if.h2d.a_valid = 0;\n\n'
            mystr += '    do @(posedge drv_if.clk_i); while (!drv_if.d2h.d_valid);\n'
            mystr += '    data = drv_if.d2h.d_data;\n\n'
            mystr += '    if (drv_if.d2h.d_error) begin\n'
            mystr += '      $display("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);\n'
            mystr += '    end else begin\n'
            mystr += '      $display("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);\n'
            mystr += '    end\n'
            mystr += '    #1;\n'
            mystr += '  endtask\n\n'
            mystr += 'endclass\n'
            f.write(mystr)

    # New: generic reg_iface (your structs)
    if compiler == 'verilator' and flag_reg_pkg and itf == 'reg_iface':
        with open(os.path.join(tb_path, 'reg_if.sv'), 'w+') as f:
            mystr  = '`timescale 1ns/1ps\n\n'
            mystr += 'interface reg_if (\n'
            mystr += '  input  logic clk_i,\n'
            mystr += '  input  logic rst_ni\n'
            mystr += ');\n'
            mystr += '  import '+str(top)+'_reg_pkg::*;\n'
            mystr += '\n'
            mystr += '  // Verso il DUT (richiesta registrata)\n'
            mystr += '  reg_req_t req /*verilator public*/;\n'
            mystr += '  // Dal DUT (risposta)\n'
            mystr += '  reg_rsp_t rsp /*verilator public*/;\n'
            mystr += '\n'
            mystr += '  // Staging dal TB per evitare cicli combinazionali\n'
            mystr += '  reg_req_t req_q;\n'
            mystr += '\n'
            mystr += '  // Registra la richiesta da req_q verso req, vista dal DUT\n'
            mystr += '  always_ff @(posedge clk_i or negedge rst_ni) begin\n'
            mystr += '    if (!rst_ni) req <= \'0;\n'
            mystr += '    else         req <= req_q;\n'
            mystr += '  end\n'
            mystr += '\n'
            mystr += '  // Modport per driver (usa req_q e clock)\n'
            mystr += '  modport drv (\n'
            mystr += '    input  clk_i,\n'
            mystr += '    output req_q,\n'
            mystr += '    input  rsp\n'
            mystr += '  );\n'
            mystr += '\n'
            mystr += '  // Modport per DUT (vede req registrato)\n'
            mystr += '  modport dut (\n'
            mystr += '    input  clk_i,\n'
            mystr += '    input  rst_ni,\n'
            mystr += '    input  req,\n'
            mystr += '    output rsp\n'
            mystr += '  );\n'
            mystr += '\n'
            mystr += 'endinterface\n'
            f.write(mystr)

        with open(os.path.join(tb_path, 'reg_utils.sv'), 'w+') as f:
            mystr  = 'class reg_utils;\n\n'
            mystr += '  // Usa il modport del driver per avere direzioni chiare e l\'accesso al clock\n'
            mystr += '  virtual reg_if.drv drv_if;\n'
            mystr += '\n'
            mystr += '  function new(virtual reg_if.drv drv_if);\n'
            mystr += '    this.drv_if = drv_if;\n'
            mystr += '  endfunction\n'
            mystr += '\n'
            mystr += '  // Helper: un ciclo di clock\n'
            mystr += '  task automatic cycle();\n'
            mystr += '    @(posedge drv_if.clk_i);\n'
            mystr += '  endtask\n'
            mystr += '\n'
            mystr += '  task automatic write(\n'
            mystr += '      input  logic ['+str(top)+'_reg_pkg::AW-1:0]  addr,\n'
            mystr += '      input  logic ['+str(top)+'_reg_pkg::DW-1:0]  data,\n'
            mystr += '      input  logic ['+str(top)+'_reg_pkg::DBW-1:0] strb = {'+str(top)+'_reg_pkg::DBW{1\'b1}});\n'
            mystr += '    $display("[%0t] REG WRITE: Addr = 0x%0h Data = 0x%0h WSTRB = 0x%0h", $time, addr, data, strb);\n'
            mystr += '\n'
            mystr += '    // Pilota la richiesta su registri di staging (req_q) con assegnazioni non bloccanti\n'
            mystr += '    drv_if.req_q.valid <= 1\'b1;\n'
            mystr += '    drv_if.req_q.write <= 1\'b1;\n'
            mystr += '    drv_if.req_q.addr  <= addr;\n'
            mystr += '    drv_if.req_q.wdata <= data;\n'
            mystr += '    drv_if.req_q.wstrb <= strb;\n'
            mystr += '\n'
            mystr += '    // Presenta la richiesta al DUT al prossimo fronte di clock (req <= req_q nell\'interfaccia)\n'
            mystr += '    cycle();\n'
            mystr += '\n'
            mystr += '    // Attende il ready (campionato sui fronti di clock)\n'
            mystr += '    while (!drv_if.rsp.ready) cycle();\n'
            mystr += '\n'
            mystr += '    // Deassert di valid dopo handshake\n'
            mystr += '    drv_if.req_q.valid <= 1\'b0;\n'
            mystr += '    cycle();\n'
            mystr += '\n'
            mystr += '    if (drv_if.rsp.error) begin\n'
            mystr += '      $display("[%0t] REG WRITE ERROR: Addr = 0x%0h", $time, addr);\n'
            mystr += '    end else begin\n'
            mystr += '      $display("[%0t] REG WRITE DONE: Addr = 0x%0h", $time, addr);\n'
            mystr += '    end\n'
            mystr += '    #1;\n'
            mystr += '  endtask\n'
            mystr += '\n'
            mystr += '  task automatic read(\n'
            mystr += '      input  logic ['+str(top)+'_reg_pkg::AW-1:0]  addr,\n'
            mystr += '      output logic ['+str(top)+'_reg_pkg::DW-1:0]  data);\n'
            mystr += '    $display("[%0t] REG READ: Addr = 0x%0h", $time, addr);\n'
            mystr += '\n'
            mystr += '    drv_if.req_q.valid <= 1\'b1;\n'
            mystr += '    drv_if.req_q.write <= 1\'b0;\n'
            mystr += '    drv_if.req_q.addr  <= addr;\n'
            mystr += '    drv_if.req_q.wdata <= \'0;\n'
            mystr += '    drv_if.req_q.wstrb <= \'0;\n'
            mystr += '\n'
            mystr += '    cycle(); // presenta al DUT\n'
            mystr += '\n'
            mystr += '    // Attende ready\n'
            mystr += '    while (!drv_if.rsp.ready) cycle();\n'
            mystr += '\n'
            mystr += '    // Raccoglie i dati (se validi nello stesso ciclo del ready saranno già visibili)\n'
            mystr += '    data = drv_if.rsp.rdata;\n'
            mystr += '\n'
            mystr += '    // Deassert di valid dopo handshake\n'
            mystr += '    drv_if.req_q.valid <= 1\'b0;\n'
            mystr += '    cycle();\n'
            mystr += '\n'
            mystr += '    if (drv_if.rsp.error) begin\n'
            mystr += '      $display("[%0t] REG READ ERROR: Addr = 0x%0h", $time, addr);\n'
            mystr += '    end else begin\n'
            mystr += '      $display("[%0t] REG READ DONE: Addr = 0x%0h Data = 0x%0h", $time, addr, data);\n'
            mystr += '    end\n'
            mystr += '    #1;\n'
            mystr += '  endtask\n'
            mystr += '\n'
            mystr += 'endclass\n'
            f.write(mystr)

    # =========================
    # INCLUDE FILE (for Verilator)
    # =========================
    if compiler == 'verilator':
        with open(os.path.join(tb_path, 'include_' + str(top) + '_tb.sv'), 'w+') as f:
            mystr = '`ifndef SYN\n'
            mystr += '  `include "ips/pkgs/top_pkg.sv"\n'
            mystr += '  `include "ips/pkgs/prim_util_pkg.sv"\n'
            mystr += '  `include "ips/pkgs/prim_mubi_pkg.sv"\n'
            mystr += '  `include "ips/pkgs/prim_secded_pkg.sv"\n'
            # May add reg_pkg
            if flag_reg_pkg:
                mystr += '  `include "'+str(rtldir)+'/'+str(top)+'_reg_pkg.sv"\n'
            # TLUL / reg_iface extras
            if flag_reg_pkg and itf == 'tlul':
                mystr += '  `include "ips/pkgs/tlul_pkg.sv"\n'
                mystr += '  `include "tb/tlul_utils.sv"\n'
                mystr += '  `include "tb/tlul_if.sv"\n'
            if flag_reg_pkg and itf == 'reg_iface':
                mystr += '`include "tb/reg_utils.sv"\n'
                mystr += '`include "tb/reg_if.sv"\n'
            if vsv == 'sv':
                mystr += '  `include "'+str(rtldir)+'/'+str(top)+'.sv"\n'
            else:
                mystr += '  `include "'+str(rtldir)+'/'+str(top)+'.v"\n'
            mystr += '`else\n'
            for p in prim:
                mystr += '  `include "'+str(p)+'"\n'
            mystr += '  `include "'+str(syndir)+'/'+str(top)+'_synth.v"\n'
            mystr += '`endif\n'
            f.write(mystr)

    # =========================
    # TESTBENCH
    # =========================
    with open(os.path.join(base_path, top + '_tb.sv'), 'w+') as f:
        mystr  = '// Timescale \n'
        mystr += '`timescale 1ns/1ps \n'
        mystr += '// Include files \n'
        if compiler == 'verilator':
            mystr += '`include "tb/include_'+str(top)+'_tb.sv"\n\n'
        else:
            if flag_reg_pkg:
                mystr += '`include "'+str(rtldir)+'/'+str(top)+'_reg_pkg.sv"\n'
            mystr += '`ifndef SYN\n'
            mystr += '  `include "'+str(rtldir)+'/'+str(top)+'.v"\n'
            mystr += '`else\n'
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

        # Inputs
        mystr += '  // Inputs\n'
        for i in inputs:
            w = input_w[inputs.index(i)]
            if w == 1:
                mystr += '  reg '+str(i)+';\n'
            else:
                if '[' in str(w):
                    mystr += '  reg '+str(w)+' '+str(i)+';\n'
                else:
                    if itf=='tlul':
                        mystr += '  '+str(w)+' '+str(i)+';\n'
                    else:
                        mystr += '  '+str(top)+'_reg_pkg::'+str(w)+' '+str(i)+';\n'

        # Outputs
        mystr += '  // Outputs\n'
        for o in outputs:
            w = output_w[outputs.index(o)]
            if w == 1:
                mystr += '  wire '+str(o)+';\n'
            else:
                if '[' in str(w):
                    mystr += '  wire '+str(w)+' '+str(o)+';\n'
                else:
                    if itf=='tlul':
                        mystr += '  '+str(w)+' '+str(o)+';\n'
                    else:
                        mystr += '  '+str(top)+'_reg_pkg::'+str(w)+' '+str(o)+';\n'

        mystr += '\n  integer error_count;\n\n'
        if flag_reg_pkg:
            mystr += '  logic ['+str(top)+'_reg_pkg::DW-1:0] rdata;\n\n'

        # Interfaces (Verilator paths)
        if compiler == 'verilator':
            if flag_reg_pkg and itf == 'tlul':
                mystr += '  tlul_utils tl_utils_inst;\n'
                mystr += '  tlul_if tl_if(.clk_i(clk_i), .rst_ni(rst_ni));\n'
            if flag_reg_pkg and itf == 'reg_iface':
                mystr += '  reg_utils reg_utils_inst;\n'
                mystr += '  reg_if regif(.clk_i(clk_i), .rst_ni(rst_ni));\n'

        # Normalize lists (strip widths and commas)
        for p, name in enumerate(parameters):
            parameters[p] = name.split('=')[0].strip()
        for i, el in enumerate(inputs):
            inputs[i] = inputs[i].split()[-1]
        for i, el in enumerate(outputs):
            outputs[i] = outputs[i].split()[-1]

        # DUT instance
        mystr += '\n  // Device Under Test Instance\n'
        mystr += '  '+str(top)+'\n'
        if parameters_flag:
            mystr += '  `ifndef SYN\n    #(\n'
            if len(parameters) > 1:
                for p in parameters[:-1]:
                    mystr += '      .'+str(p)+'('+str(p)+'),\n'
                mystr += '      .'+str(parameters[-1])+'('+str(parameters[-1])+')\n    ) '
            else:
                mystr += '      .'+str(parameters[-1])+'('+str(parameters[-1])+')\n    ) '
            mystr += '\n  `endif\n'
        mystr += '  u_'+str(top)+' (\n'

        # Inputs wiring (special cases for TLUL/reg_iface)
        for i_name in inputs:
            if itf == 'tlul' and i_name.strip() == 'tl_i':
                mystr += '    .'+i_name+'(tl_if.h2d),\n'
            elif itf == 'reg_iface' and i_name.strip() == 'reg_req_i':
                mystr += '    .'+i_name+'(regif.req),\n'
            else:
                mystr += '    .'+i_name+',\n'

        # Outputs wiring
        for o_name in outputs[:-1]:
            if itf == 'tlul' and o_name.strip() == 'tl_o':
                mystr += '    .'+o_name+'(tl_if.d2h),\n'
            elif itf == 'reg_iface' and o_name.strip() == 'reg_rsp_o':
                mystr += '    .'+o_name+'(regif.rsp),\n'
            else:
                mystr += '    .'+o_name+',\n'
        # last output
        last_o = outputs[-1]
        if itf == 'tlul' and last_o.strip() == 'tl_o':
            mystr += '    .'+last_o+'(tl_if.d2h)\n'
        elif itf == 'reg_iface' and last_o.strip() == 'reg_rsp_o':
            mystr += '    .'+last_o+'(regif.rsp)\n'
        else:
            mystr += '    .'+last_o+'\n'
        mystr += '  );\n\n'

        # Clock generators (for every clk_* input found)
        for c in clk:
            mystr += '  initial begin\n'
            mystr += '    '+str(c)+' = 0;\n'
            mystr += '    forever #(CLK_PERIOD / 2) '+str(c)+' = ~'+str(c)+';\n'
            mystr += '  end\n\n'

        # VCD dump
        mystr += '  // Dump vcd file \n'
        mystr += '  initial begin\n'
        mystr += '    `ifndef SYN\n'
        mystr += '      $dumpfile("'+str(simdir)+'/'+str(top)+'.vcd");\n'
        mystr += '    `else\n'
        mystr += '      $dumpfile("'+str(simdir)+'/'+str(top)+'_syn.vcd");\n'
        mystr += '    `endif\n'
        mystr += '    $dumpvars(0, '+str(top)+'_tb);\n'
        mystr += '  end\n\n'

        # SDF
  
        mystr += '  // SDF backannotation \n'
        mystr += '  `ifndef VERILATOR\n'
        mystr += '    initial begin\n'
        mystr += '      string sdf = "signoff/sdf/'+str(top)+'_ss.sdf";\n'
        mystr += '      $sdf_annotate(sdf, '+str(top)+'_tb.u_'+str(top)+', , , "MAXIMUM");\n'
        mystr += '    end\n\n'
        mystr += '  `endif\n'

        # Error count
        mystr += '  initial begin\n'
        mystr += '    error_count = 0;\n'
        mystr += '  end\n\n'

        # Basic stimulus
        mystr += '  initial begin\n'
        mystr += '    // Init inputs\n'
        # first input typically clk; keep resets low by default
        for i_name in inputs[1:]:
            mystr += '    '+str(i_name)+' = \'0;\n'
        mystr += '    // Asynch Reset\n'
        mystr += '    #(CLK_PERIOD);\n'
        # try to set first rst_* high if present
        if len(rst) > 0:
            mystr += '    '+rst[0]+' = 1;\n'
        else:
            # fallback: toggle the second input as reset if it looks like rst_ni
            if len(inputs) > 1 and 'rst' in inputs[1]:
                mystr += '    '+inputs[1]+' = 1;\n'
        mystr += '    #(CLK_PERIOD);\n'
        mystr += '    // Start main test\n'
        mystr += '    $display("\\nRunning...\\n");\n'

        if compiler == 'verilator':
            if flag_reg_pkg and itf == 'tlul':
                mystr += '    // Usage example\n'
                mystr += '    tl_utils_inst = new(tl_if);\n'
                mystr += '    #(CLK_PERIOD*10);\n'
                mystr += '    tl_utils_inst.tlul_write(32\'h0, 32\'h1, 4\'h0);\n'
                mystr += '    #(CLK_PERIOD*10);\n'
                mystr += '    tl_utils_inst.tlul_read(32\'h0, rdata, 4\'h0);\n'
                mystr += '    $display("Read data: %h", rdata);\n'
                mystr += '    #(CLK_PERIOD*10);\n'
            if flag_reg_pkg and itf == 'reg_iface':
                mystr += '    // Usage example\n'
                mystr += '    reg_utils_inst = new(regif);\n'
                mystr += '    #(CLK_PERIOD*10);\n'
                mystr += '    reg_utils_inst.write(\'h0, 32\'h1);\n'
                mystr += '    #(CLK_PERIOD*10);\n'
                mystr += '    reg_utils_inst.read (\'h0, rdata);\n'
                mystr += '    $display("Read data: 0x%08x", rdata);\n'
                mystr += '    #(CLK_PERIOD*10);\n'

        mystr += '    // INSERT YOUR CODE\n\n'
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
    sys.exit(1)

