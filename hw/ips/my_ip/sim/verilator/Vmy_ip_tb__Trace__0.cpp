// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vmy_ip_tb__Syms.h"


void Vmy_ip_tb___024root__trace_chg_0_sub_0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmy_ip_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_chg_0\n"); );
    // Body
    Vmy_ip_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_ip_tb___024root*>(voidSelf);
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vmy_ip_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vmy_ip_tb___024root__trace_chg_0_sub_0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_chg_0_sub_0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__my_ip_tb.__PVT__rst_ni));
        bufp->chgBit(oldp+1,((1U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                    >> 0x0000000cU))));
        bufp->chgCData(oldp+2,((7U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                      >> 9U))),3);
        bufp->chgCData(oldp+3,((7U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                      >> 6U))),3);
        bufp->chgCData(oldp+4,((3U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                      >> 4U))),2);
        bufp->chgCData(oldp+5,((0x000000ffU & ((vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                                << 4U) 
                                               | (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[2U] 
                                                  >> 0x0000001cU)))),8);
        bufp->chgIData(oldp+6,(((vlSymsp->TOP__my_ip_tb.__PVT__tl_i[2U] 
                                 << 4U) | (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[1U] 
                                           >> 0x0000001cU))),32);
        bufp->chgCData(oldp+7,((0x0000000fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[1U] 
                                               >> 0x00000018U))),4);
        bufp->chgIData(oldp+8,(((vlSymsp->TOP__my_ip_tb.__PVT__tl_i[1U] 
                                 << 8U) | (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                           >> 0x00000018U))),32);
        bufp->chgCData(oldp+9,((0x0000001fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                               >> 0x00000013U))),5);
        bufp->chgCData(oldp+10,((0x0000000fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                                >> 0x0000000fU))),4);
        bufp->chgCData(oldp+11,((0x0000007fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                                >> 8U))),7);
        bufp->chgCData(oldp+12,((0x0000007fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                                >> 1U))),7);
        bufp->chgBit(oldp+13,((1U & vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U])));
        bufp->chgBit(oldp+14,(vlSymsp->TOP__my_ip_tb.__PVT__port_i));
        bufp->chgIData(oldp+15,(vlSymsp->TOP__my_ip_tb.__PVT__error_count),32);
        bufp->chgIData(oldp+16,(vlSymsp->TOP__my_ip_tb.__PVT__rdata),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U])))) {
        bufp->chgCData(oldp+17,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit),4);
        bufp->chgBit(oldp+18,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__instr_error));
        bufp->chgBit(oldp+19,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__malformed_meta_err));
        bufp->chgBit(oldp+20,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
        bufp->chgBit(oldp+21,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
        bufp->chgBit(oldp+22,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
        bufp->chgBit(oldp+23,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
        bufp->chgBit(oldp+24,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgBit(oldp+25,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o));
        bufp->chgBit(oldp+26,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o));
        bufp->chgIData(oldp+27,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next),32);
        bufp->chgBit(oldp+28,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i));
        bufp->chgBit(oldp+29,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we));
        bufp->chgBit(oldp+30,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack));
        bufp->chgBit(oldp+32,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal));
        bufp->chgBit(oldp+33,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req));
        bufp->chgBit(oldp+34,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+35,(vlSymsp->TOP__my_ip_tb.__PVT__port_o));
        bufp->chgBit(oldp+36,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q));
        bufp->chgCData(oldp+37,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q),3);
        bufp->chgCData(oldp+38,((7U & (IData)(((0x000000000000001fULL 
                                                & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                   >> 2U)) 
                                               | ((0x000000000000001fULL 
                                                   & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                      >> 0x0000000aU)) 
                                                  | ((0x000000000000001fULL 
                                                      & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                         >> 0x0000002bU)) 
                                                     | ((QData)((IData)(
                                                                        (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                          << 1U) 
                                                                         | (1U 
                                                                            & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                        >> 0x0000003bU))))))),3);
        bufp->chgCData(oldp+39,((3U & (IData)(((0x000000000000007fULL 
                                                & (QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q))) 
                                               | ((0x000000000000007fULL 
                                                   & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                      >> 8U)) 
                                                  | ((0x000000000000007fULL 
                                                      & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                         >> 0x00000029U)) 
                                                     | ((QData)((IData)(
                                                                        (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                          << 1U) 
                                                                         | (1U 
                                                                            & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                        >> 0x00000039U))))))),2);
        bufp->chgCData(oldp+40,((0x000000ffU & (IData)(
                                                       ((0x0000000000007f00ULL 
                                                         & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                            << 8U)) 
                                                        | ((0x0000000000007fffULL 
                                                            & (QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q))) 
                                                           | ((0x0000000000007fffULL 
                                                               & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                                  >> 0x00000021U)) 
                                                              | ((QData)((IData)(
                                                                                (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                                 >> 0x00000031U))))))),8);
        bufp->chgBit(oldp+41,((1U & (IData)(((0x000000000000fe00ULL 
                                              & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                 << 9U)) 
                                             | ((0x000000000000fffeULL 
                                                 & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                    << 1U)) 
                                                | ((0x000000000000ffffULL 
                                                    & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                       >> 0x00000020U)) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                        << 1U) 
                                                                       | (1U 
                                                                          & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                      >> 0x00000030U))))))));
        bufp->chgIData(oldp+42,((IData)(((0x0000fe0000000000ULL 
                                          & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                             << 0x00000029U)) 
                                         | ((0x0000fffe00000000ULL 
                                             & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                << 0x00000021U)) 
                                            | ((0x0000ffffffffffffULL 
                                                & (QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q))) 
                                               | ((QData)((IData)(
                                                                  (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                    << 1U) 
                                                                   | (1U 
                                                                      & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                  >> 0x00000010U)))))),32);
        bufp->chgCData(oldp+43,((0x0000007fU & (IData)(
                                                       ((0x007f000000000000ULL 
                                                         & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                            << 0x00000030U)) 
                                                        | ((0x007fff0000000000ULL 
                                                            & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                               << 0x00000028U)) 
                                                           | ((0x007fffffffffff80ULL 
                                                               & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                                  << 7U)) 
                                                              | ((QData)((IData)(
                                                                                (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                                 >> 9U))))))),7);
        bufp->chgCData(oldp+44,((0x0000007fU & (IData)(
                                                       ((0x3f80000000000000ULL 
                                                         & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                            << 0x00000037U)) 
                                                        | ((0x3fff800000000000ULL 
                                                            & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                               << 0x0000002fU)) 
                                                           | ((0x3fffffffffffc000ULL 
                                                               & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                                  << 0x0000000eU)) 
                                                              | ((QData)((IData)(
                                                                                (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                                 >> 2U))))))),7);
        bufp->chgBit(oldp+45,((1U & (IData)(((0x7f00000000000000ULL 
                                              & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                 << 0x00000038U)) 
                                             | ((0x7fff000000000000ULL 
                                                 & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                    << 0x00000030U)) 
                                                | ((0x7fffffffffff8000ULL 
                                                    & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                       << 0x0000000fU)) 
                                                   | ((QData)((IData)(
                                                                      (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                        << 1U) 
                                                                       | (1U 
                                                                          & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                      >> 1U))))))));
        bufp->chgBit(oldp+46,((1U & (IData)((((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                              << 0x00000039U) 
                                             | (((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                 << 0x00000031U) 
                                                | (((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                    << 0x00000010U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                       << 1U) 
                                                                      | (1U 
                                                                         & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))))))))));
        bufp->chgSData(oldp+47,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q),16);
        bufp->chgBit(oldp+48,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q));
        bufp->chgBit(oldp+49,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q));
        bufp->chgBit(oldp+50,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q));
        bufp->chgBit(oldp+51,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q));
        bufp->chgCData(oldp+52,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q),8);
        bufp->chgBit(oldp+53,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe));
        bufp->chgBit(oldp+54,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq));
        bufp->chgIData(oldp+55,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q),32);
        bufp->chgBit(oldp+56,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q));
        bufp->chgCData(oldp+57,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q),8);
        bufp->chgCData(oldp+58,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q),2);
        bufp->chgCData(oldp+59,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q),3);
        bufp->chgBit(oldp+60,((1U & (~ ((((VL_REDXOR_4(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q) 
                                           ^ VL_REDXOR_2(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                          ^ VL_REDXOR_8(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                         ^ VL_REDXOR_32(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                        ^ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q))))));
    }
    bufp->chgBit(oldp+61,(vlSymsp->TOP__my_ip_tb.__PVT__clk_i));
    bufp->chgBit(oldp+62,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                 >> 0x0000000cU))));
    bufp->chgCData(oldp+63,((7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                   >> 9U))),3);
    bufp->chgCData(oldp+64,((7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                   >> 6U))),3);
    bufp->chgCData(oldp+65,((3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                   >> 4U))),2);
    bufp->chgCData(oldp+66,((0x000000ffU & ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                             << 4U) 
                                            | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+67,(((vlSymsp->TOP__my_ip_tb__tl_if.h2d[2U] 
                              << 4U) | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                        >> 0x0000001cU))),32);
    bufp->chgCData(oldp+68,((0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgIData(oldp+69,(((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                              << 8U) | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+70,((0x0000001fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                            >> 0x00000013U))),5);
    bufp->chgCData(oldp+71,((0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                            >> 0x0000000fU))),4);
    bufp->chgCData(oldp+72,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                            >> 8U))),7);
    bufp->chgCData(oldp+73,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                            >> 1U))),7);
    bufp->chgBit(oldp+74,((1U & vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U])));
    bufp->chgBit(oldp+75,((1U & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                 >> 0x00000015U))));
    bufp->chgBit(oldp+76,((1U & ((0x00000fffU & ((1U 
                                                  == 
                                                  (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 0x0000001eU)) 
                                                 & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                    & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))) 
                                 | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                    >> 0x00000014U)))));
    bufp->chgBit(oldp+77,((1U & ((0x00001ffeU & (((1U 
                                                   == 
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001eU)) 
                                                  & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                     & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                 << 1U)) 
                                 | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                    >> 0x00000013U)))));
    bufp->chgBit(oldp+78,((1U & ((0x00003ffcU & (((1U 
                                                   == 
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001eU)) 
                                                  & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                     & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                 << 2U)) 
                                 | ((0x00003fffU & 
                                     ((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                              >> 0x0000001eU)) 
                                      & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                         & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))) 
                                    | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                       >> 0x00000012U))))));
    bufp->chgCData(oldp+79,((0x000000ffU & ((0x003ffc00U 
                                             & (((1U 
                                                  == 
                                                  (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 0x0000001eU)) 
                                                 & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                    & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                << 0x0000000aU)) 
                                            | ((0x003fff00U 
                                                & (((1U 
                                                     == 
                                                     (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                      >> 0x0000001eU)) 
                                                    & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                       & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                   << 8U)) 
                                               | ((0x003fffffU 
                                                   & (((2U 
                                                        == 
                                                        (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                         >> 0x0000001eU)) 
                                                       & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                          & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                      >> 1U)) 
                                                  | ((0x003fffffU 
                                                      & ((IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q) 
                                                         >> 9U)) 
                                                     | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                                        >> 0x0000000aU))))))),8);
    bufp->chgBit(oldp+80,((1U & ((0x007ff800U & (((1U 
                                                   == 
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001eU)) 
                                                  & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                     & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                 << 0x0000000bU)) 
                                 | ((0x007ffe00U & 
                                     (((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                               >> 0x0000001eU)) 
                                       & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                          & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                      << 9U)) | ((0x007fffffU 
                                                  & ((2U 
                                                      == 
                                                      (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                       >> 0x0000001eU)) 
                                                     & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                        & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))) 
                                                 | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                                    >> 9U)))))));
    bufp->chgCData(oldp+81,((0x000000ffU & ((0x7ff80000U 
                                             & (((1U 
                                                  == 
                                                  (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 0x0000001eU)) 
                                                 & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                    & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                << 0x00000013U)) 
                                            | ((0x7ffe0000U 
                                                & (((1U 
                                                     == 
                                                     (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                      >> 0x0000001eU)) 
                                                    & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                       & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                   << 0x00000011U)) 
                                               | ((0x7fffff00U 
                                                   & (((2U 
                                                        == 
                                                        (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                         >> 0x0000001eU)) 
                                                       & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                          & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                      << 8U)) 
                                                  | ((0x7fffffffU 
                                                      & (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q)) 
                                                     | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                                        >> 1U))))))),8);
    bufp->chgBit(oldp+82,((1U & (((IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q) 
                                  << 1U) | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe)))));
    bufp->chgBit(oldp+83,(((2U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                   >> 0x0000001eU)) 
                           & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                              & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->chgCData(oldp+84,((0x0000000cU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                            >> 0x0000001cU))),4);
    bufp->chgBit(oldp+85,(((~ (0U != (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) 
                           & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o) 
                              | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o)))));
    bufp->chgBit(oldp+86,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o) 
                           & (((0U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                       >> 0x0000001eU)) 
                               & (0U != (0x0000000fU 
                                         & (~ ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                << 8U) 
                                               | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  >> 0x00000018U)))))) 
                              | ((0U != (1U & (~ ((
                                                   vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   << 8U) 
                                                  | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                     >> 0x00000018U))))) 
                                 & ((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                            >> 0x0000001eU)) 
                                    | ((2U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                               >> 0x0000001eU)) 
                                       | (3U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                 >> 0x0000001eU)))))))));
    bufp->chgBit(oldp+87,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                 >> 0x00000018U))));
    bufp->chgBit(oldp+88,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                 >> 0x00000019U))));
    bufp->chgSData(oldp+89,((0x0000ffffU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                            >> 8U))),16);
    bufp->chgBit(oldp+90,(((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                   >> 0x0000001eU)) 
                           & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                              & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->chgCData(oldp+91,((vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                             >> 0x00000018U)),8);
    bufp->chgBit(oldp+92,((1U & VL_REDXOR_32(((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                               << 8U) 
                                              | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                                 >> 0x00000018U))))));
    bufp->chgBit(oldp+93,((1U & VL_REDXOR_32((0x0000000fU 
                                              & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                 >> 0x00000018U))))));
    bufp->chgBit(oldp+94,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                            ? ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                               & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                  >> 0x00000018U)) : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q))));
    bufp->chgBit(oldp+95,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                           & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                              >> 0x00000018U))));
    bufp->chgBit(oldp+96,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                            ? ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                               & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                  >> 0x00000019U)) : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q))));
    bufp->chgBit(oldp+97,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                           & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                              >> 0x00000019U))));
    bufp->chgSData(oldp+98,((0x0000ffffU & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                                             ? ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                 << 0x00000018U) 
                                                | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 8U))
                                             : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q)))),16);
    bufp->chgSData(oldp+99,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                              ? (0x0000ffffU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                >> 8U))
                              : 0U)),16);
    bufp->chgBit(oldp+100,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
                            & vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U])));
    bufp->chgBit(oldp+101,((1U & ((~ (((0U == (7U & 
                                               (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                >> 9U))) 
                                       | ((1U == (7U 
                                                  & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                     >> 9U))) 
                                          | (4U == 
                                             (7U & 
                                              (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                               >> 9U))))) 
                                      & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                                         & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                            & ((4U 
                                                == 
                                                (7U 
                                                 & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                    >> 9U))) 
                                               | ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                       >> 9U))) 
                                                  | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk))))))) 
                                  | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err) 
                                     | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err))))));
    bufp->chgBit(oldp+102,(((0U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                          >> 9U))) 
                            | ((1U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                             >> 9U))) 
                               | (4U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                               >> 9U)))))));
    bufp->chgBit(oldp+103,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                            & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                               & ((4U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                >> 9U))) 
                                  | ((1U == (7U & (
                                                   vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                   >> 9U))) 
                                     | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->chgBit(oldp+104,((0U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                         >> 9U)))));
    bufp->chgBit(oldp+105,((1U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                         >> 9U)))));
    bufp->chgBit(oldp+106,((4U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                         >> 9U)))));
    bufp->chgCData(oldp+107,((0x0000000fU & ((IData)(1U) 
                                             << (3U 
                                                 & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001cU))))),4);
    bufp->chgCData(oldp+108,((0x000000ffU & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i)
                                              ? ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                                  << 8U) 
                                                 | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                                    >> 0x00000018U))
                                              : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q)))),8);
    bufp->chgCData(oldp+109,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i)
                               ? (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                  >> 0x00000018U) : 0U)),8);
    bufp->chgBit(oldp+110,(vlSymsp->TOP__my_ip_tb__tl_if.__PVT__clk_i));
    bufp->chgBit(oldp+111,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+112,((7U & ((vlSymsp->TOP__my_ip_tb__tl_if.d2h[2U] 
                                     << 2U) | (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+113,((7U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+114,((3U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+115,((0x000000ffU & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+116,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+117,(((vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                               << 0x00000010U) | (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+118,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+119,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+120,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+121,((1U & vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U])));
}

void Vmy_ip_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_cleanup\n"); );
    // Body
    Vmy_ip_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_ip_tb___024root*>(voidSelf);
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
