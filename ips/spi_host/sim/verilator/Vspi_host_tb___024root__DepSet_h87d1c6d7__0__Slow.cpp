// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb___024root.h"

VL_ATTR_COLD void Vspi_host_tb___024root___eval_static(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_static\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_wr_i__0 
        = vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_wr_ni__0 
        = vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_rd_i__0 
        = vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_rd_ni__0 
        = vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n__0 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n;
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
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Eclk_i__0 
        = vlSelfRef.tlul_adapter_host__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Erst_ni__0 
        = vlSelfRef.tlul_adapter_host__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Eclk_i__0 
        = vlSelfRef.tlul_adapter_sram__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Erst_ni__0 
        = vlSelfRef.tlul_adapter_sram__02Erst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_assert_multiple__02Eclk_i__0 
        = vlSelfRef.tlul_assert_multiple__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tlul_assert_multiple__02Erst_ni__0 
        = vlSelfRef.tlul_assert_multiple__02Erst_ni;
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
    vlSelfRef.__Vtrigprevexpr___TOP__spi_host_tb____PVT__clk_i__0 
        = vlSymsp->TOP__spi_host_tb.__PVT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__spi_host_tb____PVT__rst_ni__0 
        = vlSymsp->TOP__spi_host_tb.__PVT__rst_ni;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host_tb___024root___dump_triggers__stl(Vspi_host_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vspi_host_tb___024root___eval_triggers__stl(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_triggers__stl\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vspi_host_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vspi_host_tb___024root___stl_sequent__TOP__0(Vspi_host_tb___024root* vlSelf);
VL_ATTR_COLD void Vspi_host_tb___024root____Vm_traceActivitySetAll(Vspi_host_tb___024root* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_spi_host_tb___stl_sequent__TOP__spi_host_tb__0(Vspi_host_tb_spi_host_tb* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
VL_ATTR_COLD void Vspi_host_tb___024root___stl_sequent__TOP__1(Vspi_host_tb___024root* vlSelf);
void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tb___024root___ico_sequent__TOP__2(Vspi_host_tb___024root* vlSelf);

VL_ATTR_COLD void Vspi_host_tb___024root___eval_stl(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_stl\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vspi_host_tb___024root___stl_sequent__TOP__0(vlSelf);
        Vspi_host_tb___024root____Vm_traceActivitySetAll(vlSelf);
        Vspi_host_tb_spi_host_tb___stl_sequent__TOP__spi_host_tb__0((&vlSymsp->TOP__spi_host_tb));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___stl_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host_tb___024root___stl_sequent__TOP__1(vlSelf);
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host_tb___024root___ico_sequent__TOP__2(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 16> Vspi_host_tb__ConstPool__TABLE_h91148bf5_0;
extern const VlUnpacked<IData/*31:0*/, 16> Vspi_host_tb__ConstPool__TABLE_hce599b47_0;

VL_ATTR_COLD void Vspi_host_tb___024root___stl_sequent__TOP__1(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___stl_sequent__TOP__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<4>/*127:0*/ __Vtemp_33;
    VlWide<4>/*127:0*/ __Vtemp_44;
    VlWide<4>/*127:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<4>/*127:0*/ __Vtemp_79;
    VlWide<4>/*127:0*/ __Vtemp_80;
    VlWide<4>/*127:0*/ __Vtemp_81;
    VlWide<4>/*127:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<4>/*127:0*/ __Vtemp_96;
    // Body
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                       << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                  >> 7U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x3fU) | (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                        >> 7U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x1fU) | ((QData)((IData)(
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
          >> 0x1fU) | ((IData)(((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                  >> 1U))) 
                                >> 0x20U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][2U]) | (3U & ((IData)(((((QData)((IData)(
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
                                        << 0x3fU) | 
                                       (((QData)((IData)(
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
                                      >> 0x20U)) >> 0x1fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [0U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                       << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                  >> 5U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x3fU) | (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                        >> 5U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x1fU) | ((QData)((IData)(
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
          >> 0x1fU) | ((IData)(((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                  >> 1U))) 
                                >> 0x20U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][2U]) | (3U & ((IData)(((((QData)((IData)(
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
                                        << 0x3fU) | 
                                       (((QData)((IData)(
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
                                      >> 0x20U)) >> 0x1fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [1U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                       << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                  >> 3U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x3fU) | (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                        >> 3U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x1fU) | ((QData)((IData)(
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
          >> 0x1fU) | ((IData)(((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                  >> 1U))) 
                                >> 0x20U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][2U]) | (3U & ((IData)(((((QData)((IData)(
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
                                        << 0x3fU) | 
                                       (((QData)((IData)(
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
                                      >> 0x20U)) >> 0x1fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [2U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[0U]) 
                                               | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_22[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [3U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][1U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][1U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [3U][3U] 
                                                  >> 0xcU))
                                               ? (0xfffffffeU 
                                                  & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [3U][0U])
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                    >> 1U));
    __Vtemp_22[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [3U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][2U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][2U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [3U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [3U][1U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_22[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [3U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][3U]) | (0xffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][3U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [3U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [3U][2U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[0U]) 
                                               | (__Vtemp_22[0U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U] = ((__Vtemp_22[0U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_22[1U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U] = ((__Vtemp_22[1U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_22[2U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U] = ((0xfffff000U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[3U]) 
                                               | ((__Vtemp_22[2U] 
                                                   >> 0x1fU) 
                                                  | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                      ? 0U
                                                      : 
                                                     (0xffeU 
                                                      & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                          & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                             [3U][3U] 
                                                             >> 0xcU))
                                                          ? 
                                                         ((1U 
                                                           & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                           [3U][3U]) 
                                                          | (0xffeU 
                                                             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                             [3U][3U]))
                                                          : 
                                                         vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U] = ((0xffffcfffU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[3U]) 
                                               | (0xfffff000U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o) 
                                                      << 0xdU) 
                                                     | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                                                        << 0xcU))));
    __Vtemp_33[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [2U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][1U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][1U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [2U][3U] 
                                                  >> 0xcU))
                                               ? (0xfffffffeU 
                                                  & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [2U][0U])
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                    >> 1U));
    __Vtemp_33[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [2U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][2U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][2U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [2U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [2U][1U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_33[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [2U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][3U]) | (0xffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][3U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [2U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [2U][2U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U] = ((0x3fffU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[3U]) 
                                               | (__Vtemp_33[0U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[4U] = ((__Vtemp_33[0U] 
                                                >> 0x12U) 
                                               | (__Vtemp_33[1U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[5U] = ((__Vtemp_33[1U] 
                                                >> 0x12U) 
                                               | (__Vtemp_33[2U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[6U] = ((0xfe000000U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[6U]) 
                                               | ((__Vtemp_33[2U] 
                                                   >> 0x12U) 
                                                  | (0x1ffc000U 
                                                     & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                          ? 0U
                                                          : 
                                                         (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                           & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                              [2U][3U] 
                                                              >> 0xcU))
                                                           ? 
                                                          ((1U 
                                                            & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                            [2U][3U]) 
                                                           | (0xffeU 
                                                              & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                              [2U][3U]))
                                                           : 
                                                          vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                                                        << 0xdU))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[6U] = ((0xf9ffffffU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[6U]) 
                                               | (0xfe000000U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o) 
                                                      << 0x1aU) 
                                                     | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                                                        << 0x19U))));
    __Vtemp_44[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][1U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][1U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][3U] 
                                                  >> 0xcU))
                                               ? (0xfffffffeU 
                                                  & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][0U])
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                    >> 1U));
    __Vtemp_44[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][2U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][2U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [1U][1U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_44[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][3U]) | (0xffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][3U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [1U][2U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[6U] = ((0x7ffffffU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[6U]) 
                                               | (__Vtemp_44[0U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[7U] = ((__Vtemp_44[0U] 
                                                >> 5U) 
                                               | (__Vtemp_44[1U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[8U] = ((__Vtemp_44[1U] 
                                                >> 5U) 
                                               | (__Vtemp_44[2U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[9U] = ((__Vtemp_44[2U] 
                                                >> 5U) 
                                               | (0xf8000000U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                       ? 0U
                                                       : 
                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
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
                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                                                     << 0x1aU)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xaU] = ((0xffffffc0U 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xaU]) 
                                                 | (0x3fU 
                                                    & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                         ? 0U
                                                         : 
                                                        (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
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
                                                         vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                                                       >> 6U)));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xaU] = ((0xffffff3fU 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xaU]) 
                                                 | (0xffffffc0U 
                                                    & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o) 
                                                        << 7U) 
                                                       | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                                                          << 6U))));
    __Vtemp_55[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][1U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][1U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][3U] 
                                                  >> 0xcU))
                                               ? (0xfffffffeU 
                                                  & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][0U])
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                    >> 1U));
    __Vtemp_55[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][2U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][2U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [0U][1U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_55[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][3U]) | (0xffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][3U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [0U][2U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xaU] = ((0xffU 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xaU]) 
                                                 | (__Vtemp_55[0U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xbU] = ((__Vtemp_55[0U] 
                                                  >> 0x18U) 
                                                 | (__Vtemp_55[1U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xcU] = ((__Vtemp_55[1U] 
                                                  >> 0x18U) 
                                                 | (__Vtemp_55[2U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU] = ((0x80000U 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU]) 
                                                 | (0xfffffU 
                                                    & ((__Vtemp_55[2U] 
                                                        >> 0x18U) 
                                                       | (0x7ff00U 
                                                          & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
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
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                                                             << 7U)))));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU] = ((0x7ffffU 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU]) 
                                                 | (0xfffffU 
                                                    & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                                                       << 0x13U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][0U]) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][0U]) | ((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                       << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][1U] = 
        (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                  >> 1U))
                                               ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                    << 0x3fU) | (((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                  << 0x1fU) | ((QData)((IData)(
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
          >> 0x1fU) | ((IData)(((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                  >> 1U))) 
                                >> 0x20U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U] = 
        ((2U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][2U]) | (3U & ((IData)(((((QData)((IData)(
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
                                        << 0x3fU) | 
                                       (((QData)((IData)(
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
                                      >> 0x20U)) >> 0x1fU)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U] = 
        ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
          [3U][2U]) | (3U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                             << 1U)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U] 
        = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U];
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U] 
        = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[1U];
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U] 
        = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[2U];
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
            << 0xdU) | vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[3U]);
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[4U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
            >> 0x13U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[1U] 
                         << 0xdU));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[5U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[1U] 
            >> 0x13U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[2U] 
                         << 0xdU));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[6U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
            << 0x1aU) | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[2U] 
                          >> 0x13U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                       << 0xdU)));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[7U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
            >> 6U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[1U] 
                      << 0x1aU));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[8U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[1U] 
            >> 6U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[2U] 
                      << 0x1aU));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[9U] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[2U] 
            >> 6U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                      << 0x1aU));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
            << 7U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                      >> 6U));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
            >> 0x19U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[1U] 
                         << 7U));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[1U] 
            >> 0x19U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[2U] 
                         << 7U));
    vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
        = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[2U] 
            >> 0x19U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[3U] 
                         << 7U));
    vlSelfRef.tlul_socket_m1__DOT__hrequest = (((8U 
                                                 & (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                    >> 9U)) 
                                                | (4U 
                                                   & (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                      >> 0xaU))) 
                                               | ((2U 
                                                   & (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                      >> 0xbU)) 
                                                  | (1U 
                                                     & (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                        >> 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready = 
        (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
         [4U][0U]);
    if ((0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready 
            = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
               [0U][0U]);
    }
    if ((1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready 
            = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
               [1U][0U]);
    }
    if ((2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready 
            = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
               [2U][0U]);
    }
    if ((3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]))) {
        vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready 
            = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_i
               [3U][0U]);
    }
    if (vlSelfRef.tlul_socket_1n__DOT__hold_all_requests) {
        vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready = 0U;
    }
    vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][0U];
    vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][1U];
    vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] = vlSelfRef.tlul_socket_1n__DOT__tl_u_i
        [4U][2U];
    if ((0U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][0U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][1U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0U][2U];
    }
    if ((1U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][0U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][1U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1U][2U];
    }
    if ((2U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][0U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][1U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2U][2U];
    }
    if ((3U == (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding))) {
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][0U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][1U];
        vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] = 
            vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3U][2U];
    }
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp = (
                                                   (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                    >> 1U) 
                                                   & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (0xfffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x1eU))))
                ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x10U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] 
                                 >> 0x10U)) : 0U) << 0x10U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x1eU))))
                ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x10U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U] 
                                 >> 0x10U)) : 0U) >> 0x10U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]);
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req 
        = ((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req))
            ? (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req)
            : (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_req = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                                   & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xeU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req)));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xdU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (2U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (0xfffffffeU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req)))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xbU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (4U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((7U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (8U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[0U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
                                                                            ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                              ? 0U
                                                                              : 
                                                                             (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                               ? 
                                                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                               : 
                                                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                            << 0x3fU) 
                                                           | (((QData)((IData)(
                                                                               ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                               << 0x1fU) 
                                                              | ((QData)((IData)(
                                                                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                 >> 1U)))) 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[1U] = (((IData)(
                                                        (((QData)((IData)(
                                                                          ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                            ? 0U
                                                                            : 
                                                                           (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                             & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                             ? 
                                                                            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                             : 
                                                                            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                          << 0x3fU) 
                                                         | (((QData)((IData)(
                                                                             ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                               ? 0U
                                                                               : 
                                                                              (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                ? 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                : 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                             << 0x1fU) 
                                                            | ((QData)((IData)(
                                                                               ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                               >> 1U)))) 
                                                >> 0x1fU) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                               ? 0U
                                                                               : 
                                                                              (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                ? 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                                : 
                                                                               vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                             << 0x3fU) 
                                                            | (((QData)((IData)(
                                                                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                << 0x1fU) 
                                                               | ((QData)((IData)(
                                                                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                  >> 1U))) 
                                                           >> 0x20U)) 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((2U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
                                                                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                                << 0x3fU) 
                                                               | (((QData)((IData)(
                                                                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                                   << 0x1fU) 
                                                                  | ((QData)((IData)(
                                                                                ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                                 ? 0U
                                                                                 : 
                                                                                (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                                                >> 1U))
                                                                                 ? 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                                                                 : 
                                                                                vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                                     >> 1U))) 
                                                              >> 0x20U)) 
                                                     >> 0x1fU)));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
                                                     << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner 
        = (0xfU & ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                   ^ VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    __Vtableidx1 = vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner;
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__idx_o 
        = Vspi_host_tb__ConstPool__TABLE_h91148bf5_0
        [__Vtableidx1];
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__sv2v_autoblock_3__DOT__i 
        = Vspi_host_tb__ConstPool__TABLE_hce599b47_0
        [__Vtableidx1];
    vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] = 0U;
    vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] = 0U;
    if ((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
                << 0x19U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
                             >> 7U));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
                << 0x19U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
                             >> 7U));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
                << 0x19U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
                             >> 7U));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
            = (0x1fffU & (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
                          >> 7U));
    }
    if ((2U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[7U] 
                << 6U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                          >> 0x1aU));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[8U] 
                << 6U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[7U] 
                          >> 0x1aU));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[9U] 
                << 6U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[8U] 
                          >> 0x1aU));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
            = (0x1fffU & ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
                           << 6U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[9U] 
                                     >> 0x1aU)));
    }
    if ((4U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[4U] 
                << 0x13U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U] 
                             >> 0xdU));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[5U] 
                << 0x13U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[4U] 
                             >> 0xdU));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] 
            = ((vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                << 0x13U) | (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[5U] 
                             >> 0xdU));
        vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
            = (0x1fffU & (vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                          >> 0xdU));
    }
    if ((8U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[0U];
        vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[1U];
        vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[2U];
        vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
            = (0x1fffU & vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o[3U]);
    }
    vlSelfRef.tlul_socket_m1__DOT__hgrant = ((IData)(vlSelfRef.tlul_socket_m1__DOT__arb_ready)
                                              ? (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner)
                                              : 0U);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_78, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp 
                    = ((vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] 
                        << 4U) | (vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
                                  >> 0x1cU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
                                               >> 0x18U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp 
                                        = ((vlSelfRef.tlul_socket_m1__DOT__arb_data[1U] 
                                            << 8U) 
                                           | (vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] 
                                              >> 0x18U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__DOT__arb_data[0U] 
                                                  >> 1U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__Vfuncout) 
                                                                << 1U) 
                                                               | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                                                   & (IData)(
                                                                             ((0x60000U 
                                                                               == 
                                                                               (0x60000U 
                                                                                & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                                              & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                                                  | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                                                      & (IData)(
                                                                                ((0x40000U 
                                                                                == 
                                                                                (0x60000U 
                                                                                & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                                                & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                                                     | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                                                         & (IData)(
                                                                                ((0x20000U 
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
                                                                                & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))))))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_79, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__inp 
                    = (0xffU & ((vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
                                 << 4U) | (vlSelfRef.tlul_socket_m1__DOT__arb_data[2U] 
                                           >> 0x1cU)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout)), __Vtemp_78);
    VL_CONCAT_WIW(102,2,100, __Vtemp_80, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
                             >> 4U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout)), __Vtemp_79);
    VL_CONCAT_WIW(105,3,102, __Vtemp_81, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
                             >> 6U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout)), __Vtemp_80);
    VL_CONCAT_WIW(108,3,105, __Vtemp_82, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__DOT__arb_data[3U] 
                             >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__Vfuncout)), __Vtemp_81);
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U] 
        = __Vtemp_82[0U];
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U] 
        = __Vtemp_82[1U];
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U] 
        = __Vtemp_82[2U];
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest))) 
            << 0xcU) | __Vtemp_82[3U]);
    VL_CONCAT_WQI(66,64,2, __Vtemp_83, (((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__0__KET__)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            ([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__263__inp 
                                        = (7U & ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                    >> 0x1eU)));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__263__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__263__inp;
                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__263__Vfuncout)))) 
                                            << 0x3cU) 
                                           | (((QData)((IData)(
                                                               ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__264__inp 
                                            = (7U & 
                                               (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                >> 0x1bU));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__264__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__264__inp;
                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__264__Vfuncout)))) 
                                               << 0x39U) 
                                              | (((QData)((IData)(
                                                                  ([&]() {
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__265__inp 
                                                = (3U 
                                                   & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                      >> 0x19U));
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__265__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__265__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__265__Vfuncout)))) 
                                                  << 0x37U) 
                                                 | (((QData)((IData)(
                                                                     ([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__266__inp 
                                                    = 
                                                    (0x3fU 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                        >> 0x13U));
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__266__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__266__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__266__Vfuncout)))) 
                                                     << 0x2fU) 
                                                    | (((QData)((IData)(
                                                                        ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__267__inp 
                                                        = 
                                                        (1U 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                            >> 0x10U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__267__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__267__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__267__Vfuncout)))) 
                                                        << 0x2eU) 
                                                       | (((QData)((IData)(
                                                                           ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__268__inp 
                                                            = 
                                                            ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                              << 0x10U) 
                                                             | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                                >> 0x10U));
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__268__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__268__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__268__Vfuncout))) 
                                                           << 0xeU) 
                                                          | (QData)((IData)(
                                                                            ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__269__inp 
                                                        = 
                                                        (0x3fffU 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                            >> 2U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__269__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__269__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__269__Vfuncout))))))))))), 
                  ((2U & vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U]) 
                   | (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__hgrant))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][0U] 
        = __Vtemp_83[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][1U] 
        = __Vtemp_83[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][2U] 
        = __Vtemp_83[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_84, (((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__1__KET__)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            ([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__270__inp 
                                        = (7U & ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                    >> 0x1eU)));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__270__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__270__inp;
                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__270__Vfuncout)))) 
                                            << 0x3cU) 
                                           | (((QData)((IData)(
                                                               ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__271__inp 
                                            = (7U & 
                                               (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                >> 0x1bU));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__271__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__271__inp;
                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__271__Vfuncout)))) 
                                               << 0x39U) 
                                              | (((QData)((IData)(
                                                                  ([&]() {
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__272__inp 
                                                = (3U 
                                                   & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                      >> 0x19U));
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__272__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__272__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__272__Vfuncout)))) 
                                                  << 0x37U) 
                                                 | (((QData)((IData)(
                                                                     ([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__273__inp 
                                                    = 
                                                    (0x3fU 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                        >> 0x13U));
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__273__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__273__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__273__Vfuncout)))) 
                                                     << 0x2fU) 
                                                    | (((QData)((IData)(
                                                                        ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__274__inp 
                                                        = 
                                                        (1U 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                            >> 0x10U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__274__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__274__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__274__Vfuncout)))) 
                                                        << 0x2eU) 
                                                       | (((QData)((IData)(
                                                                           ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__275__inp 
                                                            = 
                                                            ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                              << 0x10U) 
                                                             | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                                >> 0x10U));
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__275__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__275__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__275__Vfuncout))) 
                                                           << 0xeU) 
                                                          | (QData)((IData)(
                                                                            ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__276__inp 
                                                        = 
                                                        (0x3fffU 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                            >> 2U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__276__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__276__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__276__Vfuncout))))))))))), 
                  ((2U & vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U]) 
                   | (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__hgrant) 
                            >> 1U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][2U] 
        = __Vtemp_84[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_85, (((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__2__KET__)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            ([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__277__inp 
                                        = (7U & ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                    >> 0x1eU)));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__277__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__277__inp;
                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__277__Vfuncout)))) 
                                            << 0x3cU) 
                                           | (((QData)((IData)(
                                                               ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__278__inp 
                                            = (7U & 
                                               (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                >> 0x1bU));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__278__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__278__inp;
                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__278__Vfuncout)))) 
                                               << 0x39U) 
                                              | (((QData)((IData)(
                                                                  ([&]() {
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__279__inp 
                                                = (3U 
                                                   & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                      >> 0x19U));
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__279__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__279__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__279__Vfuncout)))) 
                                                  << 0x37U) 
                                                 | (((QData)((IData)(
                                                                     ([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__280__inp 
                                                    = 
                                                    (0x3fU 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                        >> 0x13U));
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__280__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__280__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__280__Vfuncout)))) 
                                                     << 0x2fU) 
                                                    | (((QData)((IData)(
                                                                        ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__281__inp 
                                                        = 
                                                        (1U 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                            >> 0x10U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__281__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__281__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__281__Vfuncout)))) 
                                                        << 0x2eU) 
                                                       | (((QData)((IData)(
                                                                           ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__282__inp 
                                                            = 
                                                            ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                              << 0x10U) 
                                                             | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                                >> 0x10U));
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__282__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__282__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__282__Vfuncout))) 
                                                           << 0xeU) 
                                                          | (QData)((IData)(
                                                                            ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__283__inp 
                                                        = 
                                                        (0x3fffU 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                            >> 2U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__283__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__283__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__283__Vfuncout))))))))))), 
                  ((2U & vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U]) 
                   | (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__hgrant) 
                            >> 2U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][0U] 
        = __Vtemp_85[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][1U] 
        = __Vtemp_85[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][2U] 
        = __Vtemp_85[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_86, (((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__3__KET__)) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            ([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__284__inp 
                                        = (7U & ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[2U] 
                                                  << 2U) 
                                                 | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                    >> 0x1eU)));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__284__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__284__inp;
                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__284__Vfuncout)))) 
                                            << 0x3cU) 
                                           | (((QData)((IData)(
                                                               ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__285__inp 
                                            = (7U & 
                                               (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                >> 0x1bU));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__285__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__285__inp;
                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__285__Vfuncout)))) 
                                               << 0x39U) 
                                              | (((QData)((IData)(
                                                                  ([&]() {
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__286__inp 
                                                = (3U 
                                                   & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                      >> 0x19U));
                                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__286__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__286__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__286__Vfuncout)))) 
                                                  << 0x37U) 
                                                 | (((QData)((IData)(
                                                                     ([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__287__inp 
                                                    = 
                                                    (0x3fU 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                                        >> 0x13U));
                                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__287__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__287__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__287__Vfuncout)))) 
                                                     << 0x2fU) 
                                                    | (((QData)((IData)(
                                                                        ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__288__inp 
                                                        = 
                                                        (1U 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                            >> 0x10U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__288__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__288__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__288__Vfuncout)))) 
                                                        << 0x2eU) 
                                                       | (((QData)((IData)(
                                                                           ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__289__inp 
                                                            = 
                                                            ((vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
                                                              << 0x10U) 
                                                             | (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                                >> 0x10U));
                                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__289__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__289__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__289__Vfuncout))) 
                                                           << 0xeU) 
                                                          | (QData)((IData)(
                                                                            ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__290__inp 
                                                        = 
                                                        (0x3fffU 
                                                         & (vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
                                                            >> 2U));
                                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__290__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__290__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__290__Vfuncout))))))))))), 
                  ((2U & vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U]) 
                   | (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__hgrant) 
                            >> 3U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3U][0U] 
        = __Vtemp_86[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3U][1U] 
        = __Vtemp_86[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3U][2U] 
        = __Vtemp_86[2U];
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_m1__DOT__arb_ready)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
    __Vtemp_96[1U] = ((((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]))
                                  : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]))
                                               : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_96[2U] = ((((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]))
                                  : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]))
                                               : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xfffffffeU 
                                                   & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                          >> 0xcU))
                                                       ? 
                                                      (0xfffffffeU 
                                                       & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U])
                                                       : 
                                                      vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U]))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[1U] = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                 ? 0U
                                                 : 
                                                (1U 
                                                 & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                        >> 0xcU))
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                                                     | (0xfffffffeU 
                                                        & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]))
                                                     : 
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U]))) 
                                               | (__Vtemp_96[1U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[2U] = ((__Vtemp_96[1U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_96[2U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0x1000U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x1fffU 
                                                  & ((__Vtemp_96[2U] 
                                                      >> 0x1fU) 
                                                     | ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                         ? 0U
                                                         : 
                                                        (0xffeU 
                                                         & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                             & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                                >> 0xcU))
                                                             ? 
                                                            ((1U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                                                             | (0xffeU 
                                                                & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]))
                                                             : 
                                                            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U]))))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0xfffU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x1fffU 
                                                  & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
                                                     << 0xcU)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}
