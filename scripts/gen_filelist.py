#!/usr/bin/env python3
"""
gen_top_filelist.py — emit an ordered files.f with a TOP-specific tail.

By default writes:
  ips/prim/prim_reg_pkg.sv
  ips/pkgs/top_pkg.sv
  ips/pkgs/prim_mubi_pkg.sv
  ips/pkgs/prim_secded_pkg.sv
  ips/pkgs/prim_subreg_pkg.sv
  ips/pkgs/tlul_pkg.sv
  rtl/<TOP>_reg_pkg.sv
  rtl/<TOP>_reg_top.sv
  rtl/<TOP>_core.sv
  rtl/<TOP>.sv

Usage:
  python3 gen_top_filelist.py --top spi_host
  python3 gen_top_filelist.py --top spi_host --out files.f
  # Optional: change roots if your tree differs
  python3 gen_top_filelist.py --top spi_host --ips-root ips --rtl-root rtl
  # Skip existence checks:
  python3 gen_top_filelist.py --top spi_host --no-check
"""

import argparse
from pathlib import Path

def main():
    ap = argparse.ArgumentParser(description="Generate files.f with TOP-tail entries.")
    ap.add_argument("--top", required=True, help="Top module base name (e.g. spi_host)")
    ap.add_argument("--out", default="rtl/rtl_list.f", help="Output filename (default: files.f)")
    ap.add_argument("--ips-root", default="ips", help="Root dir for ips (default: ips)")
    ap.add_argument("--rtl-root", default="rtl", help="Root dir for rtl (default: rtl)")
    ap.add_argument("--no-check", action="store_true",
                    help="Do not check for file existence; just write the list.")
    args = ap.parse_args()

    ips = Path(args.ips_root)
    rtl = Path(args.rtl_root)
    top = args.top

    fixed = [
        ips / "pkgs" / "top_pkg.sv",
        ips / "prim" / "prim_reg_pkg.sv",
        ips / "pkgs" / "prim_mubi_pkg.sv",
        ips / "pkgs" / "prim_secded_pkg.sv",
        ips / "pkgs" / "prim_subreg_pkg.sv",
        ips / "pkgs" / "prim_util_pkg.sv",
        ips / "pkgs" / "tlul_pkg.sv",
        ips / "pkgs" / "prim_assert.sv",
        ips / "pkgs" / "prim_count_pkg.sv",
        ips / "pkgs" / "prim_flop_macros.sv",
        ips / "prim" / "prim_bin2gray.sv",
        ips / "prim" / "prim_cdc_2phase.sv",
        ips / "prim" / "prim_clk_div.sv",
        ips / "prim" / "prim_clk_gate.sv",
        ips / "prim" / "prim_counter.sv",
        ips / "prim" / "prim_deglitch.sv",
        ips / "prim" / "prim_edge_detect.sv",
        ips / "prim" / "prim_ff.sv",
        ips / "prim" / "prim_ff_2sync.sv",
        ips / "prim" / "prim_fifo.sv",
        ips / "prim" / "prim_gray2bin.sv",
        ips / "prim" / "prim_lifo.sv",
        ips / "prim" / "prim_lzc.sv",
        ips / "prim" / "prim_ram.sv",
        ips / "prim" / "prim_reg.sv",
        ips / "prim" / "prim_reg_pkg.sv",
        ips / "prim" / "prim_rom.sv",
        ips / "prim" / "prim_rrarbiter.sv",
        ips / "prim" / "prim_shreg.sv",
        ips / "prim_opentitan" / "prim_arbiter_ppc.sv",
        ips / "prim_opentitan" / "prim_cdc_rand_delay.sv",
        ips / "prim_opentitan" / "prim_count.sv",
        ips / "prim_opentitan" / "prim_fifo_async.sv",
        ips / "prim_opentitan" / "prim_fifo_async_simple.sv",
        ips / "prim_opentitan" / "prim_fifo_async_sram_adapter.sv",
        ips / "prim_opentitan" / "prim_fifo_sync.sv",
        ips / "prim_opentitan" / "prim_fifo_sync_cnt.sv",
        ips / "prim_opentitan" / "prim_filter.sv",
        ips / "prim_opentitan" / "prim_filter_ctr.sv",
        ips / "prim_opentitan" / "prim_flop.sv",
        ips / "prim_opentitan" / "prim_flop_2sync.sv",
        ips / "prim_opentitan" / "prim_secded_inv_39_32_dec.sv",
        ips / "prim_opentitan" / "prim_secded_inv_39_32_enc.sv",
        ips / "prim_opentitan" / "prim_secded_inv_64_57_dec.sv",
        ips / "prim_opentitan" / "prim_secded_inv_64_57_enc.sv",
        ips / "prim_opentitan" / "prim_subreg.sv",
        ips / "prim_opentitan" / "prim_subreg_arb.sv",
        ips / "prim_opentitan" / "prim_subreg_ext.sv",
        ips / "prim_opentitan" / "prim_sync_reqack.sv",
        ips / "tlul" / "sram2tlul.sv",
        ips / "tlul" / "tlul_adapter_host.sv",
        ips / "tlul" / "tlul_adapter_reg.sv",
        ips / "tlul" / "tlul_adapter_sram.sv",
        ips / "tlul" / "tlul_assert.sv",
        ips / "tlul" / "tlul_assert_multiple.sv",
        ips / "tlul" / "tlul_cmd_intg_chk.sv",
        ips / "tlul" / "tlul_cmd_intg_gen.sv",
        ips / "tlul" / "tlul_data_integ_dec.sv",
        ips / "tlul" / "tlul_data_integ_enc.sv",
        ips / "tlul" / "tlul_err.sv",
        ips / "tlul" / "tlul_err_resp.sv",
        ips / "tlul" / "tlul_fifo_async.sv",
        ips / "tlul" / "tlul_fifo_sync.sv",
        ips / "tlul" / "tlul_rsp_intg_chk.sv",
        ips / "tlul" / "tlul_rsp_intg_gen.sv",
        ips / "tlul" / "tlul_socket_1n.sv",
        ips / "tlul" / "tlul_socket_m1.sv",
        ips / "tlul" / "tlul_sram_byte.sv",
    ]
    # Build candidates
    dynamic_candidates = [
        rtl / f"{top}_reg_pkg.sv",
        rtl / f"{top}_reg_top.sv",
        rtl / f"{top}_core.sv",
        rtl / f"{top}.sv",
    ]

    # Keep only existing files
    dynamic = [p for p in dynamic_candidates if p.is_file()]

    # (Optional) warn about removed items
    if not args.no_check:
        for p in (p for p in dynamic_candidates if not p.is_file()):
            print(f"Warning: {p.as_posix()} does not exist (removed from list).")

    paths = fixed + dynamic


    # Optionally check that files exist and warn (but still write the list).
    if not args.no_check:
        for p in paths:
            if not p.exists():
                print(f"Warning: {p.as_posix()} does not exist.")

    # Write POSIX-style paths in the requested order.
    out_path = Path(args.out)
    out_path.write_text("\n".join(p.as_posix() for p in paths) + "\n")
    #print(f"Wrote {len(paths)} entries to {out_path.as_posix()}")

if __name__ == "__main__":
    main()

