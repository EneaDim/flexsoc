"""Formal scaffold and property verification flow."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from textwrap import dedent
from typing import Sequence

from flexsoc.backend.core import clock_config


@dataclass(frozen=True, slots=True)
class PropertyFormalConfig:
    """Inputs required to build one authored-property SBY configuration."""

    top: str
    filelists: tuple[Path, ...]
    properties_dir: Path
    mode: str
    engine: str
    depth: int
    output: Path
    bmc_engine: str = "smtbmc bitwuzla"
    bmc_depth: int = 30
    bmc_append: int = 5
    multiclock: bool = False


def _resolved(paths: Sequence[Path]) -> tuple[Path, ...]:
    """Resolve paths without requiring them to share a common parent."""

    return tuple(path.expanduser().resolve() for path in paths)


def _require_files(paths: Sequence[Path], *, label: str) -> tuple[Path, ...]:
    """Return resolved paths or fail early with an actionable error."""

    resolved = _resolved(paths)
    missing = [path for path in resolved if not path.is_file()]
    if missing:
        rendered = "\n  ".join(str(path) for path in missing)
        raise ValueError(f"missing {label}:\n  {rendered}")
    return resolved


def property_files(directory: Path, *, required: bool = True) -> tuple[Path, ...]:
    """Return authored Verilog/SystemVerilog property files recursively."""

    root = directory.expanduser().resolve()
    if not root.is_dir():
        if not required:
            return ()
        raise ValueError(
            f"formal property directory does not exist: {root}\n"
            "create it and add at least one .sv/.v property file before running formal"
        )
    files = tuple(
        sorted(
            path.resolve()
            for path in root.rglob("*")
            if path.is_file() and path.suffix.lower() in {".sv", ".v"}
        )
    )
    if not files and required:
        raise ValueError(
            f"no formal property files found under: {root}\n"
            "FlexSoC refuses to report a vacuous formal PASS with zero authored properties"
        )
    return files


def _read_slang_command(
    *,
    top: str,
    filelists: Sequence[Path],
    extra_sources: Sequence[Path] = (),
    formal: bool,
) -> str:
    """Render the canonical Slang-backed Yosys frontend command."""

    define = "FORMAL" if formal else "SYNTHESIS"
    options = [f"-D {define}"]
    if not formal:
        options.append("--ignore-assertions")
    # yosys-slang forwards literal quote characters in command-file arguments.
    # FlexSoC run paths have no spaces, so pass filelist/source paths unquoted.
    options.extend(f"-f {path}" for path in filelists)
    options.extend(str(path) for path in extra_sources)
    options.append(f"--top {top}")
    return "read_slang " + " ".join(options)


def render_csr_properties(mode: str) -> str:
    """Render automatic prove or cover checks for reggen CSR primitives."""

    if mode == "cover":
        return r'''
module flexsoc_csr_subreg_cover #(
  parameter prim_subreg_pkg::sw_access_e SwAccess = prim_subreg_pkg::SwAccessRW
) (
  input logic clk_i, rst_ni, we
);
  if (SwAccess != prim_subreg_pkg::SwAccessRO) begin : gen_sw_cover
    always_ff @(posedge clk_i) if (rst_ni) cover (we);
  end
endmodule

bind prim_subreg flexsoc_csr_subreg_cover #(.SwAccess(SwAccess))
  flexsoc_csr_subreg_cover_i (.clk_i(clk_i), .rst_ni(rst_ni), .we(we));
'''

    return r'''
module flexsoc_csr_arb_checker #(
  parameter int DW = 32,
  parameter prim_subreg_pkg::sw_access_e SwAccess = prim_subreg_pkg::SwAccessRW,
  parameter bit Mubi = 1'b0
) (
  input logic we, de,
  input logic [DW-1:0] wd, d, q,
  input logic wr_en,
  input logic [DW-1:0] wr_data
);
  logic exp_en;
  logic [DW-1:0] exp_data;

  always_comb begin
    exp_en = we | de;
    exp_data = d;
    case (SwAccess)
      prim_subreg_pkg::SwAccessRW,
      prim_subreg_pkg::SwAccessWO: exp_data = we ? wd : d;
      prim_subreg_pkg::SwAccessRO: begin exp_en = de; exp_data = d; end
      prim_subreg_pkg::SwAccessW1S: begin
        if (!Mubi) exp_data = (de ? d : q) | (we ? wd : '0);
        else if (DW == 4)  exp_data = prim_mubi_pkg::mubi4_or_hi(prim_mubi_pkg::mubi4_t'(de ? d : q), we ? prim_mubi_pkg::mubi4_t'(wd) : prim_mubi_pkg::MuBi4False);
        else if (DW == 8)  exp_data = prim_mubi_pkg::mubi8_or_hi(prim_mubi_pkg::mubi8_t'(de ? d : q), we ? prim_mubi_pkg::mubi8_t'(wd) : prim_mubi_pkg::MuBi8False);
        else if (DW == 12) exp_data = prim_mubi_pkg::mubi12_or_hi(prim_mubi_pkg::mubi12_t'(de ? d : q), we ? prim_mubi_pkg::mubi12_t'(wd) : prim_mubi_pkg::MuBi12False);
        else if (DW == 16) exp_data = prim_mubi_pkg::mubi16_or_hi(prim_mubi_pkg::mubi16_t'(de ? d : q), we ? prim_mubi_pkg::mubi16_t'(wd) : prim_mubi_pkg::MuBi16False);
      end
      prim_subreg_pkg::SwAccessW1C: begin
        if (!Mubi) exp_data = (de ? d : q) & (we ? ~wd : '1);
        else if (DW == 4)  exp_data = prim_mubi_pkg::mubi4_and_hi(prim_mubi_pkg::mubi4_t'(de ? d : q), we ? prim_mubi_pkg::mubi4_t'(~wd) : prim_mubi_pkg::MuBi4True);
        else if (DW == 8)  exp_data = prim_mubi_pkg::mubi8_and_hi(prim_mubi_pkg::mubi8_t'(de ? d : q), we ? prim_mubi_pkg::mubi8_t'(~wd) : prim_mubi_pkg::MuBi8True);
        else if (DW == 12) exp_data = prim_mubi_pkg::mubi12_and_hi(prim_mubi_pkg::mubi12_t'(de ? d : q), we ? prim_mubi_pkg::mubi12_t'(~wd) : prim_mubi_pkg::MuBi12True);
        else if (DW == 16) exp_data = prim_mubi_pkg::mubi16_and_hi(prim_mubi_pkg::mubi16_t'(de ? d : q), we ? prim_mubi_pkg::mubi16_t'(~wd) : prim_mubi_pkg::MuBi16True);
      end
      prim_subreg_pkg::SwAccessW0C: begin
        if (!Mubi) exp_data = (de ? d : q) & (we ? wd : '1);
        else if (DW == 4)  exp_data = prim_mubi_pkg::mubi4_and_hi(prim_mubi_pkg::mubi4_t'(de ? d : q), we ? prim_mubi_pkg::mubi4_t'(wd) : prim_mubi_pkg::MuBi4True);
        else if (DW == 8)  exp_data = prim_mubi_pkg::mubi8_and_hi(prim_mubi_pkg::mubi8_t'(de ? d : q), we ? prim_mubi_pkg::mubi8_t'(wd) : prim_mubi_pkg::MuBi8True);
        else if (DW == 12) exp_data = prim_mubi_pkg::mubi12_and_hi(prim_mubi_pkg::mubi12_t'(de ? d : q), we ? prim_mubi_pkg::mubi12_t'(wd) : prim_mubi_pkg::MuBi12True);
        else if (DW == 16) exp_data = prim_mubi_pkg::mubi16_and_hi(prim_mubi_pkg::mubi16_t'(de ? d : q), we ? prim_mubi_pkg::mubi16_t'(wd) : prim_mubi_pkg::MuBi16True);
      end
      prim_subreg_pkg::SwAccessRC: begin
        if (!Mubi) exp_data = (de ? d : q) & (we ? '0 : '1);
        else if (DW == 4)  exp_data = prim_mubi_pkg::mubi4_and_hi(prim_mubi_pkg::mubi4_t'(de ? d : q), we ? prim_mubi_pkg::MuBi4False : prim_mubi_pkg::MuBi4True);
        else if (DW == 8)  exp_data = prim_mubi_pkg::mubi8_and_hi(prim_mubi_pkg::mubi8_t'(de ? d : q), we ? prim_mubi_pkg::MuBi8False : prim_mubi_pkg::MuBi8True);
        else if (DW == 12) exp_data = prim_mubi_pkg::mubi12_and_hi(prim_mubi_pkg::mubi12_t'(de ? d : q), we ? prim_mubi_pkg::MuBi12False : prim_mubi_pkg::MuBi12True);
        else if (DW == 16) exp_data = prim_mubi_pkg::mubi16_and_hi(prim_mubi_pkg::mubi16_t'(de ? d : q), we ? prim_mubi_pkg::MuBi16False : prim_mubi_pkg::MuBi16True);
      end
      default: begin exp_en = de; exp_data = d; end
    endcase

    assert (!Mubi || DW == 4 || DW == 8 || DW == 12 || DW == 16);
    assert (wr_en == exp_en);
    if (!Mubi || DW == 4 || DW == 8 || DW == 12 || DW == 16)
      assert (wr_data == exp_data);
  end
endmodule

module flexsoc_csr_subreg_checker #(
  parameter int DW = 32,
  parameter prim_subreg_pkg::sw_access_e SwAccess = prim_subreg_pkg::SwAccessRW,
  parameter logic [DW-1:0] RESVAL = '0
) (
  input logic clk_i, rst_ni, we, de, wr_en,
  input logic [DW-1:0] wd, d, q, wr_data, ds, qs,
  input logic qe
);
  logic past_valid = 1'b0;
  logic prev_wr_en;
  logic [DW-1:0] prev_wr_data, prev_q;

  always_comb begin
    assert (qe == wr_en);
    assert (ds == (wr_en ? wr_data : qs));
    if (SwAccess == prim_subreg_pkg::SwAccessRC)
      assert (qs == (de && we ? d : q));
    else
      assert (qs == q);
    if (!rst_ni) assert (q == RESVAL);
  end

  // Keep one-cycle history explicitly for frontend portability.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      past_valid <= 1'b0;
      prev_wr_en <= 1'b0;
      prev_wr_data <= '0;
      prev_q <= RESVAL;
    end else begin
      if (past_valid && prev_wr_en) assert (q == prev_wr_data);
      else if (past_valid) assert (q == prev_q);
      prev_wr_en <= wr_en;
      prev_wr_data <= wr_data;
      prev_q <= q;
      past_valid <= 1'b1;
    end
  end

endmodule

module flexsoc_csr_subreg_ext_checker #(parameter int DW = 32) (
  input logic re, we,
  input logic [DW-1:0] wd, d,
  input logic qe, qre,
  input logic [DW-1:0] q, ds, qs
);
  always_comb begin
    assert (ds == d);
    assert (qs == d);
    assert (q == wd);
    assert (qe == we);
    assert (qre == re);
  end
endmodule

bind prim_subreg_arb flexsoc_csr_arb_checker #(
  .DW(DW), .SwAccess(SwAccess), .Mubi(Mubi)
) flexsoc_csr_arb_checker_i (
  .we(we), .de(de), .wd(wd), .d(d), .q(q), .wr_en(wr_en), .wr_data(wr_data)
);

bind prim_subreg flexsoc_csr_subreg_checker #(
  .DW(DW), .SwAccess(SwAccess), .RESVAL(RESVAL)
) flexsoc_csr_subreg_checker_i (
  .clk_i(clk_i), .rst_ni(rst_ni), .we(we), .de(de), .wd(wd), .d(d),
  .q(q), .wr_en(wr_en), .wr_data(wr_data), .ds(ds), .qs(qs), .qe(qe)
);

bind prim_subreg_ext flexsoc_csr_subreg_ext_checker #(.DW(DW))
  flexsoc_csr_subreg_ext_checker_i (
    .re(re), .we(we), .wd(wd), .d(d), .qe(qe), .qre(qre), .q(q), .ds(ds), .qs(qs)
  );
'''


def render_design_prove(top: str, *, multiclock: bool) -> str:
    """Render starter assertions for the generated single- or N-clock core."""

    if multiclock:
        return dedent(f"""\
        // Generated starter assertions for {top}_core.
        // This file becomes designer-owned after creation and is never overwritten.
        module {top}_scaffold_prove (
          input logic dsp_clk_i, dsp_rst_ni,
          input logic enable_rx, fifo_wready, rx_ready_o,
          input logic enable_dsp, fifo_rvalid, dsp_pipe_valid_q, dsp_valid_o, dsp_ready_i, fifo_rready,
          input logic clk_gate_en_dsp, dsp_clk_active, soft_reset_dsp,
          input logic signed [31:0] dsp_result_o,
          input logic dsp_above_threshold_o, dsp_overflow_o
        );
          logic past_valid = 1'b0;

          always_comb begin
            assert (rx_ready_o == (enable_rx & fifo_wready));
            assert (fifo_rready == (enable_dsp & fifo_rvalid & (!dsp_pipe_valid_q | !dsp_valid_o | dsp_ready_i)));
            assert (dsp_clk_active == (enable_dsp & (!clk_gate_en_dsp | fifo_rvalid | dsp_pipe_valid_q | dsp_valid_o)));
          end

          always_ff @(posedge dsp_clk_i) begin
            if (past_valid && (!$past(dsp_rst_ni) || $past(soft_reset_dsp))) begin
              assert (!dsp_valid_o);
              assert (dsp_result_o == '0);
              assert (!dsp_above_threshold_o);
              assert (!dsp_overflow_o);
            end
            past_valid <= 1'b1;
          end
        endmodule

        bind {top}_core {top}_scaffold_prove {top}_scaffold_prove_i (
          .dsp_clk_i(dsp_clk_i), .dsp_rst_ni(dsp_rst_ni),
          .enable_rx(enable_rx), .fifo_wready(fifo_wready), .rx_ready_o(rx_ready_o),
          .enable_dsp(enable_dsp), .fifo_rvalid(fifo_rvalid), .dsp_pipe_valid_q(dsp_pipe_valid_q),
          .dsp_valid_o(dsp_valid_o), .dsp_ready_i(dsp_ready_i), .fifo_rready(fifo_rready),
          .clk_gate_en_dsp(clk_gate_en_dsp), .dsp_clk_active(dsp_clk_active),
          .soft_reset_dsp(soft_reset_dsp), .dsp_result_o(dsp_result_o),
          .dsp_above_threshold_o(dsp_above_threshold_o), .dsp_overflow_o(dsp_overflow_o)
        );
        """)

    return dedent(f"""\
    // Generated starter assertions for {top}_core.
    // This file becomes designer-owned after creation and is never overwritten.
    module {top}_scaffold_prove (
      input logic clk_i, rst_ni,
      input logic [31:0] data_o, pipe_q1,
      input logic valid_o, valid_q1
    );
      logic past_valid = 1'b0;

      always_comb begin
        assert (data_o == pipe_q1);
        assert (valid_o == valid_q1);
      end

      always_ff @(posedge clk_i) begin
        if (past_valid && !$past(rst_ni)) begin
          assert (data_o == '0);
          assert (!valid_o);
        end
        past_valid <= 1'b1;
      end
    endmodule

    bind {top}_core {top}_scaffold_prove {top}_scaffold_prove_i (
      .clk_i(clk_i), .rst_ni(rst_ni), .data_o(data_o), .pipe_q1(pipe_q1),
      .valid_o(valid_o), .valid_q1(valid_q1)
    );
    """)


def render_design_cover(top: str, *, multiclock: bool) -> str:
    """Render starter covers for the generated single- or N-clock core."""

    if multiclock:
        return dedent(f"""\
        // Generated starter covers for {top}_core.
        // This file becomes designer-owned after creation and is never overwritten.
        module {top}_scaffold_cover (
          input logic cfg_clk_i, cfg_rst_ni, cfg_enable,
          input logic rx_clk_i, rx_rst_ni, rx_valid_i, rx_ready_o,
          input logic dsp_clk_i, dsp_rst_ni, fifo_rvalid, dsp_valid_o, dsp_ready_i
        );
          always_ff @(posedge cfg_clk_i) if (cfg_rst_ni) cover (cfg_enable);
          always_ff @(posedge rx_clk_i) if (rx_rst_ni) cover (rx_valid_i && rx_ready_o);
          always_ff @(posedge dsp_clk_i) if (dsp_rst_ni) begin
            cover (fifo_rvalid);
            cover (dsp_valid_o);
            cover (dsp_valid_o && dsp_ready_i);
          end
        endmodule

        bind {top}_core {top}_scaffold_cover {top}_scaffold_cover_i (
          .cfg_clk_i(cfg_clk_i), .cfg_rst_ni(cfg_rst_ni), .cfg_enable(cfg_enable),
          .rx_clk_i(rx_clk_i), .rx_rst_ni(rx_rst_ni), .rx_valid_i(rx_valid_i),
          .rx_ready_o(rx_ready_o), .dsp_clk_i(dsp_clk_i), .dsp_rst_ni(dsp_rst_ni),
          .fifo_rvalid(fifo_rvalid), .dsp_valid_o(dsp_valid_o), .dsp_ready_i(dsp_ready_i)
        );
        """)

    return dedent(f"""\
    // Generated starter covers for {top}_core.
    // This file becomes designer-owned after creation and is never overwritten.
    module {top}_scaffold_cover (
      input logic clk_i, rst_ni, valid_i, valid_o,
      input logic [31:0] data_o
    );
      logic past_valid = 1'b0;

      always_ff @(posedge clk_i) begin
        if (rst_ni) begin
          cover (valid_i);
          cover (valid_o);
          cover (valid_o && |data_o);
          if (past_valid) cover (valid_i && !$past(valid_i));
        end
        past_valid <= 1'b1;
      end
    endmodule

    bind {top}_core {top}_scaffold_cover {top}_scaffold_cover_i (
      .clk_i(clk_i), .rst_ni(rst_ni), .valid_i(valid_i),
      .valid_o(valid_o), .data_o(data_o)
    );
    """)


def _write_scaffold(path: Path, text: str, *, incompatible: str | None = None) -> Path:
    """Create one designer-owned starter and reject an untouched stale topology."""

    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        if incompatible is not None and path.read_text(encoding="utf-8") == incompatible:
            raise ValueError(
                f"formal scaffold topology changed: {path}; preserve authored work, "
                "then remove or update the stale generated starter"
            )
        return path.resolve()
    path.write_text(text, encoding="utf-8")
    return path.resolve()


def generate_scaffold(
    top: str, formal_dir: Path, *, multiclock: bool | None = None
) -> tuple[Path, ...]:
    """Create non-destructive design-property starters for the generated core."""

    root = formal_dir.expanduser().resolve() / "properties"
    is_multiclock = clock_config().multiclock if multiclock is None else multiclock
    prove = _write_scaffold(
        root / "prove" / f"{top}_prove.sv",
        render_design_prove(top, multiclock=is_multiclock),
        incompatible=render_design_prove(top, multiclock=not is_multiclock),
    )
    cover = _write_scaffold(
        root / "cover" / f"{top}_cover.sv",
        render_design_cover(top, multiclock=is_multiclock),
        incompatible=render_design_cover(top, multiclock=not is_multiclock),
    )
    return prove, cover


def render_sby(cfg: PropertyFormalConfig, generated_sources: Sequence[Path] = ()) -> str:
    """Render one prove/BMC task file or one cover configuration."""

    if cfg.mode not in {"prove", "cover"}:
        raise ValueError(f"unsupported formal mode: {cfg.mode!r}")
    if cfg.depth <= 0:
        raise ValueError("formal depth must be > 0")
    if not cfg.engine.strip():
        raise ValueError("formal engine must not be empty")
    if cfg.mode == "prove" and (cfg.bmc_depth <= 0 or cfg.bmc_append < 0 or not cfg.bmc_engine.strip()):
        raise ValueError("BMC engine/depth/append are invalid")

    filelists = _require_files(cfg.filelists, label="RTL filelist(s)")
    generated = _require_files(generated_sources, label="generated property source(s)") if generated_sources else ()
    authored = tuple(
        path for path in property_files(cfg.properties_dir, required=not generated)
        if path not in generated
    )
    properties = (*generated, *authored)
    read_cmd = _read_slang_command(
        top=cfg.top,
        filelists=filelists,
        extra_sources=properties,
        formal=True,
    )

    if cfg.mode == "prove":
        header = [
            "[tasks]",
            "bmc",
            "prove",
            "",
            "[options]",
            "bmc: mode bmc",
            f"bmc: depth {cfg.bmc_depth}",
            f"bmc: append {cfg.bmc_append}",
            *(["bmc: multiclock on"] if cfg.multiclock else []),
            "prove: mode prove",
            *(["prove: multiclock on"] if cfg.multiclock else []),
            "",
            "[engines]",
            f"bmc: {cfg.bmc_engine.strip()}",
            f"prove: {cfg.engine.strip()}",
        ]
    else:
        header = [
            "[options]",
            "mode cover",
            f"depth {cfg.depth}",
            *(["multiclock on"] if cfg.multiclock else []),
            "cover_assert off",
            "",
            "[engines]",
            cfg.engine.strip(),
        ]

    return "\n".join(
        [
            *header,
            "",
            "[script]",
            read_cmd,
            f"prep -top {cfg.top}",
            "",
        ]
    )


def write_config(path: Path, text: str) -> Path:
    """Write one generated formal configuration."""

    output = path.expanduser().resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(text, encoding="utf-8")
    return output


def generate_property_config(
    cfg: PropertyFormalConfig, generated_sources: Sequence[Path] = ()
) -> Path:
    """Generate one SBY file and return its path."""

    return write_config(cfg.output, render_sby(cfg, generated_sources))


def generate_csr_config(cfg: PropertyFormalConfig, generated: Path) -> Path:
    """Generate automatic CSR properties plus one SBY configuration."""

    source = write_config(generated, render_csr_properties(cfg.mode))
    return generate_property_config(cfg, (source,))


@dataclass(slots=True)
class FormalFlow:
    """Create property-formal scaffolds and SBY configurations."""

    runner: object | None = None

    def setup_scaffold(
        self, top: str, formal_dir: Path, *, multiclock: bool | None = None
    ) -> tuple[Path, ...]:
        """Create or preserve designer-owned property sources."""

        return generate_scaffold(top, formal_dir, multiclock=multiclock)

    def setup_design(
        self,
        *,
        top: str,
        filelists: Sequence[Path],
        properties_dir: Path,
        mode: str,
        engine: str,
        output: Path,
        depth: int = 20,
        bmc_engine: str = "smtbmc bitwuzla",
        bmc_depth: int = 30,
        bmc_append: int = 5,
        multiclock: bool | None = None,
    ) -> Path:
        """Generate one authored-property SBY configuration."""

        cfg = PropertyFormalConfig(
            top=top,
            filelists=tuple(filelists),
            properties_dir=properties_dir,
            mode=mode,
            engine=engine,
            depth=depth,
            output=output,
            bmc_engine=bmc_engine,
            bmc_depth=bmc_depth,
            bmc_append=bmc_append,
            multiclock=clock_config().multiclock if multiclock is None else multiclock,
        )
        return generate_property_config(cfg)

    def setup_csr(
        self,
        *,
        top: str,
        filelists: Sequence[Path],
        properties_dir: Path,
        generated: Path,
        mode: str,
        engine: str,
        output: Path,
        depth: int = 20,
        bmc_engine: str = "smtbmc bitwuzla",
        bmc_depth: int = 30,
        bmc_append: int = 5,
        multiclock: bool | None = None,
    ) -> Path:
        """Generate automatic CSR properties and their SBY configuration."""

        cfg = PropertyFormalConfig(
            top=top,
            filelists=tuple(filelists),
            properties_dir=properties_dir,
            mode=mode,
            engine=engine,
            depth=depth,
            output=output,
            bmc_engine=bmc_engine,
            bmc_depth=bmc_depth,
            bmc_append=bmc_append,
            multiclock=clock_config().multiclock if multiclock is None else multiclock,
        )
        return generate_csr_config(cfg, generated)
    def _run_sby(
        self,
        config: Path,
        *,
        task: str | None,
        run_name: str | None,
        log: Path,
        sby: str = "sby",
        on: str = "local",
    ):
        """Execute one SBY task with deterministic cwd and logging."""
        from flexsoc.backend.core import CommandRequest, ToolRunner
        runner = self.runner or ToolRunner()
        if not config.is_file():
            raise FileNotFoundError(f"formal configuration not found: {config}")
        argv=[sby, "-f"]
        if run_name:
            argv += ["-d", run_name]
        argv.append(config.name)
        if task:
            argv.append(task)
        result=runner.run(CommandRequest(tuple(argv), config.parent, {}, log, inputs=(config,)), on=on)
        if result.returncode:
            raise RuntimeError(f"formal task failed; log: {log}")
        return result

    def run_bmc(self, config: Path, *, top: str, log: Path, sby: str = "sby", on: str = "local"):
        """Run authored-property bounded model checking."""
        return self._run_sby(config, task="bmc", run_name=f"{top}_bmc", log=log, sby=sby, on=on)

    def run_prove(self, config: Path, *, top: str, log: Path, sby: str = "sby", on: str = "local"):
        """Run authored-property induction/PDR proof."""
        return self._run_sby(config, task="prove", run_name=f"{top}_prove", log=log, sby=sby, on=on)

    def run_cover(self, config: Path, *, log: Path, sby: str = "sby", on: str = "local"):
        """Run authored-property cover analysis."""
        return self._run_sby(config, task=None, run_name=None, log=log, sby=sby, on=on)

    def run_csr_bmc(self, config: Path, *, top: str, log: Path, sby: str = "sby", on: str = "local"):
        """Run automatic CSR bounded model checking."""
        return self._run_sby(config, task="bmc", run_name=f"{top}_csr_bmc", log=log, sby=sby, on=on)

    def run_csr_prove(self, config: Path, *, top: str, log: Path, sby: str = "sby", on: str = "local"):
        """Run automatic CSR proof."""
        return self._run_sby(config, task="prove", run_name=f"{top}_csr_prove", log=log, sby=sby, on=on)

    def run_csr_cover(self, config: Path, *, log: Path, sby: str = "sby", on: str = "local"):
        """Run automatic CSR cover analysis."""
        return self._run_sby(config, task=None, run_name=None, log=log, sby=sby, on=on)

    def flow_from_context(self, context, *, on: str = "local"):
        """Prepare and run the canonical CSR + authored formal sequence."""
        paths = context.paths
        values = context.values
        top = paths.top
        common=(paths.rtl_common, paths.rtl_ip)
        props=paths.formal / "properties"
        runs=paths.formal / "runs"
        logs=paths.logs / "dv" / "formal"
        self.setup_scaffold(top, paths.formal, multiclock=context.clocks.multiclock)
        prove=self.setup_design(top=top, filelists=common, properties_dir=props/"prove", mode="prove", engine=values.get("FORMAL_PROVE_ENGINE","abc pdr"), output=runs/"properties"/"prove"/f"{top}_prove.sby", depth=int(values.get("FORMAL_DEPTH","20")), bmc_engine=values.get("FORMAL_BMC_ENGINE","smtbmc bitwuzla"), bmc_depth=int(values.get("FORMAL_BMC_DEPTH","30")), bmc_append=int(values.get("FORMAL_BMC_APPEND","5")), multiclock=context.clocks.multiclock)
        cover=self.setup_design(top=top, filelists=common, properties_dir=props/"cover", mode="cover", engine=values.get("FORMAL_COVER_ENGINE","btor btormc"), output=runs/"properties"/"cover"/f"{top}_cover.sby", depth=int(values.get("FORMAL_DEPTH","20")), multiclock=context.clocks.multiclock)
        csr_prove=self.setup_csr(top=top, filelists=common, properties_dir=paths.formal/"csr"/"prove", generated=paths.formal/"csr"/"prove"/f"{top}_csr_auto_prove.sv", mode="prove", engine=values.get("FORMAL_PROVE_ENGINE","abc pdr"), output=runs/"csr"/"prove"/f"{top}_csr_prove.sby", depth=int(values.get("FORMAL_DEPTH","20")), bmc_engine=values.get("FORMAL_BMC_ENGINE","smtbmc bitwuzla"), bmc_depth=int(values.get("FORMAL_BMC_DEPTH","30")), bmc_append=int(values.get("FORMAL_BMC_APPEND","5")), multiclock=context.clocks.multiclock)
        csr_cover=self.setup_csr(top=top, filelists=common, properties_dir=paths.formal/"csr"/"cover", generated=paths.formal/"csr"/"cover"/f"{top}_csr_auto_cover.sv", mode="cover", engine=values.get("FORMAL_COVER_ENGINE","btor btormc"), output=runs/"csr"/"cover"/f"{top}_csr_cover.sby", depth=int(values.get("FORMAL_DEPTH","20")), multiclock=context.clocks.multiclock)
        sby=values.get("SBY","sby")
        return (
            self.run_csr_bmc(csr_prove, top=top, log=logs/"csr"/f"{top}_bmc.log", sby=sby, on=on),
            self.run_bmc(prove, top=top, log=logs/"properties"/f"{top}_bmc.log", sby=sby, on=on),
            self.run_csr_prove(csr_prove, top=top, log=logs/"csr"/f"{top}_prove.log", sby=sby, on=on),
            self.run_prove(prove, top=top, log=logs/"properties"/f"{top}_prove.log", sby=sby, on=on),
            self.run_csr_cover(csr_cover, log=logs/"csr"/f"{top}_cover.log", sby=sby, on=on),
            self.run_cover(cover, log=logs/"properties"/f"{top}_cover.log", sby=sby, on=on),
        )

