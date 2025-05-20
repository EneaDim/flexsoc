// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vspi_host_tb__Syms.h"


void Vspi_host_tb___024root__trace_chg_0_sub_0(Vspi_host_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vspi_host_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root__trace_chg_0\n"); );
    // Init
    Vspi_host_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vspi_host_tb___024root*>(voidSelf);
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vspi_host_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vspi_host_tb___024root__trace_chg_0_sub_0(Vspi_host_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root__trace_chg_0_sub_0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
                      [0x1fU])))) {
        bufp->chgBit(oldp+8,(vlSymsp->TOP__spi_host_tb.__PVT__rst_ni));
        bufp->chgWData(oldp+9,(vlSymsp->TOP__spi_host_tb.__PVT__tl_i),109);
        bufp->chgBit(oldp+13,(vlSymsp->TOP__spi_host_tb.__PVT__spi_sdio_i));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+14,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n));
        bufp->chgIData(oldp+15,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d),32);
        bufp->chgBit(oldp+16,(vlSelfRef.tlul_adapter_sram__DOT__error_det));
        bufp->chgBit(oldp+17,(vlSelfRef.tlul_adapter_sram__DOT__instr_error));
        bufp->chgIData(oldp+18,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata),17);
        bufp->chgCData(oldp+19,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata),5);
        bufp->chgIData(oldp+20,(vlSelfRef.tlul_adapter_sram__DOT__wmask_int),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tlul_adapter_sram__DOT__wdata_int),32);
        bufp->chgCData(oldp+22,(vlSelfRef.tlul_adapter_sram__DOT__wmask_intg),7);
        bufp->chgCData(oldp+23,(vlSelfRef.tlul_adapter_sram__DOT__wdata_intg),7);
        bufp->chgBit(oldp+24,(((0U != (IData)(vlSelfRef.tlul_adapter_sram__DOT__wmask_intg)) 
                               & (0U != (IData)(vlSelfRef.tlul_adapter_sram__DOT__wdata_intg)))));
        bufp->chgIData(oldp+25,(vlSelfRef.tlul_adapter_sram__DOT__sv2v_autoblock_1__DOT__i),32);
        bufp->chgBit(oldp+26,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err));
        bufp->chgBit(oldp+27,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err));
        bufp->chgBit(oldp+28,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk));
        bufp->chgBit(oldp+29,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk));
        bufp->chgBit(oldp+30,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk));
        bufp->chgCData(oldp+31,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_mask),8);
        bufp->chgQData(oldp+32,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_data),64);
        bufp->chgQData(oldp+34,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_data),64);
        bufp->chgCData(oldp+36,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_mask),8);
        bufp->chgQData(oldp+37,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_data),64);
        bufp->chgQData(oldp+39,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_data),64);
        bufp->chgWData(oldp+41,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i),110);
        bufp->chgWData(oldp+45,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+49,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+53,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+57,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i),109);
        bufp->chgWData(oldp+61,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+64,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+67,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+70,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgWData(oldp+73,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+76,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_4[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_4[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_4[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_4[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                         | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+77,(__Vtemp_4),108);
        bufp->chgBit(oldp+81,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U])));
        bufp->chgBit(oldp+82,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_8[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_8[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_8[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                         | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_8[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                         | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+83,(__Vtemp_8),108);
        bufp->chgBit(oldp+87,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U])));
        bufp->chgBit(oldp+88,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_12[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_12[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_12[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_12[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                          | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+89,(__Vtemp_12),108);
        bufp->chgBit(oldp+93,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U])));
        bufp->chgBit(oldp+94,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                     >> 0xcU))));
        __Vtemp_16[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_16[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_16[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                          | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_16[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                          | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
        bufp->chgWData(oldp+95,(__Vtemp_16),108);
        bufp->chgBit(oldp+99,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U])));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [8U])))) {
        bufp->chgBit(oldp+100,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
        bufp->chgBit(oldp+101,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid));
        bufp->chgBit(oldp+102,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+103,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+104,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [9U])))) {
        bufp->chgBit(oldp+105,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+106,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+107,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+108,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+109,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+110,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+111,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+112,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+113,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+114,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [2U] | vlSelfRef.__Vm_traceActivity
                        [9U]) | vlSelfRef.__Vm_traceActivity
                       [0x11U]) | vlSelfRef.__Vm_traceActivity
                      [0x1aU])))) {
        bufp->chgBit(oldp+115,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+116,(__Vtemp_24),65);
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
        bufp->chgWData(oldp+119,(__Vtemp_26),65);
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
        bufp->chgWData(oldp+122,(__Vtemp_39),109);
        bufp->chgBit(oldp+126,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+127,(__Vtemp_55),108);
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
        bufp->chgWData(oldp+131,(__Vtemp_61),108);
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
        bufp->chgWData(oldp+135,(__Vtemp_74),109);
        bufp->chgBit(oldp+139,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+140,(__Vtemp_90),108);
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
        bufp->chgWData(oldp+144,(__Vtemp_96),108);
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
        bufp->chgWData(oldp+148,(__Vtemp_109),109);
        bufp->chgBit(oldp+152,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+153,(__Vtemp_125),108);
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
        bufp->chgWData(oldp+157,(__Vtemp_131),108);
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
        bufp->chgWData(oldp+161,(__Vtemp_144),109);
        bufp->chgBit(oldp+165,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+166,(__Vtemp_160),108);
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
        bufp->chgWData(oldp+170,(__Vtemp_166),108);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [2U] | vlSelfRef.__Vm_traceActivity
                       [9U]) | vlSelfRef.__Vm_traceActivity
                      [0x1aU])))) {
        bufp->chgWData(oldp+174,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0]),66);
        bufp->chgWData(oldp+177,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1]),66);
        bufp->chgWData(oldp+180,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2]),66);
        bufp->chgWData(oldp+183,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3]),66);
        bufp->chgWData(oldp+186,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4]),66);
        bufp->chgBit(oldp+189,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+190,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+191,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+192,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+193,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+194,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+195,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+196,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+197,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+198,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+199,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+200,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+201,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+202,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+203,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+204,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+205,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+206,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+207,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+208,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xaU])))) {
        bufp->chgBit(oldp+209,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+210,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+211,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+212,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+213,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+214,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+215,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+216,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+217,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+218,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [2U] | vlSelfRef.__Vm_traceActivity
                       [0xaU]) | vlSelfRef.__Vm_traceActivity
                      [0x14U])))) {
        bufp->chgBit(oldp+219,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+220,(__Vtemp_182),108);
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
        bufp->chgWData(oldp+224,(__Vtemp_188),108);
        bufp->chgBit(oldp+228,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+229,(__Vtemp_204),108);
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
        bufp->chgWData(oldp+233,(__Vtemp_210),108);
        bufp->chgBit(oldp+237,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+238,(__Vtemp_226),108);
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
        bufp->chgWData(oldp+242,(__Vtemp_232),108);
        bufp->chgBit(oldp+246,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+247,(__Vtemp_248),108);
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
        bufp->chgWData(oldp+251,(__Vtemp_254),108);
    }
    if (VL_UNLIKELY(((((vlSelfRef.__Vm_traceActivity
                        [2U] | vlSelfRef.__Vm_traceActivity
                        [0xaU]) | vlSelfRef.__Vm_traceActivity
                       [0x14U]) | vlSelfRef.__Vm_traceActivity
                      [0x1bU])))) {
        bufp->chgBit(oldp+255,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+256,(__Vtemp_270),108);
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
        bufp->chgWData(oldp+260,(__Vtemp_276),108);
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
        bufp->chgWData(oldp+264,(__Vtemp_282),66);
        bufp->chgBit(oldp+267,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+268,(__Vtemp_290),65);
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
        bufp->chgWData(oldp+271,(__Vtemp_292),65);
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
        bufp->chgWData(oldp+274,(__Vtemp_298),66);
        bufp->chgBit(oldp+277,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+278,(__Vtemp_306),65);
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
        bufp->chgWData(oldp+281,(__Vtemp_308),65);
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
        bufp->chgWData(oldp+284,(__Vtemp_314),66);
        bufp->chgBit(oldp+287,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+288,(__Vtemp_322),65);
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
        bufp->chgWData(oldp+291,(__Vtemp_324),65);
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
        bufp->chgWData(oldp+294,(__Vtemp_330),66);
        bufp->chgBit(oldp+297,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
        bufp->chgWData(oldp+298,(__Vtemp_338),65);
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
        bufp->chgWData(oldp+301,(__Vtemp_340),65);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity
                       [2U] | vlSelfRef.__Vm_traceActivity
                       [0xaU]) | vlSelfRef.__Vm_traceActivity
                      [0x1bU])))) {
        bufp->chgCData(oldp+304,(((((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
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
        bufp->chgBit(oldp+305,(((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
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
        bufp->chgBit(oldp+306,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+307,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+308,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+309,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+310,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+311,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+312,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+313,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+314,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+315,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+316,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+317,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+318,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+319,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+320,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+321,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+322,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+323,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+324,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgBit(oldp+325,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                                & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xfU])))) {
        bufp->chgWData(oldp+326,(vlSelfRef.tlul_adapter_host__DOT__tl_out),109);
        bufp->chgCData(oldp+330,(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d),2);
        bufp->chgBit(oldp+331,(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d));
        bufp->chgCData(oldp+332,((0x7fU & (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                           >> 8U))),7);
        bufp->chgIData(oldp+333,(((vlSelfRef.tlul_adapter_host__DOT__tl_out[1U] 
                                   << 8U) | (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                             >> 0x18U))),32);
        bufp->chgCData(oldp+334,((0x7fU & (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                           >> 1U))),7);
        bufp->chgBit(oldp+335,((1U & VL_REDXOR_32((
                                                   ((vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                                     ^ 
                                                     vlSelfRef.tlul_adapter_host__DOT__tl_out[1U]) 
                                                    ^ 
                                                    vlSelfRef.tlul_adapter_host__DOT__tl_out[2U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_adapter_host__DOT__tl_out[3U])))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x10U])))) {
        bufp->chgBit(oldp+336,(vlSelfRef.prim_fifo_async_simple__DOT__wr_en));
        bufp->chgBit(oldp+337,(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
        bufp->chgBit(oldp+338,(((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
                                & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
                                   | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)))));
        bufp->chgBit(oldp+339,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns));
        bufp->chgBit(oldp+340,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x1aU])))) {
        bufp->chgCData(oldp+341,((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])),3);
        bufp->chgWData(oldp+342,(vlSelfRef.tlul_socket_1n__DOT__tl_t_o),109);
        __Vtemp_344[0U] = ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U]) 
                           | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
        __Vtemp_344[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]));
        __Vtemp_344[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]) 
                           | (2U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]));
        bufp->chgWData(oldp+346,(__Vtemp_344),66);
        bufp->chgBit(oldp+349,(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests));
        bufp->chgBit(oldp+350,(vlSelfRef.tlul_socket_1n__DOT__accept_t_req));
        bufp->chgBit(oldp+351,(vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp));
        bufp->chgWData(oldp+352,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0]),109);
        bufp->chgWData(oldp+356,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1]),109);
        bufp->chgWData(oldp+360,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2]),109);
        bufp->chgWData(oldp+364,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3]),109);
        bufp->chgWData(oldp+368,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4]),109);
        bufp->chgIData(oldp+372,(vlSelfRef.tlul_socket_1n__DOT__blanked_auser),23);
        bufp->chgWData(oldp+373,(vlSelfRef.tlul_socket_1n__DOT__tl_t_p),66);
        bufp->chgBit(oldp+376,(vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready));
        bufp->chgBit(oldp+377,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
        bufp->chgWData(oldp+378,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o),110);
        bufp->chgBit(oldp+382,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+383,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+384,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                      >> 1U))));
        bufp->chgWData(oldp+385,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+388,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+389,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+390,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+391,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+392,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [4U]),109);
        bufp->chgBit(oldp+396,((1U & VL_REDXOR_32((
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
        bufp->chgBit(oldp+397,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select));
        bufp->chgBit(oldp+398,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select));
        bufp->chgBit(oldp+399,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select));
        bufp->chgBit(oldp+400,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select));
        bufp->chgWData(oldp+401,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [0U]),109);
        bufp->chgBit(oldp+405,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
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
        bufp->chgWData(oldp+406,(__Vtemp_348),108);
        bufp->chgBit(oldp+410,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+411,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+412,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+413,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+414,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [0U][0U])));
        bufp->chgBit(oldp+415,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+416,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+417,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [1U]),109);
        bufp->chgBit(oldp+421,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
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
        bufp->chgWData(oldp+422,(__Vtemp_352),108);
        bufp->chgBit(oldp+426,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+427,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+428,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+429,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+430,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [1U][0U])));
        bufp->chgBit(oldp+431,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+432,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+433,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [2U]),109);
        bufp->chgBit(oldp+437,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
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
        bufp->chgWData(oldp+438,(__Vtemp_356),108);
        bufp->chgBit(oldp+442,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+443,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+444,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+445,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+446,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [2U][0U])));
        bufp->chgBit(oldp+447,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+448,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+449,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                 [3U]),109);
        bufp->chgBit(oldp+453,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
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
        bufp->chgWData(oldp+454,(__Vtemp_360),108);
        bufp->chgBit(oldp+458,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+459,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+460,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+461,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+462,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                [3U][0U])));
        bufp->chgBit(oldp+463,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+464,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x1bU])))) {
        bufp->chgWData(oldp+465,(vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o),436);
        bufp->chgWData(oldp+479,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0]),66);
        bufp->chgWData(oldp+482,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1]),66);
        bufp->chgWData(oldp+485,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2]),66);
        bufp->chgWData(oldp+488,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3]),66);
        bufp->chgCData(oldp+491,(vlSelfRef.tlul_socket_m1__DOT__hrequest),4);
        bufp->chgCData(oldp+492,(vlSelfRef.tlul_socket_m1__DOT__hgrant),4);
        bufp->chgWData(oldp+493,(vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i),109);
        bufp->chgWData(oldp+497,(vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o),66);
        bufp->chgBit(oldp+500,((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest))));
        bufp->chgWData(oldp+501,(vlSelfRef.tlul_socket_m1__DOT__arb_data),109);
        bufp->chgCData(oldp+505,(((((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__3__KET__) 
                                    << 3U) | ((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__2__KET__) 
                                              << 2U)) 
                                  | (((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__1__KET__) 
                                      << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__0__KET__)))),4);
        bufp->chgCData(oldp+506,((0x3fU & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                           >> 0x13U))),8);
        bufp->chgCData(oldp+507,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__idx_o),2);
        bufp->chgCData(oldp+508,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req),4);
        bufp->chgCData(oldp+509,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out),4);
        bufp->chgCData(oldp+510,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req),4);
        bufp->chgCData(oldp+511,((0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U))),4);
        bufp->chgCData(oldp+512,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner),4);
        bufp->chgIData(oldp+513,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__sv2v_autoblock_3__DOT__i),32);
        bufp->chgBit(oldp+514,((1U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
        bufp->chgBit(oldp+515,((1U & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                      >> 0xcU))));
        __Vtemp_364[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
        __Vtemp_364[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
        __Vtemp_364[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
        __Vtemp_364[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
        bufp->chgWData(oldp+516,(__Vtemp_364),108);
        bufp->chgBit(oldp+520,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o));
        bufp->chgBit(oldp+521,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+522,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+523,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgBit(oldp+524,((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U])));
        bufp->chgWData(oldp+525,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o),65);
        bufp->chgBit(oldp+528,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+529,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgWData(oldp+530,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+534,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [0U]),66);
        bufp->chgBit(oldp+537,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [0U][0U])));
        bufp->chgBit(oldp+538,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+539,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+540,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [0U][2U] >> 1U))));
        bufp->chgWData(oldp+541,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+544,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+545,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+546,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+547,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+548,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+552,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [1U]),66);
        bufp->chgBit(oldp+555,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [1U][0U])));
        bufp->chgBit(oldp+556,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+557,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+558,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [1U][2U] >> 1U))));
        bufp->chgWData(oldp+559,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+562,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+563,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+564,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+565,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+566,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+570,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [2U]),66);
        bufp->chgBit(oldp+573,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [2U][0U])));
        bufp->chgBit(oldp+574,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+575,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+576,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [2U][2U] >> 1U))));
        bufp->chgWData(oldp+577,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+580,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+581,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+582,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+583,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
        bufp->chgWData(oldp+584,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o),109);
        bufp->chgWData(oldp+588,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                 [3U]),66);
        bufp->chgBit(oldp+591,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                [3U][0U])));
        bufp->chgBit(oldp+592,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+593,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+594,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                      [3U][2U] >> 1U))));
        bufp->chgWData(oldp+595,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
        bufp->chgBit(oldp+598,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
        bufp->chgBit(oldp+599,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+600,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+601,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x1eU])))) {
        bufp->chgWData(oldp+602,(vlSelfRef.tlul_adapter_sram__DOT__tl_o_int),66);
        bufp->chgBit(oldp+605,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready));
        bufp->chgBit(oldp+606,((IData)(((0x8000U == 
                                         (0x1c000U 
                                          & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                        & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready)))));
        bufp->chgQData(oldp+607,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata),40);
        bufp->chgQData(oldp+609,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata),40);
        bufp->chgBit(oldp+611,(vlSelfRef.tlul_adapter_sram__DOT__d_valid));
        bufp->chgBit(oldp+612,(vlSelfRef.tlul_adapter_sram__DOT__d_error));
        bufp->chgBit(oldp+613,(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp));
        bufp->chgIData(oldp+614,((((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                                   & (IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp))
                                   ? (IData)((vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                              >> 8U))
                                   : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data)),32);
        bufp->chgCData(oldp+615,((0x7fU & (((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp) 
                                            & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                               >> 0xeU))
                                            ? (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ)
                                            : ((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp)
                                                ? (IData)(
                                                          (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                           >> 1U))
                                                : 0x2aU)))),7);
        bufp->chgBit(oldp+616,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+617,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+618,((1U & VL_REDXOR_32((
                                                   (vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U] 
                                                    ^ 
                                                    vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[1U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U])))));
        bufp->chgBit(oldp+619,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+620,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+621,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0xbU])))) {
        bufp->chgCData(oldp+622,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit),4);
        bufp->chgBit(oldp+623,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__instr_error));
        bufp->chgBit(oldp+624,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__malformed_meta_err));
        bufp->chgBit(oldp+625,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
        bufp->chgBit(oldp+626,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
        bufp->chgBit(oldp+627,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
        bufp->chgBit(oldp+628,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
        bufp->chgBit(oldp+629,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity
                      [0x19U])))) {
        bufp->chgBit(oldp+630,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we));
        bufp->chgBit(oldp+631,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re));
        bufp->chgBit(oldp+632,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error));
        bufp->chgBit(oldp+633,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en));
        bufp->chgBit(oldp+634,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack));
        bufp->chgBit(oldp+635,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal));
        bufp->chgBit(oldp+636,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req));
        bufp->chgBit(oldp+637,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgCData(oldp+638,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray),5);
        bufp->chgCData(oldp+639,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr),5);
        bufp->chgCData(oldp+640,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))),4);
        bufp->chgBit(oldp+641,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr) 
                                      >> 4U))));
        bufp->chgCData(oldp+642,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q),5);
        bufp->chgCData(oldp+643,((0x1fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)))),5);
        bufp->chgCData(oldp+644,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))),4);
        bufp->chgBit(oldp+645,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                      >> 4U))));
        bufp->chgBit(oldp+646,(((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                == (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))));
        bufp->chgBit(oldp+647,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored));
        bufp->chgIData(oldp+648,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q),32);
        bufp->chgCData(oldp+649,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr),5);
        bufp->chgBit(oldp+650,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty));
        bufp->chgCData(oldp+651,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+652,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_q));
        bufp->chgBit(oldp+653,(vlSymsp->TOP__spi_host_tb.__PVT__spi_sclk_o));
        bufp->chgBit(oldp+654,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_q));
        bufp->chgBit(oldp+655,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_q));
        bufp->chgWData(oldp+656,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre),66);
        bufp->chgCData(oldp+659,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state),2);
        bufp->chgBit(oldp+660,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d));
        bufp->chgBit(oldp+661,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_d));
        bufp->chgCData(oldp+662,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q),3);
        bufp->chgCData(oldp+663,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q),4);
        bufp->chgBit(oldp+664,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_q));
        bufp->chgBit(oldp+665,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_q));
        bufp->chgBit(oldp+666,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d));
        bufp->chgBit(oldp+667,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q));
        bufp->chgBit(oldp+668,(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q));
        bufp->chgBit(oldp+669,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk));
        bufp->chgBit(oldp+670,(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q));
        bufp->chgBit(oldp+671,(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q));
        bufp->chgBit(oldp+672,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe));
        bufp->chgBit(oldp+673,(((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_q)) 
                                & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk))));
        bufp->chgCData(oldp+674,((3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))),2);
        bufp->chgBit(oldp+675,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgCData(oldp+676,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),3);
        bufp->chgCData(oldp+677,((4U & ((~ ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 2U)) 
                                        << 2U))),3);
        bufp->chgBit(oldp+678,((1U & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 2U))));
        bufp->chgCData(oldp+679,((3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))),2);
        bufp->chgBit(oldp+680,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgCData(oldp+681,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),3);
        bufp->chgCData(oldp+682,((4U & ((~ ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 2U)) 
                                        << 2U))),3);
        bufp->chgBit(oldp+683,((1U & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 2U))));
        bufp->chgBit(oldp+684,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q));
        bufp->chgIData(oldp+685,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q),32);
        bufp->chgBit(oldp+686,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q));
        bufp->chgCData(oldp+687,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q),8);
        bufp->chgCData(oldp+688,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q),2);
        bufp->chgCData(oldp+689,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q),3);
        bufp->chgBit(oldp+690,((1U & VL_REDXOR_32((
                                                   (vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                                    ^ 
                                                    vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[1U]) 
                                                   ^ 
                                                   vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[2U])))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgWData(oldp+691,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[0]),107);
        bufp->chgWData(oldp+695,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[1]),107);
        bufp->chgWData(oldp+699,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[2]),107);
        bufp->chgWData(oldp+703,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[3]),107);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[6U] 
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
        bufp->chgWData(oldp+707,(__Vtemp_366),107);
        bufp->chgWData(oldp+711,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                 [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))]),107);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgQData(oldp+715,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[0]),64);
        bufp->chgQData(oldp+717,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[1]),64);
        bufp->chgQData(oldp+719,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[2]),64);
        bufp->chgQData(oldp+721,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[3]),64);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgBit(oldp+723,(vlSelfRef.tlul_adapter_sram__DOT__intg_error_q));
        bufp->chgBit(oldp+724,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready));
        bufp->chgBit(oldp+725,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid));
        bufp->chgBit(oldp+726,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
        bufp->chgBit(oldp+727,((1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)) 
                                      & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))))));
        bufp->chgBit(oldp+728,(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q));
        bufp->chgBit(oldp+729,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o));
        bufp->chgBit(oldp+730,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+731,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+732,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+733,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+734,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+735,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+736,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+737,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+738,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+739,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+740,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+741,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+742,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o));
        bufp->chgBit(oldp+743,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+744,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+745,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+746,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+747,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+748,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+749,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+750,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+751,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+752,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+753,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+754,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+755,((1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                                      & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))))));
        bufp->chgBit(oldp+756,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o));
        bufp->chgBit(oldp+757,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__depth_o));
        bufp->chgBit(oldp+758,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+759,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+760,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+761,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+762,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+763,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+764,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+765,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+766,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+767,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+768,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgSData(oldp+769,(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding),9);
        bufp->chgCData(oldp+770,(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding),3);
        bufp->chgBit(oldp+771,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+772,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+773,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+774,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+775,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+776,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+777,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+778,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+779,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+780,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+781,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+782,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+783,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+784,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+785,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+786,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+787,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+788,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+789,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+790,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+791,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+792,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+793,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+794,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+795,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+796,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+797,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+798,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgWData(oldp+799,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int),66);
        bufp->chgCData(oldp+802,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode),3);
        bufp->chgCData(oldp+803,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source),8);
        bufp->chgCData(oldp+804,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size),2);
        bufp->chgBit(oldp+805,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending));
        bufp->chgCData(oldp+806,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type),4);
        bufp->chgBit(oldp+807,((1U & VL_REDXOR_32((
                                                   (vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
                                                    ^ 
                                                    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
                                                   ^ 
                                                   vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U])))));
        bufp->chgBit(oldp+808,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+809,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+810,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+811,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+812,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+813,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+814,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+815,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+816,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+817,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+818,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+819,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+820,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+821,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+822,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+823,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+824,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+825,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+826,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+827,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+828,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+829,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+830,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+831,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+832,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+833,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+834,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+835,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+836,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+837,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+838,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+839,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+840,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+841,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+842,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+843,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+844,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+845,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+846,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+847,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+848,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+849,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+850,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+851,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+852,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+853,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+854,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+855,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+856,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+857,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+858,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+859,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+860,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+861,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+862,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+863,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+864,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+865,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+866,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+867,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+868,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+869,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+870,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+871,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+872,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+873,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+874,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+875,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+876,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+877,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+878,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+879,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+880,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+881,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+882,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+883,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+884,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+885,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+886,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+887,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+888,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+889,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+890,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+891,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+892,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+893,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+894,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+895,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+896,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+897,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+898,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+899,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+900,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+901,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+902,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+903,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+904,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+905,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+906,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+907,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+908,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+909,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+910,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+911,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+912,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+913,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+914,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+915,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+916,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+917,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+918,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+919,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xaU]))) {
        bufp->chgBit(oldp+920,(vlSelfRef.tlul_socket_m1__DOT__arb_ready));
        bufp->chgCData(oldp+921,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask),4);
        bufp->chgBit(oldp+922,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+923,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+924,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+925,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+926,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+927,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+928,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+929,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+930,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+931,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+932,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+933,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+934,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+935,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+936,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+937,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+938,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+939,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+940,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+941,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+942,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+943,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+944,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+945,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+946,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+947,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+948,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+949,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+950,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+951,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+952,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+953,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+954,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+955,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+956,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+957,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+958,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+959,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+960,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+961,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+962,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+963,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+964,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+965,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+966,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+967,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+968,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+969,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+970,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+971,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+972,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+973,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+974,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+975,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+976,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+977,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+978,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+979,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+980,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+981,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+982,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+983,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+984,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+985,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+986,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgCData(oldp+987,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+988,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                            >> 1U)) 
                                        << 1U))),2);
        bufp->chgBit(oldp+989,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+990,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      >> 1U))));
        bufp->chgBit(oldp+991,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+992,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+993,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+994,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+995,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+996,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+997,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+998,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                      ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+999,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1000,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1001,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1002,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1003,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1004,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1005,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+1006,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+1007,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+1008,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1009,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1010,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1011,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1012,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1013,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1014,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1015,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1016,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1017,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1018,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1019,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+1020,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+1021,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+1022,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1023,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1024,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1025,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1026,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1027,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1028,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1029,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1030,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1031,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1032,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1033,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
        bufp->chgBit(oldp+1034,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
        bufp->chgBit(oldp+1035,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
        bufp->chgBit(oldp+1036,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1037,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1038,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1039,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1040,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1041,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1042,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1043,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1044,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1045,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1046,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1047,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
        bufp->chgBit(oldp+1048,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
        bufp->chgBit(oldp+1049,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
        bufp->chgBit(oldp+1050,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1051,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
        bufp->chgBit(oldp+1052,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgBit(oldp+1053,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
        bufp->chgBit(oldp+1054,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
        bufp->chgCData(oldp+1055,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1056,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgCData(oldp+1057,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
        bufp->chgCData(oldp+1058,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                             >> 1U)) 
                                         << 1U))),2);
        bufp->chgBit(oldp+1059,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 1U))));
        bufp->chgBit(oldp+1060,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                       >> 1U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xcU]))) {
        bufp->chgBit(oldp+1061,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_sva));
        bufp->chgBit(oldp+1062,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_d_error_sva));
        bufp->chgBit(oldp+1063,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_sva));
        bufp->chgBit(oldp+1064,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_d_error_sva));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xdU]))) {
        bufp->chgCData(oldp+1065,(vlSelfRef.prim_filter__DOT__stored_vector_q),4);
        bufp->chgBit(oldp+1066,(vlSelfRef.prim_filter__DOT__stored_value_q));
        bufp->chgBit(oldp+1067,((1U & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                       >> 3U))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xeU]))) {
        bufp->chgCData(oldp+1068,(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q),2);
        bufp->chgBit(oldp+1069,(vlSelfRef.prim_filter_ctr__DOT__filter_q));
        bufp->chgBit(oldp+1070,(vlSelfRef.prim_filter_ctr__DOT__stored_value_q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0xfU]))) {
        bufp->chgCData(oldp+1071,(vlSelfRef.tlul_adapter_host__DOT__tl_source),8);
        bufp->chgCData(oldp+1072,(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q),2);
        bufp->chgBit(oldp+1073,(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x10U]))) {
        bufp->chgBit(oldp+1074,(vlSelfRef.prim_fifo_async_simple__DOT__src_ack));
        bufp->chgBit(oldp+1075,(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
        bufp->chgBit(oldp+1076,(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
        bufp->chgBit(oldp+1077,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs));
        bufp->chgBit(oldp+1078,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack));
        bufp->chgBit(oldp+1079,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x11U]))) {
        bufp->chgWData(oldp+1080,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage),110);
        bufp->chgWData(oldp+1084,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1087,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1091,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1094,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1098,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1101,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1105,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1108,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1112,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x12U]))) {
        bufp->chgWData(oldp+1115,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req),2560);
        bufp->chgWData(oldp+1195,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req),2560);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x13U]))) {
        bufp->chgBit(oldp+1275,(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
        bufp->chgBit(oldp+1276,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs));
        bufp->chgBit(oldp+1277,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q));
        bufp->chgBit(oldp+1278,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req));
        bufp->chgBit(oldp+1279,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x14U]))) {
        bufp->chgWData(oldp+1280,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1284,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1287,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1291,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1294,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1298,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1301,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1305,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
        bufp->chgWData(oldp+1308,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
        bufp->chgWData(oldp+1312,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x15U]))) {
        bufp->chgCData(oldp+1315,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q),5);
        bufp->chgCData(oldp+1316,((0x1fU & ((IData)(1U) 
                                            + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)))),5);
        bufp->chgCData(oldp+1317,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d),5);
        bufp->chgCData(oldp+1318,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q),5);
        bufp->chgCData(oldp+1319,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q))),4);
        bufp->chgBit(oldp+1320,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                                       >> 4U))));
        bufp->chgCData(oldp+1321,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray),5);
        bufp->chgCData(oldp+1322,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr),5);
        bufp->chgCData(oldp+1323,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr))),4);
        bufp->chgBit(oldp+1324,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr) 
                                       >> 4U))));
        bufp->chgCData(oldp+1325,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x16U]))) {
        bufp->chgBit(oldp+1326,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)))));
        bufp->chgCData(oldp+1327,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__wdepth_o),3);
        bufp->chgCData(oldp+1328,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q),3);
        bufp->chgCData(oldp+1329,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)))),3);
        bufp->chgCData(oldp+1330,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi),3);
        bufp->chgCData(oldp+1331,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync),3);
        bufp->chgCData(oldp+1332,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q),3);
        bufp->chgBit(oldp+1333,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk));
        bufp->chgBit(oldp+1334,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1335,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q) 
                                       >> 2U))));
        bufp->chgCData(oldp+1336,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q))),2);
        bufp->chgCData(oldp+1337,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q))),2);
        bufp->chgCData(oldp+1338,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq),3);
        bufp->chgBit(oldp+1339,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)))));
        bufp->chgCData(oldp+1340,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__rdepth_o),3);
        bufp->chgCData(oldp+1341,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q),3);
        bufp->chgCData(oldp+1342,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))),3);
        bufp->chgCData(oldp+1343,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi),3);
        bufp->chgCData(oldp+1344,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync),3);
        bufp->chgBit(oldp+1345,(((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                                 == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))));
        bufp->chgBit(oldp+1346,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk));
        bufp->chgBit(oldp+1347,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1348,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                                       >> 2U))));
        bufp->chgCData(oldp+1349,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))),2);
        bufp->chgCData(oldp+1350,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi))),2);
        bufp->chgCData(oldp+1351,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x17U]))) {
        bufp->chgBit(oldp+1352,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)))));
        bufp->chgCData(oldp+1353,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__rdepth_o),3);
        bufp->chgCData(oldp+1354,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q),3);
        bufp->chgCData(oldp+1355,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))),3);
        bufp->chgCData(oldp+1356,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi),3);
        bufp->chgCData(oldp+1357,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync),3);
        bufp->chgCData(oldp+1358,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q),3);
        bufp->chgCData(oldp+1359,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d),3);
        bufp->chgBit(oldp+1360,(((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                                 == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))));
        bufp->chgBit(oldp+1361,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk));
        bufp->chgBit(oldp+1362,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1363,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                                       >> 2U))));
        bufp->chgCData(oldp+1364,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))),2);
        bufp->chgCData(oldp+1365,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi))),2);
        bufp->chgCData(oldp+1366,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq),3);
        bufp->chgBit(oldp+1367,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)))));
        bufp->chgCData(oldp+1368,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__wdepth_o),3);
        bufp->chgCData(oldp+1369,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q),3);
        bufp->chgCData(oldp+1370,((7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)))),3);
        bufp->chgCData(oldp+1371,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi),3);
        bufp->chgCData(oldp+1372,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync),3);
        bufp->chgCData(oldp+1373,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q),3);
        bufp->chgCData(oldp+1374,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q),3);
        bufp->chgCData(oldp+1375,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d),3);
        bufp->chgBit(oldp+1376,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk));
        bufp->chgBit(oldp+1377,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1378,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q) 
                                       >> 2U))));
        bufp->chgCData(oldp+1379,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q))),2);
        bufp->chgCData(oldp+1380,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q))),2);
        bufp->chgCData(oldp+1381,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x18U]))) {
        bufp->chgIData(oldp+1382,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage),17);
        bufp->chgQData(oldp+1383,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage),40);
        bufp->chgCData(oldp+1385,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage),5);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1cU]))) {
        bufp->chgCData(oldp+1386,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q),3);
        bufp->chgCData(oldp+1387,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d),3);
        bufp->chgCData(oldp+1388,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q),3);
        bufp->chgCData(oldp+1389,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1dU]))) {
        bufp->chgCData(oldp+1390,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state),2);
        bufp->chgCData(oldp+1391,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q),8);
        bufp->chgBit(oldp+1392,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d));
        bufp->chgBit(oldp+1393,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en));
        bufp->chgCData(oldp+1394,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d),3);
        bufp->chgCData(oldp+1395,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d),4);
        bufp->chgBit(oldp+1396,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d));
        bufp->chgCData(oldp+1397,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_depth),2);
        bufp->chgCData(oldp+1398,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_depth),2);
        bufp->chgCData(oldp+1399,(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q),8);
        bufp->chgBit(oldp+1400,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid));
        bufp->chgBit(oldp+1401,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready));
        bufp->chgBit(oldp+1402,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid));
        bufp->chgBit(oldp+1403,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready));
        bufp->chgBit(oldp+1404,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o));
        bufp->chgCData(oldp+1405,((3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))),2);
        bufp->chgBit(oldp+1406,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+1407,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgCData(oldp+1408,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),3);
        bufp->chgCData(oldp+1409,((4U & ((~ ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 2U)) 
                                         << 2U))),3);
        bufp->chgBit(oldp+1410,((1U & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1411,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                 & (2U == (3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))))));
        bufp->chgBit(oldp+1412,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o));
        bufp->chgCData(oldp+1413,((3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))),2);
        bufp->chgBit(oldp+1414,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
        bufp->chgBit(oldp+1415,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
        bufp->chgBit(oldp+1416,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
        bufp->chgCData(oldp+1417,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),3);
        bufp->chgCData(oldp+1418,((4U & ((~ ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                             >> 2U)) 
                                         << 2U))),3);
        bufp->chgBit(oldp+1419,((1U & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                       >> 2U))));
        bufp->chgBit(oldp+1420,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                                 & (2U == (3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))))));
        bufp->chgBit(oldp+1421,((1U & (~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready)))));
        bufp->chgBit(oldp+1422,((1U & (~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))));
        bufp->chgBit(oldp+1423,((1U & (~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)))));
        bufp->chgBit(oldp+1424,((1U & (~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0x1eU]))) {
        bufp->chgIData(oldp+1425,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata),17);
        bufp->chgCData(oldp+1426,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata),5);
        bufp->chgIData(oldp+1427,(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data),32);
        bufp->chgCData(oldp+1428,(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ),7);
        bufp->chgIData(oldp+1429,(vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask),32);
    }
    bufp->chgBit(oldp+1430,(vlSelfRef.prim_cdc_rand_delay__02Eclk_i));
    bufp->chgBit(oldp+1431,(vlSelfRef.prim_cdc_rand_delay__02Erst_ni));
    bufp->chgBit(oldp+1432,(vlSelfRef.prev_data_i));
    bufp->chgBit(oldp+1433,(vlSelfRef.src_data_i));
    bufp->chgBit(oldp+1434,(vlSelfRef.dst_data_o));
    bufp->chgBit(oldp+1435,(vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i));
    bufp->chgBit(oldp+1436,(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni));
    bufp->chgBit(oldp+1437,(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i));
    bufp->chgBit(oldp+1438,(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    bufp->chgSData(oldp+1439,(vlSelfRef.prim_fifo_async_simple__02Ewdata_i),16);
    bufp->chgBit(oldp+1440,(vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i));
    bufp->chgBit(oldp+1441,(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni));
    bufp->chgBit(oldp+1442,(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    bufp->chgBit(oldp+1443,(vlSelfRef.prim_fifo_async_simple__02Erready_i));
    bufp->chgSData(oldp+1444,(vlSelfRef.prim_fifo_async_simple__02Erdata_o),16);
    bufp->chgBit(oldp+1445,(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i));
    bufp->chgBit(oldp+1446,(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni));
    bufp->chgBit(oldp+1447,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    bufp->chgBit(oldp+1448,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
    bufp->chgIData(oldp+1449,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i),32);
    bufp->chgCData(oldp+1450,(vlSelfRef.wdepth_o),5);
    bufp->chgBit(oldp+1451,(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i));
    bufp->chgBit(oldp+1452,(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni));
    bufp->chgBit(oldp+1453,(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o));
    bufp->chgBit(oldp+1454,(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    bufp->chgIData(oldp+1455,(vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o),32);
    bufp->chgCData(oldp+1456,(vlSelfRef.rdepth_o),5);
    bufp->chgBit(oldp+1457,(vlSelfRef.r_full_o));
    bufp->chgBit(oldp+1458,(vlSelfRef.r_notempty_o));
    bufp->chgBit(oldp+1459,(vlSelfRef.w_full_o));
    bufp->chgBit(oldp+1460,(vlSelfRef.w_sram_req_o));
    bufp->chgBit(oldp+1461,(vlSelfRef.w_sram_gnt_i));
    bufp->chgBit(oldp+1462,(vlSelfRef.w_sram_write_o));
    bufp->chgSData(oldp+1463,(vlSelfRef.w_sram_addr_o),16);
    bufp->chgIData(oldp+1464,(vlSelfRef.w_sram_wdata_o),32);
    bufp->chgIData(oldp+1465,(vlSelfRef.w_sram_wmask_o),32);
    bufp->chgBit(oldp+1466,(vlSelfRef.w_sram_rvalid_i));
    bufp->chgIData(oldp+1467,(vlSelfRef.w_sram_rdata_i),32);
    bufp->chgCData(oldp+1468,(vlSelfRef.w_sram_rerror_i),2);
    bufp->chgBit(oldp+1469,(vlSelfRef.r_sram_req_o));
    bufp->chgBit(oldp+1470,(vlSelfRef.r_sram_gnt_i));
    bufp->chgBit(oldp+1471,(vlSelfRef.r_sram_write_o));
    bufp->chgSData(oldp+1472,(vlSelfRef.r_sram_addr_o),16);
    bufp->chgIData(oldp+1473,(vlSelfRef.r_sram_wdata_o),32);
    bufp->chgIData(oldp+1474,(vlSelfRef.r_sram_wmask_o),32);
    bufp->chgBit(oldp+1475,(vlSelfRef.r_sram_rvalid_i));
    bufp->chgIData(oldp+1476,(vlSelfRef.r_sram_rdata_i),32);
    bufp->chgCData(oldp+1477,(vlSelfRef.r_sram_rerror_i),2);
    bufp->chgBit(oldp+1478,(vlSelfRef.prim_filter__02Eclk_i));
    bufp->chgBit(oldp+1479,(vlSelfRef.prim_filter__02Erst_ni));
    bufp->chgBit(oldp+1480,(vlSelfRef.prim_filter__02Eenable_i));
    bufp->chgBit(oldp+1481,(vlSelfRef.prim_filter__02Efilter_i));
    bufp->chgBit(oldp+1482,(vlSelfRef.prim_filter__02Efilter_o));
    bufp->chgBit(oldp+1483,(vlSelfRef.prim_filter_ctr__02Eclk_i));
    bufp->chgBit(oldp+1484,(vlSelfRef.prim_filter_ctr__02Erst_ni));
    bufp->chgBit(oldp+1485,(vlSelfRef.prim_filter_ctr__02Eenable_i));
    bufp->chgBit(oldp+1486,(vlSelfRef.prim_filter_ctr__02Efilter_i));
    bufp->chgCData(oldp+1487,(vlSelfRef.thresh_i),2);
    bufp->chgBit(oldp+1488,(vlSelfRef.prim_filter_ctr__02Efilter_o));
    bufp->chgBit(oldp+1489,(vlSelfRef.sram2tlul__02Eclk_i));
    bufp->chgBit(oldp+1490,(vlSelfRef.sram2tlul__02Erst_ni));
    bufp->chgWData(oldp+1491,(vlSelfRef.sram2tlul__02Etl_o),109);
    bufp->chgWData(oldp+1495,(vlSelfRef.sram2tlul__02Etl_i),66);
    bufp->chgBit(oldp+1498,(vlSelfRef.mem_req_i));
    bufp->chgBit(oldp+1499,(vlSelfRef.mem_write_i));
    bufp->chgSData(oldp+1500,(vlSelfRef.mem_addr_i),12);
    bufp->chgIData(oldp+1501,(vlSelfRef.mem_wdata_i),32);
    bufp->chgBit(oldp+1502,(vlSelfRef.mem_rvalid_o));
    bufp->chgIData(oldp+1503,(vlSelfRef.mem_rdata_o),32);
    bufp->chgCData(oldp+1504,(vlSelfRef.mem_error_o),2);
    bufp->chgBit(oldp+1505,(vlSelfRef.tlul_adapter_host__02Eclk_i));
    bufp->chgBit(oldp+1506,(vlSelfRef.tlul_adapter_host__02Erst_ni));
    bufp->chgBit(oldp+1507,(vlSelfRef.req_i));
    bufp->chgBit(oldp+1508,(vlSelfRef.gnt_o));
    bufp->chgIData(oldp+1509,(vlSelfRef.addr_i),32);
    bufp->chgBit(oldp+1510,(vlSelfRef.we_i));
    bufp->chgIData(oldp+1511,(vlSelfRef.tlul_adapter_host__02Ewdata_i),32);
    bufp->chgCData(oldp+1512,(vlSelfRef.wdata_intg_i),7);
    bufp->chgCData(oldp+1513,(vlSelfRef.be_i),4);
    bufp->chgCData(oldp+1514,(vlSelfRef.instr_type_i),4);
    bufp->chgBit(oldp+1515,(vlSelfRef.valid_o));
    bufp->chgIData(oldp+1516,(vlSelfRef.tlul_adapter_host__02Erdata_o),32);
    bufp->chgCData(oldp+1517,(vlSelfRef.rdata_intg_o),7);
    bufp->chgBit(oldp+1518,(vlSelfRef.err_o));
    bufp->chgBit(oldp+1519,(vlSelfRef.intg_err_o));
    bufp->chgWData(oldp+1520,(vlSelfRef.tlul_adapter_host__02Etl_o),109);
    bufp->chgWData(oldp+1524,(vlSelfRef.tlul_adapter_host__02Etl_i),66);
    bufp->chgBit(oldp+1527,(vlSelfRef.tlul_adapter_sram__02Eclk_i));
    bufp->chgBit(oldp+1528,(vlSelfRef.tlul_adapter_sram__02Erst_ni));
    bufp->chgWData(oldp+1529,(vlSelfRef.tlul_adapter_sram__02Etl_i),109);
    bufp->chgWData(oldp+1533,(vlSelfRef.tlul_adapter_sram__02Etl_o),66);
    bufp->chgCData(oldp+1536,(vlSelfRef.en_ifetch_i),4);
    bufp->chgBit(oldp+1537,(vlSelfRef.req_o));
    bufp->chgCData(oldp+1538,(vlSelfRef.req_type_o),4);
    bufp->chgBit(oldp+1539,(vlSelfRef.gnt_i));
    bufp->chgBit(oldp+1540,(vlSelfRef.we_o));
    bufp->chgSData(oldp+1541,(vlSelfRef.addr_o),12);
    bufp->chgIData(oldp+1542,(vlSelfRef.wdata_o),32);
    bufp->chgIData(oldp+1543,(vlSelfRef.wmask_o),32);
    bufp->chgBit(oldp+1544,(vlSelfRef.intg_error_o));
    bufp->chgIData(oldp+1545,(vlSelfRef.rdata_i),32);
    bufp->chgBit(oldp+1546,(vlSelfRef.rvalid_i));
    bufp->chgCData(oldp+1547,(vlSelfRef.rerror_i),2);
    bufp->chgBit(oldp+1548,(vlSelfRef.compound_txn_in_progress_o));
    bufp->chgCData(oldp+1549,(vlSelfRef.readback_en_i),4);
    bufp->chgBit(oldp+1550,(vlSelfRef.readback_error_o));
    bufp->chgBit(oldp+1551,(vlSelfRef.wr_collision_i));
    bufp->chgBit(oldp+1552,(vlSelfRef.write_pending_i));
    bufp->chgBit(oldp+1553,(vlSelfRef.tlul_assert_multiple__02Eclk_i));
    bufp->chgBit(oldp+1554,(vlSelfRef.tlul_assert_multiple__02Erst_ni));
    bufp->chgWData(oldp+1555,(vlSelfRef.h2d),218);
    bufp->chgWData(oldp+1562,(vlSelfRef.d2h),132);
    bufp->chgBit(oldp+1567,(vlSelfRef.clk_h_i));
    bufp->chgBit(oldp+1568,(vlSelfRef.rst_h_ni));
    bufp->chgBit(oldp+1569,(vlSelfRef.clk_d_i));
    bufp->chgBit(oldp+1570,(vlSelfRef.rst_d_ni));
    bufp->chgWData(oldp+1571,(vlSelfRef.tlul_fifo_async__02Etl_h_i),109);
    bufp->chgWData(oldp+1575,(vlSelfRef.tlul_fifo_async__02Etl_h_o),66);
    bufp->chgWData(oldp+1578,(vlSelfRef.tlul_fifo_async__02Etl_d_o),109);
    bufp->chgWData(oldp+1582,(vlSelfRef.tlul_fifo_async__02Etl_d_i),66);
    bufp->chgBit(oldp+1585,(vlSelfRef.tlul_socket_1n__02Eclk_i));
    bufp->chgBit(oldp+1586,(vlSelfRef.tlul_socket_1n__02Erst_ni));
    bufp->chgWData(oldp+1587,(vlSelfRef.tlul_socket_1n__02Etl_h_i),109);
    bufp->chgWData(oldp+1591,(vlSelfRef.tlul_socket_1n__02Etl_h_o),66);
    bufp->chgWData(oldp+1594,(vlSelfRef.tlul_socket_1n__02Etl_d_o),436);
    bufp->chgWData(oldp+1608,(vlSelfRef.tlul_socket_1n__02Etl_d_i),264);
    bufp->chgCData(oldp+1617,(vlSelfRef.dev_select_i),3);
    bufp->chgBit(oldp+1618,(vlSelfRef.tlul_socket_m1__02Eclk_i));
    bufp->chgBit(oldp+1619,(vlSelfRef.tlul_socket_m1__02Erst_ni));
    bufp->chgWData(oldp+1620,(vlSelfRef.tlul_socket_m1__02Etl_h_i),436);
    bufp->chgWData(oldp+1634,(vlSelfRef.tlul_socket_m1__02Etl_h_o),264);
    bufp->chgWData(oldp+1643,(vlSelfRef.tlul_socket_m1__02Etl_d_o),109);
    bufp->chgWData(oldp+1647,(vlSelfRef.tlul_socket_m1__02Etl_d_i),66);
    bufp->chgBit(oldp+1650,(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack));
    bufp->chgSData(oldp+1651,(vlSelfRef.prim_fifo_async_simple__DOT__data_q),16);
    bufp->chgBit(oldp+1652,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag));
    bufp->chgBit(oldp+1653,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns));
    bufp->chgBit(oldp+1654,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d));
    bufp->chgBit(oldp+1655,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q));
    bufp->chgBit(oldp+1656,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d));
    bufp->chgBit(oldp+1657,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake));
    bufp->chgCData(oldp+1658,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d),5);
    bufp->chgCData(oldp+1659,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q),5);
    bufp->chgBit(oldp+1660,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc));
    bufp->chgBit(oldp+1661,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc));
    bufp->chgBit(oldp+1662,(((IData)(vlSelfRef.r_sram_gnt_i) 
                             & (IData)(vlSelfRef.r_sram_req_o))));
    bufp->chgBit(oldp+1663,((1U & ((IData)(vlSelfRef.w_sram_rvalid_i) 
                                   ^ (VL_REDXOR_32(vlSelfRef.w_sram_rdata_i) 
                                      ^ VL_REDXOR_2(vlSelfRef.w_sram_rerror_i))))));
    bufp->chgBit(oldp+1664,((1U & VL_REDXOR_2(vlSelfRef.r_sram_rerror_i))));
    bufp->chgBit(oldp+1665,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en));
    bufp->chgCData(oldp+1666,(vlSelfRef.prim_filter__DOT__stored_vector_d),4);
    bufp->chgBit(oldp+1667,(((0U == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)) 
                             | (0xfU == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)))));
    bufp->chgCData(oldp+1668,(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d),2);
    bufp->chgBit(oldp+1669,(((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d) 
                             == (IData)(vlSelfRef.thresh_i))));
    bufp->chgCData(oldp+1670,(((IData)(vlSelfRef.we_i)
                                ? (IData)(vlSelfRef.be_i)
                                : 0xfU)),4);
    bufp->chgBit(oldp+1671,((1U & VL_REDXOR_32((3U 
                                                & vlSelfRef.addr_i)))));
    bufp->chgBit(oldp+1672,((1U & (VL_REDXOR_16((0xfffcU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_i[0U])) 
                                   ^ VL_REDXOR_32((0x1ffffU 
                                                   & ((vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                                                       << 0x10U) 
                                                      | (vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                         >> 0x10U))))))));
    bufp->chgBit(oldp+1673,((1U & ((~ (((0U == (7U 
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
    bufp->chgBit(oldp+1674,((1U & VL_REDXOR_32((((vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                                  ^ 
                                                  vlSelfRef.tlul_adapter_sram__02Etl_i[1U]) 
                                                 ^ 
                                                 vlSelfRef.tlul_adapter_sram__02Etl_i[2U]) 
                                                ^ vlSelfRef.tlul_adapter_sram__02Etl_i[3U])))));
    bufp->chgBit(oldp+1675,((IData)(((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                      >> 0xcU) & vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]))));
    bufp->chgBit(oldp+1676,(((~ (IData)(vlSelfRef.we_o)) 
                             & ((IData)(vlSelfRef.req_o) 
                                & (IData)(vlSelfRef.gnt_i)))));
    bufp->chgSData(oldp+1677,((0xfffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                          << 2U) | 
                                         (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                          >> 0x1eU)))),12);
    bufp->chgBit(oldp+1678,(((IData)(vlSelfRef.req_o) 
                             & (IData)(vlSelfRef.gnt_i))));
    bufp->chgBit(oldp+1679,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
                             & ((~ vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                   >> 0xcU)))));
    bufp->chgIData(oldp+1680,((vlSelfRef.rdata_i & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask)),32);
    bufp->chgBit(oldp+1681,((1U & (IData)(vlSelfRef.rerror_i))));
    bufp->chgBit(oldp+1682,((1U & VL_REDXOR_32((0xfffU 
                                                & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x1eU)))))));
    bufp->chgBit(oldp+1683,(((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                           >> 9U))) 
                             | ((1U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                              >> 9U))) 
                                | (4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U)))))));
    bufp->chgBit(oldp+1684,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                             & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
                                & ((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                 >> 9U))) 
                                   | ((1U == (7U & 
                                              (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                               >> 9U))) 
                                      | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->chgBit(oldp+1685,((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1686,((1U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1687,((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                          >> 9U)))));
    bufp->chgCData(oldp+1688,((0xfU & ((IData)(1U) 
                                       << (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                 >> 0x1cU))))),4);
    bufp->chgBit(oldp+1689,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->chgBit(oldp+1690,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->chgQData(oldp+1691,((((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                                ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                                : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage)),40);
    bufp->chgBit(oldp+1693,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->chgBit(oldp+1694,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->chgBit(oldp+1695,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    __Vtemp_369[0U] = ((vlSelfRef.h2d[4U] << 0x13U) 
                       | (vlSelfRef.h2d[3U] >> 0xdU));
    __Vtemp_369[1U] = ((vlSelfRef.h2d[5U] << 0x13U) 
                       | (vlSelfRef.h2d[4U] >> 0xdU));
    __Vtemp_369[2U] = ((vlSelfRef.h2d[6U] << 0x13U) 
                       | (vlSelfRef.h2d[5U] >> 0xdU));
    __Vtemp_369[3U] = (0x1fffU & (vlSelfRef.h2d[6U] 
                                  >> 0xdU));
    bufp->chgWData(oldp+1696,(__Vtemp_369),109);
    __Vtemp_372[0U] = ((vlSelfRef.d2h[3U] << 0x1eU) 
                       | (vlSelfRef.d2h[2U] >> 2U));
    __Vtemp_372[1U] = ((vlSelfRef.d2h[4U] << 0x1eU) 
                       | (vlSelfRef.d2h[3U] >> 2U));
    __Vtemp_372[2U] = (3U & (vlSelfRef.d2h[4U] >> 2U));
    bufp->chgWData(oldp+1700,(__Vtemp_372),66);
    bufp->chgCData(oldp+1703,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask),8);
    __Vtemp_375[0U] = vlSelfRef.h2d[0U];
    __Vtemp_375[1U] = vlSelfRef.h2d[1U];
    __Vtemp_375[2U] = vlSelfRef.h2d[2U];
    __Vtemp_375[3U] = (0x1fffU & vlSelfRef.h2d[3U]);
    bufp->chgWData(oldp+1704,(__Vtemp_375),109);
    __Vtemp_378[0U] = vlSelfRef.d2h[0U];
    __Vtemp_378[1U] = vlSelfRef.d2h[1U];
    __Vtemp_378[2U] = (3U & vlSelfRef.d2h[2U]);
    bufp->chgWData(oldp+1708,(__Vtemp_378),66);
    bufp->chgCData(oldp+1711,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask),8);
    bufp->chgBit(oldp+1712,((1U & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
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
    bufp->chgWData(oldp+1713,(__Vtemp_381),107);
    bufp->chgBit(oldp+1717,((1U & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])));
    bufp->chgBit(oldp+1718,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+1719,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+1720,((1U & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
                                   >> 1U))));
    bufp->chgQData(oldp+1721,((((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[2U])) 
                                << 0x3fU) | (((QData)((IData)(
                                                              vlSelfRef.tlul_fifo_async__02Etl_d_i[1U])) 
                                              << 0x1fU) 
                                             | ((QData)((IData)(
                                                                vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])) 
                                                >> 1U)))),64);
    bufp->chgBit(oldp+1723,((1U & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U])));
    bufp->chgQData(oldp+1724,(((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                ? 0ULL : vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                               [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])),64);
    bufp->chgBit(oldp+1726,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+1727,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr));
    bufp->chgQData(oldp+1728,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                              [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]),64);
    bufp->chgBit(oldp+1730,((1U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
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
    bufp->chgWData(oldp+1731,(__Vtemp_383),110);
    bufp->chgBit(oldp+1735,((1U & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U])));
    bufp->chgCData(oldp+1736,((0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                        >> 1U))),8);
    bufp->chgCData(oldp+1737,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                     >> 9U))),2);
    bufp->chgCData(oldp+1738,((1U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                              >> 0x14U)))),8);
    bufp->chgCData(oldp+1739,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                     >> 0x1cU))),2);
    bufp->chgCData(oldp+1740,((2U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                              >> 7U)))),8);
    bufp->chgCData(oldp+1741,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                     >> 0xfU))),2);
    bufp->chgCData(oldp+1742,((3U | (0xfcU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                               << 6U) 
                                              | (0x3cU 
                                                 & (vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                                                    >> 0x1aU)))))),8);
    bufp->chgCData(oldp+1743,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                     >> 2U))),2);
    bufp->chgBit(oldp+1744,((1U & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U])));
    bufp->chgBit(oldp+1745,((1U & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
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
    bufp->chgWData(oldp+1746,(__Vtemp_385),65);
    bufp->chgBit(oldp+1749,(vlSymsp->TOP__spi_host_tb.__PVT__clk_i));
    bufp->chgWData(oldp+1750,(vlSymsp->TOP__spi_host_tb__tl_if.h2d),109);
    bufp->chgIData(oldp+1754,((((IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q) 
                                << 0x1cU) | (((IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q) 
                                              << 0x1bU) 
                                             | (((IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
                                                 << 0x1aU) 
                                                | ((0xff000000U 
                                                    & (((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                                                        << 0x17U) 
                                                       & (((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                                           & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)) 
                                                          << 0x18U))) 
                                                   | ((0xffc00000U 
                                                       & (((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                                                           << 0x15U) 
                                                          & (((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                                              & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)) 
                                                             << 0x16U))) 
                                                      | ((0xfff00000U 
                                                          & (((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                                                              << 0x13U) 
                                                             & (((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                                                 & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)) 
                                                                << 0x14U))) 
                                                         | ((0xfffc0000U 
                                                             & (((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                                                                 << 0x11U) 
                                                                & (((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                                                    & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)) 
                                                                   << 0x12U))) 
                                                            | ((0xfffffe00U 
                                                                & (((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                                                                    << 7U) 
                                                                   & (((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                                                       & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)) 
                                                                      << 9U))) 
                                                               | (((IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q) 
                                                                   << 1U) 
                                                                  | (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe))))))))))),29);
    bufp->chgSData(oldp+1755,((((0x800U & ((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready)) 
                                           << 0xbU)) 
                                | (0x400U & ((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)) 
                                             << 0xaU))) 
                               | ((0x200U & ((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)) 
                                             << 9U)) 
                                  | ((0x100U & ((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid)) 
                                                << 8U)) 
                                     | ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
                                         ? 0U : ((0x17U 
                                                  >= 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(5,5,32, 
                                                                   (3U 
                                                                    & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                                  ? 
                                                 (0xffU 
                                                  & (vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                                                     >> 
                                                     (0x1fU 
                                                      & VL_SHIFTL_III(5,5,32, 
                                                                      (3U 
                                                                       & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                                  : 0U)))))),12);
    bufp->chgCData(oldp+1756,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d),8);
    bufp->chgBit(oldp+1757,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_d));
    bufp->chgCData(oldp+1758,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata),8);
    bufp->chgBit(oldp+1759,((((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                              >> 2U) & ((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                        & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)))));
    bufp->chgCData(oldp+1760,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
                                ? 0U : ((0x17U >= (0x1fU 
                                                   & VL_SHIFTL_III(5,5,32, 
                                                                   (3U 
                                                                    & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                         ? (0xffU & 
                                            (vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                                             >> (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (3U 
                                                                  & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                         : 0U))),8);
    bufp->chgBit(oldp+1761,(((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk)) 
                             & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en))));
    bufp->chgBit(oldp+1762,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgIData(oldp+1763,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage),24);
    bufp->chgCData(oldp+1764,(((0x17U >= (0x1fU & VL_SHIFTL_III(5,5,32, 
                                                                (3U 
                                                                 & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                ? (0xffU & (vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, 
                                                                (3U 
                                                                 & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                : 0U)),8);
    bufp->chgBit(oldp+1765,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (2U == (3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))))));
    bufp->chgIData(oldp+1766,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage),24);
    bufp->chgCData(oldp+1767,(((0x17U >= (0x1fU & VL_SHIFTL_III(5,5,32, 
                                                                (3U 
                                                                 & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                ? (0xffU & (vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                            >> (0x1fU 
                                                & VL_SHIFTL_III(5,5,32, 
                                                                (3U 
                                                                 & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                : 0U)),8);
    bufp->chgBit(oldp+1768,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (2U == (3U & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))))));
    bufp->chgCData(oldp+1769,((0xcU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                       >> 0x1cU))),4);
    bufp->chgIData(oldp+1770,(((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                << 8U) | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                          >> 0x18U))),32);
    bufp->chgCData(oldp+1771,((0xfU & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                       >> 0x18U))),4);
    bufp->chgIData(oldp+1772,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+1773,(((~ (IData)((0U != (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit)))) 
                             & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re) 
                                | (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we)))));
    bufp->chgBit(oldp+1774,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we) 
                             & ((IData)((0U != (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit))) 
                                & (0U != (1U & (~ (
                                                   (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                      >> 0x18U)))))))));
    bufp->chgBit(oldp+1775,((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                   >> 0x18U))));
    bufp->chgBit(oldp+1776,((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                   >> 0x19U))));
    bufp->chgBit(oldp+1777,((1U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                   >> 0x1aU))));
    bufp->chgBit(oldp+1778,((((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                              >> 1U) & ((~ (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                                        & (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re)))));
    bufp->chgBit(oldp+1779,(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en));
    bufp->chgCData(oldp+1780,((vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                               >> 0x18U)),8);
    bufp->chgBit(oldp+1781,((1U & VL_REDXOR_32(((vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                 << 8U) 
                                                | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                                   >> 0x18U))))));
    bufp->chgBit(oldp+1782,((1U & VL_REDXOR_32((0xfU 
                                                & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                   >> 0x18U))))));
    bufp->chgBit(oldp+1783,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en)
                              ? ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                                 & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                    >> 0x18U)) : (IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q))));
    bufp->chgBit(oldp+1784,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                             & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                >> 0x18U))));
    bufp->chgBit(oldp+1785,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en)
                              ? ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                                 & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                    >> 0x1aU)) : (IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q))));
    bufp->chgBit(oldp+1786,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                             & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                >> 0x1aU))));
    bufp->chgBit(oldp+1787,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en)
                              ? ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                                 & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                    >> 0x19U)) : (IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q))));
    bufp->chgBit(oldp+1788,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                             & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                >> 0x19U))));
    bufp->chgBit(oldp+1789,((IData)(((vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                      >> 1U) & vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U]))));
    bufp->chgBit(oldp+1790,((1U & ((~ (((0U == (7U 
                                                & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                   >> 9U))) 
                                        | ((1U == (7U 
                                                   & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                      >> 9U))) 
                                           | (4U == 
                                              (7U & 
                                               (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 9U))))) 
                                       & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                                          & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                             & ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                     >> 9U))) 
                                                | ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                        >> 9U))) 
                                                   | (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk))))))) 
                                   | ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err) 
                                      | (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err))))));
    bufp->chgBit(oldp+1791,(((0U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                           >> 9U))) 
                             | ((1U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                              >> 9U))) 
                                | (4U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                >> 9U)))))));
    bufp->chgBit(oldp+1792,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                             & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                & ((4U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                                 >> 9U))) 
                                   | ((1U == (7U & 
                                              (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                               >> 9U))) 
                                      | (IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->chgBit(oldp+1793,((0U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1794,((1U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                          >> 9U)))));
    bufp->chgBit(oldp+1795,((4U == (7U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[3U] 
                                          >> 9U)))));
    bufp->chgCData(oldp+1796,((0xfU & ((IData)(1U) 
                                       << (3U & (vlSymsp->TOP__spi_host_tb__tl_if.h2d[1U] 
                                                 >> 0x1cU))))),4);
    bufp->chgCData(oldp+1797,((0xffU & ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en)
                                         ? ((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en)
                                             ? ((vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                                 << 8U) 
                                                | (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                                   >> 0x18U))
                                             : 0U) : (IData)(vlSymsp->TOP__spi_host_tb.u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q)))),8);
    bufp->chgCData(oldp+1798,(((IData)(vlSymsp->TOP__spi_host_tb.__PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en)
                                ? (vlSymsp->TOP__spi_host_tb__tl_if.h2d[0U] 
                                   >> 0x18U) : 0U)),8);
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
    bufp->chgWData(oldp+1799,(__Vtemp_391),66);
    __Vtemp_394[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[7U] 
                        << 0x1aU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                     >> 6U));
    __Vtemp_394[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                        << 0x1aU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[7U] 
                                     >> 6U));
    __Vtemp_394[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                             >> 6U));
    bufp->chgWData(oldp+1802,(__Vtemp_394),66);
    bufp->chgBit(oldp+1805,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                >> 7U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1806,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                   >> 6U))));
    bufp->chgBit(oldp+1807,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
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
    bufp->chgWData(oldp+1808,(__Vtemp_402),65);
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
    bufp->chgWData(oldp+1811,(__Vtemp_404),65);
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
    bufp->chgWData(oldp+1814,(__Vtemp_410),66);
    __Vtemp_413[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[5U] 
                        << 0x1cU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                     >> 4U));
    __Vtemp_413[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                        << 0x1cU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[5U] 
                                     >> 4U));
    __Vtemp_413[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                             >> 4U));
    bufp->chgWData(oldp+1817,(__Vtemp_413),66);
    bufp->chgBit(oldp+1820,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                >> 5U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1821,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                   >> 4U))));
    bufp->chgBit(oldp+1822,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
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
    bufp->chgWData(oldp+1823,(__Vtemp_421),65);
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
    bufp->chgWData(oldp+1826,(__Vtemp_423),65);
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
    bufp->chgWData(oldp+1829,(__Vtemp_429),66);
    __Vtemp_432[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[3U] 
                        << 0x1eU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                     >> 2U));
    __Vtemp_432[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                        << 0x1eU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[3U] 
                                     >> 2U));
    __Vtemp_432[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                             >> 2U));
    bufp->chgWData(oldp+1832,(__Vtemp_432),66);
    bufp->chgBit(oldp+1835,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                >> 3U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1836,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                   >> 2U))));
    bufp->chgBit(oldp+1837,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
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
    bufp->chgWData(oldp+1838,(__Vtemp_440),65);
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
    bufp->chgWData(oldp+1841,(__Vtemp_442),65);
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
    bufp->chgWData(oldp+1844,(__Vtemp_448),66);
    __Vtemp_451[0U] = vlSelfRef.tlul_socket_1n__02Etl_d_i[0U];
    __Vtemp_451[1U] = vlSelfRef.tlul_socket_1n__02Etl_d_i[1U];
    __Vtemp_451[2U] = (3U & vlSelfRef.tlul_socket_1n__02Etl_d_i[2U]);
    bufp->chgWData(oldp+1847,(__Vtemp_451),66);
    bufp->chgBit(oldp+1850,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                >> 1U))
                                             ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->chgBit(oldp+1851,((1U & vlSelfRef.tlul_socket_1n__02Etl_d_i[0U])));
    bufp->chgBit(oldp+1852,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
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
    bufp->chgWData(oldp+1853,(__Vtemp_459),65);
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
    bufp->chgWData(oldp+1856,(__Vtemp_461),65);
    bufp->chgBit(oldp+1859,(vlSymsp->TOP__spi_host_tb__tl_if.__PVT__clk_i));
    bufp->chgWData(oldp+1860,(vlSymsp->TOP__spi_host_tb__tl_if.d2h),66);
}

void Vspi_host_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root__trace_cleanup\n"); );
    // Init
    Vspi_host_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vspi_host_tb___024root*>(voidSelf);
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
    vlSymsp->TOP.__Vm_traceActivity[0x1eU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 0U;
}
