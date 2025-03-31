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
    # Define the output folder
    if output_folder:
        path = './' + output_folder + '/'
    else:
        path = './'
    # Create model.py
    with open(path+'model.py', 'w+') as f:
        mystr = 'import math\n'
        mystr += 'import time\n'
        mystr += '\n'
        mystr += 'def _sum(a, b):\n'
        mystr += '    expected_outcome = a + b\n'
        mystr += '    return expected_outcome\n'
        mystr += '\n'
        mystr += 'def _sub(a, b):\n'
        mystr += '    expected_outcome = a - b\n'
        mystr += '    return expected_outcome\n'
        mystr += '\n'
        mystr += 'def _multiply(a, b):\n'
        mystr += '    expected_outcome = a * b\n'
        mystr += '    return expected_outcome\n'
        mystr += '\n'
        mystr += 'def _divide(a, b):\n'
        mystr += '    expected_outcome = a / b\n'
        mystr += '    return expected_outcome\n'
        f.write(mystr)

except Exception as err:
    exc_type, exc_value, exc_traceback = sys.exc_info()
    print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
    print(err)
    sys.exit()


