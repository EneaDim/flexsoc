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

import os
import sys
import argparse
import Interface as itf

# ARGUMENT PARSING
try:
    ap = argparse.ArgumentParser()
    ap.add_argument("-fsm_name", "--fsm_name", required=True, help="Required input filename")
    ap.add_argument("-f_clk", "--f_clk", type=int, required=True, help="Required Clock Frequency")
    args = vars(ap.parse_args())
    fsm_name = args.get('fsm_name')
    f_clk = args.get('f_clk')
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()
# MAIN
try:
    interface = itf.Interface('FSM Interface from .gv and .csv to System Verilog Modules')
    interface.read_inputs(fsm_name)
    interface.write_sv()
    interface.write_gv()
    #interface.write_tb(f_clk)
except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()
