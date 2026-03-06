// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vip1_tb.h for the primary calling header

#ifndef VERILATED_VIP1_TB_IP1_TB_H_
#define VERILATED_VIP1_TB_IP1_TB_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vip1_tb___024unit__03a__03atlul_utils;
class Vip1_tb_tlul_if;


class Vip1_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vip1_tb_ip1_tb final {
  public:
    // CELLS
    Vip1_tb_tlul_if* tl_if;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__clk_i;
    CData/*0:0*/ __PVT__rst_ni;
    CData/*0:0*/ __PVT__port_i;
    CData/*0:0*/ __PVT__port_o;
    CData/*0:0*/ u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_en__q;
    CData/*0:0*/ u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_rst__q;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__wdata_qe;
    CData/*7:0*/ u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_wdata__q;
    CData/*3:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__addr_hit;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__we_o;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__outstanding_q;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__a_ack;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__d_ack;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_q;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__err_internal;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__instr_error;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__malformed_meta_err;
    CData/*7:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqid_q;
    CData/*1:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqsz_q;
    CData/*2:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rspop_q;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rd_req;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__wr_req;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_wdata0_qe__DOT__d_i;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_core__DOT__status_full;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_core__DOT__status_empty;
    CData/*7:0*/ __PVT__u_ip1__DOT__u_ip1_core__DOT__rdata;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_core__DOT__u_sync_name__DOT__d_o;
    CData/*0:0*/ __PVT__u_ip1__DOT__u_ip1_core__DOT__u_sync_name__DOT__intq;
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__3__Vfuncout;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__3__val;
    CData/*0:0*/ __Vfunc_mubi4_test_true_strict__4__Vfuncout;
    CData/*3:0*/ __Vfunc_mubi4_test_true_strict__4__val;
    CData/*0:0*/ __Vfunc_mubi4_test_true_strict__8__Vfuncout;
    CData/*3:0*/ __Vfunc_mubi4_test_true_strict__8__val;
    SData/*15:0*/ u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_setting__q;
    IData/*31:0*/ __PVT__error_count;
    IData/*31:0*/ __PVT__rdata;
    IData/*31:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__reg_rdata_next;
    IData/*31:0*/ __PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rdata_q;
    VlWide<4>/*108:0*/ __PVT__tl_i;
    VlWide<3>/*65:0*/ __PVT__tl_o;

    // INTERNAL VARIABLES
    Vip1_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vip1_tb_ip1_tb() = default;
    ~Vip1_tb_ip1_tb() = default;
    void ctor(Vip1_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vip1_tb_ip1_tb);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
