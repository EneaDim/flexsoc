# ruff: noqa
import argparse
import re
from pathlib import Path


TEMPLATE_HEADER = """module soc #(
  SramInitFile = ""
) (
  // Clock and reset.
  input  logic clk_i,
  input  logic rst_ni,
  // I/O"""

TEMPLATE_FOOTER = """
endmodule
"""


def find_sv_file(module_name, root_dir=".", from_vendor=False):
    if from_vendor:
        root_dir = "vendor"
    else:
        root_dir = "../hw/ips/" + module_name
    for path in Path(root_dir).rglob(f"{module_name}.sv"):
        return path
    return None


def parse_ports(sv_file):
    with open(sv_file, "r", encoding="utf-8") as f:
        content = f.read()

    content = re.sub(r"//.*?$|/\*.*?\*/", "", content, flags=re.DOTALL | re.MULTILINE)
    content = re.sub(r"\s+", " ", content)

    m = re.search(r"\bmodule\b.*?\((?P<plist>.*?)\)\s*;", content)
    if not m:
        return []

    plist = m.group("plist")
    port_decls = [p.strip() for p in plist.split(",") if p.strip()]

    ports = []
    for decl in port_decls:
        dm = re.match(r"^\s*(input|output)\b\s+(.*)$", decl)
        if not dm:
            continue
        dir_ = dm.group(1)
        rest = dm.group(2).strip()
        nm = re.search(r"([A-Za-z_]\w*)\s*$", rest)
        if not nm:
            continue
        name = nm.group(1)
        dtype = rest[: nm.start(1)].strip() or None
        ports.append((dir_, dtype, name))
    return ports


def generate_port_decls(all_ports):
    lines = []
    for name, direction in all_ports.items():
        if "tl_" not in name and "intr" not in name and "clk_i" not in name and "rst_ni" not in name:
            lines.append(f"  {direction} {name},")
    return lines


def generate_module_inst(mod, ports):
    inst_lines = [f"  // Instantiate {mod}", f"  {mod} u_{mod} ("]
    port_assignments = ["    .clk_i", "    .rst_ni", f"    .tl_i(tl_{mod}_h2d)", f"    .tl_o(tl_{mod}_d2h)"]
    port_assignments += [
        f"    .{name}"
        for direction, _, name in ports
        if name not in {"tl_i", "tl_o", "clk_i", "rst_ni"} and "intr" not in name and "alert" not in name
    ]
    port_assignments += [f"    .{name}()" for direction, _, name in ports if "intr" in name]
    port_assignments += [f"    .{name}()" for direction, _, name in ports if "alert_rx" in name]
    port_assignments += [f"    .{name}()" for direction, _, name in ports if "alert_tx" in name]
    inst_lines.append(",\n".join(port_assignments))
    inst_lines.append("  );\n")
    return "\n".join(inst_lines)


def generate_soc_sv(host, device, root_dir, output_file):
    modules_ports = {}
    modules = []
    lowrisc_modules = []
    all_modules = []
    for m in device:
        if m[-1] == "True":
            lowrisc_modules.append(m[0])
        else:
            modules.append(m[0])
    all_modules = lowrisc_modules[1:] + modules

    for mod in all_modules:
        if mod == "uart" and host == "uart":
            continue
        if mod in modules:
            from_vendor = False
        else:
            from_vendor = True
        sv_path = find_sv_file(mod, root_dir, from_vendor)
        if not sv_path:
            raise FileNotFoundError(f"SystemVerilog file for module '{mod}' not found.")
        modules_ports[mod] = parse_ports(sv_path)

    all_ports = {}
    for mod_ports in modules_ports.values():
        for direction, dtype, name in mod_ports:
            if name not in all_ports:
                all_ports[name] = direction + " " + ("" if dtype is None else dtype)

    output_path = Path(output_file).resolve()
    run_dir = output_path.parent.parent
    tb_dir = run_dir / "tb"
    tb_dir.mkdir(parents=True, exist_ok=True)

    with open(output_path, "w", encoding="utf-8") as f:
        f.write(TEMPLATE_HEADER)

        if host == "uart":
            f.write("\n  input  logic cio_rx_i,\n")
            f.write("  output logic cio_tx_o,\n")
            f.write("  output logic cio_tx_en_o,\n")

        port_decls = generate_port_decls(all_ports)
        for decl in port_decls:
            if "alert" not in decl.split()[1]:
                f.write(f"\n{decl}")

        f.seek(f.tell() - 1)
        f.write("\n);\n\n")

        f.write(defaults(host))

        for mod in all_modules:
            if mod == "uart" and host == "uart":
                continue
            f.write(f"  tlul_pkg::tl_h2d_t tl_{mod}_h2d;\n")
            f.write(f"  tlul_pkg::tl_d2h_t tl_{mod}_d2h;\n")

        f.write("\n")
        f.write("  // Our main data bus.\n")
        f.write("  xbar_main xbar (\n")
        f.write("    .clk_i,\n")
        f.write("    .rst_ni,\n\n")

        if host == "ibex":
            f.write("    .tl_ibex_i (tl_ibex_h2d),\n")
            f.write("    .tl_ibex_o (tl_ibex_d2h),\n")
            f.write("    .tl_sram_o (tl_sram_h2d),\n")
            f.write("    .tl_sram_i (tl_sram_d2h),\n")
        elif host == "uart":
            f.write("    .tl_uart_host_i (tl_uart_host_h2d),\n")
            f.write("    .tl_uart_host_o (tl_uart_host_d2h),\n")
            f.write("    .tl_uart_o (tl_uart_h2d),\n")
            f.write("    .tl_uart_i (tl_uart_d2h),\n")

        for mod in modules:
            if mod == "uart" and host == "uart":
                continue
            f.write(f"    .tl_{mod}_o (tl_{mod}_h2d),\n")
            f.write(f"    .tl_{mod}_i (tl_{mod}_d2h),\n")

        f.write("    .scanmode_i (prim_mubi_pkg::MuBi4False)\n")
        f.write("  );\n\n")

        for mod, ports in modules_ports.items():
            f.write(generate_module_inst(mod, ports))

        f.write(TEMPLATE_FOOTER)

    with open(tb_dir / "top_verilator.sv", "w", encoding="utf-8") as f:
        port_decls = generate_port_decls(all_ports)
        clean_decls = [re.sub(r"^\s*(input|output)\s+", "", decl.strip()) for decl in port_decls]
        cleaned_ports = [decl.rstrip(",").strip() + ";" for decl in clean_decls]
        f.write("module top_verilator (input logic clk_i, rst_ni);\n")
        for decl in cleaned_ports:
            parts = decl.split()
            if not parts[0] == "logic":
                if "alert" not in parts[0]:
                    parts = ["logic " + " ".join(parts)]
                else:
                    continue
            f.write(f"  {' '.join(parts)}\n")
        f.write("\n")
        cleaned_ports = [re.sub(r"^\s*(input|output)\s+(logic|wire|reg)?\s*", "", decl.strip()) for decl in port_decls]
        f.write("  soc #(\n")
        f.write("  ) u_soc (\n")
        f.write("    .clk_i,\n")
        f.write("    .rst_ni,\n")
        for decl in cleaned_ports:
            parts = decl.split()
            if "alert" not in parts[0]:
                f.write(f"    .{parts[-1]}\n")
        f.seek(f.tell() - 2)
        f.write("\n);\n\n")
        f.write("  uartdpi #(\n")
        f.write("    .BAUD ( 921_600    ),\n")
        f.write("    .FREQ ( 50_000_000 )\n")
        f.write("  ) u_uartdpi (\n")
        f.write("    .clk_i,\n")
        f.write("    .rst_ni,\n")
        f.write("    .active(1'b1),\n")
        f.write("    .tx_o(cio_rx_i),\n")
        f.write("    .rx_i(cio_tx_o)\n")
        f.write("  );\n")
        if host == "ibex":
            f.write('\n  export "DPI-C" function mhpmcounter_num;\n')
            f.write("  function automatic int unsigned mhpmcounter_num();\n")
            f.write("    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.MHPMCounterNum;\n")
            f.write("  endfunction\n")
            f.write('\n  export "DPI-C" function mhpmcounter_get;\n')
            f.write("  function automatic longint unsigned mhpmcounter_get(int index);\n")
            f.write("    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.mhpmcounter[index];\n")
            f.write("  endfunction\n")
        f.write("endmodule\n")

    with open(tb_dir / "top_verilator.cc", "w", encoding="utf-8") as f:
        f.write('#include <cassert>\n#include <fstream>\n#include <iostream>\n\n')
        f.write('#include "Vtop_verilator__Syms.h"\n')
        f.write('#include "ibex_pcounts.h"\n')
        f.write('#include "verilated_toplevel.h"\n')
        f.write('#include "verilator_memutil.h"\n')
        f.write('#include "verilator_sim_ctrl.h"\n\n')
        f.write('class MySoc {\n public:\n  MySoc(const char *ram_hier_path, int ram_size_words);\n  virtual ~MySoc() {}\n  virtual int Main(int argc, char **argv);\n protected:\n  top_verilator _top;\n  VerilatorMemUtil _memutil;\n  MemArea _ram;\n  virtual int Setup(int argc, char **argv, bool &exit_app);\n  virtual void Run();\n  virtual bool Finish();\n};\n\n')
        f.write('MySoc::MySoc(const char *ram_hier_path, int ram_size_words)\n    : _ram(ram_hier_path, ram_size_words, 4) {}\n\n')
        f.write('int MySoc::Main(int argc, char **argv) {\n  bool exit_app;\n  int ret_code = Setup(argc, argv, exit_app);\n  if (exit_app) return ret_code;\n  Run();\n  if (!Finish()) return 1;\n  return 0;\n}\n\n')
        f.write('int MySoc::Setup(int argc, char **argv, bool &exit_app) {\n  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n  simctrl.SetTop(&_top, &_top.clk_i, &_top.rst_ni, VerilatorSimCtrlFlags::ResetPolarityNegative);\n  _memutil.RegisterMemoryArea("ram", 0x100000, &_ram);\n  simctrl.RegisterExtension(&_memutil);\n  exit_app = false;\n  return simctrl.ParseCommandArgs(argc, argv, exit_app);\n}\n\n')
        f.write('void MySoc::Run() {\n  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n  std::cout << "Simulation of your SoC" << std::endl << "======================" << std::endl << std::endl;\n  simctrl.RunSimulation();\n}\n\n')
        f.write('bool MySoc::Finish() {\n  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n  if (!simctrl.WasSimulationSuccessful()) return false;\n')
        if host == "ibex":
            f.write('  svSetScope(svGetScopeFromName("TOP.top_verilator"));\n  std::cout << "Performance Counters" << std::endl << "====================" << std::endl;\n  std::cout << ibex_pcount_string(false);\n  std::ofstream pcount_csv("sw/performance_counters.csv");\n  pcount_csv << ibex_pcount_string(true);\n')
        f.write("  return true;\n}\n\n")
        f.write('int main(int argc, char **argv) {\n  MySoc my_soc("TOP.top_verilator.u_soc.u_ram.gen_generic.u_impl_generic", 32 * 1024);\n  return my_soc.Main(argc, argv);\n}\n')

    with open(run_dir / "soc.core", "w", encoding="utf-8") as f:
        f.write('CAPI=2:\nname: "enea:soc:main"\ndescription: "An easy to build SoC"\n')
        f.write("filesets:\n")
        f.write("  files_rtl:\n")
        f.write("    depend:\n")
        if host == "ibex":
            f.write("      - lowrisc:ibex:ibex_top_tracing\n")
            f.write("      - lowrisc:prim:onehot\n")
            f.write("      - lowrisc:prim:alert\n")
            f.write("      - lowrisc:tlul:adapter_host\n")
            f.write("      - lowrisc:tlul:adapter_reg\n")
        for mod in modules:
            f.write(f"      - prj:ip:{mod}\n")
        f.write("    files:\n")
        f.write("      - rtl/tl_main_pkg.sv\n")
        f.write("      - rtl/xbar_main.sv\n")
        f.write("      - rtl/soc.sv\n")
        f.write("    file_type: systemVerilogSource\n\n")
        f.write("  files_verilator:\n")
        f.write("    depend:\n")
        f.write("      - lowrisc:ibex:sim_shared\n")
        f.write("      - lowrisc:dv_verilator:memutil_verilator\n")
        f.write("      - lowrisc:dv_verilator:simutil_verilator\n")
        f.write("      - lowrisc:dv_verilator:ibex_pcounts\n")
        f.write("      - lowrisc:dv_dpi_c:uartdpi:0.1\n")
        f.write("      - lowrisc:dv_dpi_sv:uartdpi:0.1\n")
        f.write("    files:\n")
        f.write("      - tb/top_verilator.sv: { file_type: systemVerilogSource }\n")
        f.write("      - tb/top_verilator.cc: { file_type: cppSource }\n\n")
        f.write("parameters:\n")
        f.write("  PRIM_DEFAULT_IMPL:\n")
        f.write("    datatype: str\n")
        f.write("    paramtype: vlogdefine\n")
        f.write('    description: Primitives implementation to use, e.g. "prim_pkg::ImplGeneric".\n\n')
        f.write("targets:\n")
        f.write("  default: &default_target\n")
        f.write("    filesets:\n")
        f.write("      - files_rtl\n\n")
        f.write("  sim:\n")
        f.write("    <<: *default_target\n")
        f.write("    default_tool: verilator\n")
        f.write("    filesets_append:\n")
        f.write("      - files_verilator\n")
        f.write("    toplevel: top_verilator\n")
        f.write("    tools:\n")
        f.write("      verilator:\n")
        f.write("        mode: cc\n")
        f.write("        verilator_options:\n")
        f.write("          - '--trace'\n")
        f.write("          - '--trace-fst'\n")
        f.write("          - '--trace-structs'\n")
        f.write("          - '--trace-params'\n")
        f.write("          - '--trace-max-array 1024'\n")
        f.write('          - \'-CFLAGS "-Wall -DVM_TRACE_FMT_FST -DTOPLEVEL_NAME=top_verilator"\'\n')
        f.write('          - \'-LDFLAGS "-pthread -lutil -lelf"\'\n')
        f.write('          - "-Wno-WIDTHEXPAND"\n')
        f.write('          - "-Wno-WIDTHTRUNC"\n')
        f.write('          - "-Wno-MODDUP"\n')
        f.write('          - "-Wno-UNOPTFLAT"\n')
        f.write('          - "--unroll-count 72"\n')
        f.write("    parameters:\n")
        f.write("      - PRIM_DEFAULT_IMPL=prim_pkg::ImplGeneric\n")


def defaults(host):
    out = f"""
  localparam int unsigned MemSize       = 128 * 1024;
  localparam int unsigned DataWidth     = 32;
  localparam int unsigned AddrOffset    = $clog2(DataWidth / 8);
  localparam int unsigned SramAddrWidth = $clog2(MemSize) - AddrOffset;

  logic                     {host}_req;
  logic                     {host}_gnt;
  logic                     {host}_we;
  logic [(DataWidth/8)-1:0] {host}_be;
  logic [DataWidth-1:0]     {host}_addr;
  logic [DataWidth-1:0]     {host}_wdata;
  logic                     {host}_rvalid;
  logic [DataWidth-1:0]     {host}_rdata;
  logic                     {host}_err;
"""
    if host == "ibex":
        out += """
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

  tlul_pkg::tl_h2d_t tl_ibex_h2d;
  tlul_pkg::tl_d2h_t tl_ibex_d2h;
  tlul_pkg::tl_h2d_t tl_sram_h2d;
  tlul_pkg::tl_d2h_t tl_sram_d2h;

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

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      sram_data_rvalid  <= '0;
      sram_instr_rvalid <= '0;
    end else begin
      sram_data_rvalid <= sram_data_req & ~sram_data_we;
      sram_instr_rvalid <= sram_instr_req;
    end
  end
"""
    elif host == "uart":
        out += """
  tlul_pkg::tl_h2d_t tl_uart_host_h2d;
  tlul_pkg::tl_d2h_t tl_uart_host_d2h;
  tlul_pkg::tl_h2d_t tl_uart_h2d;
  tlul_pkg::tl_d2h_t tl_uart_d2h;

  uart u_uart (
    .clk_i, .rst_ni,
    .tl_i(tl_uart_h2d),
    .tl_o(tl_uart_d2h),
    .req_o   (uart_req),
    .gnt_i   (uart_gnt),
    .addr_o  (uart_addr),
    .we_o    (uart_we),
    .wdata_o (uart_wdata),
    .be_o    (uart_be),
    .valid_i (uart_rvalid),
    .rdata_i (uart_rdata),
    .err_i   (uart_err),
    .cio_rx_i,
    .cio_tx_o,
    .cio_tx_en_o
  );
"""
    out += f"""
  tlul_adapter_host {host}_host_adapter (
    .clk_i,
    .rst_ni,
    .req_i        ({host}_req),
    .gnt_o        ({host}_gnt),
    .addr_i       ({host}_addr),
    .we_i         ({host}_we),
    .wdata_i      ({host}_wdata),
    .wdata_intg_i ('0),
    .be_i         ({host}_be),
    .instr_type_i (prim_mubi_pkg::MuBi4False),
    .valid_o      ({host}_rvalid),
    .rdata_o      ({host}_rdata),
    .rdata_intg_o (),
    .err_o        ({host}_err),
    .intg_err_o   (),
"""
    if host == "ibex":
        out += """
    .tl_o         (tl_ibex_h2d),
    .tl_i         (tl_ibex_d2h)
  );

  tlul_adapter_sram #(
    .SramAw           ( SramAddrWidth - AddrOffset ),
    .EnableRspIntgGen ( 0                          )
  ) sram_a_device_adapter (
    .clk_i,
    .rst_ni,
    .tl_i        (tl_sram_h2d),
    .tl_o        (tl_sram_d2h),
    .en_ifetch_i (prim_mubi_pkg::MuBi4True),
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
    .compound_txn_in_progress_o (),
    .readback_en_i              (prim_mubi_pkg::MuBi4False),
    .readback_error_o           (),
    .wr_collision_i             (1'b0),
    .write_pending_i            (1'b0)
  );
"""
    else:
        out += """
    .tl_o         (tl_uart_host_h2d),
    .tl_i         (tl_uart_host_d2h)
  );
"""
    return out


def main():
    parser = argparse.ArgumentParser(description="Generate soc.sv with module instantiations.")
    parser.add_argument(
        "--host", "-host", required=True, type=str,
        help="Host selection: ibex - uart"
    )
    parser.add_argument(
        "--device", "-device",
        action="append",
        nargs=4,
        metavar=("NAME", "BASE_ADDR", "SIZE_BYTE", "FROM_LR"),
        help="Add a device with NAME, BASE_ADDR, and SIZE_BYTE",
        required=True
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
    generate_soc_sv(args.host, args.device, args.root, args.output)


if __name__ == "__main__":
    main()
