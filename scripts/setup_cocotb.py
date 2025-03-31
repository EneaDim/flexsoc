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
    # Source files under rtl
    sourcefiles = [f for f in os.listdir('rtl') if os.path.isfile(os.path.join('rtl', f))]
    # Create Makefile
    with open(path+'Makefile', 'w+') as f:
        mystr = '# Makefile\n'
        mystr += 'TOPLEVEL_LANG = verilog\n'
        mystr += 'PWD = $(shell pwd)\n'
        mystr += '# Import path for model used in tb_mul.py file\n'
        mystr += 'export PYTHONPATH := $(PWD)/../model:$(PYTHONPATH)\n'
        mystr += '# Verilog sources\n'
        for i, file in enumerate(sourcefiles):
            if not file.split('.')[0] == str(top):
                if i == 0:
                    mystr += 'VERILOG_SOURCES = $(PWD)/../rtl/'+str(file)+'\n'
                else:
                    mystr += 'VERILOG_SOURCES += $(PWD)/../rtl/'+str(file)+'\n'
        mystr += 'VERILOG_SOURCES += $(shell pwd)/../rtl/'+str(top)+'.sv\n'
        mystr += '# Top\n'
        mystr += 'TOPLEVEL = '+str(top)+'\n'
        mystr += '# Tb filename\n'
        mystr += 'MODULE = '+str(top)+'_tb\n'
        mystr += '# Cocotb include\n'
        mystr += 'include $(shell cocotb-config --makefiles)/Makefile.sim\n'
        f.write(mystr)
    # Create utils.py
    with open(path+'utils.py', 'w+') as f:
        mystr = 'import random\n'
        mystr += 'import math\n'
        mystr += '\n'
        mystr += 'def rand_bin_values(nbit):\n'
        mystr += '    a = random.randint(0, 2**(nbit)-1)\n'
        mystr += '    b = random.randint(0, 2**(nbit)-1)\n'
        mystr += '\n'
        mystr += '    return a, b\n'
        f.write(mystr)
    # Create cocotb test wrapper
    with open(path+top+'_tb.py', 'w+') as f:
        mystr = '# Import utils functions\n'
        mystr += 'import utils\n'
        mystr += '# Import random lib\n'
        mystr += 'import random\n'
        mystr += '# Import cocotb\n'
        mystr += 'import cocotb\n'
        mystr += 'from cocotb.clock import Clock\n'
        mystr += 'from cocotb.triggers import Timer, FallingEdge, RisingEdge\n\n'
        mystr += '# RSTN COROUTINE\n'
        mystr += '@cocotb.coroutine\n'
        mystr += 'async def rst_ni(rst_ni):\n'
        mystr += "    await Timer(1, units='ns')\n"
        mystr += '    rst_ni.value = 1\n'
        mystr += "    await Timer(1, units='ns')\n"
        mystr += '    rst_ni.value = 0\n'
        mystr += "    await Timer(1, units='ns')\n"
        mystr += '    rst_ni.value = 1\n'
        mystr += "    await Timer(2, units='ns')\n\n"
        mystr += '# WAIT One Clock Cycle COROUTINE\n'
        mystr += '@cocotb.coroutine\n'
        mystr += 'async def WaitOneClockCycle(dut):\n'
        mystr += '    await FallingEdge(dut.clk_i)\n'
        mystr += '    await FallingEdge(dut.clk_i)\n\n'
        mystr += '# TEST 1\n'
        mystr += '@cocotb.test()\n'
        mystr += 'async def tb_'+str(top)+'(dut):\n'
        mystr += '    """ Test that multiplies 2 random unsigned numbers """\n'
        mystr += '    # Parameters for utils function\n'
        mystr += '    # nbit = "number of bits of input"\n'
        mystr += '    # n_op = "number of iteration over the loop"\n'
        mystr += '    """ CLK  """\n'
        mystr += "    clock = Clock(dut.clk_i, 10, units='ns')\n"
        mystr += '    cocotb.start_soon(clock.start())\n'
        mystr += '    """ RSTn """\n'
        mystr += '    await rst_ni(dut.rst_ni)\n'
        mystr += '    """ Wait CLK falling edge"""\n'
        mystr += '    await FallingEdge(dut.clk_i)\n'
        mystr += '    """ Loop setting the inputs """\n'
        mystr += '    for i in range(n_op):\n'
        mystr += '        """ Random value on inputs"""\n'
        mystr += '        # 1) Set input values\n'
        mystr += '        # a, b = utils.rand_bin_values(nbit)\n'
        mystr += '        # 2) Set dut."input".value =  "value"\n'
        mystr += '        """ Set expected outcome from model"""\n'
        mystr += '        # dut.a.value = a\n'
        mystr += '        # dut.b.value = b\n'
        mystr += '        # expected_outcome = model.ref_model()\n'
        mystr += '        """ Wait 1 clock cycle to check the result"""\n'
        mystr += '        await WaitOneClockCycle(dut)\n'
        mystr += '        """ Check the result"""\n'
        mystr += '        #assert dut."output".value == expected_outcome, "output q was incorrect on the {}th cycle".format(i)\n'
        mystr += '        #assert dut.out.value == expected_outcome, "output q was incorrect on the {}th cycle".format(i)\n'
        f.write(mystr)
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()

