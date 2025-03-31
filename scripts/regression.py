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
import glob
import subprocess
import sys

# Directory containing RTL and testbench files
TB_DIR = './tb/regression'

def extract_top_names():
    """Extract base names from testbench files."""
    testbenches = glob.glob(os.path.join(TB_DIR, '*.sv'))
    top_names = [os.path.basename(tb).replace('.sv', '').split('_tb')[0] for tb in testbenches]
    return top_names

def extract_testbenchs(top):
    """Extract testenches."""
    testbenches = glob.glob(os.path.join(TB_DIR, ''+str(top)+'_tb*.sv'))
    testbenches = [os.path.basename(tb).replace('.sv', '') for tb in testbenches]
    return testbenches

def run_make(target, top_name=None, tb=None):
    """Run a make target in a subprocess."""
    command = ['make', target]
    if top_name and tb:
        command += [f'TOP={top_name}']
        command += [f'TESTBENCH=regression/{tb}']
    try:
        result = subprocess.run(command, check=True)
        print(f"Make action '{target}' completed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error during make action '{target}': {e}")
        sys.exit(1)

def main():
    # Extract base names and testbench files
    top_names = extract_top_names()
    for name in top_names:
    # Run lint for each testbench
    for top in top_names:
       testbenches = extract_testbenchs(top)
       for tb in testbenches:
           run_make('sim', top, tb)

if __name__ == "__main__":
    main()
