// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_pkg.h for the primary calling header

#include "Vtop_pkg__pch.h"

VL_ATTR_COLD void Vtop_pkg___024root___eval_static(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_static\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtop_pkg___024root___eval_initial__TOP(Vtop_pkg___024root* vlSelf);

VL_ATTR_COLD void Vtop_pkg___024root___eval_initial(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_initial\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_pkg___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop_pkg___024root___eval_initial__TOP(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_initial__TOP\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
        = (2U | (0xffff0001U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]));
    vlSelfRef.rrarbiter__DOT__mask_lut[0U] = 1U;
    vlSelfRef.rrarbiter__DOT__mask_lut[1U] = 3U;
    vlSelfRef.rrarbiter__DOT__mask_lut[2U] = 7U;
    vlSelfRef.rrarbiter__DOT__mask_lut[3U] = 0x000fU;
    vlSelfRef.rrarbiter__DOT__mask_lut[4U] = 0x001fU;
    vlSelfRef.rrarbiter__DOT__mask_lut[5U] = 0x003fU;
    vlSelfRef.rrarbiter__DOT__mask_lut[6U] = 0x007fU;
    vlSelfRef.rrarbiter__DOT__mask_lut[7U] = 0x00ffU;
    vlSelfRef.rrarbiter__DOT__mask_lut[8U] = 0x01ffU;
    vlSelfRef.rrarbiter__DOT__mask_lut[9U] = 0x03ffU;
    vlSelfRef.rrarbiter__DOT__mask_lut[0x0000000aU] = 0x07ffU;
    vlSelfRef.rrarbiter__DOT__mask_lut[0x0000000bU] = 0x0fffU;
    vlSelfRef.rrarbiter__DOT__mask_lut[0x0000000cU] = 0x1fffU;
    vlSelfRef.w_sram_write_o = 1U;
    vlSelfRef.w_sram_wmask_o = 0xffffffffU;
    vlSelfRef.r_sram_write_o = 0U;
    vlSelfRef.r_sram_wdata_o = 0U;
    vlSelfRef.r_sram_wmask_o = 0U;
    vlSelfRef.intg_err_o = 0U;
    vlSelfRef.readback_error_o = 0U;
    vlSelfRef.compound_txn_in_progress_o = 0U;
}

VL_ATTR_COLD void Vtop_pkg___024root___eval_final(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_final\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_pkg___024root___eval_phase__stl(Vtop_pkg___024root* vlSelf);

VL_ATTR_COLD void Vtop_pkg___024root___eval_settle(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_settle\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop_pkg___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/eneadim/github/flexsoc/hw/ips/prim/prim_clk_div.sv", 5, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop_pkg___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop_pkg___024root___eval_triggers__stl(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_triggers__stl\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_pkg___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop_pkg___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_pkg___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop_pkg___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop_pkg___024root___stl_sequent__TOP__0(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___stl_sequent__TOP__0\n"); );
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
    CData/*4:0*/ prim_fifo_async_sram_adapter__DOT__r_wptr;
    prim_fifo_async_sram_adapter__DOT__r_wptr = 0;
    CData/*4:0*/ prim_fifo_async_sram_adapter__DOT__w_rptr;
    prim_fifo_async_sram_adapter__DOT__w_rptr = 0;
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
    CData/*2:0*/ tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi;
    tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi = 0;
    CData/*2:0*/ tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi;
    tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi = 0;
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
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__0__decval_in = 0;
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
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in = 0;
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
    CData/*0:0*/ __Vfunc_mubi4_test_invalid__9__Vfuncout;
    __Vfunc_mubi4_test_invalid__9__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_mubi4_test_invalid__9__val;
    __Vfunc_mubi4_test_invalid__9__val = 0;
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
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in = 0;
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
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__17__decval_in = 0;
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
    if ((1U & (~ VL_ONEHOT_I((((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) 
                               << 1U) | (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)))))))) {
        if ((0U != (((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) 
                     << 1U) | (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: prim_sync_reqack.sv:225: Assertion failed in %Nprim_fifo_async_simple.u_prim_sync_reqack.gen_nrz_hs_protocol.src_fsm: unique case, but multiple matches found for '1'h%x'\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name(),1,
                             (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs));
                VL_STOP_MT("/home/eneadim/github/flexsoc/hw/ips/prim_opentitan/prim_sync_reqack.sv", 225, "");
            }
        }
    }
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
    vlSelfRef.q_o = 0U;
    if ((4U == (IData)(vlSelfRef.prim_deglitch__DOT__count_q))) {
        vlSelfRef.q_o = 1U;
    } else if ((0U == (IData)(vlSelfRef.prim_deglitch__DOT__count_q))) {
        vlSelfRef.q_o = 0U;
    }
    vlSelfRef.pdata_o = vlSelfRef.prim_shreg__DOT__shift_reg;
    vlSelfRef.serial_o = (1U & ((IData)(vlSelfRef.prim_shreg__DOT__shift_reg) 
                                >> 7U));
    vlSelfRef.prim_cdc_rand_delay__02Edst_data_o = vlSelfRef.prim_cdc_rand_delay__DOT__dst_internal;
    vlSelfRef.cdc_2phase__02Edst_data_o = vlSelfRef.cdc_2phase__DOT__i_dst__DOT__data_dst_q;
    vlSelfRef.prim_fifo__02Ewready_o = (1U & (~ (IData)(vlSelfRef.fifo_full)));
    vlSelfRef.prim_fifo__DOT__wr_binary_pointer_next 
        = ((0x0bU == (IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer))
            ? 0U : (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo__DOT__wr_binary_pointer))));
    vlSelfRef.prim_fifo__DOT__rd_binary_pointer_next 
        = ((0x0bU == (IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer))
            ? 0U : (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo__DOT__rd_binary_pointer))));
    vlSelfRef.qs = vlSelfRef.q;
    vlSelfRef.prim_fifo_async_simple__02Erdata_o = vlSelfRef.prim_fifo_async_simple__DOT__data_q;
    vlSelfRef.w_sram_addr_o = (0x0000000fU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    vlSelfRef.w_sram_wdata_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i;
    vlSelfRef.r_sram_addr_o = (0x0000000fU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.src_busy_o = vlSelfRef.prim_reg_cdc__DOT__src_busy_q;
    vlSelfRef.src_qs_o = vlSelfRef.prim_reg_cdc__DOT__src_q;
    vlSelfRef.dst_wd_o = vlSelfRef.prim_reg_cdc__DOT__src_q;
    vlSelfRef.alert_state_o = vlSelfRef.prim_alert_sender__DOT__alert_set_q;
    vlSelfRef.alert_tx_o = ((2U & ((IData)(vlSelfRef.prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o) 
                                   << 1U)) | (1U & 
                                              ((IData)(vlSelfRef.prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o) 
                                               >> 1U)));
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
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.intg_error_o = vlSelfRef.tlul_adapter_sram__DOT__intg_error_q;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.src_ready_o = ((IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__ack_q) 
                             == (IData)(vlSelfRef.cdc_2phase__DOT__i_src__DOT__req_src_q));
    vlSelfRef.dst_valid_o = ((IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__ack_dst_q) 
                             != (IData)(vlSelfRef.cdc_2phase__DOT__i_dst__DOT__req_q1));
    vlSelfRef.r_edge_o = ((~ (IData)(vlSelfRef.prim_edge_detect__DOT__serial_q)) 
                          & (IData)(vlSelfRef.prim_edge_detect__02Eserial_i));
    vlSelfRef.f_edge_o = ((~ (IData)(vlSelfRef.prim_edge_detect__02Eserial_i)) 
                          & (IData)(vlSelfRef.prim_edge_detect__DOT__serial_q));
    vlSelfRef.fifo_empty = (vlSelfRef.prim_fifo__DOT__wr_gray_pointer_sync
                            [1U] == (IData)(vlSelfRef.prim_fifo__DOT__rd_gray_pointer));
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0x0000000eU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_reg_cdc__DOT__src_req = ((IData)(vlSelfRef.src_re_i) 
                                            | (IData)(vlSelfRef.src_we_i));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
           & vlSelfRef.my_ip__02Etl_i[0U]);
    vlSelfRef.prim_fifo__DOT__rdptr_eq_next_wrptr = 
        (vlSelfRef.prim_fifo__DOT__rd_gray_pointer_sync
         [1U] == (IData)(vlSelfRef.prim_fifo__DOT__wr_gray_pointer));
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
    vlSelfRef.prim_lifo__02Ewready_o = (1U & (~ (IData)(vlSelfRef.lifo_full_o)));
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
    vlSelfRef.prim_reg_cdc__DOT__src_ack = ((IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level) 
                                            ^ (IData)(vlSelfRef.prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level_q));
    vlSelfRef.gnt_o = (1U & vlSelfRef.tlul_adapter_host__02Etl_i[0U]);
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
    if ((1U & (~ (IData)(vlSelfRef.prim_clk_gate__02Eclk_i)))) {
        vlSelfRef.prim_clk_gate__DOT__en_latch = ((IData)(vlSelfRef.prim_clk_gate__02Een_i) 
                                                  | (IData)(vlSelfRef.test_en_i));
    }
    vlSelfRef.hw2reg_intr_state_de_o = (((IData)(vlSelfRef.reg2hw_intr_test_q_i) 
                                         & (IData)(vlSelfRef.reg2hw_intr_test_qe_i)) 
                                        | (IData)(vlSelfRef.event_intr_i));
    vlSelfRef.qe = ((IData)(vlSelfRef.de) | (IData)(vlSelfRef.we));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d 
        = ((IData)(vlSelfRef.r_sram_rvalid_i) ? vlSelfRef.r_sram_rdata_i
            : 0U);
    vlSelfRef.lifo_empty_o = (0U == (IData)(vlSelfRef.prim_lifo__DOT__pointer));
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
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval 
        = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub 
        = (0x0000001fU & (((IData)(0x10U) - (0x0000000fU 
                                             & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval))) 
                          - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in 
        = ((0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in 
        = (0x0fU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout 
        = (0x0000001fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout) 
                          ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout 
        = ((0x0fU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout)) 
           | (0x00000010U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__2__Vfuncout;
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
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__13__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__16__Vfuncout;
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
    vlSelfRef.vld_o = ((0U != (IData)(vlSelfRef.rrarbiter__02Ereq_i)) 
                       & (IData)(vlSelfRef.rrarbiter__02Een_i));
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.prim_fifo_async_simple__02Ewready_o = 
        ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
    vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
           != (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q)));
    vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
           != (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q)));
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
    vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src = 
        ((IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level) 
         ^ (IData)(vlSelfRef.prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level_q));
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
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__addr_hit 
        = ((((3U == (vlSelfRef.my_ip__02Etl_i[1U] >> 0x0000001eU)) 
             << 3U) | ((2U == (vlSelfRef.my_ip__02Etl_i[1U] 
                               >> 0x0000001eU)) << 2U)) 
           | (((1U == (vlSelfRef.my_ip__02Etl_i[1U] 
                       >> 0x0000001eU)) << 1U) | (0U 
                                                  == 
                                                  (vlSelfRef.my_ip__02Etl_i[1U] 
                                                   >> 0x0000001eU))));
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
    vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
        = (1U & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs)
                  ? (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack))
                  : (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack)));
    vlSelfRef.prim_fifo_async_simple__02Ervalid_o = 
        (1U & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs)
                ? (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req))
                : (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req)));
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
    vlSelfRef.prim_alert_sender__DOT__alert_req_trigger 
        = ((IData)(vlSelfRef.alert_req_i) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_set_q));
    vlSelfRef.prim_alert_sender__DOT__alert_test_trigger 
        = ((IData)(vlSelfRef.alert_test_i) | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_set_q));
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
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_check_ok 
        = ((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_nd) 
           ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd));
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
    prim_alert_sender__DOT__u_decode_ping__DOT____VdfgExtracted_h845d1838__0 
        = (((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd) 
            ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pq)) 
           & ((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd) 
              ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nq)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)) 
           & (vlSelfRef.my_ip__02Etl_i[3U] >> 0x0000000cU));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
        = ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]) 
           | (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U] 
        = ((1U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U]) 
           | (3U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0x0000ffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (0xffff0000U & ((((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                                ? 1U : 0U) << 0x0000001eU) 
                             | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size) 
                                 << 0x00000019U) | 
                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source) 
                                 << 0x00000011U)))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U] 
        = ((2U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U]) 
           | (3U & ((((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                       ? 1U : 0U) >> 2U) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size) 
                                             >> 7U) 
                                            | ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source) 
                                               >> 0x0000000fU)))));
    VL_ASSIGNSEL_WI(66, 32, 0x00000010U, vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int, 
                    (([&]() {
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__26__val 
                        = vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type;
                    vlSelfRef.__Vfunc_mubi4_test_true_strict__26__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__26__val));
                }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__26__Vfuncout))
                      ? 0U : 0xffffffffU));
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
    prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_check_ok 
        = ((IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd) 
           ^ (IData)(vlSelfRef.prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o 
        = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
            != (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
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
    vlSelfRef.rrarbiter__DOT__mask = ((0x0cU >= (IData)(vlSelfRef.rrarbiter__DOT__arb_sel_q))
                                       ? vlSelfRef.rrarbiter__DOT__mask_lut
                                      [vlSelfRef.rrarbiter__DOT__arb_sel_q]
                                       : 0U);
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
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.prim_lifo__DOT__wr_en = ((IData)(vlSelfRef.prim_lifo__02Ewready_o) 
                                       & (IData)(vlSelfRef.prim_lifo__02Ewvalid_i));
    vlSelfRef.tc_o = ((IData)(vlSelfRef.tc_val_i) == (IData)(vlSelfRef.val_o));
    vlSelfRef.prim_reg_cdc__DOT__dst_to_src = ((IData)(vlSelfRef.prim_reg_cdc__DOT__src_ack) 
                                               & (IData)(vlSelfRef.prim_reg_cdc__DOT__src_busy_q));
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = (1U & (((IData)(vlSelfRef.gnt_o) & (IData)(vlSelfRef.tlul_adapter_host__02Ereq_i))
                  ? ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)))
                  : (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)));
    vlSelfRef.prim_clk_gate__02Eclk_o = ((IData)(vlSelfRef.prim_clk_gate__02Eclk_i) 
                                         & (IData)(vlSelfRef.prim_clk_gate__DOT__en_latch));
    vlSelfRef.hw2reg_intr_state_d_o = ((IData)(vlSelfRef.hw2reg_intr_state_de_o) 
                                       | (IData)(vlSelfRef.reg2hw_intr_state_q_i));
    vlSelfRef.prim_lifo__02Ervalid_o = (1U & (~ (IData)(vlSelfRef.lifo_empty_o)));
    vlSelfRef.ds = ((IData)(vlSelfRef.qe) ? vlSelfRef.prim_reg__DOT__wr_data
                     : vlSelfRef.q);
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0x0000000cU));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.dst_we_o = (((IData)(vlSelfRef.prim_reg_cdc__DOT__txn_bits_q) 
                           >> 2U) & (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src));
    vlSelfRef.dst_re_o = (((IData)(vlSelfRef.prim_reg_cdc__DOT__txn_bits_q) 
                           >> 1U) & (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src));
    vlSelfRef.dst_regwen_o = ((IData)(vlSelfRef.prim_reg_cdc__DOT__txn_bits_q) 
                              & (IData)(vlSelfRef.prim_reg_cdc__DOT__dst_req_from_src));
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0x0000000cU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                               & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
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
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
           == (IData)(tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
           == (IData)(tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
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
    vlSelfRef.r_sram_req_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
                               ? ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1) 
                                  & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))
                               : ((~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                      ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
                                  & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1)));
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
    prim_alert_sender__DOT__alert_trigger = ((IData)(vlSelfRef.prim_alert_sender__DOT__alert_req_trigger) 
                                             | (IData)(vlSelfRef.prim_alert_sender__DOT__alert_test_trigger));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0 
        = (((IData)(vlSelfRef.gnt_i) | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
           & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o)));
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
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][0U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][1U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][2U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U];
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
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0x0000000cU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.prim_lifo__DOT__rd_en = ((IData)(vlSelfRef.prim_lifo__02Erready_i) 
                                       & (IData)(vlSelfRef.prim_lifo__02Ervalid_o));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
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
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[1U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                 >> 0x0000001fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[2U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                 >> 0x0000001fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0x00001000U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x00001fffU 
                                                   & ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                         ? 0U
                                                         : 
                                                        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                       >> 0x0000001fU) 
                                                      | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                           ? 0U
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][3U]) 
                                                         << 1U))));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0x00000fffU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x00001000U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                                                      << 0x0000000cU)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | (IData)(vlSelfRef.tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | ((IData)(
                                                           ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                             ? 0ULL
                                                             : 
                                                            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                            [
                                                            (3U 
                                                             & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[1U] = (((IData)(
                                                         ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                           ? 0ULL
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                 >> 0x0000001fU) 
                                                | ((IData)(
                                                           (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                              ? 0ULL
                                                              : 
                                                             vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                             [
                                                             (3U 
                                                              & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                            >> 0x00000020U)) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((2U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (3U 
                                                   & ((IData)(
                                                              (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                                 ? 0ULL
                                                                 : 
                                                                vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                                [
                                                                (3U 
                                                                 & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                               >> 0x00000020U)) 
                                                      >> 0x0000001fU)));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (2U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                                                      << 1U)));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
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
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
             >> 0x0000000cU) & (IData)(vlSelfRef.tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0)) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o)));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0x0000000cU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o)));
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.my_ip__02Etl_i[1U] 
                           >> 0x0000001cU))));
    vlSelfRef.prim_alert_sender__DOT__ping_trigger 
        = (((IData)(prim_alert_sender__DOT__u_decode_ping__DOT__fall_o) 
            | (IData)(prim_alert_sender__DOT__u_decode_ping__DOT__rise_o)) 
           | (IData)(vlSelfRef.prim_alert_sender__DOT__ping_set_q));
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data 
        = (([&]() {
                vlSelfRef.__Vfunc_mubi4_test_true_strict__7__val 
                    = (0x0000000fU & (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o 
                                      >> 0x0000000aU));
                vlSelfRef.__Vfunc_mubi4_test_true_strict__7__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__7__val));
            }(), (IData)(vlSelfRef.__Vfunc_mubi4_test_true_strict__7__Vfuncout))
            ? 0U : 0xffffffffU);
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o) 
           & (IData)(vlSelfRef.rvalid_i));
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
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.we_o)) & ((IData)(vlSelfRef.gnt_i) 
                                           & (IData)(vlSelfRef.req_o))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o)));
    my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req));
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
    vlSelfRef.alert_ack_o = ((IData)(vlSelfRef.prim_alert_sender__DOT__alert_clr) 
                             & (IData)(vlSelfRef.prim_alert_sender__DOT__alert_set_q));
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
    vlSelfRef.idx_o = (0x0000000fU & ((IData)(vlSelfRef.rrarbiter__DOT__lock_q)
                                       ? (IData)(vlSelfRef.rrarbiter__DOT__arb_sel_lock_q)
                                       : ((0x0dU > (IData)(rrarbiter__DOT__next_idx))
                                           ? (IData)(rrarbiter__DOT__next_idx)
                                           : 0x0000000cU)));
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
    my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7 
        = ((~ (IData)(vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__reg_error)) 
           & (IData)(my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o));
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
    __Vtableidx4 = (((IData)(vlSelfRef.vld_o) << 4U) 
                    | (IData)(vlSelfRef.idx_o));
    vlSelfRef.ack_o = Vtop_pkg__ConstPool__TABLE_hdd797092_0
        [__Vtableidx4];
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
    vlSelfRef.my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((0U == (vlSelfRef.my_ip__02Etl_i[1U] >> 0x0000001eU)) 
           & (IData)(my_ip__DOT__u_my_ip_reg__DOT____VdfgRegularize_h283c86b4_0_7));
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
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
}

VL_ATTR_COLD void Vtop_pkg___024root___stl_sequent__TOP__1(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___stl_sequent__TOP__1\n"); );
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
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
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

VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
VL_ATTR_COLD void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);
void Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vtop_pkg_tlul_fifo_sync__RCz9_RDz9* vlSelf);

VL_ATTR_COLD void Vtop_pkg___024root___eval_stl(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_stl\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop_pkg___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vtop_pkg___024root___stl_sequent__TOP__1(vlSelf);
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vtop_pkg_tlul_fifo_sync__RCz9_RDz9___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
    }
}

VL_ATTR_COLD bool Vtop_pkg___024root___eval_phase__stl(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___eval_phase__stl\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop_pkg___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop_pkg___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop_pkg___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop_pkg___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_pkg___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop_pkg___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_pkg___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_pkg___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge prim_clk_div.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge prim_clk_div.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge prim_lifo.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge prim_lifo.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge prim_ram.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(posedge prim_rom.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @(posedge prim_shreg.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @(posedge prim_cdc_rand_delay.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @(negedge prim_cdc_rand_delay.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @(posedge prim_intr_hw.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 10 is active: @(negedge prim_intr_hw.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 11 is active: @(posedge src_clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 12 is active: @(negedge src_rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 13 is active: @(posedge dst_clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 14 is active: @(negedge dst_rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 15 is active: @(posedge prim_counter.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 16 is active: @(negedge prim_counter.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 17 is active: @(posedge prim_deglitch.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 18 is active: @(negedge prim_deglitch.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 19 is active: @(posedge prim_edge_detect.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 20 is active: @(negedge prim_edge_detect.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 21 is active: @(negedge prim_fifo.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 22 is active: @(posedge wr_clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 23 is active: @(posedge rd_clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 24 is active: @(posedge prim_reg.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 25 is active: @(negedge prim_reg.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 26 is active: @(posedge rrarbiter.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 27 is active: @(negedge rrarbiter.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 28 is active: @(posedge prim_fifo_async_simple.clk_wr_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 29 is active: @(negedge prim_fifo_async_simple.rst_wr_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 30 is active: @(posedge prim_fifo_async_simple.clk_rd_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 31 is active: @(negedge prim_fifo_async_simple.rst_rd_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 32 is active: @(posedge prim_fifo_async_sram_adapter.clk_wr_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 33 is active: @(negedge prim_fifo_async_sram_adapter.rst_wr_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 34 is active: @(posedge prim_fifo_async_sram_adapter.clk_rd_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 35 is active: @(negedge prim_fifo_async_sram_adapter.rst_rd_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 36 is active: @(posedge prim_filter.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 37 is active: @(negedge prim_filter.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 38 is active: @(posedge prim_filter_ctr.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 39 is active: @(negedge prim_filter_ctr.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 40 is active: @(posedge clk_src_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 41 is active: @(negedge rst_src_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 42 is active: @(posedge clk_dst_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 43 is active: @(negedge rst_dst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 44 is active: @(posedge prim_alert_sender.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 45 is active: @(negedge prim_alert_sender.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 46 is active: @(posedge tlul_adapter_host.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 47 is active: @(negedge tlul_adapter_host.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 48 is active: @(posedge tlul_adapter_sram.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 49 is active: @(negedge tlul_adapter_sram.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 50 is active: @(posedge clk_h_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 51 is active: @(negedge rst_h_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 52 is active: @(posedge clk_d_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 53 is active: @(negedge rst_d_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 54 is active: @(posedge tlul_socket_1n.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 55 is active: @(negedge tlul_socket_1n.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 56 is active: @(posedge tlul_socket_m1.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 57 is active: @(negedge tlul_socket_m1.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 58 is active: @(posedge my_ip.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 59 is active: @(negedge my_ip.rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_pkg___024root___ctor_var_reset(Vtop_pkg___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_pkg___024root___ctor_var_reset\n"); );
    Vtop_pkg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->prim_clk_div__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 817051054220190671ull);
    vlSelf->prim_clk_div__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3203236063447792352ull);
    vlSelf->testmode_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12320502978421127714ull);
    vlSelf->prim_clk_div__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11151308724633475182ull);
    vlSelf->prim_clk_div__02Eclk_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12768712639864395660ull);
    vlSelf->prim_clk_gate__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11095146842912875917ull);
    vlSelf->prim_clk_gate__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16759468834995712353ull);
    vlSelf->test_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9265559370075686664ull);
    vlSelf->prim_clk_gate__02Eclk_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11204416008844058858ull);
    vlSelf->A = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3969090544990846983ull);
    vlSelf->Z = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4398759943034541363ull);
    vlSelf->prim_lifo__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17282678104021254970ull);
    vlSelf->prim_lifo__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16520829340372775813ull);
    vlSelf->prim_lifo__02Ewdata_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7084278663468856145ull);
    vlSelf->prim_lifo__02Ewvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5262983606099458534ull);
    vlSelf->prim_lifo__02Ewready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8213811166919011038ull);
    vlSelf->prim_lifo__02Erdata_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8867133851816675979ull);
    vlSelf->prim_lifo__02Ervalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12532295962155722291ull);
    vlSelf->prim_lifo__02Erready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16004459827627640680ull);
    vlSelf->lifo_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12941069735567446515ull);
    vlSelf->lifo_empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11838763158318648861ull);
    vlSelf->prim_ram__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4892910441781511609ull);
    vlSelf->prim_ram__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13972105567927976965ull);
    vlSelf->prim_ram__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5808459783200746539ull);
    vlSelf->prim_ram__02Ewe_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1066699620828601456ull);
    vlSelf->prim_ram__02Eaddr_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16696233342688283107ull);
    vlSelf->prim_ram__02Ewdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4955154692897860194ull);
    vlSelf->prim_ram__02Erdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2385487376331969133ull);
    vlSelf->prim_rom__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5004403117764261919ull);
    vlSelf->prim_rom__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10883104815569221618ull);
    vlSelf->prim_rom__02Eaddr_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17576665329939673367ull);
    vlSelf->prim_rom__02Erdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12922135855078453466ull);
    vlSelf->prim_shreg__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10714732063537124957ull);
    vlSelf->prim_shreg__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12220047001572294600ull);
    vlSelf->prim_shreg__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16615065422541461537ull);
    vlSelf->prim_shreg__02Eserial_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9121723493735214485ull);
    vlSelf->pdata_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4474880437952447820ull);
    vlSelf->serial_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2688168735925054928ull);
    vlSelf->prim_cdc_rand_delay__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7130415939755854911ull);
    vlSelf->prim_cdc_rand_delay__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4342115214787159165ull);
    vlSelf->prev_data_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 370851070020915823ull);
    vlSelf->prim_cdc_rand_delay__02Esrc_data_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8813283746223292107ull);
    vlSelf->prim_cdc_rand_delay__02Edst_data_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11851302403735561122ull);
    vlSelf->prim_intr_hw__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8821559553242299938ull);
    vlSelf->prim_intr_hw__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2071415695027420670ull);
    vlSelf->event_intr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3086694155548980750ull);
    vlSelf->reg2hw_intr_enable_q_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6758147818321775349ull);
    vlSelf->reg2hw_intr_test_q_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17827372268826424408ull);
    vlSelf->reg2hw_intr_test_qe_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11740294177951309645ull);
    vlSelf->reg2hw_intr_state_q_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12456162989855848157ull);
    vlSelf->hw2reg_intr_state_de_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4816405906024677924ull);
    vlSelf->hw2reg_intr_state_d_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14407081978736232411ull);
    vlSelf->intr_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9634479256470380856ull);
    vlSelf->src_clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6913922591468233478ull);
    vlSelf->src_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10733924514174127722ull);
    vlSelf->cdc_2phase__02Esrc_data_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10317734337283866072ull);
    vlSelf->src_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12988678573092369438ull);
    vlSelf->src_ready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18182486825893421409ull);
    vlSelf->dst_clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14268718918106230470ull);
    vlSelf->dst_rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13808650392307194017ull);
    vlSelf->cdc_2phase__02Edst_data_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13052932065562986781ull);
    vlSelf->dst_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11892664094701194159ull);
    vlSelf->dst_ready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4203590292587283183ull);
    vlSelf->prim_counter__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12793266709687253017ull);
    vlSelf->prim_counter__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10708204920747369718ull);
    vlSelf->prim_counter__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12037433068211860493ull);
    vlSelf->clr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4950173694017053554ull);
    vlSelf->up_down_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3146697557810154045ull);
    vlSelf->step_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3336879808810971777ull);
    vlSelf->tc_val_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18268097815709503188ull);
    vlSelf->val_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15573012321347423349ull);
    vlSelf->tc_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11596343589067271766ull);
    vlSelf->prim_deglitch__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7542620784740658950ull);
    vlSelf->prim_deglitch__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12761749049990696500ull);
    vlSelf->prim_deglitch__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4776303102905438981ull);
    vlSelf->d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2330852176559559633ull);
    vlSelf->q_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12211521543721664862ull);
    vlSelf->prim_edge_detect__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7746163340671506266ull);
    vlSelf->prim_edge_detect__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11029787669444676357ull);
    vlSelf->prim_edge_detect__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12925879881492778581ull);
    vlSelf->prim_edge_detect__02Eserial_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7917581927265076203ull);
    vlSelf->r_edge_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16960149032419538355ull);
    vlSelf->f_edge_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12993950134852869505ull);
    vlSelf->rd_clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14051990289421456627ull);
    vlSelf->wr_clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4972585237341502859ull);
    vlSelf->prim_fifo__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15462259728124652287ull);
    vlSelf->prim_fifo__02Ewdata_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14807922690776547352ull);
    vlSelf->prim_fifo__02Ewvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4281781601263523054ull);
    vlSelf->prim_fifo__02Ewready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 50871991405542433ull);
    vlSelf->prim_fifo__02Erdata_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14726448034466589827ull);
    vlSelf->prim_fifo__02Ervalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4985491877411427767ull);
    vlSelf->prim_fifo__02Erready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16161681070290448220ull);
    vlSelf->fifo_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4782710040797492827ull);
    vlSelf->fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7130728548526110812ull);
    vlSelf->prim_reg__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10111721728148945659ull);
    vlSelf->prim_reg__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2385036375399886630ull);
    vlSelf->we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10105644630884274164ull);
    vlSelf->wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18210509495843279068ull);
    vlSelf->ds = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10343076919720641053ull);
    vlSelf->qs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1373413353089790568ull);
    vlSelf->de = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13418971983228644420ull);
    vlSelf->d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1720370409040345145ull);
    vlSelf->qe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13811282347017747479ull);
    vlSelf->q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8861071527689086543ull);
    vlSelf->rrarbiter__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15721315670920079001ull);
    vlSelf->rrarbiter__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3383718262510818996ull);
    vlSelf->flush_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12823618135036147526ull);
    vlSelf->rrarbiter__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7818630029752460077ull);
    vlSelf->rrarbiter__02Ereq_i = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 5932634292086375681ull);
    vlSelf->ack_o = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 7968475957095882202ull);
    vlSelf->vld_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9914080848836798661ull);
    vlSelf->idx_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16573138247442084722ull);
    vlSelf->prim_fifo_async_simple__02Eclk_wr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13161334828138196571ull);
    vlSelf->prim_fifo_async_simple__02Erst_wr_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13317407479673324529ull);
    vlSelf->prim_fifo_async_simple__02Ewvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2109284318277179952ull);
    vlSelf->prim_fifo_async_simple__02Ewready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2307623430833081755ull);
    vlSelf->prim_fifo_async_simple__02Ewdata_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4240555491118761960ull);
    vlSelf->prim_fifo_async_simple__02Eclk_rd_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12154328466968224559ull);
    vlSelf->prim_fifo_async_simple__02Erst_rd_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7861772877918414154ull);
    vlSelf->prim_fifo_async_simple__02Ervalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9327581356772465273ull);
    vlSelf->prim_fifo_async_simple__02Erready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2508000287383456596ull);
    vlSelf->prim_fifo_async_simple__02Erdata_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11270905549299322113ull);
    vlSelf->prim_fifo_async_sram_adapter__02Eclk_wr_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14639896819757392714ull);
    vlSelf->prim_fifo_async_sram_adapter__02Erst_wr_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11999454544329308805ull);
    vlSelf->prim_fifo_async_sram_adapter__02Ewvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3391460053721408770ull);
    vlSelf->prim_fifo_async_sram_adapter__02Ewready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9325193623084057530ull);
    vlSelf->prim_fifo_async_sram_adapter__02Ewdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14602778743786343917ull);
    vlSelf->wdepth_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8820535233231916995ull);
    vlSelf->prim_fifo_async_sram_adapter__02Eclk_rd_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16924581245085255904ull);
    vlSelf->prim_fifo_async_sram_adapter__02Erst_rd_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7478262917960006560ull);
    vlSelf->prim_fifo_async_sram_adapter__02Ervalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14565574896983052327ull);
    vlSelf->prim_fifo_async_sram_adapter__02Erready_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8439777308382069239ull);
    vlSelf->prim_fifo_async_sram_adapter__02Erdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4218602636490408417ull);
    vlSelf->rdepth_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9982912201746250091ull);
    vlSelf->r_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9500786639391166409ull);
    vlSelf->r_notempty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8471168441199265866ull);
    vlSelf->w_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2598963129036131991ull);
    vlSelf->w_sram_req_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14197136532197849820ull);
    vlSelf->w_sram_gnt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11617630611995728568ull);
    vlSelf->w_sram_write_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2539785642491847272ull);
    vlSelf->w_sram_addr_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10465147810060829434ull);
    vlSelf->w_sram_wdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17405356208995654410ull);
    vlSelf->w_sram_wmask_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11887540766394321641ull);
    vlSelf->w_sram_rvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3770407490508088952ull);
    vlSelf->w_sram_rdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9462583216486910567ull);
    vlSelf->w_sram_rerror_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2997047427200037839ull);
    vlSelf->r_sram_req_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1330823827761410699ull);
    vlSelf->r_sram_gnt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18192746602208076813ull);
    vlSelf->r_sram_write_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15865949739526419573ull);
    vlSelf->r_sram_addr_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8961569158626842787ull);
    vlSelf->r_sram_wdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11210705549885224451ull);
    vlSelf->r_sram_wmask_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9511348035735092641ull);
    vlSelf->r_sram_rvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2947981763023376193ull);
    vlSelf->r_sram_rdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 512915813469395516ull);
    vlSelf->r_sram_rerror_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4091329199393658640ull);
    vlSelf->prim_filter__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4540038929235772044ull);
    vlSelf->prim_filter__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12349180009974268446ull);
    vlSelf->prim_filter__02Eenable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15039754826739121444ull);
    vlSelf->prim_filter__02Efilter_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9109301640414159487ull);
    vlSelf->prim_filter__02Efilter_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4663196495151438442ull);
    vlSelf->prim_filter_ctr__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10225700792689041351ull);
    vlSelf->prim_filter_ctr__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5548642803983120628ull);
    vlSelf->prim_filter_ctr__02Eenable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3365164131662941556ull);
    vlSelf->prim_filter_ctr__02Efilter_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12525474539599438571ull);
    vlSelf->thresh_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2450114284915665370ull);
    vlSelf->prim_filter_ctr__02Efilter_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12256248272253987607ull);
    vlSelf->clk_src_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4001498580928466257ull);
    vlSelf->rst_src_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5051664114225530441ull);
    vlSelf->clk_dst_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12851786363318594956ull);
    vlSelf->rst_dst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4194750565043001346ull);
    vlSelf->src_regwen_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17099014108730345698ull);
    vlSelf->src_we_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17542492657126063174ull);
    vlSelf->src_re_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4814825604165719572ull);
    vlSelf->src_wd_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14796056282611505485ull);
    vlSelf->src_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10086578303772526111ull);
    vlSelf->src_qs_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7303931147743945635ull);
    vlSelf->dst_ds_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8570661034182711617ull);
    vlSelf->dst_qs_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1188878227332427069ull);
    vlSelf->dst_update_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7537277360995277466ull);
    vlSelf->dst_we_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11943994256373921413ull);
    vlSelf->dst_re_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17746061217599766768ull);
    vlSelf->dst_regwen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4157798524948868598ull);
    vlSelf->dst_wd_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5097451175198061258ull);
    vlSelf->prim_reg_we_check__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8438453934384567729ull);
    vlSelf->prim_reg_we_check__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4140056255478245248ull);
    vlSelf->oh_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16598430225602142758ull);
    vlSelf->prim_reg_we_check__02Een_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2601430786291548802ull);
    vlSelf->prim_reg_we_check__02Eerr_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12972613376835358609ull);
    vlSelf->prim_alert_sender__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 863118677887058021ull);
    vlSelf->prim_alert_sender__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11290466901864125332ull);
    vlSelf->alert_test_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17462262601123946775ull);
    vlSelf->alert_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2967653272698415251ull);
    vlSelf->alert_ack_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5035762474647222145ull);
    vlSelf->alert_state_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16538130280503528403ull);
    vlSelf->alert_rx_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3626835617410658616ull);
    vlSelf->alert_tx_o = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 268840600036833065ull);
    vlSelf->sram2tlul__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14498564742491988945ull);
    vlSelf->sram2tlul__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1283341933177774564ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->sram2tlul__02Etl_o, __VscopeHash, 2082888234225280089ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->sram2tlul__02Etl_i, __VscopeHash, 9979301477367309268ull);
    vlSelf->mem_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9602946012337845599ull);
    vlSelf->mem_write_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6718616174579250495ull);
    vlSelf->mem_addr_i = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 5219164976016085494ull);
    vlSelf->mem_wdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1087537329350986119ull);
    vlSelf->mem_rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9704645861843026599ull);
    vlSelf->mem_rdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14734067514201526555ull);
    vlSelf->mem_error_o = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16082422893818280768ull);
    vlSelf->tlul_adapter_host__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6756678502031656081ull);
    vlSelf->tlul_adapter_host__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1467922377375738726ull);
    vlSelf->tlul_adapter_host__02Ereq_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1169648171734662543ull);
    vlSelf->gnt_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11825630704627518037ull);
    vlSelf->tlul_adapter_host__02Eaddr_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2490125134645028778ull);
    vlSelf->tlul_adapter_host__02Ewe_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 591944109644240624ull);
    vlSelf->tlul_adapter_host__02Ewdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16536899642454038209ull);
    vlSelf->wdata_intg_i = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 13796587183322886850ull);
    vlSelf->be_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11504187847728164574ull);
    vlSelf->instr_type_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16465864997580800559ull);
    vlSelf->valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10854271546065566948ull);
    vlSelf->tlul_adapter_host__02Erdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6045763135741870626ull);
    vlSelf->rdata_intg_o = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 10990154104825283461ull);
    vlSelf->tlul_adapter_host__02Eerr_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11527068783315314631ull);
    vlSelf->intg_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8789439780594604087ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_adapter_host__02Etl_o, __VscopeHash, 18324899651217273308ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_adapter_host__02Etl_i, __VscopeHash, 1904629015416413261ull);
    vlSelf->tlul_adapter_sram__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7897380864575400391ull);
    vlSelf->tlul_adapter_sram__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8939575033651098909ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_adapter_sram__02Etl_i, __VscopeHash, 7774722047785205627ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_adapter_sram__02Etl_o, __VscopeHash, 9645705021079483355ull);
    vlSelf->en_ifetch_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17474012580135680959ull);
    vlSelf->req_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14083548127655471290ull);
    vlSelf->req_type_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12079034522389375949ull);
    vlSelf->gnt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13289480920257270115ull);
    vlSelf->we_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4716421662202290248ull);
    vlSelf->addr_o = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 8886233680481133883ull);
    vlSelf->wdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11772386738134641114ull);
    vlSelf->wmask_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1843244455351364317ull);
    vlSelf->intg_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7486886209812712495ull);
    vlSelf->rdata_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2003564130048450692ull);
    vlSelf->rvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3586105308544157546ull);
    vlSelf->rerror_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1952728914134980337ull);
    vlSelf->compound_txn_in_progress_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7437008012948831483ull);
    vlSelf->readback_en_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5298994560014161105ull);
    vlSelf->readback_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15382970186325059961ull);
    vlSelf->wr_collision_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15837285587554985172ull);
    vlSelf->write_pending_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5742807122815720609ull);
    vlSelf->tlul_assert_multiple__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4655021951644632724ull);
    vlSelf->tlul_assert_multiple__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 19833215720817358ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(109, vlSelf->h2d[__Vi0], __VscopeHash, 11460876968636362437ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(66, vlSelf->d2h[__Vi0], __VscopeHash, 18089683219658873148ull);
    }
    vlSelf->clk_h_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13114408084727706158ull);
    vlSelf->rst_h_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3210938375933500741ull);
    vlSelf->clk_d_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5015677828910384221ull);
    vlSelf->rst_d_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 338268933110373976ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_fifo_async__02Etl_h_i, __VscopeHash, 1910831070838978207ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_fifo_async__02Etl_h_o, __VscopeHash, 11817247428061112410ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_fifo_async__02Etl_d_o, __VscopeHash, 8141657904586275657ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_fifo_async__02Etl_d_i, __VscopeHash, 8906933710045652757ull);
    vlSelf->tlul_socket_1n__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4190597201453145940ull);
    vlSelf->tlul_socket_1n__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17653341986472654125ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_socket_1n__02Etl_h_i, __VscopeHash, 4278202361175622123ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_socket_1n__02Etl_h_o, __VscopeHash, 4580079230364298258ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_socket_1n__02Etl_d_o[__Vi0], __VscopeHash, 16929302659630613513ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_socket_1n__02Etl_d_i[__Vi0], __VscopeHash, 12819343196191970251ull);
    }
    vlSelf->dev_select_i = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9780703115793365750ull);
    vlSelf->tlul_socket_m1__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1904123150784897452ull);
    vlSelf->tlul_socket_m1__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12915914010321099247ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_socket_m1__02Etl_h_i[__Vi0], __VscopeHash, 16057790028242869791ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_socket_m1__02Etl_h_o[__Vi0], __VscopeHash, 5471815548806303780ull);
    }
    VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_socket_m1__02Etl_d_o, __VscopeHash, 9252685417282971132ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_socket_m1__02Etl_d_i, __VscopeHash, 3077823679422073310ull);
    vlSelf->my_ip__02Eclk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3005558959822304525ull);
    vlSelf->my_ip__02Erst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18418474994469497819ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->my_ip__02Etl_i, __VscopeHash, 16948821589359214520ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->my_ip__02Etl_o, __VscopeHash, 4300044740100665323ull);
    vlSelf->port_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 313071210505319004ull);
    vlSelf->port_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5055776756475145770ull);
    vlSelf->prim_clk_div__DOT__counter_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8514880746404614247ull);
    vlSelf->prim_clk_div__DOT__clk_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4059815839653590555ull);
    vlSelf->prim_clk_gate__DOT__en_latch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5587073761777453940ull);
    vlSelf->prim_lifo__DOT____Vlvbound_hd0f2e51d__0 = 0;
    vlSelf->prim_lifo__DOT__pointer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2960949042277589901ull);
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->prim_lifo__DOT__lifo_stored[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9408323609812509652ull);
    }
    vlSelf->prim_lifo__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17346809228532590799ull);
    vlSelf->prim_lifo__DOT__rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6479525997973124646ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->prim_ram__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12719613892639030935ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->prim_rom__DOT__rom[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11667695315985999238ull);
    }
    vlSelf->prim_shreg__DOT__shift_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13964179599515452769ull);
    vlSelf->prim_cdc_rand_delay__DOT__dst_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11272479990455304580ull);
    vlSelf->cdc_2phase__DOT__i_src__DOT__req_src_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6055388202925889010ull);
    vlSelf->cdc_2phase__DOT__i_src__DOT__ack_src_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7879574132726536177ull);
    vlSelf->cdc_2phase__DOT__i_src__DOT__ack_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1357404016673590239ull);
    vlSelf->cdc_2phase__DOT__i_src__DOT__data_src_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11751544336541029644ull);
    vlSelf->cdc_2phase__DOT__i_dst__DOT__req_dst_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6150165348852084677ull);
    vlSelf->cdc_2phase__DOT__i_dst__DOT__req_q0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11966614479891093113ull);
    vlSelf->cdc_2phase__DOT__i_dst__DOT__req_q1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1812103128635760903ull);
    vlSelf->cdc_2phase__DOT__i_dst__DOT__ack_dst_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14843886225467718468ull);
    vlSelf->cdc_2phase__DOT__i_dst__DOT__data_dst_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14466528742954321079ull);
    vlSelf->prim_counter__DOT__count_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 239711980192879884ull);
    vlSelf->prim_counter__DOT__count_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7676219721697639509ull);
    vlSelf->prim_deglitch__DOT__count_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1383900438181921456ull);
    vlSelf->prim_edge_detect__DOT__serial_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10079106145968600130ull);
    vlSelf->prim_fifo__DOT____Vlvbound_h2c7b1089__0 = 0;
    vlSelf->prim_fifo__DOT__rd_gray_pointer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1854849885935447142ull);
    vlSelf->prim_fifo__DOT__rd_binary_pointer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3781580977289345875ull);
    vlSelf->prim_fifo__DOT__rd_binary_pointer_next = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 515161015083537091ull);
    vlSelf->prim_fifo__DOT__wr_gray_pointer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6749500539876364157ull);
    vlSelf->prim_fifo__DOT__wr_binary_pointer = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4248773271305849843ull);
    vlSelf->prim_fifo__DOT__wr_binary_pointer_next = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18382639958569786898ull);
    for (int __Vi0 = 0; __Vi0 < 12; ++__Vi0) {
        vlSelf->prim_fifo__DOT__fifo_stored[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2961609386125383515ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->prim_fifo__DOT__rd_gray_pointer_sync[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 166578129724741525ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->prim_fifo__DOT__wr_gray_pointer_sync[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6182759031022004621ull);
    }
    vlSelf->prim_fifo__DOT__rdptr_eq_next_wrptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 374486674707242482ull);
    vlSelf->prim_reg__DOT__wr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15454481069534792003ull);
    vlSelf->rrarbiter__DOT__arb_sel_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2744465341383432641ull);
    vlSelf->rrarbiter__DOT__arb_sel_lock_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6116627602412589237ull);
    for (int __Vi0 = 0; __Vi0 < 13; ++__Vi0) {
        vlSelf->rrarbiter__DOT__mask_lut[__Vi0] = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 630839717999079515ull);
    }
    vlSelf->rrarbiter__DOT__mask = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 16659163226542784252ull);
    vlSelf->rrarbiter__DOT__lock_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3261976446758827497ull);
    vlSelf->prim_fifo_async_simple__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10753885399401881178ull);
    vlSelf->prim_fifo_async_simple__DOT__src_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11367978643848443628ull);
    vlSelf->prim_fifo_async_simple__DOT__src_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12939752158797755286ull);
    vlSelf->prim_fifo_async_simple__DOT__pending_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15926852384519448046ull);
    vlSelf->prim_fifo_async_simple__DOT__pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18270435849758061247ull);
    vlSelf->prim_fifo_async_simple__DOT__not_in_reset_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16393853340339498594ull);
    vlSelf->prim_fifo_async_simple__DOT__dst_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14034977718620941269ull);
    vlSelf->prim_fifo_async_simple__DOT__data_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9772910759283672346ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 631791976887736667ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7074957093070588807ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4819122162994514809ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4043776708178805058ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5894025515260757706ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14870725363346654974ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16022562087404823330ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7814660556321576354ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 868503204620588908ull);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4287094011597060276ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16350185492339224451ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12495315779191542188ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4300251424331541661ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14371725458531049392ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_wptr_gray = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7355253441334520014ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9812253391480626978ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15779760875052025496ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17301363649134628769ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10050197278953428848ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_rptr_gray = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2284250945590920042ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_inc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14146043725098304990ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_inc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3332499069249166610ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__stored = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4326242173063187202ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11599585718243087209ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__rdata_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12921191420059894515ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_sram_rptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15843674868444464208ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__store_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15074169103120547020ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT____VdfgRegularize_h1c658b81_0_1 = 0;
    vlSelf->prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4903518354399580852ull);
    vlSelf->prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9090513942706695226ull);
    vlSelf->prim_filter__DOT__stored_vector_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12178564423428921452ull);
    vlSelf->prim_filter__DOT__stored_vector_d = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14052077008535177325ull);
    vlSelf->prim_filter__DOT__stored_value_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17710955656675103902ull);
    vlSelf->prim_filter_ctr__DOT__diff_ctr_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11650095859425010217ull);
    vlSelf->prim_filter_ctr__DOT__diff_ctr_d = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4276877853382287851ull);
    vlSelf->prim_filter_ctr__DOT__filter_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4533864243713385512ull);
    vlSelf->prim_filter_ctr__DOT__stored_value_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17373104421038390874ull);
    vlSelf->prim_reg_cdc__DOT__src_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10071273190871077673ull);
    vlSelf->prim_reg_cdc__DOT__src_busy_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14621415935634883600ull);
    vlSelf->prim_reg_cdc__DOT__src_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13767313880243503038ull);
    vlSelf->prim_reg_cdc__DOT__txn_bits_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9402305771165811948ull);
    vlSelf->prim_reg_cdc__DOT__src_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17528311835047333383ull);
    vlSelf->prim_reg_cdc__DOT__dst_to_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2590793456343909108ull);
    vlSelf->prim_reg_cdc__DOT__dst_req_from_src = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 854741750346748353ull);
    vlSelf->prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5840046349650823437ull);
    vlSelf->prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9652488298670082403ull);
    vlSelf->prim_reg_cdc__DOT__u_src_to_dst_req__DOT__dst_level_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16862845757311883383ull);
    vlSelf->prim_reg_cdc__DOT__u_src_to_dst_req__DOT__prim_flop_2sync__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7545625899846397304ull);
    vlSelf->prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__src_level = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1277432061805054021ull);
    vlSelf->prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1648474203256890271ull);
    vlSelf->prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__dst_level_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17637299221302040075ull);
    vlSelf->prim_reg_cdc__DOT__u_arb__DOT__gen_passthru__DOT__u_dst_to_src_ack__DOT__prim_flop_2sync__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2946302181442956551ull);
    vlSelf->prim_alert_sender__DOT__ping_sigint = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2740706421530994686ull);
    vlSelf->prim_alert_sender__DOT__ack_sigint = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1969581308150559977ull);
    vlSelf->prim_alert_sender__DOT__state_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14151839370085032840ull);
    vlSelf->prim_alert_sender__DOT__state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8273343960029652828ull);
    vlSelf->prim_alert_sender__DOT__alert_pd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7735631314743779477ull);
    vlSelf->prim_alert_sender__DOT__alert_nd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8520863599250732057ull);
    vlSelf->prim_alert_sender__DOT__alert_set_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7719866943832949763ull);
    vlSelf->prim_alert_sender__DOT__alert_clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9090664791847292295ull);
    vlSelf->prim_alert_sender__DOT__alert_test_set_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14804946151552854150ull);
    vlSelf->prim_alert_sender__DOT__ping_set_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4837977917935347671ull);
    vlSelf->prim_alert_sender__DOT__ping_clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 935056726629812497ull);
    vlSelf->prim_alert_sender__DOT__alert_req_trigger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17786310855305506822ull);
    vlSelf->prim_alert_sender__DOT__alert_test_trigger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16724695819003577279ull);
    vlSelf->prim_alert_sender__DOT__ping_trigger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2526618099750793619ull);
    vlSelf->prim_alert_sender__DOT____Vcellout__u_prim_flop_alert__q_o = 0;
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_d = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16626926490063172873ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1773318123667798013ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17937995355920425577ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6950553750175559408ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_pd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11653577168429187349ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__diff_nd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3511710572024920939ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17510794744432660385ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__skew_cnt_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 189485783230501770ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__i_sync_p__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16039450466718403293ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ping__DOT__gen_async__DOT__i_sync_n__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4759690725263054764ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__level_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7103080741615600241ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__level_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12191020356665711533ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_d = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7974771655401916670ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8822583566009758326ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_pd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11955037438199276707ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__diff_nd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9943417151676957461ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9752865496186210231ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__skew_cnt_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13294490532695344435ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__i_sync_p__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6004135942203411011ull);
    vlSelf->prim_alert_sender__DOT__u_decode_ack__DOT__gen_async__DOT__i_sync_n__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1893188395143830699ull);
    vlSelf->tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8079961854368562449ull);
    vlSelf->tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3021074284095207753ull);
    vlSelf->tlul_adapter_sram__DOT__error_det = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11486352126726329257ull);
    vlSelf->tlul_adapter_sram__DOT__intg_error_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12141543821718396310ull);
    vlSelf->tlul_adapter_sram__DOT__error_blanking_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8235223404322362623ull);
    vlSelf->tlul_adapter_sram__DOT__missed_err_gnt_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3925276480379763589ull);
    vlSelf->tlul_adapter_sram__DOT____Vcellout__u_reqfifo__rdata_o = 0;
    vlSelf->tlul_adapter_sram__DOT____Vcellout__u_sramreqfifo__rdata_o = 0;
    vlSelf->tlul_adapter_sram__DOT____Vcellinp__u_rspfifo__wdata_i = 0;
    vlSelf->tlul_adapter_sram__DOT____VdfgRegularize_hb17975a6_0_0 = 0;
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__wready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12905979854485715184ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8065096672763705718ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10438243680965868273ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16997861015649059625ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 65390243587749333ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10470869124213234379ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6397345938780809951ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3701583225398808179ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16580172604450796838ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 284368548662155992ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8825841450148387350ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9086197289167886709ull);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9913477656992423934ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__wready_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1074929220653059057ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16669189782915127250ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14876556034243611071ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14564260780728965221ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5563033907368069472ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16225940724611706913ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12947028098920902083ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15576089074546768139ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10288750996988492638ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18160382729919050577ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13376905926488966447ull);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15959141684162111735ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__wvalid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12025481932001954955ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__rvalid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10240660703581398905ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3739886037030363381ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1883302926960584639ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7677108932626599929ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9318985837497145758ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17134910333991567080ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 6439520265743241516ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3063445032842525663ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9579692272611767477ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14828382128475866022ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15751244772979656890ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10788857494883541075ull);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14189264475140747934ull);
    vlSelf->tlul_fifo_async__DOT____Vcellout__reqfifo__wready_o = 0;
    vlSelf->tlul_fifo_async__DOT____Vcellout__rspfifo__wready_o = 0;
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11075167665445981694ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13655850470398118751ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10735809387814620574ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16477729086016824703ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4667645233543812714ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14758380994322008089ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15367679166810258127ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 130823841818622342ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5361906960515141750ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9800446776446030870ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16797675220692766763ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7595083404856355040ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5703861188703282367ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12270040897579989078ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6554129896458069629ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(107, vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__storage[__Vi0], __VscopeHash, 2592848095020287597ull);
    }
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7350549430744543478ull);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 440585248878841557ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8003539271735009392ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3944744973889395371ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15368386691569819239ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2308117167609228603ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1100614395434722640ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6125230667053936963ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4612104696919367709ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9788838506001769396ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5988961976574529789ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16826828194533537172ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4471956468405315762ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7327085558597943064ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17028649483148415221ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3664672807999520815ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5237562389096808653ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__storage[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10221955733593836424ull);
    }
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15616674431806603546ull);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11533130128284058627ull);
    vlSelf->tlul_socket_1n__DOT__num_req_outstanding = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5695332604365843606ull);
    vlSelf->tlul_socket_1n__DOT__dev_select_outstanding = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18390249840664109938ull);
    vlSelf->tlul_socket_1n__DOT__hold_all_requests = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6791193960077112797ull);
    vlSelf->tlul_socket_1n__DOT__accept_t_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1149643731888936453ull);
    vlSelf->tlul_socket_1n__DOT__accept_t_rsp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12152435702459470967ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_socket_1n__DOT__tl_u_i[__Vi0], __VscopeHash, 6208919807107136234ull);
    }
    vlSelf->tlul_socket_1n__DOT__blanked_auser = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 3522924849078636549ull);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4952917440749265605ull);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18000092634287124457ull);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1025672247270461553ull);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5572456998937764116ull);
    VL_ZERO_RESET_W(109, vlSelf->tlul_socket_1n__DOT____Vcellinp__gen_err_resp__DOT__err_resp__tl_h_i);
    VL_ZERO_RESET_W(110, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o = 0;
    VL_ZERO_RESET_W(110, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o = 0;
    VL_ZERO_RESET_W(65, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o = 0;
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10192384952941920675ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2876541934828130608ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 96908364914994225ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10451882224009887697ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5865164650819961881ull);
    VL_SCOPED_RAND_RESET_W(110, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 5408425563101728829ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11954094946075479859ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13321134208349045455ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1202937422590851525ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6304292156123000373ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17800825812822003975ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10224652325472795560ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1960515125754291379ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12777075269491832195ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13317400661416625404ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11550750605940029423ull);
    VL_SCOPED_RAND_RESET_W(65, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 5645986153568384132ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14470967413727351920ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17563215919109875726ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9349629372251076797ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1441504150931008219ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8231456741296888588ull);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 839618993370383933ull);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15270828526672545200ull);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3559709765341219323ull);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7282869515279299256ull);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1692354367943545707ull);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17940071029395226459ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int, __VscopeHash, 4190096867873213017ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__hreq_fifo_o[__Vi0], __VscopeHash, 10035514910201414297ull);
    }
    VL_ZERO_RESET_W(109, vlSelf->tlul_socket_m1__DOT____Vcellout__gen_arb_ppc__DOT__u_reqarb__data_o);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_ZERO_RESET_W(109, vlSelf->tlul_socket_m1__DOT____Vcellinp__gen_arb_ppc__DOT__u_reqarb__data_i[__Vi0]);
    }
    vlSelf->tlul_socket_m1__DOT____VdfgRegularize_ha7c0ca08_0_4 = 0;
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o = 0;
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o = 0;
    VL_ZERO_RESET_W(65, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o = 0;
    VL_ZERO_RESET_W(65, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o = 0;
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14728443932655658164ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11236488165976026911ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8488042049177012930ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3753525065128456295ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9016048726432224432ull);
    VL_SCOPED_RAND_RESET_W(108, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 15883016464446990307ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14238850423795774919ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10361019366918632526ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11258143355779598962ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12667133374662028611ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11226307844069474344ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6302008447610707428ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2714581079337806487ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17776028312429786852ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2949600473529534914ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1553219066614875074ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2588429207489607824ull);
    VL_SCOPED_RAND_RESET_W(65, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage, __VscopeHash, 711355300350922986ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12099131020646436354ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2511469180358551683ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1144285488993955983ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17062426817283597820ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9935692199926105482ull);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14445926906776250094ull);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__req_i = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8300804941161782845ull);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gnt_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8383302998521492626ull);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3258850602703930525ull);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17742465942145862021ull);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5576689125502501566ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__reg_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15358768671131104884ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10805397282941075125ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q = 0;
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q = 0;
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q = 0;
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__addr_hit = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18017918474430171372ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10751265893804029608ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7116852958562708803ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__d_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11244992593329447238ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4411521616250346858ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14287676994928638653ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11609469206960382255ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6262770542908668242ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7048880341527464794ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13533872394765439203ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2642592706156846377ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7613693340094483982ull);
    vlSelf->my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16249537375599910977ull);
    vlSelf->my_ip__DOT__u_my_ip_core__DOT__status_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11829791662869275996ull);
    vlSelf->my_ip__DOT__u_my_ip_core__DOT__status_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13902216074229559058ull);
    vlSelf->my_ip__DOT__u_my_ip_core__DOT__rdata = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4167324134368407463ull);
    vlSelf->my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17125272029717368878ull);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__1__Vfuncout = 0;
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__3__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_invalid__4__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_invalid__4__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__5__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__5__val = 0;
    vlSelf->__Vfunc_mubi4_test_false_loose__6__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_false_loose__6__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__7__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__7__val = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__8__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__8__val = 0;
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__10__Vfuncout = 0;
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__11__Vfuncout = 0;
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__14__Vfuncout = 0;
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__15__Vfuncout = 0;
    vlSelf->__Vfunc_get_bad_cmd_intg__18__Vfuncout = 0;
    VL_ZERO_RESET_W(109, vlSelf->__Vfunc_get_bad_cmd_intg__18__tl);
    vlSelf->__Vfunc_get_bad_cmd_intg__18__cmd_intg = 0;
    vlSelf->__Vfunc_get_cmd_intg__19__Vfuncout = 0;
    VL_ZERO_RESET_W(109, vlSelf->__Vfunc_get_cmd_intg__19__tl);
    vlSelf->__Vfunc_get_cmd_intg__19__cmd_intg = 0;
    vlSelf->__Vfunc_get_cmd_intg__19__cmd = 0;
    vlSelf->__Vfunc_extract_h2d_cmd_intg__20__Vfuncout = 0;
    VL_ZERO_RESET_W(109, vlSelf->__Vfunc_extract_h2d_cmd_intg__20__tl);
    vlSelf->__Vfunc_extract_h2d_cmd_intg__20__payload = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__21__Vfuncout = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__21__data_i = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__21__data_o = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__22__Vfuncout = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__22__data_i = 0;
    vlSelf->__Vfunc_prim_secded_inv_64_57_enc__22__data_o = 0;
    vlSelf->__Vfunc_get_bad_data_intg__23__Vfuncout = 0;
    vlSelf->__Vfunc_get_bad_data_intg__23__data_intg = 0;
    vlSelf->__Vfunc_get_data_intg__24__Vfuncout = 0;
    vlSelf->__Vfunc_get_data_intg__24__data_intg = 0;
    vlSelf->__Vfunc_get_data_intg__24__enc_data = 0;
    vlSelf->__Vfunc_prim_secded_inv_39_32_enc__25__Vfuncout = 0;
    vlSelf->__Vfunc_prim_secded_inv_39_32_enc__25__data_o = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__26__Vfuncout = 0;
    vlSelf->__Vfunc_mubi4_test_true_strict__26__val = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = 0;
    vlSelf->__Vdly__cdc_2phase__DOT__i_src__DOT__req_src_q = 0;
    vlSelf->__Vdly__prim_reg_cdc__DOT__u_src_to_dst_req__DOT__src_level = 0;
    vlSelf->__VdlyVal__prim_fifo__DOT__fifo_stored__v0 = 0;
    vlSelf->__VdlyDim0__prim_fifo__DOT__fifo_stored__v0 = 0;
    vlSelf->__VdlySet__prim_fifo__DOT__fifo_stored__v0 = 0;
    vlSelf->__VdlySet__prim_fifo__DOT__fifo_stored__v1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__prim_clk_div__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_clk_div__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_lifo__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_lifo__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_ram__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_rom__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_shreg__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_cdc_rand_delay__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_cdc_rand_delay__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_intr_hw__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_intr_hw__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__src_clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__src_rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__dst_clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__dst_rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_counter__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_counter__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_deglitch__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_deglitch__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_edge_detect__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_edge_detect__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__wr_clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rd_clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_reg__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_reg__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rrarbiter__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rrarbiter__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_wr_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_wr_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_rd_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_rd_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_wr_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_wr_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_rd_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_rd_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_filter__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_filter__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_filter_ctr__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_filter_ctr__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk_src_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_src_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk_dst_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_dst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_alert_sender__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_alert_sender__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_host__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_host__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_sram__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_sram__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk_h_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_h_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk_d_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_d_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_1n__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_1n__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_m1__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_m1__02Erst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__my_ip__02Eclk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__my_ip__02Erst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
