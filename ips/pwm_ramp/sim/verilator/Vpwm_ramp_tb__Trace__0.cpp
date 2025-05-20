// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpwm_ramp_tb__Syms.h"


void Vpwm_ramp_tb___024root__trace_chg_0_sub_0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpwm_ramp_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_chg_0\n"); );
    // Init
    Vpwm_ramp_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_ramp_tb___024root*>(voidSelf);
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vpwm_ramp_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vpwm_ramp_tb___024root__trace_chg_0_sub_0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_chg_0_sub_0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_12;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_36;
    VlWide<4>/*127:0*/ __Vtemp_39;
    VlWide<4>/*127:0*/ __Vtemp_55;
    VlWide<4>/*127:0*/ __Vtemp_61;
    VlWide<4>/*127:0*/ __Vtemp_71;
    VlWide<4>/*127:0*/ __Vtemp_74;
    VlWide<4>/*127:0*/ __Vtemp_90;
    VlWide<4>/*127:0*/ __Vtemp_96;
    VlWide<4>/*127:0*/ __Vtemp_106;
    VlWide<4>/*127:0*/ __Vtemp_109;
    VlWide<4>/*127:0*/ __Vtemp_125;
    VlWide<4>/*127:0*/ __Vtemp_131;
    VlWide<4>/*127:0*/ __Vtemp_141;
    VlWide<4>/*127:0*/ __Vtemp_144;
    VlWide<4>/*127:0*/ __Vtemp_160;
    VlWide<4>/*127:0*/ __Vtemp_166;
    VlWide<4>/*127:0*/ __Vtemp_182;
    VlWide<4>/*127:0*/ __Vtemp_188;
    VlWide<4>/*127:0*/ __Vtemp_204;
    VlWide<4>/*127:0*/ __Vtemp_210;
    VlWide<4>/*127:0*/ __Vtemp_226;
    VlWide<4>/*127:0*/ __Vtemp_232;
    VlWide<4>/*127:0*/ __Vtemp_248;
    VlWide<4>/*127:0*/ __Vtemp_254;
    VlWide<4>/*127:0*/ __Vtemp_270;
    VlWide<4>/*127:0*/ __Vtemp_276;
    VlWide<3>/*95:0*/ __Vtemp_281;
    VlWide<3>/*95:0*/ __Vtemp_282;
    VlWide<3>/*95:0*/ __Vtemp_290;
    VlWide<3>/*95:0*/ __Vtemp_292;
    VlWide<3>/*95:0*/ __Vtemp_297;
    VlWide<3>/*95:0*/ __Vtemp_298;
    VlWide<3>/*95:0*/ __Vtemp_306;
    VlWide<3>/*95:0*/ __Vtemp_308;
    VlWide<3>/*95:0*/ __Vtemp_313;
    VlWide<3>/*95:0*/ __Vtemp_314;
    VlWide<3>/*95:0*/ __Vtemp_322;
    VlWide<3>/*95:0*/ __Vtemp_324;
    VlWide<3>/*95:0*/ __Vtemp_329;
    VlWide<3>/*95:0*/ __Vtemp_330;
    VlWide<3>/*95:0*/ __Vtemp_338;
    VlWide<3>/*95:0*/ __Vtemp_340;
    VlWide<3>/*95:0*/ __Vtemp_344;
    VlWide<4>/*127:0*/ __Vtemp_348;
    VlWide<4>/*127:0*/ __Vtemp_352;
    VlWide<4>/*127:0*/ __Vtemp_356;
    VlWide<4>/*127:0*/ __Vtemp_360;
    VlWide<4>/*127:0*/ __Vtemp_364;
    VlWide<4>/*127:0*/ __Vtemp_366;
    VlWide<4>/*127:0*/ __Vtemp_369;
    VlWide<3>/*95:0*/ __Vtemp_372;
    VlWide<4>/*127:0*/ __Vtemp_375;
    VlWide<3>/*95:0*/ __Vtemp_378;
    VlWide<4>/*127:0*/ __Vtemp_381;
    VlWide<4>/*127:0*/ __Vtemp_383;
    VlWide<3>/*95:0*/ __Vtemp_385;
    VlWide<3>/*95:0*/ __Vtemp_390;
    VlWide<3>/*95:0*/ __Vtemp_391;
    VlWide<3>/*95:0*/ __Vtemp_394;
    VlWide<3>/*95:0*/ __Vtemp_402;
    VlWide<3>/*95:0*/ __Vtemp_404;
    VlWide<3>/*95:0*/ __Vtemp_409;
    VlWide<3>/*95:0*/ __Vtemp_410;
    VlWide<3>/*95:0*/ __Vtemp_413;
    VlWide<3>/*95:0*/ __Vtemp_421;
    VlWide<3>/*95:0*/ __Vtemp_423;
    VlWide<3>/*95:0*/ __Vtemp_428;
    VlWide<3>/*95:0*/ __Vtemp_429;
    VlWide<3>/*95:0*/ __Vtemp_432;
    VlWide<3>/*95:0*/ __Vtemp_440;
    VlWide<3>/*95:0*/ __Vtemp_442;
    VlWide<3>/*95:0*/ __Vtemp_447;
    VlWide<3>/*95:0*/ __Vtemp_448;
    VlWide<3>/*95:0*/ __Vtemp_451;
    VlWide<3>/*95:0*/ __Vtemp_459;
    VlWide<3>/*95:0*/ __Vtemp_461;
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o)),32);
        bufp->chgIData(oldp+1,((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o)),32);
        bufp->chgCData(oldp+2,((0x7fU & (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
                                                 >> 0x20U)))),7);
        bufp->chgCData(oldp+3,((0x7fU & (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
                                                 >> 0x20U)))),7);
        bufp->chgQData(oldp+4,(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o),39);
        bufp->chgQData(oldp+6,(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o),39);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+8,(vlSelfRef.pwm_ramp_tb__DOT__rst_ni));
        bufp->chgBit(oldp+9,(vlSelfRef.pwm_ramp_tb__DOT__enable_i));
        bufp->chgBit(oldp+10,(vlSelfRef.pwm_ramp_tb__DOT__reverse_i));
        bufp->chgCData(oldp+11,(vlSelfRef.pwm_ramp_tb__DOT__step_i),6);
        bufp->chgDouble(oldp+12,(vlSelfRef.pwm_ramp_tb__DOT__analog_input));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+14,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n));
        bufp->chgIData(oldp+15,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d),32);
        bufp->chgIData(oldp+16,(vlSelfRef.prim_subreg__DOT__wr_data),32);
        bufp->chgBit(oldp+17,(vlSelfRef.tlul_adapter_reg__DOT__instr_error));
        bufp->chgBit(oldp+18,(vlSelfRef.tlul_adapter_reg__DOT__malformed_meta_err));
        bufp->chgBit(oldp+19,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_wr_err));
        bufp->chgBit(oldp+20,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_type_err));
        bufp->chgBit(oldp+21,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk));
        bufp->chgBit(oldp+22,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk));
        bufp->chgBit(oldp+23,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk));
        bufp->chgBit(oldp+24,(vlSelfRef.tlul_adapter_sram__DOT__error_det));
        bufp->chgBit(oldp+25,(vlSelfRef.tlul_adapter_sram__DOT__instr_error));
        bufp->chgIData(oldp+26,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata),17);
        bufp->chgCData(oldp+27,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata),5);
        bufp->chgIData(oldp+28,(vlSelfRef.tlul_adapter_sram__DOT__wmask_int),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tlul_adapter_sram__DOT__wdata_int),32);
        bufp->chgCData(oldp+30,(vlSelfRef.tlul_adapter_sram__DOT__wmask_intg),7);
        bufp->chgCData(oldp+31,(vlSelfRef.tlul_adapter_sram__DOT__wdata_intg),7);
        bufp->chgBit(oldp+32,(((0U != (IData)(vlSelfRef.tlul_adapter_sram__DOT__wmask_intg)) 
                               & (0U != (IData)(vlSelfRef.tlul_adapter_sram__DOT__wdata_intg)))));
        bufp->chgIData(oldp+33,(vlSelfRef.tlul_adapter_sram__DOT__sv2v_autoblock_1__DOT__i),32);
        bufp->chgBit(oldp+34,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err));
        bufp->chgBit(oldp+35,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err));
        bufp->chgBit(oldp+36,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk));
        bufp->chgBit(oldp+37,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk));
        bufp->chgBit(oldp+38,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk));
        bufp->chgCData(oldp+39,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_mask),8);
        bufp->chgQData(oldp+40,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_data),64);
        bufp->chgQData(oldp+42,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_data),64);
        bufp->chgCData(oldp+44,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_mask),8);
        bufp->chgQData(oldp+45,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_data),64);
        bufp->chgQData(oldp+47,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_data),64);
        bufp->chgWData(oldp+49,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i),110);
        bufp->chgWData(oldp+53,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+57,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+61,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+65,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+69,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+72,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+75,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+78,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+81,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+84,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_4[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_4[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_4[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_4[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                         | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+85,(__Vtemp_4),108);
        bufp->chgBit(oldp+89,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U])));
        bufp->chgBit(oldp+90,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_8[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_8[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_8[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_8[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                         | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+91,(__Vtemp_8),108);
        bufp->chgBit(oldp+95,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U])));
        bufp->chgBit(oldp+96,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_12[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_12[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_12[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_12[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                          | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+97,(__Vtemp_12),108);
        bufp->chgBit(oldp+101,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U])));
        bufp->chgBit(oldp+102,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                      >> 0xcU))));
        __Vtemp_16[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_16[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_16[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_16[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                          | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+103,(__Vtemp_16),108);
        bufp->chgBit(oldp+107,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U])));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgBit(oldp+108,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
        bufp->chgBit(oldp+109,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid));
        bufp->chgBit(oldp+110,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+111,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+112,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xaU])))) {
        bufp->chgBit(oldp+113,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+114,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+115,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+116,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+117,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+118,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+119,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+120,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+121,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+122,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [3U] | vlSelfRef.__Vm_traceActivity
                        [0xaU]) | vlSelfRef.__Vm_traceActivity
                       [0x11U]) | vlSelfRef.__Vm_traceActivity
                      [0x1aU])))) {
        bufp->chgBit(oldp+123,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                   >> 1U))
                                                ? vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                : vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_24[0U] = 0U;
            __Vtemp_24[1U] = 0U;
            __Vtemp_24[2U] = 0U;
        } else if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                       >> 1U))) {
            __Vtemp_24[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_24[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_24[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_24[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_24[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_24[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+124,(__Vtemp_24),65);
        if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                >> 1U))) {
            __Vtemp_26[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_26[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_26[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_26[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_26[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_26[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+127,(__Vtemp_26),65);
        __Vtemp_36[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                             ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [0U][3U] >> 0xcU))
                                      ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [0U][1U]) 
                                         | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][1U]))
                                      : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                           << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [0U][3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][0U])
                                                   : 
                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                        >> 1U));
        __Vtemp_36[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                             ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [0U][3U] >> 0xcU))
                                      ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [0U][2U]) 
                                         | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][2U]))
                                      : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                           << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [0U][3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [0U][1U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [0U][1U]))
                                                   : 
                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                        >> 1U));
        __Vtemp_36[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                             ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [0U][3U] >> 0xcU))
                                      ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [0U][3U]) 
                                         | (0xffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][3U]))
                                      : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                           << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [0U][3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [0U][2U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [0U][2U]))
                                                   : 
                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                        >> 1U));
        __Vtemp_39[0U] = ((__Vtemp_36[0U] << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        __Vtemp_39[1U] = ((__Vtemp_36[0U] >> 0x1fU) 
                          | (__Vtemp_36[1U] << 1U));
        __Vtemp_39[2U] = ((__Vtemp_36[1U] >> 0x1fU) 
                          | (__Vtemp_36[2U] << 1U));
        __Vtemp_39[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                           << 0xcU) | ((__Vtemp_36[2U] 
                                        >> 0x1fU) | 
                                       ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                         ? 0U : (0xffeU 
                                                 & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                        [0U][3U] 
                                                        >> 0xcU))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [0U][3U]) 
                                                     | (0xffeU 
                                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                        [0U][3U]))
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
        bufp->chgWData(oldp+130,(__Vtemp_39),109);
        bufp->chgBit(oldp+134,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][0U])
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_55[0U] = 0U;
            __Vtemp_55[1U] = 0U;
            __Vtemp_55[2U] = 0U;
            __Vtemp_55[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [0U][3U] >> 0xcU))) {
            __Vtemp_55[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [0U][0U]);
            __Vtemp_55[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [0U][1U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][1U]));
            __Vtemp_55[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [0U][2U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][2U]));
            __Vtemp_55[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [0U][3U]) | (0xffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][3U]));
        } else {
            __Vtemp_55[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_55[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_55[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_55[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+135,(__Vtemp_55),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                [0U][3U] >> 0xcU))) {
            __Vtemp_61[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [0U][0U]);
            __Vtemp_61[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [0U][1U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][1U]));
            __Vtemp_61[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [0U][2U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][2U]));
            __Vtemp_61[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [0U][3U]) | (0xffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [0U][3U]));
        } else {
            __Vtemp_61[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_61[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_61[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_61[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+139,(__Vtemp_61),108);
        __Vtemp_71[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                             ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [1U][3U] >> 0xcU))
                                      ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [1U][1U]) 
                                         | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][1U]))
                                      : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                           << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [1U][3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][0U])
                                                   : 
                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                        >> 1U));
        __Vtemp_71[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                             ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [1U][3U] >> 0xcU))
                                      ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [1U][2U]) 
                                         | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][2U]))
                                      : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                           << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [1U][3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [1U][1U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [1U][1U]))
                                                   : 
                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                        >> 1U));
        __Vtemp_71[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                             ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [1U][3U] >> 0xcU))
                                      ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [1U][3U]) 
                                         | (0xffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][3U]))
                                      : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                           << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [1U][3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [1U][2U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [1U][2U]))
                                                   : 
                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                        >> 1U));
        __Vtemp_74[0U] = ((__Vtemp_71[0U] << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        __Vtemp_74[1U] = ((__Vtemp_71[0U] >> 0x1fU) 
                          | (__Vtemp_71[1U] << 1U));
        __Vtemp_74[2U] = ((__Vtemp_71[1U] >> 0x1fU) 
                          | (__Vtemp_71[2U] << 1U));
        __Vtemp_74[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                           << 0xcU) | ((__Vtemp_71[2U] 
                                        >> 0x1fU) | 
                                       ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                         ? 0U : (0xffeU 
                                                 & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                        [1U][3U] 
                                                        >> 0xcU))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [1U][3U]) 
                                                     | (0xffeU 
                                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                        [1U][3U]))
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
        bufp->chgWData(oldp+143,(__Vtemp_74),109);
        bufp->chgBit(oldp+147,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][0U])
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_90[0U] = 0U;
            __Vtemp_90[1U] = 0U;
            __Vtemp_90[2U] = 0U;
            __Vtemp_90[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [1U][3U] >> 0xcU))) {
            __Vtemp_90[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [1U][0U]);
            __Vtemp_90[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [1U][1U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][1U]));
            __Vtemp_90[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [1U][2U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][2U]));
            __Vtemp_90[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [1U][3U]) | (0xffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][3U]));
        } else {
            __Vtemp_90[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_90[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_90[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_90[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+148,(__Vtemp_90),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                [1U][3U] >> 0xcU))) {
            __Vtemp_96[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [1U][0U]);
            __Vtemp_96[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [1U][1U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][1U]));
            __Vtemp_96[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [1U][2U]) | (0xfffffffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][2U]));
            __Vtemp_96[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [1U][3U]) | (0xffeU 
                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                            [1U][3U]));
        } else {
            __Vtemp_96[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_96[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_96[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_96[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+152,(__Vtemp_96),108);
        __Vtemp_106[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [2U][3U] 
                                          >> 0xcU))
                                       ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                           [2U][1U]) 
                                          | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][1U]))
                                       : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                            << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                           ? 0U : (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [2U][3U] 
                                                       >> 0xcU))
                                                    ? 
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [2U][0U])
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                         >> 1U));
        __Vtemp_106[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [2U][3U] 
                                          >> 0xcU))
                                       ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                           [2U][2U]) 
                                          | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][2U]))
                                       : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                            << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                           ? 0U : (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [2U][3U] 
                                                       >> 0xcU))
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [2U][1U]) 
                                                    | (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [2U][1U]))
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                         >> 1U));
        __Vtemp_106[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [2U][3U] 
                                          >> 0xcU))
                                       ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                           [2U][3U]) 
                                          | (0xffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][3U]))
                                       : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                            << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                           ? 0U : (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [2U][3U] 
                                                       >> 0xcU))
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [2U][2U]) 
                                                    | (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [2U][2U]))
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                         >> 1U));
        __Vtemp_109[0U] = ((__Vtemp_106[0U] << 1U) 
                           | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        __Vtemp_109[1U] = ((__Vtemp_106[0U] >> 0x1fU) 
                           | (__Vtemp_106[1U] << 1U));
        __Vtemp_109[2U] = ((__Vtemp_106[1U] >> 0x1fU) 
                           | (__Vtemp_106[2U] << 1U));
        __Vtemp_109[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                            << 0xcU) | ((__Vtemp_106[2U] 
                                         >> 0x1fU) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0xffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][3U] 
                                                   >> 0xcU))
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [2U][3U]) 
                                                   | (0xffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [2U][3U]))
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
        bufp->chgWData(oldp+156,(__Vtemp_109),109);
        bufp->chgBit(oldp+160,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][0U])
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_125[0U] = 0U;
            __Vtemp_125[1U] = 0U;
            __Vtemp_125[2U] = 0U;
            __Vtemp_125[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [2U][3U] >> 0xcU))) {
            __Vtemp_125[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [2U][0U]);
            __Vtemp_125[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][1U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][1U]));
            __Vtemp_125[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][2U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][2U]));
            __Vtemp_125[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][3U]) | (0xffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][3U]));
        } else {
            __Vtemp_125[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_125[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_125[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_125[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+161,(__Vtemp_125),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                [2U][3U] >> 0xcU))) {
            __Vtemp_131[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [2U][0U]);
            __Vtemp_131[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][1U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][1U]));
            __Vtemp_131[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][2U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][2U]));
            __Vtemp_131[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][3U]) | (0xffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [2U][3U]));
        } else {
            __Vtemp_131[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_131[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_131[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_131[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+165,(__Vtemp_131),108);
        __Vtemp_141[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [3U][3U] 
                                          >> 0xcU))
                                       ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                           [3U][1U]) 
                                          | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][1U]))
                                       : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                            << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                           ? 0U : (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [3U][3U] 
                                                       >> 0xcU))
                                                    ? 
                                                   (0xfffffffeU 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [3U][0U])
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                         >> 1U));
        __Vtemp_141[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [3U][3U] 
                                          >> 0xcU))
                                       ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                           [3U][2U]) 
                                          | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][2U]))
                                       : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                            << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                           ? 0U : (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [3U][3U] 
                                                       >> 0xcU))
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [3U][1U]) 
                                                    | (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [3U][1U]))
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                         >> 1U));
        __Vtemp_141[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                          [3U][3U] 
                                          >> 0xcU))
                                       ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                           [3U][3U]) 
                                          | (0xffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][3U]))
                                       : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                            << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                           ? 0U : (
                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [3U][3U] 
                                                       >> 0xcU))
                                                    ? 
                                                   ((1U 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [3U][2U]) 
                                                    | (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [3U][2U]))
                                                    : 
                                                   vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                         >> 1U));
        __Vtemp_144[0U] = ((__Vtemp_141[0U] << 1U) 
                           | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        __Vtemp_144[1U] = ((__Vtemp_141[0U] >> 0x1fU) 
                           | (__Vtemp_141[1U] << 1U));
        __Vtemp_144[2U] = ((__Vtemp_141[1U] >> 0x1fU) 
                           | (__Vtemp_141[2U] << 1U));
        __Vtemp_144[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                            << 0xcU) | ((__Vtemp_141[2U] 
                                         >> 0x1fU) 
                                        | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                            ? 0U : 
                                           (0xffeU 
                                            & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][3U] 
                                                   >> 0xcU))
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [3U][3U]) 
                                                   | (0xffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [3U][3U]))
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
        bufp->chgWData(oldp+169,(__Vtemp_144),109);
        bufp->chgBit(oldp+173,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][0U])
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_160[0U] = 0U;
            __Vtemp_160[1U] = 0U;
            __Vtemp_160[2U] = 0U;
            __Vtemp_160[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [3U][3U] >> 0xcU))) {
            __Vtemp_160[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [3U][0U]);
            __Vtemp_160[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][1U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][1U]));
            __Vtemp_160[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][2U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][2U]));
            __Vtemp_160[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][3U]) | (0xffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][3U]));
        } else {
            __Vtemp_160[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_160[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_160[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_160[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+174,(__Vtemp_160),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                [3U][3U] >> 0xcU))) {
            __Vtemp_166[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                               [3U][0U]);
            __Vtemp_166[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][1U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][1U]));
            __Vtemp_166[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][2U]) | (0xfffffffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][2U]));
            __Vtemp_166[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][3U]) | (0xffeU 
                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                             [3U][3U]));
        } else {
            __Vtemp_166[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_166[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_166[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_166[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+178,(__Vtemp_166),108);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [0xaU]) | vlSelfRef.__Vm_traceActivity
                      [0x1aU])))) {
        bufp->chgWData(oldp+182,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0]),66);
        bufp->chgWData(oldp+185,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1]),66);
        bufp->chgWData(oldp+188,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2]),66);
        bufp->chgWData(oldp+191,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3]),66);
        bufp->chgWData(oldp+194,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4]),66);
        bufp->chgBit(oldp+197,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+198,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+199,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+200,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+201,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+202,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+203,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+204,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+205,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+206,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+207,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+208,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+209,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+210,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+211,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+212,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+213,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+214,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+215,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+216,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xbU])))) {
        bufp->chgBit(oldp+217,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+218,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+219,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+220,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+221,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+222,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+223,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+224,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+225,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+226,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [0xbU]) | vlSelfRef.__Vm_traceActivity
                      [0x14U])))) {
        bufp->chgBit(oldp+227,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U])
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_182[0U] = 0U;
            __Vtemp_182[1U] = 0U;
            __Vtemp_182[2U] = 0U;
            __Vtemp_182[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                       >> 0xcU))) {
            __Vtemp_182[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_182[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_182[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_182[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_182[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_182[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_182[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_182[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+228,(__Vtemp_182),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                >> 0xcU))) {
            __Vtemp_188[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_188[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_188[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_188[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_188[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_188[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_188[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_188[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+232,(__Vtemp_188),108);
        bufp->chgBit(oldp+236,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U])
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_204[0U] = 0U;
            __Vtemp_204[1U] = 0U;
            __Vtemp_204[2U] = 0U;
            __Vtemp_204[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                       >> 0xcU))) {
            __Vtemp_204[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_204[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_204[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_204[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_204[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_204[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_204[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_204[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+237,(__Vtemp_204),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                >> 0xcU))) {
            __Vtemp_210[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_210[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_210[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_210[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_210[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_210[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_210[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_210[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+241,(__Vtemp_210),108);
        bufp->chgBit(oldp+245,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U])
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_226[0U] = 0U;
            __Vtemp_226[1U] = 0U;
            __Vtemp_226[2U] = 0U;
            __Vtemp_226[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                       >> 0xcU))) {
            __Vtemp_226[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_226[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_226[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_226[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_226[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_226[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_226[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_226[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+246,(__Vtemp_226),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                >> 0xcU))) {
            __Vtemp_232[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_232[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_232[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_232[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_232[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_232[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_232[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_232[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+250,(__Vtemp_232),108);
        bufp->chgBit(oldp+254,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U])
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_248[0U] = 0U;
            __Vtemp_248[1U] = 0U;
            __Vtemp_248[2U] = 0U;
            __Vtemp_248[3U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                       >> 0xcU))) {
            __Vtemp_248[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_248[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_248[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_248[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_248[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_248[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_248[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_248[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+255,(__Vtemp_248),108);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                >> 0xcU))) {
            __Vtemp_254[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
            __Vtemp_254[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
            __Vtemp_254[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
            __Vtemp_254[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
        } else {
            __Vtemp_254[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_254[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_254[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_254[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+259,(__Vtemp_254),108);
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [3U] | vlSelfRef.__Vm_traceActivity
                        [0xbU]) | vlSelfRef.__Vm_traceActivity
                       [0x14U]) | vlSelfRef.__Vm_traceActivity
                      [0x1bU])))) {
        bufp->chgBit(oldp+263,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U])
                                                : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_270[0U] = 0U;
            __Vtemp_270[1U] = 0U;
            __Vtemp_270[2U] = 0U;
            __Vtemp_270[3U] = 0U;
        } else if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                       >> 0xcU))) {
            __Vtemp_270[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
            __Vtemp_270[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
            __Vtemp_270[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
            __Vtemp_270[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
        } else {
            __Vtemp_270[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_270[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_270[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_270[3U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+264,(__Vtemp_270),108);
        if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                >> 0xcU))) {
            __Vtemp_276[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
            __Vtemp_276[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
            __Vtemp_276[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
            __Vtemp_276[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
        } else {
            __Vtemp_276[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_276[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_276[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
            __Vtemp_276[3U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
        }
        bufp->chgWData(oldp+268,(__Vtemp_276),108);
        __Vtemp_281[1U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [0U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [0U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [0U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            >> 0x1fU) | ((IData)(((
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [0U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                         ? 0U
                                                                         : 
                                                                        (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                          & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                             [0U][2U] 
                                                                             >> 1U))
                                                                          ? 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                          : 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                           ? 0U
                                                                           : 
                                                                          (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                            & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                               [0U][2U] 
                                                                               >> 1U))
                                                                            ? 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                            : 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                         >> 1U))) 
                                                  >> 0x20U)) 
                                         << 1U));
        __Vtemp_282[0U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [0U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [0U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [0U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        __Vtemp_282[1U] = __Vtemp_281[1U];
        __Vtemp_282[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                            << 1U) | ((IData)(((((QData)((IData)(
                                                                 ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                   ? 0U
                                                                   : 
                                                                  (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                       [0U][2U] 
                                                                       >> 1U))
                                                                    ? 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                    : 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [0U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [0U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U))) 
                                               >> 0x20U)) 
                                      >> 0x1fU));
        bufp->chgWData(oldp+272,(__Vtemp_282),66);
        bufp->chgBit(oldp+275,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                   [0U][2U] 
                                                   >> 1U))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_290[0U] = 0U;
            __Vtemp_290[1U] = 0U;
            __Vtemp_290[2U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                       [0U][2U] >> 1U))) {
            __Vtemp_290[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_290[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_290[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_290[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_290[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_290[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+276,(__Vtemp_290),65);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                [0U][2U] >> 1U))) {
            __Vtemp_292[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_292[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_292[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_292[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_292[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_292[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+279,(__Vtemp_292),65);
        __Vtemp_297[1U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [1U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [1U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [1U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            >> 0x1fU) | ((IData)(((
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [1U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                         ? 0U
                                                                         : 
                                                                        (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                          & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                             [1U][2U] 
                                                                             >> 1U))
                                                                          ? 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                          : 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                           ? 0U
                                                                           : 
                                                                          (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                            & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                               [1U][2U] 
                                                                               >> 1U))
                                                                            ? 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                            : 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                         >> 1U))) 
                                                  >> 0x20U)) 
                                         << 1U));
        __Vtemp_298[0U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [1U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [1U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [1U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        __Vtemp_298[1U] = __Vtemp_297[1U];
        __Vtemp_298[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                            << 1U) | ((IData)(((((QData)((IData)(
                                                                 ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                   ? 0U
                                                                   : 
                                                                  (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                       [1U][2U] 
                                                                       >> 1U))
                                                                    ? 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                    : 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [1U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [1U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U))) 
                                               >> 0x20U)) 
                                      >> 0x1fU));
        bufp->chgWData(oldp+282,(__Vtemp_298),66);
        bufp->chgBit(oldp+285,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                   [1U][2U] 
                                                   >> 1U))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_306[0U] = 0U;
            __Vtemp_306[1U] = 0U;
            __Vtemp_306[2U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                       [1U][2U] >> 1U))) {
            __Vtemp_306[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_306[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_306[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_306[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_306[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_306[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+286,(__Vtemp_306),65);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                [1U][2U] >> 1U))) {
            __Vtemp_308[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_308[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_308[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_308[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_308[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_308[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+289,(__Vtemp_308),65);
        __Vtemp_313[1U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [2U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [2U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [2U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            >> 0x1fU) | ((IData)(((
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [2U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                         ? 0U
                                                                         : 
                                                                        (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                          & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                             [2U][2U] 
                                                                             >> 1U))
                                                                          ? 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                          : 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                           ? 0U
                                                                           : 
                                                                          (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                            & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                               [2U][2U] 
                                                                               >> 1U))
                                                                            ? 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                            : 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                         >> 1U))) 
                                                  >> 0x20U)) 
                                         << 1U));
        __Vtemp_314[0U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [2U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [2U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [2U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        __Vtemp_314[1U] = __Vtemp_313[1U];
        __Vtemp_314[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                            << 1U) | ((IData)(((((QData)((IData)(
                                                                 ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                   ? 0U
                                                                   : 
                                                                  (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                       [2U][2U] 
                                                                       >> 1U))
                                                                    ? 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                    : 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [2U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [2U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U))) 
                                               >> 0x20U)) 
                                      >> 0x1fU));
        bufp->chgWData(oldp+292,(__Vtemp_314),66);
        bufp->chgBit(oldp+295,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                   [2U][2U] 
                                                   >> 1U))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_322[0U] = 0U;
            __Vtemp_322[1U] = 0U;
            __Vtemp_322[2U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                       [2U][2U] >> 1U))) {
            __Vtemp_322[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_322[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_322[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_322[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_322[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_322[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+296,(__Vtemp_322),65);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                [2U][2U] >> 1U))) {
            __Vtemp_324[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_324[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_324[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_324[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_324[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_324[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+299,(__Vtemp_324),65);
        __Vtemp_329[1U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [3U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [3U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [3U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            >> 0x1fU) | ((IData)(((
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [3U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                         ? 0U
                                                                         : 
                                                                        (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                          & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                             [3U][2U] 
                                                                             >> 1U))
                                                                          ? 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                          : 
                                                                         vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                           ? 0U
                                                                           : 
                                                                          (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                            & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                               [3U][2U] 
                                                                               >> 1U))
                                                                            ? 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                            : 
                                                                           vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                         >> 1U))) 
                                                  >> 0x20U)) 
                                         << 1U));
        __Vtemp_330[0U] = (((IData)((((QData)((IData)(
                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                        ? 0U
                                                        : 
                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                            [3U][2U] 
                                                            >> 1U))
                                                         ? 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                         : 
                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [3U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [3U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U)))) 
                            << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        __Vtemp_330[1U] = __Vtemp_329[1U];
        __Vtemp_330[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                            << 1U) | ((IData)(((((QData)((IData)(
                                                                 ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                   ? 0U
                                                                   : 
                                                                  (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                       [3U][2U] 
                                                                       >> 1U))
                                                                    ? 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                    : 
                                                                   vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                      ? 0U
                                                                      : 
                                                                     (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                       & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                          [3U][2U] 
                                                                          >> 1U))
                                                                       ? 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                       : 
                                                                      vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                        ? 0U
                                                                        : 
                                                                       (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                            [3U][2U] 
                                                                            >> 1U))
                                                                         ? 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                         : 
                                                                        vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                      >> 1U))) 
                                               >> 0x20U)) 
                                      >> 0x1fU));
        bufp->chgWData(oldp+302,(__Vtemp_330),66);
        bufp->chgBit(oldp+305,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                 ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                   [3U][2U] 
                                                   >> 1U))
                                                ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
        if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
            __Vtemp_338[0U] = 0U;
            __Vtemp_338[1U] = 0U;
            __Vtemp_338[2U] = 0U;
        } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                    & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                       [3U][2U] >> 1U))) {
            __Vtemp_338[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_338[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_338[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_338[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_338[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_338[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+306,(__Vtemp_338),65);
        if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                [3U][2U] >> 1U))) {
            __Vtemp_340[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
            __Vtemp_340[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
            __Vtemp_340[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
        } else {
            __Vtemp_340[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
            __Vtemp_340[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
            __Vtemp_340[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        }
        bufp->chgWData(oldp+309,(__Vtemp_340),65);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [3U] | vlSelfRef.__Vm_traceActivity
                       [0xbU]) | vlSelfRef.__Vm_traceActivity
                      [0x1bU])))) {
        bufp->chgCData(oldp+312,(((((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                     & (IData)(((0x60000U 
                                                 == 
                                                 (0x60000U 
                                                  & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                    << 3U) | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                               & (IData)(
                                                         ((0x40000U 
                                                           == 
                                                           (0x60000U 
                                                            & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                          & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                              << 2U)) 
                                  | (((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                       & (IData)(((0x20000U 
                                                   == 
                                                   (0x60000U 
                                                    & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                  & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                      << 1U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                                & (IData)(
                                                          ((0U 
                                                            == 
                                                            (0x60000U 
                                                             & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                           & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o))))))),4);
        bufp->chgBit(oldp+313,(((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                 & (IData)(((0x60000U 
                                             == (0x60000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                            & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                    & (IData)(((0x40000U 
                                                == 
                                                (0x60000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                               & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                   | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                       & (IData)(((0x20000U 
                                                   == 
                                                   (0x60000U 
                                                    & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                  & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                      | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                         & (IData)(
                                                   ((0U 
                                                     == 
                                                     (0x60000U 
                                                      & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                    & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))))))));
        bufp->chgBit(oldp+314,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+315,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+316,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+317,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+318,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+319,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+320,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+321,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+322,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+323,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+324,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+325,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+326,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+327,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+328,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+329,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+330,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+331,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+332,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+333,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xfU])))) {
        bufp->chgWData(oldp+334,(vlSelfRef.tlul_adapter_host__DOT__tl_out),109);
        bufp->chgCData(oldp+338,(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d),2);
        bufp->chgBit(oldp+339,(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d));
        bufp->chgCData(oldp+340,((0x7fU & (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                           >> 8U))),7);
        bufp->chgIData(oldp+341,(((vlSelfRef.tlul_adapter_host__DOT__tl_out[1U] 
                                   << 8U) | (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                             >> 0x18U))),32);
        bufp->chgCData(oldp+342,((0x7fU & (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                           >> 1U))),7);
        bufp->chgBit(oldp+343,((1U & VL_REDXOR_32((
                                                   ((vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                                     ^ 
                                                     vlSelfRef.tlul_adapter_host__DOT__tl_out[1U]) 
                                                    ^ 
                                                    vlSelfRef.tlul_adapter_host__DOT__tl_out[2U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_adapter_host__DOT__tl_out[3U])))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x10U])))) {
        bufp->chgBit(oldp+344,(vlSelfRef.prim_fifo_async_simple__DOT__wr_en));
        bufp->chgBit(oldp+345,(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
        bufp->chgBit(oldp+346,(((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
                                & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
                                   | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)))));
        bufp->chgBit(oldp+347,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns));
        bufp->chgBit(oldp+348,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x18U])))) {
        bufp->chgBit(oldp+349,(vlSelfRef.tlul_adapter_reg__DOT__a_ack));
        bufp->chgBit(oldp+350,(vlSelfRef.tlul_adapter_reg__DOT__err_internal));
        bufp->chgBit(oldp+351,(vlSelfRef.tlul_adapter_reg__DOT__rd_req));
        bufp->chgBit(oldp+352,(vlSelfRef.tlul_adapter_reg__DOT__wr_req));
        bufp->chgWData(oldp+353,(vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre),66);
        bufp->chgBit(oldp+356,((1U & VL_REDXOR_32((
                                                   (vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[0U] 
                                                    ^ 
                                                    vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[1U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U])))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x1aU])))) {
        bufp->chgCData(oldp+357,((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])),3);
        bufp->chgWData(oldp+358,(vlSelfRef.tlul_socket_1n__DOT__tl_t_o),109);
        __Vtemp_344[0U] = ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U]) 
                           | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
        __Vtemp_344[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]));
        __Vtemp_344[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]) 
                           | (2U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]));
        bufp->chgWData(oldp+362,(__Vtemp_344),66);
        bufp->chgBit(oldp+365,(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests));
        bufp->chgBit(oldp+366,(vlSelfRef.tlul_socket_1n__DOT__accept_t_req));
        bufp->chgBit(oldp+367,(vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp));
        bufp->chgWData(oldp+368,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0]),109);
        bufp->chgWData(oldp+372,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1]),109);
        bufp->chgWData(oldp+376,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2]),109);
        bufp->chgWData(oldp+380,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3]),109);
        bufp->chgWData(oldp+384,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4]),109);
        bufp->chgIData(oldp+388,(vlSelfRef.tlul_socket_1n__DOT__blanked_auser),23);
        bufp->chgWData(oldp+389,(vlSelfRef.tlul_socket_1n__DOT__tl_t_p),66);
        bufp->chgBit(oldp+392,(vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready));
        bufp->chgBit(oldp+393,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
        bufp->chgWData(oldp+394,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o),110);
        bufp->chgBit(oldp+398,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+399,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+400,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                      >> 1U))));
        bufp->chgWData(oldp+401,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+404,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+405,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+406,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+407,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+408,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [4U]),109);
        bufp->chgBit(oldp+412,((1U & VL_REDXOR_32((
                                                   ((vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [4U][0U] 
                                                     ^ 
                                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [4U][1U]) 
                                                    ^ 
                                                    vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [4U][2U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [4U][3U])))));
        bufp->chgBit(oldp+413,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select));
        bufp->chgBit(oldp+414,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select));
        bufp->chgBit(oldp+415,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select));
        bufp->chgBit(oldp+416,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select));
        bufp->chgWData(oldp+417,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [0U]),109);
        bufp->chgBit(oldp+421,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][3U] >> 0xcU))));
        __Vtemp_348[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][0U]);
        __Vtemp_348[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [0U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [0U][1U]));
        __Vtemp_348[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [0U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [0U][2U]));
        __Vtemp_348[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [0U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [0U][3U]));
        bufp->chgWData(oldp+422,(__Vtemp_348),108);
        bufp->chgBit(oldp+426,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+427,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+428,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+429,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+430,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [0U][0U])));
        bufp->chgBit(oldp+431,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+432,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+433,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [1U]),109);
        bufp->chgBit(oldp+437,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][3U] >> 0xcU))));
        __Vtemp_352[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][0U]);
        __Vtemp_352[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [1U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [1U][1U]));
        __Vtemp_352[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [1U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [1U][2U]));
        __Vtemp_352[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [1U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [1U][3U]));
        bufp->chgWData(oldp+438,(__Vtemp_352),108);
        bufp->chgBit(oldp+442,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+443,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+444,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+445,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+446,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [1U][0U])));
        bufp->chgBit(oldp+447,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+448,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+449,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [2U]),109);
        bufp->chgBit(oldp+453,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][3U] >> 0xcU))));
        __Vtemp_356[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [2U][0U]);
        __Vtemp_356[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][1U]));
        __Vtemp_356[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][2U]));
        __Vtemp_356[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][3U]));
        bufp->chgWData(oldp+454,(__Vtemp_356),108);
        bufp->chgBit(oldp+458,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+459,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+460,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+461,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+462,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][0U])));
        bufp->chgBit(oldp+463,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+464,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+465,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [3U]),109);
        bufp->chgBit(oldp+469,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][3U] >> 0xcU))));
        __Vtemp_360[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [3U][0U]);
        __Vtemp_360[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][1U]));
        __Vtemp_360[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][2U]));
        __Vtemp_360[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][3U]));
        bufp->chgWData(oldp+470,(__Vtemp_360),108);
        bufp->chgBit(oldp+474,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+475,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+476,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+477,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+478,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][0U])));
        bufp->chgBit(oldp+479,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+480,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x1bU])))) {
        bufp->chgWData(oldp+481,(vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o),436);
        bufp->chgWData(oldp+495,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0]),66);
        bufp->chgWData(oldp+498,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1]),66);
        bufp->chgWData(oldp+501,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2]),66);
        bufp->chgWData(oldp+504,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3]),66);
        bufp->chgCData(oldp+507,(vlSelfRef.tlul_socket_m1__DOT__hrequest),4);
        bufp->chgCData(oldp+508,(vlSelfRef.tlul_socket_m1__DOT__hgrant),4);
        bufp->chgWData(oldp+509,(vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i),109);
        bufp->chgWData(oldp+513,(vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o),66);
        bufp->chgBit(oldp+516,((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest))));
        bufp->chgWData(oldp+517,(vlSelfRef.tlul_socket_m1__DOT__arb_data),109);
        bufp->chgCData(oldp+521,(((((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__3__KET__) 
                                    << 3U) | ((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__2__KET__) 
                                              << 2U)) 
                                  | (((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__1__KET__) 
                                      << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__0__KET__)))),4);
        bufp->chgCData(oldp+522,((0x3fU & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                           >> 0x13U))),8);
        bufp->chgCData(oldp+523,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__idx_o),2);
        bufp->chgCData(oldp+524,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req),4);
        bufp->chgCData(oldp+525,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out),4);
        bufp->chgCData(oldp+526,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req),4);
        bufp->chgCData(oldp+527,((0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U))),4);
        bufp->chgCData(oldp+528,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner),4);
        bufp->chgIData(oldp+529,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__sv2v_autoblock_3__DOT__i),32);
        bufp->chgBit(oldp+530,((1U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
        bufp->chgBit(oldp+531,((1U & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                      >> 0xcU))));
        __Vtemp_364[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
        __Vtemp_364[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
        __Vtemp_364[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
        __Vtemp_364[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
        bufp->chgWData(oldp+532,(__Vtemp_364),108);
        bufp->chgBit(oldp+536,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+537,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+538,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+539,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+540,((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U])));
        bufp->chgWData(oldp+541,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o),65);
        bufp->chgBit(oldp+544,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+545,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+546,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+550,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [0U]),66);
        bufp->chgBit(oldp+553,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [0U][0U])));
        bufp->chgBit(oldp+554,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+555,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+556,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [0U][2U] >> 1U))));
        bufp->chgWData(oldp+557,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+560,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+561,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+562,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+563,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+564,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+568,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [1U]),66);
        bufp->chgBit(oldp+571,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [1U][0U])));
        bufp->chgBit(oldp+572,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+573,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+574,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [1U][2U] >> 1U))));
        bufp->chgWData(oldp+575,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+578,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+579,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+580,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+581,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+582,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+586,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [2U]),66);
        bufp->chgBit(oldp+589,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [2U][0U])));
        bufp->chgBit(oldp+590,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+591,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+592,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [2U][2U] >> 1U))));
        bufp->chgWData(oldp+593,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+596,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+597,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+598,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+599,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+600,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+604,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [3U]),66);
        bufp->chgBit(oldp+607,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [3U][0U])));
        bufp->chgBit(oldp+608,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+609,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+610,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [3U][2U] >> 1U))));
        bufp->chgWData(oldp+611,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+614,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+615,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+616,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+617,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x1dU])))) {
        bufp->chgWData(oldp+618,(vlSelfRef.tlul_adapter_sram__DOT__tl_o_int),66);
        bufp->chgBit(oldp+621,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready));
        bufp->chgBit(oldp+622,((IData)(((0x8000U == 
                                         (0x1c000U 
                                          & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                        & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready)))));
        bufp->chgQData(oldp+623,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata),40);
        bufp->chgQData(oldp+625,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata),40);
        bufp->chgBit(oldp+627,(vlSelfRef.tlul_adapter_sram__DOT__d_valid));
        bufp->chgBit(oldp+628,(vlSelfRef.tlul_adapter_sram__DOT__d_error));
        bufp->chgBit(oldp+629,(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp));
        bufp->chgIData(oldp+630,((((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                                   & (IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp))
                                   ? (IData)((vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                              >> 8U))
                                   : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data)),32);
        bufp->chgCData(oldp+631,((0x7fU & (((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp) 
                                            & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                               >> 0xeU))
                                            ? (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ)
                                            : ((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp)
                                                ? (IData)(
                                                          (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                           >> 1U))
                                                : 0x2aU)))),7);
        bufp->chgBit(oldp+632,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+633,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+634,((1U & VL_REDXOR_32((
                                                   (vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U] 
                                                    ^ 
                                                    vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[1U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U])))));
        bufp->chgBit(oldp+635,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+636,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+637,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgCData(oldp+638,(vlSelfRef.pwm_ramp_tb__DOT__adc_value_o),6);
        bufp->chgBit(oldp+639,(vlSelfRef.pwm_ramp_tb__DOT__adc_valid_o));
        bufp->chgDouble(oldp+640,((1.58730158730158721e-02 
                                   * VL_ITOR_D_I(6, (IData)(vlSelfRef.pwm_ramp_tb__DOT__adc_value_o)))));
        bufp->chgDouble(oldp+642,((1.0 * vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev)));
        bufp->chgCData(oldp+644,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle),6);
        bufp->chgCData(oldp+645,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter),6);
        bufp->chgBit(oldp+646,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear));
        bufp->chgBit(oldp+647,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds));
        bufp->chgBit(oldp+648,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds_rise));
        bufp->chgBit(oldp+649,(((~ (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds)) 
                                & (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q))));
        bufp->chgCData(oldp+650,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q),2);
        bufp->chgBit(oldp+651,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__d_s));
        bufp->chgBit(oldp+652,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
        bufp->chgBit(oldp+653,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q));
        bufp->chgDouble(oldp+654,(vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgCData(oldp+656,(vlSelfRef.multiple_pwm_ramp__DOT__adc_value_0),8);
        bufp->chgCData(oldp+657,(vlSelfRef.multiple_pwm_ramp__DOT__adc_value_1),8);
        bufp->chgBit(oldp+658,(vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_0));
        bufp->chgBit(oldp+659,(vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_1));
        bufp->chgCData(oldp+660,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle),8);
        bufp->chgCData(oldp+661,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter),8);
        bufp->chgBit(oldp+662,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear));
        bufp->chgBit(oldp+663,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds));
        bufp->chgBit(oldp+664,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds_rise));
        bufp->chgBit(oldp+665,(((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds)) 
                                & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q))));
        bufp->chgCData(oldp+666,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q),2);
        bufp->chgBit(oldp+667,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__d_s));
        bufp->chgBit(oldp+668,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
        bufp->chgBit(oldp+669,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q));
        bufp->chgCData(oldp+670,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle),8);
        bufp->chgCData(oldp+671,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter),8);
        bufp->chgBit(oldp+672,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear));
        bufp->chgBit(oldp+673,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds));
        bufp->chgBit(oldp+674,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds_rise));
        bufp->chgBit(oldp+675,(((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds)) 
                                & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q))));
        bufp->chgCData(oldp+676,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q),2);
        bufp->chgBit(oldp+677,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__d_s));
        bufp->chgBit(oldp+678,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
        bufp->chgBit(oldp+679,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgCData(oldp+680,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray),5);
        bufp->chgCData(oldp+681,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr),5);
        bufp->chgCData(oldp+682,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))),4);
        bufp->chgBit(oldp+683,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr) 
                                      >> 4U))));
        bufp->chgCData(oldp+684,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q),5);
        bufp->chgCData(oldp+685,((0x1fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)))),5);
        bufp->chgCData(oldp+686,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))),4);
        bufp->chgBit(oldp+687,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                      >> 4U))));
        bufp->chgBit(oldp+688,(((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                == (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))));
        bufp->chgBit(oldp+689,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored));
        bufp->chgIData(oldp+690,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q),32);
        bufp->chgCData(oldp+691,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr),5);
        bufp->chgBit(oldp+692,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty));
        bufp->chgCData(oldp+693,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgWData(oldp+694,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[0]),107);
        bufp->chgWData(oldp+698,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[1]),107);
        bufp->chgWData(oldp+702,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[2]),107);
        bufp->chgWData(oldp+706,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[3]),107);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[7U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x17U])))) {
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk) {
            __Vtemp_366[0U] = 0U;
            __Vtemp_366[1U] = 0U;
            __Vtemp_366[2U] = 0U;
            __Vtemp_366[3U] = 0U;
        } else {
            __Vtemp_366[0U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U];
            __Vtemp_366[1U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U];
            __Vtemp_366[2U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U];
            __Vtemp_366[3U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][3U];
        }
        bufp->chgWData(oldp+710,(__Vtemp_366),107);
        bufp->chgWData(oldp+714,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                 [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))]),107);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgQData(oldp+718,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[0]),64);
        bufp->chgQData(oldp+720,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[1]),64);
        bufp->chgQData(oldp+722,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[2]),64);
        bufp->chgQData(oldp+724,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[3]),64);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgBit(oldp+726,(vlSelfRef.tlul_adapter_sram__DOT__intg_error_q));
        bufp->chgBit(oldp+727,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready));
        bufp->chgBit(oldp+728,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid));
        bufp->chgBit(oldp+729,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
        bufp->chgBit(oldp+730,((1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)) 
                                      & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))))));
        bufp->chgBit(oldp+731,(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q));
        bufp->chgBit(oldp+732,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o));
        bufp->chgBit(oldp+733,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+734,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+735,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+736,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+737,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+738,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+739,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+740,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+741,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+742,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+743,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+744,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+745,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o));
        bufp->chgBit(oldp+746,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+747,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+748,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+749,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+750,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+751,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+752,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+753,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+754,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+755,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+756,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+757,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+758,((1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                                      & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))))));
        bufp->chgBit(oldp+759,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o));
        bufp->chgBit(oldp+760,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__depth_o));
        bufp->chgBit(oldp+761,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+762,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+763,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+764,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+765,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+766,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+767,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+768,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+769,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+770,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+771,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xaU]))) {
        bufp->chgSData(oldp+772,(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding),9);
        bufp->chgCData(oldp+773,(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding),3);
        bufp->chgBit(oldp+774,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+775,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+776,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+777,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+778,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+779,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+780,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+781,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+782,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+783,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+784,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+785,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+786,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+787,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+788,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+789,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+790,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+791,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+792,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+793,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+794,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+795,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+796,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+797,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+798,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+799,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+800,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+801,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgWData(oldp+802,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int),66);
        bufp->chgCData(oldp+805,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode),3);
        bufp->chgCData(oldp+806,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source),8);
        bufp->chgCData(oldp+807,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size),2);
        bufp->chgBit(oldp+808,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending));
        bufp->chgCData(oldp+809,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type),4);
        bufp->chgBit(oldp+810,((1U & VL_REDXOR_32((
                                                   (vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
                                                    ^ 
                                                    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U])))));
        bufp->chgBit(oldp+811,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+812,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+813,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+814,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+815,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+816,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+817,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+818,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+819,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+820,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+821,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+822,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+823,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+824,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+825,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+826,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+827,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+828,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+829,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+830,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+831,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+832,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+833,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+834,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+835,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+836,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+837,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+838,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+839,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+840,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+841,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+842,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+843,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+844,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+845,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+846,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+847,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+848,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+849,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+850,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+851,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+852,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+853,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+854,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+855,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+856,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+857,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+858,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+859,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+860,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+861,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+862,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+863,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+864,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+865,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+866,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+867,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+868,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+869,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+870,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+871,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+872,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+873,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+874,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+875,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+876,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+877,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+878,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+879,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+880,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+881,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+882,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+883,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+884,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+885,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+886,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+887,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+888,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+889,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+890,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+891,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+892,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+893,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+894,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+895,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+896,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+897,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+898,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+899,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+900,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+901,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+902,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+903,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+904,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+905,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+906,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+907,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+908,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+909,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+910,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+911,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+912,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+913,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+914,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+915,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+916,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+917,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+918,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+919,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+920,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+921,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+922,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xbU]))) {
        bufp->chgBit(oldp+923,(vlSelfRef.tlul_socket_m1__DOT__arb_ready));
        bufp->chgCData(oldp+924,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask),4);
        bufp->chgBit(oldp+925,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+926,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+927,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+928,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+929,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+930,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+931,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+932,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+933,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+934,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+935,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+936,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+937,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+938,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+939,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+940,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+941,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+942,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+943,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+944,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+945,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+946,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+947,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+948,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+949,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+950,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+951,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+952,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+953,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+954,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+955,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+956,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+957,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+958,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+959,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+960,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+961,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+962,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+963,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+964,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+965,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+966,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+967,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+968,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+969,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+970,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+971,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+972,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+973,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+974,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+975,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+976,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+977,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+978,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+979,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+980,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+981,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+982,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+983,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+984,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+985,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+986,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+987,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+988,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+989,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+990,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+991,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+992,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+993,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+994,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+995,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+996,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+997,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+998,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+999,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1000,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1001,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1002,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1003,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1004,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1005,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1006,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1007,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1008,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+1009,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+1010,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+1011,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1012,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1013,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1014,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1015,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1016,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1017,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1018,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1019,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1020,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1021,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1022,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+1023,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+1024,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+1025,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1026,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1027,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1028,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1029,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1030,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1031,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1032,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1033,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1034,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1035,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1036,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+1037,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+1038,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+1039,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1040,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1041,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1042,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1043,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1044,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1045,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1046,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1047,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1048,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1049,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1050,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+1051,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+1052,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+1053,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1054,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1055,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1056,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1057,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1058,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1059,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1060,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1061,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1062,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1063,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xcU]))) {
        bufp->chgBit(oldp+1064,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_sva));
        bufp->chgBit(oldp+1065,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_d_error_sva));
        bufp->chgBit(oldp+1066,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_sva));
        bufp->chgBit(oldp+1067,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_d_error_sva));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xdU]))) {
        bufp->chgCData(oldp+1068,(vlSelfRef.prim_filter__DOT__stored_vector_q),4);
        bufp->chgBit(oldp+1069,(vlSelfRef.prim_filter__DOT__stored_value_q));
        bufp->chgBit(oldp+1070,((1U & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                       >> 3U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xeU]))) {
        bufp->chgCData(oldp+1071,(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q),2);
        bufp->chgBit(oldp+1072,(vlSelfRef.prim_filter_ctr__DOT__filter_q));
        bufp->chgBit(oldp+1073,(vlSelfRef.prim_filter_ctr__DOT__stored_value_q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xfU]))) {
        bufp->chgCData(oldp+1074,(vlSelfRef.tlul_adapter_host__DOT__tl_source),8);
        bufp->chgCData(oldp+1075,(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q),2);
        bufp->chgBit(oldp+1076,(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x10U]))) {
        bufp->chgBit(oldp+1077,(vlSelfRef.prim_fifo_async_simple__DOT__src_ack));
        bufp->chgBit(oldp+1078,(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
        bufp->chgBit(oldp+1079,(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
        bufp->chgBit(oldp+1080,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs));
        bufp->chgBit(oldp+1081,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack));
        bufp->chgBit(oldp+1082,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x11U]))) {
        bufp->chgWData(oldp+1083,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage),110);
        bufp->chgWData(oldp+1087,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1090,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1094,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1097,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1101,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1104,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1108,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1111,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1115,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x12U]))) {
        bufp->chgWData(oldp+1118,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req),2560);
        bufp->chgWData(oldp+1198,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req),2560);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x13U]))) {
        bufp->chgBit(oldp+1278,(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
        bufp->chgBit(oldp+1279,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs));
        bufp->chgBit(oldp+1280,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q));
        bufp->chgBit(oldp+1281,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req));
        bufp->chgBit(oldp+1282,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x14U]))) {
        bufp->chgWData(oldp+1283,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1287,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1290,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1294,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1297,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1301,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1304,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1308,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1311,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1315,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x15U]))) {
        bufp->chgCData(oldp+1318,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q),5);
        bufp->chgCData(oldp+1319,((0x1fU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)))),5);
        bufp->chgCData(oldp+1320,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d),5);
        bufp->chgCData(oldp+1321,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q),5);
        bufp->chgCData(oldp+1322,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q))),4);
        bufp->chgBit(oldp+1323,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                                       >> 4U))));
        bufp->chgCData(oldp+1324,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray),5);
        bufp->chgCData(oldp+1325,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr),5);
        bufp->chgCData(oldp+1326,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr))),4);
        bufp->chgBit(oldp+1327,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr) 
                                       >> 4U))));
        bufp->chgCData(oldp+1328,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x16U]))) {
        bufp->chgBit(oldp+1329,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)))));
        bufp->chgCData(oldp+1330,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__wdepth_o),3);
        bufp->chgCData(oldp+1331,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q),3);
        bufp->chgCData(oldp+1332,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)))),3);
        bufp->chgCData(oldp+1333,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi),3);
        bufp->chgCData(oldp+1334,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync),3);
        bufp->chgCData(oldp+1335,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q),3);
        bufp->chgBit(oldp+1336,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk));
        bufp->chgBit(oldp+1337,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1338,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q) 
                                       >> 2U))));
        bufp->chgCData(oldp+1339,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q))),2);
        bufp->chgCData(oldp+1340,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q))),2);
        bufp->chgCData(oldp+1341,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq),3);
        bufp->chgBit(oldp+1342,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)))));
        bufp->chgCData(oldp+1343,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__rdepth_o),3);
        bufp->chgCData(oldp+1344,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q),3);
        bufp->chgCData(oldp+1345,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))),3);
        bufp->chgCData(oldp+1346,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi),3);
        bufp->chgCData(oldp+1347,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync),3);
        bufp->chgBit(oldp+1348,(((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                                 == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))));
        bufp->chgBit(oldp+1349,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk));
        bufp->chgBit(oldp+1350,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1351,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                                       >> 2U))));
        bufp->chgCData(oldp+1352,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))),2);
        bufp->chgCData(oldp+1353,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi))),2);
        bufp->chgCData(oldp+1354,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x17U]))) {
        bufp->chgBit(oldp+1355,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)))));
        bufp->chgCData(oldp+1356,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__rdepth_o),3);
        bufp->chgCData(oldp+1357,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q),3);
        bufp->chgCData(oldp+1358,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))),3);
        bufp->chgCData(oldp+1359,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi),3);
        bufp->chgCData(oldp+1360,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync),3);
        bufp->chgCData(oldp+1361,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q),3);
        bufp->chgCData(oldp+1362,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d),3);
        bufp->chgBit(oldp+1363,(((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                                 == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))));
        bufp->chgBit(oldp+1364,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk));
        bufp->chgBit(oldp+1365,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1366,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                                       >> 2U))));
        bufp->chgCData(oldp+1367,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))),2);
        bufp->chgCData(oldp+1368,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi))),2);
        bufp->chgCData(oldp+1369,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq),3);
        bufp->chgBit(oldp+1370,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)))));
        bufp->chgCData(oldp+1371,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__wdepth_o),3);
        bufp->chgCData(oldp+1372,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q),3);
        bufp->chgCData(oldp+1373,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)))),3);
        bufp->chgCData(oldp+1374,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi),3);
        bufp->chgCData(oldp+1375,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync),3);
        bufp->chgCData(oldp+1376,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q),3);
        bufp->chgCData(oldp+1377,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q),3);
        bufp->chgCData(oldp+1378,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d),3);
        bufp->chgBit(oldp+1379,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk));
        bufp->chgBit(oldp+1380,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1381,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q) 
                                       >> 2U))));
        bufp->chgCData(oldp+1382,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q))),2);
        bufp->chgCData(oldp+1383,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q))),2);
        bufp->chgCData(oldp+1384,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x18U]))) {
        bufp->chgBit(oldp+1385,(vlSelfRef.tlul_adapter_reg__DOT__outstanding_q));
        bufp->chgIData(oldp+1386,(vlSelfRef.tlul_adapter_reg__DOT__rdata_q),32);
        bufp->chgBit(oldp+1387,(vlSelfRef.tlul_adapter_reg__DOT__error_q));
        bufp->chgCData(oldp+1388,(vlSelfRef.tlul_adapter_reg__DOT__reqid_q),8);
        bufp->chgCData(oldp+1389,(vlSelfRef.tlul_adapter_reg__DOT__reqsz_q),2);
        bufp->chgCData(oldp+1390,(vlSelfRef.tlul_adapter_reg__DOT__rspop_q),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x19U]))) {
        bufp->chgIData(oldp+1391,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage),17);
        bufp->chgQData(oldp+1392,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage),40);
        bufp->chgCData(oldp+1394,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1cU]))) {
        bufp->chgCData(oldp+1395,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q),3);
        bufp->chgCData(oldp+1396,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d),3);
        bufp->chgCData(oldp+1397,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q),3);
        bufp->chgCData(oldp+1398,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1dU]))) {
        bufp->chgIData(oldp+1399,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata),17);
        bufp->chgCData(oldp+1400,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata),5);
        bufp->chgIData(oldp+1401,(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data),32);
        bufp->chgCData(oldp+1402,(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ),7);
        bufp->chgIData(oldp+1403,(vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask),32);
    }
    bufp->chgBit(oldp+1404,(vlSelfRef.prim_cdc_rand_delay__02Eclk_i));
    bufp->chgBit(oldp+1405,(vlSelfRef.prim_cdc_rand_delay__02Erst_ni));
    bufp->chgBit(oldp+1406,(vlSelfRef.prev_data_i));
    bufp->chgBit(oldp+1407,(vlSelfRef.src_data_i));
    bufp->chgBit(oldp+1408,(vlSelfRef.dst_data_o));
    bufp->chgBit(oldp+1409,(vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i));
    bufp->chgBit(oldp+1410,(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni));
    bufp->chgBit(oldp+1411,(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i));
    bufp->chgBit(oldp+1412,(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    bufp->chgSData(oldp+1413,(vlSelfRef.prim_fifo_async_simple__02Ewdata_i),16);
    bufp->chgBit(oldp+1414,(vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i));
    bufp->chgBit(oldp+1415,(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni));
    bufp->chgBit(oldp+1416,(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    bufp->chgBit(oldp+1417,(vlSelfRef.prim_fifo_async_simple__02Erready_i));
    bufp->chgSData(oldp+1418,(vlSelfRef.prim_fifo_async_simple__02Erdata_o),16);
    bufp->chgBit(oldp+1419,(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i));
    bufp->chgBit(oldp+1420,(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni));
    bufp->chgBit(oldp+1421,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    bufp->chgBit(oldp+1422,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
    bufp->chgIData(oldp+1423,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i),32);
    bufp->chgCData(oldp+1424,(vlSelfRef.wdepth_o),5);
    bufp->chgBit(oldp+1425,(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i));
    bufp->chgBit(oldp+1426,(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni));
    bufp->chgBit(oldp+1427,(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o));
    bufp->chgBit(oldp+1428,(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    bufp->chgIData(oldp+1429,(vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o),32);
    bufp->chgCData(oldp+1430,(vlSelfRef.rdepth_o),5);
    bufp->chgBit(oldp+1431,(vlSelfRef.r_full_o));
    bufp->chgBit(oldp+1432,(vlSelfRef.r_notempty_o));
    bufp->chgBit(oldp+1433,(vlSelfRef.w_full_o));
    bufp->chgBit(oldp+1434,(vlSelfRef.w_sram_req_o));
    bufp->chgBit(oldp+1435,(vlSelfRef.w_sram_gnt_i));
    bufp->chgBit(oldp+1436,(vlSelfRef.w_sram_write_o));
    bufp->chgSData(oldp+1437,(vlSelfRef.w_sram_addr_o),16);
    bufp->chgIData(oldp+1438,(vlSelfRef.w_sram_wdata_o),32);
    bufp->chgIData(oldp+1439,(vlSelfRef.w_sram_wmask_o),32);
    bufp->chgBit(oldp+1440,(vlSelfRef.w_sram_rvalid_i));
    bufp->chgIData(oldp+1441,(vlSelfRef.w_sram_rdata_i),32);
    bufp->chgCData(oldp+1442,(vlSelfRef.w_sram_rerror_i),2);
    bufp->chgBit(oldp+1443,(vlSelfRef.r_sram_req_o));
    bufp->chgBit(oldp+1444,(vlSelfRef.r_sram_gnt_i));
    bufp->chgBit(oldp+1445,(vlSelfRef.r_sram_write_o));
    bufp->chgSData(oldp+1446,(vlSelfRef.r_sram_addr_o),16);
    bufp->chgIData(oldp+1447,(vlSelfRef.r_sram_wdata_o),32);
    bufp->chgIData(oldp+1448,(vlSelfRef.r_sram_wmask_o),32);
    bufp->chgBit(oldp+1449,(vlSelfRef.r_sram_rvalid_i));
    bufp->chgIData(oldp+1450,(vlSelfRef.r_sram_rdata_i),32);
    bufp->chgCData(oldp+1451,(vlSelfRef.r_sram_rerror_i),2);
    bufp->chgBit(oldp+1452,(vlSelfRef.prim_filter__02Eclk_i));
    bufp->chgBit(oldp+1453,(vlSelfRef.prim_filter__02Erst_ni));
    bufp->chgBit(oldp+1454,(vlSelfRef.prim_filter__02Eenable_i));
    bufp->chgBit(oldp+1455,(vlSelfRef.prim_filter__02Efilter_i));
    bufp->chgBit(oldp+1456,(vlSelfRef.prim_filter__02Efilter_o));
    bufp->chgBit(oldp+1457,(vlSelfRef.prim_filter_ctr__02Eclk_i));
    bufp->chgBit(oldp+1458,(vlSelfRef.prim_filter_ctr__02Erst_ni));
    bufp->chgBit(oldp+1459,(vlSelfRef.prim_filter_ctr__02Eenable_i));
    bufp->chgBit(oldp+1460,(vlSelfRef.prim_filter_ctr__02Efilter_i));
    bufp->chgCData(oldp+1461,(vlSelfRef.thresh_i),2);
    bufp->chgBit(oldp+1462,(vlSelfRef.prim_filter_ctr__02Efilter_o));
    bufp->chgBit(oldp+1463,(vlSelfRef.prim_subreg__02Eclk_i));
    bufp->chgBit(oldp+1464,(vlSelfRef.prim_subreg__02Erst_ni));
    bufp->chgBit(oldp+1465,(vlSelfRef.prim_subreg__02Ewe));
    bufp->chgIData(oldp+1466,(vlSelfRef.prim_subreg__02Ewd),32);
    bufp->chgBit(oldp+1467,(vlSelfRef.de));
    bufp->chgIData(oldp+1468,(vlSelfRef.prim_subreg__02Ed),32);
    bufp->chgBit(oldp+1469,(vlSelfRef.prim_subreg__02Eqe));
    bufp->chgIData(oldp+1470,(vlSelfRef.prim_subreg__02Eq),32);
    bufp->chgIData(oldp+1471,(vlSelfRef.prim_subreg__02Eds),32);
    bufp->chgIData(oldp+1472,(vlSelfRef.prim_subreg__02Eqs),32);
    bufp->chgBit(oldp+1473,(vlSelfRef.re));
    bufp->chgBit(oldp+1474,(vlSelfRef.prim_subreg_ext__02Ewe));
    bufp->chgIData(oldp+1475,(vlSelfRef.prim_subreg_ext__02Ewd),32);
    bufp->chgIData(oldp+1476,(vlSelfRef.prim_subreg_ext__02Ed),32);
    bufp->chgBit(oldp+1477,(vlSelfRef.prim_subreg_ext__02Eqe));
    bufp->chgBit(oldp+1478,(vlSelfRef.qre));
    bufp->chgIData(oldp+1479,(vlSelfRef.prim_subreg_ext__02Eq),32);
    bufp->chgIData(oldp+1480,(vlSelfRef.prim_subreg_ext__02Eds),32);
    bufp->chgIData(oldp+1481,(vlSelfRef.prim_subreg_ext__02Eqs),32);
    bufp->chgBit(oldp+1482,(vlSelfRef.sram2tlul__02Eclk_i));
    bufp->chgBit(oldp+1483,(vlSelfRef.sram2tlul__02Erst_ni));
    bufp->chgWData(oldp+1484,(vlSelfRef.sram2tlul__02Etl_o),109);
    bufp->chgWData(oldp+1488,(vlSelfRef.sram2tlul__02Etl_i),66);
    bufp->chgBit(oldp+1491,(vlSelfRef.mem_req_i));
    bufp->chgBit(oldp+1492,(vlSelfRef.mem_write_i));
    bufp->chgSData(oldp+1493,(vlSelfRef.mem_addr_i),12);
    bufp->chgIData(oldp+1494,(vlSelfRef.mem_wdata_i),32);
    bufp->chgBit(oldp+1495,(vlSelfRef.mem_rvalid_o));
    bufp->chgIData(oldp+1496,(vlSelfRef.mem_rdata_o),32);
    bufp->chgCData(oldp+1497,(vlSelfRef.mem_error_o),2);
    bufp->chgBit(oldp+1498,(vlSelfRef.tlul_adapter_host__02Eclk_i));
    bufp->chgBit(oldp+1499,(vlSelfRef.tlul_adapter_host__02Erst_ni));
    bufp->chgBit(oldp+1500,(vlSelfRef.req_i));
    bufp->chgBit(oldp+1501,(vlSelfRef.gnt_o));
    bufp->chgIData(oldp+1502,(vlSelfRef.addr_i),32);
    bufp->chgBit(oldp+1503,(vlSelfRef.we_i));
    bufp->chgIData(oldp+1504,(vlSelfRef.tlul_adapter_host__02Ewdata_i),32);
    bufp->chgCData(oldp+1505,(vlSelfRef.wdata_intg_i),7);
    bufp->chgCData(oldp+1506,(vlSelfRef.be_i),4);
    bufp->chgCData(oldp+1507,(vlSelfRef.instr_type_i),4);
    bufp->chgBit(oldp+1508,(vlSelfRef.valid_o));
    bufp->chgIData(oldp+1509,(vlSelfRef.tlul_adapter_host__02Erdata_o),32);
    bufp->chgCData(oldp+1510,(vlSelfRef.rdata_intg_o),7);
    bufp->chgBit(oldp+1511,(vlSelfRef.err_o));
    bufp->chgBit(oldp+1512,(vlSelfRef.intg_err_o));
    bufp->chgWData(oldp+1513,(vlSelfRef.tlul_adapter_host__02Etl_o),109);
    bufp->chgWData(oldp+1517,(vlSelfRef.tlul_adapter_host__02Etl_i),66);
    bufp->chgBit(oldp+1520,(vlSelfRef.tlul_adapter_reg__02Eclk_i));
    bufp->chgBit(oldp+1521,(vlSelfRef.tlul_adapter_reg__02Erst_ni));
    bufp->chgWData(oldp+1522,(vlSelfRef.tlul_adapter_reg__02Etl_i),109);
    bufp->chgWData(oldp+1526,(vlSelfRef.tlul_adapter_reg__02Etl_o),66);
    bufp->chgCData(oldp+1529,(vlSelfRef.tlul_adapter_reg__02Een_ifetch_i),4);
    bufp->chgBit(oldp+1530,(vlSelfRef.tlul_adapter_reg__02Eintg_error_o));
    bufp->chgBit(oldp+1531,(vlSelfRef.re_o));
    bufp->chgBit(oldp+1532,(vlSelfRef.tlul_adapter_reg__02Ewe_o));
    bufp->chgCData(oldp+1533,(vlSelfRef.tlul_adapter_reg__02Eaddr_o),8);
    bufp->chgIData(oldp+1534,(vlSelfRef.tlul_adapter_reg__02Ewdata_o),32);
    bufp->chgCData(oldp+1535,(vlSelfRef.be_o),4);
    bufp->chgBit(oldp+1536,(vlSelfRef.busy_i));
    bufp->chgIData(oldp+1537,(vlSelfRef.tlul_adapter_reg__02Erdata_i),32);
    bufp->chgBit(oldp+1538,(vlSelfRef.error_i));
    bufp->chgBit(oldp+1539,(vlSelfRef.tlul_adapter_sram__02Eclk_i));
    bufp->chgBit(oldp+1540,(vlSelfRef.tlul_adapter_sram__02Erst_ni));
    bufp->chgWData(oldp+1541,(vlSelfRef.tlul_adapter_sram__02Etl_i),109);
    bufp->chgWData(oldp+1545,(vlSelfRef.tlul_adapter_sram__02Etl_o),66);
    bufp->chgCData(oldp+1548,(vlSelfRef.tlul_adapter_sram__02Een_ifetch_i),4);
    bufp->chgBit(oldp+1549,(vlSelfRef.req_o));
    bufp->chgCData(oldp+1550,(vlSelfRef.req_type_o),4);
    bufp->chgBit(oldp+1551,(vlSelfRef.gnt_i));
    bufp->chgBit(oldp+1552,(vlSelfRef.tlul_adapter_sram__02Ewe_o));
    bufp->chgSData(oldp+1553,(vlSelfRef.tlul_adapter_sram__02Eaddr_o),12);
    bufp->chgIData(oldp+1554,(vlSelfRef.tlul_adapter_sram__02Ewdata_o),32);
    bufp->chgIData(oldp+1555,(vlSelfRef.wmask_o),32);
    bufp->chgBit(oldp+1556,(vlSelfRef.tlul_adapter_sram__02Eintg_error_o));
    bufp->chgIData(oldp+1557,(vlSelfRef.tlul_adapter_sram__02Erdata_i),32);
    bufp->chgBit(oldp+1558,(vlSelfRef.rvalid_i));
    bufp->chgCData(oldp+1559,(vlSelfRef.rerror_i),2);
    bufp->chgBit(oldp+1560,(vlSelfRef.compound_txn_in_progress_o));
    bufp->chgCData(oldp+1561,(vlSelfRef.readback_en_i),4);
    bufp->chgBit(oldp+1562,(vlSelfRef.readback_error_o));
    bufp->chgBit(oldp+1563,(vlSelfRef.wr_collision_i));
    bufp->chgBit(oldp+1564,(vlSelfRef.write_pending_i));
    bufp->chgBit(oldp+1565,(vlSelfRef.tlul_assert_multiple__02Eclk_i));
    bufp->chgBit(oldp+1566,(vlSelfRef.tlul_assert_multiple__02Erst_ni));
    bufp->chgWData(oldp+1567,(vlSelfRef.h2d),218);
    bufp->chgWData(oldp+1574,(vlSelfRef.d2h),132);
    bufp->chgBit(oldp+1579,(vlSelfRef.clk_h_i));
    bufp->chgBit(oldp+1580,(vlSelfRef.rst_h_ni));
    bufp->chgBit(oldp+1581,(vlSelfRef.clk_d_i));
    bufp->chgBit(oldp+1582,(vlSelfRef.rst_d_ni));
    bufp->chgWData(oldp+1583,(vlSelfRef.tlul_fifo_async__02Etl_h_i),109);
    bufp->chgWData(oldp+1587,(vlSelfRef.tlul_fifo_async__02Etl_h_o),66);
    bufp->chgWData(oldp+1590,(vlSelfRef.tlul_fifo_async__02Etl_d_o),109);
    bufp->chgWData(oldp+1594,(vlSelfRef.tlul_fifo_async__02Etl_d_i),66);
    bufp->chgBit(oldp+1597,(vlSelfRef.tlul_socket_1n__02Eclk_i));
    bufp->chgBit(oldp+1598,(vlSelfRef.tlul_socket_1n__02Erst_ni));
    bufp->chgWData(oldp+1599,(vlSelfRef.tlul_socket_1n__02Etl_h_i),109);
    bufp->chgWData(oldp+1603,(vlSelfRef.tlul_socket_1n__02Etl_h_o),66);
    bufp->chgWData(oldp+1606,(vlSelfRef.tlul_socket_1n__02Etl_d_o),436);
    bufp->chgWData(oldp+1620,(vlSelfRef.tlul_socket_1n__02Etl_d_i),264);
    bufp->chgCData(oldp+1629,(vlSelfRef.dev_select_i),3);
    bufp->chgBit(oldp+1630,(vlSelfRef.tlul_socket_m1__02Eclk_i));
    bufp->chgBit(oldp+1631,(vlSelfRef.tlul_socket_m1__02Erst_ni));
    bufp->chgWData(oldp+1632,(vlSelfRef.tlul_socket_m1__02Etl_h_i),436);
    bufp->chgWData(oldp+1646,(vlSelfRef.tlul_socket_m1__02Etl_h_o),264);
    bufp->chgWData(oldp+1655,(vlSelfRef.tlul_socket_m1__02Etl_d_o),109);
    bufp->chgWData(oldp+1659,(vlSelfRef.tlul_socket_m1__02Etl_d_i),66);
    bufp->chgBit(oldp+1662,(vlSelfRef.multiple_pwm_ramp__02Eclk_i));
    bufp->chgBit(oldp+1663,(vlSelfRef.multiple_pwm_ramp__02Erst_ni));
    bufp->chgBit(oldp+1664,(vlSelfRef.multiple_pwm_ramp__02Eenable_i));
    bufp->chgCData(oldp+1665,(vlSelfRef.step_i),8);
    bufp->chgBit(oldp+1666,(vlSelfRef.lvds_0_i));
    bufp->chgBit(oldp+1667,(vlSelfRef.lvds_1_i));
    bufp->chgBit(oldp+1668,(vlSelfRef.pwm_0_o));
    bufp->chgBit(oldp+1669,(vlSelfRef.pwm_1_o));
    bufp->chgCData(oldp+1670,(vlSelfRef.adc_value_o),8);
    bufp->chgBit(oldp+1671,(vlSelfRef.adc_valid_o));
    bufp->chgBit(oldp+1672,(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack));
    bufp->chgSData(oldp+1673,(vlSelfRef.prim_fifo_async_simple__DOT__data_q),16);
    bufp->chgBit(oldp+1674,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag));
    bufp->chgBit(oldp+1675,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns));
    bufp->chgBit(oldp+1676,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d));
    bufp->chgBit(oldp+1677,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q));
    bufp->chgBit(oldp+1678,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d));
    bufp->chgBit(oldp+1679,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake));
    bufp->chgCData(oldp+1680,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d),5);
    bufp->chgCData(oldp+1681,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q),5);
    bufp->chgBit(oldp+1682,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc));
    bufp->chgBit(oldp+1683,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc));
    bufp->chgBit(oldp+1684,(((IData)(vlSelfRef.r_sram_gnt_i) 
                             & (IData)(vlSelfRef.r_sram_req_o))));
    bufp->chgBit(oldp+1685,((1U & ((IData)(vlSelfRef.w_sram_rvalid_i) 
                                   ^ (VL_REDXOR_32(vlSelfRef.w_sram_rdata_i) 
                                      ^ VL_REDXOR_2(vlSelfRef.w_sram_rerror_i))))));
    bufp->chgBit(oldp+1686,((1U & VL_REDXOR_2(vlSelfRef.r_sram_rerror_i))));
    bufp->chgBit(oldp+1687,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en));
    bufp->chgCData(oldp+1688,(vlSelfRef.prim_filter__DOT__stored_vector_d),4);
    bufp->chgBit(oldp+1689,(((0U == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)) 
                             | (0xfU == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)))));
    bufp->chgCData(oldp+1690,(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d),2);
    bufp->chgBit(oldp+1691,(((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d) 
                             == (IData)(vlSelfRef.thresh_i))));
    bufp->chgBit(oldp+1692,(vlSelfRef.pwm_ramp_tb__DOT__clk_i));
    bufp->chgBit(oldp+1693,(((IData)(vlSelfRef.pwm_ramp_tb__DOT__reverse_i)
                              ? ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter) 
                                 > (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle))
                              : ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter) 
                                 < (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle)))));
    bufp->chgBit(oldp+1694,(((1.0 * vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev) 
                             > vlSelfRef.pwm_ramp_tb__DOT__analog_input)));
    bufp->chgCData(oldp+1695,(((IData)(vlSelfRef.we_i)
                                ? (IData)(vlSelfRef.be_i)
                                : 0xfU)),4);
    bufp->chgBit(oldp+1696,((1U & VL_REDXOR_32((3U 
                                                & vlSelfRef.addr_i)))));
    bufp->chgBit(oldp+1697,((1U & (VL_REDXOR_16((0xfffcU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_i[0U])) 
                                   ^ VL_REDXOR_32((0x1ffffU 
                                                   & ((vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                                                       << 0x10U) 
                                                      | (vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                         >> 0x10U))))))));
    bufp->chgBit(oldp+1698,((IData)(((vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U] 
                                      >> 1U) & vlSelfRef.tlul_adapter_reg__02Etl_i[0U]))));
    bufp->chgBit(oldp+1699,((1U & ((~ (((0U == (7U 
                                                & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                   >> 9U))) 
                                        | ((1U == (7U 
                                                   & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                      >> 9U))) 
                                           | (4U == 
                                              (7U & 
                                               (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                >> 9U))))) 
                                       & ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk) 
                                          & ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk) 
                                             & ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                     >> 9U))) 
                                                | ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                        >> 9U))) 
                                                   | (IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk))))))) 
                                   | ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_type_err) 
                                      | (IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_wr_err))))));
    bufp->chgBit(oldp+1700,(((0U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                           >> 9U))) 
                             | ((1U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                              >> 9U))) 
                                | (4U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                >> 9U)))))));
    bufp->chgBit(oldp+1701,(((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk) 
                             & ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk) 
                                & ((4U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                 >> 9U))) 
                                   | ((1U == (7U & 
                                              (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                               >> 9U))) 
                                      | (IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->chgBit(oldp+1702,((0U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1703,((1U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1704,((4U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgCData(oldp+1705,((0xfU & ((IData)(1U) 
                                       << (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                 >> 0x1cU))))),4);
    bufp->chgBit(oldp+1706,((1U & ((~ (((0U == (7U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 9U))) 
                                        | ((1U == (7U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                      >> 9U))) 
                                           | (4U == 
                                              (7U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U))))) 
                                       & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                                          & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
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
                                                   | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk))))))) 
                                   | ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err) 
                                      | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err))))));
    bufp->chgBit(oldp+1707,((1U & VL_REDXOR_32((((vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                                  ^ 
                                                  vlSelfRef.tlul_adapter_sram__02Etl_i[1U]) 
                                                 ^ 
                                                 vlSelfRef.tlul_adapter_sram__02Etl_i[2U]) 
                                                ^ vlSelfRef.tlul_adapter_sram__02Etl_i[3U])))));
    bufp->chgBit(oldp+1708,((IData)(((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                      >> 0xcU) & vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]))));
    bufp->chgBit(oldp+1709,(((~ (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o)) 
                             & ((IData)(vlSelfRef.req_o) 
                                & (IData)(vlSelfRef.gnt_i)))));
    bufp->chgSData(oldp+1710,((0xfffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                          << 2U) | 
                                         (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                          >> 0x1eU)))),12);
    bufp->chgBit(oldp+1711,(((IData)(vlSelfRef.req_o) 
                             & (IData)(vlSelfRef.gnt_i))));
    bufp->chgBit(oldp+1712,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
                             & ((~ vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                   >> 0xcU)))));
    bufp->chgIData(oldp+1713,((vlSelfRef.tlul_adapter_sram__02Erdata_i 
                               & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask)),32);
    bufp->chgBit(oldp+1714,((1U & (IData)(vlSelfRef.rerror_i))));
    bufp->chgBit(oldp+1715,((1U & VL_REDXOR_32((0xfffU 
                                                & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x1eU)))))));
    bufp->chgBit(oldp+1716,(((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                           >> 9U))) 
                             | ((1U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                              >> 9U))) 
                                | (4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U)))))));
    bufp->chgBit(oldp+1717,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                             & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
                                & ((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                 >> 9U))) 
                                   | ((1U == (7U & 
                                              (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                               >> 9U))) 
                                      | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->chgBit(oldp+1718,((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1719,((1U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1720,((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgCData(oldp+1721,((0xfU & ((IData)(1U) 
                                       << (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                 >> 0x1cU))))),4);
    bufp->chgBit(oldp+1722,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->chgBit(oldp+1723,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->chgQData(oldp+1724,((((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                                ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                                : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage)),40);
    bufp->chgBit(oldp+1726,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->chgBit(oldp+1727,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->chgBit(oldp+1728,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    __Vtemp_369[0U] = ((vlSelfRef.h2d[4U] << 0x13U) 
                       | (vlSelfRef.h2d[3U] >> 0xdU));
    __Vtemp_369[1U] = ((vlSelfRef.h2d[5U] << 0x13U) 
                       | (vlSelfRef.h2d[4U] >> 0xdU));
    __Vtemp_369[2U] = ((vlSelfRef.h2d[6U] << 0x13U) 
                       | (vlSelfRef.h2d[5U] >> 0xdU));
    __Vtemp_369[3U] = (0x1fffU & (vlSelfRef.h2d[6U] 
                                  >> 0xdU));
    bufp->chgWData(oldp+1729,(__Vtemp_369),109);
    __Vtemp_372[0U] = ((vlSelfRef.d2h[3U] << 0x1eU) 
                       | (vlSelfRef.d2h[2U] >> 2U));
    __Vtemp_372[1U] = ((vlSelfRef.d2h[4U] << 0x1eU) 
                       | (vlSelfRef.d2h[3U] >> 2U));
    __Vtemp_372[2U] = (3U & (vlSelfRef.d2h[4U] >> 2U));
    bufp->chgWData(oldp+1733,(__Vtemp_372),66);
    bufp->chgCData(oldp+1736,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask),8);
    __Vtemp_375[0U] = vlSelfRef.h2d[0U];
    __Vtemp_375[1U] = vlSelfRef.h2d[1U];
    __Vtemp_375[2U] = vlSelfRef.h2d[2U];
    __Vtemp_375[3U] = (0x1fffU & vlSelfRef.h2d[3U]);
    bufp->chgWData(oldp+1737,(__Vtemp_375),109);
    __Vtemp_378[0U] = vlSelfRef.d2h[0U];
    __Vtemp_378[1U] = vlSelfRef.d2h[1U];
    __Vtemp_378[2U] = (3U & vlSelfRef.d2h[2U]);
    bufp->chgWData(oldp+1741,(__Vtemp_378),66);
    bufp->chgCData(oldp+1744,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask),8);
    bufp->chgBit(oldp+1745,((1U & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                                   >> 0xcU))));
    __Vtemp_381[0U] = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                        << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[0U] 
                                     >> 1U));
    __Vtemp_381[1U] = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                        << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                                     >> 1U));
    __Vtemp_381[2U] = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                        << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                                     >> 1U));
    __Vtemp_381[3U] = (0x7ffU & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                                 >> 1U));
    bufp->chgWData(oldp+1746,(__Vtemp_381),107);
    bufp->chgBit(oldp+1750,((1U & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])));
    bufp->chgBit(oldp+1751,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+1752,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+1753,((1U & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
                                   >> 1U))));
    bufp->chgQData(oldp+1754,((((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[2U])) 
                                << 0x3fU) | (((QData)((IData)(
                                                              vlSelfRef.tlul_fifo_async__02Etl_d_i[1U])) 
                                              << 0x1fU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])) 
                                                >> 1U)))),64);
    bufp->chgBit(oldp+1756,((1U & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U])));
    bufp->chgQData(oldp+1757,(((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                ? 0ULL : vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                               [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])),64);
    bufp->chgBit(oldp+1759,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+1760,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr));
    bufp->chgQData(oldp+1761,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                              [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]),64);
    bufp->chgBit(oldp+1763,((1U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                                   >> 0xcU))));
    if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU))) {
        __Vtemp_383[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        __Vtemp_383[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        __Vtemp_383[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        __Vtemp_383[3U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    } else {
        __Vtemp_383[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_383[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_383[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_383[3U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->chgWData(oldp+1764,(__Vtemp_383),110);
    bufp->chgBit(oldp+1768,((1U & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U])));
    bufp->chgCData(oldp+1769,((0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                        >> 1U))),8);
    bufp->chgCData(oldp+1770,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                     >> 9U))),2);
    bufp->chgCData(oldp+1771,((1U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                              >> 0x14U)))),8);
    bufp->chgCData(oldp+1772,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                     >> 0x1cU))),2);
    bufp->chgCData(oldp+1773,((2U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                              >> 7U)))),8);
    bufp->chgCData(oldp+1774,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                     >> 0xfU))),2);
    bufp->chgCData(oldp+1775,((3U | (0xfcU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                               << 6U) 
                                              | (0x3cU 
                                                 & (vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                                                    >> 0x1aU)))))),8);
    bufp->chgCData(oldp+1776,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                     >> 2U))),2);
    bufp->chgBit(oldp+1777,((1U & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U])));
    bufp->chgBit(oldp+1778,((1U & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                                   >> 1U))));
    if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U))) {
        __Vtemp_385[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_385[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_385[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_385[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_385[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_385[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1779,(__Vtemp_385),65);
    __Vtemp_390[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                        >> 7U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                        >> 7U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                         >> 7U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                           >> 7U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_391[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                        >> 7U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                        >> 7U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_391[1U] = __Vtemp_390[1U];
    __Vtemp_391[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                   >> 7U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                        >> 7U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->chgWData(oldp+1782,(__Vtemp_391),66);
    __Vtemp_394[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[7U] 
                        << 0x1aU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                     >> 6U));
    __Vtemp_394[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                        << 0x1aU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[7U] 
                                     >> 6U));
    __Vtemp_394[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                             >> 6U));
    bufp->chgWData(oldp+1785,(__Vtemp_394),66);
    bufp->chgBit(oldp+1788,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                >> 7U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1789,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                   >> 6U))));
    bufp->chgBit(oldp+1790,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                   >> 7U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_402[0U] = 0U;
        __Vtemp_402[1U] = 0U;
        __Vtemp_402[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                   >> 7U))) {
        __Vtemp_402[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_402[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_402[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_402[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_402[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_402[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1791,(__Vtemp_402),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
            >> 7U))) {
        __Vtemp_404[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_404[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_404[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_404[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_404[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_404[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1794,(__Vtemp_404),65);
    __Vtemp_409[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                        >> 5U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                        >> 5U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                         >> 5U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                           >> 5U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_410[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                        >> 5U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                        >> 5U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_410[1U] = __Vtemp_409[1U];
    __Vtemp_410[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                   >> 5U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                        >> 5U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->chgWData(oldp+1797,(__Vtemp_410),66);
    __Vtemp_413[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[5U] 
                        << 0x1cU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                     >> 4U));
    __Vtemp_413[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                        << 0x1cU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[5U] 
                                     >> 4U));
    __Vtemp_413[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                             >> 4U));
    bufp->chgWData(oldp+1800,(__Vtemp_413),66);
    bufp->chgBit(oldp+1803,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                >> 5U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1804,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                   >> 4U))));
    bufp->chgBit(oldp+1805,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                   >> 5U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_421[0U] = 0U;
        __Vtemp_421[1U] = 0U;
        __Vtemp_421[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                   >> 5U))) {
        __Vtemp_421[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_421[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_421[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_421[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_421[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_421[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1806,(__Vtemp_421),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
            >> 5U))) {
        __Vtemp_423[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_423[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_423[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_423[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_423[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_423[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1809,(__Vtemp_423),65);
    __Vtemp_428[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                        >> 3U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                        >> 3U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                         >> 3U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                           >> 3U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_429[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                        >> 3U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                        >> 3U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_429[1U] = __Vtemp_428[1U];
    __Vtemp_429[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                   >> 3U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                        >> 3U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->chgWData(oldp+1812,(__Vtemp_429),66);
    __Vtemp_432[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[3U] 
                        << 0x1eU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                     >> 2U));
    __Vtemp_432[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                        << 0x1eU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[3U] 
                                     >> 2U));
    __Vtemp_432[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                             >> 2U));
    bufp->chgWData(oldp+1815,(__Vtemp_432),66);
    bufp->chgBit(oldp+1818,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                >> 3U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1819,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                   >> 2U))));
    bufp->chgBit(oldp+1820,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                   >> 3U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_440[0U] = 0U;
        __Vtemp_440[1U] = 0U;
        __Vtemp_440[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                   >> 3U))) {
        __Vtemp_440[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_440[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_440[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_440[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_440[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_440[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1821,(__Vtemp_440),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
            >> 3U))) {
        __Vtemp_442[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_442[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_442[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_442[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_442[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_442[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1824,(__Vtemp_442),65);
    __Vtemp_447[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                         >> 1U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                           >> 1U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_448[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_448[1U] = __Vtemp_447[1U];
    __Vtemp_448[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->chgWData(oldp+1827,(__Vtemp_448),66);
    __Vtemp_451[0U] = vlSelfRef.tlul_socket_1n__02Etl_d_i[0U];
    __Vtemp_451[1U] = vlSelfRef.tlul_socket_1n__02Etl_d_i[1U];
    __Vtemp_451[2U] = (3U & vlSelfRef.tlul_socket_1n__02Etl_d_i[2U]);
    bufp->chgWData(oldp+1830,(__Vtemp_451),66);
    bufp->chgBit(oldp+1833,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                >> 1U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1834,((1U & vlSelfRef.tlul_socket_1n__02Etl_d_i[0U])));
    bufp->chgBit(oldp+1835,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                   >> 1U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_459[0U] = 0U;
        __Vtemp_459[1U] = 0U;
        __Vtemp_459[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                   >> 1U))) {
        __Vtemp_459[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_459[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_459[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_459[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_459[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_459[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1836,(__Vtemp_459),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
            >> 1U))) {
        __Vtemp_461[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_461[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_461[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_461[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_461[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_461[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->chgWData(oldp+1839,(__Vtemp_461),65);
}

void Vpwm_ramp_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_cleanup\n"); );
    // Init
    Vpwm_ramp_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_ramp_tb___024root*>(voidSelf);
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xaU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xbU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xcU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xdU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xeU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xfU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x10U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x11U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x12U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x13U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x14U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x15U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x16U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x17U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x18U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x19U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1aU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1bU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1cU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1dU] = 0U;
}
