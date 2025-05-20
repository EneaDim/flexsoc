// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpwm_ramp_tb.h for the primary calling header

#ifndef VERILATED_VPWM_RAMP_TB_TLUL_FIFO_SYNC__RCZ6_RDZ6_H_
#define VERILATED_VPWM_RAMP_TB_TLUL_FIFO_SYNC__RCZ6_RDZ6_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpwm_ramp_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
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
        CData/*0:0*/ __PVT__reqfifo__DOT__full_o;
        CData/*0:0*/ __PVT__reqfifo__DOT__depth_o;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty;
        CData/*1:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
        CData/*1:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
        CData/*0:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
        CData/*0:0*/ __PVT__rspfifo__DOT__full_o;
        CData/*0:0*/ __PVT__rspfifo__DOT__depth_o;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty;
        CData/*1:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
        CData/*1:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
        CData/*0:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__4__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__4__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__5__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__5__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__7__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__7__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__8__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__8__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__13__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__13__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__14__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__14__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__16__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__16__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__17__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__17__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__22__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__22__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__23__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__23__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__25__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__25__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__26__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__26__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__31__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__31__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__32__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__32__inp;
    };
    struct {
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__34__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__34__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__35__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__35__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__40__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__40__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__41__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__41__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__43__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__43__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__44__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__44__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__49__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__49__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__50__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__50__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__52__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__52__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__53__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__53__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__58__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__58__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__59__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__59__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__61__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__61__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__62__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__62__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__85__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__85__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__86__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__86__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__88__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__88__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__89__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__89__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__94__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__94__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__95__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__95__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__97__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__97__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__98__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__98__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__103__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__103__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__inp;
    };
    struct {
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__106__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__106__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__107__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__107__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__112__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__112__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__115__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__115__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__116__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__116__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__121__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__121__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__124__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__124__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__125__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__125__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__130__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__130__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__131__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__131__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__133__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__133__inp;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__134__Vfuncout;
        CData/*0:0*/ __Vfunc_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__134__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__139__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__139__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__140__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__140__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__142__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__142__inp;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__143__Vfuncout;
        CData/*0:0*/ __Vfunc_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__143__inp;
        VL_INW(tl_h_i,108,0,4);
        VL_OUTW(tl_h_o,65,0,3);
        VL_OUTW(tl_d_o,108,0,4);
        VL_INW(tl_d_i,65,0,3);
        VlWide<3>/*64:0*/ __Vcellinp__rspfifo__wdata_i;
        VlWide<4>/*107:0*/ __PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage;
        VlWide<3>/*64:0*/ __PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage;
    };

    // INTERNAL VARIABLES
    Vpwm_ramp_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6(Vpwm_ramp_tb__Syms* symsp, const char* v__name);
    ~Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6();
    VL_UNCOPYABLE(Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
