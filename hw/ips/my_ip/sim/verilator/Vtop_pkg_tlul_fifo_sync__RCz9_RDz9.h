// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_pkg.h for the primary calling header

#ifndef VERILATED_VTOP_PKG_TLUL_FIFO_SYNC__RCZ9_RDZ9_H_
#define VERILATED_VTOP_PKG_TLUL_FIFO_SYNC__RCZ9_RDZ9_H_  // guard

#include "verilated.h"


class Vtop_pkg__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(spare_req_i,0,0);
    VL_OUT8(__PVT__spare_req_o,0,0);
    VL_IN8(spare_rsp_i,0,0);
    VL_OUT8(__PVT__spare_rsp_o,0,0);
    CData/*0:0*/ __PVT__reqfifo__DOT__wvalid_i;
    CData/*0:0*/ __PVT__reqfifo__DOT__wready_o;
    CData/*0:0*/ __PVT__reqfifo__DOT__rvalid_o;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty;
    CData/*1:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    CData/*1:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    CData/*1:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    CData/*1:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
    CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
    CData/*0:0*/ __PVT__rspfifo__DOT__wvalid_i;
    CData/*0:0*/ __PVT__rspfifo__DOT__wready_o;
    CData/*0:0*/ __PVT__rspfifo__DOT__rvalid_o;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty;
    CData/*1:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    CData/*1:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    CData/*1:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    CData/*1:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
    CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
    VlWide<4>/*107:0*/ __Vcellinp__reqfifo__wdata_i;
    VlWide<3>/*64:0*/ __Vcellinp__rspfifo__wdata_i;
    VlWide<4>/*107:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage;
    VlWide<3>/*64:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage;
    VL_INW(tl_h_i,108,0,4);
    VL_OUTW(tl_h_o,65,0,3);
    VL_OUTW(tl_d_o,108,0,4);
    VL_INW(tl_d_i,65,0,3);

    // INTERNAL VARIABLES
    Vtop_pkg__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9() = default;
    ~Vtop_pkg_tlul_fifo_sync__RCz9_RDz9() = default;
    void ctor(Vtop_pkg__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
