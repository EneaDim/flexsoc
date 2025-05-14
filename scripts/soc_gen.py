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

import argparse
import os
import re
from pathlib import Path

# Header of the top module (with default ports)
TEMPLATE_HEADER = """module soc #(
  SramInitFile = ""
) (
  // Clock and reset.
  input  logic clk_i,
  input  logic rst_ni,
  // I/O"""

# Footer of the module
TEMPLATE_FOOTER = """
endmodule
"""

# Default modules (placeholders only)
DEFAULT_MODULES = [
    "ibex_top_tracing",
    "tlul_adapter_host",
    "tlul_adapter_sram",
    "xbar_main",
    "prim_ram_2p"
]

def find_sv_file(module_name, root_dir="."):
    for path in Path(root_dir).rglob(f"{module_name}.sv"):
        return path
    return None

def parse_ports(sv_file):
    ports = []
    with open(sv_file, 'r') as f:
        content = f.read()
    # Remove comments
    content = re.sub(r"//.*?$|/\*.*?\*/", "", content, flags=re.DOTALL | re.MULTILINE)

    # Flatten multi-line declarations
    content = re.sub(r"\s*\n\s*", " ", content)

    # Match direction, optional logic/wire, optional width, optional pkg type, and final signal name
    pattern = re.compile(
        r'\b(input|output)\b\s+(?:logic|wire)?\s*(?:\[[^\]]*\]\s*)?(?:(?:\w+::)?\w+\s+)?(\w+)',
        re.MULTILINE
    )

    ports = pattern.findall(content)
    
    return ports

def parse_parameters(file_path):
    """
    Parse parameters from a SystemVerilog module file.

    Returns a list of tuples: [(param_name, default_value or None), ...]
    """
    parameters = []
    with open(file_path, 'r') as f:
        content = f.read()

    # Remove single-line and multi-line comments
    content = re.sub(r'//.*?\n|/\*.*?\*/', '', content, flags=re.S)

    # Match parameter list inside module #( ... )
    param_block_match = re.search(r'module\s+\w+\s*#\s*\((.*?)\)\s*\(', content, re.S)
    if not param_block_match:
        return parameters  # No parameters

    param_block = param_block_match.group(1)

    # Split and extract parameters
    param_lines = param_block.split(',')
    for line in param_lines:
        line = line.strip()
        # Match: parameter type? name = value
        match = re.match(r'(parameter\s+)?(?:\w+\s+)?(\w+)\s*=\s*([^,]+)', line)
        if match:
            param_name = match.group(2)
            param_value = match.group(3).strip()
            parameters.append((param_name, param_value))
        else:
            # Just parameter name without default
            match = re.match(r'(parameter\s+)?(?:\w+\s+)?(\w+)', line)
            if match:
                parameters.append((match.group(2), None))

    return parameters

def generate_port_decls(all_ports):
    lines = []
    for name, direction in all_ports.items():
        if "tl_" not in name and "intr" not in name and "clk_i" not in name and "rst_ni" not in name:
            lines.append(f"  {direction} logic {name},")
    return lines

def generate_module_inst(mod, ports):
    inst_lines = [f"  // Instantiate {mod}", f"  {mod} u_{mod} ("]
    port_assignments = ["    .clk_i", "    .rst_ni"]
    port_assignments += [f"    .tl_i(tl_{mod}_h2d)"]
    port_assignments += [f"    .tl_o(tl_{mod}_d2h)"]
    port_assignments += [f"    .{name}" for direction, name in ports if not name == 'tl_i' and not name == 'tl_o' and not name == 'clk_i' and not name == 'rst_ni' and not 'intr' in name]
    port_assignments += [f"    .{name}()" for direction, name in ports if 'intr' in name]
    inst_lines.append(",\n".join(port_assignments))
    inst_lines.append("  );\n")
    return "\n".join(inst_lines)

def generate_soc_sv(modules, root_dir, output_file):
    modules_ports = {}

    # Parse user-provided modules
    for mod in modules:
        sv_path = find_sv_file(mod, root_dir)
        if not sv_path:
            raise FileNotFoundError(f"SystemVerilog file for module '{mod}' not found.")
        ports = parse_ports(sv_path)
        modules_ports[mod] = ports

    # Collect unique top-level ports
    all_ports = {}
    for mod_ports in modules_ports.values():
        for direction, name in mod_ports:
            if name not in all_ports:
                all_ports[name] = direction
            else:
                # Warn on duplicate with differing direction
                if all_ports[name] != direction:
                    print(f"⚠️ Warning: Port '{name}' appears with conflicting directions.")
    with open(output_file, 'w') as f:
        # Write module header
        f.write(TEMPLATE_HEADER)

        # Append unique ports
        port_decls = generate_port_decls(all_ports)
        for decl in port_decls:
            f.write(f"\n{decl}")

        # Remove last comma and close header
        f.seek(f.tell() -1)
        f.write("\n);\n\n")
       
        # Basic
        f.write(defaults())

        # Tilelink for modules
        for mod in modules:
            f.write(f"  tlul_pkg::tl_h2d_t tl_{mod}_h2d;\n")
            f.write(f"  tlul_pkg::tl_d2h_t tl_{mod}_d2h;\n")

        f.write(f"\n")
        f.write(f"  // Our main data bus.\n")
        f.write(f"  xbar_main xbar (\n")
        f.write(f"    // Clock and reset.\n")
        f.write(f"    .clk_i,\n")
        f.write(f"    .rst_ni,\n")
        f.write(f"\n")
        f.write(f"    // Host interfaces.\n")
        f.write(f"    .tl_ibex_lsu_i (tl_ibex_lsu_h2d),\n")
        f.write(f"    .tl_ibex_lsu_o (tl_ibex_lsu_d2h),\n")
        f.write(f"\n")
        f.write(f"    // Device interfaces.\n")
        f.write(f"    .tl_sram_o     (tl_sram_h2d),\n")
        f.write(f"    .tl_sram_i     (tl_sram_d2h),\n")
        for mod in modules:
            f.write(f"    .tl_{mod}_o     (tl_{mod}_h2d),\n")
            f.write(f"    .tl_{mod}_i     (tl_{mod}_d2h),\n")
        f.write(f"\n")
        f.write(f"    .scanmode_i (prim_mubi_pkg::MuBi4False)\n")
        f.write(f"  );\n")


        f.write("\n")

        # Custom modules
        for mod, ports in modules_ports.items():
            f.write(generate_module_inst(mod, ports))

        f.write(TEMPLATE_FOOTER)

    with open('tb/top_verilator.sv', 'w') as f:
        port_decls = generate_port_decls(all_ports)
        # Delete input or output keyword
        clean_decls = [re.sub(r'^\s*(input|output)\s+', '', decl.strip()) for decl in port_decls]
        # Substitute "," with ";"
        cleaned_ports = [decl.rstrip(',').strip() + ';' for decl in clean_decls]
        f.write(f"module top_verilator (input logic clk_i, rst_ni);\n")
        for decl in cleaned_ports:
            f.write(f"  {decl}\n")
        f.write(f"\n")
        cleaned_ports = [ re.sub(r'^\s*(input|output)\s+(logic|wire|reg)?\s*', '', decl.strip()) for decl in port_decls ]
        f.write(f"  // Our SoC\n")
        f.write(f"  soc #(\n")
        f.write(f"  ) u_soc (\n")
        f.write(f"    .clk_i,\n")
        f.write(f"    .rst_ni,\n")
        for decl in cleaned_ports:
            f.write(f"    .{decl}\n")
        # Remove last comma and close header
        f.seek(f.tell() -2)
        f.write("\n);\n\n")
        f.write(f"  // Virtual UART\n")
        f.write(f"  uartdpi #(\n")
        f.write(f"    .BAUD ( 921_600    ),\n")
        f.write(f"    .FREQ ( 50_000_000 )\n")
        f.write(f"  ) u_uartdpi (\n")
        f.write(f"    .clk_i,\n")
        f.write(f"    .rst_ni,\n")
        f.write(f"    .active(1'b1       ),\n")
        f.write(f"    .tx_o  (cio_rx_i),\n")
        f.write(f"    .rx_i  (cio_tx_o)\n")
        f.write(f"  );\n")
        f.write(f"\n")
        f.write(f'  export "DPI-C" function mhpmcounter_num;\n')
        f.write(f"\n")
        f.write(f"  function automatic int unsigned mhpmcounter_num();\n")
        f.write(f"    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.MHPMCounterNum;\n")
        f.write(f"  endfunction\n")
        f.write(f"\n")
        f.write(f'  export "DPI-C" function mhpmcounter_get;\n')
        f.write(f"\n")
        f.write(f"  function automatic longint unsigned mhpmcounter_get(int index);\n")
        f.write(f"    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.mhpmcounter[index];\n")
        f.write(f"  endfunction\n")
        f.write(f"\n")
        f.write(f"endmodule\n")

    with open('tb/top_verilator.cc', 'w') as f:
        f.write('#include <cassert>\n')
        f.write('#include <fstream>\n')
        f.write('#include <iostream>\n')
        f.write('\n')
        f.write('#include "Vtop_verilator__Syms.h"\n')
        f.write('#include "ibex_pcounts.h"\n')
        f.write('#include "verilated_toplevel.h"\n')
        f.write('#include "verilator_memutil.h"\n')
        f.write('#include "verilator_sim_ctrl.h"\n')
        f.write('\n')
        f.write('class MySoc {\n')
        f.write(' public:\n')
        f.write('  MySoc(const char *ram_hier_path, int ram_size_words);\n')
        f.write('  virtual ~MySoc() {}\n')
        f.write('  virtual int Main(int argc, char **argv);\n')
        f.write('\n')
        f.write('\n')
        f.write(' protected:\n')
        f.write('  top_verilator _top;\n')
        f.write('  VerilatorMemUtil _memutil;\n')
        f.write('  MemArea _ram;\n')
        f.write('\n')
        f.write('  virtual int Setup(int argc, char **argv, bool &exit_app);\n')
        f.write('  virtual void Run();\n')
        f.write('  virtual bool Finish();\n')
        f.write('};\n')
        f.write('\n')
        f.write('MySoc::MySoc(const char *ram_hier_path, int ram_size_words)\n')
        f.write('    : _ram(ram_hier_path, ram_size_words, 4) {}\n')
        f.write('\n')
        f.write('int MySoc::Main(int argc, char **argv) {\n')
        f.write('  bool exit_app;\n')
        f.write('  int ret_code = Setup(argc, argv, exit_app);\n')
        f.write('\n')
        f.write('  if (exit_app) {\n')
        f.write('    return ret_code;\n')
        f.write('  }\n')
        f.write('\n')
        f.write('  Run();\n')
        f.write('\n')
        f.write('  if (!Finish()) {\n')
        f.write('    return 1;\n')
        f.write('  }\n')
        f.write('\n')
        f.write('  return 0;\n')
        f.write('}\n')
        f.write('\n')
        f.write('int MySoc::Setup(int argc, char **argv, bool &exit_app) {\n')
        f.write('  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n')
        f.write('\n')
        f.write('  simctrl.SetTop(&_top, &_top.clk_i, &_top.rst_ni,\n')
        f.write('                 VerilatorSimCtrlFlags::ResetPolarityNegative);\n')
        f.write('\n')
        f.write('  _memutil.RegisterMemoryArea("ram", 0x100000, &_ram);\n')
        f.write('  simctrl.RegisterExtension(&_memutil);\n')
        f.write('\n')
        f.write('  exit_app = false;\n')
        f.write('  return simctrl.ParseCommandArgs(argc, argv, exit_app);\n')
        f.write('}\n')
        f.write('\n')
        f.write('void MySoc::Run() {\n')
        f.write('  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n')
        f.write('\n')
        f.write('  std::cout << "Simulation of your SoC" << std::endl\n')
        f.write('            << "======================" << std::endl\n')
        f.write('            << std::endl;\n')
        f.write('\n')
        f.write('  simctrl.RunSimulation();\n')
        f.write('}\n')
        f.write('\n')
        f.write('bool MySoc::Finish() {\n')
        f.write('  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n')
        f.write('\n')
        f.write('  if (!simctrl.WasSimulationSuccessful()) {\n')
        f.write('    return false;\n')
        f.write('  }\n')
        f.write('\n')
        f.write('  // Set the scope to the root scope, the ibex_pcount_string function otherwise\n')
        f.write("  // doesn't know the scope itself. Could be moved to ibex_pcount_string, but\n")
        f.write('  // would require a way to set the scope name from here, similar to MemUtil.\n')
        f.write('  svSetScope(svGetScopeFromName("TOP.top_verilator"));\n')
        f.write('\n')
        f.write('  std::cout << "Performance Counters" << std::endl\n')
        f.write('            << "====================" << std::endl;\n')
        f.write('  std::cout << ibex_pcount_string(false);\n')
        f.write('\n')
        f.write('  std::ofstream pcount_csv("sw/performance_counters.csv");\n')
        f.write('  pcount_csv << ibex_pcount_string(true);\n')
        f.write('\n')
        f.write('  return true;\n')
        f.write('}\n')
        f.write('\n')
        f.write('int main(int argc, char **argv) {\n')
        f.write('  MySoc my_soc(\n')
        f.write('      "TOP.top_verilator.u_soc.u_ram.gen_generic.u_impl_generic",\n')
        f.write('      32 * 1024 // 32k words = 128 KiB\n')
        f.write('  );\n')
        f.write('\n')
        f.write('  return my_soc.Main(argc, argv);\n')
        f.write('}\n')

    with open('soc.core', 'w') as f:
        f.write(f'CAPI=2:\n')
        f.write(f'name: "enea:soc:main"\n')
        f.write(f'description: "An easy to build SoC"\n')
        f.write(f'filesets:\n')
        f.write(f'  files_rtl:\n')
        f.write(f'    depend:\n')
        f.write(f'      - lowrisc:ibex:ibex_top_tracing\n')
        f.write(f'      - lowrisc:ip:uart\n')
        f.write(f'      - lowrisc:ip:xbar_main\n')
        f.write(f'      - lowrisc:prim:onehot\n')
        f.write(f'      - lowrisc:tlul:adapter_host\n')
        f.write(f'      - lowrisc:tlul:adapter_reg\n')
        for mod in modules[1:]:
            f.write(f'      - prj:ip:{mod}\n')
        f.write(f'    files:\n')
        f.write(f'      - top/soc.sv\n')
        f.write(f'    file_type: systemVerilogSource\n')
        f.write(f'\n')
        f.write(f'  files_verilator:\n')
        f.write(f'    depend:\n')
        f.write(f'      - lowrisc:ibex:sim_shared\n')
        f.write(f'      - lowrisc:dv_verilator:memutil_verilator\n')
        f.write(f'      - lowrisc:dv_verilator:simutil_verilator\n')
        f.write(f'      - lowrisc:dv_verilator:ibex_pcounts\n')
        f.write(f'      - lowrisc:dv_dpi_c:uartdpi:0.1\n')
        f.write(f'      - lowrisc:dv_dpi_sv:uartdpi:0.1\n')
        f.write(f'    files:\n')
        f.write('      - tb/top_verilator.sv: { file_type: systemVerilogSource }\n')
        f.write('      - tb/top_verilator.cc: { file_type: cppSource }\n')
        f.write(f'\n')
        f.write(f'parameters:\n')
        f.write(f'  # For value definition, please see ip/prim/rtl/prim_pkg.sv\n')
        f.write(f'  PRIM_DEFAULT_IMPL:\n')
        f.write(f'    datatype: str\n')
        f.write(f'    paramtype: vlogdefine\n')
        f.write(f'    description: Primitives implementation to use, e.g. "prim_pkg::ImplGeneric".\n')
        f.write(f'\n')
        f.write(f'targets:\n')
        f.write(f'  default: &default_target\n')
        f.write(f'    filesets:\n')
        f.write(f'      - files_rtl\n')
        f.write(f'\n')
        f.write(f'  sim:\n')
        f.write(f'    <<: *default_target\n')
        f.write(f'    default_tool: verilator\n')
        f.write(f'    filesets_append:\n')
        f.write(f'      - files_verilator\n')
        f.write(f'    toplevel: top_verilator\n')
        f.write(f'    tools:\n')
        f.write(f'      verilator:\n')
        f.write(f'        mode: cc\n')
        f.write(f'        verilator_options:\n')
        f.write(f"          # Disabling tracing reduces compile times but doesn't have a\n")
        f.write(f'          # huge influence on runtime performance.\n')
        f.write(f"          - '--trace'\n")
        f.write(f"          - '--trace-fst' # this requires -DVM_TRACE_FMT_FST in CFLAGS below!\n")
        f.write(f"          - '--trace-structs'\n")
        f.write(f"          - '--trace-params'\n")
        f.write(f"          - '--trace-max-array 1024'\n")
        f.write(f"          - '-CFLAGS "+'"-Wall -DVM_TRACE_FMT_FST -DTOPLEVEL_NAME=top_verilator"'+"'\n")
        f.write(f"          - '-LDFLAGS "+'"-pthread -lutil -lelf"'+"'\n")
        f.write(f'          - "-Wno-WIDTHEXPAND"\n')
        f.write(f'          - "-Wno-WIDTHTRUNC"\n')
        f.write(f'          - "-Wno-MODDUP"\n')
        f.write(f'          # RAM primitives wider than 64bit (required for ECC) fail to build in\n')
        f.write(f'          # Verilator without increasing the unroll count (see Verilator#1266)\n')
        f.write(f'          - "--unroll-count 72"\n')
        f.write(f'    parameters:\n')
        f.write(f'      - PRIM_DEFAULT_IMPL=prim_pkg::ImplGeneric\n')


def defaults():
    return """
  // Local parameters.
  localparam int unsigned MemSize       = 128 * 1024; // 128 KiB
  localparam int unsigned DataWidth     = 32;
  localparam int unsigned AddrOffset    = $clog2(DataWidth / 8);
  localparam int unsigned SramAddrWidth = $clog2(MemSize) - AddrOffset;  
  

  // Read/write signals.
  logic                     ibex_req;
  logic                     ibex_gnt;
  logic                     ibex_we;
  logic [(DataWidth/8)-1:0] ibex_be;
  logic [DataWidth-1:0]     ibex_addr;
  logic [DataWidth-1:0]     ibex_wdata;
  logic                     ibex_rvalid;
  logic [DataWidth-1:0]     ibex_rdata;
  logic                     ibex_err;
  logic                     sram_data_req;
  logic                     sram_data_we;
  logic [SramAddrWidth-1:0] sram_data_addr;
  logic [DataWidth-1:0]     sram_data_wmask;
  logic [DataWidth-1:0]     sram_data_wdata;
  logic                     sram_data_rvalid;
  logic [DataWidth-1:0]     sram_data_rdata;
  logic                     sram_instr_req;
  logic [DataWidth-1:0]     sram_instr_addr;
  logic                     sram_instr_rvalid;
  logic [DataWidth-1:0]     sram_instr_rdata;

  // Instantiate our Ibex CPU.
  ibex_top_tracing #(
    .MHPMCounterNum  ( 10                  ),
    .RV32M           ( ibex_pkg::RV32MFast ),
    .RV32B           ( ibex_pkg::RV32BNone ),
    .DbgTriggerEn    ( 1'b0                ),
    .DbgHwBreakNum   ( 0                   )
  ) u_ibex_top_tracing (
    .clk_i,
    .rst_ni,

    .test_en_i   ('b0),
    .scan_rst_ni (1'b1),
    .ram_cfg_i   ('b0),

    .hart_id_i   (32'b0),
    // First instruction executed is at 0x0 + 0x80.
    .boot_addr_i (32'h00100000),

    .instr_req_o        (sram_instr_req),
    .instr_gnt_i        (sram_instr_req),
    .instr_rvalid_i     (sram_instr_rvalid),
    .instr_addr_o       (sram_instr_addr),
    .instr_rdata_i      (sram_instr_rdata),
    .instr_rdata_intg_i ('0),
    .instr_err_i        ('0),

    .data_req_o        (ibex_req),
    .data_gnt_i        (ibex_gnt),
    .data_rvalid_i     (ibex_rvalid),
    .data_we_o         (ibex_we),
    .data_be_o         (ibex_be),
    .data_addr_o       (ibex_addr),
    .data_wdata_o      (ibex_wdata),
    .data_wdata_intg_o ( ),
    .data_rdata_i      (ibex_rdata),
    .data_rdata_intg_i ('0),
    .data_err_i        (ibex_err),

    .irq_software_i (1'b0),
    .irq_timer_i    (1'b0),
    .irq_external_i (1'b0),
    .irq_fast_i     (15'b0),
    .irq_nm_i       (1'b0),

    .scramble_key_valid_i ('0),
    .scramble_key_i       ('0),
    .scramble_nonce_i     ('0),
    .scramble_req_o       ( ),

    .debug_req_i         ('0),
    .crash_dump_o        ( ),
    .double_fault_seen_o ( ),

    .fetch_enable_i         ('1),
    .alert_minor_o          ( ),
    .alert_major_internal_o ( ),
    .alert_major_bus_o      ( ),
    .core_sleep_o           ( )
  );

  // Our RAM
  prim_ram_2p #(
    .Width           ( DataWidth                         ),
    .DataBitsPerMask ( 8                                 ),
    .Depth           ( 2 ** (SramAddrWidth - AddrOffset) ),
    .MemInitFile     ( SramInitFile                      )
  ) u_ram (
    .clk_a_i (clk_i),
    .clk_b_i (clk_i),

    .a_req_i   (sram_data_req),
    .a_write_i (sram_data_we),
    .a_addr_i  (sram_data_addr),
    .a_wdata_i (sram_data_wdata),
    .a_wmask_i (sram_data_wmask),
    .a_rdata_o (sram_data_rdata),

    .b_req_i   (sram_instr_req),
    .b_write_i (1'b0),
    .b_addr_i  (sram_instr_addr[SramAddrWidth-1+AddrOffset:AddrOffset]),
    .b_wdata_i (DataWidth'(0)),
    .b_wmask_i (DataWidth'(0)),
    .b_rdata_o (sram_instr_rdata),

    .cfg_i ('0)
  );

  // Single-cycle read response.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      sram_data_rvalid  <= '0;
      sram_instr_rvalid <= '0;
    end else begin
      sram_data_rvalid <= sram_data_req & ~sram_data_we;
      sram_instr_rvalid <= sram_instr_req;
    end
  end


  // TileLink host adapter to connect Ibex to bus.
  tlul_adapter_host ibex_lsu_host_adapter (
    .clk_i,
    .rst_ni,

    .req_i        (ibex_req),
    .gnt_o        (ibex_gnt),
    .addr_i       (ibex_addr),
    .we_i         (ibex_we),
    .wdata_i      (ibex_wdata),
    .wdata_intg_i ('0),
    .be_i         (ibex_be),
    .instr_type_i (prim_mubi_pkg::MuBi4False),

    .valid_o      (ibex_rvalid),
    .rdata_o      (ibex_rdata),
    .rdata_intg_o (),
    .err_o        (ibex_err),
    .intg_err_o   (),

    .tl_o         (tl_ibex_lsu_h2d),
    .tl_i         (tl_ibex_lsu_d2h)
  );

  // TileLink device adapter to connect SRAM to bus.
  tlul_adapter_sram #(
    .SramAw           ( SramAddrWidth - AddrOffset ),
    .EnableRspIntgGen ( 0                          )
  ) sram_a_device_adapter (
    .clk_i,
    .rst_ni,

    // TL-UL interface.
    .tl_i        (tl_sram_h2d),
    .tl_o        (tl_sram_d2h),

    // Control interface.
    .en_ifetch_i (prim_mubi_pkg::MuBi4True),

    // SRAM interface.
    .req_o        (sram_data_req),
    .req_type_o   ( ),
    .gnt_i        (sram_data_req),
    .we_o         (sram_data_we),
    .addr_o       (sram_data_addr),
    .wdata_o      (sram_data_wdata),
    .wmask_o      (sram_data_wmask),
    .intg_error_o ( ),
    .rdata_i      (sram_data_rdata),
    .rvalid_i     (sram_data_rvalid),
    .rerror_i     (2'b00),

    // Readback functionality not required.
    .compound_txn_in_progress_o (),
    .readback_en_i              (prim_mubi_pkg::MuBi4False),
    .readback_error_o           (),
    .wr_collision_i             (1'b0),
    .write_pending_i            (1'b0)
  );
  

  // TileLink signals.
  tlul_pkg::tl_h2d_t tl_ibex_lsu_h2d;
  tlul_pkg::tl_d2h_t tl_ibex_lsu_d2h;
  tlul_pkg::tl_h2d_t tl_sram_h2d;
  tlul_pkg::tl_d2h_t tl_sram_d2h;
"""

def main():
    parser = argparse.ArgumentParser(description="Generate soc.sv with module instantiations.")
    parser.add_argument(
        "--modules", "-m", nargs="+", required=True,
        help="List of module names to include (e.g., uart spi_host)"
    )
    parser.add_argument(
        "--root", "-r", default=".",
        help="Root directory to search for Verilog files"
    )
    parser.add_argument(
        "--output", "-o", default="soc.sv",
        help="Output SystemVerilog file (default: soc.sv)"
    )

    args = parser.parse_args()
    generate_soc_sv(args.modules, args.root, args.output)

if __name__ == "__main__":
    main()

