// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspi_host.h for the primary calling header

#ifndef VERILATED_VSPI_HOST_TLUL_FIFO_SYNC__RCZ6_RDZ6_H_
#define VERILATED_VSPI_HOST_TLUL_FIFO_SYNC__RCZ6_RDZ6_H_  // guard

#include "verilated.h"


class Vspi_host__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vspi_host_tlul_fifo_sync__RCz6_RDz6 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(spare_req_i,0,0);
    VL_OUT8(__PVT__spare_req_o,0,0);
    VL_IN8(spare_rsp_i,0,0);
    VL_OUT8(__PVT__spare_rsp_o,0,0);
    CData/*0:0*/ __Vcellout__reqfifo__rvalid_o;
    CData/*0:0*/ __Vcellout__reqfifo__wready_o;
    CData/*0:0*/ __Vcellout__rspfifo__rvalid_o;
    CData/*0:0*/ __Vcellout__rspfifo__wready_o;
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
    VL_INW(tl_h_i,108,0,4);
    VL_OUTW(tl_h_o,65,0,3);
    VL_OUTW(tl_d_o,108,0,4);
    VL_INW(tl_d_i,65,0,3);
    VlWide<3>/*64:0*/ __Vcellinp__rspfifo__wdata_i;
    VlWide<4>/*107:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage;
    VlWide<3>/*64:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage;

    // INTERNAL VARIABLES
    Vspi_host__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vspi_host_tlul_fifo_sync__RCz6_RDz6(Vspi_host__Syms* symsp, const char* v__name);
    ~Vspi_host_tlul_fifo_sync__RCz6_RDz6();
    VL_UNCOPYABLE(Vspi_host_tlul_fifo_sync__RCz6_RDz6);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
