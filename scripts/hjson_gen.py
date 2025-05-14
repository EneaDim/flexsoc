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
    ap.add_argument("-o", "--output", type=str, required='False', help="Output Folder")
    args = vars(ap.parse_args())
    top = args.get("top")
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
    with open(path+top+'.hjson', 'w+') as f:
        mystr = '{\n'
        mystr += '  name:               "'+str(top)+'",\n'
        mystr += '  human_name:         "'+str(top)+'",\n'
        mystr += '  one_line_desc:      "",\n'
        mystr += "  one_paragraph_desc: '''\n"
        mystr += "  '''\n"
        mystr += '  // Unique comportable IP identifier defined under KNOWN_CIP_IDS in the regtool.\n'
        mystr += '  cip_id:             "1",\n'
        mystr += '  design_spec:        "",\n'
        mystr += '  dv_doc:             "",\n'
        mystr += '  hw_checklist:       "",\n'
        mystr += '  sw_checklist:       "",\n'
        mystr += '  revisions: [\n'
        mystr += '  {\n'
        mystr += '    version:            "1.0.0",\n'
        mystr += '    life_stage:         "",\n'
        mystr += '    design_stage:       "",\n'
        mystr += '    verification_stage: "",\n'
        mystr += '    commit_id:          "",\n'
        mystr += '    notes:              ""\n'
        mystr += '  }\n'
        mystr += '    ]\n'
        mystr += '  clocking: [{clock: "clk_i", reset: "rst_ni"}],\n'
        mystr += '  bus_interfaces: [\n'
        mystr += '    { protocol: "tlul", direction: "device" }\n'
        mystr += '  ],\n'
        mystr += '  //available_input_list: [\n'
        mystr += '  //  { name: "input_i", desc: "input" }\n'
        mystr += '  //],\n'
        mystr += '  //available_output_list: [\n'
        mystr += '  //  { name: "output_o", desc: "output" }\n'
        mystr += '  //],\n'
        mystr += '  //interrupt_list: [\n'
        mystr += '  //  { name: "main_interrupt",\n'
        mystr += '  //    desc: "main_interrupt"}\n'
        mystr += '  //],\n'
        mystr += '  //alert_list: [\n'
        mystr += '  //  { name: "fatal_fault",\n'
        mystr += "  //    desc: '''\n"
        mystr += '  //    This fatal alert is triggered when ...\n'
        mystr += "  //    '''\n"
        mystr += '  //  }\n'
        mystr += '  //],\n'
        mystr += '  //features: [\n'
        mystr += '  //  { name: "feature1",\n'
        mystr += "  //    desc: '''\n"
        mystr += '  //      Feature 1.\n'
        mystr += "  //    '''\n"
        mystr += '  //  },\n'
        mystr += '  //]\n'
        mystr += '  //inter_signal_list: [\n'
        mystr += '  //  { struct: "logic"\n'
        mystr += '  //    type:   "uni"\n'
        mystr += '  //    name:   "trigger"\n'
        mystr += "  //    desc: '''\n"
        mystr += '  //      Trigger request\n'
        mystr += "  //    '''\n"
        mystr += '  //    act:    "req"\n'
        mystr += '  //  }\n'
        mystr += '  //]\n'
        mystr += '  //countermeasures: [\n'
        mystr += '  //  { name: "BUS.INTEGRITY",\n'
        mystr += '  //    desc: "End-to-end bus integrity scheme."\n'
        mystr += '  //  }\n'
        mystr += '  //]\n'
        mystr += '  //param_list: [\n'
        mystr += '  //  { name:    "FifoDepth",\n'
        mystr += '  //    desc:    "Number of bytes in the FIFO.",\n'
        mystr += '  //    type:    "int",\n'
        mystr += '  //    default: "64",\n'
        mystr += '  //    local:   "true",\n'
        mystr += '  //  }\n'
        mystr += '  //]\n'
        mystr += '  regwidth: "32",\n'
        mystr += '  registers: [\n'
        mystr += '    { name: "CTRL",\n'
        mystr += '      desc: "UART control register",\n'
        mystr += '      swaccess: "rw",\n'
        mystr += '      hwaccess: "hro",\n'
        mystr += '      fields: [\n'
        mystr += '        { bits: "0",\n'
        mystr += '          name: "EN",\n'
        mystr += '          desc: "enable"\n'
        mystr += '        }\n'
        mystr += '        { bits: "1",\n'
        mystr += '          name: "RST",\n'
        mystr += '          desc: "reset"\n'
        mystr += '        }\n'
        mystr += '        { bits: "31:16",\n'
        mystr += '          name: "SETTING",\n'
        mystr += '          desc: "Basic setting 16 bits."\n'
        mystr += '        }\n'
        mystr += '      ]\n'
        mystr += '    },\n'
        mystr += '    { name:     "STATUS"\n'
        mystr += '      desc:     "UART live status register"\n'
        mystr += '      swaccess: "ro"\n'
        mystr += '      hwaccess: "hrw"\n'
        mystr += '      hwext:    "true"\n'
        mystr += '      hwre:     "true"\n'
        mystr += '      fields: [\n'
        mystr += '        { bits: "0"\n'
        mystr += '          name: "FULL"\n'
        mystr += '          desc: "Buffer is full"\n'
        mystr += '        }\n'
        mystr += '        { bits: "1"\n'
        mystr += '          name: "EMPTY"\n'
        mystr += '          desc: "Buffer is empty"\n'
        mystr += '        }\n'
        mystr += '      ]\n'
        mystr += '    }\n'
        mystr += '    { name: "RDATA",\n'
        mystr += '      desc: "read data",\n'
        mystr += '      swaccess: "ro",\n'
        mystr += '      hwaccess: "hrw",\n'
        mystr += '      hwext: "true",\n'
        mystr += '      hwre: "true",\n'
        mystr += '      fields: [\n'
        mystr += '        { bits: "7:0" }\n'
        mystr += '      ]\n'
        mystr += '      tags: [// read wdata when fifo is empty, dut may return unknown data\n'
        mystr += '             "excl:CsrAllTests:CsrExclCheck"]\n'
        mystr += '    }\n'
        mystr += '    { name: "WDATA",\n'
        mystr += '      desc: "write data",\n'
        mystr += '      swaccess: "wo",\n'
        mystr += '      hwaccess: "hro",\n'
        mystr += '      hwqe: "true",\n'
        mystr += '      fields: [\n'
        mystr += '        { bits: "7:0" }\n'
        mystr += '      ]\n'
        mystr += "      tags: [// don't write to wdata - it affects several other csrs\n"
        mystr += '             "excl:CsrNonInitTests:CsrExclWrite"]\n'
        mystr += '    }\n'
        mystr += '  ]\n'
        mystr += '}\n'
        f.write(mystr)
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

