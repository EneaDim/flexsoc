// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop_pkg___024root___eval_triggers__ico(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_triggers__ico\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_pkg___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop_pkg___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*2:0*/, 512> Vtop_pkg__ConstPool__TABLE_ha29f17c5_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vtop_pkg__ConstPool__TABLE_h15830d43_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vtop_pkg__ConstPool__TABLE_hc6902e0f_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vtop_pkg__ConstPool__TABLE_he2f1360b_0;
extern const VlUnpacked<CData/*0:0*/, 512> Vtop_pkg__ConstPool__TABLE_ha6f04773_0;
extern const VlUnpacked<SData/*12:0*/, 32> Vtop_pkg__ConstPool__TABLE_hdd797092_0;

void Vtop_pkg___024root___ico_sequent__TOP__0(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___ico_sequent__TOP__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ rrarbiter__DOT__next_idx;
    rrarbiter__DOT__next_idx = 0;
    CData/*0:0*/ rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__;
    rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__ = 0;
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake = 0;
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake = 0;
    CData/*0:0*/ prim_alert_sender__DOT__alert_trigger;
    prim_alert_sender__DOT__alert_trigger = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__instr_error;
    tlul_adapter_sram__DOT__instr_error = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_valid;
    tlul_adapter_sram__DOT__d_valid = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_error;
    tlul_adapter_sram__DOT__d_error = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__vld_rd_rsp;
    tlul_adapter_sram__DOT__vld_rd_rsp = 0;
    QData/*39:0*/ tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o;
    tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err;
    tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__instr_type_err;
    tlul_adapter_sram__DOT__u_err__DOT__instr_type_err = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk;
    tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__mask_chk;
    tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk;
    tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i;
    tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i = 0;
    VlWide<4>/*108:0*/ tlul_socket_1n__DOT__tl_t_o;
    VL_ZERO_W(109, tlul_socket_1n__DOT__tl_t_o);
    CData/*0:0*/ my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7;
    my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 = 0;
    CData/*0:0*/ my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o;
    my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_0;
    __VdfgRegularize_he50b618e_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_1;
    __VdfgRegularize_he50b618e_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_2;
    __VdfgRegularize_he50b618e_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_3;
    __VdfgRegularize_he50b618e_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_5;
    __VdfgRegularize_he50b618e_0_5 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_6;
    __VdfgRegularize_he50b618e_0_6 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_7;
    __VdfgRegularize_he50b618e_0_7 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_9;
    __VdfgRegularize_he50b618e_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_10;
    __VdfgRegularize_he50b618e_0_10 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_11;
    __VdfgRegularize_he50b618e_0_11 = 0;
    VlWide<4>/*107:0*/ __VdfgRegularize_he50b618e_0_27;
    VL_ZERO_W(108, __VdfgRegularize_he50b618e_0_27);
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__9__Vfuncout;
    __Vfunc_mubi4_test_invalid__9__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__9__val;
    __Vfunc_mubi4_test_invalid__9__val = 0;
    QData/*56:0*/ __Vfunc_get_cmd_intg__19__unused_cmd_payload;
    __Vfunc_get_cmd_intg__19__unused_cmd_payload = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    // Body
    if ((0x00001000U & vlSelfRef.my_ip__02Etl_i[3U])) {
        if ((1U & (~ VL_ONEHOT_I((((2U == (3U & (vlSelfRef.my_ip__02Etl_i[3U] 
                                                 >> 4U))) 
                                   << 2U) | (((1U == 
                                               (3U 
                                                & (vlSelfRef.my_ip__02Etl_i[3U] 
                                                   >> 4U))) 
                                              << 1U) 
                                             | (0U 
                                                == 
                                                (3U 
                                                 & (vlSelfRef.my_ip__02Etl_i[3U] 
                                                    >> 4U))))))))) {
            if ((0U != (((2U == (3U & (vlSelfRef.my_ip__02Etl_i[3U] 
                                       >> 4U))) << 2U) 
                        | (((1U == (3U & (vlSelfRef.my_ip__02Etl_i[3U] 
                                          >> 4U))) 
                            << 1U) | (0U == (3U & (
                                                   vlSelfRef.my_ip__02Etl_i[3U] 
                                                   >> 4U))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: tlul_err.sv:62: Assertion failed in %Nmy_ip.u_my_ip_reg.u_reg_if.u_err: unique case, but multiple matches found for '32'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -12,vlSymsp->name(),
                                 32,(3U & (vlSelfRef.my_ip__02Etl_i[3U] 
                                           >> 4U)));
                    VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv", 62, "");
                }
            }
        }
    }
    vlSelfRef.w_sram_wdata_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i;
    vlSelfRef.mem_rvalid_o = ((vlSelfRef.sram2tlul__02Etl_i[2U] 
                               >> 1U) & (1U == (7U 
                                                & ((vlSelfRef.sram2tlul__02Etl_i[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.sram2tlul__02Etl_i[1U] 
                                                      >> 0x0000001eU)))));
    vlSelfRef.mem_rdata_o = ((vlSelfRef.sram2tlul__02Etl_i[1U] 
                              << 0x00000010U) | (vlSelfRef.sram2tlul__02Etl_i[0U] 
                                                 >> 0x00000010U));
    vlSelfRef.mem_error_o = (3U & (- (IData)((1U & 
                                              (vlSelfRef.sram2tlul__02Etl_i[0U] 
                                               >> 1U)))));
    vlSelfRef.valid_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                               >> 1U));
    vlSelfRef.tlul_adapter_host__02Erdata_o = ((vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                << 0x00000010U) 
                                               | (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                                  >> 0x00000010U));
    vlSelfRef.rdata_intg_o = (0x0000007fU & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                             >> 2U));
    vlSelfRef.tlul_adapter_host__02Eerr_o = (1U & (
                                                   vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                                   >> 1U));
    vlSelfRef.req_type_o = (0x0000000fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                           >> 0x0000000fU));
    vlSelfRef.prim_lifo__DOT__wr_en = ((IData)(vlSelfRef.prim_lifo__02Ewready_o) 
                                       & (IData)(vlSelfRef.prim_lifo__02Ewvalid_i));
    vlSelfRef.prim_lifo__DOT__rd_en = ((IData)(vlSelfRef.prim_lifo__02Erready_i) 
                                       & (IData)(vlSelfRef.prim_lifo__02Ervalid_o));
    vlSelfRef.tc_o = ((IData)(vlSelfRef.tc_val_i) == (IData)(vlSelfRef.val_o));
    vlSelfRef.r_edge_o = ((~ (IData)(vlSelfRef.prim_edge_detect__DOT__serial_q)) 
                          & (IData)(vlSelfRef.prim_edge_detect__02Eserial_i));
    vlSelfRef.f_edge_o = ((~ (IData)(vlSelfRef.prim_edge_detect__02Eserial_i)) 
                          & (IData)(vlSelfRef.prim_edge_detect__DOT__serial_q));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0x0000000eU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_reg_cdc__DOT__src_req = ((IData)(vlSelfRef.src_re_i) 
                                            | (IData)(vlSelfRef.src_we_i));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0x0000000cU));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
           & vlSelfRef.my_ip__02Etl_i[0U]);
    vlSelfRef.prim_clk_div__02Eclk_o = ((IData)(vlSelfRef.testmode_i)
                                         ? (IData)(vlSelfRef.prim_clk_div__02Eclk_i)
                                         : (IData)(vlSelfRef.prim_clk_div__DOT__clk_q));
    vlSelfRef.prim_filter__02Efilter_o = ((IData)(vlSelfRef.prim_filter__02Eenable_i)
                                           ? (IData)(vlSelfRef.prim_filter__DOT__stored_value_q)
                                           : (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_filter_ctr__02Efilter_o = ((IData)(vlSelfRef.prim_filter_ctr__02Eenable_i)
                                               ? (IData)(vlSelfRef.prim_filter_ctr__DOT__stored_value_q)
                                               : (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
    vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d = (((IData)(vlSelfRef.prim_filter_ctr__02Efilter_i) 
                                                   == (IData)(vlSelfRef.prim_filter_ctr__DOT__filter_q))
                                                   ? 
                                                  (3U 
                                                   & (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q) 
                                                       >= (IData)(vlSelfRef.thresh_i))
                                                       ? (IData)(vlSelfRef.thresh_i)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q))))
                                                   : 0U);
    vlSelfRef.sram2tlul__02Etl_o[0U] = (IData)((0x0f00000000000001ULL 
                                                | ((QData)((IData)(vlSelfRef.mem_wdata_i)) 
                                                   << 0x00000018U)));
    vlSelfRef.sram2tlul__02Etl_o[1U] = (((IData)(vlSelfRef.mem_addr_i) 
                                         << 0x0000001eU) 
                                        | (IData)((
                                                   (0x0f00000000000001ULL 
                                                    | ((QData)((IData)(vlSelfRef.mem_wdata_i)) 
                                                       << 0x00000018U)) 
                                                   >> 0x00000020U)));
    vlSelfRef.sram2tlul__02Etl_o[2U] = ((0xfffffc00U 
                                         & vlSelfRef.sram2tlul__02Etl_o[2U]) 
                                        | ((IData)(vlSelfRef.mem_addr_i) 
                                           >> 2U));
    vlSelfRef.sram2tlul__02Etl_o[2U] = ((0x000003ffU 
                                         & vlSelfRef.sram2tlul__02Etl_o[2U]) 
                                        | ((IData)(
                                                   (0x0000000008000000ULL 
                                                    | (((QData)((IData)(vlSelfRef.mem_req_i)) 
                                                        << 0x00000022U) 
                                                       | ((QData)((IData)(
                                                                          ((IData)(vlSelfRef.mem_write_i)
                                                                            ? 0U
                                                                            : 4U))) 
                                                          << 0x0000001fU)))) 
                                           << 0x0000000aU));
    vlSelfRef.sram2tlul__02Etl_o[3U] = (0x00001fffU 
                                        & (((IData)(
                                                    (0x0000000008000000ULL 
                                                     | (((QData)((IData)(vlSelfRef.mem_req_i)) 
                                                         << 0x00000022U) 
                                                        | ((QData)((IData)(
                                                                           ((IData)(vlSelfRef.mem_write_i)
                                                                             ? 0U
                                                                             : 4U))) 
                                                           << 0x0000001fU)))) 
                                            >> 0x00000016U) 
                                           | ((IData)(
                                                      ((0x0000000008000000ULL 
                                                        | (((QData)((IData)(vlSelfRef.mem_req_i)) 
                                                            << 0x00000022U) 
                                                           | ((QData)((IData)(
                                                                              ((IData)(vlSelfRef.mem_write_i)
                                                                                ? 0U
                                                                                : 4U))) 
                                                              << 0x0000001fU))) 
                                                       >> 0x00000020U)) 
                                              << 0x0000000aU)));
    vlSelfRef.prim_counter__DOT__count_d = ((IData)(vlSelfRef.clr_i)
                                             ? 0U : 
                                            (0x0000001fU 
                                             & ((IData)(vlSelfRef.prim_counter__02Een_i)
                                                 ? 
                                                (((~ (IData)(vlSelfRef.up_down_i)) 
                                                  & ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                     >> 4U))
                                                  ? 0U
                                                  : 
                                                 (((IData)(vlSelfRef.up_down_i) 
                                                   & ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                      >> 4U))
                                                   ? 0x0fU
                                                   : 
                                                  ((IData)(vlSelfRef.up_down_i)
                                                    ? 
                                                   ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                    + (IData)(vlSelfRef.step_i))
                                                    : 
                                                   ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                    - (IData)(vlSelfRef.step_i)))))
                                                 : (IData)(vlSelfRef.prim_counter__DOT__count_q))));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.gnt_o = (1U & vlSelfRef.tlul_adapter_host__02Etl_i[0U]);
    if ((1U & (~ (IData)(vlSelfRef.prim_clk_gate__02Eclk_i)))) {
        vlSelfRef.prim_clk_gate__DOT__en_latch = ((IData)(vlSelfRef.prim_clk_gate__02Een_i) 
                                                  | (IData)(vlSelfRef.test_en_i));
    }
    vlSelfRef.hw2reg_intr_state_de_o = (((IData)(vlSelfRef.reg2hw_intr_test_q_i) 
                                         & (IData)(vlSelfRef.reg2hw_intr_test_qe_i)) 
                                        | (IData)(vlSelfRef.event_intr_i));
    vlSelfRef.qe = ((IData)(vlSelfRef.de) | (IData)(vlSelfRef.we));
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d 
        = ((IData)(vlSelfRef.r_sram_rvalid_i) ? vlSelfRef.r_sram_rdata_i
            : 0U);
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.prim_reg__DOT__wr_data = ((IData)(vlSelfRef.we)
                                         ? vlSelfRef.wd
                                         : vlSelfRef.d);
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelfRef.tlul_adapter_host__02Ewe_i)
                                                                           ? (IData)(vlSelfRef.be_i)
                                                                           : 0x0fU))) 
                                                         << 0x00000038U) 
                                                        | (((QData)((IData)(vlSelfRef.tlul_adapter_host__02Ewdata_i)) 
                                                            << 0x00000018U) 
                                                           | (QData)((IData)(
                                                                             (1U 
                                                                              | (((IData)(vlSelfRef.instr_type_i) 
                                                                                << 0x0000000fU) 
                                                                                | ((IData)(vlSelfRef.wdata_intg_i) 
                                                                                << 1U))))))));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0xc0000000U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelfRef.tlul_adapter_host__02Ewe_i)
                                                                               ? (IData)(vlSelfRef.be_i)
                                                                               : 0x0fU))) 
                                                             << 0x00000038U) 
                                                            | (((QData)((IData)(vlSelfRef.tlul_adapter_host__02Ewdata_i)) 
                                                                << 0x00000018U) 
                                                               | (QData)((IData)(
                                                                                (1U 
                                                                                | (((IData)(vlSelfRef.instr_type_i) 
                                                                                << 0x0000000fU) 
                                                                                | ((IData)(vlSelfRef.wdata_intg_i) 
                                                                                << 1U))))))) 
                                                           >> 0x00000020U)));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0x3fffffffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | ((IData)(
                                                           (0x0000008000000000ULL 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                                << 0x0000001eU) 
                                                                               | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U)))))) 
                                                   << 0x0000001eU));
    vlSelfRef.tlul_adapter_host__02Etl_o[2U] = (((IData)(
                                                         (0x0000008000000000ULL 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                              << 0x0000001eU) 
                                                                             | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U)))))) 
                                                 >> 2U) 
                                                | ((IData)(
                                                           ((0x0000008000000000ULL 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                                << 0x0000001eU) 
                                                                                | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U))))) 
                                                            >> 0x00000020U)) 
                                                   << 0x0000001eU));
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = ((0x00001e00U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[3U]) 
                                                | (0x00001fffU 
                                                   & ((IData)(
                                                              ((0x0000008000000000ULL 
                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                                << 0x0000001eU) 
                                                                                | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U))))) 
                                                               >> 0x00000020U)) 
                                                      >> 2U)));
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = ((0x000001ffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[3U]) 
                                                | (0x00001e00U 
                                                   & (((IData)(vlSelfRef.tlul_adapter_host__02Ereq_i) 
                                                       << 0x0000000cU) 
                                                      | (((IData)(vlSelfRef.tlul_adapter_host__02Ewe_i)
                                                           ? 
                                                          ((0x0000000fU 
                                                            == (IData)(vlSelfRef.be_i))
                                                            ? 0U
                                                            : 1U)
                                                           : 4U) 
                                                         << 9U))));
    vlSelfRef.vld_o = ((0U != (IData)(vlSelfRef.rrarbiter__02Ereq_i)) 
                       & (IData)(vlSelfRef.rrarbiter__02Een_i));
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    vlSelfRef.we_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                       >> 0x0000000cU) & ((0U == (7U 
                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                     >> 9U))) 
                                          | (1U == 
                                             (7U & 
                                              (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                               >> 9U)))));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0 
        = (((IData)(vlSelfRef.gnt_i) | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
           & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit 
        = ((((3U == (vlSelfRef.my_ip__02Etl_i[1U] >> 0x0000001eU)) 
             << 3U) | ((2U == (vlSelfRef.my_ip__02Etl_i[1U] 
                               >> 0x0000001eU)) << 2U)) 
           | (((1U == (vlSelfRef.my_ip__02Etl_i[1U] 
                       >> 0x0000001eU)) << 1U) | (0U 
                                                  == 
                                                  (vlSelfRef.my_ip__02Etl_i[1U] 
                                                   >> 0x0000001eU))));
    if ((0x00001000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        vlSelfRef.addr_o = (0x00000fffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                            << 2U) 
                                           | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                              >> 0x0000001eU)));
        vlSelfRef.wmask_o = ((((0x0000ff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                              >> 0x0000001bU)))) 
                                               << 8U)) 
                               | (0x000000ffU & (- (IData)(
                                                           (1U 
                                                            & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                               >> 0x0000001aU)))))) 
                              << 0x00000010U) | ((0x0000ff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                    >> 0x00000019U)))) 
                                                     << 8U)) 
                                                 | (0x000000ffU 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                     >> 0x00000018U)))))));
    } else {
        vlSelfRef.addr_o = 0U;
        vlSelfRef.wmask_o = 0U;
    }
    tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_true_strict__8__val 
                    = (0x0000000fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_true_strict__8__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__8__val));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__8__Vfuncout)) 
           & ((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U)))));
    __Vfunc_mubi4_test_invalid__9__val = (0x0000000fU 
                                          & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                             >> 0x0000000fU));
    __Vfunc_mubi4_test_invalid__9__Vfuncout = (1U & 
                                               (~ (
                                                   (6U 
                                                    == (IData)(__Vfunc_mubi4_test_invalid__9__val)) 
                                                   | (9U 
                                                      == (IData)(__Vfunc_mubi4_test_invalid__9__val)))));
    tlul_adapter_sram__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_mubi4_test_invalid__9__Vfuncout;
    __VdfgRegularize_he50b618e_0_11 = (1U & ((~ (IData)(vlSelfRef.rrarbiter__DOT__mask)) 
                                             & (IData)(vlSelfRef.rrarbiter__02Ereq_i)));
    __VdfgRegularize_he50b618e_0_7 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 4U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 4U)));
    __VdfgRegularize_he50b618e_0_3 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 8U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 8U)));
    __VdfgRegularize_he50b618e_0_1 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 0x0000000aU)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 0x0000000aU)));
    rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__ 
        = (IData)(((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                       >> 0x0000000cU)) & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                           >> 0x0000000cU)));
    __VdfgRegularize_he50b618e_0_0 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 0x0000000bU)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 0x0000000bU)));
    __VdfgRegularize_he50b618e_0_2 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 9U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 9U)));
    vlSelfRef.prim_alert_sender__DOT__alert_req_trigger 
        = ((IData)(vlSelfRef.alert_req_i) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_set_q));
    vlSelfRef.prim_alert_sender__DOT__alert_test_trigger 
        = ((IData)(vlSelfRef.alert_test_i) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_set_q));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellinp__u_rspfifo__wdata_i 
        = (((QData)((IData)((vlSelfRef.rdata_i & ((
                                                   ((0x0000ff00U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                       >> 4U)))) 
                                                        << 8U)) 
                                                    | (0x000000ffU 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                        >> 3U)))))) 
                                                   << 0x00000010U) 
                                                  | ((0x0000ff00U 
                                                      & ((- (IData)(
                                                                    (1U 
                                                                     & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                        >> 2U)))) 
                                                         << 8U)) 
                                                     | (0x000000ffU 
                                                        & (- (IData)(
                                                                     (1U 
                                                                      & ((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o) 
                                                                         >> 1U)))))))))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    tlul_adapter_sram__DOT__instr_error = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_invalid__4__val 
                    = (0x0000000fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                      >> 0x0000000fU));
                vlSelfRef.__Vfunc_mubi4_test_invalid__4__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__4__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__4__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_invalid__4__Vfuncout)) 
                                           | (([&]() {
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__5__val 
                        = (0x0000000fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                          >> 0x0000000fU));
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__5__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__5__val));
                }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__5__Vfuncout)) 
                                              & ([&]() {
                    vlSelfRef.__Vfunc_mubi4_test_false_loose__6__val 
                        = vlSelfRef.en_ifetch_i;
                    vlSelfRef.__Vfunc_mubi4_test_false_loose__6__Vfuncout 
                        = (6U != (IData)(vlSelfRef.__Vfunc_mubi4_test_false_loose__6__val));
                }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_false_loose__6__Vfuncout))));
    __VdfgRegularize_he50b618e_0_10 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                 >> 1U)) 
                                             & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                                >> 1U)));
    __VdfgRegularize_he50b618e_0_9 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 2U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 2U)));
    __VdfgRegularize_he50b618e_0_6 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 5U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 5U)));
    __VdfgRegularize_he50b618e_0_5 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 6U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 6U)));
    tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = 0U;
    tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 0U;
    tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk = 0U;
    if ((0x00001000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        if ((0U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                          >> 4U)))) {
            tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = 1U;
            tlul_adapter_sram__DOT__u_err__DOT__mask_chk 
                = (1U & (~ (0U != (0x0000000fU & ((
                                                   (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                    << 8U) 
                                                   | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x00000018U)) 
                                                  & (~ 
                                                     ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                          >> 0x0000001cU)))))))));
            tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk 
                = (0U != (0x0000000fU & (((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                           << 8U) | 
                                          (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                           >> 0x00000018U)) 
                                         & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                   >> 0x0000001cU))))));
        } else if ((1U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                 >> 4U)))) {
            tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                            >> 0x0000001cU)));
            if ((0x20000000U & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])) {
                tlul_adapter_sram__DOT__u_err__DOT__mask_chk 
                    = (1U & (~ (0U != (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                             >> 0x00000018U)))));
                tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk 
                    = (3U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                    >> 0x0000001aU)));
            } else {
                tlul_adapter_sram__DOT__u_err__DOT__mask_chk 
                    = (1U & (~ (0U != (0x0cU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                >> 0x00000018U)))));
                tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk 
                    = (3U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                    >> 0x00000018U)));
            }
        } else if ((2U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                 >> 4U)))) {
            tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk 
                = (1U & (~ (0U != (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                         >> 0x0000001cU)))));
            tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 1U;
            tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk 
                = (0x0000000fU == (0x0000000fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                  >> 0x00000018U)));
        } else {
            tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = 0U;
            tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 0U;
            tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk = 0U;
        }
        if ((1U & (~ VL_ONEHOT_I((((2U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                 >> 4U))) 
                                   << 2U) | (((1U == 
                                               (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U))) 
                                              << 1U) 
                                             | (0U 
                                                == 
                                                (3U 
                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                    >> 4U))))))))) {
            if ((0U != (((2U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                       >> 4U))) << 2U) 
                        | (((1U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 4U))) 
                            << 1U) | (0U == (3U & (
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: tlul_err.sv:62: Assertion failed in %Ntlul_adapter_sram.u_err: unique case, but multiple matches found for '32'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1),
                                 -12,vlSymsp->name(),
                                 32,(3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                           >> 4U)));
                    VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/tlul/tlul_err.sv", 62, "");
                }
            }
        }
    } else {
        tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = 0U;
        tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 0U;
        tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk = 0U;
    }
    vlSelfRef.wdata_o = ((0x00001000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])
                          ? ((((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                  >> 0x0000001bU) & (IData)(vlSelfRef.we_o))
                                 ? (0x000000ffU & (
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                   >> 0x00000010U))
                                 : 0U) << 0x00000018U) 
                              | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                    >> 0x0000001aU) 
                                   & (IData)(vlSelfRef.we_o))
                                   ? (0x000000ffU & 
                                      (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                       >> 8U)) : 0U) 
                                 << 0x00000010U)) | 
                             (((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                  >> 0x00000019U) & (IData)(vlSelfRef.we_o))
                                 ? (0x000000ffU & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                                 : 0U) << 8U) | (((
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                   >> 0x00000018U) 
                                                  & (IData)(vlSelfRef.we_o))
                                                  ? 
                                                 (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                                  >> 0x00000018U)
                                                  : 0U)))
                          : 0U);
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)) 
           & (vlSelfRef.my_ip__02Etl_i[3U] >> 0x0000000cU));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
           & (IData)(vlSelfRef.rvalid_i));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (0x0000fffeU & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                                        >> 0x0000001eU))))
                ? ((vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                    << 0x00000010U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[0U] 
                                       >> 0x00000010U))
                : 0U) << 0x00000010U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                                        >> 0x0000001eU))))
                ? ((vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                    << 0x00000010U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[0U] 
                                       >> 0x00000010U))
                : 0U) >> 0x00000010U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & vlSelfRef.tlul_socket_m1__02Etl_d_i[1U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & vlSelfRef.tlul_socket_m1__02Etl_d_i[2U]);
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U] 
        = ((0xfffffff8U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[0U] 
                           << 2U)) | (IData)(vlSelfRef.dev_select_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[0U] 
                              >> 0x0000001eU)) | (0xfffffff8U 
                                                  & (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                                                     << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                              >> 0x0000001eU)) | (0xfffffff8U 
                                                  & (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                                                     << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                              >> 0x0000001eU)) | (0x00003ff8U 
                                                  & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                                                     << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0x0000000cU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = (1U & (((IData)(vlSelfRef.gnt_o) & (IData)(vlSelfRef.tlul_adapter_host__02Ereq_i))
                  ? ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)))
                  : (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)));
    vlSelfRef.prim_clk_gate__02Eclk_o = ((IData)(vlSelfRef.prim_clk_gate__02Eclk_i) 
                                         & (IData)(vlSelfRef.prim_clk_gate__DOT__en_latch));
    vlSelfRef.hw2reg_intr_state_d_o = ((IData)(vlSelfRef.hw2reg_intr_state_de_o) 
                                       | (IData)(vlSelfRef.reg2hw_intr_state_q_i));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.ds = ((IData)(vlSelfRef.qe) ? vlSelfRef.prim_reg__DOT__wr_data
                     : vlSelfRef.q);
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
             >> 0x0000000cU) & (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o)));
    vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
            ? vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q
            : vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d);
    if ((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))))) {
        if ((0U != (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: my_ip_reg_top.sv:319: Assertion failed in %Nmy_ip.u_my_ip_reg: unique case, but multiple matches found for '1'h1'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("/home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/rtl/my_ip_reg_top.sv", 319, "");
            }
        }
    }
    vlSelfRef.r_sram_req_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
                               ? ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1) 
                                  & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))
                               : ((~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                      ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
                                  & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) {
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((0xfffffffcU & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q) 
                   << 1U) | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q)));
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((0x0000ffffU & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q) 
                  << 0x00000010U));
    } else {
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((2U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                ? ((0xfffffffcU & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__status_empty) 
                       << 1U) | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__status_full)))
                : ((4U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                    ? ((0xffffff00U & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
                       | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__rdata))
                    : ((8U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                        ? (0xffffff00U & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next)
                        : 0xffffffffU)));
    }
    prim_alert_sender__DOT__alert_trigger = ((IData)(vlSelfRef.prim_alert_sender__DOT__alert_req_trigger) 
                                             | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_trigger));
    __VdfgRegularize_h6e95ff9d_0_2 = (1U & ((IData)(__VdfgRegularize_he50b618e_0_10) 
                                            | ((IData)(__VdfgRegularize_he50b618e_0_9) 
                                               | ((~ 
                                                   ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                    >> 3U)) 
                                                  & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                                     >> 3U)))));
    __VdfgRegularize_h6e95ff9d_0_1 = (1U & ((IData)(__VdfgRegularize_he50b618e_0_6) 
                                            | ((IData)(__VdfgRegularize_he50b618e_0_5) 
                                               | ((~ 
                                                   ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                    >> 7U)) 
                                                  & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                                     >> 7U)))));
    vlSelfRef.tlul_adapter_sram__DOT__error_det = (1U 
                                                   & ((IData)(tlul_adapter_sram__DOT__instr_error) 
                                                      | ((~ 
                                                          (((0U 
                                                             == 
                                                             (7U 
                                                              & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                 >> 9U))) 
                                                            | ((1U 
                                                                == 
                                                                (7U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                    >> 9U))) 
                                                               | (4U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                      >> 9U))))) 
                                                           & ((IData)(tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                                                              & ((IData)(tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
                                                                 & ((4U 
                                                                     == 
                                                                     (7U 
                                                                      & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                         >> 9U))) 
                                                                    | ((1U 
                                                                        == 
                                                                        (7U 
                                                                         & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                            >> 9U))) 
                                                                       | (IData)(tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk))))))) 
                                                         | ((IData)(tlul_adapter_sram__DOT__u_err__DOT__instr_type_err) 
                                                            | (IData)(tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err)))));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.my_ip__02Etl_i[3U])));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.my_ip__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.my_ip__02Etl_i[3U] 
                                                >> 9U)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 != (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                   >> 1U))) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   >> 0x0000000cU))) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    } else {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        }
    }
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    __Vtableidx2 = (((((IData)(vlSelfRef.prim_alert_sender__DOT__ack_sigint) 
                       | (IData)(vlSelfRef.prim_alert_sender__DOT__ping_sigint)) 
                      << 8U) | ((((IData)(prim_alert_sender__DOT__alert_trigger)
                                   ? 1U : 3U) << 5U) 
                                | (((IData)(prim_alert_sender__DOT__alert_trigger) 
                                    | (IData)(vlSelfRef.prim_alert_sender__DOT__ping_trigger)) 
                                   << 4U))) | (((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d) 
                                                << 3U) 
                                               | (IData)(vlSelfRef.prim_alert_sender__DOT__state_q)));
    vlSelfRef.prim_alert_sender__DOT__state_d = Vtop_pkg__ConstPool__TABLE_ha29f17c5_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__alert_pd = Vtop_pkg__ConstPool__TABLE_h15830d43_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__alert_nd = Vtop_pkg__ConstPool__TABLE_hc6902e0f_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__ping_clr = Vtop_pkg__ConstPool__TABLE_he2f1360b_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__alert_clr = Vtop_pkg__ConstPool__TABLE_ha6f04773_0
        [__Vtableidx2];
    rrarbiter__DOT__next_idx = ((((IData)(__VdfgRegularize_he50b618e_0_11) 
                                  | (IData)(__VdfgRegularize_h6e95ff9d_0_2)) 
                                 | (((IData)(__VdfgRegularize_he50b618e_0_7) 
                                     | (IData)(__VdfgRegularize_h6e95ff9d_0_1)) 
                                    | (((IData)(__VdfgRegularize_he50b618e_0_3) 
                                        | (IData)(__VdfgRegularize_he50b618e_0_2)) 
                                       | (((IData)(__VdfgRegularize_he50b618e_0_1) 
                                           | (IData)(__VdfgRegularize_he50b618e_0_0)) 
                                          | (IData)(rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__)))))
                                 ? ((IData)(__VdfgRegularize_he50b618e_0_11)
                                     ? 0U : ((IData)(__VdfgRegularize_h6e95ff9d_0_2)
                                              ? ((IData)(__VdfgRegularize_he50b618e_0_10)
                                                  ? 1U
                                                  : 
                                                 ((IData)(__VdfgRegularize_he50b618e_0_9)
                                                   ? 2U
                                                   : 3U))
                                              : ((IData)(__VdfgRegularize_he50b618e_0_7)
                                                  ? 4U
                                                  : 
                                                 ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                                   ? 
                                                  ((IData)(__VdfgRegularize_he50b618e_0_6)
                                                    ? 5U
                                                    : 
                                                   ((IData)(__VdfgRegularize_he50b618e_0_5)
                                                     ? 6U
                                                     : 7U))
                                                   : 
                                                  ((IData)(__VdfgRegularize_he50b618e_0_3)
                                                    ? 8U
                                                    : 
                                                   ((IData)(__VdfgRegularize_he50b618e_0_2)
                                                     ? 9U
                                                     : 
                                                    ((IData)(__VdfgRegularize_he50b618e_0_1)
                                                      ? 0x0aU
                                                      : 
                                                     ((IData)(__VdfgRegularize_he50b618e_0_0)
                                                       ? 0x0bU
                                                       : 
                                                      ((IData)(rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__)
                                                        ? 0x0cU
                                                        : 0U)))))))))
                                 : ((1U & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                           & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                     ? 0U : ((2U & 
                                              ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                               & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                              ? 1U : 
                                             ((4U & 
                                               ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                               ? 2U
                                               : ((8U 
                                                   & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                      & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                   ? 3U
                                                   : 
                                                  ((0x00000010U 
                                                    & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                       & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                    ? 4U
                                                    : 
                                                   ((0x00000020U 
                                                     & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                        & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                     ? 5U
                                                     : 
                                                    ((0x00000040U 
                                                      & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                         & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                      ? 6U
                                                      : 
                                                     ((0x00000080U 
                                                       & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                          & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                       ? 7U
                                                       : 
                                                      ((0x00000100U 
                                                        & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                           & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                        ? 8U
                                                        : 
                                                       ((0x00000200U 
                                                         & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                            & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                         ? 9U
                                                         : 
                                                        ((0x00000400U 
                                                          & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                             & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                          ? 0x0aU
                                                          : 
                                                         ((0x00000800U 
                                                           & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                              & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                           ? 0x0bU
                                                           : 
                                                          ((0x00001000U 
                                                            & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                               & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                            ? 0x0cU
                                                            : 0U))))))))))))));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0x0000000cU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.my_ip__02Etl_i[1U] 
                           >> 0x0000001cU))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)
            ? 0ULL : (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                       & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i))
                       ? vlSelfRef.tlul_adapter_sram__DOT____Vcellinp__u_rspfifo__wdata_i
                       : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                  & (IData)(((0x00060000U == (0x00060000U 
                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                             & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                 | (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                     & (IData)(((0x00040000U == (0x00060000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                    | (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                        & (IData)(((0x00020000U == 
                                    (0x00060000U & 
                                     vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                   & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                       | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o) 
                          & (IData)(((0U == (0x00060000U 
                                             & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                     & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))))))));
    vlSelfRef.tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 
        = (((QData)((IData)((0x000000ffU & ((vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
                                             << 7U) 
                                            | (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                               >> 0x00000019U))))) 
            << 0x00000037U) | (((QData)((IData)((0x0000003fU 
                                                 & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                    >> 0x00000013U)))) 
                                << 0x0000002fU) | (0x00007fffffffffffULL 
                                                   & (((QData)((IData)(
                                                                       vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                       << 0x0000001eU) 
                                                      | ((QData)((IData)(
                                                                         vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                         >> 2U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((1U 
                                                 == 
                                                 (7U 
                                                  & ((vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
                                                      << 2U) 
                                                     | (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                        >> 0x0000001eU))))
                                                 ? 
                                                ((vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                  << 0x00000010U) 
                                                 | (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
                                                    >> 0x00000010U))
                                                 : 0U);
    __VdfgRegularize_he50b618e_0_27[0U] = (((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                             << 0x0000001eU) 
                                            | (0x3ffffffeU 
                                               & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                  >> 2U))) 
                                           | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    __VdfgRegularize_he50b618e_0_27[1U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                  >> 2U)) 
                                           | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                               << 0x0000001eU) 
                                              | (0x3ffffffeU 
                                                 & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                    >> 2U))));
    __VdfgRegularize_he50b618e_0_27[2U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                  >> 2U)) 
                                           | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                               << 0x0000001eU) 
                                              | (0x3ffffffeU 
                                                 & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                    >> 2U))));
    __VdfgRegularize_he50b618e_0_27[3U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                  >> 2U)) 
                                           | (0x00000ffeU 
                                              & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                 >> 2U)));
    vlSelfRef.tlul_socket_1n__DOT__hold_all_requests 
        = ((0U != (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)) 
           & ((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]) 
              != (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding)));
    vlSelfRef.alert_ack_o = ((IData)(vlSelfRef.prim_alert_sender__DOT__alert_clr) 
                             & (IData)(vlSelfRef.prim_alert_sender__DOT__alert_set_q));
    vlSelfRef.idx_o = (0x0000000fU & ((IData)(vlSelfRef.rrarbiter__DOT__lock_q)
                                       ? (IData)(vlSelfRef.rrarbiter__DOT__arb_sel_lock_q)
                                       : ((0x0dU > (IData)(rrarbiter__DOT__next_idx))
                                           ? (IData)(rrarbiter__DOT__next_idx)
                                           : 0x0000000cU)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.we_o)) & ((IData)(vlSelfRef.gnt_i) 
                                           & (IData)(vlSelfRef.req_o))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o)));
    my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req));
    tlul_adapter_sram__DOT__d_error = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
                                       & ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                     >> 0x0000000fU)))
                                           ? ((IData)(tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o) 
                                              | (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                 >> 0x0000000eU))
                                           : (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                              >> 0x0000000eU)));
    tlul_adapter_sram__DOT__d_valid = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
                                       & (IData)(((0x00008000U 
                                                   != 
                                                   (0x0001c000U 
                                                    & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)) 
                                                  | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    tlul_socket_1n__DOT__tl_t_o[0U] = __VdfgRegularize_he50b618e_0_27[0U];
    tlul_socket_1n__DOT__tl_t_o[1U] = __VdfgRegularize_he50b618e_0_27[1U];
    tlul_socket_1n__DOT__tl_t_o[2U] = __VdfgRegularize_he50b618e_0_27[2U];
    tlul_socket_1n__DOT__tl_t_o[3U] = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                        << 0x0000000cU) 
                                       | __VdfgRegularize_he50b618e_0_27[3U]);
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[0U] 
        = __VdfgRegularize_he50b618e_0_27[0U];
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[1U] 
        = __VdfgRegularize_he50b618e_0_27[1U];
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[2U] 
        = __VdfgRegularize_he50b618e_0_27[2U];
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U]) 
           | (0x00001fffU & __VdfgRegularize_he50b618e_0_27[3U]));
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U]) 
           | (0x00001fffU & (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                              & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
                                 & (4U <= (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])))) 
                             << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    __Vtableidx4 = (((IData)(vlSelfRef.vld_o) << 4U) 
                    | (IData)(vlSelfRef.idx_o));
    vlSelfRef.ack_o = Vtop_pkg__ConstPool__TABLE_hdd797092_0
        [__Vtableidx4];
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error 
        = (((~ (0U != (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) 
            & (((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
                & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req)) 
               | (IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o))) 
           | ((IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o) 
              & (((0U == (vlSelfRef.my_ip__02Etl_i[1U] 
                          >> 0x0000001eU)) & (0U != 
                                              (0x0000000fU 
                                               & (~ 
                                                  ((vlSelfRef.my_ip__02Etl_i[1U] 
                                                    << 8U) 
                                                   | (vlSelfRef.my_ip__02Etl_i[1U] 
                                                      >> 0x00000018U)))))) 
                 | ((0U != (1U & (~ ((vlSelfRef.my_ip__02Etl_i[1U] 
                                      << 8U) | (vlSelfRef.my_ip__02Etl_i[1U] 
                                                >> 0x00000018U))))) 
                    & ((1U == (vlSelfRef.my_ip__02Etl_i[1U] 
                               >> 0x0000001eU)) | (
                                                   (2U 
                                                    == 
                                                    (vlSelfRef.my_ip__02Etl_i[1U] 
                                                     >> 0x0000001eU)) 
                                                   | (3U 
                                                      == 
                                                      (vlSelfRef.my_ip__02Etl_i[1U] 
                                                       >> 0x0000001eU))))))));
    tlul_adapter_sram__DOT__vld_rd_rsp = ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                          & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
                                             & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o) 
                                                & (0x00008000U 
                                                   == 
                                                   (0x00018000U 
                                                    & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)))));
    tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i 
        = ((IData)(tlul_adapter_sram__DOT__d_valid) 
           & vlSelfRef.tlul_adapter_sram__02Etl_i[0U]);
    vlSelfRef.tlul_socket_1n__DOT__blanked_auser = 
        ((0x007fc000U & (tlul_socket_1n__DOT__tl_t_o[0U] 
                         >> 1U)) | ((([&]() {
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[0U] 
                            = tlul_socket_1n__DOT__tl_t_o[0U];
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[1U] 
                            = tlul_socket_1n__DOT__tl_t_o[1U];
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[2U] 
                            = tlul_socket_1n__DOT__tl_t_o[2U];
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[3U] 
                            = tlul_socket_1n__DOT__tl_t_o[3U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[0U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[0U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[1U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[1U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[2U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[2U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[3U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[3U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[0U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[0U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[1U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[1U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[2U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[2U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[3U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[3U];
                        vlSelf->__Vfunc_extract_h2d_cmd_intg__20__payload = 0;
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload 
                            = ((0x0000078000000000ULL 
                                & vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload) 
                               | (((QData)((IData)(
                                                   ((vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[2U] 
                                                     << 4U) 
                                                    | (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[1U] 
                                                       >> 0x0000001cU)))) 
                                   << 7U) | (QData)((IData)(
                                                            ((0x00000070U 
                                                              & (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[3U] 
                                                                 >> 5U)) 
                                                             | (0x0000000fU 
                                                                & (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[1U] 
                                                                   >> 0x00000018U)))))));
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload 
                            = ((0x0000007fffffffffULL 
                                & vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload) 
                               | ((QData)((IData)((0x0000000fU 
                                                   & (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[0U] 
                                                      >> 0x0000000fU)))) 
                                  << 0x00000027U));
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__Vfuncout 
                            = vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload;
                        vlSelfRef.__Vfunc_get_cmd_intg__19__cmd 
                            = vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__Vfuncout;
                        vlSelfRef.__Vfunc_get_cmd_intg__19__cmd_intg 
                            = (0x0000007fU & (IData)(
                                                     (([&]() {
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_i 
                                                = vlSelfRef.__Vfunc_get_cmd_intg__19__cmd;
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_i;
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xfdffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x0103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x00000039U));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xfbffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x017c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003aU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xf7ffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003bU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xefffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003cU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xdfffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003dU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xbfffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003eU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0x7fffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003fU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (0x5400000000000000ULL 
                                                   ^ vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o);
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__Vfuncout 
                                                = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o;
                                        }(), vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__Vfuncout) 
                                                      >> 0x00000039U)));
                        __Vfunc_get_cmd_intg__19__unused_cmd_payload 
                            = (0x01ffffffffffffffULL 
                               & ([&]() {
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_i 
                                        = vlSelfRef.__Vfunc_get_cmd_intg__19__cmd;
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_i;
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xfdffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x0103fff800007fffULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x00000039U));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xfbffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x017c1ff801ff801fULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003aU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xf7ffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01bde1f87e0781e1ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003bU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xefffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01deee3b8e388e22ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003cU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xdfffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01ef76cdb2c93244ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003dU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xbfffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01f7bb56d5525488ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003eU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0x7fffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01fbdda769a46910ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003fU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = (0x5400000000000000ULL 
                                           ^ vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o);
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__Vfuncout 
                                        = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o;
                                }(), vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__Vfuncout));
                        vlSelfRef.__Vfunc_get_cmd_intg__19__Vfuncout 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__cmd_intg;
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__cmd_intg 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__Vfuncout;
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__Vfuncout 
                            = (0x0000007fU & (~ (IData)(vlSelfRef.__Vfunc_get_bad_cmd_intg__18__cmd_intg)));
                    }(), (IData)(vlSelfRef.__Vfunc_get_bad_cmd_intg__18__Vfuncout)) 
                                     << 7U) | ([&]() {
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o = 0x00000000ffffffffULL;
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = (0x0000007effffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o);
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000007dffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x00000000deba8050ULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000021U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000007bffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x00000000413d89aaULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000022U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x00000077ffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x0000000031234ed1ULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000023U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000006fffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x00000000c2c1323bULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000024U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000005fffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x000000002dcc624cULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000025U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000003fffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x0000000098505586ULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000026U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = (0x0000002a00000000ULL ^ vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o);
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__Vfuncout 
                        = vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o;
                    vlSelfRef.__Vfunc_get_data_intg__24__enc_data 
                        = vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__Vfuncout;
                    vlSelfRef.__Vfunc_get_data_intg__24__data_intg 
                        = (0x0000007fU & (IData)((vlSelfRef.__Vfunc_get_data_intg__24__enc_data 
                                                  >> 0x20U)));
                    vlSelfRef.__Vfunc_get_data_intg__24__Vfuncout 
                        = vlSelfRef.__Vfunc_get_data_intg__24__data_intg;
                    vlSelfRef.__Vfunc_get_bad_data_intg__23__data_intg 
                        = vlSelfRef.__Vfunc_get_data_intg__24__Vfuncout;
                    vlSelfRef.__Vfunc_get_bad_data_intg__23__Vfuncout 
                        = (0x0000007fU & (~ (IData)(vlSelfRef.__Vfunc_get_bad_data_intg__23__data_intg)));
                }(), (IData)(vlSelfRef.__Vfunc_get_bad_data_intg__23__Vfuncout))));
    my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error)) 
           & (IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o));
    vlSelfRef.tlul_adapter_sram__02Etl_o[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                           ? 
                                                                          (3U 
                                                                           & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                              >> 8U))
                                                                           : 0U))) 
                                                         << 0x00000039U) 
                                                        | (((QData)((IData)(
                                                                            ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                              ? 
                                                                             (0x000000ffU 
                                                                              & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)
                                                                              : 0U))) 
                                                            << 0x00000031U) 
                                                           | (((QData)((IData)(
                                                                               (((~ (IData)(tlul_adapter_sram__DOT__d_error)) 
                                                                                & (IData)(tlul_adapter_sram__DOT__vld_rd_rsp))
                                                                                 ? (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 8U))
                                                                                 : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data))) 
                                                               << 0x00000010U) 
                                                              | (QData)((IData)(
                                                                                (((((IData)(tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                                & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                                >> 0x0000000eU))
                                                                                 ? 0x0000002aU
                                                                                 : 
                                                                                ((IData)(tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                                 ? 
                                                                                (0x0000007fU 
                                                                                & (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 1U)))
                                                                                 : 0x0000002aU)) 
                                                                                << 2U) 
                                                                                | ((((IData)(tlul_adapter_sram__DOT__d_error) 
                                                                                & (IData)(tlul_adapter_sram__DOT__d_valid)) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)))))))));
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = ((0xc0000000U 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[1U]) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                               ? 
                                                                              (3U 
                                                                               & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                                >> 8U))
                                                                               : 0U))) 
                                                             << 0x00000039U) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                                                 ? 
                                                                                (0x000000ffU 
                                                                                & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)
                                                                                 : 0U))) 
                                                                << 0x00000031U) 
                                                               | (((QData)((IData)(
                                                                                (((~ (IData)(tlul_adapter_sram__DOT__d_error)) 
                                                                                & (IData)(tlul_adapter_sram__DOT__vld_rd_rsp))
                                                                                 ? (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 8U))
                                                                                 : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data))) 
                                                                   << 0x00000010U) 
                                                                  | (QData)((IData)(
                                                                                (((((IData)(tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                                & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                                                >> 0x0000000eU))
                                                                                 ? 0x0000002aU
                                                                                 : 
                                                                                ((IData)(tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                                 ? 
                                                                                (0x0000007fU 
                                                                                & (IData)(
                                                                                (tlul_adapter_sram__DOT____Vcellout__u_rspfifo__rdata_o 
                                                                                >> 1U)))
                                                                                 : 0x0000002aU)) 
                                                                                << 2U) 
                                                                                | ((((IData)(tlul_adapter_sram__DOT__d_error) 
                                                                                & (IData)(tlul_adapter_sram__DOT__d_valid)) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)))))))) 
                                                           >> 0x00000020U)));
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = ((0x3fffffffU 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[1U]) 
                                                | ((((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                     & (1U 
                                                        != 
                                                        (3U 
                                                         & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                            >> 0x0000000fU))))
                                                     ? 0U
                                                     : 1U) 
                                                   << 0x0000001eU));
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = ((2U 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[2U]) 
                                                | (3U 
                                                   & ((((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                        & (1U 
                                                           != 
                                                           (3U 
                                                            & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                                               >> 0x0000000fU))))
                                                        ? 0U
                                                        : 1U) 
                                                      >> 2U)));
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = ((1U 
                                                 & vlSelfRef.tlul_adapter_sram__02Etl_o[2U]) 
                                                | (3U 
                                                   & ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                      << 1U)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(((0x00008000U == (0x0001c000U 
                                          & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o)) 
                         & (IData)(tlul_adapter_sram__DOT__u_reqfifo__DOT__rready_i)))));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((0U == (vlSelfRef.my_ip__02Etl_i[1U] >> 0x0000001eU)) 
           & (IData)(my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

void Vtop_pkg___024root___ico_sequent__TOP__1(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___ico_sequent__TOP__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*65:0*/ tlul_socket_1n__DOT__tl_t_p;
    VL_ZERO_W(66, tlul_socket_1n__DOT__tl_t_p);
    CData/*0:0*/ tlul_socket_1n__DOT__hfifo_reqready;
    tlul_socket_1n__DOT__hfifo_reqready = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i;
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o;
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty;
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    // Body
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [0U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [0U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [0U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [0U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [0U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [0U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [0U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [0U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [0U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [0U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [0U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [0U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [0U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [1U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [1U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [1U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [1U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [1U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [1U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [1U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [1U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [1U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [1U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [1U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [1U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [1U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [2U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [2U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [2U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [2U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [2U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [2U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [2U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [2U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [2U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [2U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [2U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [2U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [2U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [3U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [3U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [3U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [3U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [3U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [3U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [3U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [3U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [3U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [3U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [3U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [3U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][0U]) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[0U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][1U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][2U] = (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                     ? 0U
                                                     : 
                                                    (1U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                                   | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (0xfffffffeU 
                                                       & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][3U] = (
                                                   (0x00001000U 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][3U]) 
                                                   | (0x00001fffU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                           ? 0U
                                                           : 
                                                          (1U 
                                                           & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                               & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                               ? 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                               : 
                                                              vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                         | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (0x00000ffeU 
                                                             & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                 & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wvalid_i))
                                                                 ? 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__reqfifo__wdata_i[3U]
                                                                 : 
                                                                vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U][3U] = (
                                                   (0x00000fffU 
                                                    & vlSelfRef.tlul_socket_1n__02Etl_d_o
                                                    [3U][3U]) 
                                                   | (0x00001fffU 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__rvalid_o) 
                                                         << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [0U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [0U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [0U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [0U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [0U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [0U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [0U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [0U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [0U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [1U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [1U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [1U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [1U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [1U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [1U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [1U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [1U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [1U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [2U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [2U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [2U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [2U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [2U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [2U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [2U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [2U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [2U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][0U] 
        = ((1U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][0U]) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                     [3U][3U] 
                                                     >> 0x0000000cU))
                                                  ? 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[0U]
                                                  : 
                                                 vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][1U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [3U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [3U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[1U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][2U] 
        = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
             ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                            & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                               [3U][3U] >> 0x0000000cU))
                            ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                            : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
           | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
               ? 0U : (0xfffffffeU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                          [3U][3U] 
                                          >> 0x0000000cU))
                                       ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[2U]
                                       : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][3U]) | (0x00001fffU & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (1U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                         [3U][3U] 
                                                         >> 0x0000000cU))
                                                      ? 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0x00000ffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__02Etl_h_i
                                                   [3U][3U] 
                                                   >> 0x0000000cU))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__reqfifo__wdata_i[3U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U][3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
            [3U][3U]) | (0x00001fffU & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                        << 0x0000000cU)));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i 
        = ((((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
             << 3U) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                       << 2U)) | (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                   << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][0U] = (
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][0U]) 
                                                   | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][0U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][0U]) 
                                                   | ((IData)(
                                                              (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U)))) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][1U] = (
                                                   ((IData)(
                                                            (((QData)((IData)(
                                                                              ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                ? 0U
                                                                                : 
                                                                               (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                              << 0x0000003fU) 
                                                             | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                 << 0x0000001fU) 
                                                                | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                   >> 1U)))) 
                                                    >> 0x0000001fU) 
                                                   | ((IData)(
                                                              ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                 << 0x0000003fU) 
                                                                | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                    << 0x0000001fU) 
                                                                   | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                      >> 1U))) 
                                                               >> 0x00000020U)) 
                                                      << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][2U] = (
                                                   (2U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][2U]) 
                                                   | (3U 
                                                      & ((IData)(
                                                                 ((((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                    << 0x0000003fU) 
                                                                   | (((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                       << 0x0000001fU) 
                                                                      | ((QData)((IData)(
                                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__wvalid_i))
                                                                                 ? 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                         >> 1U))) 
                                                                  >> 0x00000020U)) 
                                                         >> 0x0000001fU)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U][2U] = (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_m1__02Etl_h_o
                                                    [3U][2U]) 
                                                   | (3U 
                                                      & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__rvalid_o) 
                                                         << 1U)));
    tlul_socket_1n__DOT__hfifo_reqready = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                           [4U][0U]);
    if ((0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [0U][0U]);
    }
    if ((1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [1U][0U]);
    }
    if ((2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [2U][0U]);
    }
    if ((3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [3U][0U]);
    }
    if (vlSelfRef.tlul_socket_1n__DOT__hold_all_requests) {
        tlul_socket_1n__DOT__hfifo_reqready = 0U;
    }
    tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][0U];
    tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][1U];
    tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][2U];
    if ((0U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [0U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [0U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [0U][2U];
    }
    if ((1U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [1U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [1U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [1U][2U];
    }
    if ((2U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [2U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [2U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [2U][2U];
    }
    if ((3U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [3U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [3U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [3U][2U];
    }
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[0U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [0U][3U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[1U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [1U][3U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[2U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [2U][3U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][0U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][0U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][1U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][1U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][2U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][2U];
    vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[3U][3U] 
        = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o
        [3U][3U];
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i))) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i));
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & (IData)(tlul_socket_1n__DOT__hfifo_reqready));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp = (
                                                   (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                    >> 1U) 
                                                   & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((tlul_socket_1n__DOT__tl_t_p[2U] >> 1U) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (0x0000fffeU & tlul_socket_1n__DOT__tl_t_p[0U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x0000001eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x00000010U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                       >> 0x00000010U))
                : 0U) << 0x00000010U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x0000001eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x00000010U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                       >> 0x00000010U))
                : 0U) >> 0x00000010U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & tlul_socket_1n__DOT__tl_t_p[1U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & tlul_socket_1n__DOT__tl_t_p[2U]);
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (tlul_socket_1n__DOT__tl_t_p[2U] >> 1U)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req 
        = ((0U != (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req))
            ? (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req)
            : (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_req = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                                   & (IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    __VdfgRegularize_h6e95ff9d_0_4 = (IData)((0U != 
                                              (3U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[0U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
                                                                            ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                              ? 0U
                                                                              : 
                                                                             (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                               & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                               ? 
                                                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                               : 
                                                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                            << 0x0000003fU) 
                                                           | (((QData)((IData)(
                                                                               ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                               << 0x0000001fU) 
                                                              | ((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                 >> 1U)))) 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[1U] = (((IData)(
                                                        (((QData)((IData)(
                                                                          ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                            ? 0U
                                                                            : 
                                                                           (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                             & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                             ? 
                                                                            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                             : 
                                                                            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                          << 0x0000003fU) 
                                                         | (((QData)((IData)(
                                                                             ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                               ? 0U
                                                                               : 
                                                                              (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                ? 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                : 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                             << 0x0000001fU) 
                                                            | ((QData)((IData)(
                                                                               ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                               >> 1U)))) 
                                                >> 0x0000001fU) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                               ? 0U
                                                                               : 
                                                                              (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                ? 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                                : 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                             << 0x0000003fU) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                << 0x0000001fU) 
                                                               | ((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                  >> 1U))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((2U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
                                                     << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    __VdfgRegularize_h6e95ff9d_0_5 = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                            | ((IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req) 
                                               >> 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = (((((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
              | ((IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req) 
                 >> 3U)) << 3U) | ((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                                   << 2U)) | (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                               << 1U) 
                                              | (1U 
                                                 & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner 
        = (0x0000000fU & ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                          ^ VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U)));
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] = 0U;
    if ((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [0U][3U];
    }
    if ((2U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [1U][3U];
    }
    if ((4U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [2U][3U];
    }
    if ((8U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][0U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][1U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][2U];
        vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U] 
            = vlSelfRef.tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i
            [3U][3U];
    }
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)
            ? (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner)
            : 0U);
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                       ? 
                                                      (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U])
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[1U] = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (0U 
                                                        != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]) 
                                                     | (0xfffffffeU 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]))
                                                     : 
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]) 
                                                       | (0xfffffffeU 
                                                          & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]))
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[2U] = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (0U 
                                                        != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]) 
                                                     | (0xfffffffeU 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]))
                                                     : 
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]) 
                                                       | (0xfffffffeU 
                                                          & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]))
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0x00001000U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x00001fffU 
                                                  & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (1U 
                                                       & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (0U 
                                                              != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                           ? 
                                                          ((1U 
                                                            & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]) 
                                                           | (0x00000ffeU 
                                                              & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]))
                                                           : 
                                                          vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))) 
                                                     | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                         ? 0U
                                                         : 
                                                        (0x00000ffeU 
                                                         & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (0U 
                                                                != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)))
                                                             ? 
                                                            ((1U 
                                                              & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]) 
                                                             | (0x00000ffeU 
                                                                & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]))
                                                             : 
                                                            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0x00000fffU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x00001fffU 
                                                  & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
                                                     << 0x0000000cU)));
}

void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);

void Vtop_pkg___024root___eval_ico(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_ico\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop_pkg___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vtop_pkg___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
    }
}

bool Vtop_pkg___024root___eval_phase__ico(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_phase__ico\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop_pkg___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop_pkg___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop_pkg___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop_pkg___024root___eval_triggers__act(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_triggers__act\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (((QData)((IData)(
                                                      ((((((((~ (IData)(vlSelfRef.my_ip__02Erst_ni)) 
                                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__my_ip__02Erst_ni__0)) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.my_ip__02Eclk_i) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__my_ip__02Eclk_i__0))) 
                                                              << 2U)) 
                                                          | ((((~ (IData)(vlSelfRef.tlul_socket_m1__02Erst_ni)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_m1__02Erst_ni__0)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelfRef.tlul_socket_m1__02Eclk_i) 
                                                                & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_m1__02Eclk_i__0))))) 
                                                         << 0x00000018U) 
                                                        | (((((((~ (IData)(vlSelfRef.tlul_socket_1n__02Erst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_1n__02Erst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.tlul_socket_1n__02Eclk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_1n__02Eclk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.rst_d_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_d_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.clk_d_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_d_i__0))))) 
                                                            << 0x00000014U) 
                                                           | ((((((~ (IData)(vlSelfRef.rst_h_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_h_ni__0)) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.clk_h_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_h_i__0))) 
                                                                   << 2U)) 
                                                               | ((((~ (IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Erst_ni__0)) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.tlul_adapter_sram__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Eclk_i__0))))) 
                                                              << 0x00000010U))) 
                                                       | ((((((((~ (IData)(vlSelfRef.tlul_adapter_host__02Erst_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Erst_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.tlul_adapter_host__02Eclk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Eclk_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.prim_alert_sender__02Erst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_alert_sender__02Erst_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.prim_alert_sender__02Eclk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_alert_sender__02Eclk_i__0))))) 
                                                            << 0x0000000cU) 
                                                           | ((((((~ (IData)(vlSelfRef.rst_dst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_dst_ni__0)) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.clk_dst_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_dst_i__0))) 
                                                                   << 2U)) 
                                                               | ((((~ (IData)(vlSelfRef.rst_src_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_src_ni__0)) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.clk_src_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_src_i__0))))) 
                                                              << 8U)) 
                                                          | (((((((~ (IData)(vlSelfRef.prim_filter_ctr__02Erst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter_ctr__02Erst_ni__0)) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.prim_filter_ctr__02Eclk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter_ctr__02Eclk_i__0))) 
                                                                   << 2U)) 
                                                               | ((((~ (IData)(vlSelfRef.prim_filter__02Erst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter__02Erst_ni__0)) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.prim_filter__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter__02Eclk_i__0))))) 
                                                              << 4U) 
                                                             | (((((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_rd_ni__0)) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_rd_i__0))) 
                                                                    << 2U)) 
                                                                | ((((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_wr_ni__0)) 
                                                                    << 1U) 
                                                                   | ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_wr_i__0)))))))))) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(
                                                       ((((((((((~ (IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni)) 
                                                                & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_rd_ni__0)) 
                                                               << 3U) 
                                                              | (((IData)(vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_rd_i__0))) 
                                                                 << 2U)) 
                                                             | ((((~ (IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_wr_ni__0)) 
                                                                 << 1U) 
                                                                | ((IData)(vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_wr_i__0))))) 
                                                            << 0x0000000cU) 
                                                           | ((((((~ (IData)(vlSelfRef.rrarbiter__02Erst_ni)) 
                                                                  & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rrarbiter__02Erst_ni__0)) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.rrarbiter__02Eclk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rrarbiter__02Eclk_i__0))) 
                                                                   << 2U)) 
                                                               | ((((~ (IData)(vlSelfRef.prim_reg__02Erst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_reg__02Erst_ni__0)) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.prim_reg__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_reg__02Eclk_i__0))))) 
                                                              << 8U)) 
                                                          | (((((((IData)(vlSelfRef.rd_clk_i) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rd_clk_i__0))) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.wr_clk_i) 
                                                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__wr_clk_i__0))) 
                                                                   << 2U)) 
                                                               | ((((~ (IData)(vlSelfRef.prim_fifo__02Erst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo__02Erst_ni__0)) 
                                                                   << 1U) 
                                                                  | ((~ (IData)(vlSelfRef.prim_edge_detect__02Erst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_edge_detect__02Erst_ni__0)))) 
                                                              << 4U) 
                                                             | (((((IData)(vlSelfRef.prim_edge_detect__02Eclk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_edge_detect__02Eclk_i__0))) 
                                                                  << 3U) 
                                                                 | (((~ (IData)(vlSelfRef.prim_deglitch__02Erst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_deglitch__02Erst_ni__0)) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.prim_deglitch__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_deglitch__02Eclk_i__0))) 
                                                                    << 1U) 
                                                                   | ((~ (IData)(vlSelfRef.prim_counter__02Erst_ni)) 
                                                                      & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_counter__02Erst_ni__0)))))) 
                                                         << 0x00000010U) 
                                                        | ((((((((IData)(vlSelfRef.prim_counter__02Eclk_i) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_counter__02Eclk_i__0))) 
                                                                << 3U) 
                                                               | (((~ (IData)(vlSelfRef.dst_rst_ni)) 
                                                                   & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dst_rst_ni__0)) 
                                                                  << 2U)) 
                                                              | ((((IData)(vlSelfRef.dst_clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dst_clk_i__0))) 
                                                                  << 1U) 
                                                                 | ((~ (IData)(vlSelfRef.src_rst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__src_rst_ni__0)))) 
                                                             << 0x0000000cU) 
                                                            | ((((((IData)(vlSelfRef.src_clk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__src_clk_i__0))) 
                                                                  << 3U) 
                                                                 | (((~ (IData)(vlSelfRef.prim_intr_hw__02Erst_ni)) 
                                                                     & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_intr_hw__02Erst_ni__0)) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.prim_intr_hw__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_intr_hw__02Eclk_i__0))) 
                                                                    << 1U) 
                                                                   | ((~ (IData)(vlSelfRef.prim_cdc_rand_delay__02Erst_ni)) 
                                                                      & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_cdc_rand_delay__02Erst_ni__0)))) 
                                                               << 8U)) 
                                                           | (((((((IData)(vlSelfRef.prim_cdc_rand_delay__02Eclk_i) 
                                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_cdc_rand_delay__02Eclk_i__0))) 
                                                                  << 3U) 
                                                                 | (((IData)(vlSelfRef.prim_shreg__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_shreg__02Eclk_i__0))) 
                                                                    << 2U)) 
                                                                | ((((IData)(vlSelfRef.prim_rom__02Eclk_i) 
                                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_rom__02Eclk_i__0))) 
                                                                    << 1U) 
                                                                   | ((IData)(vlSelfRef.prim_ram__02Eclk_i) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_ram__02Eclk_i__0))))) 
                                                               << 4U) 
                                                              | (((((~ (IData)(vlSelfRef.prim_lifo__02Erst_ni)) 
                                                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_lifo__02Erst_ni__0)) 
                                                                   << 3U) 
                                                                  | (((IData)(vlSelfRef.prim_lifo__02Eclk_i) 
                                                                      & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_lifo__02Eclk_i__0))) 
                                                                     << 2U)) 
                                                                 | ((((~ (IData)(vlSelfRef.prim_clk_div__02Erst_ni)) 
                                                                      & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_clk_div__02Erst_ni__0)) 
                                                                     << 1U) 
                                                                    | ((IData)(vlSelfRef.prim_clk_div__02Eclk_i) 
                                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_clk_div__02Eclk_i__0)))))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__prim_clk_div__02Eclk_i__0 
        = vlSelfRef.prim_clk_div__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_clk_div__02Erst_ni__0 
        = vlSelfRef.prim_clk_div__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_lifo__02Eclk_i__0 
        = vlSelfRef.prim_lifo__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_lifo__02Erst_ni__0 
        = vlSelfRef.prim_lifo__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_ram__02Eclk_i__0 
        = vlSelfRef.prim_ram__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_rom__02Eclk_i__0 
        = vlSelfRef.prim_rom__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_shreg__02Eclk_i__0 
        = vlSelfRef.prim_shreg__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_cdc_rand_delay__02Eclk_i__0 
        = vlSelfRef.prim_cdc_rand_delay__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_cdc_rand_delay__02Erst_ni__0 
        = vlSelfRef.prim_cdc_rand_delay__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_intr_hw__02Eclk_i__0 
        = vlSelfRef.prim_intr_hw__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_intr_hw__02Erst_ni__0 
        = vlSelfRef.prim_intr_hw__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__src_clk_i__0 = vlSelfRef.src_clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__src_rst_ni__0 
        = vlSelfRef.src_rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__dst_clk_i__0 = vlSelfRef.dst_clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__dst_rst_ni__0 
        = vlSelfRef.dst_rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_counter__02Eclk_i__0 
        = vlSelfRef.prim_counter__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_counter__02Erst_ni__0 
        = vlSelfRef.prim_counter__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_deglitch__02Eclk_i__0 
        = vlSelfRef.prim_deglitch__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_deglitch__02Erst_ni__0 
        = vlSelfRef.prim_deglitch__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_edge_detect__02Eclk_i__0 
        = vlSelfRef.prim_edge_detect__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_edge_detect__02Erst_ni__0 
        = vlSelfRef.prim_edge_detect__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo__02Erst_ni__0 
        = vlSelfRef.prim_fifo__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__wr_clk_i__0 = vlSelfRef.wr_clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rd_clk_i__0 = vlSelfRef.rd_clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_reg__02Eclk_i__0 
        = vlSelfRef.prim_reg__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_reg__02Erst_ni__0 
        = vlSelfRef.prim_reg__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__rrarbiter__02Eclk_i__0 
        = vlSelfRef.rrarbiter__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rrarbiter__02Erst_ni__0 
        = vlSelfRef.rrarbiter__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_wr_i__0 
        = vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_wr_ni__0 
        = vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_rd_i__0 
        = vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_rd_ni__0 
        = vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_wr_i__0 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_wr_ni__0 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_rd_i__0 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_rd_ni__0 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_filter__02Eclk_i__0 
        = vlSelfRef.prim_filter__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_filter__02Erst_ni__0 
        = vlSelfRef.prim_filter__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_filter_ctr__02Eclk_i__0 
        = vlSelfRef.prim_filter_ctr__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_filter_ctr__02Erst_ni__0 
        = vlSelfRef.prim_filter_ctr__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__clk_src_i__0 = vlSelfRef.clk_src_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_src_ni__0 
        = vlSelfRef.rst_src_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__clk_dst_i__0 = vlSelfRef.clk_dst_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_dst_ni__0 
        = vlSelfRef.rst_dst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_alert_sender__02Eclk_i__0 
        = vlSelfRef.prim_alert_sender__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_alert_sender__02Erst_ni__0 
        = vlSelfRef.prim_alert_sender__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Eclk_i__0 
        = vlSelfRef.tlul_adapter_host__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Erst_ni__0 
        = vlSelfRef.tlul_adapter_host__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Eclk_i__0 
        = vlSelfRef.tlul_adapter_sram__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Erst_ni__0 
        = vlSelfRef.tlul_adapter_sram__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__clk_h_i__0 = vlSelfRef.clk_h_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_h_ni__0 = vlSelfRef.rst_h_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__clk_d_i__0 = vlSelfRef.clk_d_i;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_d_ni__0 = vlSelfRef.rst_d_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_1n__02Eclk_i__0 
        = vlSelfRef.tlul_socket_1n__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_1n__02Erst_ni__0 
        = vlSelfRef.tlul_socket_1n__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_m1__02Eclk_i__0 
        = vlSelfRef.tlul_socket_m1__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_m1__02Erst_ni__0 
        = vlSelfRef.tlul_socket_m1__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__my_ip__02Eclk_i__0 
        = vlSelfRef.my_ip__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__my_ip__02Erst_ni__0 
        = vlSelfRef.my_ip__02Erst_ni;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_pkg___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop_pkg___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop_pkg___024root___nba_sequent__TOP__0(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__prim_clk_div__DOT__counter_q;
    __Vdly__prim_clk_div__DOT__counter_q = 0;
    // Body
    __Vdly__prim_clk_div__DOT__counter_q = vlSelfRef.prim_clk_div__DOT__counter_q;
    if (vlSelfRef.prim_clk_div__02Erst_ni) {
        vlSelfRef.prim_clk_div__DOT__clk_q = 0U;
        if (vlSelfRef.prim_clk_div__02Een_i) {
            if ((3U == (IData)(vlSelfRef.prim_clk_div__DOT__counter_q))) {
                vlSelfRef.prim_clk_div__DOT__clk_q = 1U;
                __Vdly__prim_clk_div__DOT__counter_q = 0U;
            } else {
                __Vdly__prim_clk_div__DOT__counter_q 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.prim_clk_div__DOT__counter_q)));
            }
        }
    } else {
        __Vdly__prim_clk_div__DOT__counter_q = 0U;
        vlSelfRef.prim_clk_div__DOT__clk_q = 0U;
    }
    vlSelfRef.prim_clk_div__DOT__counter_q = __Vdly__prim_clk_div__DOT__counter_q;
    vlSelfRef.prim_clk_div__02Eclk_o = ((IData)(vlSelfRef.testmode_i)
                                         ? (IData)(vlSelfRef.prim_clk_div__02Eclk_i)
                                         : (IData)(vlSelfRef.prim_clk_div__DOT__clk_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__1(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vdly__prim_deglitch__DOT__count_q;
    __Vdly__prim_deglitch__DOT__count_q = 0;
    // Body
    __Vdly__prim_deglitch__DOT__count_q = vlSelfRef.prim_deglitch__DOT__count_q;
    if (vlSelfRef.prim_deglitch__02Erst_ni) {
        if (vlSelfRef.prim_deglitch__02Een_i) {
            if (((IData)(vlSelfRef.d_i) & (4U > (IData)(vlSelfRef.prim_deglitch__DOT__count_q)))) {
                __Vdly__prim_deglitch__DOT__count_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.prim_deglitch__DOT__count_q)));
            } else if (((~ (IData)(vlSelfRef.d_i)) 
                        & (0U < (IData)(vlSelfRef.prim_deglitch__DOT__count_q)))) {
                __Vdly__prim_deglitch__DOT__count_q 
                    = (7U & ((IData)(vlSelfRef.prim_deglitch__DOT__count_q) 
                             - (IData)(1U)));
            }
        }
    } else {
        __Vdly__prim_deglitch__DOT__count_q = 0U;
    }
    vlSelfRef.prim_deglitch__DOT__count_q = __Vdly__prim_deglitch__DOT__count_q;
    vlSelfRef.q_o = 0U;
    if ((4U == (IData)(vlSelfRef.prim_deglitch__DOT__count_q))) {
        vlSelfRef.q_o = 1U;
    } else if ((0U == (IData)(vlSelfRef.prim_deglitch__DOT__count_q))) {
        vlSelfRef.q_o = 0U;
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__2(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__2\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_shreg__02Erst_ni) {
        if (vlSelfRef.prim_shreg__02Een_i) {
            vlSelfRef.prim_shreg__DOT__shift_reg = 
                ((0x000000feU & ((IData)(vlSelfRef.prim_shreg__DOT__shift_reg) 
                                 << 1U)) | (IData)(vlSelfRef.prim_shreg__02Eserial_i));
        }
    } else {
        vlSelfRef.prim_shreg__DOT__shift_reg = 0U;
    }
    vlSelfRef.pdata_o = vlSelfRef.prim_shreg__DOT__shift_reg;
    vlSelfRef.serial_o = (1U & ((IData)(vlSelfRef.prim_shreg__DOT__shift_reg) 
                                >> 7U));
}

void Vtop_pkg___024root___nba_sequent__TOP__3(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__3\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level 
        = vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level;
    vlSelfRef.__Vdly__prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level 
        = ((IData)(vlSelfRef.rst_src_ni) && ((IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level) 
                                             ^ (IData)(vlSelfRef.prim_reg_cdc__DOT__src_req)));
    if (vlSelfRef.rst_src_ni) {
        if (vlSelfRef.prim_reg_cdc__DOT__src_req) {
            vlSelfRef.prim_reg_cdc__DOT__src_busy_q = 1U;
            vlSelfRef.prim_reg_cdc__DOT__src_q = vlSelfRef.src_wd_i;
            vlSelfRef.prim_reg_cdc__DOT__txn_bits_q 
                = (((IData)(vlSelfRef.src_we_i) << 2U) 
                   | (((IData)(vlSelfRef.src_re_i) 
                       << 1U) | (IData)(vlSelfRef.src_regwen_i)));
        } else {
            if (vlSelfRef.prim_reg_cdc__DOT__src_ack) {
                vlSelfRef.prim_reg_cdc__DOT__src_busy_q = 0U;
            }
            if (vlSelfRef.prim_reg_cdc__DOT__dst_to_src) {
                vlSelfRef.prim_reg_cdc__DOT__src_q 
                    = vlSelfRef.dst_qs_i;
                vlSelfRef.prim_reg_cdc__DOT__txn_bits_q = 0U;
            }
        }
    } else {
        vlSelfRef.prim_reg_cdc__DOT__src_busy_q = 0U;
        vlSelfRef.prim_reg_cdc__DOT__src_q = 0U;
        vlSelfRef.prim_reg_cdc__DOT__txn_bits_q = 0U;
    }
    vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level_q 
        = ((IData)(vlSelfRef.rst_src_ni) && (IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level));
    vlSelfRef.src_busy_o = vlSelfRef.prim_reg_cdc__DOT__src_busy_q;
    vlSelfRef.src_qs_o = vlSelfRef.prim_reg_cdc__DOT__src_q;
    vlSelfRef.dst_wd_o = vlSelfRef.prim_reg_cdc__DOT__src_q;
    vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level 
        = ((IData)(vlSelfRef.rst_src_ni) && (IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__prim_flop_2sync__DOT__intq));
    vlSelfRef.prim_reg_cdc__DOT__src_ack = ((IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level) 
                                            ^ (IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level_q));
    vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__prim_flop_2sync__DOT__intq 
        = ((IData)(vlSelfRef.rst_src_ni) && (IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__src_level));
    vlSelfRef.prim_reg_cdc__DOT__dst_to_src = ((IData)(vlSelfRef.prim_reg_cdc__DOT__src_ack) 
                                               & (IData)(vlSelfRef.prim_reg_cdc__DOT__src_busy_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__4(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__4\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__src_level 
        = ((IData)(vlSelfRef.rst_dst_ni) && ((IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__src_level) 
                                             ^ (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src)));
    vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level_q 
        = ((IData)(vlSelfRef.rst_dst_ni) && (IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level));
    vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level 
        = ((IData)(vlSelfRef.rst_dst_ni) && (IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__prim_flop_2sync__DOT__intq));
    vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src = 
        ((IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level) 
         ^ (IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level_q));
    vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__prim_flop_2sync__DOT__intq 
        = ((IData)(vlSelfRef.rst_dst_ni) && (IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level));
}

void Vtop_pkg___024root___nba_sequent__TOP__5(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__5\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__prim_ram__DOT__mem__v0;
    __VdlyVal__prim_ram__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__prim_ram__DOT__mem__v0;
    __VdlyDim0__prim_ram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__prim_ram__DOT__mem__v0;
    __VdlySet__prim_ram__DOT__mem__v0 = 0;
    // Body
    __VdlySet__prim_ram__DOT__mem__v0 = 0U;
    if (vlSelfRef.prim_ram__02Erst_ni) {
        if (vlSelfRef.prim_ram__02Een_i) {
            if (vlSelfRef.prim_ram__02Ewe_i) {
                __VdlyVal__prim_ram__DOT__mem__v0 = vlSelfRef.prim_ram__02Ewdata_i;
                __VdlyDim0__prim_ram__DOT__mem__v0 
                    = vlSelfRef.prim_ram__02Eaddr_i;
                __VdlySet__prim_ram__DOT__mem__v0 = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.prim_ram__02Ewe_i)))) {
                vlSelfRef.prim_ram__02Erdata_o = vlSelfRef.prim_ram__DOT__mem
                    [vlSelfRef.prim_ram__02Eaddr_i];
            }
        }
    } else {
        vlSelfRef.prim_ram__02Erdata_o = 0U;
    }
    if (__VdlySet__prim_ram__DOT__mem__v0) {
        vlSelfRef.prim_ram__DOT__mem[__VdlyDim0__prim_ram__DOT__mem__v0] 
            = __VdlyVal__prim_ram__DOT__mem__v0;
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__6(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__6\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__cdc_2phase__DOT__i_src__DOT__req_src_q 
        = vlSelfRef.cdc_2phase__DOT__i_src__DOT__req_src_q;
    if (vlSelfRef.src_rst_ni) {
        if (((IData)(vlSelfRef.src_valid_i) & (IData)(vlSelfRef.src_ready_o))) {
            vlSelfRef.__Vdly__cdc_2phase__DOT__i_src__DOT__req_src_q 
                = (1U & (~ (IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__req_src_q)));
        }
    } else {
        vlSelfRef.__Vdly__cdc_2phase__DOT__i_src__DOT__req_src_q = 0U;
    }
    vlSelfRef.cdc_2phase__DOT__i_src__DOT__ack_q = 
        ((IData)(vlSelfRef.src_rst_ni) && (IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__ack_src_q));
    vlSelfRef.cdc_2phase__DOT__i_src__DOT__ack_src_q 
        = ((IData)(vlSelfRef.src_rst_ni) && (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__ack_dst_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__7(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__7\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.dst_rst_ni) {
        if (((IData)(vlSelfRef.dst_valid_o) & (IData)(vlSelfRef.dst_ready_i))) {
            vlSelfRef.cdc_2phase__DOT__i_dst__DOT__ack_dst_q 
                = (1U & (~ (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__ack_dst_q)));
        }
        if ((((IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q0) 
              != (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q1)) 
             & (~ (IData)(vlSelfRef.dst_valid_o)))) {
            vlSelfRef.cdc_2phase__DOT__i_dst__DOT__data_dst_q 
                = vlSelfRef.cdc_2phase__DOT__i_src__DOT__data_src_q;
        }
    } else {
        vlSelfRef.cdc_2phase__DOT__i_dst__DOT__ack_dst_q = 0U;
        vlSelfRef.cdc_2phase__DOT__i_dst__DOT__data_dst_q = 0U;
    }
    vlSelfRef.cdc_2phase__02Edst_data_o = vlSelfRef.cdc_2phase__DOT__i_dst__DOT__data_dst_q;
    vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q1 = 
        ((IData)(vlSelfRef.dst_rst_ni) && (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q0));
    vlSelfRef.dst_valid_o = ((IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__ack_dst_q) 
                             != (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q1));
    vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q0 = 
        ((IData)(vlSelfRef.dst_rst_ni) && (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_dst_q));
    vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_dst_q 
        = ((IData)(vlSelfRef.dst_rst_ni) && (IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__req_src_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__8(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__8\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ prim_fifo_async_sram_adapter__DOT__r_wptr;
    prim_fifo_async_sram_adapter__DOT__r_wptr = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__unused_decsub_msb = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni) {
        if (((IData)(vlSelfRef.r_sram_gnt_i) & (IData)(vlSelfRef.r_sram_req_o))) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr)));
        }
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 1U;
        } else if (((~ (IData)(vlSelfRef.r_sram_rvalid_i)) 
                    & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q = 0U;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 0U;
        }
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d;
        }
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q;
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq = 0U;
    }
    vlSelfRef.r_sram_addr_o = (0x0000000fU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
            ? vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q
            : vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d);
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval 
        = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__unused_decsub_msb = 0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp = 0U;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0 
        = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval) 
                 >> 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp 
        = ((0x17U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp)) 
           | ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0) 
              << 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp) 
                  >> 3U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval) 
                            >> 2U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp 
        = ((0x1bU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp)) 
           | ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0) 
              << 2U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp) 
                  >> 2U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval) 
                            >> 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp 
        = ((0x1dU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp)) 
           | ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0) 
              << 1U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp 
        = ((0x1eU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp)) 
           | (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1____Vlvbound_hb4cc09bd__0));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp_sub 
        = (0x0000001fU & (((IData)(0x10U) - (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp)) 
                          - (IData)(1U)));
    if ((0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__grayval))) {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp_sub;
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__Vfuncout 
            = (0x00000010U | (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__Vfuncout));
        __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp_sub) 
                     >> 4U));
    } else {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__dec_tmp;
    }
    prim_fifo_async_sram_adapter__DOT__r_wptr = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__Vfuncout;
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.rdepth_o = (0x0000001fU & (((1U & ((IData)(prim_fifo_async_sram_adapter__DOT__r_wptr) 
                                                 >> 4U)) 
                                          == (1U & 
                                              ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                               >> 4U)))
                                          ? ((0x0000000fU 
                                              & (IData)(prim_fifo_async_sram_adapter__DOT__r_wptr)) 
                                             - (0x0000000fU 
                                                & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)))
                                          : ((0x00000010U 
                                              | (0x0000000fU 
                                                 & (IData)(prim_fifo_async_sram_adapter__DOT__r_wptr))) 
                                             - (0x0000000fU 
                                                & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)))));
    vlSelfRef.r_full_o = ((IData)(prim_fifo_async_sram_adapter__DOT__r_wptr) 
                          == (0x10U ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr) 
           != (IData)(prim_fifo_async_sram_adapter__DOT__r_wptr));
}

extern const VlUnpacked<CData/*0:0*/, 512> Vtop_pkg__ConstPool__TABLE_hec7b0556_0;
extern const VlUnpacked<CData/*3:0*/, 512> Vtop_pkg__ConstPool__TABLE_hf7248577_0;

void Vtop_pkg___024root___nba_sequent__TOP__9(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__9\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vdly__prim_lifo__DOT__pointer;
    __Vdly__prim_lifo__DOT__pointer = 0;
    CData/*7:0*/ __VdlyVal__prim_lifo__DOT__lifo_stored__v0;
    __VdlyVal__prim_lifo__DOT__lifo_stored__v0 = 0;
    CData/*3:0*/ __VdlyDim0__prim_lifo__DOT__lifo_stored__v0;
    __VdlyDim0__prim_lifo__DOT__lifo_stored__v0 = 0;
    CData/*0:0*/ __VdlySet__prim_lifo__DOT__lifo_stored__v0;
    __VdlySet__prim_lifo__DOT__lifo_stored__v0 = 0;
    CData/*0:0*/ __VdlySet__prim_lifo__DOT__lifo_stored__v1;
    __VdlySet__prim_lifo__DOT__lifo_stored__v1 = 0;
    // Body
    __VdlySet__prim_lifo__DOT__lifo_stored__v0 = 0U;
    __VdlySet__prim_lifo__DOT__lifo_stored__v1 = 0U;
    __Vdly__prim_lifo__DOT__pointer = vlSelfRef.prim_lifo__DOT__pointer;
    __Vtableidx1 = ((((IData)(vlSelfRef.lifo_empty_o) 
                      << 8U) | ((IData)(vlSelfRef.prim_lifo__DOT__pointer) 
                                << 4U)) | ((((IData)(vlSelfRef.lifo_full_o) 
                                             << 3U) 
                                            | ((IData)(vlSelfRef.prim_lifo__DOT__wr_en) 
                                               << 2U)) 
                                           | (((IData)(vlSelfRef.prim_lifo__DOT__rd_en) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.prim_lifo__02Erst_ni))));
    if (vlSelfRef.prim_lifo__02Erst_ni) {
        if (((IData)(vlSelfRef.prim_lifo__DOT__wr_en) 
             & (~ (IData)(vlSelfRef.lifo_full_o)))) {
            vlSelfRef.prim_lifo__DOT____Vlvbound_hd0f2e51d__0 
                = vlSelfRef.prim_lifo__02Ewdata_i;
            if ((0x0bU >= (IData)(vlSelfRef.prim_lifo__DOT__pointer))) {
                __VdlyVal__prim_lifo__DOT__lifo_stored__v0 
                    = vlSelfRef.prim_lifo__DOT____Vlvbound_hd0f2e51d__0;
                __VdlyDim0__prim_lifo__DOT__lifo_stored__v0 
                    = vlSelfRef.prim_lifo__DOT__pointer;
                __VdlySet__prim_lifo__DOT__lifo_stored__v0 = 1U;
            }
        }
        if (((IData)(vlSelfRef.prim_lifo__DOT__rd_en) 
             & (~ (IData)(vlSelfRef.lifo_empty_o)))) {
            vlSelfRef.prim_lifo__02Erdata_o = ((0x0bU 
                                                >= 
                                                (0x0000000fU 
                                                 & ((IData)(vlSelfRef.prim_lifo__DOT__pointer) 
                                                    - (IData)(1U))))
                                                ? vlSelfRef.prim_lifo__DOT__lifo_stored
                                               [(0x0000000fU 
                                                 & ((IData)(vlSelfRef.prim_lifo__DOT__pointer) 
                                                    - (IData)(1U)))]
                                                : 0U);
        } else if ((((IData)(vlSelfRef.prim_lifo__02Ewvalid_i) 
                     & (IData)(vlSelfRef.prim_lifo__02Erready_i)) 
                    & (IData)(vlSelfRef.lifo_empty_o))) {
            vlSelfRef.prim_lifo__02Erdata_o = vlSelfRef.prim_lifo__02Ewdata_i;
        }
        if (vlSelfRef.prim_lifo__DOT__rd_en) {
            vlSelfRef.lifo_full_o = 0U;
        } else if (((0x0bU == (IData)(vlSelfRef.prim_lifo__DOT__pointer)) 
                    & (IData)(vlSelfRef.prim_lifo__DOT__wr_en))) {
            vlSelfRef.lifo_full_o = 1U;
        }
    } else {
        __VdlySet__prim_lifo__DOT__lifo_stored__v1 = 1U;
        vlSelfRef.prim_lifo__02Erdata_o = 0U;
        vlSelfRef.lifo_full_o = 0U;
    }
    if (Vtop_pkg__ConstPool__TABLE_hec7b0556_0[__Vtableidx1]) {
        __Vdly__prim_lifo__DOT__pointer = Vtop_pkg__ConstPool__TABLE_hf7248577_0
            [__Vtableidx1];
    }
    if (__VdlySet__prim_lifo__DOT__lifo_stored__v0) {
        vlSelfRef.prim_lifo__DOT__lifo_stored[__VdlyDim0__prim_lifo__DOT__lifo_stored__v0] 
            = __VdlyVal__prim_lifo__DOT__lifo_stored__v0;
    }
    if (__VdlySet__prim_lifo__DOT__lifo_stored__v1) {
        vlSelfRef.prim_lifo__DOT__lifo_stored[0U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[1U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[2U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[3U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[4U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[5U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[6U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[7U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[8U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[9U] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[0x0aU] = 0U;
        vlSelfRef.prim_lifo__DOT__lifo_stored[0x0bU] = 0U;
    }
    vlSelfRef.prim_lifo__DOT__pointer = __Vdly__prim_lifo__DOT__pointer;
    vlSelfRef.prim_lifo__02Ewready_o = (1U & (~ (IData)(vlSelfRef.lifo_full_o)));
    vlSelfRef.lifo_empty_o = (0U == (IData)(vlSelfRef.prim_lifo__DOT__pointer));
    vlSelfRef.prim_lifo__DOT__wr_en = ((IData)(vlSelfRef.prim_lifo__02Ewready_o) 
                                       & (IData)(vlSelfRef.prim_lifo__02Ewvalid_i));
    vlSelfRef.prim_lifo__02Ervalid_o = (1U & (~ (IData)(vlSelfRef.lifo_empty_o)));
    vlSelfRef.prim_lifo__DOT__rd_en = ((IData)(vlSelfRef.prim_lifo__02Erready_i) 
                                       & (IData)(vlSelfRef.prim_lifo__02Ervalid_o));
}

void Vtop_pkg___024root___nba_sequent__TOP__10(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__10\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*106:0*/ __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    VL_ZERO_W(107, __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0);
    CData/*1:0*/ __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0;
    CData/*0:0*/ __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0;
    // Body
    __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0U;
    if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[0U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                << 0x0000001fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[0U] 
                                   >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[1U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                << 0x0000001fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                                   >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[2U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                << 0x0000001fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                                   >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[3U] 
            = (0x000007ffU & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                              >> 1U));
        __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 
            = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
        __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 1U;
    }
    if (__VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0) {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][0U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[0U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][1U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[1U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][2U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[2U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][3U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[3U];
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__11(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__11\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*63:0*/ __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    CData/*0:0*/ __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    // Body
    __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0U;
    if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr) {
        __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 
            = (((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[2U])) 
                << 0x0000003fU) | (((QData)((IData)(
                                                    vlSelfRef.tlul_fifo_async__02Etl_d_i[1U])) 
                                    << 0x0000001fU) 
                                   | ((QData)((IData)(
                                                      vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])) 
                                      >> 1U)));
        __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 
            = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
        __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 1U;
    }
    if (__VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0) {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0] 
            = __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__12(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__12\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v0;
    __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v0 = 0;
    CData/*0:0*/ __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v0;
    __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v0 = 0;
    CData/*3:0*/ __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v1;
    __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v1 = 0;
    CData/*0:0*/ __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v2;
    __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v2 = 0;
    // Body
    __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v0 = 0U;
    __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v2 = 0U;
    vlSelfRef.__VdlySet__prim_fifo__DOT__fifo_stored__v0 = 0U;
    vlSelfRef.__VdlySet__prim_fifo__DOT__fifo_stored__v1 = 0U;
    if (vlSelfRef.prim_fifo__02Erst_ni) {
        __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v0 
            = vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync
            [0U];
        __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v0 = 1U;
        __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v1 
            = vlSelfRef.prim_fifo__DOT__rd_gray_pointer;
        if (((IData)(vlSelfRef.prim_fifo__02Ewvalid_i) 
             & (~ (IData)(vlSelfRef.fifo_full)))) {
            vlSelfRef.prim_fifo__DOT____Vlvbound_h2c7b1089__0 
                = vlSelfRef.prim_fifo__02Ewdata_i;
            if ((0x0bU >= (IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer))) {
                vlSelfRef.__VdlyVal__prim_fifo__DOT__fifo_stored__v0 
                    = vlSelfRef.prim_fifo__DOT____Vlvbound_h2c7b1089__0;
                vlSelfRef.__VdlyDim0__prim_fifo__DOT__fifo_stored__v0 
                    = vlSelfRef.prim_fifo__DOT__wr_binary_pointer;
                vlSelfRef.__VdlySet__prim_fifo__DOT__fifo_stored__v0 = 1U;
            }
        }
        if ((((IData)(vlSelfRef.prim_fifo__02Ewvalid_i) 
              & (~ (IData)(vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr))) 
             | ((IData)(vlSelfRef.fifo_full) & (~ (IData)(vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr))))) {
            vlSelfRef.prim_fifo__DOT__wr_binary_pointer 
                = vlSelfRef.prim_fifo__DOT__wr_binary_pointer_next;
        }
    } else {
        __VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v2 = 1U;
        vlSelfRef.__VdlySet__prim_fifo__DOT__fifo_stored__v1 = 1U;
        vlSelfRef.prim_fifo__DOT__wr_binary_pointer = 0U;
    }
    if (__VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v0) {
        vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync[1U] 
            = __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v0;
        vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync[0U] 
            = __VdlyVal__prim_fifo__DOT__rd_gray_pointer_sync__v1;
    }
    if (__VdlySet__prim_fifo__DOT__rd_gray_pointer_sync__v2) {
        vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync[1U] = 0U;
        vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync[0U] = 0U;
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__13(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__13\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_adapter_sram__02Erst_ni) {
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni)))) {
        vlSelfRef.tlul_adapter_sram__DOT__intg_error_q = 0U;
    }
    vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q 
        = ((IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni) 
           && ((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
               & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)) 
                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                     >> 0x0000000cU))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.intg_error_o = vlSelfRef.tlul_adapter_sram__DOT__intg_error_q;
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0x0000000cU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o)));
    vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0 
        = (((IData)(vlSelfRef.gnt_i) | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
           & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
           & (IData)(vlSelfRef.rvalid_i));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg___024root___nba_sequent__TOP__14(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__14\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v0;
    __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v0 = 0;
    CData/*0:0*/ __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v0;
    __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v0 = 0;
    CData/*3:0*/ __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v1;
    __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v1 = 0;
    CData/*0:0*/ __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v2;
    __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v2 = 0;
    // Body
    __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v0 = 0U;
    __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v2 = 0U;
    if (vlSelfRef.prim_fifo__02Erst_ni) {
        __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v0 
            = vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync
            [0U];
        __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v0 = 1U;
        __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v1 
            = vlSelfRef.prim_fifo__DOT__wr_gray_pointer;
        if (((IData)(vlSelfRef.prim_fifo__02Ervalid_o) 
             & (~ (IData)(vlSelfRef.fifo_empty)))) {
            vlSelfRef.prim_fifo__02Erdata_o = ((0x0bU 
                                                >= (IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer))
                                                ? vlSelfRef.prim_fifo__DOT__fifo_stored
                                               [vlSelfRef.prim_fifo__DOT__rd_binary_pointer]
                                                : 0U);
            vlSelfRef.prim_fifo__DOT__rd_gray_pointer 
                = (0x0000000fU & ((IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer_next) 
                                  ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer_next), 1U)));
            vlSelfRef.prim_fifo__DOT__rd_binary_pointer 
                = vlSelfRef.prim_fifo__DOT__rd_binary_pointer_next;
        }
    } else {
        __VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v2 = 1U;
        vlSelfRef.prim_fifo__02Erdata_o = 0U;
        vlSelfRef.prim_fifo__DOT__rd_gray_pointer = 0U;
        vlSelfRef.prim_fifo__DOT__rd_binary_pointer = 0U;
    }
    if (__VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v0) {
        vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync[1U] 
            = __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v0;
        vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync[0U] 
            = __VdlyVal__prim_fifo__DOT__wr_gray_pointer_sync__v1;
    }
    if (__VdlySet__prim_fifo__DOT__wr_gray_pointer_sync__v2) {
        vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync[1U] = 0U;
        vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync[0U] = 0U;
    }
    vlSelfRef.prim_fifo__DOT__rd_binary_pointer_next 
        = ((0x0bU == (IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer))
            ? 0U : (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer))));
    vlSelfRef.prim_fifo__02Ervalid_o = ((IData)(vlSelfRef.prim_fifo__02Erst_ni) 
                                        && ((~ (IData)(vlSelfRef.fifo_empty)) 
                                            & (IData)(vlSelfRef.prim_fifo__02Erready_i)));
    vlSelfRef.fifo_empty = (vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync
                            [1U] == (IData)(vlSelfRef.prim_fifo__DOT__rd_gray_pointer));
}

void Vtop_pkg___024root___nba_sequent__TOP__15(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__15\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if (vlSelfRef.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)) 
             & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o))) {
            vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask 
                = (0x0000000fU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U));
        } else if (((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i)) 
                    & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)))) {
            vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask 
                = vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out;
        }
    } else {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask = 0U;
    }
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg___024root___nba_sequent__TOP__16(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__16\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    // Body
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i 
        = ((((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
             << 3U) | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                       << 2U)) | (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o) 
                                   << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__rvalid_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i))) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req 
        = ((0U != (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req))
            ? (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req)
            : (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    __VdfgRegularize_h6e95ff9d_0_4 = (IData)((0U != 
                                              (3U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    __VdfgRegularize_h6e95ff9d_0_5 = (1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                            | ((IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req) 
                                               >> 2U)));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = (((((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
              | ((IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req) 
                 >> 3U)) << 3U) | ((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                                   << 2U)) | (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                               << 1U) 
                                              | (1U 
                                                 & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner 
        = (0x0000000fU & ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                          ^ VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U)));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)
            ? (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner)
            : 0U);
}

void Vtop_pkg___024root___nba_sequent__TOP__17(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__17\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vdly__tlul_socket_1n__DOT__num_req_outstanding;
    __Vdly__tlul_socket_1n__DOT__num_req_outstanding = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
        = vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__accept_t_req) {
            if ((1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp)))) {
                __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
                    = (0x000001ffU & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)));
            }
            vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding 
                = (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]);
        } else if (vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp) {
            __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
                = (0x000001ffU & ((IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding) 
                                  - (IData)(1U)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
             & vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[0U])) {
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 0U;
        } else if ((IData)(((vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
                             >> 0x0000000cU) & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]))) {
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 1U;
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source 
                = (0x000000ffU & ((vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
                                   << 4U) | (vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode 
                = (7U & (vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
                         >> 9U));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size 
                = (3U & (vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
                         >> 4U));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type 
                = (0x0000000fU & (vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[0U] 
                                  >> 0x0000000fU));
        }
    } else {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__num_req_outstanding = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode = 4U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type = 9U;
        vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding = 0U;
    }
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding 
        = __Vdly__tlul_socket_1n__DOT__num_req_outstanding;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0xfe00ffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (0xffff0000U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source) 
                             << 0x00000011U)));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0x01ffffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (0xfe000000U & ((((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                                ? 1U : 0U) << 0x0000001eU) 
                             | ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size) 
                                << 0x00000019U))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U] 
        = ((2U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U]) 
           | (3U & ((0x01ffffffU & (((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                                      ? 1U : 0U) >> 2U)) 
                    | ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size) 
                       >> 7U))));
    VL_ASSIGNSEL_WI(66, 32, 0x00000010U, vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int, 
                    (([&]() {
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__26__val 
                        = vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type;
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__26__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__26__val));
                }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__26__Vfuncout))
                      ? 0U : 0xffffffffU));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]) 
           | (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U] 
        = ((1U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U]) 
           | (3U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0x0000000cU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][0U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][1U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][2U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U];
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

void Vtop_pkg___024root___nba_sequent__TOP__18(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__18\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_rom__02Erdata_o = ((IData)(vlSelfRef.prim_rom__02Erst_ni)
                                       ? vlSelfRef.prim_rom__DOT__rom
                                      [vlSelfRef.prim_rom__02Eaddr_i]
                                       : 0U);
}

void Vtop_pkg___024root___nba_sequent__TOP__19(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__19\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.intr_o = ((IData)(vlSelfRef.prim_intr_hw__02Erst_ni) 
                        && ((IData)(vlSelfRef.reg2hw_intr_state_q_i) 
                            & (IData)(vlSelfRef.reg2hw_intr_enable_q_i)));
}

void Vtop_pkg___024root___nba_sequent__TOP__20(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__20\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_cdc_rand_delay__DOT__dst_internal 
        = ((IData)(vlSelfRef.prim_cdc_rand_delay__02Erst_ni) 
           & (IData)(vlSelfRef.prim_cdc_rand_delay__02Esrc_data_i));
    vlSelfRef.prim_cdc_rand_delay__02Edst_data_o = vlSelfRef.prim_cdc_rand_delay__DOT__dst_internal;
}

void Vtop_pkg___024root___nba_sequent__TOP__21(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__21\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_fifo_async_simple__DOT__wr_en) {
        vlSelfRef.prim_fifo_async_simple__DOT__data_q 
            = vlSelfRef.prim_fifo_async_simple__02Ewdata_i;
    }
    vlSelfRef.prim_fifo_async_simple__02Erdata_o = vlSelfRef.prim_fifo_async_simple__DOT__data_q;
}

void Vtop_pkg___024root___nba_sequent__TOP__22(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__22\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_edge_detect__DOT__serial_q = ((IData)(vlSelfRef.prim_edge_detect__02Erst_ni) 
                                                 && (IData)(vlSelfRef.prim_edge_detect__02Eserial_i));
    vlSelfRef.r_edge_o = ((~ (IData)(vlSelfRef.prim_edge_detect__DOT__serial_q)) 
                          & (IData)(vlSelfRef.prim_edge_detect__02Eserial_i));
    vlSelfRef.f_edge_o = ((~ (IData)(vlSelfRef.prim_edge_detect__02Eserial_i)) 
                          & (IData)(vlSelfRef.prim_edge_detect__DOT__serial_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__23(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__23\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_filter__02Erst_ni) {
        vlSelfRef.prim_filter__DOT__stored_vector_q 
            = vlSelfRef.prim_filter__DOT__stored_vector_d;
        if (((0U == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)) 
             | (0x0fU == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)))) {
            vlSelfRef.prim_filter__DOT__stored_value_q 
                = vlSelfRef.prim_filter__02Efilter_i;
        }
    } else {
        vlSelfRef.prim_filter__DOT__stored_vector_q = 0U;
        vlSelfRef.prim_filter__DOT__stored_value_q = 0U;
    }
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0x0000000eU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_filter__02Efilter_o = ((IData)(vlSelfRef.prim_filter__02Eenable_i)
                                           ? (IData)(vlSelfRef.prim_filter__DOT__stored_value_q)
                                           : (IData)(vlSelfRef.prim_filter__02Efilter_i));
}

void Vtop_pkg___024root___nba_sequent__TOP__24(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__24\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_filter_ctr__DOT__filter_q = ((IData)(vlSelfRef.prim_filter_ctr__02Erst_ni) 
                                                && (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
    if (vlSelfRef.prim_filter_ctr__02Erst_ni) {
        vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q 
            = vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d;
        if (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d) 
             == (IData)(vlSelfRef.thresh_i))) {
            vlSelfRef.prim_filter_ctr__DOT__stored_value_q 
                = vlSelfRef.prim_filter_ctr__02Efilter_i;
        }
    } else {
        vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q = 0U;
        vlSelfRef.prim_filter_ctr__DOT__stored_value_q = 0U;
    }
    vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d = (((IData)(vlSelfRef.prim_filter_ctr__02Efilter_i) 
                                                   == (IData)(vlSelfRef.prim_filter_ctr__DOT__filter_q))
                                                   ? 
                                                  (3U 
                                                   & (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q) 
                                                       >= (IData)(vlSelfRef.thresh_i))
                                                       ? (IData)(vlSelfRef.thresh_i)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q))))
                                                   : 0U);
    vlSelfRef.prim_filter_ctr__02Efilter_o = ((IData)(vlSelfRef.prim_filter_ctr__02Eenable_i)
                                               ? (IData)(vlSelfRef.prim_filter_ctr__DOT__stored_value_q)
                                               : (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
}

void Vtop_pkg___024root___nba_sequent__TOP__25(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__25\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ rrarbiter__DOT__next_idx;
    rrarbiter__DOT__next_idx = 0;
    CData/*0:0*/ rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__;
    rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__ = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_0;
    __VdfgRegularize_he50b618e_0_0 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_1;
    __VdfgRegularize_he50b618e_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_2;
    __VdfgRegularize_he50b618e_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_3;
    __VdfgRegularize_he50b618e_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_5;
    __VdfgRegularize_he50b618e_0_5 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_6;
    __VdfgRegularize_he50b618e_0_6 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_7;
    __VdfgRegularize_he50b618e_0_7 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_9;
    __VdfgRegularize_he50b618e_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_10;
    __VdfgRegularize_he50b618e_0_10 = 0;
    CData/*0:0*/ __VdfgRegularize_he50b618e_0_11;
    __VdfgRegularize_he50b618e_0_11 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_1;
    __VdfgRegularize_h6e95ff9d_0_1 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    // Body
    vlSelfRef.rrarbiter__DOT__lock_q = 0U;
    vlSelfRef.rrarbiter__DOT__arb_sel_lock_q = 0U;
    if (vlSelfRef.rrarbiter__02Erst_ni) {
        if (vlSelfRef.flush_i) {
            vlSelfRef.rrarbiter__DOT__arb_sel_q = 0U;
        } else if (vlSelfRef.vld_o) {
            vlSelfRef.rrarbiter__DOT__arb_sel_q = vlSelfRef.idx_o;
        }
    } else {
        vlSelfRef.rrarbiter__DOT__arb_sel_q = 0U;
    }
    vlSelfRef.rrarbiter__DOT__mask = ((0x0cU >= (IData)(vlSelfRef.rrarbiter__DOT__arb_sel_q))
                                       ? vlSelfRef.rrarbiter__DOT__mask_lut
                                      [vlSelfRef.rrarbiter__DOT__arb_sel_q]
                                       : 0U);
    __VdfgRegularize_he50b618e_0_11 = (1U & ((~ (IData)(vlSelfRef.rrarbiter__DOT__mask)) 
                                             & (IData)(vlSelfRef.rrarbiter__02Ereq_i)));
    __VdfgRegularize_he50b618e_0_7 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 4U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 4U)));
    __VdfgRegularize_he50b618e_0_3 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 8U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 8U)));
    __VdfgRegularize_he50b618e_0_1 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 0x0000000aU)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 0x0000000aU)));
    rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__ 
        = (IData)(((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                       >> 0x0000000cU)) & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                           >> 0x0000000cU)));
    __VdfgRegularize_he50b618e_0_0 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 0x0000000bU)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 0x0000000bU)));
    __VdfgRegularize_he50b618e_0_2 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 9U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 9U)));
    __VdfgRegularize_he50b618e_0_10 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                 >> 1U)) 
                                             & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                                >> 1U)));
    __VdfgRegularize_he50b618e_0_9 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 2U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 2U)));
    __VdfgRegularize_he50b618e_0_6 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 5U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 5U)));
    __VdfgRegularize_he50b618e_0_5 = (1U & ((~ ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                >> 6U)) 
                                            & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                               >> 6U)));
    __VdfgRegularize_h6e95ff9d_0_2 = (1U & ((IData)(__VdfgRegularize_he50b618e_0_10) 
                                            | ((IData)(__VdfgRegularize_he50b618e_0_9) 
                                               | ((~ 
                                                   ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                    >> 3U)) 
                                                  & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                                     >> 3U)))));
    __VdfgRegularize_h6e95ff9d_0_1 = (1U & ((IData)(__VdfgRegularize_he50b618e_0_6) 
                                            | ((IData)(__VdfgRegularize_he50b618e_0_5) 
                                               | ((~ 
                                                   ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                    >> 7U)) 
                                                  & ((IData)(vlSelfRef.rrarbiter__02Ereq_i) 
                                                     >> 7U)))));
    rrarbiter__DOT__next_idx = ((((IData)(__VdfgRegularize_he50b618e_0_11) 
                                  | (IData)(__VdfgRegularize_h6e95ff9d_0_2)) 
                                 | (((IData)(__VdfgRegularize_he50b618e_0_7) 
                                     | (IData)(__VdfgRegularize_h6e95ff9d_0_1)) 
                                    | (((IData)(__VdfgRegularize_he50b618e_0_3) 
                                        | (IData)(__VdfgRegularize_he50b618e_0_2)) 
                                       | (((IData)(__VdfgRegularize_he50b618e_0_1) 
                                           | (IData)(__VdfgRegularize_he50b618e_0_0)) 
                                          | (IData)(rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__)))))
                                 ? ((IData)(__VdfgRegularize_he50b618e_0_11)
                                     ? 0U : ((IData)(__VdfgRegularize_h6e95ff9d_0_2)
                                              ? ((IData)(__VdfgRegularize_he50b618e_0_10)
                                                  ? 1U
                                                  : 
                                                 ((IData)(__VdfgRegularize_he50b618e_0_9)
                                                   ? 2U
                                                   : 3U))
                                              : ((IData)(__VdfgRegularize_he50b618e_0_7)
                                                  ? 4U
                                                  : 
                                                 ((IData)(__VdfgRegularize_h6e95ff9d_0_1)
                                                   ? 
                                                  ((IData)(__VdfgRegularize_he50b618e_0_6)
                                                    ? 5U
                                                    : 
                                                   ((IData)(__VdfgRegularize_he50b618e_0_5)
                                                     ? 6U
                                                     : 7U))
                                                   : 
                                                  ((IData)(__VdfgRegularize_he50b618e_0_3)
                                                    ? 8U
                                                    : 
                                                   ((IData)(__VdfgRegularize_he50b618e_0_2)
                                                     ? 9U
                                                     : 
                                                    ((IData)(__VdfgRegularize_he50b618e_0_1)
                                                      ? 0x0aU
                                                      : 
                                                     ((IData)(__VdfgRegularize_he50b618e_0_0)
                                                       ? 0x0bU
                                                       : 
                                                      ((IData)(rrarbiter__DOT__genblk2__DOT__i_lower_ff1__DOT__sel_nodes__BRA__13__KET__)
                                                        ? 0x0cU
                                                        : 0U)))))))))
                                 : ((1U & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                           & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                     ? 0U : ((2U & 
                                              ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                               & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                              ? 1U : 
                                             ((4U & 
                                               ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                               ? 2U
                                               : ((8U 
                                                   & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                      & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                   ? 3U
                                                   : 
                                                  ((0x00000010U 
                                                    & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                       & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                    ? 4U
                                                    : 
                                                   ((0x00000020U 
                                                     & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                        & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                     ? 5U
                                                     : 
                                                    ((0x00000040U 
                                                      & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                         & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                      ? 6U
                                                      : 
                                                     ((0x00000080U 
                                                       & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                          & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                       ? 7U
                                                       : 
                                                      ((0x00000100U 
                                                        & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                           & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                        ? 8U
                                                        : 
                                                       ((0x00000200U 
                                                         & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                            & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                         ? 9U
                                                         : 
                                                        ((0x00000400U 
                                                          & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                             & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                          ? 0x0aU
                                                          : 
                                                         ((0x00000800U 
                                                           & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                              & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                           ? 0x0bU
                                                           : 
                                                          ((0x00001000U 
                                                            & ((IData)(vlSelfRef.rrarbiter__DOT__mask) 
                                                               & (IData)(vlSelfRef.rrarbiter__02Ereq_i)))
                                                            ? 0x0cU
                                                            : 0U))))))))))))));
    vlSelfRef.idx_o = (0x0000000fU & ((IData)(vlSelfRef.rrarbiter__DOT__lock_q)
                                       ? (IData)(vlSelfRef.rrarbiter__DOT__arb_sel_lock_q)
                                       : ((0x0dU > (IData)(rrarbiter__DOT__next_idx))
                                           ? (IData)(rrarbiter__DOT__next_idx)
                                           : 0x0000000cU)));
    __Vtableidx4 = (((IData)(vlSelfRef.vld_o) << 4U) 
                    | (IData)(vlSelfRef.idx_o));
    vlSelfRef.ack_o = Vtop_pkg__ConstPool__TABLE_hdd797092_0
        [__Vtableidx4];
}

void Vtop_pkg___024root___nba_sequent__TOP__26(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__26\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q 
        = vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni;
    vlSelfRef.prim_fifo_async_simple__DOT__pending_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_d));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq));
    vlSelfRef.prim_fifo_async_simple__02Ewready_o = 
        ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q));
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i));
}

void Vtop_pkg___024root___nba_sequent__TOP__27(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__27\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_counter__DOT__count_q = ((IData)(vlSelfRef.prim_counter__02Erst_ni)
                                             ? (IData)(vlSelfRef.prim_counter__DOT__count_d)
                                             : 0U);
    vlSelfRef.val_o = (0x0000000fU & (IData)(vlSelfRef.prim_counter__DOT__count_q));
    vlSelfRef.prim_counter__DOT__count_d = ((IData)(vlSelfRef.clr_i)
                                             ? 0U : 
                                            (0x0000001fU 
                                             & ((IData)(vlSelfRef.prim_counter__02Een_i)
                                                 ? 
                                                (((~ (IData)(vlSelfRef.up_down_i)) 
                                                  & ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                     >> 4U))
                                                  ? 0U
                                                  : 
                                                 (((IData)(vlSelfRef.up_down_i) 
                                                   & ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                      >> 4U))
                                                   ? 0x0fU
                                                   : 
                                                  ((IData)(vlSelfRef.up_down_i)
                                                    ? 
                                                   ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                    + (IData)(vlSelfRef.step_i))
                                                    : 
                                                   ((IData)(vlSelfRef.prim_counter__DOT__count_q) 
                                                    - (IData)(vlSelfRef.step_i)))))
                                                 : (IData)(vlSelfRef.prim_counter__DOT__count_q))));
    vlSelfRef.tc_o = ((IData)(vlSelfRef.tc_val_i) == (IData)(vlSelfRef.val_o));
}

void Vtop_pkg___024root___nba_sequent__TOP__28(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__28\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q 
        = ((IData)(vlSelfRef.tlul_adapter_host__02Erst_ni) 
           && (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d));
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = (1U & (((IData)(vlSelfRef.gnt_o) & (IData)(vlSelfRef.tlul_adapter_host__02Ereq_i))
                  ? ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)))
                  : (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = (IData)(
                                                       (((QData)((IData)(
                                                                         ((IData)(vlSelfRef.tlul_adapter_host__02Ewe_i)
                                                                           ? (IData)(vlSelfRef.be_i)
                                                                           : 0x0fU))) 
                                                         << 0x00000038U) 
                                                        | (((QData)((IData)(vlSelfRef.tlul_adapter_host__02Ewdata_i)) 
                                                            << 0x00000018U) 
                                                           | (QData)((IData)(
                                                                             (1U 
                                                                              | (((IData)(vlSelfRef.instr_type_i) 
                                                                                << 0x0000000fU) 
                                                                                | ((IData)(vlSelfRef.wdata_intg_i) 
                                                                                << 1U))))))));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0xc0000000U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | (IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelfRef.tlul_adapter_host__02Ewe_i)
                                                                               ? (IData)(vlSelfRef.be_i)
                                                                               : 0x0fU))) 
                                                             << 0x00000038U) 
                                                            | (((QData)((IData)(vlSelfRef.tlul_adapter_host__02Ewdata_i)) 
                                                                << 0x00000018U) 
                                                               | (QData)((IData)(
                                                                                (1U 
                                                                                | (((IData)(vlSelfRef.instr_type_i) 
                                                                                << 0x0000000fU) 
                                                                                | ((IData)(vlSelfRef.wdata_intg_i) 
                                                                                << 1U))))))) 
                                                           >> 0x00000020U)));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0x3fffffffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | ((IData)(
                                                           (0x0000008000000000ULL 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                                << 0x0000001eU) 
                                                                               | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U)))))) 
                                                   << 0x0000001eU));
    vlSelfRef.tlul_adapter_host__02Etl_o[2U] = (((IData)(
                                                         (0x0000008000000000ULL 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                              << 0x0000001eU) 
                                                                             | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U)))))) 
                                                 >> 2U) 
                                                | ((IData)(
                                                           ((0x0000008000000000ULL 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                                << 0x0000001eU) 
                                                                                | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U))))) 
                                                            >> 0x00000020U)) 
                                                   << 0x0000001eU));
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = ((0x00001e00U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[3U]) 
                                                | (0x00001fffU 
                                                   & ((IData)(
                                                              ((0x0000008000000000ULL 
                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q) 
                                                                                << 0x0000001eU) 
                                                                                | (vlSelfRef.tlul_adapter_host__02Eaddr_i 
                                                                                >> 2U))))) 
                                                               >> 0x00000020U)) 
                                                      >> 2U)));
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = ((0x000001ffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[3U]) 
                                                | (0x00001e00U 
                                                   & (((IData)(vlSelfRef.tlul_adapter_host__02Ereq_i) 
                                                       << 0x0000000cU) 
                                                      | (((IData)(vlSelfRef.tlul_adapter_host__02Ewe_i)
                                                           ? 
                                                          ((0x0000000fU 
                                                            == (IData)(vlSelfRef.be_i))
                                                            ? 0U
                                                            : 1U)
                                                           : 4U) 
                                                         << 9U))));
}

void Vtop_pkg___024root___nba_sequent__TOP__29(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__29\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_reg__02Erst_ni) {
        if (vlSelfRef.qe) {
            vlSelfRef.q = vlSelfRef.prim_reg__DOT__wr_data;
        }
    } else {
        vlSelfRef.q = 0U;
    }
    vlSelfRef.qs = vlSelfRef.q;
    vlSelfRef.ds = ((IData)(vlSelfRef.qe) ? vlSelfRef.prim_reg__DOT__wr_data
                     : vlSelfRef.q);
}

void Vtop_pkg___024root___nba_sequent__TOP__30(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__30\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
    }
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__31(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__31\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[0U]);
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]) 
               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[1U]));
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]) 
               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[2U]));
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]) 
               | (0x00000ffeU & vlSelfRef.tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o[3U]));
    }
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__32(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__32\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7;
    my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 = 0;
    CData/*0:0*/ my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o;
    my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o = 0;
    // Body
    if (vlSelfRef.my_ip__02Erst_ni) {
        if (vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__wr_en) {
            if (vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__wr_en) {
                vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q 
                    = (1U & (vlSelfRef.my_ip__02Etl_i[0U] 
                             >> 0x00000018U));
                vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q 
                    = (1U & (vlSelfRef.my_ip__02Etl_i[0U] 
                             >> 0x00000019U));
                vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q 
                    = (0x0000ffffU & (vlSelfRef.my_ip__02Etl_i[1U] 
                                      >> 8U));
            } else {
                vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q = 0U;
                vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q = 0U;
                vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q = 0U;
            }
        }
        if (vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) {
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q 
                = (0x000000ffU & ((vlSelfRef.my_ip__02Etl_i[3U] 
                                   << 4U) | (vlSelfRef.my_ip__02Etl_i[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q 
                = (3U & (vlSelfRef.my_ip__02Etl_i[3U] 
                         >> 4U));
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q 
                = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req)
                    ? 1U : 0U);
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q 
                = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error) 
                   | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal));
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q 
                = ((((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error) 
                     | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
                    | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req))
                    ? 0xffffffffU : vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next);
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = 1U;
        } else if (vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack) {
            vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        }
    } else {
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q = 0U;
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
    }
    vlSelfRef.port_o = ((IData)(vlSelfRef.my_ip__02Erst_ni) 
                        && (IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) {
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((0xfffffffcU & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q) 
                   << 1U) | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q)));
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((0x0000ffffU & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q) 
                  << 0x00000010U));
    } else {
        vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next 
            = ((2U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                ? ((0xfffffffcU & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
                   | (((IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__status_empty) 
                       << 1U) | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__status_full)))
                : ((4U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                    ? ((0xffffff00U & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next) 
                       | (IData)(vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__rdata))
                    : ((8U & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))
                        ? (0xffffff00U & vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next)
                        : 0xffffffffU)));
    }
    vlSelfRef.my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq 
        = ((IData)(vlSelfRef.my_ip__02Erst_ni) && (IData)(vlSelfRef.port_i));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
           & vlSelfRef.my_ip__02Etl_i[0U]);
    vlSelfRef.my_ip__02Etl_o[0U] = (IData)((((QData)((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                             << 0x00000039U) 
                                            | (((QData)((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                << 0x00000031U) 
                                               | (((QData)((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                   << 0x00000010U) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                      << 1U) 
                                                                     | (1U 
                                                                        & (~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q))))))))));
    vlSelfRef.my_ip__02Etl_o[1U] = ((0xc0000000U & 
                                     vlSelfRef.my_ip__02Etl_o[1U]) 
                                    | (IData)(((((QData)((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                 << 0x00000039U) 
                                                | (((QData)((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                    << 0x00000031U) 
                                                   | (((QData)((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                       << 0x00000010U) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                          << 1U) 
                                                                         | (1U 
                                                                            & (~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q))))))))) 
                                               >> 0x00000020U)));
    vlSelfRef.my_ip__02Etl_o[1U] = ((0x3fffffffU & 
                                     vlSelfRef.my_ip__02Etl_o[1U]) 
                                    | ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q) 
                                       << 0x0000001eU));
    vlSelfRef.my_ip__02Etl_o[2U] = (3U & ((0x3ffffffeU 
                                           & ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
                                              << 1U)) 
                                          | ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q) 
                                             >> 2U)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)) 
           & (vlSelfRef.my_ip__02Etl_i[3U] >> 0x0000000cU));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.my_ip__02Etl_i[3U])));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.my_ip__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.my_ip__02Etl_i[3U] 
                                                >> 9U)))));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.my_ip__02Etl_i[1U] 
                           >> 0x0000001cU))));
    my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error 
        = (((~ (0U != (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) 
            & (((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
                & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req)) 
               | (IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o))) 
           | ((IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o) 
              & (((0U == (vlSelfRef.my_ip__02Etl_i[1U] 
                          >> 0x0000001eU)) & (0U != 
                                              (0x0000000fU 
                                               & (~ 
                                                  ((vlSelfRef.my_ip__02Etl_i[1U] 
                                                    << 8U) 
                                                   | (vlSelfRef.my_ip__02Etl_i[1U] 
                                                      >> 0x00000018U)))))) 
                 | ((0U != (1U & (~ ((vlSelfRef.my_ip__02Etl_i[1U] 
                                      << 8U) | (vlSelfRef.my_ip__02Etl_i[1U] 
                                                >> 0x00000018U))))) 
                    & ((1U == (vlSelfRef.my_ip__02Etl_i[1U] 
                               >> 0x0000001eU)) | (
                                                   (2U 
                                                    == 
                                                    (vlSelfRef.my_ip__02Etl_i[1U] 
                                                     >> 0x0000001eU)) 
                                                   | (3U 
                                                      == 
                                                      (vlSelfRef.my_ip__02Etl_i[1U] 
                                                       >> 0x0000001eU))))))));
    my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error)) 
           & (IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((0U == (vlSelfRef.my_ip__02Etl_i[1U] >> 0x0000001eU)) 
           & (IData)(my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7));
}

void Vtop_pkg___024root___nba_sequent__TOP__33(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__33\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi;
    tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__grayval = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10____Vlvbound_h05b14091__0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10____Vlvbound_h05b14091__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__grayval = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15____Vlvbound_h05b14091__0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15____Vlvbound_h05b14091__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__unused_decsub_msb = 0;
    // Body
    if (vlSelfRef.rst_h_ni) {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi;
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq;
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q;
    } else {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp = 0U;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10____Vlvbound_h05b14091__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp)) 
           | ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10____Vlvbound_h05b14091__0) 
              << 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10____Vlvbound_h05b14091__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp)) 
           | (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10____Vlvbound_h05b14091__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp = 0U;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15____Vlvbound_h05b14091__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15____Vlvbound_h05b14091__0) 
              << 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15____Vlvbound_h05b14091__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp)) 
           | (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15____Vlvbound_h05b14091__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__dec_tmp;
    }
    tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
           != (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
           == (IData)(tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
}

void Vtop_pkg___024root___nba_sequent__TOP__34(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__34\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi;
    tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__grayval = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11____Vlvbound_h05b14091__0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11____Vlvbound_h05b14091__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__grayval = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14____Vlvbound_h05b14091__0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14____Vlvbound_h05b14091__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in = 0;
    // Body
    if (vlSelfRef.rst_d_ni) {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi;
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d;
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq;
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d;
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q;
    } else {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__12__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp = 0U;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14____Vlvbound_h05b14091__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp)) 
           | ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14____Vlvbound_h05b14091__0) 
              << 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14____Vlvbound_h05b14091__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp)) 
           | (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14____Vlvbound_h05b14091__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp = 0U;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11____Vlvbound_h05b14091__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp)) 
           | ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11____Vlvbound_h05b14091__0) 
              << 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11____Vlvbound_h05b14091__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp)) 
           | (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11____Vlvbound_h05b14091__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__dec_tmp;
    }
    tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
           != (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
           == (IData)(tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
}

void Vtop_pkg___024root___nba_sequent__TOP__35(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__35\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ prim_fifo_async_sram_adapter__DOT__w_rptr;
    prim_fifo_async_sram_adapter__DOT__w_rptr = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__unused_decsub_msb = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni) {
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d;
        }
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q;
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq = 0U;
    }
    vlSelfRef.w_sram_addr_o = (0x0000000fU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_sub 
        = (0x0000001fU & (((IData)(0x10U) - (0x0000000fU 
                                             & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval))) 
                          - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in 
        = ((0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in 
        = (0x0fU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout 
        = (0x0000001fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout) 
                          ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout 
        = ((0x0fU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout)) 
           | (0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval 
        = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__unused_decsub_msb = 0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp = 0U;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0 
        = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval) 
                 >> 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp 
        = ((0x17U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp)) 
           | ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0) 
              << 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp) 
                  >> 3U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval) 
                            >> 2U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp 
        = ((0x1bU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp)) 
           | ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0) 
              << 2U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp) 
                  >> 2U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval) 
                            >> 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp 
        = ((0x1dU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp)) 
           | ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0) 
              << 1U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp 
        = ((0x1eU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp)) 
           | (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3____Vlvbound_hb4cc09bd__0));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp_sub 
        = (0x0000001fU & (((IData)(0x10U) - (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp)) 
                          - (IData)(1U)));
    if ((0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__grayval))) {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp_sub;
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__Vfuncout 
            = (0x00000010U | (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__Vfuncout));
        __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp_sub) 
                     >> 4U));
    } else {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__dec_tmp;
    }
    prim_fifo_async_sram_adapter__DOT__w_rptr = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__Vfuncout;
    vlSelfRef.wdepth_o = (0x0000001fU & (((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                                                 >> 4U)) 
                                          == (1U & 
                                              ((IData)(prim_fifo_async_sram_adapter__DOT__w_rptr) 
                                               >> 4U)))
                                          ? ((0x0000000fU 
                                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)) 
                                             - (0x0000000fU 
                                                & (IData)(prim_fifo_async_sram_adapter__DOT__w_rptr)))
                                          : ((0x00000010U 
                                              | (0x0000000fU 
                                                 & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q))) 
                                             - (0x0000000fU 
                                                & (IData)(prim_fifo_async_sram_adapter__DOT__w_rptr)))));
    vlSelfRef.w_full_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                          == (0x10U ^ (IData)(prim_fifo_async_sram_adapter__DOT__w_rptr)));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
}

void Vtop_pkg___024root___nba_sequent__TOP__36(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__36\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage 
            = (0x0000001eU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                              >> 0x00000017U));
    }
    if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT____Vcellinp__u_rspfifo__wdata_i;
    }
    if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage 
            = ((((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                               >> 9U))) ? 1U : 0U) 
                << 0x0000000fU) | (((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
                                    << 0x0000000eU) 
                                   | (((IData)(vlSelfRef.req_type_o) 
                                       << 0x0000000aU) 
                                      | (0x000003ffU 
                                         & ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                               >> 0x0000001cU))))));
    }
}

void Vtop_pkg___024root___nba_sequent__TOP__37(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__37\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ prim_alert_sender__DOT__alert_trigger;
    prim_alert_sender__DOT__alert_trigger = 0;
    CData/*0:0*/ prim_alert_sender__DOT__u_decode_ping__DOT__rise_o;
    prim_alert_sender__DOT__u_decode_ping__DOT__rise_o = 0;
    CData/*0:0*/ prim_alert_sender__DOT__u_decode_ping__DOT__fall_o;
    prim_alert_sender__DOT__u_decode_ping__DOT__fall_o = 0;
    CData/*0:0*/ prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok;
    prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok = 0;
    CData/*0:0*/ prim_alert_sender__DOT__u_decode_ping__DOT____VdfgExtracted_h845d1838__0;
    prim_alert_sender__DOT__u_decode_ping__DOT____VdfgExtracted_h845d1838__0 = 0;
    CData/*0:0*/ prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok;
    prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok = 0;
    SData/*8:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    if (vlSelfRef.prim_alert_sender__02Erst_ni) {
        vlSelfRef.prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o 
            = (((IData)(vlSelfRef.prim_alert_sender__DOT__alert_nd) 
                << 1U) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_pd));
        vlSelfRef.prim_alert_sender__DOT__state_q = vlSelfRef.prim_alert_sender__DOT__state_d;
        vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q 
            = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d;
        vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q 
            = vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d;
    } else {
        vlSelfRef.prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o = 0U;
        vlSelfRef.prim_alert_sender__DOT__state_q = 0U;
        vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q = 0U;
        vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q = 0U;
    }
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_d));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_d));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_q 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d));
    vlSelfRef.prim_alert_sender__DOT__ping_set_q = 
        ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
         && ((~ (IData)(vlSelfRef.prim_alert_sender__DOT__ping_clr)) 
             & (IData)(vlSelfRef.prim_alert_sender__DOT__ping_trigger)));
    vlSelfRef.prim_alert_sender__DOT__alert_test_set_q 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && ((~ (IData)(vlSelfRef.prim_alert_sender__DOT__alert_clr)) 
               & (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_trigger)));
    vlSelfRef.prim_alert_sender__DOT__alert_set_q = 
        ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
         && ((~ (IData)(vlSelfRef.prim_alert_sender__DOT__alert_clr)) 
             & (IData)(vlSelfRef.prim_alert_sender__DOT__alert_req_trigger)));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_nd 
        = ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__02Erst_ni))) 
           || (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__i_sync_n__DOT__intq));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__i_sync_p__DOT__intq));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nq 
        = ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__02Erst_ni))) 
           || (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pq 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd));
    vlSelfRef.alert_tx_o = ((2U & ((IData)(vlSelfRef.prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o) 
                                   << 1U)) | (1U & 
                                              ((IData)(vlSelfRef.prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o) 
                                               >> 1U)));
    vlSelfRef.prim_alert_sender__DOT__alert_test_trigger 
        = ((IData)(vlSelfRef.alert_test_i) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_set_q));
    vlSelfRef.alert_state_o = vlSelfRef.prim_alert_sender__DOT__alert_set_q;
    vlSelfRef.prim_alert_sender__DOT__alert_req_trigger 
        = ((IData)(vlSelfRef.alert_req_i) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_set_q));
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q)) 
                                << 1U) | (0U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: prim_diff_decode.sv:126: Assertion failed in %Nprim_alert_sender.u_decode_ack.gen_async.p_diff_fsm: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),2,
                             (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q));
                VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_diff_decode.sv", 126, "");
            }
        }
    }
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__i_sync_n__DOT__intq 
        = ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__02Erst_ni))) 
           || (1U & (IData)(vlSelfRef.alert_rx_i)));
    if ((1U & (~ VL_ONEHOT_I((((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q)) 
                               << 2U) | (((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q)) 
                                          << 1U) | 
                                         (0U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q)))))))) {
        if ((0U != (((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q)) 
                     << 2U) | (((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q)) 
                                << 1U) | (0U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: prim_diff_decode.sv:126: Assertion failed in %Nprim_alert_sender.u_decode_ping.gen_async.p_diff_fsm: unique case, but multiple matches found for '2'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),2,
                             (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q));
                VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_diff_decode.sv", 126, "");
            }
        }
    }
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__i_sync_p__DOT__intq 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (1U & ((IData)(vlSelfRef.alert_rx_i) 
                     >> 1U)));
    prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok 
        = ((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_nd) 
           ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd 
        = ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__02Erst_ni))) 
           || (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__i_sync_n__DOT__intq));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__i_sync_p__DOT__intq));
    prim_alert_sender__DOT__alert_trigger = ((IData)(vlSelfRef.prim_alert_sender__DOT__alert_req_trigger) 
                                             | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_trigger));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_d 
        = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q;
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d 
        = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q;
    vlSelfRef.prim_alert_sender__DOT__ack_sigint = 0U;
    if ((0U != (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q))) {
        if ((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q))) {
            if ((1U & (~ (IData)(prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok)))) {
                if ((1U <= (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q))) {
                    vlSelfRef.prim_alert_sender__DOT__ack_sigint = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q))) {
            vlSelfRef.prim_alert_sender__DOT__ack_sigint = 1U;
            if (prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok) {
                vlSelfRef.prim_alert_sender__DOT__ack_sigint = 0U;
            }
        }
    }
    vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d 
        = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_q;
    if ((0U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q))) {
        if ((1U & (~ (IData)(prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok)))) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_d = 1U;
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d = 1U;
        }
        if (prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d 
                = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd;
        }
    } else if ((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q))) {
        vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_d 
            = ((1U & (~ (IData)(prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok))) 
               && ((1U > (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q)) 
                   && (1U & ((IData)(1U) + (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q)))));
        if (prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d = 0U;
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d 
                = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd;
        } else if ((1U <= (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q))) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d = 2U;
        }
    } else if ((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q))) {
        if (prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d = 0U;
            vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d 
                = vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd;
        }
    }
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__i_sync_n__DOT__intq 
        = ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__02Erst_ni))) 
           || (1U & ((IData)(vlSelfRef.alert_rx_i) 
                     >> 2U)));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__i_sync_p__DOT__intq 
        = ((IData)(vlSelfRef.prim_alert_sender__02Erst_ni) 
           && (1U & ((IData)(vlSelfRef.alert_rx_i) 
                     >> 3U)));
    prim_alert_sender__DOT__u_decode_ping__DOT____VdfgExtracted_h845d1838__0 
        = (((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd) 
            ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pq)) 
           & ((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd) 
              ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nq)));
    prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok 
        = ((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd) 
           ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd));
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_d 
        = vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q;
    vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d 
        = vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q;
    vlSelfRef.prim_alert_sender__DOT__ping_sigint = 0U;
    if ((0U != (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q))) {
        if ((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q))) {
            if ((1U & (~ (IData)(prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok)))) {
                if ((1U <= (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q))) {
                    vlSelfRef.prim_alert_sender__DOT__ping_sigint = 1U;
                }
            }
        } else if ((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q))) {
            vlSelfRef.prim_alert_sender__DOT__ping_sigint = 1U;
            if (prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok) {
                vlSelfRef.prim_alert_sender__DOT__ping_sigint = 0U;
            }
        }
    }
    prim_alert_sender__DOT__u_decode_ping__DOT__fall_o = 0U;
    prim_alert_sender__DOT__u_decode_ping__DOT__rise_o = 0U;
    if ((0U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q))) {
        if ((1U & (~ (IData)(prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok)))) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_d = 1U;
            vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d = 1U;
        }
        if (prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok) {
            if (prim_alert_sender__DOT__u_decode_ping__DOT____VdfgExtracted_h845d1838__0) {
                if ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd)))) {
                    prim_alert_sender__DOT__u_decode_ping__DOT__fall_o = 1U;
                }
                if (vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd) {
                    prim_alert_sender__DOT__u_decode_ping__DOT__rise_o = 1U;
                }
            }
        }
    } else if ((1U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q))) {
        vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_d 
            = ((1U & (~ (IData)(prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok))) 
               && ((1U > (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q)) 
                   && (1U & ((IData)(1U) + (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q)))));
        if (prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d = 0U;
            if ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd)))) {
                prim_alert_sender__DOT__u_decode_ping__DOT__fall_o = 1U;
            }
            if (vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd) {
                prim_alert_sender__DOT__u_decode_ping__DOT__rise_o = 1U;
            }
        } else if ((1U <= (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q))) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d = 2U;
        }
    } else if ((2U == (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q))) {
        if (prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok) {
            vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d = 0U;
            if ((1U & (~ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd)))) {
                prim_alert_sender__DOT__u_decode_ping__DOT__fall_o = 1U;
            }
            if (vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd) {
                prim_alert_sender__DOT__u_decode_ping__DOT__rise_o = 1U;
            }
        }
    }
    vlSelfRef.prim_alert_sender__DOT__ping_trigger 
        = (((IData)(prim_alert_sender__DOT__u_decode_ping__DOT__fall_o) 
            | (IData)(prim_alert_sender__DOT__u_decode_ping__DOT__rise_o)) 
           | (IData)(vlSelfRef.prim_alert_sender__DOT__ping_set_q));
    __Vtableidx2 = (((((IData)(vlSelfRef.prim_alert_sender__DOT__ack_sigint) 
                       | (IData)(vlSelfRef.prim_alert_sender__DOT__ping_sigint)) 
                      << 8U) | ((((IData)(prim_alert_sender__DOT__alert_trigger)
                                   ? 1U : 3U) << 5U) 
                                | (((IData)(prim_alert_sender__DOT__alert_trigger) 
                                    | (IData)(vlSelfRef.prim_alert_sender__DOT__ping_trigger)) 
                                   << 4U))) | (((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__level_d) 
                                                << 3U) 
                                               | (IData)(vlSelfRef.prim_alert_sender__DOT__state_q)));
    vlSelfRef.prim_alert_sender__DOT__state_d = Vtop_pkg__ConstPool__TABLE_ha29f17c5_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__alert_pd = Vtop_pkg__ConstPool__TABLE_h15830d43_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__alert_nd = Vtop_pkg__ConstPool__TABLE_hc6902e0f_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__ping_clr = Vtop_pkg__ConstPool__TABLE_he2f1360b_0
        [__Vtableidx2];
    vlSelfRef.prim_alert_sender__DOT__alert_clr = Vtop_pkg__ConstPool__TABLE_ha6f04773_0
        [__Vtableidx2];
    vlSelfRef.alert_ack_o = ((IData)(vlSelfRef.prim_alert_sender__DOT__alert_clr) 
                             & (IData)(vlSelfRef.prim_alert_sender__DOT__alert_set_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__38(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__38\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake = 0;
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (1U & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs)
                      ? (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack))
                      : (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack))));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns));
    if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) 
                               << 1U) | (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs)))))))) {
        if ((0U != (((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) 
                     << 1U) | (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: prim_sync_reqack.sv:269: Assertion failed in %Nprim_fifo_async_simple.u_prim_sync_reqack.gen_nrz_hs_protocol.dst_fsm: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),1,
                             (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs));
                VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sync_reqack.sv", 269, "");
            }
        }
    }
    vlSelfRef.prim_fifo_async_simple__02Ervalid_o = 
        (1U & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs)
                ? (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req))
                : (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req)));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
}

void Vtop_pkg___024root___nba_comb__TOP__0(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__0\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dst_we_o = (((IData)(vlSelfRef.prim_reg_cdc__DOT__txn_bits_q) 
                           >> 2U) & (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src));
    vlSelfRef.dst_re_o = (((IData)(vlSelfRef.prim_reg_cdc__DOT__txn_bits_q) 
                           >> 1U) & (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src));
    vlSelfRef.dst_regwen_o = ((IData)(vlSelfRef.prim_reg_cdc__DOT__txn_bits_q) 
                              & (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src));
}

void Vtop_pkg___024root___nba_sequent__TOP__39(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__39\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level 
        = vlSelfRef.__Vdly__prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level;
}

void Vtop_pkg___024root___nba_sequent__TOP__40(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__40\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cdc_2phase__DOT__i_src__DOT__req_src_q 
        = vlSelfRef.__Vdly__cdc_2phase__DOT__i_src__DOT__req_src_q;
    if (vlSelfRef.src_rst_ni) {
        if (((IData)(vlSelfRef.src_valid_i) & (IData)(vlSelfRef.src_ready_o))) {
            vlSelfRef.cdc_2phase__DOT__i_src__DOT__data_src_q 
                = vlSelfRef.cdc_2phase__02Esrc_data_i;
        }
    } else {
        vlSelfRef.cdc_2phase__DOT__i_src__DOT__data_src_q = 0U;
    }
    vlSelfRef.src_ready_o = ((IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__ack_q) 
                             == (IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__req_src_q));
}

void Vtop_pkg___024root___nba_sequent__TOP__41(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__41\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__prim_fifo__DOT__fifo_stored__v0) {
        vlSelfRef.prim_fifo__DOT__fifo_stored[vlSelfRef.__VdlyDim0__prim_fifo__DOT__fifo_stored__v0] 
            = vlSelfRef.__VdlyVal__prim_fifo__DOT__fifo_stored__v0;
    }
    if (vlSelfRef.__VdlySet__prim_fifo__DOT__fifo_stored__v1) {
        vlSelfRef.prim_fifo__DOT__fifo_stored[0x0000000bU] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[0x0000000aU] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[9U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[8U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[7U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[6U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[5U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[4U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[3U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[2U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[1U] = 0U;
        vlSelfRef.prim_fifo__DOT__fifo_stored[0U] = 0U;
    }
    if (vlSelfRef.prim_fifo__02Erst_ni) {
        if ((((IData)(vlSelfRef.prim_fifo__02Ewvalid_i) 
              & (~ (IData)(vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr))) 
             | ((IData)(vlSelfRef.fifo_full) & (~ (IData)(vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr))))) {
            vlSelfRef.prim_fifo__DOT__wr_gray_pointer 
                = (0x0000000fU & ((IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer_next) 
                                  ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer_next), 1U)));
        }
        if (((IData)(vlSelfRef.prim_fifo__02Ewvalid_i) 
             & (IData)(vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr))) {
            vlSelfRef.fifo_full = 1U;
        } else if ((1U & (~ (IData)(vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr)))) {
            vlSelfRef.fifo_full = 0U;
        }
    } else {
        vlSelfRef.prim_fifo__DOT__wr_gray_pointer = 0U;
        vlSelfRef.fifo_full = 0U;
    }
    vlSelfRef.prim_fifo__DOT__wr_binary_pointer_next 
        = ((0x0bU == (IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer))
            ? 0U : (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer))));
    vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr = 
        (vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync
         [1U] == (IData)(vlSelfRef.prim_fifo__DOT__wr_gray_pointer));
    vlSelfRef.prim_fifo__02Ewready_o = (1U & (~ (IData)(vlSelfRef.fifo_full)));
}

void Vtop_pkg___024root___nba_sequent__TOP__42(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_sequent__TOP__42\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
}

void Vtop_pkg___024root___nba_comb__TOP__1(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___nba_comb__TOP__1\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*108:0*/ tlul_socket_1n__DOT__tl_t_o;
    VL_ZERO_W(109, tlul_socket_1n__DOT__tl_t_o);
    VlWide<3>/*65:0*/ tlul_socket_1n__DOT__tl_t_p;
    VL_ZERO_W(66, tlul_socket_1n__DOT__tl_t_p);
    CData/*0:0*/ tlul_socket_1n__DOT__hfifo_reqready;
    tlul_socket_1n__DOT__hfifo_reqready = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i;
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o;
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty;
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty = 0;
    VlWide<4>/*107:0*/ __VdfgRegularize_he50b618e_0_27;
    VL_ZERO_W(108, __VdfgRegularize_he50b618e_0_27);
    QData/*56:0*/ __Vfunc_get_cmd_intg__19__unused_cmd_payload;
    __Vfunc_get_cmd_intg__19__unused_cmd_payload = 0;
    // Body
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   >> 0x0000000cU))) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    } else {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [0U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [0U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [0U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [0U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [0U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [0U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [0U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [0U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [0U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [0U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [0U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [0U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [1U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [1U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [1U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [1U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [1U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [1U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [1U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [1U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [1U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [1U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [1U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [1U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [2U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [2U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [2U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [2U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [2U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [2U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [2U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [2U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [2U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [2U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [2U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [2U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                       [3U][2U] 
                                                       >> 1U))
                                                    ? 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                 << 0x0000003fU) | 
                                (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [3U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x0000001fU) | 
                                 ((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                        [3U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                  >> 1U)))) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                  [3U][2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x0000003fU) | (((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [3U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                        << 0x0000001fU) 
                                       | ((QData)((IData)(
                                                          ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                            ? 0U
                                                            : 
                                                           (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                [3U][2U] 
                                                                >> 1U))
                                                             ? 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                             : 
                                                            vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                          >> 1U)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [3U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [3U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [3U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][2U]) | (3U & ((IData)(((((QData)((IData)(
                                                        ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                              [3U][2U] 
                                                              >> 1U))
                                                           ? 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                        << 0x0000003fU) 
                                       | (((QData)((IData)(
                                                           ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                             ? 0U
                                                             : 
                                                            (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                 [3U][2U] 
                                                                 >> 1U))
                                                              ? 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                              : 
                                                             vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                           << 0x0000001fU) 
                                          | ((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i
                                                                   [3U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                             >> 1U))) 
                                      >> 0x00000020U)) 
                             >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__rvalid_o) 
                             << 1U)));
    __VdfgRegularize_he50b618e_0_27[0U] = (((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                             << 0x0000001eU) 
                                            | (0x3ffffffeU 
                                               & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                  >> 2U))) 
                                           | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    __VdfgRegularize_he50b618e_0_27[1U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                  >> 2U)) 
                                           | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                               << 0x0000001eU) 
                                              | (0x3ffffffeU 
                                                 & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                    >> 2U))));
    __VdfgRegularize_he50b618e_0_27[2U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                  >> 2U)) 
                                           | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                               << 0x0000001eU) 
                                              | (0x3ffffffeU 
                                                 & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                    >> 2U))));
    __VdfgRegularize_he50b618e_0_27[3U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                  >> 2U)) 
                                           | (0x00000ffeU 
                                              & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                 >> 2U)));
    vlSelfRef.tlul_socket_1n__DOT__hold_all_requests 
        = ((0U != (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)) 
           & ((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]) 
              != (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding)));
    tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][0U];
    tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][1U];
    tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][2U];
    if ((0U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [0U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [0U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [0U][2U];
    }
    if ((1U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [1U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [1U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [1U][2U];
    }
    if ((2U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [2U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [2U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [2U][2U];
    }
    if ((3U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [3U][0U];
        tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [3U][1U];
        tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
            [3U][2U];
    }
    tlul_socket_1n__DOT__tl_t_o[0U] = __VdfgRegularize_he50b618e_0_27[0U];
    tlul_socket_1n__DOT__tl_t_o[1U] = __VdfgRegularize_he50b618e_0_27[1U];
    tlul_socket_1n__DOT__tl_t_o[2U] = __VdfgRegularize_he50b618e_0_27[2U];
    tlul_socket_1n__DOT__tl_t_o[3U] = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                        << 0x0000000cU) 
                                       | __VdfgRegularize_he50b618e_0_27[3U]);
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[0U] 
        = __VdfgRegularize_he50b618e_0_27[0U];
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[1U] 
        = __VdfgRegularize_he50b618e_0_27[1U];
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[2U] 
        = __VdfgRegularize_he50b618e_0_27[2U];
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
        = ((0x00001000U & vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U]) 
           | (0x00001fffU & __VdfgRegularize_he50b618e_0_27[3U]));
    vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U] 
        = ((0x00000fffU & vlSelfRef.tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i[3U]) 
           | (0x00001fffU & (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                              & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
                                 & (4U <= (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])))) 
                             << 0x0000000cU)));
    tlul_socket_1n__DOT__hfifo_reqready = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                           [4U][0U]);
    if ((0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [0U][0U]);
    }
    if ((1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [1U][0U]);
    }
    if ((2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [2U][0U]);
    }
    if ((3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        tlul_socket_1n__DOT__hfifo_reqready = (1U & 
                                               vlSelfRef.tlul_socket_1n__DOT__tl_u_i
                                               [3U][0U]);
    }
    if (vlSelfRef.tlul_socket_1n__DOT__hold_all_requests) {
        tlul_socket_1n__DOT__hfifo_reqready = 0U;
    }
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
           & (3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp = (
                                                   (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                    >> 1U) 
                                                   & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((tlul_socket_1n__DOT__tl_t_p[2U] >> 1U) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (0x0000fffeU & tlul_socket_1n__DOT__tl_t_p[0U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x0000001eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x00000010U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                       >> 0x00000010U))
                : 0U) << 0x00000010U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x0000001eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x00000010U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                       >> 0x00000010U))
                : 0U) >> 0x00000010U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & tlul_socket_1n__DOT__tl_t_p[1U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & tlul_socket_1n__DOT__tl_t_p[2U]);
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (tlul_socket_1n__DOT__tl_t_p[2U] >> 1U)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__blanked_auser = 
        ((0x007fc000U & (tlul_socket_1n__DOT__tl_t_o[0U] 
                         >> 1U)) | ((([&]() {
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[0U] 
                            = tlul_socket_1n__DOT__tl_t_o[0U];
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[1U] 
                            = tlul_socket_1n__DOT__tl_t_o[1U];
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[2U] 
                            = tlul_socket_1n__DOT__tl_t_o[2U];
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[3U] 
                            = tlul_socket_1n__DOT__tl_t_o[3U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[0U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[0U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[1U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[1U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[2U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[2U];
                        vlSelfRef.__Vfunc_get_cmd_intg__19__tl[3U] 
                            = vlSelfRef.__Vfunc_get_bad_cmd_intg__18__tl[3U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[0U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[0U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[1U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[1U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[2U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[2U];
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[3U] 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__tl[3U];
                        vlSelf->__Vfunc_extract_h2d_cmd_intg__20__payload = 0;
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload 
                            = ((0x0000078000000000ULL 
                                & vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload) 
                               | (((QData)((IData)(
                                                   ((vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[2U] 
                                                     << 4U) 
                                                    | (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[1U] 
                                                       >> 0x0000001cU)))) 
                                   << 7U) | (QData)((IData)(
                                                            ((0x00000070U 
                                                              & (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[3U] 
                                                                 >> 5U)) 
                                                             | (0x0000000fU 
                                                                & (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[1U] 
                                                                   >> 0x00000018U)))))));
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload 
                            = ((0x0000007fffffffffULL 
                                & vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload) 
                               | ((QData)((IData)((0x0000000fU 
                                                   & (vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__tl[0U] 
                                                      >> 0x0000000fU)))) 
                                  << 0x00000027U));
                        vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__Vfuncout 
                            = vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__payload;
                        vlSelfRef.__Vfunc_get_cmd_intg__19__cmd 
                            = vlSelfRef.__Vfunc_extract_h2d_cmd_intg__20__Vfuncout;
                        vlSelfRef.__Vfunc_get_cmd_intg__19__cmd_intg 
                            = (0x0000007fU & (IData)(
                                                     (([&]() {
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_i 
                                                = vlSelfRef.__Vfunc_get_cmd_intg__19__cmd;
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_i;
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xfdffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x0103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x00000039U));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xfbffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x017c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003aU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xf7ffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003bU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xefffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003cU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xdfffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003dU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0xbfffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003eU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (
                                                   (0x7fffffffffffffffULL 
                                                    & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o) 
                                                   | ((QData)((IData)(
                                                                      (1U 
                                                                       & VL_REDXOR_64(
                                                                                (0x01fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o))))) 
                                                      << 0x0000003fU));
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o 
                                                = (0x5400000000000000ULL 
                                                   ^ vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o);
                                            vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__Vfuncout 
                                                = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__data_o;
                                        }(), vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__21__Vfuncout) 
                                                      >> 0x00000039U)));
                        __Vfunc_get_cmd_intg__19__unused_cmd_payload 
                            = (0x01ffffffffffffffULL 
                               & ([&]() {
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_i 
                                        = vlSelfRef.__Vfunc_get_cmd_intg__19__cmd;
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_i;
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xfdffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x0103fff800007fffULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x00000039U));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xfbffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x017c1ff801ff801fULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003aU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xf7ffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01bde1f87e0781e1ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003bU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xefffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01deee3b8e388e22ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003cU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xdfffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01ef76cdb2c93244ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003dU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0xbfffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01f7bb56d5525488ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003eU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = ((0x7fffffffffffffffULL 
                                            & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o) 
                                           | ((QData)((IData)(
                                                              (1U 
                                                               & VL_REDXOR_64(
                                                                              (0x01fbdda769a46910ULL 
                                                                               & vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o))))) 
                                              << 0x0000003fU));
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o 
                                        = (0x5400000000000000ULL 
                                           ^ vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o);
                                    vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__Vfuncout 
                                        = vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__data_o;
                                }(), vlSelfRef.__Vfunc_prim_secded_inv_64_57_enc__22__Vfuncout));
                        vlSelfRef.__Vfunc_get_cmd_intg__19__Vfuncout 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__cmd_intg;
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__cmd_intg 
                            = vlSelfRef.__Vfunc_get_cmd_intg__19__Vfuncout;
                        vlSelfRef.__Vfunc_get_bad_cmd_intg__18__Vfuncout 
                            = (0x0000007fU & (~ (IData)(vlSelfRef.__Vfunc_get_bad_cmd_intg__18__cmd_intg)));
                    }(), (IData)(vlSelfRef.__Vfunc_get_bad_cmd_intg__18__Vfuncout)) 
                                     << 7U) | ([&]() {
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o = 0x00000000ffffffffULL;
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = (0x0000007effffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o);
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000007dffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x00000000deba8050ULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000021U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000007bffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x00000000413d89aaULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000022U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x00000077ffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x0000000031234ed1ULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000023U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000006fffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x00000000c2c1323bULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000024U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000005fffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x000000002dcc624cULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000025U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = ((0x0000003fffffffffULL & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o) 
                           | ((QData)((IData)((1U & 
                                               VL_REDXOR_64(
                                                            (0x0000000098505586ULL 
                                                             & vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o))))) 
                              << 0x00000026U));
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o 
                        = (0x0000002a00000000ULL ^ vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o);
                    vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__Vfuncout 
                        = vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__data_o;
                    vlSelfRef.__Vfunc_get_data_intg__24__enc_data 
                        = vlSelfRef.__Vfunc_prim_secded_inv_39_32_enc__25__Vfuncout;
                    vlSelfRef.__Vfunc_get_data_intg__24__data_intg 
                        = (0x0000007fU & (IData)((vlSelfRef.__Vfunc_get_data_intg__24__enc_data 
                                                  >> 0x20U)));
                    vlSelfRef.__Vfunc_get_data_intg__24__Vfuncout 
                        = vlSelfRef.__Vfunc_get_data_intg__24__data_intg;
                    vlSelfRef.__Vfunc_get_bad_data_intg__23__data_intg 
                        = vlSelfRef.__Vfunc_get_data_intg__24__Vfuncout;
                    vlSelfRef.__Vfunc_get_bad_data_intg__23__Vfuncout 
                        = (0x0000007fU & (~ (IData)(vlSelfRef.__Vfunc_get_bad_data_intg__23__data_intg)));
                }(), (IData)(vlSelfRef.__Vfunc_get_bad_data_intg__23__Vfuncout))));
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & (IData)(tlul_socket_1n__DOT__hfifo_reqready));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_req = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                                   & (IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i)));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[0U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
                                                                            ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                              ? 0U
                                                                              : 
                                                                             (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                               & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                               ? 
                                                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                               : 
                                                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                            << 0x0000003fU) 
                                                           | (((QData)((IData)(
                                                                               ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                               << 0x0000001fU) 
                                                              | ((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                 >> 1U)))) 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[1U] = (((IData)(
                                                        (((QData)((IData)(
                                                                          ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                            ? 0U
                                                                            : 
                                                                           (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                             & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                             ? 
                                                                            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                             : 
                                                                            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                          << 0x0000003fU) 
                                                         | (((QData)((IData)(
                                                                             ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                               ? 0U
                                                                               : 
                                                                              (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                ? 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                : 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                             << 0x0000001fU) 
                                                            | ((QData)((IData)(
                                                                               ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                               >> 1U)))) 
                                                >> 0x0000001fU) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                               ? 0U
                                                                               : 
                                                                              (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                ? 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                                : 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                             << 0x0000003fU) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                << 0x0000001fU) 
                                                               | ((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                  >> 1U))) 
                                                           >> 0x00000020U)) 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((2U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x0000003fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x0000001fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U))) 
                                                              >> 0x00000020U)) 
                                                     >> 0x0000001fU)));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
                                                     << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}
