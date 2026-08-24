"""SoC configuration, generation, FuseSoC and software scaffold flow."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

_cfg_SUPPORTED_HOSTS = {"ibex", "uart"}
KNOWN_BASES = {
    "uart": 0x80000000,
    "uart_master": 0x80000000,
    "pwm": 0x80020000,
    "gpio": 0x80040000,
    "rv_timer": 0x80060000,
    "spi_host": 0x80080000,
}
HOST_IPS = {"ibex", "ibex_top_tracing"}


@dataclass(frozen=True, slots=True)
class SoCDevice:
    """Describe one memory-mapped device used by generated SoC flows."""

    name: str
    base: str
    size: str = "0x00001000"
    from_lr: str = "False"

    def make_call(self) -> str:
        """Render this device as one Make `add_device` evaluation."""

        return f"$(eval $(call add_device,{self.name},{self.base},{self.size},{self.from_lr}))"

    def args(self) -> tuple[str, str, str, str]:
        """Return CLI argument fields consumed by SoC backend generators."""

        return self.name, self.base, self.size, self.from_lr


@dataclass(frozen=True, slots=True)
class SoCConfig:
    """Resolved host and memory map emitted for one SoC run."""

    host: str
    devices: tuple[SoCDevice, ...]

    def args(self) -> tuple[str, ...]:
        """Return flat generator arguments for host and devices."""

        parts = ["--host", self.host]
        for device in self.devices:
            parts.extend(("--device", *device.args()))
        return tuple(parts)


def _cfg_run_dir(workspace: str | Path, run_top: str, run_id: str) -> Path:
    """Return the canonical run directory for a workspace/run identity."""

    return Path(workspace).expanduser().resolve() / "runs" / run_top / run_id


def _cfg_loaded_ips(workspace: str | Path, run_top: str, run_id: str) -> tuple[str, ...]:
    """List IP directories staged under a run workspace."""

    ips_dir = _cfg_run_dir(workspace, run_top, run_id) / "ips"
    if not ips_dir.exists():
        return ()
    return tuple(sorted(path.name for path in ips_dir.iterdir() if path.is_dir()))


def builtin_devices(host: str) -> tuple[SoCDevice, ...]:
    """Return the built-in memory map for a supported host profile."""

    if host == "ibex":
        return (
            SoCDevice("sram", "0x00100000", "0x00100000", "True"),
            SoCDevice("uart", "0x80000000"),
            SoCDevice("pwm", "0x80020000"),
            SoCDevice("gpio", "0x80040000"),
            SoCDevice("rv_timer", "0x80060000"),
            SoCDevice("spi_host", "0x80080000"),
        )
    if host == "uart":
        return (
            SoCDevice("uart", "0x80000000"),
            SoCDevice("pwm", "0x80020000"),
            SoCDevice("gpio", "0x80040000"),
            SoCDevice("rv_timer", "0x80060000"),
        )
    raise SystemExit(f"ERROR: Unknown HOST '{host}'. Supported builtin hosts: ibex, uart")


def _cfg_normalize_host(host: str | None) -> str | None:
    """Normalize and validate an optional host override."""

    if not host:
        return None
    normalized = host.strip().lower()
    if normalized not in _cfg_SUPPORTED_HOSTS:
        raise SystemExit(f"ERROR: unsupported host '{host}'. Use ibex or uart.")
    return normalized


def resolve_host(ip_names: tuple[str, ...], default_host: str | None = None) -> str:
    """Resolve the host profile from an explicit hint or staged IP names."""

    if default_host:
        return default_host
    names = set(ip_names)
    if names & HOST_IPS:
        return "ibex"
    if names & {"uart", "uart_master"}:
        return "uart"
    raise SystemExit("ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips")


def workspace_devices(ip_names: tuple[str, ...], host: str) -> tuple[SoCDevice, ...]:
    """Build a deterministic memory map from staged workspace IP names."""

    devices = [SoCDevice("sram", "0x00100000", "0x00100000", "True")] if host == "ibex" else []
    next_base = 0x800A0000
    used_bases = set(KNOWN_BASES.values())

    for ip in dict.fromkeys(ip_names):
        if ip in HOST_IPS:
            continue
        base = KNOWN_BASES.get(ip)
        if base is None:
            while next_base in used_bases:
                next_base += 0x00020000
            base = next_base
            used_bases.add(base)
            next_base += 0x00020000
        devices.append(SoCDevice(ip, f"0x{base:08X}"))
    return tuple(devices)


def resolve_soc_config(
    workspace: str | Path,
    run_top: str,
    run_id: str,
    *,
    default_host: str | None = None,
    mode: str = "auto",
) -> SoCConfig:
    """Resolve a SoC config from builtin profiles, workspace IPs, or both."""

    host_hint = _cfg_normalize_host(default_host)
    if mode not in {"workspace", "builtin", "auto"}:
        raise SystemExit("ERROR: --mode must be workspace, builtin, or auto")

    if mode == "builtin":
        if not host_hint:
            raise SystemExit("ERROR: --mode builtin requires --default-host <ibex|uart>")
        return SoCConfig(host_hint, builtin_devices(host_hint))

    ips = _cfg_loaded_ips(workspace, run_top, run_id)
    if mode == "workspace" or ips:
        host = resolve_host(ips, host_hint)
        return SoCConfig(host, workspace_devices(ips, host))

    if host_hint:
        return SoCConfig(host_hint, builtin_devices(host_hint))
    raise SystemExit(
        "ERROR: no loaded IPs found under workspace/runs/<run_top>/<run_id>/ips "
        "and no supported builtin host selected. Use HOST=ibex or HOST=uart, or load IPs into the run."
    )


def render_make_config(config: SoCConfig) -> str:
    """Render a Make fragment containing host and device memory map data."""

    lines = [
        f"HOST ?= {config.host}",
        "DEVLIST :=",
        "define add_device",
        "DEVLIST += $(1)",
        "BASE_$(1) := $(2)",
        "SIZE_$(1) := $(3)",
        "FROM_LR_$(1) := $(4)",
        "endef",
        *(device.make_call() for device in config.devices),
        "SOC_MEMORY_MAP ?= $(foreach d,$(DEVLIST),--device $(d) $(BASE_$(d)) $(SIZE_$(d)) $(FROM_LR_$(d)))",
    ]
    return "\n".join(lines) + "\n"


def render_args(config: SoCConfig) -> str:
    """Render flat command-line arguments for SoC generators."""

    return " ".join(config.args()) + "\n"






import shutil
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True, slots=True)
class SoCStartConfig:
    """Configuration required to initialize a SoC run."""

    workspace: Path
    run_top: str
    run_id: str

    @property
    def run_dir(self) -> Path:
        """Return the canonical run directory for this SoC build."""

        return self.workspace.expanduser().resolve() / "runs" / self.run_top / self.run_id

    @property
    def ips_dir(self) -> Path:
        """Return the directory containing staged IP bundles."""

        return self.run_dir / "ips"


def _start_loaded_ips(ips_dir: Path) -> tuple[Path, ...]:
    """Return staged IP bundle directories sorted by name."""

    return tuple(sorted(path for path in ips_dir.iterdir() if path.is_dir()))



def _copy_tree(src: Path, dst: Path) -> bool:
    """Copy one optional verification asset tree."""

    if not src.exists():
        return False
    if dst.exists():
        shutil.rmtree(dst)
    shutil.copytree(src, dst)
    return True


def stage_ip_verification_assets(config: SoCStartConfig, ips: tuple[Path, ...]) -> Path:
    """Stage per-IP tests/models into the SoC run root."""

    manifest = config.run_dir / "tests" / "loaded_tests.txt"
    lines: list[str] = []
    for ip in ips:
        copied_tests = _copy_tree(ip / "tb" / "tests", config.run_dir / "tests" / ip.name)
        copied_model = _copy_tree(ip / "model", config.run_dir / "model" / ip.name)
        if copied_tests or copied_model:
            lines.append(f"{ip.name}: tests={int(copied_tests)} model={int(copied_model)}")
    manifest.parent.mkdir(parents=True, exist_ok=True)
    manifest.write_text("\n".join(lines) + ("\n" if lines else ""), encoding="utf-8")
    return manifest

def read_filelists(ip_dir: Path) -> tuple[str, ...]:
    """Read staged IP common/IP filelists, with legacy fallback."""

    rtl = ip_dir / "rtl"
    files = [rtl / "rtl_common.f", rtl / "rtl_ip.f"]
    if not any(path.exists() for path in files):
        files = [rtl / "rtl_list.f"]
    lines: list[str] = []
    for flist in files:
        if flist.exists():
            lines.extend(
                line
                for raw in flist.read_text(encoding="utf-8").splitlines()
                if (line := raw.strip()) and not line.startswith("#")
            )
    return tuple(lines)


def fallback_rtl_sources(ip_dir: Path) -> tuple[str, ...]:
    """Discover RTL files when an IP bundle has no explicit filelist."""

    rtl_dir = ip_dir / "rtl"
    if not rtl_dir.exists():
        return ()
    files = sorted(rtl_dir.glob("*.sv")) + sorted(rtl_dir.glob("*.v"))
    return tuple(path.resolve().as_posix() for path in files if path.is_file())


def merged_rtl_sources(ips: tuple[Path, ...]) -> tuple[str, ...]:
    """Merge IP RTL sources while preserving first-seen ordering."""

    merged: list[str] = []
    seen: set[str] = set()
    for ip_dir in ips:
        for source in read_filelists(ip_dir) or fallback_rtl_sources(ip_dir):
            if source not in seen:
                seen.add(source)
                merged.append(source)
    return tuple(merged)


def write_soc_start_summary(config: SoCStartConfig, ips: tuple[Path, ...], rtl_ip: Path) -> Path:
    """Write a compact summary for the initialized SoC run."""

    doc_dir = config.run_dir / "doc"
    doc_dir.mkdir(parents=True, exist_ok=True)
    path = doc_dir / "soc_start.txt"
    path.write_text(
        "\n".join(
            (
                f"run_top={config.run_top}",
                f"run_id={config.run_id}",
                f"run_dir={config.run_dir}",
                f"loaded_ips={len(ips)}",
                f"rtl_ip={rtl_ip}",
            )
        )
        + "\n",
        encoding="utf-8",
    )
    return path


def initialize_soc_run(config: SoCStartConfig) -> Path:
    """Create SoC run folders and write the merged RTL filelist."""

    if not config.ips_dir.exists():
        raise FileNotFoundError(f"missing ips directory: {config.ips_dir}")

    ips = _start_loaded_ips(config.ips_dir)
    if not ips:
        raise ValueError(f"no loaded IPs under: {config.ips_dir}")

    for dirname in ("rtl", "tb", "sim", "logs", "doc", "tests", "model"):
        (config.run_dir / dirname).mkdir(parents=True, exist_ok=True)

    (config.ips_dir / "loaded_ips.txt").write_text("".join(f"{ip.name}\n" for ip in ips), encoding="utf-8")
    sources = merged_rtl_sources(ips)
    if not sources:
        raise ValueError(f"no RTL sources found under loaded IPs in: {config.ips_dir}")

    rtl_ip = config.run_dir / "rtl" / "rtl_ip.f"
    rtl_ip.write_text("\n".join(sources) + "\n", encoding="utf-8")
    (config.run_dir / "rtl" / "rtl_list.f").unlink(missing_ok=True)
    stage_ip_verification_assets(config, ips)
    write_soc_start_summary(config, ips, rtl_ip)
    return rtl_ip






import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass(frozen=True, slots=True)
class XbarDevice:
    """Describe one device node attached to the generated crossbar."""

    name: str
    base_addr: str
    size_byte: str
    from_lr: str = "False"


@dataclass(frozen=True, slots=True)
class XbarConfig:
    """Group all inputs needed to render one crossbar configuration."""

    host: str
    devices: tuple[XbarDevice, ...]


def _xbar_normalize_host(host: str) -> str:
    """Map user-facing host names to generated crossbar node names."""

    return "uart_host" if host.strip().lower() == "uart" else "ibex"


def device_node(device: XbarDevice) -> dict[str, Any]:
    """Render one device as a JSON-ready crossbar node."""

    return {
        "name": device.name,
        "type": "device",
        "clock": "clk_i",
        "reset": "rst_ni",
        "xbar": False,
        "addr_range": [{"base_addr": device.base_addr, "size_byte": device.size_byte}],
    }


def host_node(name: str) -> dict[str, Any]:
    """Render the host node shared by all generated configurations."""

    return {
        "name": name,
        "type": "host",
        "clock": "clk_i",
        "reset": "rst_ni",
        "xbar": False,
        "pipeline": False,
    }


def build_xbar_config(config: XbarConfig) -> dict[str, Any]:
    """Build a JSON-ready crossbar configuration from normalized inputs."""

    host_name = _xbar_normalize_host(config.host)
    nodes = [host_node(host_name), *(device_node(device) for device in config.devices)]
    return {
        "name": "main",
        "type": "xbar",
        "clock": "clk_i",
        "clock_connections": {"clk_i": "main"},
        "reset": "rst_ni",
        "reset_connections": {"rst_ni": "main"},
        "nodes": nodes,
        "connections": {host_name: [device.name for device in config.devices]},
    }


def write_json(path: Path, payload: dict[str, Any]) -> Path:
    """Write a JSON payload to disk and return the resolved path."""

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    return path.resolve()


def parse_device_rows(rows: list[list[str]]) -> tuple[XbarDevice, ...]:
    """Convert argparse device rows into typed crossbar devices."""

    return tuple(XbarDevice(name, base_addr, size_byte, from_lr) for name, base_addr, size_byte, from_lr in rows)






from dataclasses import dataclass
from pathlib import Path
import re

_gen_SUPPORTED_HOSTS = {"ibex", "uart"}


@dataclass(frozen=True, slots=True)
class SoCModule:
    """Describe one generated SoC device and where its RTL should be resolved."""

    name: str
    base_addr: str
    size_bytes: str
    from_lowrisc: bool = False


@dataclass(frozen=True, slots=True)
class SoCGenerationConfig:
    """Collect the inputs needed to generate SoC RTL and simulator files."""

    host: str
    devices: tuple[SoCModule, ...]
    root: Path = Path(".")
    output: Path = Path("soc.sv")

    @property
    def run_dir(self) -> Path:
        """Return the run directory inferred from the RTL output path."""

        return self.output.resolve().parent.parent

    @property
    def tb_dir(self) -> Path:
        """Return the generated SoC testbench directory."""

        return self.run_dir / "tb"


TEMPLATE_HEADER = """module soc #(
  parameter string SramInitFile = ""
) (
  // Clock and reset.
  input  logic clk_i,
  input  logic rst_ni,
  // I/O"""

TEMPLATE_FOOTER = """
endmodule
"""


def _gen_normalize_host(host: str) -> str:
    """Normalize and validate the host selected for SoC generation."""

    host = host.strip().lower()
    if host not in _gen_SUPPORTED_HOSTS:
        expected = ", ".join(sorted(_gen_SUPPORTED_HOSTS))
        raise ValueError(f"unsupported host {host!r}; expected one of: {expected}")
    return host


def normalize_device(raw: tuple[str, str, str, str] | list[str]) -> SoCModule:
    """Convert one CLI device tuple into the canonical SoC module model."""

    name, base_addr, size_bytes, from_lowrisc = raw
    return SoCModule(name, base_addr, size_bytes, from_lowrisc == "True")


def normalize_devices(devices: list[list[str]] | tuple[SoCModule, ...]) -> tuple[SoCModule, ...]:
    """Normalize CLI or API device entries into immutable module objects."""

    if all(isinstance(device, SoCModule) for device in devices):
        return tuple(devices)
    return tuple(normalize_device(device) for device in devices)


def find_sv_file(module_name, root_dir=".", from_vendor=False):
    """Find the SystemVerilog source for one module below canonical roots."""

    root = Path(root_dir)
    search_roots = [root / "vendor"] if from_vendor else [
        root / "hw" / "ips" / module_name,
        root / "rtl",
        root,
    ]
    for search_root in search_roots:
        if not search_root.exists():
            continue
        for path in search_root.rglob(f"{module_name}.sv"):
            return path
    return None


def parse_ports(sv_file):
    """Parse simple input/output port declarations from a SystemVerilog module."""

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
    """Render top-level SoC ports while hiding clocks, TL-UL, and interrupts."""

    lines = []
    for name, direction in all_ports.items():
        if "tl_" in name:
            continue
        if name in {"clk_i", "rst_ni"}:
            continue
        if "intr" in name:
            continue
        lines.append(f"  {direction} {name},")
    return lines


def generate_module_inst(mod, ports):
    """Render one peripheral instance with TL-UL and auxiliary ports wired."""

    inst_lines = [f"  // Instantiate {mod}", f"  {mod} u_{mod} ("]
    port_assignments = [
        "    .clk_i",
        "    .rst_ni",
        f"    .tl_i(tl_{mod}_h2d)",
        f"    .tl_o(tl_{mod}_d2h)",
    ]

    for direction, _, name in ports:
        if name in {"tl_i", "tl_o", "clk_i", "rst_ni"}:
            continue
        if "intr" in name:
            continue
        if "alert_rx" in name:
            continue
        if "alert_tx" in name:
            continue
        port_assignments.append(f"    .{name}")

    for direction, _, name in ports:
        if "intr" in name:
            port_assignments.append(f"    .{name}()")
    for direction, _, name in ports:
        if "alert_rx" in name:
            port_assignments.append(f"    .{name}()")
    for direction, _, name in ports:
        if "alert_tx" in name:
            port_assignments.append(f"    .{name}()")

    inst_lines.append(",\n".join(port_assignments))
    inst_lines.append("  );\n")
    return "\n".join(inst_lines)


def defaults(host):
    """Render host-specific default logic and TileLink adapters."""

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
      sram_data_rvalid  <= sram_data_req & ~sram_data_we;
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

def write_top_verilator_sv(tb_file, host, all_ports):
    """Write the generated Verilator SystemVerilog wrapper."""

    soc_ports = []
    for name, direction in all_ports.items():
        if name in {"clk_i", "rst_ni"}:
            continue
        if "tl_" in name:
            continue
        if "intr" in name:
            continue
        soc_ports.append((name, direction))

    with open(tb_file, "w", encoding="utf-8") as f:
        f.write("module top_verilator (input logic clk_i, rst_ni);\n")

        for name, direction in soc_ports:
            parts = direction.split()
            decl = " ".join(parts[1:]).strip()
            if not decl:
                decl = "logic"
            f.write(f"  {decl} {name};\n")

        f.write("\n")
        f.write("  // Our SoC\n")
        f.write("  soc #(\n")
        f.write("  ) u_soc (\n")
        f.write("    .clk_i,\n")
        f.write("    .rst_ni")

        for name, _direction in soc_ports:
            f.write(f",\n    .{name}")

        f.write("\n  );\n\n")

        has_uart_pins = all(x in all_ports for x in ("cio_rx_i", "cio_tx_o"))
        if has_uart_pins:
            f.write("  // Virtual UART\n")
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
            f.write("\n")
            f.write('  export "DPI-C" function mhpmcounter_num;\n')
            f.write("  function automatic int unsigned mhpmcounter_num();\n")
            f.write("    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.MHPMCounterNum;\n")
            f.write("  endfunction\n")
            f.write("\n")
            f.write('  export "DPI-C" function mhpmcounter_get;\n')
            f.write("  function automatic longint unsigned mhpmcounter_get(int index);\n")
            f.write("    return u_soc.u_ibex_top_tracing.u_ibex_top.u_ibex_core.cs_registers_i.mhpmcounter[index];\n")
            f.write("  endfunction\n")

        f.write("endmodule\n")

def write_top_verilator_cc(tb_file, host):
    """Write the generated Verilator C++ harness."""

    with open(tb_file, "w", encoding="utf-8") as f:
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
        f.write('  if (exit_app) return ret_code;\n')
        f.write('  Run();\n')
        f.write('  if (!Finish()) return 1;\n')
        f.write('  return 0;\n')
        f.write('}\n')
        f.write('\n')
        f.write('int MySoc::Setup(int argc, char **argv, bool &exit_app) {\n')
        f.write('  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n')
        f.write('  simctrl.SetTop(&_top, &_top.clk_i, &_top.rst_ni,\n')
        f.write('                 VerilatorSimCtrlFlags::ResetPolarityNegative);\n')
        f.write('  _memutil.RegisterMemoryArea("ram", 0x100000, &_ram);\n')
        f.write('  simctrl.RegisterExtension(&_memutil);\n')
        f.write('  exit_app = false;\n')
        f.write('  return simctrl.ParseCommandArgs(argc, argv, exit_app);\n')
        f.write('}\n')
        f.write('\n')
        f.write('void MySoc::Run() {\n')
        f.write('  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n')
        f.write('  std::cout << "Simulation of your SoC" << std::endl\n')
        f.write('            << "======================" << std::endl\n')
        f.write('            << std::endl;\n')
        f.write('  simctrl.RunSimulation();\n')
        f.write('}\n')
        f.write('\n')
        f.write('bool MySoc::Finish() {\n')
        f.write('  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();\n')
        f.write('  if (!simctrl.WasSimulationSuccessful()) return false;\n')
        if host == "ibex":
            f.write('  svSetScope(svGetScopeFromName("TOP.top_verilator"));\n')
            f.write('  std::cout << "Performance Counters" << std::endl\n')
            f.write('            << "====================" << std::endl;\n')
            f.write('  std::cout << ibex_pcount_string(false);\n')
            f.write('  std::ofstream pcount_csv("sw/performance_counters.csv");\n')
            f.write('  pcount_csv << ibex_pcount_string(true);\n')
        f.write('  return true;\n')
        f.write('}\n')
        f.write('\n')
        f.write('int main(int argc, char **argv) {\n')
        f.write('  MySoc my_soc(\n')
        f.write('      "TOP.top_verilator.u_soc.u_ram.gen_generic.u_impl_generic",\n')
        f.write('      32 * 1024\n')
        f.write('  );\n')
        f.write('  return my_soc.Main(argc, argv);\n')
        f.write('}\n')


def write_soc_core(core_file, host, modules):
    """Write the FuseSoC core file for the generated SoC."""

    with open(core_file, "w", encoding="utf-8") as f:
        f.write('CAPI=2:\n')
        f.write('name: "enea:soc:main"\n')
        f.write('description: "An easy to build SoC"\n')
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


def split_devices(devices: tuple[SoCModule, ...]) -> tuple[list[str], list[str]]:
    """Split normalized devices into local IPs and lowRISC dependencies."""

    local = [device.name for device in devices if not device.from_lowrisc]
    lowrisc = [device.name for device in devices if device.from_lowrisc]
    return local, lowrisc


def soc_modules(devices: tuple[SoCModule, ...]) -> tuple[list[str], list[str], list[str]]:
    """Return local, lowRISC, and renderable module lists for SoC generation."""

    local, lowrisc = split_devices(devices)
    return local, lowrisc, lowrisc[1:] + local


def collect_module_ports(config: SoCGenerationConfig) -> tuple[dict[str, list[tuple[str, str | None, str]]], list[str]]:
    """Resolve every renderable module and parse its external ports."""

    local_modules, lowrisc_modules, modules = soc_modules(config.devices)
    parsed = {}
    for module in modules:
        if module == "uart" and config.host == "uart":
            continue
        sv_path = find_sv_file(module, config.root, module in lowrisc_modules)
        if not sv_path:
            raise FileNotFoundError(f"SystemVerilog file for module {module!r} not found.")
        parsed[module] = parse_ports(sv_path)
    return parsed, local_modules


def collect_soc_ports(modules_ports):
    """Merge parsed module ports into the generated SoC top-level port map."""

    all_ports = {}
    for mod_ports in modules_ports.values():
        for direction, dtype, name in mod_ports:
            all_ports.setdefault(name, direction + " " + ("" if dtype is None else dtype))
    return all_ports


def add_host_ports(host: str, all_ports: dict[str, str]) -> dict[str, str]:
    """Add host-facing external pins that are not discovered from IP wrappers."""

    if host == "uart":
        all_ports.setdefault("cio_rx_i", "input logic")
        all_ports.setdefault("cio_tx_o", "output logic")
        all_ports.setdefault("cio_tx_en_o", "output logic")
    return all_ports


def render_xbar_connections(host: str, modules: list[str]) -> str:
    """Render the generated xbar instance connections for host and devices."""

    lines = ["  // Our main data bus.", "  xbar_main xbar (", "    .clk_i,", "    .rst_ni,", ""]
    if host == "ibex":
        lines += [
            "    .tl_ibex_i (tl_ibex_h2d),",
            "    .tl_ibex_o (tl_ibex_d2h),",
            "    .tl_sram_o (tl_sram_h2d),",
            "    .tl_sram_i (tl_sram_d2h),",
        ]
    if host == "uart":
        lines += [
            "    .tl_uart_host_i (tl_uart_host_h2d),",
            "    .tl_uart_host_o (tl_uart_host_d2h),",
            "    .tl_uart_o (tl_uart_h2d),",
            "    .tl_uart_i (tl_uart_d2h),",
        ]
    for module in modules:
        if module == "uart" and host == "uart":
            continue
        lines += [f"    .tl_{module}_o (tl_{module}_h2d),", f"    .tl_{module}_i (tl_{module}_d2h),"]
    lines += ["    .scanmode_i (prim_mubi_pkg::MuBi4False)", "  );", ""]
    return "\n".join(lines)


def render_soc_sv(host: str, modules_ports, local_modules: list[str]) -> str:
    """Render the generated `soc.sv` source as a string."""

    modules = list(modules_ports)
    all_ports = add_host_ports(host, collect_soc_ports(modules_ports))
    port_decls = generate_port_decls(all_ports)
    body = [TEMPLATE_HEADER, *port_decls, ");", "", defaults(host)]
    for module in modules:
        if module == "uart" and host == "uart":
            continue
        body.append(f"  tlul_pkg::tl_h2d_t tl_{module}_h2d;")
        body.append(f"  tlul_pkg::tl_d2h_t tl_{module}_d2h;")
    body += ["", render_xbar_connections(host, local_modules)]
    body.extend(generate_module_inst(module, ports) for module, ports in modules_ports.items())
    body.append(TEMPLATE_FOOTER)
    return "\n".join(body)


def generate_soc(config: SoCGenerationConfig) -> Path:
    """Generate SoC RTL, Verilator wrappers, and FuseSoC metadata."""

    modules_ports, local_modules = collect_module_ports(config)
    all_ports = add_host_ports(config.host, collect_soc_ports(modules_ports))
    config.output.parent.mkdir(parents=True, exist_ok=True)
    config.tb_dir.mkdir(parents=True, exist_ok=True)
    config.output.write_text(render_soc_sv(config.host, modules_ports, local_modules), encoding="utf-8")
    write_top_verilator_sv(config.tb_dir / "top_verilator.sv", config.host, all_ports)
    write_top_verilator_cc(config.tb_dir / "top_verilator.cc", config.host)
    write_soc_core(config.run_dir / "soc.core", config.host, local_modules)
    return config.output


def generate_soc_sv(host, device, root_dir, output_file):
    """Generate SoC files from CLI-style arguments."""

    return generate_soc(
        SoCGenerationConfig(
            host=_gen_normalize_host(host),
            devices=normalize_devices(device),
            root=Path(root_dir),
            output=Path(output_file),
        )
    )




from pathlib import Path


LICENSE = """# Copyright 2025 Enea Dimroci
#
# Licensed under the Apache License, Version 2.0.
"""


def rtl_sort_key(filename: str, top: str) -> tuple[int, str]:
    """Return a stable RTL order with packages first and the top module last."""

    if filename.endswith("_pkg.sv") and filename != f"{top}_reg_pkg.sv":
        return (0, filename)
    if filename == f"{top}_reg_pkg.sv":
        return (1, filename)
    if filename == f"{top}_reg_top.sv":
        return (2, filename)
    if filename.endswith("_core.sv") or filename == "timer_core.sv":
        return (3, filename)
    if filename == f"{top}.sv":
        return (4, filename)
    return (5, filename)


def list_rtl_sources(rtl_dir: Path, top: str) -> list[str]:
    """List visible SystemVerilog files in FuseSoC-friendly order."""

    files = [p.name for p in rtl_dir.iterdir() if p.is_file() and not p.name.startswith(".")]
    return sorted((name for name in files if name.endswith(".sv")), key=lambda name: rtl_sort_key(name, top))


def render_core(prj: str, top: str, rtl_files: list[str], rtl_ref_dir: str = "rtl") -> str:
    """Render the CAPI2 core description used by FuseSoC."""

    file_lines = "\n".join(f"      - {rtl_ref_dir}/{name}" for name in rtl_files)
    if file_lines:
        file_lines += "\n"
    return (
        "CAPI=2:\n"
        f"name: \"{prj}:ip:{top}:0.1\"\n"
        f"description: \"{top}\"\n"
        "filesets:\n"
        "  files_rtl:\n"
        "    depend:\n"
        "      - ips:dependecies:all\n"
        "    files:\n"
        f"{file_lines}"
        "    file_type: systemVerilogSource\n\n"
        "targets:\n"
        "  default: &default_target\n"
        "    filesets:\n"
        "      - files_rtl\n"
        f"    toplevel: {top}\n\n"
        "  lint:\n"
        "    <<: *default_target\n"
        "    default_tool: verilator\n"
        "    tools:\n"
        "      verilator:\n"
        "        mode: lint-only\n"
        "        verilator_options:\n"
        "          - \"-Wall\"\n"
        "          - \"-Wno-fatal\"\n"
    )


def write_core(prj: str, top: str, rtl_dir: Path, output: Path | None = None) -> Path:
    """Write `<top>.core` and return the generated path."""

    out_dir = output or Path.cwd()
    out_dir.mkdir(parents=True, exist_ok=True)
    core_path = out_dir / f"{top}.core"
    core_path.write_text(render_core(prj, top, list_rtl_sources(rtl_dir, top)), encoding="utf-8")
    return core_path






import shutil
from dataclasses import dataclass
from pathlib import Path


BOOT_S = r"""# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0.

.section .text

default_exc_handler:
  j default_exc_handler

reset_handler:
  mv  x1, x0
  mv  x2, x1
  mv  x3, x1
  mv  x4, x1
  mv  x5, x1
  mv  x6, x1
  mv  x7, x1
  mv  x8, x1
  mv  x9, x1
  mv x10, x1
  mv x11, x1
  mv x12, x1
  mv x13, x1
  mv x14, x1
  mv x15, x1
  mv x16, x1
  mv x17, x1
  mv x18, x1
  mv x19, x1
  mv x20, x1
  mv x21, x1
  mv x22, x1
  mv x23, x1
  mv x24, x1
  mv x25, x1
  mv x26, x1
  mv x27, x1
  mv x28, x1
  mv x29, x1
  mv x30, x1
  mv x31, x1

  la   x2, _stack_start

_start:
  .global _start

  la x26, _bss_start
  la x27, _bss_end

  bge x26, x27, zero_loop_end

zero_loop:
  sw x0, 0(x26)
  addi x26, x26, 4
  ble x26, x27, zero_loop
zero_loop_end:

main_entry:
  addi x10, x0, 0
  addi x11, x0, 0
  jal x1, main

sleep_loop:
  wfi
  j sleep_loop

  .section .vectors, "ax"
  .option norvc;

  .org 0x00
  .rept 32
  jal x0, default_exc_handler
  .endr

  .org 0x80
  jal x0, reset_handler
"""

LINK_LD = r"""OUTPUT_ARCH(riscv)

MEMORY
{
    ram   : ORIGIN = 0x00100000, LENGTH = 0x1F000
    stack : ORIGIN = 0x0011F000, LENGTH = 0x01000
}

_min_stack    = 0x1000;
_stack_len    = LENGTH(stack);
_stack_start  = ORIGIN(stack) + LENGTH(stack);

_entry_point = _vectors_start;
ENTRY(_entry_point)

PROVIDE(_stext = ORIGIN(ram));
PROVIDE(_stack_start = ORIGIN(stack) + LENGTH(stack));
PROVIDE(_max_hart_id = 0);
PROVIDE(_hart_stack_size = LENGTH(stack));
PROVIDE(_heap_size = 0);
PROVIDE(UserSoft = DefaultHandler);
PROVIDE(SupervisorSoft = DefaultHandler);
PROVIDE(MachineSoft = DefaultHandler);
PROVIDE(UserTimer = DefaultHandler);
PROVIDE(SupervisorTimer = DefaultHandler);
PROVIDE(MachineTimer = DefaultHandler);
PROVIDE(UserExternal = DefaultHandler);
PROVIDE(SupervisorExternal = DefaultHandler);
PROVIDE(MachineExternal = DefaultHandler);
PROVIDE(DefaultHandler = DefaultInterruptHandler);
PROVIDE(ExceptionHandler = DefaultExceptionHandler);
PROVIDE(__pre_init = default_pre_init);
PROVIDE(_mp_hook = default_mp_hook);
PROVIDE(_start_trap = default_start_trap);
PROVIDE(_setup_interrupts = default_setup_interrupts);

SECTIONS
{
    .text : {
        . = ALIGN(4);
        _vectors_start = .;
        KEEP(*(.vectors))
        _vectors_end = .;
        *(.text)
        *(.text.*)
        . = ALIGN(4);
    } > ram

    .rodata : {
        . = ALIGN(4);
        *(.srodata)
        *(.srodata.*)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
    } > ram

    .data : {
        . = ALIGN(4);
        *(.sdata)
        *(.sdata.*)
        *(.data)
        *(.data.*)
        . = ALIGN(4);
    } > ram

    .bss : {
        . = ALIGN(4);
        _bss_start = .;
        *(.sbss)
        *(.sbss.*)
        *(.bss)
        *(.bss.*)
        *(COMMON)
        _bss_end = .;
        . = ALIGN(4);
    } > ram

    _sbss = _bss_start;
    _ebss = _bss_end;

    .stack (NOLOAD): {
        . = ALIGN(4);
        . = . + _min_stack;
        . = ALIGN(4);
        stack = .;
        _stack = .;
    } > stack
}
"""


@dataclass(frozen=True, slots=True)
class SoCSoftwareConfig:
    """Collect paths and options used to build the SoC software scaffold."""

    workspace: Path
    run_top: str
    run_id: str
    host: str

    @property
    def _software_run_dir(self) -> Path:
        """Return the canonical run directory for this software scaffold."""

        return _software_run_dir(self.workspace, self.run_top, self.run_id)


def _software_run_dir(workspace: Path, run_top: str, run_id: str) -> Path:
    """Build the canonical workspace run directory path."""

    return workspace / "runs" / run_top / run_id


def copy_driver_files(ips_dir: Path, sw_dir: Path) -> list[str]:
    """Copy staged IP C drivers into the software directory."""

    if not ips_dir.exists():
        raise SystemExit(f"ERROR: missing loaded IP directory: {ips_dir}")

    modules: list[str] = []
    for ip_dir in sorted((p for p in ips_dir.iterdir() if p.is_dir()), key=lambda p: p.name):
        driver_files = sorted((ip_dir / "drivers").glob("*.h")) + sorted((ip_dir / "drivers").glob("*.c"))
        if not driver_files:
            continue
        for src in driver_files:
            shutil.copy2(src, sw_dir / src.name)
        modules.append(ip_dir.name)
    return modules


def render_main_c(modules: list[str], host: str) -> str:
    """Render the generated SoC C entrypoint."""

    uses_uart = host == "uart" and "uart" in modules
    includes = [f'#include "{mod}.h"' for mod in sorted(modules)]
    body = ["int main(void) {"]

    for mod in modules:
        body.append(f"  {mod}_init(({mod}_t){mod.upper()}_BASE);")

    if uses_uart:
        body.extend([
            '  uart_puts("FlexSoC SoC boot\\n");',
            "  (void)uart_in((uart_t)UART_BASE);",
        ])

    body.append("  for (;;) {")
    if uses_uart:
        body.extend([
            "    int ch = uart_in((uart_t)UART_BASE);",
            "    if (ch >= 0) {",
            "      uart_putchar(ch);",
            "    }",
        ])
    body.extend(["  }", "  return 0;", "}"])
    return f"{chr(10).join(includes)}\n\n{chr(10).join(body)}\n"


def render_makefile(modules: list[str]) -> str:
    """Render the generated RISC-V software Makefile."""

    c_modules = ["main", *modules]
    obj_list = " ".join(f"$(BUILD_DIR)/{m}.o" for m in c_modules) + " $(BUILD_DIR)/boot.o"
    return f"""CC = riscv32-unknown-elf-gcc
CFLAGS = -march=rv32imc -mabi=ilp32 -static -mcmodel=medany -Wall -g -fvisibility=hidden -ffreestanding
LDFLAGS = -nostdlib -nostartfiles -T link.ld
BUILD_DIR = build

OBJS = {obj_list}

all: $(BUILD_DIR)/main.elf

$(BUILD_DIR):
\tmkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
\t$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/boot.o: boot.S | $(BUILD_DIR)
\t$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.elf: $(OBJS)
\t$(CC) $(LDFLAGS) $(OBJS) -o $@

clean:
\trm -rf $(BUILD_DIR)

.PHONY: all clean
"""


def write_soc_software(config: SoCSoftwareConfig) -> tuple[Path, list[str]]:
    """Generate the SoC software directory and return its copied modules."""

    sw_dir = config._software_run_dir / "sw"
    sw_dir.mkdir(parents=True, exist_ok=True)

    modules = copy_driver_files(config._software_run_dir / "ips", sw_dir)
    if not modules:
        raise SystemExit(f"ERROR: no driver files found under loaded IPs: {config._software_run_dir / 'ips'}")

    (sw_dir / "boot.S").write_text(BOOT_S, encoding="utf-8")
    (sw_dir / "link.ld").write_text(LINK_LD, encoding="utf-8")
    (sw_dir / "main.c").write_text(render_main_c(modules, config.host), encoding="utf-8")
    (sw_dir / "Makefile").write_text(render_makefile(modules), encoding="utf-8")
    return sw_dir, modules







class SocFlow:
    """Generate SoC integration, FuseSoC metadata and software collateral."""

    def __init__(self, project_root: Path, runner=None):
        from ..core import ToolRunner
        self.project_root = Path(project_root).resolve()
        self.runner = runner or ToolRunner(project_root=self.project_root)

    def resolve_config(self, **kwargs) -> SoCConfig:
        """Resolve host and device configuration from loaded IP metadata."""
        return resolve_soc_config(**kwargs)

    def start(self, config: SoCStartConfig) -> Path:
        """Initialize a SoC run from packaged IPs."""
        return initialize_soc_run(config)

    def init_xbar(self, config: XbarConfig, output: Path) -> Path:
        """Write the tlgen crossbar input configuration."""
        return write_json(output, build_xbar_config(config))

    def generate(self, config: SoCGenerationConfig) -> Path:
        """Generate the SoC top and simulation wrappers."""
        return generate_soc(config)

    def generate_fusesoc(self, project: str, top: str, rtl_dir: Path, output_dir: Path) -> Path:
        """Generate the CAPI2 FuseSoC core metadata."""
        return write_core(project, top, rtl_dir, output_dir)

    def generate_software(self, config: SoCSoftwareConfig):
        """Generate the SoC software workspace from staged IP drivers."""
        return write_soc_software(config)

    def run_tool(self, argv, *, cwd: Path, log: Path, inputs=(), outputs=(), on: str = "local"):
        """Run one external SoC tool through the shared execution layer."""
        from ..core import CommandRequest
        return self.runner.run(CommandRequest(tuple(argv), cwd, {}, log, tuple(inputs), tuple(outputs)), on=on)
