// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp.h for the primary calling header

#include "Vpwm_ramp__pch.h"
#include "Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6.h"

VL_ATTR_COLD void Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ctor_var_reset(Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6___ctor_var_reset\n"); );
    Vpwm_ramp__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tl_h_i);
    VL_RAND_RESET_W(66, vlSelf->tl_h_o);
    VL_RAND_RESET_W(109, vlSelf->tl_d_o);
    VL_RAND_RESET_W(66, vlSelf->tl_d_i);
    vlSelf->spare_req_i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__spare_req_o = VL_RAND_RESET_I(1);
    vlSelf->spare_rsp_i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__spare_rsp_o = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__reqfifo__rvalid_o = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__reqfifo__wready_o = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__rspfifo__rvalid_o = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->__Vcellinp__rspfifo__wdata_i);
    vlSelf->__Vcellout__rspfifo__wready_o = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(108, vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
}
