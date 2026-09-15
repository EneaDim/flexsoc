// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___nba_sequent__TOP__19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) {
            ++(vlSelf->__Vcoverage[5009]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = 1U;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack) {
            ++(vlSelf->__Vcoverage[5007]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = 0U;
        } else {
            ++(vlSelf->__Vcoverage[5008]);
        }
    } else {
        ++(vlSelf->__Vcoverage[5010]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5011]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5012]);
    }
    ++(vlSelf->__Vcoverage[5013]);
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) {
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
                  | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)) 
                 | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req))) {
                ++(vlSelf->__Vcoverage[5028]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_1 = 0xffffffffU;
            } else {
                ++(vlSelf->__Vcoverage[5029]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_1;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
                   | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal));
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) {
                ++(vlSelf->__Vcoverage[5024]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
                ++(vlSelf->__Vcoverage[5025]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) {
                ++(vlSelf->__Vcoverage[5026]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i)) 
                        & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal))) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req))))) {
                ++(vlSelf->__Vcoverage[5027]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
                ++(vlSelf->__Vcoverage[5030]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) {
                ++(vlSelf->__Vcoverage[5031]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal))))) {
                ++(vlSelf->__Vcoverage[5032]);
            }
            ++(vlSelf->__Vcoverage[5033]);
        } else {
            ++(vlSelf->__Vcoverage[5034]);
        }
    } else {
        ++(vlSelf->__Vcoverage[5035]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5036]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5037]);
    }
    ++(vlSelf->__Vcoverage[5038]);
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) {
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) {
                ++(vlSelf->__Vcoverage[5016]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_0 = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5017]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_0 = 0U;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q 
                = (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                   << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q 
                = (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                         >> 4U));
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) {
                ++(vlSelf->__Vcoverage[5014]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req)))) {
                ++(vlSelf->__Vcoverage[5015]);
            }
            ++(vlSelf->__Vcoverage[5018]);
        } else {
            ++(vlSelf->__Vcoverage[5019]);
        }
    } else {
        ++(vlSelf->__Vcoverage[5020]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5021]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5022]);
    }
    ++(vlSelf->__Vcoverage[5023]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4810, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4880, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4944, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4958, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4974, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4978, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4816, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4946, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error;
    }
}

void Vtop___024root___nba_sequent__TOP__20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
             & (1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q)))) {
            ++(vlSelf->__Vcoverage[7543]);
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q 
            = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
               & (1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q)));
        if ((1U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q))) {
            ++(vlSelf->__Vcoverage[7544]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q)))) {
            ++(vlSelf->__Vcoverage[7545]);
        }
        ++(vlSelf->__Vcoverage[7547]);
    } else {
        ++(vlSelf->__Vcoverage[7546]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[7548]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[7549]);
    }
    ++(vlSelf->__Vcoverage[7550]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7427, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[7514]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d;
    } else {
        ++(vlSelf->__Vcoverage[7513]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[7515]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[7516]);
    }
    ++(vlSelf->__Vcoverage[7517]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7401, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6223, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7473, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7489, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7507, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0aU)))) {
        ++(vlSelf->__Vcoverage[7555]);
    }
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q))) {
        ++(vlSelf->__Vcoverage[7556]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q)))) {
        ++(vlSelf->__Vcoverage[7557]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 7429, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err 
        = ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0000000aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7511, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7399, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7421, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7419, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5989, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6273, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6231, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle;
    }
}

void Vtop___024root___nba_sequent__TOP__21(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__21\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        ++(vlSelf->__Vcoverage[6873]);
        VL_ASSIGNSEL_WI(128, 8, (0x0000007fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                                                << 3U)), vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i);
    } else {
        ++(vlSelf->__Vcoverage[6874]);
    }
    ++(vlSelf->__Vcoverage[6875]);
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6601, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6617, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6633, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6649, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U]));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6665, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6681, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6697, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6713, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U]));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6729, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6745, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6761, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6777, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U]));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6793, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 8U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6809, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 8U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                              >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0xffff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 0x00000010U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6825, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                           >> 0x00000018U)) 
                               ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                   << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                             >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6841, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
                                           >> 0x00000018U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                 << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
                                           >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U] 
            = ((0x00ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]) 
               | (0xff000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U]));
    }
}

void Vtop___024root___nba_comb__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
        = (((QData)((IData)((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q) 
                              << 9U) | ((((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q) 
                                            << 4U) 
                                           | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q) 
                                               << 3U) 
                                              | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q) 
                                                 << 2U))) 
                                          | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q) 
                                              << 1U) 
                                             | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q))) 
                                         << 4U) | (
                                                   ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q) 
                                                    << 3U) 
                                                   | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q) 
                                                       << 2U) 
                                                      | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre))))))) 
            << 0x00000020U) | (QData)((IData)(((((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre) 
                                                   << 8U) 
                                                  | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre) 
                                                     << 6U)) 
                                                 | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre) 
                                                     << 4U) 
                                                    | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre) 
                                                        << 2U) 
                                                       | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre)))) 
                                                << 0x00000016U) 
                                               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre) 
                                                   << 0x0000000dU) 
                                                  | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q) 
                                                      << 5U) 
                                                     | ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe) 
                                                          << 4U) 
                                                         | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q) 
                                                             << 3U) 
                                                            | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe) 
                                                               << 2U))) 
                                                        | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q) 
                                                            << 1U) 
                                                           | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe)))))))));
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 2084, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                        >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2116, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2118, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2120, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2122, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2124, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2126, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2128, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2130, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2132, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2134, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2136, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2138, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2140, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2142, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2144, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2146, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2148, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2150, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2152, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2154, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2170, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2172, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2188, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2190, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2192, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2194, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2196, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw;
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 1507, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                        >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1539, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1541, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1543, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1545, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1547, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1549, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1551, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1553, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1555, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1557, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1559, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1561, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1563, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1565, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1567, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1569, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1571, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1573, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1575, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1577, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1593, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1595, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1611, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1613, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1615, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1617, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1619, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw;
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 975, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1007, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1009, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1011, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1013, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1015, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1017, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1019, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1021, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1023, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1025, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1027, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1029, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1031, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1033, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1035, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1037, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1039, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1041, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1043, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1045, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1061, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1063, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1079, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1081, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1083, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1085, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1087, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw;
    if ((IData)((3ULL == (3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[6309]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[6310]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 1U))))) {
        ++(vlSelf->__Vcoverage[6311]);
    }
    if ((IData)((0x000000000000000cULL == (0x000000000000000cULL 
                                           & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[6312]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 2U))))) {
        ++(vlSelf->__Vcoverage[6313]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 3U))))) {
        ++(vlSelf->__Vcoverage[6314]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata 
        = (0x000000ffU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                  >> 5U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst 
        = (3U == (3U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst 
        = (3U == (3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                >> 2U))));
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 5761, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                        >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000029U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x000001ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x0000ffffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                          >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5793, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffeffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5795, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000027U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffff7fffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000026U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000026U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5797, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000026U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000026U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffbfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000026U))))) 
                  << 0x00000026U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000025U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000025U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5799, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000025U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffdfffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5801, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000024U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffefffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5803, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000023U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffff7ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000022U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000022U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5805, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000022U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000022U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffbffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000022U))))) 
                  << 0x00000022U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000021U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000021U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5807, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000021U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000021U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffdffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000021U))))) 
                  << 0x00000021U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000020U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000020U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5809, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffeffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001fU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001fU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5811, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001fU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001fU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffff7fffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001fU))))) 
                  << 0x0000001fU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001eU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001eU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5813, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffbfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001eU))))) 
                  << 0x0000001eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5815, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffdfffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001dU))))) 
                  << 0x0000001dU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001cU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5817, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001cU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001cU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffefffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001cU))))) 
                  << 0x0000001cU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001bU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001bU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5819, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001bU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffff7ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001bU))))) 
                  << 0x0000001bU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000001aU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000001aU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5821, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000001aU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000001aU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffbffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000001aU))))) 
                  << 0x0000001aU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000019U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000019U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5823, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000019U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffdffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000019U))))) 
                  << 0x00000019U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000018U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000018U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5825, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffeffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000017U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000017U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5827, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000017U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000017U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffff7fffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000017U))))) 
                  << 0x00000017U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x00000016U)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x00000016U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5829, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x00000016U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x00000016U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffbfffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x00000016U))))) 
                  << 0x00000016U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                        >> 0x0000000eU)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                          >> 0x0000000eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5831, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000000eU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffc03fffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                          >> 0x0000000eU))))) 
                  << 0x0000000eU));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 0x0000000dU)) ^ (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                    >> 0x0000000dU))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5847, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 0x0000000dU)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 0x0000000dU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffdfffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 0x0000000dU))))) 
                  << 0x0000000dU));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                        >> 5U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                           >> 5U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5849, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 5U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 5U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffe01fULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                          >> 5U))))) 
                  << 5U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 4U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5865, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 4U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 4U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01ffffffffffffefULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 4U))))) 
                  << 4U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 3U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5867, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 3U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffff7ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 3U))))) 
                  << 3U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5869, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffbULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 2U))))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5871, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5873, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000027U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 4U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x0000000dU)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000025U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000028U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000024U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000026U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000027U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                         >> 0x00000022U)));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6291, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6175, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6177, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7566, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6307, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6289, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6169, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7397, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6173, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6171, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7395, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6167, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7026, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6499, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7020, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7022, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6523, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7562, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7287, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i;
    }
}

void Vtop___024root___nba_comb__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[6317]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[6318]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) {
        ++(vlSelf->__Vcoverage[6319]);
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable))) {
        ++(vlSelf->__Vcoverage[6369]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[6370]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[6371]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) {
        ++(vlSelf->__Vcoverage[6372]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6195, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready;
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
        ++(vlSelf->__Vcoverage[7112]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[7113]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)))) {
        ++(vlSelf->__Vcoverage[7114]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o)))) {
        ++(vlSelf->__Vcoverage[7115]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7044, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7568, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr) {
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d 
                = (0x00000400U | ((0x00000200U & ((
                                                   (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)) 
                                                   | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity)) 
                                                  << 9U)) 
                                  | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data) 
                                     << 1U)));
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[7681]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0 = 0x0bU;
            } else {
                ++(vlSelf->__Vcoverage[7682]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0 = 0x0aU;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[7677]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[7678]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[7679]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[7680]);
            }
            ++(vlSelf->__Vcoverage[7688]);
        } else {
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 & (0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q)))) {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d 
                    = (0x00000400U | (0x000003ffU & 
                                      ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q) 
                                       >> 1U)));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d 
                    = (1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
                    = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q) 
                                      - (IData)(1U)));
                ++(vlSelf->__Vcoverage[7683]);
            } else {
                ++(vlSelf->__Vcoverage[7684]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 & (0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q)))) {
                ++(vlSelf->__Vcoverage[7685]);
            }
            if ((0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q))) {
                ++(vlSelf->__Vcoverage[7686]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q)))) {
                ++(vlSelf->__Vcoverage[7687]);
            }
        }
        ++(vlSelf->__Vcoverage[7690]);
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d = 0x07ffU;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d = 1U;
        ++(vlSelf->__Vcoverage[7689]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[7691]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        ++(vlSelf->__Vcoverage[7692]);
    }
    ++(vlSelf->__Vcoverage[7693]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7086, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7610, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 7640, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7664, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)))) {
        ++(vlSelf->__Vcoverage[7360]);
    }
    if ((7U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o))) {
        ++(vlSelf->__Vcoverage[7361]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i)))) {
        ++(vlSelf->__Vcoverage[7362]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7291, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
           & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7355, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
    }
}

void Vtop___024root___nba_comb__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
        = (((((4U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid)) 
                     << 2U)) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle) 
                                 << 1U) | ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
                                           & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) 
             << 0x0000001bU) | (((0x00000400U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
                                                 << 0x0000000aU)) 
                                 | ((0x00000200U & 
                                     ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready)) 
                                      << 9U)) | ((0x00000100U 
                                                  & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready)) 
                                                     << 8U)) 
                                                 | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata)))) 
                                << 0x00000010U)) | 
           (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth) 
             << 8U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth)));
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5875, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5877, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5879, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5881, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5883, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5885, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5887, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5903, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5919, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1089, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1091, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1093, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1095, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1097, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1099, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1101, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1117, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1133, vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1621, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1623, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1625, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1627, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1629, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1631, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1633, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1649, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1665, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2198, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2200, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2202, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2204, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2206, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2208, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000018U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000018U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3effffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x01000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2210, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3f00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x00ff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2226, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2242, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001dU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001cU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001bU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x0000001aU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x00000019U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d 
        = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                 >> 0x00000018U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d 
        = (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                          >> 8U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d 
        = (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d 
        = (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                          >> 0x00000010U));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3165, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3175, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3185, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3195, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3205, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3215, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3614, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3666, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3893, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3169, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3171, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3179, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3181, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3189, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3191, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3199, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3201, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3209, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3211, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3219, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3221, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3632, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3648, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3684, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3700, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3911, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3927, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2632, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2630, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2628, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2626, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2624, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2622, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2694, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2678, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2636, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff8U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs) 
                   << 2U) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs) 
                              << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs))));
        ++(vlSelf->__Vcoverage[2764]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff0fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs) 
                     << 3U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs) 
                               << 2U)) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs) 
                                           << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs))) 
                  << 4U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs) 
                  << 0x00000010U));
    } else if ((2U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff0U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs) 
                    << 3U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs) 
                              << 2U)) | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs) 
                                          << 1U) | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs))));
        ++(vlSelf->__Vcoverage[2765]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffffcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs) 
                   << 5U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs) 
                             << 4U)));
    } else if ((4U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs));
        ++(vlSelf->__Vcoverage[2766]);
    } else if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = (0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[2767]);
    } else if ((0x00000010U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = (0xfffffffcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[2768]);
    } else if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs));
        ++(vlSelf->__Vcoverage[2769]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[2770]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: uart_reg_core.sv:663: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"uart_tb.u_uart.u_uart_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/rtl/uart_reg_core.sv", 663, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[2771]);
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2416, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2346, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
        = (((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata)) 
            << 2U) | (QData)((IData)((1U | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error) 
                                            << 1U)))));
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2016, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2080, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2082, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1855, (IData)(
                                                                       (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1919, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1921, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
        = (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                   >> 2U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i 
        = (1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 1U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i 
        = (1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp)));
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4744, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4808, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4742, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i;
    }
}

void Vtop___024root___nba_comb__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d = 0U;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d 
            = (1U & (((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q)) 
                     >> 4U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d 
            = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q)));
        ++(vlSelf->__Vcoverage[7518]);
    } else {
        ++(vlSelf->__Vcoverage[7519]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d = 8U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d = 0U;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
            ++(vlSelf->__Vcoverage[7522]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0 = 0x0bU;
        } else {
            ++(vlSelf->__Vcoverage[7523]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0 = 0x0aU;
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
            ++(vlSelf->__Vcoverage[7520]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)))) {
            ++(vlSelf->__Vcoverage[7521]);
        }
        ++(vlSelf->__Vcoverage[7534]);
    } else {
        if (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)) 
             & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q))) {
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                  == ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                       ? 0x0bU : 0x0aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx))) {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = 1U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d = 0U;
                ++(vlSelf->__Vcoverage[7524]);
            } else {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d 
                    = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) 
                        << 0x0000000aU) | (0x000003ffU 
                                           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                              >> 1U)));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
                    = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                                      - (IData)(1U)));
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d 
                    = (1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q));
                ++(vlSelf->__Vcoverage[7525]);
            }
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                  == ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                       ? 0x0bU : 0x0aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx))) {
                ++(vlSelf->__Vcoverage[7526]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
                ++(vlSelf->__Vcoverage[7527]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                 != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                      ? 0x0bU : 0x0aU))) {
                ++(vlSelf->__Vcoverage[7528]);
            }
            ++(vlSelf->__Vcoverage[7529]);
        } else {
            ++(vlSelf->__Vcoverage[7530]);
        }
        if (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)) 
             & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q))) {
            ++(vlSelf->__Vcoverage[7531]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q)))) {
            ++(vlSelf->__Vcoverage[7532]);
        }
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) {
            ++(vlSelf->__Vcoverage[7533]);
        }
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
        ++(vlSelf->__Vcoverage[7535]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) {
        ++(vlSelf->__Vcoverage[7536]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)))) {
        ++(vlSelf->__Vcoverage[7537]);
    }
    ++(vlSelf->__Vcoverage[7539]);
    ++(vlSelf->__Vcoverage[7541]);
    ++(vlSelf->__Vcoverage[7542]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7505, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 7451, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7481, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7497, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7509, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d;
    }
}

void Vtop___024root___nba_comb__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))))) {
        ++(vlSelf->__Vcoverage[5171]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                     >> 0x0000000cU))))) {
        ++(vlSelf->__Vcoverage[5172]);
    }
    if (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
          >> 0x0000000cU) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))) {
        ++(vlSelf->__Vcoverage[5173]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) {
        ++(vlSelf->__Vcoverage[5174]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
               << 1U) | (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                  | ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                      >> 0x0000000cU) 
                                     & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i)))))));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                        << 0x00000029U) | (((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                            << 0x00000021U) 
                                           | (QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
              << 0x00000010U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | (((IData)((((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                         << 0x00000029U) | (((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                             << 0x00000021U) 
                                            | (QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
               >> 0x00000010U) | ((IData)(((((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                                             << 0x00000029U) 
                                            | (((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                                << 0x00000021U) 
                                               | (QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata)))) 
                                           >> 0x00000020U)) 
                                  << 0x00000010U)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                                            >> 2U)));
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5039, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                        << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                          << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5041, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5047, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xc7ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x38000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5053, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xf9ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x06000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5057, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfe01ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x01fe0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0x00010000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5073, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfffeffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x00010000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                  << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                    << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5075, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5139, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xffff01ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x0000fe00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5153, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffe03U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x000001fcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5167, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffdU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5169, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5491, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                        << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                          << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5493, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5499, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xc7ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x38000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5505, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xf9ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x06000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5509, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfe01ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x01fe0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0x00010000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5525, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfffeffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x00010000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                  << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                    << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5527, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5591, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff01ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x0000fe00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5605, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffe03U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x000001fcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5619, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffdU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5621, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5755, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl;
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5623, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5625, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5631, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5637, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5641, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5657, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5659, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5723, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5737, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5751, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5753, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    if ((IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU) & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4988]);
    }
    if ((1U & (~ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4989]);
    }
    if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU)))) {
        ++(vlSelf->__Vcoverage[4990]);
    }
    if ((IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U) & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4991]);
    }
    if ((1U & (~ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4992]);
    }
    if ((1U & (~ (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[4993]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack 
        = (IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4516, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4518, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4524, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4530, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4534, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4550, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4552, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4616, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4630, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4644, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4646, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack 
        = (IData)(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4814, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0200U == (0x0e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4994]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0U == (0x0e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4995]);
    }
    if (((0U != (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                       >> 9U))) & (1U != (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U))))) {
        ++(vlSelf->__Vcoverage[4996]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4997]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0800U == (0x0e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4998]);
    }
    if ((4U != (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[4999]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[5000]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4812, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U)))));
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1375, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1377, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1383, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1389, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1393, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1409, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1411, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1475, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1489, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1503, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1505, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U];
    vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4984, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4986, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err 
            = (0U != (3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
        if ((0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[5179]);
        }
        if ((0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[5180]);
        }
        if ((IData)((0U == (0x30000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])))) {
            ++(vlSelf->__Vcoverage[5181]);
        }
        ++(vlSelf->__Vcoverage[5182]);
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err = 0U;
        ++(vlSelf->__Vcoverage[5183]);
    }
    ++(vlSelf->__Vcoverage[5184]);
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 843, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 845, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 851, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 857, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 861, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 877, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 879, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U]));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 943, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 957, 
                               ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 971, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 973, vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U]));
    }
    vlSelfRef.uart_tb__DOT__tl_o[0U] = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U];
    vlSelfRef.uart_tb__DOT__tl_o[1U] = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U];
    vlSelfRef.uart_tb__DOT__tl_o[2U] = vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4952, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    if ((0U != (((vlSelfRef.uart_tb__DOT__tl_o[0U] 
                  ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_o[0U]) 
                 | (vlSelfRef.uart_tb__DOT__tl_o[1U] 
                    ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_o[1U])) 
                | (vlSelfRef.uart_tb__DOT__tl_o[2U] 
                   ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_o[2U])))) {
        VL_COV_TOGGLE_CHG_ST_W(66, vlSelf->__Vcoverage + 474, vlSelfRef.uart_tb__DOT__tl_o, vlSelfRef.uart_tb__DOT____Vtogcov__tl_o);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o[0U] 
            = vlSelfRef.uart_tb__DOT__tl_o[0U];
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o[1U] 
            = vlSelfRef.uart_tb__DOT__tl_o[1U];
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o[2U] 
            = vlSelfRef.uart_tb__DOT__tl_o[2U];
    }
    vlSelfRef.uart_tb__DOT__tl_o_d_valid = (1U & (vlSelfRef.uart_tb__DOT__tl_o[2U] 
                                                  >> 1U));
    vlSelfRef.uart_tb__DOT__tl_o_d_opcode = (7U & (
                                                   (vlSelfRef.uart_tb__DOT__tl_o[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.uart_tb__DOT__tl_o[1U] 
                                                      >> 0x0000001eU)));
    vlSelfRef.uart_tb__DOT__tl_o_d_data = ((vlSelfRef.uart_tb__DOT__tl_o[1U] 
                                            << 0x00000010U) 
                                           | (vlSelfRef.uart_tb__DOT__tl_o[0U] 
                                              >> 0x00000010U));
    vlSelfRef.uart_tb__DOT__tl_o_d_error = (1U & (vlSelfRef.uart_tb__DOT__tl_o[0U] 
                                                  >> 1U));
    vlSelfRef.uart_tb__DOT__tl_o_a_ready = (1U & vlSelfRef.uart_tb__DOT__tl_o[0U]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[5001]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[5002]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req)))) {
        ++(vlSelf->__Vcoverage[5003]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[5004]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[5005]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req)))) {
        ++(vlSelf->__Vcoverage[5006]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4948, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
           & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
           & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    if (((IData)(vlSelfRef.uart_tb__DOT__tl_o_d_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 180, vlSelfRef.uart_tb__DOT__tl_o_d_valid, vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_valid);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_valid 
            = vlSelfRef.uart_tb__DOT__tl_o_d_valid;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__tl_o_d_opcode) 
                ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 182, vlSelfRef.uart_tb__DOT__tl_o_d_opcode, vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_opcode);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_opcode 
            = vlSelfRef.uart_tb__DOT__tl_o_d_opcode;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__tl_o_d_data 
                ^ vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 188, vlSelfRef.uart_tb__DOT__tl_o_d_data, vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_data);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_data 
            = vlSelfRef.uart_tb__DOT__tl_o_d_data;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__tl_o_d_error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 252, vlSelfRef.uart_tb__DOT__tl_o_d_error, vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_error);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_d_error 
            = vlSelfRef.uart_tb__DOT__tl_o_d_error;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__tl_o_a_ready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_a_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 254, vlSelfRef.uart_tb__DOT__tl_o_a_ready, vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_a_ready);
        vlSelfRef.uart_tb__DOT____Vtogcov__tl_o_a_ready 
            = vlSelfRef.uart_tb__DOT__tl_o_a_ready;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4656, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4658, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1683, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_re);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_re 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we) {
        ++(vlSelf->__Vcoverage[1923]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re) {
        ++(vlSelf->__Vcoverage[1924]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re)) 
               & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we))))) {
        ++(vlSelf->__Vcoverage[1925]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1685, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_we);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__flexsoc_tlul_we 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we;
    }
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__18(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16) {
                    ++(vlSelf->__Vcoverage[7666]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q 
                        = (1U & (((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q)) 
                                 >> 4U));
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q)));
                } else {
                    ++(vlSelf->__Vcoverage[7667]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q = 0U;
                }
            } else {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q = 0U;
                ++(vlSelf->__Vcoverage[7668]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7669]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7670]);
            }
            ++(vlSelf->__Vcoverage[7671]);
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7673]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d;
            } else {
                ++(vlSelf->__Vcoverage[7672]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q = 0U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q = 0x07ffU;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7674]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7675]);
            }
            ++(vlSelf->__Vcoverage[7676]);
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7592, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 7618, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7662, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 7602, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7590, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
            }
        }
    }
    if ((0x0000004800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) {
                ++(vlSelf->__Vcoverage[6392]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
            } else {
                ++(vlSelf->__Vcoverage[6391]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1 = 1U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2 = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni)))) {
                ++(vlSelf->__Vcoverage[6393]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) {
                ++(vlSelf->__Vcoverage[6394]);
            }
            ++(vlSelf->__Vcoverage[6395]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6385, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6383, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1;
            }
        }
    }
    if ((0x0000001800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                    = (0x0001ffffU & ((0x0000ffffU 
                                       & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q) 
                                      + (0x0000ffffU 
                                         & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                    >> 0x00000029U)))));
                ++(vlSelf->__Vcoverage[6360]);
                ++(vlSelf->__Vcoverage[6362]);
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) {
                    ++(vlSelf->__Vcoverage[6363]);
                }
            } else {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q = 0U;
                ++(vlSelf->__Vcoverage[6365]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni)))) {
                ++(vlSelf->__Vcoverage[6366]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) {
                ++(vlSelf->__Vcoverage[6367]);
            }
            ++(vlSelf->__Vcoverage[6368]);
            if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q))) {
                VL_COV_TOGGLE_CHG_ST_I(17, vlSelf->__Vcoverage + 6326, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16 
                = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                         >> 0x00000010U));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5987, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7564, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7393, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16;
            }
        }
    }
    if ((0x0006000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__3
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
            __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst = 0;
            __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                    __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst 
                        = (1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)));
                    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                        ++(vlSelf->__Vcoverage[6577]);
                    }
                    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                        ++(vlSelf->__Vcoverage[6578]);
                    }
                    ++(vlSelf->__Vcoverage[6579]);
                } else {
                    ++(vlSelf->__Vcoverage[6580]);
                }
            } else {
                ++(vlSelf->__Vcoverage[6581]);
                __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6582]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6583]);
            }
            ++(vlSelf->__Vcoverage[6584]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6575, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
            }
        }
    }
    if ((0x0060000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__4
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
            __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst = 0;
            __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                    __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst 
                        = (1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)));
                    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                        ++(vlSelf->__Vcoverage[7092]);
                    }
                    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                        ++(vlSelf->__Vcoverage[7093]);
                    }
                    ++(vlSelf->__Vcoverage[7094]);
                } else {
                    ++(vlSelf->__Vcoverage[7095]);
                }
            } else {
                ++(vlSelf->__Vcoverage[7096]);
                __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7097]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7098]);
            }
            ++(vlSelf->__Vcoverage[7099]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7090, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
            }
        }
    }
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x0001800000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__7
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6491]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[6490]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6492]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6493]);
            }
            ++(vlSelf->__Vcoverage[6494]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6488, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6283, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni;
            }
        }
    }
    if (((1ULL & vlSelfRef.__VnbaTriggered[1U]) | (0x8000000000000000ULL 
                                                   & vlSelfRef.__VnbaTriggered[0U]))) {
        {
            // Inlined CFunc: _nba_sequent__TOP__8
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7728]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[7727]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7729]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7730]);
            }
            ++(vlSelf->__Vcoverage[7731]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7725, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7706, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
            }
        }
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[1U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__9
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7762]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[7761]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7763]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7764]);
            }
            ++(vlSelf->__Vcoverage[7765]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7759, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7740, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
            }
        }
    }
    if ((0x0000060000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__10
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6456]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[6455]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6457]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6458]);
            }
            ++(vlSelf->__Vcoverage[6459]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6453, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6431, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
            }
        }
    }
    if ((0x0000600000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__11
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6480]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[6479]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6481]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6482]);
            }
            ++(vlSelf->__Vcoverage[6483]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6477, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
            }
        }
    }
    if ((0x6000000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__12
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7717]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[7716]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7718]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7719]);
            }
            ++(vlSelf->__Vcoverage[7720]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7714, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7702, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1151, vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5759, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6475, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6486, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0000180000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__13
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6469]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[6468]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6470]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6471]);
            }
            ++(vlSelf->__Vcoverage[6472]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6466, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6287, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6497, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6423, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6449, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000000000060ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__14
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[2498]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[2499]);
                }
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[2500]);
                }
                if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err)))) {
                    ++(vlSelf->__Vcoverage[2502]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2503]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2504]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2505]);
            }
            ++(vlSelf->__Vcoverage[2506]);
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
                ++(vlSelf->__Vcoverage[2507]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) {
                ++(vlSelf->__Vcoverage[2509]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
                ++(vlSelf->__Vcoverage[2510]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2496, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
                   | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2258, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o;
            }
        }
    }
    if ((0x0000002800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__15
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
                    ++(vlSelf->__Vcoverage[6377]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[6378]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
                }
            } else {
                ++(vlSelf->__Vcoverage[6379]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni)))) {
                ++(vlSelf->__Vcoverage[6380]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) {
                ++(vlSelf->__Vcoverage[6381]);
            }
            ++(vlSelf->__Vcoverage[6382]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6205, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
            }
        }
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[1U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__16
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7751]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[7750]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[7752]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[7753]);
            }
            ++(vlSelf->__Vcoverage[7754]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7748, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7736, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1149, vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1155, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1928, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3225, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3257, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
            }
        }
    }
    if ((0x0000018000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__17
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6443]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[6442]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[6444]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[6445]);
            }
            ++(vlSelf->__Vcoverage[6446]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6440, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6427, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6233, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
            }
        }
    }
    if ((0x0020000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x0000000600000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__20(vlSelf);
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__21(vlSelf);
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__22
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3146]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[3145]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3147]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3148]);
            }
            ++(vlSelf->__Vcoverage[3149]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3143, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2714, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe;
            }
        }
    }
    if ((0x0000000001800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__23
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3159]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[3158]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3160]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3161]);
            }
            ++(vlSelf->__Vcoverage[3162]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3156, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2710, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe;
            }
        }
    }
    if ((0x0000000060000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__24
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3806]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3807]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3808]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3809]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3810]);
            }
            ++(vlSelf->__Vcoverage[3811]);
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3740, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3834, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3772, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3814]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3815]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3812]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3813]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3875, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3756, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds;
            }
        }
    }
    if ((0x0000000006000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__25
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3518]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3519]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3520]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3521]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3522]);
            }
            ++(vlSelf->__Vcoverage[3523]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3508, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3532, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3512, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3526]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3527]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3524]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3525]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3545, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3510, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds;
            }
        }
    }
    if ((0x0000000018000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__26
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3567]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3568]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3569]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3570]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3571]);
            }
            ++(vlSelf->__Vcoverage[3572]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3557, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3581, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3561, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3575]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3576]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3573]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3574]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3594, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3559, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds;
            }
        }
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__27
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2814]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2815]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2816]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2817]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2818]);
            }
            ++(vlSelf->__Vcoverage[2819]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2804, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2828, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2808, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2822]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2823]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2820]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2821]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2841, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2552, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2806, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds;
            }
        }
    }
    if ((0x0000000000000600ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__28
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2863]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2864]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2865]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2866]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2867]);
            }
            ++(vlSelf->__Vcoverage[2868]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2853, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2877, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2857, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2871]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2872]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2869]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2870]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2890, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2548, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2855, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds;
            }
        }
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__29
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2912]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2913]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2914]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2915]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2916]);
            }
            ++(vlSelf->__Vcoverage[2917]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2902, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2926, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2906, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2920]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2921]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2918]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2919]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2939, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2544, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2904, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds;
            }
        }
    }
    if ((0x0000000000006000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__30
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2961]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2962]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2963]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2964]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2965]);
            }
            ++(vlSelf->__Vcoverage[2966]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2951, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2975, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2955, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2969]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2970]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2967]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2968]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2988, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2540, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2953, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds;
            }
        }
    }
    if ((0x0000000000018000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__31
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3010]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3011]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3012]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3013]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3014]);
            }
            ++(vlSelf->__Vcoverage[3015]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3024, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3004, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3018]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3019]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3016]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3017]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3037, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2536, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3002, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds;
            }
        }
    }
    if ((0x0000000000060000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__32
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3059]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3060]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3061]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3062]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3063]);
            }
            ++(vlSelf->__Vcoverage[3064]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3049, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3073, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3053, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3067]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3068]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3065]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3066]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3086, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2532, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3051, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds;
            }
        }
    }
    if ((0x0000000000180000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__33
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3108]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3109]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3110]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3111]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3112]);
            }
            ++(vlSelf->__Vcoverage[3113]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3098, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3122, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3102, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3116]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3117]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3114]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3115]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3135, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2528, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3100, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds;
            }
        }
    }
    if ((0x0000000180000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__34
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[4145]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[4146]);
                }
            } else {
                ++(vlSelf->__Vcoverage[4147]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q = 0x4b7fU;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4148]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4149]);
            }
            ++(vlSelf->__Vcoverage[4150]);
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4015, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4189, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4079, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[4153]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[4154]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[4151]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[4152]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4262, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 2556, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 4047, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds;
            }
        }
    }
    if ((0x01e0000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[7102]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[7103]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) {
                ++(vlSelf->__Vcoverage[7104]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[7105]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[7106]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[7107]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty))));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7024, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7042, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready)))) {
                ++(vlSelf->__Vcoverage[6324]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) {
                ++(vlSelf->__Vcoverage[6325]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6199, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
                ++(vlSelf->__Vcoverage[6320]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
                ++(vlSelf->__Vcoverage[6321]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6197, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid;
            }
        }
    }
    if ((0x001e000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__1
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[6587]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[6588]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) {
                ++(vlSelf->__Vcoverage[6589]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[6590]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[6591]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[6592]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty))));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6503, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6521, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready)))) {
                ++(vlSelf->__Vcoverage[6322]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) {
                ++(vlSelf->__Vcoverage[6323]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6229, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid)))) {
                ++(vlSelf->__Vcoverage[6315]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) {
                ++(vlSelf->__Vcoverage[6316]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6227, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid;
            }
        }
    }
    if (((1ULL & vlSelfRef.__VnbaTriggered[1U]) | (0x8000000000000000ULL 
                                                   & vlSelfRef.__VnbaTriggered[0U]))) {
        {
            // Inlined CFunc: _nba_sequent__TOP__35
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7712, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x6000000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__36
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6462, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0000600000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__37
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6285, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7560, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7018, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7285, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
            }
        }
    }
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__38
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6203, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
            }
        }
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[1U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__39
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7746, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000180000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__40
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6436, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7391, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni;
            }
        }
    }
    if ((0x0000060000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__41
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6438, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x000001c800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__2
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                 & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
                ++(vlSelf->__Vcoverage[6396]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                 & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
                ++(vlSelf->__Vcoverage[6397]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                 & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))) {
                ++(vlSelf->__Vcoverage[6398]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[6399]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[6400]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                        & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[6401]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))))) {
                ++(vlSelf->__Vcoverage[6402]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[6403]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                        & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
                ++(vlSelf->__Vcoverage[6404]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[6405]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
                ++(vlSelf->__Vcoverage[6406]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj 
                = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                    & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                       | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
                   | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6389, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
            }
        }
    }
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__42
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
                VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 7072, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
            }
        }
    }
    if ((0x01a0000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__3
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata 
                = (0x000000ffU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                          >> ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                              << 3U))));
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7244, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7263, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[7281]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[7282]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[7279]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)))) {
                ++(vlSelf->__Vcoverage[7280]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7046, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6179, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7572, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data;
            }
        }
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[1U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__43
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4296, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3139, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3152, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3718, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3500, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3549, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2794, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2845, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2894, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2943, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2992, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3041, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3090, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3945, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5187, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni;
            }
        }
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__44
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 6553, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
            }
        }
    }
    if ((0x001a000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__4
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata 
                = (0x000000ffU & (((0U == (0x0000001fU 
                                           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                              << 3U)))
                                    ? 0U : (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage
                                            [(((IData)(7U) 
                                               + ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                                  << 3U)) 
                                              >> 5U)] 
                                            << ((IData)(0x00000020U) 
                                                - (0x0000001fU 
                                                   & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                                      << 3U))))) 
                                  | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage
                                     [(0x07ffffffU 
                                       & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                          >> 2U))] 
                                     >> (0x0000001fU 
                                         & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                            << 3U)))));
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6857, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6876, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[6894]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[6895]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[6892]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)))) {
                ++(vlSelf->__Vcoverage[6893]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6525, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5971, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata;
            }
        }
    }
    if ((0x00000001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x01a00001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__6
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity 
                = (1U & (VL_REDXOR_8(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                         ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                    >> 0x00000028U))));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7570, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity;
            }
        }
    }
    if ((0x000001c9ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__7
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) {
                ++(vlSelf->__Vcoverage[6409]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
            } else {
                ++(vlSelf->__Vcoverage[6410]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) {
                ++(vlSelf->__Vcoverage[6407]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable)))) {
                ++(vlSelf->__Vcoverage[6408]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6387, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx;
            }
        }
    }
    if ((0x00000029ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__8
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
                ++(vlSelf->__Vcoverage[6375]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
            } else {
                ++(vlSelf->__Vcoverage[6376]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
                ++(vlSelf->__Vcoverage[6373]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback)))) {
                ++(vlSelf->__Vcoverage[6374]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5937, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 623, vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o;
            }
            vlSelfRef.uart_tb__DOT__tx_o = vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__tx_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__tx_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6, vlSelfRef.uart_tb__DOT__tx_o, vlSelfRef.uart_tb__DOT____Vtogcov__tx_o);
                vlSelfRef.uart_tb__DOT____Vtogcov__tx_o 
                    = vlSelfRef.uart_tb__DOT__tx_o;
            }
        }
    }
    if ((0x06000001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__9
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[7553]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1 
                    = (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                      >> 1U));
            } else {
                ++(vlSelf->__Vcoverage[7554]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1 
                    = (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                      >> 2U));
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[7551]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[7552]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) 
                   & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
                      & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd) 
                         ^ VL_REDXOR_32((0x000001ffU 
                                         & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                            >> 1U))))));
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 7403, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7423, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6207, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data;
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
                  & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err))) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err)))) {
                ++(vlSelf->__Vcoverage[6417]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err) {
                ++(vlSelf->__Vcoverage[6418]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) {
                ++(vlSelf->__Vcoverage[6419]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid)))) {
                ++(vlSelf->__Vcoverage[6420]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6279, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid 
                = ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
                       | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err))) 
                   & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 6505, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6225, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6501, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i;
            }
        }
    }
    if ((0x01e00001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__10
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
                  & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                ++(vlSelf->__Vcoverage[7108]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[7109]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)))) {
                ++(vlSelf->__Vcoverage[7110]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i)))) {
                ++(vlSelf->__Vcoverage[7111]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
                   & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7084, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)))) {
                ++(vlSelf->__Vcoverage[7357]);
            }
            if ((7U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o))) {
                ++(vlSelf->__Vcoverage[7358]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i)))) {
                ++(vlSelf->__Vcoverage[7359]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7289, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                   & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7353, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
            }
        }
    }
    if ((0x001e0001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__11
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
                  & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                ++(vlSelf->__Vcoverage[6597]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[6598]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)))) {
                ++(vlSelf->__Vcoverage[6599]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o)))) {
                ++(vlSelf->__Vcoverage[6600]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
                   & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6571, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
                 & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)))) {
                ++(vlSelf->__Vcoverage[6987]);
            }
            if ((0x0fU != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o))) {
                ++(vlSelf->__Vcoverage[6988]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i)))) {
                ++(vlSelf->__Vcoverage[6989]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6904, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
                   & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6982, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
            }
        }
    }
    if ((0x18000001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__12
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
                ++(vlSelf->__Vcoverage[7696]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1 
                    = (0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q));
            } else {
                ++(vlSelf->__Vcoverage[7697]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1 = 1U;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
                ++(vlSelf->__Vcoverage[7694]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable)))) {
                ++(vlSelf->__Vcoverage[7695]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7588, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6201, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle;
            }
        }
    }
    if ((0x180001c9ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__13
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
                ++(vlSelf->__Vcoverage[6413]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
            } else {
                ++(vlSelf->__Vcoverage[6416]);
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
                    ++(vlSelf->__Vcoverage[6414]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[6415]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx;
                }
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
                ++(vlSelf->__Vcoverage[6411]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback)))) {
                ++(vlSelf->__Vcoverage[6412]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6235, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 7425, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx;
            }
        }
    }
    if ((0x061e0001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__14
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
                  & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                ++(vlSelf->__Vcoverage[6593]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[6594]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)))) {
                ++(vlSelf->__Vcoverage[6595]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i)))) {
                ++(vlSelf->__Vcoverage[6596]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
                   & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6569, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)))) {
                ++(vlSelf->__Vcoverage[6984]);
            }
            if ((0x0fU != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o))) {
                ++(vlSelf->__Vcoverage[6985]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i)))) {
                ++(vlSelf->__Vcoverage[6986]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6902, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                   & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6980, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
            }
        }
    }
    if ((0x19e00001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__15(vlSelf);
    }
    if ((0x1ffe0001ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__16(vlSelf);
    }
    if ((0x1e0001d9ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__17(vlSelf);
    }
    if ((0x1ffe0007ffffff80ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__18(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 2> &out, const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U >= n));
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in);
void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___act_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___act_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___act_sequent__TOP__3(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        {
            // Inlined CFunc: _timing_resume
            if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[1U])) {
                vlSelfRef.__VdlySched.resume();
            }
        }
        {
            // Inlined CFunc: _eval_act
            if ((0x000000000000000cULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__0(vlSelf);
            }
            if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__1(vlSelf);
            }
            if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__2(vlSelf);
            }
            if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__3(vlSelf);
            }
            if ((7ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
                        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 3281, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
                        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
                            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
                    }
                }
            }
            if ((0x0000000000000013ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__1
                    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
                        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 3311, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
                        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
                            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
                    }
                }
            }
        }
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 2> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((2U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf);

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-tlul/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtop___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
