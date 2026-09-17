"""RTL scaffold, top regeneration, hierarchy and ordered source views."""

from __future__ import annotations

import ast
import hashlib
import re
import shlex
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Sequence

from flexsoc.backend.core import ClockConfig, ClockDomain, Files
from .regs import RegsFlow

try:
    import hjson  # type: ignore
except ImportError:  # pragma: no cover - import fallback for tiny tests.
    hjson = None

Hjson = dict[str, Any]

REGISTER_BUS_PORTS = frozenset({"tl_i", "tl_o", "reg_req_i", "reg_rsp_o", "axi_lite_i", "axi_lite_o"})


@dataclass(frozen=True, slots=True)
class Port:
    """One parsed SystemVerilog port."""

    direction: str
    svtype: str
    name: str


_REG_PORT_RE = re.compile(r"^(?P<name>[A-Za-z_][A-Za-z0-9_]*)_(?P<kind>reg2hw_i|hw2reg_o)$")


@dataclass(frozen=True, slots=True)
class RegisterWindow:
    """One discovered regtool interface and its clock domain."""

    name: str
    domain: ClockDomain

    @property
    def reset_ni(self) -> str:
        return RtlFlow._reset_sync_name(self.domain)


MODULE_RE = re.compile(r"\bmodule\s+(?:(?:automatic|static)\s+)?([A-Za-z_][A-Za-z0-9_$]*)")
TIMESCALE_RE = re.compile(r"`timescale\s+([^\s/]+)\s*/\s*([^\s]+)")


class RtlFlow:
    def __init__(self, project_root: Path, runner=None):
        self.project_root = Path(project_root).resolve()
        from ...core import ToolRunner
        self.runner = runner or ToolRunner(project_root=self.project_root)
    """Create RTL scaffold, top wiring and canonical source views."""

    def init_scaffold(
        self,
        hjson_file: Path | None,
        interface: str,
        output_dir: Path,
        *,
        top: str | None = None,
        force: bool = False,
        clocks: ClockConfig | None = None,
    ) -> tuple[Path, Path]:
        """Create the single- or multi-clock starter RTL."""

        clocks = clocks or ClockConfig.from_values()
        if clocks.multiclock:
            if not top:
                raise ValueError("top is required for a multi-clock RTL scaffold")
            Files.ensure_dir(output_dir)
            core = output_dir / f"{top}_core.sv"
            Files.safe_write_file(core, RtlFlow.render_nclock_core(top), overwrite=force)
            wrapper = RtlFlow.write_top_from_core(top, output_dir, interface, force=force, clocks=clocks)
            return core, wrapper
        if hjson_file is None:
            raise ValueError("hjson_file is required for a single-clock RTL scaffold")
        return RtlFlow.generate_rtl_stubs(hjson_file, interface, output_dir, force=force, clocks=clocks)

    def setup_top(
        self,
        top: str,
        rtl_dir: Path,
        interface: str,
        *,
        force: bool = False,
        clocks: ClockConfig | None = None,
    ) -> Path:
        """Regenerate the wrapper from the edited core signature."""

        return RtlFlow.write_top_from_core(top, rtl_dir, interface, force=force, clocks=clocks)

    def setup_filelists(
        self,
        *,
        root: Path,
        top_file: Path,
        common_out: Path,
        ip_out: Path,
        search_roots: Sequence[Path] = (),
        common_roots: Sequence[Path] = (),
        top: str | None = None,
        extra_args: str = "",
        slang: str = "slang",
        synthesis: bool = False,
        on: str = "local",
    ) -> None:
        """Generate ordered common/IP filelists with Slang."""

        from types import SimpleNamespace

        RtlFlow.run_flist(SimpleNamespace(
            root=root,
            search_root=list(search_roots),
            top_file=top_file,
            top=top,
            extra_args=extra_args,
            slang=slang,
            output=None,
            common_out=common_out,
            ip_out=ip_out,
            common_root=list(common_roots),
            synthesis=synthesis,
        ), runner=self.runner, on=on)

    def show_hierarchy(
        self,
        *,
        root: Path,
        top_file: Path,
        output: Path,
        search_roots: Sequence[Path] = (),
        top: str | None = None,
        extra_args: str = "",
        slang_hier: str = "slang-hier",
        on: str = "local",
    ) -> None:
        """Write the elaborated hierarchy for one top."""

        from types import SimpleNamespace

        RtlFlow.run_hier(SimpleNamespace(
            root=root,
            search_root=list(search_roots),
            top_file=top_file,
            top=top,
            extra_args=extra_args,
            slang_hier=slang_hier,
            output=output,
        ), runner=self.runner, on=on)

    def show_ast(
        self,
        *,
        root: Path,
        top_file: Path,
        output: Path,
        search_roots: Sequence[Path] = (),
        top: str | None = None,
        extra_args: str = "",
        slang: str = "slang",
        scope: str | None = None,
        on: str = "local",
    ) -> None:
        """Write the Slang AST JSON for one top."""

        from types import SimpleNamespace

        RtlFlow.run_ast(SimpleNamespace(
            root=root,
            search_root=list(search_roots),
            top_file=top_file,
            top=top,
            extra_args=extra_args,
            slang=slang,
            json_out=output,
            scope=scope,
        ), runner=self.runner, on=on)

    def fetch_vendor(
        self,
        manifest: Path,
        *,
        target_dir: Path,
        force: bool = False,
        on: str = "local",
    ) -> int:
        """Fetch one vendored dependency, reusing an intact pinned import."""

        import sys
        from flexsoc.backend.core import CommandRequest

        tool = self.project_root / "src" / "util" / "vendor.py"
        data = RtlFlow._load_hjson(manifest)
        vendor_dir = manifest.parent / str(data["target_dir"])
        marker = vendor_dir / ".flexsoc_fetch.sha256"
        lock = manifest.with_name(manifest.name.replace(".vendor.hjson", ".lock.hjson"))
        patch_root = manifest.parent / str(data["patch_dir"]) if data.get("patch_dir") else None
        inputs = [manifest, tool, *([lock] if lock.is_file() else [])]
        if patch_root is not None and patch_root.is_dir():
            inputs.extend(sorted(path for path in patch_root.rglob("*") if path.is_file()))

        digest = hashlib.sha256(b"flexsoc-vendor-input-v1\0")
        for path in inputs:
            try:
                label = path.relative_to(self.project_root).as_posix()
            except ValueError:
                label = path.relative_to(manifest.parent).as_posix()
            digest.update(label.encode())
            digest.update(b"\0")
            digest.update(path.read_bytes())
            digest.update(b"\0")
        input_hash = digest.hexdigest()

        def output_hash() -> str:
            tree = hashlib.sha256(b"flexsoc-vendor-output-v1\0")
            for path in sorted(vendor_dir.rglob("*")):
                if (not path.is_file() or path == marker or "__pycache__" in path.parts
                        or path.suffix in {".pyc", ".pyo"}):
                    continue
                tree.update(path.relative_to(vendor_dir).as_posix().encode())
                tree.update(b"\0")
                tree.update(path.read_bytes())
                tree.update(b"\0")
            return tree.hexdigest()

        if not force and marker.is_file():
            state = dict(line.split("=", 1) for line in marker.read_text().splitlines() if "=" in line)
            if state.get("INPUT_SHA256") == input_hash and state.get("OUTPUT_SHA256") == output_hash():
                print(f"[vendor] reuse {vendor_dir}")
                return 0

        update = ("--update",) if force else ()
        argv = (sys.executable, str(tool), *update, str(manifest))
        log = target_dir / ".flexsoc_vendor.log"
        request = CommandRequest(argv, self.project_root, {}, log, inputs=tuple(inputs), outputs=(vendor_dir,))
        result = self.runner.run(request, on=on)
        if result.returncode == 0 and vendor_dir.is_dir():
            Files.safe_write_file(
                marker,
                f"INPUT_SHA256={input_hash}\nOUTPUT_SHA256={output_hash()}\n",
                overwrite=True,
            )
        return result.returncode

    @staticmethod
    def is_register_bus_port(name: str) -> bool:
        """Return true for wrapper ports owned by the selected CSR transport."""

        return name in REGISTER_BUS_PORTS

    @staticmethod
    def _load_hjson(path: Path) -> Hjson:
        """Load HJSON metadata with hjson or a tiny literal fallback."""

        text = path.read_text(encoding="utf-8")
        if hjson is not None:
            return dict(hjson.loads(text))
        text = re.sub(r"([{,]\s*)([A-Za-z_]\w*)\s*:", r'\1"\2":', text)
        text = re.sub(r",\s*([}\]])", r"\1", text)
        return dict(ast.literal_eval(text))

    @staticmethod
    def _id(value: str) -> str:
        """Return a conservative lowercase SystemVerilog identifier."""

        name = re.sub(r"\W+", "_", value.strip().lower()).strip("_")
        return f"_{name}" if name[:1].isdigit() else name

    @staticmethod
    def _width(bits: str) -> int:
        """Return the width encoded by one bit or msb:lsb range."""

        if ":" not in bits:
            return 1
        msb, lsb = (int(part) for part in bits.split(":", 1))
        return abs(msb - lsb) + 1

    @staticmethod
    def _logic(name: str, width: int) -> str:
        """Render a scalar/vector logic declaration."""

        return f"  logic [{width - 1}:0] {name};" if width > 1 else f"  logic {name};"

    @staticmethod
    def _field_signal(reg_name: str, field: Hjson, *, flat: bool) -> tuple[str, int, str]:
        """Return local name, width, and reggen CSR path for one HJSON field."""

        field_name = RtlFlow._id(str(field.get("name") or reg_name))
        signal = reg_name if flat else f"{reg_name}_{field_name}"
        path = reg_name if flat else f"{reg_name}.{field_name}"
        return signal, RtlFlow._width(str(field["bits"])), path

    @staticmethod
    def _register_signals(hj: Hjson) -> tuple[list[str], list[str], list[str], set[str]]:
        """Map HJSON registers to reggen's reg2hw/hw2reg structs."""

        decls, reg2core, core2reg, names = [], [], [], set()
        for reg in hj.get("registers", []) or []:
            if not isinstance(reg, dict) or "name" not in reg:
                continue
            reg_name = RtlFlow._id(str(reg["name"]))
            fields = [f for f in reg.get("fields", []) or [] if isinstance(f, dict) and "bits" in f]
            flat = len(fields) == 1
            for field in fields:
                signal, width, path = RtlFlow._field_signal(reg_name, field, flat=flat)
                swaccess = str(field.get("swaccess", reg.get("swaccess", ""))).lower()
                hwaccess = str(field.get("hwaccess", reg.get("hwaccess", ""))).lower()
                if signal not in names:
                    decls.append(RtlFlow._logic(signal, width))
                    names.add(signal)
                if swaccess in {"rw", "wo", "w1c", "w1s", "rw1c", "rw1s", "rw0c", "rw0w1c"}:
                    reg2core.append(f"  assign {signal} = reg2hw.{path}.q;")
                if swaccess == "ro" and hwaccess in {"hrw", "hwo"}:
                    core2reg.append(f"  assign hw2reg.{path}.d = {signal};")
        return decls, reg2core, core2reg, names

    @staticmethod
    def _assign_if(name: str, expr: str, names: set[str]) -> list[str]:
        """Assign a generated CSR signal only when it exists."""

        return [f"  assign {name} = {expr};"] if name in names else []

    @staticmethod
    def _sig(names: set[str], name: str, default: str) -> str:
        """Return a CSR signal expression or a safe default."""

        return name if name in names else default

    @staticmethod
    def render_core(hj: Hjson) -> str:
        """Render a small but useful pipelined <top>_core.sv."""

        top = RtlFlow._id(str(hj["name"]))
        decls, reg2core, core2reg, names = RtlFlow._register_signals(hj)
        ctrl_en = RtlFlow._sig(names, "ctrl_en", "1'b1")
        ctrl_clr = RtlFlow._sig(names, "ctrl_clr", "1'b0")
        mode_sel = RtlFlow._sig(names, "mode_sel", "2'd0")
        scale = RtlFlow._sig(names, "scale", "8'd0")
        core_logic = [
            "  logic [31:0] add_result;",
            "  logic [31:0] xor_result;",
            "  logic [31:0] selected_d;",
            "  logic [31:0] pipe_q0;",
            "  logic [31:0] pipe_q1;",
            "  logic        valid_q0;",
            "  logic        valid_q1;",
            "",
            "  assign add_result = data_i + coeff_i;",
            "  assign xor_result = data_i ^ coeff_i;",
            "",
            "  always_comb begin",
            f"    unique case ({mode_sel}[1:0])",
            "      2'd0: selected_d = add_result;",
            "      2'd1: selected_d = xor_result;",
            f"      2'd2: selected_d = data_i << {scale}[4:0];",
            "      default: selected_d = data_i;",
            "    endcase",
            f"    if (!{ctrl_en}) selected_d = '0;",
            "  end",
            "",
            "  always_ff @(posedge clk_i or negedge rst_ni) begin",
            "    if (!rst_ni) begin",
            "      pipe_q0  <= '0;",
            "      pipe_q1  <= '0;",
            "      valid_q0 <= 1'b0;",
            "      valid_q1 <= 1'b0;",
            f"    end else if ({ctrl_clr}) begin",
            "      pipe_q0  <= '0;",
            "      pipe_q1  <= '0;",
            "      valid_q0 <= 1'b0;",
            "      valid_q1 <= 1'b0;",
            "    end else begin",
            "      pipe_q0  <= selected_d;",
            "      pipe_q1  <= pipe_q0;",
            f"      valid_q0 <= valid_i & {ctrl_en};",
            "      valid_q1 <= valid_q0;",
            "    end",
            "  end",
            "",
            "  assign data_o  = pipe_q1;",
            "  assign valid_o = valid_q1;",
            *RtlFlow._assign_if("status_busy", "valid_q0", names),
            *RtlFlow._assign_if("status_done", "valid_q1", names),
            *RtlFlow._assign_if("status_error", "1'b0", names),
            *RtlFlow._assign_if("result", "pipe_q1", names),
        ]
        lines = [
            "// Auto-generated by flexsoc.backend.design.ip.rtl.",
            f"module {top}_core",
            f"  import {top}_reg_pkg::*;",
            "(",
            "  input        clk_i,",
            "  input        rst_ni,",
            f"  input  {top}_reg2hw_t reg2hw,",
            f"  output {top}_hw2reg_t hw2reg,",
            "",
            "  input  logic [31:0] data_i,",
            "  input  logic [31:0] coeff_i,",
            "  input  logic        valid_i,",
            "  output logic [31:0] data_o,",
            "  output logic        valid_o",
            ");",
            "",
            "  // CSR signals",
            *(decls or ["  // no CSR signals inferred"]),
            "",
            "  // CSR to core",
            *(reg2core or ["  // no writable CSR fields inferred"]),
            "",
            "  // Core datapath",
            *core_logic,
            "",
            "  // Core to CSR",
            *(core2reg or ["  // no readable HW CSR fields inferred"]),
            "",
            "endmodule",
        ]
        return "\n".join(lines) + "\n"

    @staticmethod
    def render_nclock_core(top: str) -> str:
        """Render the editable N-clock RTL core scaffold."""

        from flexsoc.backend.core.render.templates import templates

        return templates.render("design/rtl/nclock_core.sv.j2", top=top)

    @staticmethod
    def generate_rtl_stubs(
        hjson_path: str | Path,
        itf: str,
        outdir: str | Path,
        *,
        force: bool = False,
        clocks: ClockConfig | None = None,
    ) -> tuple[Path, Path]:
        """Generate <top>_core.sv and an aligned <top>.sv wrapper."""

        hj = RtlFlow._load_hjson(Path(hjson_path).resolve())
        top = RtlFlow._id(str(hj.get("name", "")))
        if not top:
            raise ValueError("missing or empty 'name' in HJSON")
        Files.ensure_dir(outdir)
        rtl = Path(outdir)
        core_path = rtl / f"{top}_core.sv"
        Files.safe_write_file(core_path, RtlFlow.render_core(hj), overwrite=force)
        top_path = RtlFlow.write_top_from_core(top, rtl, itf, force=force, clocks=clocks)
        return core_path, top_path

    @staticmethod
    def _strip_comments(text: str) -> str:
        """Remove line and block comments from SystemVerilog text."""

        text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
        return "\n".join(line.split("//", 1)[0] for line in text.splitlines())

    @staticmethod
    def _port_list(text: str) -> str:
        """Return the first module port list."""

        match = re.search(r"module\s+\w+\s*(?:import\s+[^;]+;\s*)*\((.*?)\);", RtlFlow._strip_comments(text), re.S)
        if not match:
            raise ValueError("could not parse core module header")
        return match.group(1)

    @staticmethod
    def parse_ports(core_path: str | Path) -> list[Port]:
        """Parse direction, type, and name from a compact module header."""

        ports: list[Port] = []
        for raw in RtlFlow._port_list(Path(core_path).read_text(encoding="utf-8")).splitlines():
            line = raw.strip().rstrip(",")
            if not line.startswith(("input", "output")):
                continue
            tokens = line.split()
            direction, name = tokens[0], tokens[-1]
            ports.append(Port(direction, " ".join(tokens[1:-1]), name))
        return ports

    @staticmethod
    def _bus_ports(itf: str) -> list[Port]:
        """Return direct register-bus wrapper ports for the selected interface."""

        if itf == "tlul":
            return [Port("input", "tlul_pkg::tl_h2d_t", "tl_i"), Port("output", "tlul_pkg::tl_d2h_t", "tl_o")]
        if itf == "reg_iface":
            return [Port("input", "reg_req_t", "reg_req_i"), Port("output", "reg_rsp_t", "reg_rsp_o")]
        raise ValueError(f"{itf} is not a direct register-bus interface")

    @staticmethod
    def _tlul_adapter(pkg: str, prefix: str, clock: str, reset: str, stem: str) -> list[str]:
        """Adapt one TL-UL device interface to the canonical reg_req/reg_rsp transport."""

        return [
            f"  logic {stem}_re;",
            f"  logic {stem}_we;",
            f"  logic [{pkg}::AW-1:0] {stem}_addr;",
            f"  logic [{pkg}::DW-1:0] {stem}_wdata;",
            f"  logic [{pkg}::DBW-1:0] {stem}_be;",
            f"  {pkg}::reg_req_t {stem}_reg_req;",
            f"  {pkg}::reg_rsp_t {stem}_reg_rsp;",
            "",
            f"  assign {stem}_reg_req = '{{",
            f"    valid: {stem}_re | {stem}_we,",
            f"    write: {stem}_we,",
            f"    addr:  {stem}_addr,",
            f"    wdata: {stem}_wdata,",
            f"    wstrb: {stem}_be",
            "  };",
            "",
            "  tlul_adapter_reg #( ",
            f"    .RegAw         ({pkg}::AW),",
            f"    .RegDw         ({pkg}::DW),",
            "    .AccessLatency (0)",
            f"  ) u_{stem}_to_reg (",
            f"    .clk_i        ({clock}),",
            f"    .rst_ni       ({reset}),",
            f"    .tl_i         ({prefix}_i),",
            f"    .tl_o         ({prefix}_o),",
            "    .en_ifetch_i  (prim_mubi_pkg::MuBi4False),",
            "    .intg_error_o (),",
            f"    .re_o         ({stem}_re),",
            f"    .we_o         ({stem}_we),",
            f"    .addr_o       ({stem}_addr),",
            f"    .wdata_o      ({stem}_wdata),",
            f"    .be_o         ({stem}_be),",
            f"    .busy_i       (~{stem}_reg_rsp.ready),",
            f"    .rdata_i      ({stem}_reg_rsp.rdata),",
            f"    .error_i      ({stem}_reg_rsp.error)",
            "  );",
        ]

    @staticmethod
    def _axi_lite_ports(pkg: str, prefix: str = "axi_lite") -> list[Port]:
        """Return one packed AXI4-Lite request/response port pair."""

        return [
            Port("input", f"{pkg}::axi_lite_req_t", f"{prefix}_i"),
            Port("output", f"{pkg}::axi_lite_rsp_t", f"{prefix}_o"),
        ]

    @staticmethod
    def _axi_lite_adapter(pkg: str, request: str, response: str, clock: str, reset: str, stem: str) -> list[str]:
        """Adapt one packed AXI4-Lite interface to the canonical reg_req/reg_rsp transport."""

        return [
            f"  {pkg}::reg_req_t {stem}_reg_req;",
            f"  {pkg}::reg_rsp_t {stem}_reg_rsp;",
            "",
            "  axi_lite_to_reg #( ",
            f"    .ADDR_WIDTH      ({pkg}::AW),",
            f"    .DATA_WIDTH      ({pkg}::DW),",
            f"    .axi_lite_req_t  ({pkg}::axi_lite_req_t),",
            f"    .axi_lite_rsp_t  ({pkg}::axi_lite_rsp_t),",
            f"    .reg_req_t       ({pkg}::reg_req_t),",
            f"    .reg_rsp_t       ({pkg}::reg_rsp_t)",
            f"  ) u_{stem}_to_reg (",
            f"    .clk_i          ({clock}),",
            f"    .rst_ni         ({reset}),",
            f"    .axi_lite_req_i ({request}),",
            f"    .axi_lite_rsp_o ({response}),",
            f"    .reg_req_o      ({stem}_reg_req),",
            f"    .reg_rsp_i      ({stem}_reg_rsp)",
            "  );",
        ]

    @staticmethod
    def _register_top_bus_pins(itf: str, prefix: str = "") -> list[str]:
        """Connect one integration top to its protocol-facing register wrapper."""

        stem = f"{prefix}_" if prefix else ""
        if itf == "tlul":
            return [f".tl_i({stem}tl_i)", f".tl_o({stem}tl_o)"]
        if itf == "reg_iface":
            return [f".reg_req_i({stem}reg_req_i)", f".reg_rsp_o({stem}reg_rsp_o)"]
        if itf == "axi_lite":
            return [f".axi_lite_i({stem}axi_lite_i)", f".axi_lite_o({stem}axi_lite_o)"]
        raise ValueError(f"unsupported register interface: {itf}")

    @staticmethod
    def render_register_top(block: str, itf: str) -> str:
        """Render the protocol-facing wrapper around one canonical reg core."""

        itf = RegsFlow.normalize_register_interface(itf)
        pkg = f"{block}_reg_pkg"
        bus_ports = RtlFlow._axi_lite_ports(pkg) if itf == "axi_lite" else RtlFlow._bus_ports(itf)
        ports = [
            Port("input", "logic", "clk_i"),
            Port("input", "logic", "rst_ni"),
            *bus_ports,
            Port("output", f"{block}_reg2hw_t", "reg2hw"),
            Port("input", f"{block}_hw2reg_t", "hw2reg"),
            Port("input", "logic", "devmode_i"),
        ]
        core_bus = (
            [".reg_req_i(reg_req_i)", ".reg_rsp_o(reg_rsp_o)"]
            if itf == "reg_iface"
            else ([".reg_req_i(flexsoc_tlul_reg_req)", ".reg_rsp_o(flexsoc_tlul_reg_rsp)"] if itf == "tlul"
                  else [".reg_req_i(flexsoc_axi_reg_req)", ".reg_rsp_o(flexsoc_axi_reg_rsp)"])
        )
        lines = [
            "// Auto-generated by flexsoc.backend.design.ip.rtl.",
            f"module {block}_reg_top",
            f"  import {pkg}::*;",
            "(",
            *[line + ("," if i + 1 < len(ports) else "") for i, line in enumerate(RtlFlow._format_port(p) for p in ports)],
            ");",
            "",
            *(
                [*RtlFlow._axi_lite_adapter(pkg, "axi_lite_i", "axi_lite_o", "clk_i", "rst_ni", "flexsoc_axi"), ""]
                if itf == "axi_lite"
                else ([*RtlFlow._tlul_adapter(pkg, "tl", "clk_i", "rst_ni", "flexsoc_tlul"), ""] if itf == "tlul" else [])
            ),
            *RtlFlow._instance("reg_core", f"{block}_reg_core", [
                ".clk_i(clk_i)",
                ".rst_ni(rst_ni)",
                *core_bus,
                ".reg2hw(reg2hw)",
                ".hw2reg(hw2reg)",
                ".devmode_i(devmode_i)",
            ]),
            "",
            "endmodule",
        ]
        return "\n".join(lines) + "\n"

    @staticmethod
    def _external_core_ports(ports: list[Port]) -> list[Port]:
        """Return core ports that must stay visible at the wrapper boundary."""

        hidden = {"reg2hw", "hw2reg"}
        return [port for port in ports if port.name not in hidden]

    @staticmethod
    def _format_port(port: Port) -> str:
        """Render one module port declaration."""

        return f"  {port.direction:<6} {port.svtype} {port.name}".replace("  ", " ").rstrip()

    @staticmethod
    def _instance(name: str, module: str, pins: list[str]) -> list[str]:
        """Render a compact SystemVerilog instance."""

        lines = [f"  {module} u_{name} ("]
        lines.extend(f"    {pin}{',' if i + 1 < len(pins) else ''}" for i, pin in enumerate(pins))
        lines.append("  );")
        return lines

    @staticmethod
    def _reset_sync_name(domain: ClockDomain) -> str:
        """Return the wrapper-local active-low synchronized reset signal."""

        return f"{RtlFlow._id(domain.name)}_rst_sync_ni"

    @staticmethod
    def _domain_sync_reset_signal(domain: ClockDomain) -> str:
        """Return the synchronized reset with the core port's original polarity."""

        signal = RtlFlow._reset_sync_name(domain)
        return signal if domain.reset_polarity == "low" else f"~{signal}"

    @staticmethod
    def _reset_branch_name(domain: ClockDomain, branch: str, *, single: bool = False) -> str:
        """Return one active-low reset distribution branch signal."""

        prefix = "" if single else f"{RtlFlow._id(domain.name)}_"
        return f"{prefix}{RtlFlow._id(branch)}_rst_ni"

    @staticmethod
    def _domain_branch_reset_signal(domain: ClockDomain, branch: str, *, single: bool = False) -> str:
        """Return a distributed reset branch with the core port's original polarity."""

        signal = RtlFlow._reset_branch_name(domain, branch, single=single)
        return signal if domain.reset_polarity == "low" else f"~{signal}"

    @staticmethod
    def _render_reset_sync_branch(domain: ClockDomain, branch: str, *, single: bool = False) -> list[str]:
        """Render one independent reset synchronizer for a structural consumer branch."""

        signal = RtlFlow._reset_branch_name(domain, branch, single=single)
        instance = (
            f"u_{RtlFlow._id(domain.name)}_{RtlFlow._id(branch)}_reset_sync"
            if not single
            else f"u_{RtlFlow._id(branch)}_reset_sync"
        )
        return [
            "  prim_ff_2sync #(",
            "    .Width      (1),",
            "    .ResetValue (1'b0)",
            f"  ) {instance} (",
            f"    .clk_i ({domain.signal}),",
            f"    .rst_ni({RtlFlow._raw_reset_ni(domain)}),",
            "    .d_i   (1'b1),",
            f"    .q_o   ({signal})",
            "  );",
        ]

    @staticmethod
    def _raw_reset_ni(domain: ClockDomain) -> str:
        """Normalize one external reset to the active-low primitive convention."""

        return domain.reset if domain.reset_polarity == "low" else f"~{domain.reset}"

    @staticmethod
    def render_top_from_core(
        top: str,
        core_path: str | Path,
        itf: str = "tlul",
        *,
        clocks: ClockConfig | None = None,
    ) -> str:
        """Render the single-clock integration top and synchronize reset release."""

        itf = RegsFlow.normalize_register_interface(itf)
        cfg = clocks or ClockConfig((ClockDomain("core", "clk_i", "rst_ni", 10.0),))
        if cfg.multiclock:
            raise ValueError("render_top_from_core requires exactly one clock domain")
        domain = cfg.domains[0]
        ports = RtlFlow.parse_ports(core_path)
        port_names = {port.name for port in ports}
        absent = [signal for signal in (domain.signal, domain.reset) if signal not in port_names]
        if absent:
            raise ValueError(f"single-clock wrapper clock/reset port(s) missing from core: {', '.join(absent)}")
        pkg = f"{top}_reg_pkg"
        top_ports = RtlFlow._external_core_ports(ports) + (RtlFlow._axi_lite_ports(pkg) if itf == "axi_lite" else RtlFlow._bus_ports(itf))
        reg_pins = [
            f".clk_i({domain.signal})",
            f".rst_ni({RtlFlow._reset_branch_name(domain, 'reg', single=True)})",
            *RtlFlow._register_top_bus_pins(itf),
            ".reg2hw(reg2hw)",
            ".hw2reg(hw2reg)",
            ".devmode_i(1'b1)",
        ]
        core_pins = [
            f".{port.name}({RtlFlow._domain_branch_reset_signal(domain, 'core', single=True) if port.name == domain.reset else port.name})"
            for port in ports
        ]
        lines = [
            "// Auto-generated by flexsoc.backend.design.ip.rtl.",
            f"module {top}",
            f"  import {top}_reg_pkg::*;",
            "(",
            *[line + ("," if i + 1 < len(top_ports) else "") for i, line in enumerate(RtlFlow._format_port(p) for p in top_ports)],
            ");",
            "",
            f"  {top}_reg2hw_t reg2hw;",
            f"  {top}_hw2reg_t hw2reg;",
            "",
            f"  logic {RtlFlow._reset_branch_name(domain, 'reg', single=True)};",
            f"  logic {RtlFlow._reset_branch_name(domain, 'core', single=True)};",
            "",
            *RtlFlow._render_reset_sync_branch(domain, "reg", single=True),
            "",
            *RtlFlow._render_reset_sync_branch(domain, "core", single=True),
            "",
            *RtlFlow._instance(f"{top}_reg", f"{top}_reg_top", reg_pins),
            "",
            *RtlFlow._instance(f"{top}_core", f"{top}_core", core_pins),
            "",
            "endmodule",
        ]
        return "\n".join(lines) + "\n"

    @staticmethod
    def _register_windows(ports: list[Port], clocks: ClockConfig) -> tuple[RegisterWindow, ...]:
        """Bind paired register ports to same-named clock domains."""

        kinds: dict[str, set[str]] = {}
        for port in ports:
            match = _REG_PORT_RE.match(port.name)
            if match:
                kinds.setdefault(match["name"], set()).add(match["kind"])
        domains, port_names = {item.name: item for item in clocks.domains}, {port.name for port in ports}
        windows: list[RegisterWindow] = []
        for name, found in kinds.items():
            missing = {"reg2hw_i", "hw2reg_o"} - found
            if missing:
                raise ValueError(f"register window {name!r} is missing core port(s): {', '.join(sorted(missing))}")
            domain = domains.get(name)
            if domain is None:
                raise ValueError(f"register window {name!r} requires a matching CLOCK_DOMAINS entry")
            absent = [signal for signal in (domain.signal, domain.reset) if signal not in port_names]
            if absent:
                raise ValueError(f"register window {name!r} clock/reset port(s) missing from core: {', '.join(absent)}")
            windows.append(RegisterWindow(name, domain))
        return tuple(windows)

    @staticmethod
    def render_nclock_top(top: str, core_path: str | Path, clocks: ClockConfig, itf: str = "tlul") -> str:
        """Render a clock-count-neutral integration top around one editable core."""

        itf = RegsFlow.normalize_register_interface(itf)
        core = Path(core_path)
        core = core / f"{top}_core.sv" if core.is_dir() else core
        ports = RtlFlow.parse_ports(core)
        windows = RtlFlow._register_windows(ports, clocks)
        reset_domains: dict[str, list[ClockDomain]] = {}
        for domain in clocks.domains:
            reset_domains.setdefault(domain.reset, []).append(domain)
        shared = [reset for reset, domains in reset_domains.items() if len(domains) > 1]
        if shared:
            raise ValueError(
                "multi-clock synchronized reset release requires one reset port per clock domain; "
                f"shared reset port(s): {', '.join(sorted(shared))}"
            )
        hidden = {f"{window.name}_{kind}" for window in windows for kind in ("reg2hw_i", "hw2reg_o")}
        exposed = [port for port in ports if port.name not in hidden]
        declarations = [RtlFlow._format_port(port) for port in exposed]
        if itf == "tlul":
            declarations += [item for window in windows for item in (
                f"  input  tlul_pkg::tl_h2d_t        {window.name}_tl_i",
                f"  output tlul_pkg::tl_d2h_t        {window.name}_tl_o",
            )]
        elif itf == "reg_iface":
            declarations += [item for window in windows for item in (
                f"  input  {top}_{window.name}_reg_pkg::reg_req_t {window.name}_reg_req_i",
                f"  output {top}_{window.name}_reg_pkg::reg_rsp_t {window.name}_reg_rsp_o",
            )]
        else:
            declarations += [
                RtlFlow._format_port(port)
                for window in windows
                for port in RtlFlow._axi_lite_ports(f"{top}_{window.name}_reg_pkg", f"{window.name}_axi_lite")
            ]
        devmode = "devmode_i" if any(port.name == "devmode_i" for port in exposed) else "1'b1"
        lines = [
            "// Auto-generated N-clock wrapper. Edit the core, then rerun fx top_from_core.",
            f"module {top}",
            *(f"  import {top}_{window.name}_reg_pkg::*;" for window in windows),
            "(",
            *[line + ("," if i + 1 < len(declarations) else "") for i, line in enumerate(declarations)],
            ");", "",
        ]
        for domain in clocks.domains:
            lines += [
                f"  logic {RtlFlow._reset_sync_name(domain)};",
                "",
                "  prim_ff_2sync #(",
                "    .Width      (1),",
                "    .ResetValue (1'b0)",
                f"  ) u_{RtlFlow._id(domain.name)}_reset_sync (",
                f"    .clk_i ({domain.signal}),",
                f"    .rst_ni({RtlFlow._raw_reset_ni(domain)}),",
                "    .d_i   (1'b1),",
                f"    .q_o   ({RtlFlow._reset_sync_name(domain)})",
                "  );",
                "",
            ]
        for window in windows:
            name, domain = window.name, window.domain
            prefix = name
            lines += [
                f"  {top}_{name}_reg2hw_t {name}_reg2hw;",
                f"  {top}_{name}_hw2reg_t {name}_hw2reg;", "",
                f"  {top}_{name}_reg_top u_{name}_reg_top (",
                f"    .clk_i     ({domain.signal}),",
                f"    .rst_ni    ({window.reset_ni}),",
                *(f"    {pin}," for pin in RtlFlow._register_top_bus_pins(itf, prefix)),
                f"    .reg2hw    ({name}_reg2hw),",
                f"    .hw2reg    ({name}_hw2reg),",
                f"    .devmode_i ({devmode})",
                "  );", "",
            ]
        pins = []
        reset_by_port = {domain.reset: domain for domain in clocks.domains}
        for port in ports:
            match = _REG_PORT_RE.match(port.name)
            if match:
                signal = f"{match['name']}_{match['kind'][:-2]}"
            elif port.name in reset_by_port:
                signal = RtlFlow._domain_sync_reset_signal(reset_by_port[port.name])
            else:
                signal = port.name
            pins.append(f"    .{port.name:<22}({signal})")
        lines += [f"  {top}_core u_core (", ",\n".join(pins), "  );", "", "endmodule", ""]
        return "\n".join(lines)

    @staticmethod
    def write_top_from_core(top: str, rtl_dir: str | Path, itf: str, *, force: bool = False, clocks: ClockConfig | None = None) -> Path:
        """Write the integration top and protocol-facing register wrapper(s)."""

        rtl = Path(rtl_dir)
        core = rtl / f"{top}_core.sv"
        out = rtl / f"{top}.sv"
        if not core.exists():
            raise FileNotFoundError(core)
        cfg = clocks or ClockConfig.from_values()
        if cfg.multiclock:
            windows = RtlFlow._register_windows(RtlFlow.parse_ports(core), cfg)
            for window in windows:
                block = f"{top}_{window.name}"
                Files.safe_write_file(rtl / f"{block}_reg_top.sv", RtlFlow.render_register_top(block, itf), overwrite=force)
            text = RtlFlow.render_nclock_top(top, core, cfg, itf)
        else:
            Files.safe_write_file(rtl / f"{top}_reg_top.sv", RtlFlow.render_register_top(top, itf), overwrite=force)
            text = RtlFlow.render_top_from_core(top, core, itf, clocks=cfg)
        Files.safe_write_file(out, text, overwrite=force)
        return out

    @staticmethod
    def _resolve_tool(name: str) -> str:
        """Resolve one executable or raise a concise error."""

        path = Path(name)
        if path.is_file() and path.stat().st_mode & 0o111:
            return str(path.resolve())
        found = shutil.which(name)
        if found:
            return found
        raise FileNotFoundError(f"tool not found: {name}")

    @staticmethod
    def _source_text(path: Path) -> str:
        """Read source text while removing comments before module-name inference."""

        text = path.read_text(encoding="utf-8", errors="replace")
        text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
        text = re.sub(r"//.*?$", " ", text, flags=re.M)
        return text

    @staticmethod
    def infer_top(top_file: Path) -> str:
        """Infer the intended top module from one SystemVerilog source file."""

        names = MODULE_RE.findall(RtlFlow._source_text(top_file))
        if not names:
            raise ValueError(f"no module declaration found in top file: {top_file}")
        stem = top_file.stem
        if stem in names:
            return stem
        return names[0]

    @staticmethod
    def _ordered_roots(root: Path, top_file: Path, extra_roots: list[Path]) -> list[Path]:
        """Return unique recursive library roots, preferring the top's directory."""

        candidates = [top_file.parent, *extra_roots]
        if not extra_roots:
            candidates.append(root)

        ordered: list[Path] = []
        seen: set[Path] = set()
        for candidate in candidates:
            resolved = candidate.expanduser().resolve()
            if not resolved.is_dir():
                raise FileNotFoundError(f"source root not found: {resolved}")
            if resolved in seen:
                continue
            seen.add(resolved)
            ordered.append(resolved)
        return ordered

    @staticmethod
    def _recursive_search_args(roots: list[Path]) -> list[str]:
        """Return recursive include and library-search arguments for Slang."""

        args: list[str] = []
        for root in roots:
            recursive = str(root / "...")
            args.extend([f"-I{recursive}", "--libdir", recursive])
        return args

    @staticmethod
    def _default_timescale_args(top_file: Path) -> list[str]:
        """Use the top file's ``timescale`` as the default for loaded libraries."""

        match = TIMESCALE_RE.search(RtlFlow._source_text(top_file))
        if not match:
            return []
        return ["--timescale", f"{match.group(1)}/{match.group(2)}"]

    @staticmethod
    def _run_slang(
        *,
        slang: str,
        root: Path,
        search_roots: list[Path],
        top_file: Path,
        top: str | None,
        extra_args: str,
        action_args: list[str],
        synthesis: bool = True,
        runner=None,
        on: str = "local",
        outputs: tuple[Path, ...] = (),
    ) -> str:
        """Run Slang through the shared execution layer."""

        from flexsoc.backend.core import CommandRequest, ToolRunner

        root = root.expanduser().resolve()
        top_file = top_file.expanduser().resolve()
        if not top_file.is_file():
            raise FileNotFoundError(f"top source file not found: {top_file}")
        roots = RtlFlow._ordered_roots(root, top_file, search_roots)
        top_name = top or RtlFlow.infer_top(top_file)
        executable = RtlFlow._resolve_tool(slang) if on == "local" else slang
        command = (
            executable,
            "--top",
            top_name,
            *(("-DSYNTHESIS",) if synthesis else ()),
            *RtlFlow._default_timescale_args(top_file),
            *RtlFlow._recursive_search_args(roots),
            *shlex.split(extra_args),
            *action_args,
            str(top_file),
        )
        log = (outputs[0] if outputs else top_file).with_suffix(".slang.log")
        runner = runner or ToolRunner(project_root=root)
        request = CommandRequest(
            command,
            root,
            {},
            log,
            inputs=(top_file, *roots),
            outputs=outputs,
        )
        result = runner.run(request, on=on)
        if result.returncode:
            raise RuntimeError(f"Slang failed ({result.returncode}); log: {log}")
        log.unlink(missing_ok=True)
        return top_name

    @staticmethod
    def run_ast(args, *, runner=None, on: str = "local") -> None:
        """Generate elaborated Slang AST JSON."""

        json_path = args.json_out.resolve()
        json_path.parent.mkdir(parents=True, exist_ok=True)
        action = ["--ast-json", str(json_path), "--ast-json-source-info"]
        if args.scope:
            action.extend(["--ast-json-scope", args.scope])
        RtlFlow._run_slang(
            slang=args.slang,
            root=args.root,
            search_roots=args.search_root,
            top_file=args.top_file,
            top=args.top,
            extra_args=args.extra_args,
            action_args=action,
            runner=runner,
            on=on,
            outputs=(json_path,),
        )

    @staticmethod
    def _dep_lines(path: Path) -> list[str]:
        """Read one Slang dependency file, preserving first-seen order."""

        seen: set[str] = set()
        lines: list[str] = []
        for raw in path.read_text(encoding="utf-8").splitlines():
            item = raw.strip()
            if not item or item in seen:
                continue
            seen.add(item)
            lines.append(item)
        return lines

    @staticmethod
    def _resolve_dep(item: str, root: Path) -> Path:
        """Resolve one Slang dependency path against the Slang working root."""

        path = Path(item)
        if not path.is_absolute():
            path = root / path
        return path.resolve()

    @staticmethod
    def _command_path(path: Path, root: Path) -> str:
        """Prefer root-relative paths in portable standalone command files."""

        path = path.resolve()
        try:
            return path.relative_to(root.resolve()).as_posix()
        except ValueError:
            return path.as_posix()

    @staticmethod
    def _portable_extra_args(extra_args: str, root: Path) -> list[str]:
        """Keep portable preprocessor options that affect the discovered closure."""

        tokens = shlex.split(extra_args)
        result: list[str] = []
        index = 0
        while index < len(tokens):
            token = tokens[index]
            if token.startswith("+define+") or token.startswith("+incdir+"):
                result.append(token)
            elif token.startswith("-D") and token != "-D":
                result.append(f"+define+{token[2:]}")
            elif token == "-D" and index + 1 < len(tokens):
                index += 1
                result.append(f"+define+{tokens[index]}")
            elif token.startswith("-I") and token != "-I":
                include_dir = Path(token[2:])
                if not include_dir.is_absolute():
                    include_dir = root / include_dir
                result.append(f"+incdir+{RtlFlow._command_path(include_dir, root)}")
            elif token == "-I" and index + 1 < len(tokens):
                index += 1
                include_dir = Path(tokens[index])
                if not include_dir.is_absolute():
                    include_dir = root / include_dir
                result.append(f"+incdir+{RtlFlow._command_path(include_dir, root)}")
            index += 1
        return result

    @staticmethod
    def _is_under(path: Path, roots: list[Path]) -> bool:
        """Return whether ``path`` belongs to one of the configured common roots."""

        resolved = path.resolve()
        for root in roots:
            try:
                resolved.relative_to(root.resolve())
                return True
            except ValueError:
                continue
        return False

    @staticmethod
    def _write_lines(path: Path, lines: list[str]) -> None:
        """Write one command file with a trailing newline."""

        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\n".join(lines) + "\n", encoding="utf-8")

    @staticmethod
    def _split_flow_filelists(
        *,
        common_out: Path,
        ip_out: Path,
        modules: list[Path],
        includes: list[Path],
        common_roots: list[Path],
        extra_args: str,
        root: Path,
        synthesis: bool,
    ) -> None:
        """Write absolute-path FlexSoC common/IP command files from one Slang closure."""

        common_roots = [item.expanduser().resolve() for item in common_roots]
        common_lines = ["# Auto-generated by Slang: shared RTL"]
        if synthesis:
            common_lines.append("+define+SYNTHESIS")
        ip_lines = ["# Auto-generated by Slang: IP/run RTL"]
        seen_common = set(common_lines)
        seen_ip = set(ip_lines)

        def append(lines: list[str], seen: set[str], item: str) -> None:
            if item not in seen:
                seen.add(item)
                lines.append(item)

        for option in RtlFlow._portable_extra_args(extra_args, root):
            if option.startswith("+incdir+"):
                dirs = [part for part in option[len("+incdir+"):].split("+") if part]
                for directory in dirs:
                    path = Path(directory)
                    if not path.is_absolute():
                        path = (root / path).resolve()
                    target_lines, target_seen = (
                        (common_lines, seen_common) if RtlFlow._is_under(path, common_roots) else (ip_lines, seen_ip)
                    )
                    append(target_lines, target_seen, f"+incdir+{path.as_posix()}")
            else:
                append(common_lines, seen_common, option)

        include_dirs: list[Path] = []
        seen_dirs: set[Path] = set()
        for source in includes:
            directory = source.parent.resolve()
            if directory in seen_dirs:
                continue
            seen_dirs.add(directory)
            include_dirs.append(directory)

        for directory in include_dirs:
            target_lines, target_seen = (
                (common_lines, seen_common) if RtlFlow._is_under(directory, common_roots) else (ip_lines, seen_ip)
            )
            append(target_lines, target_seen, f"+incdir+{directory.as_posix()}")

        for source in modules:
            target_lines, target_seen = (
                (common_lines, seen_common) if RtlFlow._is_under(source, common_roots) else (ip_lines, seen_ip)
            )
            append(target_lines, target_seen, source.resolve().as_posix())

        RtlFlow._write_lines(common_out, common_lines)
        RtlFlow._write_lines(ip_out, ip_lines)

    @staticmethod
    def run_flist(args, *, runner=None, on: str = "local") -> None:
        """Generate a hierarchy-trimmed Slang filelist, optionally split for FlexSoC."""

        root = args.root.expanduser().resolve()
        outputs = [path for path in (args.output, args.common_out, args.ip_out) if path is not None]
        if not outputs:
            raise ValueError("flist requires --output or both --common-out/--ip-out")
        if (args.common_out is None) != (args.ip_out is None):
            raise ValueError("--common-out and --ip-out must be provided together")

        resolved_outputs = [path.expanduser().resolve() for path in outputs]
        for path in resolved_outputs:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.unlink(missing_ok=True)

        anchor = resolved_outputs[0]
        module_deps = anchor.with_suffix(anchor.suffix + ".modules.tmp")
        include_deps = anchor.with_suffix(anchor.suffix + ".includes.tmp")

        try:
            RtlFlow._run_slang(
                slang=args.slang,
                root=root,
                search_roots=args.search_root,
                top_file=args.top_file,
                top=args.top,
                extra_args=args.extra_args,
                action_args=[
                    "--Mmodule",
                    str(module_deps),
                    "--Minclude",
                    str(include_deps),
                    "--depfile-trim",
                    "--depfile-sort",
                ],
                synthesis=args.synthesis,
                runner=runner,
                on=on,
                outputs=(module_deps, include_deps),
            )

            modules = [RtlFlow._resolve_dep(item, root) for item in RtlFlow._dep_lines(module_deps)]
            includes = [RtlFlow._resolve_dep(item, root) for item in RtlFlow._dep_lines(include_deps)]

            if args.output is not None:
                lines: list[str] = []
                seen_lines: set[str] = set()

                def append_unique(item: str) -> None:
                    if item not in seen_lines:
                        seen_lines.add(item)
                        lines.append(item)

                if args.synthesis:
                    append_unique("+define+SYNTHESIS")
                for option in RtlFlow._portable_extra_args(args.extra_args, root):
                    append_unique(option)
                seen_dirs: set[Path] = set()
                for source in includes:
                    directory = source.parent.resolve()
                    if directory in seen_dirs:
                        continue
                    seen_dirs.add(directory)
                    append_unique(f"+incdir+{RtlFlow._command_path(directory, root)}")
                for source in modules:
                    append_unique(RtlFlow._command_path(source, root))
                RtlFlow._write_lines(args.output.expanduser().resolve(), lines)

            if args.common_out is not None and args.ip_out is not None:
                RtlFlow._split_flow_filelists(
                    common_out=args.common_out.expanduser().resolve(),
                    ip_out=args.ip_out.expanduser().resolve(),
                    modules=modules,
                    includes=includes,
                    common_roots=args.common_root,
                    extra_args=args.extra_args,
                    root=root,
                    synthesis=args.synthesis,
                )
        finally:
            module_deps.unlink(missing_ok=True)
            include_deps.unlink(missing_ok=True)

    @staticmethod
    def run_hier(args, *, runner=None, on: str = "local") -> None:
        """Write hierarchy through the shared execution layer."""

        from flexsoc.backend.core import CommandRequest, ToolRunner

        root = args.root.expanduser().resolve()
        top_file = args.top_file.expanduser().resolve()
        if not top_file.is_file():
            raise FileNotFoundError(f"top source file not found: {top_file}")
        roots = RtlFlow._ordered_roots(root, top_file, args.search_root)
        top_name = args.top or RtlFlow.infer_top(top_file)
        output = args.output.expanduser().resolve()
        output.parent.mkdir(parents=True, exist_ok=True)
        executable = RtlFlow._resolve_tool(args.slang_hier) if on == "local" else args.slang_hier
        command = (
            executable,
            "--top",
            top_name,
            "-DSYNTHESIS",
            *RtlFlow._default_timescale_args(top_file),
            *RtlFlow._recursive_search_args(roots),
            *shlex.split(args.extra_args),
            str(top_file),
        )
        runner = runner or ToolRunner(project_root=root)
        result = runner.run(
            CommandRequest(command, root, {}, output, inputs=(top_file, *roots), outputs=(output,)),
            on=on,
        )
        if result.returncode:
            raise RuntimeError(f"slang-hier failed ({result.returncode}); output: {output}")
