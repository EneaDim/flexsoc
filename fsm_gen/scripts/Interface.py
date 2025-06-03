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
import re
import math
import stat

class Interface(object):

  def __init__(self, name):
    self.name = name
    self.overall_elements = []

  def read_inputs(self, fsm_name):
    try:
      self.fsm_name = fsm_name
      mypath = os.getcwd()
      mypath += '/inputs/'
      my_lines = []
      file_string = mypath + self.fsm_name + '.txt'
      f = open(file_string, 'r')
      for line in f:
        line = line.replace("!", "~ ")
        line = line.replace("~", "~ ")
        line = line.replace("not", "~")
        line = line.replace("and", "&")
        line = line.replace("or","|")
        line = line.replace("nand", "%") 
        line = line.replace("nor", "*") 
        line = line.replace("xor", "^") 
        line = line.replace("(", " ( ")
        line = line.replace(")", " ) ")
        line = line.replace("[", " [ ")
        line = line.replace("]", " ] ")
        line = line.replace("->", " -> ")
        line = line.replace(" 1 ", "1")
        line = line.replace("  1  ", "1")
        line = line.replace("  ", " ") 
        line = line.replace("   ", " ")
        line = line.replace("  ", " ") 
        my_line = line.strip()
        my_line = my_line.split()
        if my_line:
          my_lines.append(' '.join(my_line))
      f.close()
      # FILTER OUT THE GV FILE
      for i in range(0, len(my_lines)):
        my_lines[i] = my_lines[i].strip()
        my_lines[i] = my_lines[i].split()
      flag = False
      self.source = []
      self.dest = []
      self.edges = []
      logic_comb = []
      # Iterate over file rows
      for elements in my_lines:
        if elements[0] == '#':
          continue
        if elements[0] == '/' and elements[1] == '/':
          continue
        if len(elements) > 3 :
          self.source.append(elements[0])
          self.dest.append(elements[2])
          elements = ' '.join(elements)
          for char in elements:
            if (char == '"'):
              if (flag == True):
                break
              flag = True
            if flag:
              logic_comb.append(char)
          logic_comb = ''.join(logic_comb).split('"')
          self.edges.append(logic_comb[1])
          logic_comb = []
          flag = False
      if len(self.edges) != len(self.source) or len(self.edges) != len(self.dest) or len(self.source) != len(self.dest):
        assert('Error, some problem in GV file\n ')

      for e in range(0, len(self.edges)):
        self.edges[e].split()
      self.signals = []
      not_sigs = ['(', '((', '(((', ')))', '))', ')', 'not', 'and', 'or', 'xor', '|', '&', '~', '%', '^', '*', '']
      for edge in self.edges:
        for el in edge.split(' '):
          if el in not_sigs:
            pass
          else:
            if not el in self.signals:
              self.signals.append(el)
      for e in range(0, len(self.edges)):
        self.edges[e] = self.edges[e].replace("~ ", "~")
      file_string = mypath + self.fsm_name + '.csv'
      out_file = open(file_string, 'r+')
      self.states = []
      self.out_values = []
      my_lines = []
      self.out_values = []
      for line in out_file:
        splitted_line = re.split(',|;|\n', line)
        splitted_line = splitted_line[:-1]
        my_lines.append(splitted_line)
      out_file.close()
      my_lines[0][1:] = [str(f).strip() for f in my_lines[0][1:]]
      self.out_names = my_lines[0][1:]
      my_lines = my_lines[1:]
      for i in range(0, len(my_lines)):
        self.states.append(my_lines[i][0])
        self.out_values.append(my_lines[i][1:])
      out_file.close()
      # DEFINE NEXT_STATES DATA STRUCTURE
      self.next_states = []
      for i in range(0, len(self.states)):
        dest_states = []
        for j in range(0, len(self.source)):
          if self.states[i] == self.source[j]:
            dest_states.append(self.dest[j])
        self.next_states.append(dest_states)
    except Exception as err:
        exc_type, exc_value, exc_traceback = sys.exc_info()
        print('\033[38;5;208mError during CORE CODE:\nError Type: '+str(exc_type)+'\nLine number: '+str(exc_traceback.tb_lineno)+'\033[0;0m')
        print(err)
        sys.exit()

  def write_sv(self):
    mypath = os.getcwd()
    mypath += '/outputs/'
    file_string = mypath + self.fsm_name + '.sv'
    print(file_string)
    sv_file = open(file_string, 'w+')
    mystr = 'module '+str(self.fsm_name)+' (\n'
    mystr += '  input  logic clk_i,\n'
    if not 'rst_ni' in self.signals:
      mystr += '  input  logic rst_ni,\n'
    for i in self.signals:
      if not i == '1':
        mystr += '  input  logic '+str(i)+',\n'
    for i in self.out_names[:-1]:
      mystr += '  output logic '+str(i)+',\n'
    mystr += '  output logic '+str(self.out_names[-1])+'\n);\n\n'
    for i in self.out_names:
      mystr += '  logic '+str(i)+'_d;\n'
    mystr += '\n  typedef enum logic ['+str(math.ceil(math.log2(len(self.states)))-1)+':0] { \n'
    for s in self.states[:-1]:
      mystr += '    '+str(s)+',\n'
    mystr += '    '+str(self.states[-1])+'\n  } state_fsm ;\n\n'
    mystr += '  state_fsm current_state, next_state; \n\n'
    mystr += '  // STATE LATCHING\n'
    mystr += '  always_ff @(posedge clk_i or negedge rst_ni)\n'
    mystr += '    begin: state_latching\n'
    mystr += '      if (~rst_ni) begin\n'
    mystr += '        current_state <= '+str(self.states[0])+';\n'
    mystr += '      end'
    mystr += ' else begin\n'
    mystr += '        current_state <= next_state;\n'
    mystr += '      end\n'
    mystr += '    end\n\n'
    mystr += '  // OUTPUT LATCHING\n'
    mystr += '  always_ff @(posedge clk_i or negedge rst_ni)\n'
    mystr += '    begin: output_latching\n'
    mystr += '      if (~rst_ni) begin\n'
    j = 0
    for i in self.out_names:
      mystr += "        "+str(i)+" <= 1'b"+str(self.out_values[0][j])+";\n"
      j += 1
    mystr += '      end'
    mystr += ' else begin\n'
    for i in self.out_names:
      mystr += "        "+str(i)+" <= "+str(i)+"_d;\n"
    mystr += '      end\n'
    mystr += '    end\n\n'
    mystr += '  // STATE TRANSITION\n'
    mystr += '  always_comb begin\n'
    mystr += '    next_state = current_state;\n'
    mystr += '    unique case (current_state)\n'
    j=0
    for state in self.states:
      mystr += '      '+str(state)+': begin\n'
      q = 0
      for dest in self.next_states[j]:
        for i in range(0, len(self.source)):
          if self.source[i] == state and self.dest[i] == dest:
            break
        if self.edges[i] == '1':
          mystr += '        next_state = '+str(self.dest[i])+';\n'
          for h in range(0, len(self.states)):
            if self.states[h] == self.dest[i]:
              break
          mystr += '      end\n'
          break
        else:
          if q == 0:
            mystr += '        if ('+str(self.edges[i])+') begin\n'
            mystr += '          next_state = '+str(self.dest[i])+';\n'
            for h in range(0, len(self.states)):
              if self.states[h] == self.dest[i]:
                break
            mystr += '        end'
          else:
            mystr += ' else if ('+str(self.edges[i])+') begin\n'
            mystr += '          next_state = '+str(self.dest[i])+';\n'
            for h in range(0, len(self.states)):
              if self.states[h] == self.dest[i]:
                break
            mystr += '        end'
        q += 1
        #print(self.source[i], self.dest[i], self.edges[i])    
      if not self.edges[i] == '1':
        mystr += ' else begin\n'
        mystr += '          next_state = '+str(state)+';\n'
        mystr += '        end\n'
        mystr += '      end\n'
      j += 1
    mystr += '      default: begin\n'
    mystr += '        next_state = '+str(self.states[0])+';\n'
    mystr += '      end\n'
    mystr += '    endcase\n'
    mystr += '  end\n\n'
    mystr += '  // OUTPUT DEFINITION\n'
    mystr += '  always_comb begin\n'
    j = 0
    for i in self.out_names:
      mystr += "    "+str(i)+"_d = 1'b"+str(self.out_values[0][j])+";\n"
      j += 1
    mystr += '    unique case (current_state)\n'
    j=0
    for state in self.states:
      mystr += '      '+str(state)+': begin\n'
      q = 0
      for dest in self.next_states[j]:
        for i in range(0, len(self.source)):
          if self.source[i] == state and self.dest[i] == dest:
            break
        if self.edges[i] == '1':
          for h in range(0, len(self.states)):
            if self.states[h] == self.dest[i]:
              break
          k = 0
          for p in self.out_names:
            mystr += "        "+str(p)+"_d = 1'b"+str(self.out_values[h][k])+";\n"
            k += 1
          mystr += '      end\n'
          break
        else:
          if q == 0:
            mystr += '        if ('+str(self.edges[i])+') begin\n'
            for h in range(0, len(self.states)):
              if self.states[h] == self.dest[i]:
                break
            k = 0
            for p in self.out_names:
              mystr += "          "+str(p)+"_d = 1'b"+str(self.out_values[h][k])+";\n"
              k += 1
            mystr += '        end'
          else:
            mystr += ' else if ('+str(self.edges[i])+') begin\n'
            for h in range(0, len(self.states)):
              if self.states[h] == self.dest[i]:
                break
            k = 0
            for p in self.out_names:
              mystr += "          "+str(p)+"_d = 1'b"+str(self.out_values[h][k])+";\n"
              k += 1
            mystr += '        end'
        q += 1
        #print(self.source[i], self.dest[i], self.edges[i])    
      if not self.edges[i] == '1':
        mystr += ' else begin\n'
        k = 0
        for p in self.out_names:
          mystr += "          "+str(p)+"_d = 1'b"+str(self.out_values[j][k])+";\n"
          k += 1
        mystr += '        end\n'
        mystr += '      end\n'
      j += 1 
    mystr += '      default: begin\n'
    for i in self.out_names:
      mystr += "        "+str(i)+"_d = 1'b"+str(self.out_values[0][0])+";\n"
      j += 1
    mystr += '      end\n'
    mystr += '    endcase\n'
    mystr += '  end\n'
    mystr += 'endmodule\n'
    sv_file.write(mystr)
    sv_file.close()

  def write_tb(self, f_CLK):
    self.f_CLK = f_CLK
    mypath = os.getcwd()
    mypath += '/outputs/'
    my_lines = []
    file_string = mypath + self.fsm_name + '_tb.sv'
    sv_file = open(file_string, 'w+')
    mystr = 'module '+str(self.fsm_name)+'_tb;\n\n'
    mystr += 'reg clk_i;\n'
    for i in self.signals:
      if not i == '1':
        mystr += 'reg '+str(i)+';\n'
    for i in self.out_names:
      mystr += 'wire '+str(i)+';\n'
    mystr += '\n'+str(self.fsm_name)+' '+str(self.fsm_name)+'_u (\n'
    mystr += '.clk_i(clk_i),\n'
    for i in self.signals:
      if not i == '1':
        mystr += '.'+str(i)+'('+str(i)+'),\n'
    for i in self.out_names[:-1]:
      mystr += '.'+str(i)+'('+str(i)+'),\n'
    mystr += '.'+str(self.out_names[-1])+'('+str(self.out_names[-1])+')\n'
    mystr += ');\n\n'
    mystr += 'always begin \n'
    mystr += '  #'+str((1/self.f_CLK*1000)/2)+' clk_i = ~clk_i;\n'
    mystr += 'end\n\n'
    mystr += 'initial\n\nbegin\n\n'
    mystr += 'clk_i = 0;\n'
    for i in self.signals:
      if not i == '1':
        mystr += str(i)+' = 0;\n'
    mystr += '\n#100;\n'
    mystr += 'rst_ni = 1;\n'
    mystr += '\n#100;\n'
    mystr += '#50 $finish;\n\n'
    mystr += 'end\n\n'
    mystr += 'endmodule\n\n'
    sv_file.write(mystr)
    sv_file.close()

  def write_gv(self):
    # READ PROCEDURE
    mypath = os.getcwd()
    mypath += '/inputs/'
    my_lines = []
    file_string = mypath + self.fsm_name + '.txt'
    f_r = open(file_string, 'r')
    for line in f_r:
      line = line.replace(":", "[ label =")
      line = line.replace(";", " ] ;")
      my_lines.append(line)
    f_r.close()  
    # WRITE PROCEDURE
    mypath = os.getcwd()
    mypath += '/outputs/'
    file_string = mypath + self.fsm_name + '.gv'
    f_w = open(file_string, 'w+')
    mystr = 'digraph ' + self.fsm_name + ' {\n'
    for line in my_lines:
      mystr += line
    mystr += '}\n'
    f_w.write(mystr)
    f_w.close()  
