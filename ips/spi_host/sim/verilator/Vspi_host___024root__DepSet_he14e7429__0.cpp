// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host.h for the primary calling header

#include "Vspi_host__pch.h"
#include "Vspi_host__Syms.h"
#include "Vspi_host___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host___024root___dump_triggers__ico(Vspi_host___024root* vlSelf);
#endif  // VL_DEBUG

void Vspi_host___024root___eval_triggers__ico(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_triggers__ico\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vspi_host___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vspi_host___024root___ico_sequent__TOP__0(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___ico_sequent__TOP__1(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___ico_sequent__TOP__2(Vspi_host___024root* vlSelf);

void Vspi_host___024root___eval_ico(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_ico\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vspi_host___024root___ico_sequent__TOP__0(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host___024root___ico_sequent__TOP__1(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host___024root___ico_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vspi_host___024root___ico_sequent__TOP__1(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___ico_sequent__TOP__1\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
    VlWide<14>/*435:0*/ tlul_socket_m1__DOT__hreq_fifo_o;
    VL_ZERO_W(436, tlul_socket_m1__DOT__hreq_fifo_o);
    CData/*3:0*/ tlul_socket_m1__DOT__hgrant;
    tlul_socket_m1__DOT__hgrant = 0;
    VlWide<4>/*108:0*/ tlul_socket_m1__DOT__arb_data;
    VL_ZERO_W(109, tlul_socket_m1__DOT__arb_data);
    CData/*0:0*/ tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o;
    tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o = 0;
    CData/*0:0*/ tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty;
    tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner = 0;
    VlWide<4>/*127:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_37;
    VlWide<4>/*127:0*/ __Vtemp_48;
    VlWide<4>/*127:0*/ __Vtemp_59;
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
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[0U]) 
                                               | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_26[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_26[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_26[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_26[0U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U] = ((__Vtemp_26[0U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_26[1U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U] = ((__Vtemp_26[1U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_26[2U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U] = ((0xfffff000U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[3U]) 
                                               | ((__Vtemp_26[2U] 
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
    __Vtemp_37[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_37[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_37[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_37[0U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[4U] = ((__Vtemp_37[0U] 
                                                >> 0x12U) 
                                               | (__Vtemp_37[1U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[5U] = ((__Vtemp_37[1U] 
                                                >> 0x12U) 
                                               | (__Vtemp_37[2U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[6U] = ((0xfe000000U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[6U]) 
                                               | ((__Vtemp_37[2U] 
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
    __Vtemp_48[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_48[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_48[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_48[0U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[7U] = ((__Vtemp_48[0U] 
                                                >> 5U) 
                                               | (__Vtemp_48[1U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[8U] = ((__Vtemp_48[1U] 
                                                >> 5U) 
                                               | (__Vtemp_48[2U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[9U] = ((__Vtemp_48[2U] 
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
    __Vtemp_59[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_59[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_59[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                 | (__Vtemp_59[0U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xbU] = ((__Vtemp_59[0U] 
                                                  >> 0x18U) 
                                                 | (__Vtemp_59[1U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xcU] = ((__Vtemp_59[1U] 
                                                  >> 0x18U) 
                                                 | (__Vtemp_59[2U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU] = ((0x80000U 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU]) 
                                                 | (0xfffffU 
                                                    & ((__Vtemp_59[2U] 
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
    tlul_socket_m1__DOT__hreq_fifo_o[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U];
    tlul_socket_m1__DOT__hreq_fifo_o[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[1U];
    tlul_socket_m1__DOT__hreq_fifo_o[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[2U];
    tlul_socket_m1__DOT__hreq_fifo_o[3U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             << 0xdU) 
                                            | vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[3U]);
    tlul_socket_m1__DOT__hreq_fifo_o[4U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             >> 0x13U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                               << 0xdU));
    tlul_socket_m1__DOT__hreq_fifo_o[5U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                             >> 0x13U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                               << 0xdU));
    tlul_socket_m1__DOT__hreq_fifo_o[6U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             << 0x1aU) 
                                            | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                                >> 0x13U) 
                                               | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                  << 0xdU)));
    tlul_socket_m1__DOT__hreq_fifo_o[7U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             >> 6U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                               << 0x1aU));
    tlul_socket_m1__DOT__hreq_fifo_o[8U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                             >> 6U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                               << 0x1aU));
    tlul_socket_m1__DOT__hreq_fifo_o[9U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                             >> 6U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                               << 0x1aU));
    tlul_socket_m1__DOT__hreq_fifo_o[0xaU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                               << 7U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                 >> 6U));
    tlul_socket_m1__DOT__hreq_fifo_o[0xbU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                               >> 0x19U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                                 << 7U));
    tlul_socket_m1__DOT__hreq_fifo_o[0xcU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                               >> 0x19U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                                 << 7U));
    tlul_socket_m1__DOT__hreq_fifo_o[0xdU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                               >> 0x19U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[3U] 
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
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest));
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
           | (0xfffeU & tlul_socket_1n__DOT__tl_t_p[0U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x1eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x10U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                 >> 0x10U)) : 0U) << 0x10U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x1eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x10U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                 >> 0x10U)) : 0U) >> 0x10U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & tlul_socket_1n__DOT__tl_t_p[1U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & tlul_socket_1n__DOT__tl_t_p[2U]);
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (tlul_socket_1n__DOT__tl_t_p[2U] >> 1U)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req 
        = ((0U != (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req))
            ? (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req)
            : (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest));
    vlSelfRef.tlul_socket_1n__DOT__accept_t_req = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                                   & (IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xeU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (1U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req)));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xdU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (2U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (0xfffffffeU & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req)))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xbU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (4U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((7U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (8U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
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
                                                            << 0x3fU) 
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
                                                               << 0x1fU) 
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
                                                          << 0x3fU) 
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
                                                             << 0x1fU) 
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
                                                >> 0x1fU) 
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
                                                             << 0x3fU) 
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
                                                                << 0x1fU) 
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
                                                           >> 0x20U)) 
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
                                                                << 0x3fU) 
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
                                                                   << 0x1fU) 
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
                                                              >> 0x20U)) 
                                                     >> 0x1fU)));
    vlSelfRef.tlul_socket_1n__02Etl_h_o[2U] = ((1U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_h_o[2U]) 
                                               | (3U 
                                                  & ((IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
                                                     << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U]));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner 
        = (0xfU & ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                   ^ VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    tlul_socket_m1__DOT__arb_data[0U] = 0U;
    tlul_socket_m1__DOT__arb_data[1U] = 0U;
    tlul_socket_m1__DOT__arb_data[2U] = 0U;
    tlul_socket_m1__DOT__arb_data[3U] = 0U;
    if ((1U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = ((tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
                                              << 0x19U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
                                                >> 7U));
        tlul_socket_m1__DOT__arb_data[1U] = ((tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
                                              << 0x19U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
                                                >> 7U));
        tlul_socket_m1__DOT__arb_data[2U] = ((tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
                                              << 0x19U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
                                                >> 7U));
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & (tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
                                                >> 7U));
    }
    if ((2U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = ((tlul_socket_m1__DOT__hreq_fifo_o[7U] 
                                              << 6U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                                                >> 0x1aU));
        tlul_socket_m1__DOT__arb_data[1U] = ((tlul_socket_m1__DOT__hreq_fifo_o[8U] 
                                              << 6U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[7U] 
                                                >> 0x1aU));
        tlul_socket_m1__DOT__arb_data[2U] = ((tlul_socket_m1__DOT__hreq_fifo_o[9U] 
                                              << 6U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[8U] 
                                                >> 0x1aU));
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & ((tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
                                                 << 6U) 
                                                | (tlul_socket_m1__DOT__hreq_fifo_o[9U] 
                                                   >> 0x1aU)));
    }
    if ((4U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = ((tlul_socket_m1__DOT__hreq_fifo_o[4U] 
                                              << 0x13U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[3U] 
                                                >> 0xdU));
        tlul_socket_m1__DOT__arb_data[1U] = ((tlul_socket_m1__DOT__hreq_fifo_o[5U] 
                                              << 0x13U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[4U] 
                                                >> 0xdU));
        tlul_socket_m1__DOT__arb_data[2U] = ((tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                                              << 0x13U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[5U] 
                                                >> 0xdU));
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & (tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                                                >> 0xdU));
    }
    if ((8U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = tlul_socket_m1__DOT__hreq_fifo_o[0U];
        tlul_socket_m1__DOT__arb_data[1U] = tlul_socket_m1__DOT__hreq_fifo_o[1U];
        tlul_socket_m1__DOT__arb_data[2U] = tlul_socket_m1__DOT__hreq_fifo_o[2U];
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & tlul_socket_m1__DOT__hreq_fifo_o[3U]);
    }
    tlul_socket_m1__DOT__hgrant = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)
                                    ? (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner)
                                    : 0U);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_78, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp 
                    = ((tlul_socket_m1__DOT__arb_data[2U] 
                        << 4U) | (tlul_socket_m1__DOT__arb_data[1U] 
                                  >> 0x1cU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp 
                                    = (0xfU & (tlul_socket_m1__DOT__arb_data[1U] 
                                               >> 0x18U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp 
                                        = ((tlul_socket_m1__DOT__arb_data[1U] 
                                            << 8U) 
                                           | (tlul_socket_m1__DOT__arb_data[0U] 
                                              >> 0x18U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__inp 
                                            = (0x7fffffU 
                                               & (tlul_socket_m1__DOT__arb_data[0U] 
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
                    = (0xffU & ((tlul_socket_m1__DOT__arb_data[3U] 
                                 << 4U) | (tlul_socket_m1__DOT__arb_data[2U] 
                                           >> 0x1cU)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout)), __Vtemp_78);
    VL_CONCAT_WIW(102,2,100, __Vtemp_80, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp 
                    = (3U & (tlul_socket_m1__DOT__arb_data[3U] 
                             >> 4U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout)), __Vtemp_79);
    VL_CONCAT_WIW(105,3,102, __Vtemp_81, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp 
                    = (7U & (tlul_socket_m1__DOT__arb_data[3U] 
                             >> 6U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout)), __Vtemp_80);
    VL_CONCAT_WIW(108,3,105, __Vtemp_82, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__inp 
                    = (7U & (tlul_socket_m1__DOT__arb_data[3U] 
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
    VL_CONCAT_WQI(66,64,2, __Vtemp_83, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & (IData)(tlul_socket_m1__DOT__hgrant))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][0U] 
        = __Vtemp_83[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][1U] 
        = __Vtemp_83[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][2U] 
        = __Vtemp_83[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_84, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0x20000U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & ((IData)(tlul_socket_m1__DOT__hgrant) 
                            >> 1U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][2U] 
        = __Vtemp_84[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_85, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0x40000U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & ((IData)(tlul_socket_m1__DOT__hgrant) 
                            >> 2U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][0U] 
        = __Vtemp_85[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][1U] 
        = __Vtemp_85[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][2U] 
        = __Vtemp_85[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_86, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0x60000U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & ((IData)(tlul_socket_m1__DOT__hgrant) 
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
                        & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]));
    tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
    __Vtemp_96[1U] = ((((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]))
                                  : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]))
                                               : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_96[2U] = ((((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]))
                                  : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    vlSelfRef.tlul_socket_m1__02Etl_d_o[1U] = (((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                     | ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                  & ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
                                                     << 0xcU)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vspi_host___024root___ico_sequent__TOP__2(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___ico_sequent__TOP__2\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[0U]) 
                                               | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[0U] = ((1U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[0U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
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
                                                                 >> 1U)))) 
                                                  << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[1U] = (((IData)(
                                                        (((QData)((IData)(
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
                                                               >> 1U)))) 
                                                >> 0x1fU) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[2U]) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U] = ((0xfffffff9U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[2U]) 
                                               | (0xfffffffeU 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o) 
                                                      << 2U) 
                                                     | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                                                        << 1U))));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[2U] = ((7U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[2U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
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
                                                                 >> 1U)))) 
                                                  << 3U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[3U] = (((IData)(
                                                        (((QData)((IData)(
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
                                                               >> 1U)))) 
                                                >> 0x1dU) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
                                                  << 3U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[4U] = ((0xfffffff8U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[4U]) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
                                                  >> 0x1dU));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[4U] = ((0xffffffe7U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[4U]) 
                                               | (0xfffffff8U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o) 
                                                      << 4U) 
                                                     | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                                                        << 3U))));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[4U] = ((0x1fU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[4U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
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
                                                                 >> 1U)))) 
                                                  << 5U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[5U] = (((IData)(
                                                        (((QData)((IData)(
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
                                                               >> 1U)))) 
                                                >> 0x1bU) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
                                                  << 5U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[6U] = ((0xffffffe0U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[6U]) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
                                                  >> 0x1bU));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[6U] = ((0xffffff9fU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[6U]) 
                                               | (0xffffffe0U 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o) 
                                                      << 6U) 
                                                     | ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                                                        << 5U))));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[6U] = ((0x7fU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[6U]) 
                                               | ((IData)(
                                                          (((QData)((IData)(
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
                                                                 >> 1U)))) 
                                                  << 7U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[7U] = (((IData)(
                                                        (((QData)((IData)(
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
                                                               >> 1U)))) 
                                                >> 0x19U) 
                                               | ((IData)(
                                                          ((((QData)((IData)(
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
                                                  << 7U));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[8U] = ((0x80U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[8U]) 
                                               | (0xffU 
                                                  & ((IData)(
                                                             ((((QData)((IData)(
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
                                                     >> 0x19U)));
    vlSelfRef.tlul_socket_m1__02Etl_h_o[8U] = ((0x7fU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_h_o[8U]) 
                                               | (0xffU 
                                                  & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                                                     << 7U)));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host___024root___dump_triggers__act(Vspi_host___024root* vlSelf);
#endif  // VL_DEBUG

void Vspi_host___024root___eval_triggers__act(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_triggers__act\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_wr_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_wr_ni__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_rd_i__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_rd_ni__0)));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_wr_i__0))));
    vlSelfRef.__VactTriggered.setBit(5U, ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_wr_ni__0)));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_rd_i__0))));
    vlSelfRef.__VactTriggered.setBit(7U, ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_rd_ni__0)));
    vlSelfRef.__VactTriggered.setBit(8U, ((IData)(vlSelfRef.prim_filter__02Eclk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(9U, ((~ (IData)(vlSelfRef.prim_filter__02Erst_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter__02Erst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0xaU, ((IData)(vlSelfRef.prim_filter_ctr__02Eclk_i) 
                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter_ctr__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0xbU, ((~ (IData)(vlSelfRef.prim_filter_ctr__02Erst_ni)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__prim_filter_ctr__02Erst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0xcU, ((IData)(vlSelfRef.tlul_adapter_host__02Eclk_i) 
                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0xdU, ((~ (IData)(vlSelfRef.tlul_adapter_host__02Erst_ni)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_host__02Erst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0xeU, ((IData)(vlSelfRef.tlul_adapter_sram__02Eclk_i) 
                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0xfU, ((~ (IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni)) 
                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_adapter_sram__02Erst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0x10U, ((IData)(vlSelfRef.clk_h_i) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_h_i__0))));
    vlSelfRef.__VactTriggered.setBit(0x11U, ((~ (IData)(vlSelfRef.rst_h_ni)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_h_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0x12U, ((IData)(vlSelfRef.clk_d_i) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_d_i__0))));
    vlSelfRef.__VactTriggered.setBit(0x13U, ((~ (IData)(vlSelfRef.rst_d_ni)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_d_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0x14U, ((IData)(vlSelfRef.tlul_socket_1n__02Eclk_i) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_1n__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0x15U, ((~ (IData)(vlSelfRef.tlul_socket_1n__02Erst_ni)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_1n__02Erst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0x16U, ((IData)(vlSelfRef.tlul_socket_m1__02Eclk_i) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_m1__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0x17U, ((~ (IData)(vlSelfRef.tlul_socket_m1__02Erst_ni)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tlul_socket_m1__02Erst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(0x18U, ((IData)(vlSelfRef.spi_host__02Eclk_i) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__spi_host__02Eclk_i__0))));
    vlSelfRef.__VactTriggered.setBit(0x19U, ((~ (IData)(vlSelfRef.spi_host__02Erst_ni)) 
                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__spi_host__02Erst_ni__0)));
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
    vlSelfRef.__Vtrigprevexpr___TOP__spi_host__02Eclk_i__0 
        = vlSelfRef.spi_host__02Eclk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__spi_host__02Erst_ni__0 
        = vlSelfRef.spi_host__02Erst_ni;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vspi_host___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vspi_host___024root___nba_sequent__TOP__0(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__1(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__2(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__3(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__4(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__5(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__6(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__7(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__8(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__9(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__10(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__11(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__12(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__13(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__14(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__15(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__16(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__17(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__18(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__19(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__20(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_comb__TOP__0(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_comb__TOP__1(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_comb__TOP__2(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__21(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_comb__TOP__3(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__22(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__2(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__23(Vspi_host___024root* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vspi_host_tlul_fifo_sync__RCz6_RDz6* vlSelf);
void Vspi_host___024root___nba_comb__TOP__4(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__24(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__25(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_sequent__TOP__26(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_comb__TOP__6(Vspi_host___024root* vlSelf);
void Vspi_host___024root___nba_comb__TOP__7(Vspi_host___024root* vlSelf);

void Vspi_host___024root___eval_nba(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_nba\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xc0ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x10000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x40000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x3000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0xc000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x300000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vspi_host___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0xc00000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__6(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x300ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0xc00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((0x100000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__11(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__1((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
    }
    if ((0x30000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0xc0000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__13(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__14(vlSelf);
    }
    if ((0x400000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x3000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__16(vlSelf);
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__17(vlSelf);
    }
    if ((0x1000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x4000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((0x300000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__20(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__2((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vspi_host___024root___nba_comb__TOP__0(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0((&vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d));
        Vspi_host___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x70000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((0x30000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__21(vlSelf);
    }
    if ((0xd0000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__22(vlSelf);
    }
    if ((0xc00000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__2((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host___024root___nba_sequent__TOP__23(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___nba_comb__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host___024root___nba_comb__TOP__4(vlSelf);
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo));
        Vspi_host_tlul_fifo_sync__RCz6_RDz6___ico_sequent__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__1((&vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo));
        Vspi_host___024root___ico_sequent__TOP__2(vlSelf);
    }
    if ((0xc0ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__24(vlSelf);
    }
    if ((0x3000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__25(vlSelf);
    }
    if ((0xc000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_sequent__TOP__26(vlSelf);
        Vspi_host___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x3000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vspi_host___024root___nba_comb__TOP__7(vlSelf);
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__0(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*108:0*/ tlul_socket_1n__DOT__tl_t_o;
    VL_ZERO_W(109, tlul_socket_1n__DOT__tl_t_o);
    IData/*22:0*/ tlul_socket_1n__DOT__blanked_auser;
    tlul_socket_1n__DOT__blanked_auser = 0;
    VlWide<3>/*65:0*/ tlul_socket_1n__DOT__tl_t_p;
    VL_ZERO_W(66, tlul_socket_1n__DOT__tl_t_p);
    CData/*0:0*/ tlul_socket_1n__DOT__hfifo_reqready;
    tlul_socket_1n__DOT__hfifo_reqready = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i;
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o;
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty;
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty = 0;
    QData/*56:0*/ __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload;
    __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload = 0;
    // Body
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   >> 0xcU))) {
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
    vlSelfRef.tlul_socket_1n__DOT__hold_all_requests 
        = ((0U != (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)) 
           & ((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]) 
              != (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding)));
    tlul_socket_1n__DOT__tl_t_o[0U] = (((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                         << 0x1eU) 
                                        | (0x3ffffffeU 
                                           & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                              >> 2U))) 
                                       | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    tlul_socket_1n__DOT__tl_t_o[1U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                              >> 2U)) 
                                       | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                           << 0x1eU) 
                                          | (0x3ffffffeU 
                                             & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                >> 2U))));
    tlul_socket_1n__DOT__tl_t_o[2U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                              >> 2U)) 
                                       | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                           << 0x1eU) 
                                          | (0x3ffffffeU 
                                             & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                >> 2U))));
    tlul_socket_1n__DOT__tl_t_o[3U] = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                        << 0xcU) | 
                                       ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                               >> 2U)) 
                                        | (0xffeU & 
                                           (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                            >> 2U))));
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
    tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select 
        = ((0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select 
        = ((1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select 
        = ((2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select 
        = ((3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (0xff000000U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xffffffU & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (0xfffffeU & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x1000U & ((tlul_socket_1n__DOT__tl_t_o[3U] 
                                   & ((4U <= (7U & 
                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
                                      << 0xcU)) & (
                                                   (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
                                                   << 0xcU))));
    tlul_socket_1n__DOT__blanked_auser = ((([&]() {
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp 
                        = (0x1fU & (tlul_socket_1n__DOT__tl_t_o[0U] 
                                    >> 0x13U));
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout)) 
                                           << 0x12U) 
                                          | ((([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp 
                            = (0xfU & (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0xfU));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout)) 
                                              << 0xeU) 
                                             | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[0U] 
                                = tlul_socket_1n__DOT__tl_t_o[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[1U] 
                                = tlul_socket_1n__DOT__tl_t_o[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[2U] 
                                = tlul_socket_1n__DOT__tl_t_o[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[3U] 
                                = tlul_socket_1n__DOT__tl_t_o[3U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[0U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[1U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[2U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[3U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[3U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[0U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[1U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[2U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[3U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[3U];
                            vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload = VL_RAND_RESET_Q(43);
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload 
                                = ((0x78000000000ULL 
                                    & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload) 
                                   | (((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[2U] 
                                                         << 4U) 
                                                        | (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[1U] 
                                                           >> 0x1cU)))) 
                                       << 7U) | (QData)((IData)(
                                                                ((0x70U 
                                                                  & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[3U] 
                                                                     >> 5U)) 
                                                                 | (0xfU 
                                                                    & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[1U] 
                                                                       >> 0x18U)))))));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload 
                                = ((0x7fffffffffULL 
                                    & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload) 
                                   | ((QData)((IData)(
                                                      (0xfU 
                                                       & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[0U] 
                                                          >> 0xfU)))) 
                                      << 0x27U));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd_intg 
                                = (0x7fU & (IData)(
                                                   (([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__inp 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__inp;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_i 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__Vfuncout;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__inp 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_i;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__inp;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__Vfuncout;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xfdffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x39U));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xfbffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x17c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3aU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xf7ffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3bU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xefffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3cU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xdfffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3dU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xbfffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3eU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0x7fffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3fU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    (0x5400000000000000ULL 
                                                     ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o);
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o;
                                            }(), vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__Vfuncout) 
                                                    >> 0x39U)));
                            __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload 
                                = (0x1ffffffffffffffULL 
                                   & ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__inp 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__inp;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_i 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__Vfuncout;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__inp 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_i;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__inp;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__Vfuncout;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xfdffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x39U));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xfbffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x17c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3aU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xf7ffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3bU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xefffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3cU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xdfffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3dU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xbfffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3eU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0x7fffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3fU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = (0x5400000000000000ULL 
                                               ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o);
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__Vfuncout));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd_intg;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__cmd_intg 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__Vfuncout 
                                = (0x7fU & (~ (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__cmd_intg)));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__inp 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__Vfuncout)) 
                                                 << 7U) 
                                                | ([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o = 0xffffffffULL;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = (0x7effffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o);
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x7dffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0xdeba8050ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x21U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x7bffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x413d89aaULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x22U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x77ffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x31234ed1ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x23U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x6fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0xc2c1323bULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x24U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x5fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x2dcc624cULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x25U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x3fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x98505586ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x26U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = (0x2a00000000ULL ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o);
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__enc_data 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__data_intg 
                            = (0x7fU & (IData)((vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__enc_data 
                                                >> 0x20U)));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__data_intg;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__data_intg 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__Vfuncout 
                            = (0x7fU & (~ (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__data_intg)));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__inp 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__Vfuncout)))));
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
           | (0xfffeU & tlul_socket_1n__DOT__tl_t_p[0U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x1eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x10U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                 >> 0x10U)) : 0U) << 0x10U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((tlul_socket_1n__DOT__tl_t_p[2U] 
                              << 2U) | (tlul_socket_1n__DOT__tl_t_p[1U] 
                                        >> 0x1eU))))
                ? ((tlul_socket_1n__DOT__tl_t_p[1U] 
                    << 0x10U) | (tlul_socket_1n__DOT__tl_t_p[0U] 
                                 >> 0x10U)) : 0U) >> 0x10U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffffU & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & tlul_socket_1n__DOT__tl_t_p[1U]));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & tlul_socket_1n__DOT__tl_t_p[2U]);
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (tlul_socket_1n__DOT__tl_t_p[2U] >> 1U)) 
           & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
           & (IData)(tlul_socket_1n__DOT__hfifo_reqready));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
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
                                                            << 0x3fU) 
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
                                                               << 0x1fU) 
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
                                                          << 0x3fU) 
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
                                                             << 0x1fU) 
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
                                                >> 0x1fU) 
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
                                                             << 0x3fU) 
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
                                                                << 0x1fU) 
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
                                                           >> 0x20U)) 
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
                                                                << 0x3fU) 
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
                                                                   << 0x1fU) 
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
                                                              >> 0x20U)) 
                                                     >> 0x1fU)));
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
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__1(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__1\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_32;
    VlWide<4>/*127:0*/ __Vtemp_43;
    // Body
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[0U]) 
                                               | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_10[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_10[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_10[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_10[0U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[1U] = ((__Vtemp_10[0U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_10[1U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[2U] = ((__Vtemp_10[1U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_10[2U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[3U] = ((0xfffff000U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[3U]) 
                                               | ((__Vtemp_10[2U] 
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
    __Vtemp_21[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_21[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_21[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_21[0U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[4U] = ((__Vtemp_21[0U] 
                                                >> 0x12U) 
                                               | (__Vtemp_21[1U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[5U] = ((__Vtemp_21[1U] 
                                                >> 0x12U) 
                                               | (__Vtemp_21[2U] 
                                                  << 0xeU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[6U] = ((0xfe000000U 
                                                & vlSelfRef.tlul_socket_1n__02Etl_d_o[6U]) 
                                               | ((__Vtemp_21[2U] 
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
    __Vtemp_32[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_32[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_32[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_32[0U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[7U] = ((__Vtemp_32[0U] 
                                                >> 5U) 
                                               | (__Vtemp_32[1U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[8U] = ((__Vtemp_32[1U] 
                                                >> 5U) 
                                               | (__Vtemp_32[2U] 
                                                  << 0x1bU));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[9U] = ((__Vtemp_32[2U] 
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
    __Vtemp_43[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_43[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    __Vtemp_43[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                 | (__Vtemp_43[0U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xbU] = ((__Vtemp_43[0U] 
                                                  >> 0x18U) 
                                                 | (__Vtemp_43[1U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xcU] = ((__Vtemp_43[1U] 
                                                  >> 0x18U) 
                                                 | (__Vtemp_43[2U] 
                                                    << 8U));
    vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU] = ((0x80000U 
                                                  & vlSelfRef.tlul_socket_1n__02Etl_d_o[0xdU]) 
                                                 | (0xfffffU 
                                                    & ((__Vtemp_43[2U] 
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
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__4(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__4\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<14>/*435:0*/ tlul_socket_m1__DOT__hreq_fifo_o;
    VL_ZERO_W(436, tlul_socket_m1__DOT__hreq_fifo_o);
    CData/*3:0*/ tlul_socket_m1__DOT__hgrant;
    tlul_socket_m1__DOT__hgrant = 0;
    VlWide<4>/*108:0*/ tlul_socket_m1__DOT__arb_data;
    VL_ZERO_W(109, tlul_socket_m1__DOT__arb_data);
    CData/*0:0*/ tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o;
    tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o = 0;
    CData/*0:0*/ tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty;
    tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req = 0;
    CData/*3:0*/ tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner;
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner = 0;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_36;
    // Body
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
    tlul_socket_m1__DOT__hreq_fifo_o[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U];
    tlul_socket_m1__DOT__hreq_fifo_o[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[1U];
    tlul_socket_m1__DOT__hreq_fifo_o[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[2U];
    tlul_socket_m1__DOT__hreq_fifo_o[3U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             << 0xdU) 
                                            | vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[3U]);
    tlul_socket_m1__DOT__hreq_fifo_o[4U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             >> 0x13U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                               << 0xdU));
    tlul_socket_m1__DOT__hreq_fifo_o[5U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                             >> 0x13U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                               << 0xdU));
    tlul_socket_m1__DOT__hreq_fifo_o[6U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             << 0x1aU) 
                                            | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                                >> 0x13U) 
                                               | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                  << 0xdU)));
    tlul_socket_m1__DOT__hreq_fifo_o[7U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             >> 6U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                               << 0x1aU));
    tlul_socket_m1__DOT__hreq_fifo_o[8U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                             >> 6U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                               << 0x1aU));
    tlul_socket_m1__DOT__hreq_fifo_o[9U] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                             >> 6U) 
                                            | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                               << 0x1aU));
    tlul_socket_m1__DOT__hreq_fifo_o[0xaU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                               << 7U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[3U] 
                                                 >> 6U));
    tlul_socket_m1__DOT__hreq_fifo_o[0xbU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                               >> 0x19U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                                 << 7U));
    tlul_socket_m1__DOT__hreq_fifo_o[0xcU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[1U] 
                                               >> 0x19U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                                 << 7U));
    tlul_socket_m1__DOT__hreq_fifo_o[0xdU] = ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[2U] 
                                               >> 0x19U) 
                                              | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[3U] 
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
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
        = (((IData)((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U)))) 
            << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
        = (((IData)((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U)))) 
            >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                    >> 1U))) 
                                  >> 0x20U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[2U] 
        = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
            << 1U) | ((IData)(((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                                 << 0x3fU) | (((QData)((IData)(
                                                               vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                               << 0x1fU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U))) 
                               >> 0x20U)) >> 0x1fU));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask) 
           & (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req 
        = ((0U != (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req))
            ? (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req)
            : (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xeU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (1U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req)));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xdU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (2U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (0xfffffffeU & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req)))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((0xbU & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (4U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out 
        = ((7U & (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out)) 
           | (8U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                     << 1U) | (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req))));
    tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner 
        = (0xfU & ((IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out) 
                   ^ VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U)));
    tlul_socket_m1__DOT__arb_data[0U] = 0U;
    tlul_socket_m1__DOT__arb_data[1U] = 0U;
    tlul_socket_m1__DOT__arb_data[2U] = 0U;
    tlul_socket_m1__DOT__arb_data[3U] = 0U;
    if ((1U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = ((tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
                                              << 0x19U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
                                                >> 7U));
        tlul_socket_m1__DOT__arb_data[1U] = ((tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
                                              << 0x19U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[0xbU] 
                                                >> 7U));
        tlul_socket_m1__DOT__arb_data[2U] = ((tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
                                              << 0x19U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[0xcU] 
                                                >> 7U));
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & (tlul_socket_m1__DOT__hreq_fifo_o[0xdU] 
                                                >> 7U));
    }
    if ((2U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = ((tlul_socket_m1__DOT__hreq_fifo_o[7U] 
                                              << 6U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                                                >> 0x1aU));
        tlul_socket_m1__DOT__arb_data[1U] = ((tlul_socket_m1__DOT__hreq_fifo_o[8U] 
                                              << 6U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[7U] 
                                                >> 0x1aU));
        tlul_socket_m1__DOT__arb_data[2U] = ((tlul_socket_m1__DOT__hreq_fifo_o[9U] 
                                              << 6U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[8U] 
                                                >> 0x1aU));
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & ((tlul_socket_m1__DOT__hreq_fifo_o[0xaU] 
                                                 << 6U) 
                                                | (tlul_socket_m1__DOT__hreq_fifo_o[9U] 
                                                   >> 0x1aU)));
    }
    if ((4U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = ((tlul_socket_m1__DOT__hreq_fifo_o[4U] 
                                              << 0x13U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[3U] 
                                                >> 0xdU));
        tlul_socket_m1__DOT__arb_data[1U] = ((tlul_socket_m1__DOT__hreq_fifo_o[5U] 
                                              << 0x13U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[4U] 
                                                >> 0xdU));
        tlul_socket_m1__DOT__arb_data[2U] = ((tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                                              << 0x13U) 
                                             | (tlul_socket_m1__DOT__hreq_fifo_o[5U] 
                                                >> 0xdU));
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & (tlul_socket_m1__DOT__hreq_fifo_o[6U] 
                                                >> 0xdU));
    }
    if ((8U & (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner))) {
        tlul_socket_m1__DOT__arb_data[0U] = tlul_socket_m1__DOT__hreq_fifo_o[0U];
        tlul_socket_m1__DOT__arb_data[1U] = tlul_socket_m1__DOT__hreq_fifo_o[1U];
        tlul_socket_m1__DOT__arb_data[2U] = tlul_socket_m1__DOT__hreq_fifo_o[2U];
        tlul_socket_m1__DOT__arb_data[3U] = (0x1fffU 
                                             & tlul_socket_m1__DOT__hreq_fifo_o[3U]);
    }
    tlul_socket_m1__DOT__hgrant = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)
                                    ? (IData)(tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner)
                                    : 0U);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_18, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp 
                    = ((tlul_socket_m1__DOT__arb_data[2U] 
                        << 4U) | (tlul_socket_m1__DOT__arb_data[1U] 
                                  >> 0x1cU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp 
                                    = (0xfU & (tlul_socket_m1__DOT__arb_data[1U] 
                                               >> 0x18U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp 
                                        = ((tlul_socket_m1__DOT__arb_data[1U] 
                                            << 8U) 
                                           | (tlul_socket_m1__DOT__arb_data[0U] 
                                              >> 0x18U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__inp 
                                            = (0x7fffffU 
                                               & (tlul_socket_m1__DOT__arb_data[0U] 
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
    VL_CONCAT_WIW(100,8,92, __Vtemp_19, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__inp 
                    = (0xffU & ((tlul_socket_m1__DOT__arb_data[3U] 
                                 << 4U) | (tlul_socket_m1__DOT__arb_data[2U] 
                                           >> 0x1cU)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout)), __Vtemp_18);
    VL_CONCAT_WIW(102,2,100, __Vtemp_20, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp 
                    = (3U & (tlul_socket_m1__DOT__arb_data[3U] 
                             >> 4U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout)), __Vtemp_19);
    VL_CONCAT_WIW(105,3,102, __Vtemp_21, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp 
                    = (7U & (tlul_socket_m1__DOT__arb_data[3U] 
                             >> 6U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout)), __Vtemp_20);
    VL_CONCAT_WIW(108,3,105, __Vtemp_22, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__inp 
                    = (7U & (tlul_socket_m1__DOT__arb_data[3U] 
                             >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__Vfuncout)), __Vtemp_21);
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U] 
        = __Vtemp_22[0U];
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U] 
        = __Vtemp_22[1U];
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U] 
        = __Vtemp_22[2U];
    vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest))) 
            << 0xcU) | __Vtemp_22[3U]);
    VL_CONCAT_WQI(66,64,2, __Vtemp_23, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & (IData)(tlul_socket_m1__DOT__hgrant))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][0U] 
        = __Vtemp_23[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][1U] 
        = __Vtemp_23[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0U][2U] 
        = __Vtemp_23[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_24, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0x20000U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & ((IData)(tlul_socket_m1__DOT__hgrant) 
                            >> 1U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1U][2U] 
        = __Vtemp_24[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_25, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0x40000U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & ((IData)(tlul_socket_m1__DOT__hgrant) 
                            >> 2U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][0U] 
        = __Vtemp_25[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][1U] 
        = __Vtemp_25[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2U][2U] 
        = __Vtemp_25[2U];
    VL_CONCAT_WQI(66,64,2, __Vtemp_26, (((QData)((IData)(
                                                         ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
                                                          & (0x60000U 
                                                             == 
                                                             (0x60000U 
                                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U]))))) 
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
                   | (1U & ((IData)(tlul_socket_m1__DOT__hgrant) 
                            >> 3U))));
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3U][0U] 
        = __Vtemp_26[0U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3U][1U] 
        = __Vtemp_26[1U];
    vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3U][2U] 
        = __Vtemp_26[2U];
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]));
    tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[0U] = ((0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[0U]) 
                                               | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
    __Vtemp_36[1U] = ((((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]))
                                  : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]))
                                               : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_36[2U] = ((((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                     >> 0xcU)) ? ((1U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                                                  | (0xffeU 
                                                     & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]))
                                  : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
    vlSelfRef.tlul_socket_m1__02Etl_d_o[1U] = (((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                               | (__Vtemp_36[1U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[2U] = ((__Vtemp_36[1U] 
                                                >> 0x1fU) 
                                               | (__Vtemp_36[2U] 
                                                  << 1U));
    vlSelfRef.tlul_socket_m1__02Etl_d_o[3U] = ((0x1000U 
                                                & vlSelfRef.tlul_socket_m1__02Etl_d_o[3U]) 
                                               | (0x1fffU 
                                                  & ((__Vtemp_36[2U] 
                                                      >> 0x1fU) 
                                                     | ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
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
                                                  & ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
                                                     << 0xcU)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o) 
           & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}
