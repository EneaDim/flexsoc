// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vip1_tb__Syms.h"


void Vip1_tb___024root__trace_chg_0_sub_0(Vip1_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vip1_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root__trace_chg_0\n"); );
    // Body
    Vip1_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vip1_tb___024root*>(voidSelf);
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vip1_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vip1_tb___024root__trace_chg_0_sub_0(Vip1_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root__trace_chg_0_sub_0\n"); );
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [6U])))) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__ip1_tb.__PVT__rst_ni));
        bufp->chgWData(oldp+1,(vlSymsp->TOP__ip1_tb.__PVT__tl_i),109);
        bufp->chgBit(oldp+5,(vlSymsp->TOP__ip1_tb.__PVT__port_i));
        bufp->chgIData(oldp+6,(vlSymsp->TOP__ip1_tb.__PVT__error_count),32);
        bufp->chgIData(oldp+7,(vlSymsp->TOP__ip1_tb.__PVT__rdata),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [3U])))) {
        bufp->chgCData(oldp+8,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__addr_hit),4);
        bufp->chgBit(oldp+9,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__instr_error));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__malformed_meta_err));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
        bufp->chgBit(oldp+14,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
        bufp->chgBit(oldp+15,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity
                      [5U])))) {
        bufp->chgBit(oldp+16,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__we_o));
        bufp->chgBit(oldp+17,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o));
        bufp->chgIData(oldp+18,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__reg_rdata_next),32);
        bufp->chgBit(oldp+19,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i));
        bufp->chgBit(oldp+20,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we));
        bufp->chgBit(oldp+21,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_wdata0_qe__DOT__d_i));
        bufp->chgBit(oldp+22,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__a_ack));
        bufp->chgBit(oldp+23,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__err_internal));
        bufp->chgBit(oldp+24,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rd_req));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__wr_req));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+26,(vlSymsp->TOP__ip1_tb.__PVT__port_o));
        __Vtemp_2[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                  << 0x00000039U) | 
                                 (((QData)((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                   << 0x00000031U) 
                                  | (((QData)((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                      << 0x00000010U) 
                                     | (QData)((IData)(
                                                       (((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_q) 
                                                         << 1U) 
                                                        | (1U 
                                                           & (~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__outstanding_q))))))))));
        __Vtemp_2[1U] = (((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rspop_q) 
                          << 0x0000001eU) | (IData)(
                                                    ((((QData)((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                       << 0x00000039U) 
                                                      | (((QData)((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                          << 0x00000031U) 
                                                         | (((QData)((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                             << 0x00000010U) 
                                                            | (QData)((IData)(
                                                                              (((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                               | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__outstanding_q))))))))) 
                                                     >> 0x00000020U)));
        __Vtemp_2[2U] = (((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__outstanding_q) 
                          << 1U) | ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rspop_q) 
                                    >> 2U));
        bufp->chgWData(oldp+27,(__Vtemp_2),66);
        bufp->chgBit(oldp+30,(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_en__q));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_rst__q));
        bufp->chgSData(oldp+32,(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_setting__q),16);
        bufp->chgCData(oldp+33,(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_wdata__q),8);
        bufp->chgBit(oldp+34,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__wdata_qe));
        bufp->chgBit(oldp+35,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_core__DOT__u_sync_name__DOT__intq));
        bufp->chgBit(oldp+36,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__outstanding_q));
        bufp->chgIData(oldp+37,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rdata_q),32);
        bufp->chgBit(oldp+38,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_q));
        bufp->chgCData(oldp+39,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqid_q),8);
        bufp->chgCData(oldp+40,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqsz_q),2);
        bufp->chgCData(oldp+41,(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rspop_q),3);
        bufp->chgBit(oldp+42,((1U & (~ ((((VL_REDXOR_4(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rspop_q) 
                                           ^ VL_REDXOR_2(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                          ^ VL_REDXOR_8(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                         ^ VL_REDXOR_32(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                        ^ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_q))))));
    }
    bufp->chgBit(oldp+43,(vlSymsp->TOP__ip1_tb.__PVT__clk_i));
    bufp->chgWData(oldp+44,(vlSymsp->TOP__ip1_tb__tl_if.h2d),109);
    bufp->chgQData(oldp+48,((((QData)((IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_setting__q)) 
                              << 0x00000018U) | (QData)((IData)(
                                                                (((IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_rst__q) 
                                                                  << 0x00000017U) 
                                                                 | (((IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_en__q) 
                                                                     << 0x00000016U) 
                                                                    | ((((1U 
                                                                          == 
                                                                          (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                                           >> 0x0000001eU)) 
                                                                         & ((~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i)) 
                                                                            & (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o))) 
                                                                        << 0x00000014U) 
                                                                       | ((((1U 
                                                                             == 
                                                                             (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                                              >> 0x0000001eU)) 
                                                                            & ((~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i)) 
                                                                               & (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o))) 
                                                                           << 0x00000012U) 
                                                                          | ((((2U 
                                                                                == 
                                                                                (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                                                >> 0x0000001eU)) 
                                                                               & ((~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i)) 
                                                                                & (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o))) 
                                                                              << 9U) 
                                                                             | (((IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_wdata__q) 
                                                                                << 1U) 
                                                                                | (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__wdata_qe))))))))))),40);
    bufp->chgBit(oldp+50,(((2U == (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                   >> 0x0000001eU)) 
                           & ((~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i)) 
                              & (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->chgCData(oldp+51,((0x0000000cU & (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                            >> 0x0000001cU))),4);
    bufp->chgIData(oldp+52,(((vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                              << 8U) | (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+53,((0x0000000fU & (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgBit(oldp+54,(((~ (0U != (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__addr_hit))) 
                           & ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o) 
                              | (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__we_o)))));
    bufp->chgBit(oldp+55,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__we_o) 
                           & (((0U == (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                       >> 0x0000001eU)) 
                               & (0U != (0x0000000fU 
                                         & (~ ((vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                << 8U) 
                                               | (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                  >> 0x00000018U)))))) 
                              | ((0U != (1U & (~ ((
                                                   vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                   << 8U) 
                                                  | (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                     >> 0x00000018U))))) 
                                 & ((1U == (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                            >> 0x0000001eU)) 
                                    | ((2U == (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                               >> 0x0000001eU)) 
                                       | (3U == (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                 >> 0x0000001eU)))))))));
    bufp->chgBit(oldp+56,((1U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                 >> 0x00000018U))));
    bufp->chgBit(oldp+57,((1U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                 >> 0x00000019U))));
    bufp->chgSData(oldp+58,((0x0000ffffU & (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                            >> 8U))),16);
    bufp->chgBit(oldp+59,(((1U == (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                   >> 0x0000001eU)) 
                           & ((~ (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__error_i)) 
                              & (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->chgCData(oldp+60,((vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                             >> 0x00000018U)),8);
    bufp->chgBit(oldp+61,((1U & VL_REDXOR_32(((vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                               << 8U) 
                                              | (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                                 >> 0x00000018U))))));
    bufp->chgBit(oldp+62,((1U & VL_REDXOR_32((0x0000000fU 
                                              & (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                 >> 0x00000018U))))));
    bufp->chgBit(oldp+63,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we)
                            ? ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we) 
                               & (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                  >> 0x00000018U)) : (IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_en__q))));
    bufp->chgBit(oldp+64,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we) 
                           & (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                              >> 0x00000018U))));
    bufp->chgBit(oldp+65,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we)
                            ? ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we) 
                               & (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                  >> 0x00000019U)) : (IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_rst__q))));
    bufp->chgBit(oldp+66,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we) 
                           & (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                              >> 0x00000019U))));
    bufp->chgSData(oldp+67,((0x0000ffffU & ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we)
                                             ? ((vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                 << 0x00000018U) 
                                                | (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                   >> 8U))
                                             : (IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_ctrl_setting__q)))),16);
    bufp->chgSData(oldp+68,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_ctrl_en__DOT__we)
                              ? (0x0000ffffU & (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                >> 8U))
                              : 0U)),16);
    bufp->chgBit(oldp+69,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__outstanding_q) 
                           & vlSymsp->TOP__ip1_tb__tl_if.h2d[0U])));
    bufp->chgBit(oldp+70,((1U & ((~ (((0U == (7U & 
                                              (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                               >> 9U))) 
                                      | ((1U == (7U 
                                                 & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                                    >> 9U))) 
                                         | (4U == (7U 
                                                   & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                                      >> 9U))))) 
                                     & ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                                        & ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                           & ((4U == 
                                               (7U 
                                                & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                                   >> 9U))) 
                                              | ((1U 
                                                  == 
                                                  (7U 
                                                   & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                                      >> 9U))) 
                                                 | (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk))))))) 
                                 | ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err) 
                                    | (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err))))));
    bufp->chgBit(oldp+71,(((0U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                         >> 9U))) | 
                           ((1U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                          >> 9U))) 
                            | (4U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                            >> 9U)))))));
    bufp->chgBit(oldp+72,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                           & ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                              & ((4U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                               >> 9U))) 
                                 | ((1U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                                  >> 9U))) 
                                    | (IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->chgBit(oldp+73,((0U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                        >> 9U)))));
    bufp->chgBit(oldp+74,((1U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                        >> 9U)))));
    bufp->chgBit(oldp+75,((4U == (7U & (vlSymsp->TOP__ip1_tb__tl_if.h2d[3U] 
                                        >> 9U)))));
    bufp->chgCData(oldp+76,((0x0000000fU & ((IData)(1U) 
                                            << (3U 
                                                & (vlSymsp->TOP__ip1_tb__tl_if.h2d[1U] 
                                                   >> 0x0000001cU))))),4);
    bufp->chgCData(oldp+77,((0x000000ffU & ((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_wdata0_qe__DOT__d_i)
                                             ? ((vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                                 << 8U) 
                                                | (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                                   >> 0x00000018U))
                                             : (IData)(vlSymsp->TOP__ip1_tb.u_ip1__DOT__u_ip1_reg__DOT____Vcellout__u_wdata__q)))),8);
    bufp->chgCData(oldp+78,(((IData)(vlSymsp->TOP__ip1_tb.__PVT__u_ip1__DOT__u_ip1_reg__DOT__u_wdata0_qe__DOT__d_i)
                              ? (vlSymsp->TOP__ip1_tb__tl_if.h2d[0U] 
                                 >> 0x00000018U) : 0U)),8);
    bufp->chgBit(oldp+79,(vlSymsp->TOP__ip1_tb__tl_if.__PVT__clk_i));
    bufp->chgWData(oldp+80,(vlSymsp->TOP__ip1_tb__tl_if.d2h),66);
}

void Vip1_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip1_tb___024root__trace_cleanup\n"); );
    // Body
    Vip1_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vip1_tb___024root*>(voidSelf);
    Vip1_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
