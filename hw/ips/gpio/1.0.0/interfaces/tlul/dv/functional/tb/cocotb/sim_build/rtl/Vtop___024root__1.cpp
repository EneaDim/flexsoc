// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (1U & (IData)(((0U != (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                            | (6U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))))));
    if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3757]);
    }
    if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3758]);
    }
    if ((IData)((6U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3759]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 2U)) & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3760]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 1U)) & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3761]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7dU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (2U & ((IData)(((0U != (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x18U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 1U)));
    if ((0x00000010U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3770]);
    }
    if ((8U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3771]);
    }
    if ((IData)((0x18U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3772]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 4U)) & (0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3773]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 3U)) & (0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3774]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7bU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (4U & ((IData)(((0U != (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x60U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 2U)));
    if ((0x00000040U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3783]);
    }
    if ((0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3784]);
    }
    if ((IData)((0x60U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3785]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 6U)) & (0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3786]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 5U)) & (0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3787]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3735, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    }
}

void Vtop___024root___act_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
        = (((QData)((IData)(((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
                               | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we)) 
                              << 5U) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
                                         << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr))))) 
            << 0x00000024U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata)) 
                                << 4U) | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be))));
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2282, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 0x00000029U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000001ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2284, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000002ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2286, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x0000030fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2294, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000003f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2358, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req 
            = ((0x000003fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_req) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req;
    if ((IData)((0x0000030000000000ULL == (0x0000030000000000ULL 
                                           & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[2924]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000028U))))) {
        ++(vlSelf->__Vcoverage[2926]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[2927]);
    }
    if ((IData)((0x0000020000000000ULL == (0x0000030000000000ULL 
                                           & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[2928]);
    }
    if ((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                       >> 0x00000028U)))) {
        ++(vlSelf->__Vcoverage[2930]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[2931]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2441, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000029U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000001ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2443, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000002ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2445, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x0000030fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2453, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000003f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2517, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i 
            = ((0x000003fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
        = (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                   >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be 
        = (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re 
        = (IData)((0x0000020000000000ULL == (0x0000030000000000ULL 
                                             & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we 
        = (IData)((0x0000030000000000ULL == (0x0000030000000000ULL 
                                             & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr 
        = (0x0000000fU & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                  >> 0x00000024U)));
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2693, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata 
        = (1U & VL_REDXOR_32(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd 
        = (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 0x0000000cU));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 0x00000010U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd 
        = (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd 
        = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                          >> 4U));
    if ((IData)((7U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3130]);
    }
    if ((IData)((0x0bU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3131]);
    }
    if ((IData)((0x0dU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3132]);
    }
    if ((IData)((1U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3133]);
    }
    if ((IData)((0x0eU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3134]);
    }
    if ((IData)((2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3135]);
    }
    if ((IData)((4U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3136]);
    }
    if ((IData)((8U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3137]);
    }
    if ((IData)((0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3138]);
    }
    if ((IData)((3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3139]);
    }
    if ((IData)((5U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3140]);
    }
    if ((IData)((9U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3141]);
    }
    if ((IData)((6U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3142]);
    }
    if ((IData)((0x0aU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3143]);
    }
    if ((IData)((0x0cU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3144]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3145]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2757, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be 
        = (1U & VL_REDXOR_4(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2683, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2681, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2685, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit 
        = (((8U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr)) 
            << 2U) | (((4U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr)) 
                       << 1U) | (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3126, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2993, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3009, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3025, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3041, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3057, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2959, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2975, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3128, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be;
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                           >> 2U)))) {
        ++(vlSelf->__Vcoverage[3087]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                           >> 1U)))) {
        ++(vlSelf->__Vcoverage[3088]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3089]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 1U)) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3093]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3097]);
    }
    if ((IData)((7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) {
        ++(vlSelf->__Vcoverage[3098]);
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
               & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                     >> 2U))))) {
        ++(vlSelf->__Vcoverage[3099]);
    }
    if ((IData)(((7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))) 
                 & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                       >> 1U))))) {
        ++(vlSelf->__Vcoverage[3100]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
         & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))) {
        ++(vlSelf->__Vcoverage[3101]);
    }
    if (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)) 
         & (7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) {
        ++(vlSelf->__Vcoverage[3102]);
    }
    if ((IData)(((0U == (5U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) 
                 & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[3103]);
    }
    if ((IData)(((0U == (3U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) 
                 & (7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))) {
        ++(vlSelf->__Vcoverage[3104]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)))) {
        ++(vlSelf->__Vcoverage[3105]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3106]);
    }
    ++(vlSelf->__Vcoverage[3107]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3074, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
           & ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                & (0U != (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) 
               | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                   >> 1U) & (0U != (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))) 
              | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 2U) & (0U != (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) 
         | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we))) {
        ++(vlSelf->__Vcoverage[3084]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0 
            = (1U & (~ (0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))));
    } else {
        ++(vlSelf->__Vcoverage[3085]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) {
        ++(vlSelf->__Vcoverage[3081]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) {
        ++(vlSelf->__Vcoverage[3082]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we))))) {
        ++(vlSelf->__Vcoverage[3083]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3572, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3469, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3366, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3263, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3152, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3954, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3906, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2833, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err) {
        ++(vlSelf->__Vcoverage[2935]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) {
        ++(vlSelf->__Vcoverage[2936]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err))))) {
        ++(vlSelf->__Vcoverage[2937]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2831, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i 
        = ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss)) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) 
           | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3628, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3525, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3422, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3319, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3216, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3974, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3926, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3679, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3108]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3109]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)))) {
        ++(vlSelf->__Vcoverage[3110]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3111]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3112]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3113]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3114]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3115]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 2U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[3116]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[3117]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[3118]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 2U)))) {
        ++(vlSelf->__Vcoverage[3119]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2829, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
              & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                 >> 2U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3703, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2947, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2983, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2949, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we) 
            << 2U) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we) 
                      << 1U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3902, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3950, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3150, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3261, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3364, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3467, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3570, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2903, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3904, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3952, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3924, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3972, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3243]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3244]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3214, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3247]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3248]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3245]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3246]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3346]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3347]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3317, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3350]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3351]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3348]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3349]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3449]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3450]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3420, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3453]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3454]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3451]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3452]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3552]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3553]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3523, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3556]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3557]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3554]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3555]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3655]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3656]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3626, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3659]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3660]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3657]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3658]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3673, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3922, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3970, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe) 
            << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3234, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3232, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3337, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3335, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3440, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3438, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3543, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3541, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3646, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3644, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3788, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv 
        = (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i)));
    if ((IData)((3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we)))) {
        ++(vlSelf->__Vcoverage[3071]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[3072]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we)))) {
        ++(vlSelf->__Vcoverage[3073]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 3067, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe 
        = (3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3196, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3194, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3212]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3213]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3210]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3211]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3299, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3297, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3315]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3316]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3313]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3314]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3402, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3400, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3418]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3419]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3416]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3417]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3505, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3503, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3521]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3522]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3519]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3520]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3608, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3606, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3624]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3625]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3622]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3623]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3800, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o 
        = (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3065, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
        = ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q) 
               << 0x0000000aU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
                                  << 9U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q) 
                                              << 5U) 
                                             | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
                                                 << 4U) 
                                                | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q)))) 
            << 0x00000010U) | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q) 
                                 << 0x0000000cU) | 
                                ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q) 
                                 << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q) 
                                             << 4U) 
                                            | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3168, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3178, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3271, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3281, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3374, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3384, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3477, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3487, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3580, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3590, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3794, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2593, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2601, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2603, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2611, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2613, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2621, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2629, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2637, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2645, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3683, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2112, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2120, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2122, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2130, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2132, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2140, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2148, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2156, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2164, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3693, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
              << 3U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
              << 3U));
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1031, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1039, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1041, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1049, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1051, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1059, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1067, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1075, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1083, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1125, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1133, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1135, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1143, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1145, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1153, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1161, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1169, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1177, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000013U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000012U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000011U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000010U));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1332, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1394]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1395]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1392]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1393]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1441, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1495]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1496]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1493]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1494]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1540, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1594]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1595]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1592]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1593]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1639, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1693]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
    } else {
        ++(vlSelf->__Vcoverage[1694]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
        ++(vlSelf->__Vcoverage[1691]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i)))) {
        ++(vlSelf->__Vcoverage[1692]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1344, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1445, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1544, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1643, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d 
        = ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
             << 3U) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
                       << 2U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
                                   << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o)));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1243, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
           & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
              >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low 
        = (0x0000000fU & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d)) 
                          & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                             >> 0x0000000cU)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q)) 
              & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d)) 
              & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 4U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg 
        = (0x00000100U | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                           << 9U) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q) 
                                      << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1291, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1299, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1275, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1283, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
              | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high) 
                 | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low))));
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1185, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1193, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1195, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1203, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1235, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1091, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1099, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1101, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1109, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 673, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__intr_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2172, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2180, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2182, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2190, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 28, vlSelfRef.gpio_tb__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__intr_gpio_o;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2653, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2661, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2663, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2671, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                          >> 9U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                 >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                          >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d 
        = (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3812, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3810, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3914, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3962, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3868, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3866, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3934, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3942, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3982, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3990, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3886, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3884, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2967, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2951, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs));
        ++(vlSelf->__Vcoverage[3121]);
    } else if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                   << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs)));
        ++(vlSelf->__Vcoverage[3122]);
    } else if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                    << 0x0000000cU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                                       << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                                                   << 4U) 
                                                  | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs))));
        ++(vlSelf->__Vcoverage[3123]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[3124]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: gpio_reg_core.sv:362: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"gpio_tb.u_gpio.u_gpio_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/rtl/gpio_reg_core.sv", 362, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[3125]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3848, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3846, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3864]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3865]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3862]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3863]);
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2835, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3820, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3830, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2765, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
        = (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata)) 
            << 2U) | (QData)((IData)((1U | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) 
                                            << 1U)))));
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2525, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2589, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2591, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2366, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2430, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2432, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
        = (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                   >> 2U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i 
        = (1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 1U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i 
        = (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp)));
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4446, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4510, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i;
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))))) {
        ++(vlSelf->__Vcoverage[4873]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                     >> 0x0000000cU))))) {
        ++(vlSelf->__Vcoverage[4874]);
    }
    if (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
          >> 0x0000000cU) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))) {
        ++(vlSelf->__Vcoverage[4875]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) {
        ++(vlSelf->__Vcoverage[4876]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4444, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
               << 1U) | (1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                  | ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                      >> 0x0000000cU) 
                                     & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i)))))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                        << 0x00000029U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                            << 0x00000021U) 
                                           | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
              << 0x00000010U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | (((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                         << 0x00000029U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                             << 0x00000021U) 
                                            | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
               >> 0x00000010U) | ((IData)(((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                                             << 0x00000029U) 
                                            | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                                << 0x00000021U) 
                                               | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata)))) 
                                           >> 0x00000020U)) 
                                  << 0x00000010U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                                            >> 2U)));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4741, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4743, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4749, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4755, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4759, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4775, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4777, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4841, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4855, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4869, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4871, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5193, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5195, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5201, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5207, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5211, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5227, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5229, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5293, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5307, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5321, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5323, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5457, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl;
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5325, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5327, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5333, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5339, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5343, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5359, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5361, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5425, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5439, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5453, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4690]);
    }
    if ((1U & (~ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4691]);
    }
    if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU)))) {
        ++(vlSelf->__Vcoverage[4692]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4693]);
    }
    if ((1U & (~ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4694]);
    }
    if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[4695]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack 
        = (IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4220, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4222, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4228, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4234, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4238, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4254, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4256, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4320, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4334, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4348, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4350, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack 
        = (IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0200U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4696]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4697]);
    }
    if (((0U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                       >> 9U))) & (1U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U))))) {
        ++(vlSelf->__Vcoverage[4698]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4699]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0800U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4700]);
    }
    if ((4U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[4701]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4702]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4514, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U)))));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1980, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1982, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1988, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1994, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1998, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2014, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2016, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2080, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2094, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2108, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2110, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4686, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4688, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err 
            = (0U != (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
        if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4881]);
        }
        if ((0x10000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4882]);
        }
        if ((IData)((0U == (0x30000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])))) {
            ++(vlSelf->__Vcoverage[4883]);
        }
        ++(vlSelf->__Vcoverage[4884]);
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err = 0U;
        ++(vlSelf->__Vcoverage[4885]);
    }
    ++(vlSelf->__Vcoverage[4886]);
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 899, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 901, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 907, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 913, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 917, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 933, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 935, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 999, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1013, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1027, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1029, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__tl_o[0U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__tl_o[1U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__tl_o[2U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4654, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    if ((0U != (((vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                  ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[0U]) 
                 | (vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                    ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[1U])) 
                | (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                   ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[2U])))) {
        VL_COV_TOGGLE_CHG_ST_W(66, vlSelf->__Vcoverage + 502, vlSelfRef.gpio_tb__DOT__tl_o, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[0U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[0U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[1U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[1U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[2U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[2U];
    }
    vlSelfRef.gpio_tb__DOT__tl_o_d_valid = (1U & (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                                                  >> 1U));
    vlSelfRef.gpio_tb__DOT__tl_o_d_opcode = (7U & (
                                                   (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                                                      >> 0x0000001eU)));
    vlSelfRef.gpio_tb__DOT__tl_o_d_data = ((vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                                            << 0x00000010U) 
                                           | (vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                                              >> 0x00000010U));
    vlSelfRef.gpio_tb__DOT__tl_o_d_error = (1U & (vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                                                  >> 1U));
    vlSelfRef.gpio_tb__DOT__tl_o_a_ready = (1U & vlSelfRef.gpio_tb__DOT__tl_o[0U]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4703]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4704]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req)))) {
        ++(vlSelf->__Vcoverage[4705]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4706]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4707]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req)))) {
        ++(vlSelf->__Vcoverage[4708]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4650, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
           & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
           & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_valid) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 208, vlSelfRef.gpio_tb__DOT__tl_o_d_valid, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_valid;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_opcode) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 210, vlSelfRef.gpio_tb__DOT__tl_o_d_opcode, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_opcode;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__tl_o_d_data 
                ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 216, vlSelfRef.gpio_tb__DOT__tl_o_d_data, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 280, vlSelfRef.gpio_tb__DOT__tl_o_d_error, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_error;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_a_ready) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 282, vlSelfRef.gpio_tb__DOT__tl_o_a_ready, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready 
            = vlSelfRef.gpio_tb__DOT__tl_o_a_ready;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4360, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2198, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) {
        ++(vlSelf->__Vcoverage[2434]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) {
        ++(vlSelf->__Vcoverage[2435]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we))))) {
        ++(vlSelf->__Vcoverage[2436]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2200, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000cULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__1
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
                = ((0x7eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
                   | (IData)((0U != (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))));
            if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3749]);
            }
            if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3750]);
            }
            if ((IData)((0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
                ++(vlSelf->__Vcoverage[3751]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
                = ((0x7dU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
                   | ((IData)((0U != (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
                      << 1U));
            if ((0x00000010U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3762]);
            }
            if ((8U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3763]);
            }
            if ((IData)((0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
                ++(vlSelf->__Vcoverage[3764]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
                = ((0x7bU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
                   | ((IData)((0U != (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
                      << 2U));
            if ((0x00000040U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3775]);
            }
            if ((0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3776]);
            }
            if ((IData)((0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
                ++(vlSelf->__Vcoverage[3777]);
            }
        }
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__2
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
                = ((0x7eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
                   | (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                            >> 1U)));
            if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
                ++(vlSelf->__Vcoverage[3753]);
            }
            if ((IData)((0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
                ++(vlSelf->__Vcoverage[3754]);
            }
            if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                          >> 1U)))) {
                ++(vlSelf->__Vcoverage[3755]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
                = ((0x7dU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
                   | (2U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                            >> 2U)));
            if ((8U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
                ++(vlSelf->__Vcoverage[3766]);
            }
            if ((IData)((0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
                ++(vlSelf->__Vcoverage[3767]);
            }
            if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                          >> 3U)))) {
                ++(vlSelf->__Vcoverage[3768]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
                = ((0x7bU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
                   | (4U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                            >> 3U)));
            if ((0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
                ++(vlSelf->__Vcoverage[3779]);
            }
            if ((IData)((0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
                ++(vlSelf->__Vcoverage[3780]);
            }
            if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                          >> 5U)))) {
                ++(vlSelf->__Vcoverage[3781]);
            }
        }
    }
    if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_comb__TOP__0
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
                VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3707, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
            }
        }
    }
    if ((0x0000000000000013ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_comb__TOP__1
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
                VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3721, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
            }
        }
    }
}

void Vtop___024root___nba_sequent__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__15\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) {
            ++(vlSelf->__Vcoverage[4711]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = 1U;
        } else if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack) {
            ++(vlSelf->__Vcoverage[4709]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = 0U;
        } else {
            ++(vlSelf->__Vcoverage[4710]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4712]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4713]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4714]);
    }
    ++(vlSelf->__Vcoverage[4715]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) {
            if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
                  | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)) 
                 | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req))) {
                ++(vlSelf->__Vcoverage[4730]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_1 = 0xffffffffU;
            } else {
                ++(vlSelf->__Vcoverage[4731]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_1 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_1;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q 
                = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
                   | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal));
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) {
                ++(vlSelf->__Vcoverage[4726]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
                ++(vlSelf->__Vcoverage[4727]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) {
                ++(vlSelf->__Vcoverage[4728]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i)) 
                        & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal))) 
                       & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req))))) {
                ++(vlSelf->__Vcoverage[4729]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
                ++(vlSelf->__Vcoverage[4732]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) {
                ++(vlSelf->__Vcoverage[4733]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i)) 
                       & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal))))) {
                ++(vlSelf->__Vcoverage[4734]);
            }
            ++(vlSelf->__Vcoverage[4735]);
        } else {
            ++(vlSelf->__Vcoverage[4736]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4737]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4738]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4739]);
    }
    ++(vlSelf->__Vcoverage[4740]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) {
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) {
                ++(vlSelf->__Vcoverage[4718]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_0 = 1U;
            } else {
                ++(vlSelf->__Vcoverage[4719]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_0 = 0U;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q 
                = (0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                   << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                             >> 0x0000001cU)));
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q 
                = (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                         >> 4U));
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) {
                ++(vlSelf->__Vcoverage[4716]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req)))) {
                ++(vlSelf->__Vcoverage[4717]);
            }
            ++(vlSelf->__Vcoverage[4720]);
        } else {
            ++(vlSelf->__Vcoverage[4721]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4722]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4723]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4724]);
    }
    ++(vlSelf->__Vcoverage[4725]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4512, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__outstanding_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4582, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4646, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4660, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqid_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4676, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__reqsz_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4680, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rspop_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4518, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4648, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error;
    }
}

void Vtop___024root___nba_sequent__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[1324]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d;
    } else {
        ++(vlSelf->__Vcoverage[1323]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)))) {
        ++(vlSelf->__Vcoverage[1325]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[1326]);
    }
    ++(vlSelf->__Vcoverage[1327]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        if ((0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)) {
            ++(vlSelf->__Vcoverage[1311]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q 
                = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x00000015U));
        } else {
            ++(vlSelf->__Vcoverage[1312]);
        }
    } else {
        ++(vlSelf->__Vcoverage[1313]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)))) {
        ++(vlSelf->__Vcoverage[1314]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[1315]);
    }
    ++(vlSelf->__Vcoverage[1316]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        if ((0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)) {
            ++(vlSelf->__Vcoverage[1317]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q 
                = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x0000001aU));
        } else {
            ++(vlSelf->__Vcoverage[1318]);
        }
    } else {
        ++(vlSelf->__Vcoverage[1319]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)))) {
        ++(vlSelf->__Vcoverage[1320]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[1321]);
    }
    ++(vlSelf->__Vcoverage[1322]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1251, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1259, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1267, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1219, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1227, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 657, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__cio_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 665, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o;
    }
    vlSelfRef.gpio_tb__DOT__cio_gpio_en_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 12, vlSelfRef.gpio_tb__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__cio_gpio_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 20, vlSelfRef.gpio_tb__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__cio_gpio_en_o;
    }
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
        = ((((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q) 
               << 0x0000000aU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
                                  << 9U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q) 
                                              << 5U) 
                                             | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
                                                 << 4U) 
                                                | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q)))) 
            << 0x00000010U) | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q) 
                                 << 0x0000000cU) | 
                                ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q) 
                                 << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q) 
                                             << 4U) 
                                            | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q))));
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2593, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2601, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2603, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2611, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2613, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2621, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2629, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2637, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2645, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2112, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2120, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2122, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2130, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2132, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2140, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2148, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2156, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2164, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1031, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1039, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1041, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1049, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1051, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1059, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1067, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1075, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1083, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1125, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1133, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000019U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000019U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3dffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000015U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1135, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1143, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000014U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000014U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fefffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x00000010U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1145, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000f0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000000cU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1153, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000000cU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000000cU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fff0fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 8U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1161, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 8U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1169, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1177, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000013U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000012U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000011U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i 
        = (1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 0x00000010U));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1332, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1441, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1540, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1639, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i;
    }
}

void Vtop___024root___nba_comb__TOP__10(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__10\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q)) 
              & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q) 
           & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d)) 
              & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                 >> 4U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg 
        = (0x00000100U | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                           << 9U) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q) 
                                      << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1275, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1283, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
              | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high) 
                 | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low))));
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1185, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1193, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1195, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1203, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1235, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1091, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1099, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1101, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1109, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 673, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__intr_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2172, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2180, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2182, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2190, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 28, vlSelfRef.gpio_tb__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__intr_gpio_o;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2653, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2661, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 8U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 8U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1effU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00000100U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2663, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2671, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                          >> 9U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                 >> 8U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                          >> 4U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d 
        = (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3812, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3810, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3914, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3962, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3868, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3866, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3934, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3942, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3982, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3990, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3886, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3884, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2967, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2951, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3848, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3846, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3820, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe;
    }
}

void Vtop___024root___nba_comb__TOP__11(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs));
        ++(vlSelf->__Vcoverage[3121]);
    } else if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                   << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs)));
        ++(vlSelf->__Vcoverage[3122]);
    } else if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                    << 0x0000000cU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                                       << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                                                   << 4U) 
                                                  | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs))));
        ++(vlSelf->__Vcoverage[3123]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[3124]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: gpio_reg_core.sv:362: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"gpio_tb.u_gpio.u_gpio_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-tlul/runs/gpio/release/rtl/gpio_reg_core.sv", 362, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[3125]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3864]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3865]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3862]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3863]);
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2835, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3830, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2765, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
        = (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata)) 
            << 2U) | (QData)((IData)((1U | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) 
                                            << 1U)))));
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2525, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2589, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2591, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2366, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2430, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2432, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_reg_rsp) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
        = (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                   >> 2U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i 
        = (1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                         >> 1U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i 
        = (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp)));
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4446, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rdata_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4510, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__error_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4444, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__busy_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i;
    }
}

void Vtop___024root___nba_comb__TOP__12(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__12\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))))) {
        ++(vlSelf->__Vcoverage[4873]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q)) 
               & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                     >> 0x0000000cU))))) {
        ++(vlSelf->__Vcoverage[4874]);
    }
    if (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
          >> 0x0000000cU) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i))) {
        ++(vlSelf->__Vcoverage[4875]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) {
        ++(vlSelf->__Vcoverage[4876]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error) 
               << 1U) | (1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                  | ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                      >> 0x0000000cU) 
                                     & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i)))))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
        = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]) 
           | ((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                        << 0x00000029U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                            << 0x00000021U) 
                                           | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
              << 0x00000010U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | (((IData)((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                         << 0x00000029U) | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                             << 0x00000021U) 
                                            | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata))))) 
               >> 0x00000010U) | ((IData)(((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q)) 
                                             << 0x00000029U) 
                                            | (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q)) 
                                                << 0x00000021U) 
                                               | (QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata)))) 
                                           >> 0x00000020U)) 
                                  << 0x00000010U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
        = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
              << 0x0000001eU));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q) 
                                 << 1U)) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q) 
                                            >> 2U)));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4741, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4743, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4749, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4755, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4759, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4775, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4777, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4841, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4855, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4869, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4871, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o_pre[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl 
        = (1U & VL_REDXOR_32(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]) 
                              ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U])));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5193, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5195, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5201, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5207, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5211, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5227, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5229, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5293, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5307, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5321, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5323, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_i[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5457, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__unused_tl 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl;
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5325, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5327, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 5333, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5339, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5343, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5359, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5361, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5425, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 5439, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5453, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U];
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4690]);
    }
    if ((1U & (~ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]))) {
        ++(vlSelf->__Vcoverage[4691]);
    }
    if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                  >> 0x0000000cU)))) {
        ++(vlSelf->__Vcoverage[4692]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4693]);
    }
    if ((1U & (~ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]))) {
        ++(vlSelf->__Vcoverage[4694]);
    }
    if ((1U & (~ (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[4695]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack 
        = (IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                    >> 1U) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U]));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4220, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4222, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4228, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4234, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4238, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4254, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4256, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4320, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 4334, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4348, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4350, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack 
        = (IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                    >> 0x0000000cU) & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U]));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__d_ack 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0200U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4696]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4697]);
    }
    if (((0U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                       >> 9U))) & (1U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U))))) {
        ++(vlSelf->__Vcoverage[4698]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4699]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         & (0x0800U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])))) {
        ++(vlSelf->__Vcoverage[4700]);
    }
    if ((4U != (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                      >> 9U)))) {
        ++(vlSelf->__Vcoverage[4701]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack)))) {
        ++(vlSelf->__Vcoverage[4702]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4514, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__a_ack 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & (0x0800U == (0x0e00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U])));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                                >> 9U)))));
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1980, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1982, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 1988, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1994, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1998, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2014, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2016, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2080, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 2094, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2108, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2110, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4686, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rd_req 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4688, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__wr_req 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err 
            = (0U != (3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                            >> 0x0000001cU)));
        if ((0x20000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4881]);
        }
        if ((0x10000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])) {
            ++(vlSelf->__Vcoverage[4882]);
        }
        if ((IData)((0U == (0x30000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U])))) {
            ++(vlSelf->__Vcoverage[4883]);
        }
        ++(vlSelf->__Vcoverage[4884]);
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err = 0U;
        ++(vlSelf->__Vcoverage[4885]);
    }
    ++(vlSelf->__Vcoverage[4886]);
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 899, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                        << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x0000001eU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                          << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001eU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 901, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x0000001eU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
                                 << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001eU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0x3fffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0xc0000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U] 
            = ((2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[2U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U]));
    }
    if ((0U != (7U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x0000001bU)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                          << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x0000001bU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 907, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x0000001bU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 5U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x0000001bU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xc7ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x38000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (3U & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x00000019U)) 
                      ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                          << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                    >> 0x00000019U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 913, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                           >> 0x00000019U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 7U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                           >> 0x00000019U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xf9ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x06000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (0x000000ffU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000011U)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 917, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000011U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x0000000fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 >> 0x00000011U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xfe01ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x01fe0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0x00010000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 933, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                >> 0x00000010U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                                  >> 0x00000010U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xfffeffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x00010000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                  << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                     >> 0x00000010U)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                    << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                       >> 0x00000010U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 935, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 0x00000010U)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
                                 << 0x00000010U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                 >> 0x00000010U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U] 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[1U]) 
               | (0x0000ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 9U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                             << 0x00000017U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                               >> 9U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 999, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x00000017U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 9U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                            << 0x00000017U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                              >> 9U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xffff01ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0x0000fe00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((0U != (0x0000007fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                             << 0x0000001eU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                               >> 2U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 1013, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffe03U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (0x000001fcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1027, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1029, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__tl_o[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U]));
    }
    vlSelfRef.gpio_tb__DOT__tl_o[0U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U];
    vlSelfRef.gpio_tb__DOT__tl_o[1U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U];
    vlSelfRef.gpio_tb__DOT__tl_o[2U] = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U];
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4654, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__addr_align_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err;
    if ((0U != (((vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                  ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[0U]) 
                 | (vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                    ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[1U])) 
                | (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                   ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[2U])))) {
        VL_COV_TOGGLE_CHG_ST_W(66, vlSelf->__Vcoverage + 502, vlSelfRef.gpio_tb__DOT__tl_o, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[0U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[0U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[1U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[1U];
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o[2U] 
            = vlSelfRef.gpio_tb__DOT__tl_o[2U];
    }
    vlSelfRef.gpio_tb__DOT__tl_o_d_valid = (1U & (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                                                  >> 1U));
    vlSelfRef.gpio_tb__DOT__tl_o_d_opcode = (7U & (
                                                   (vlSelfRef.gpio_tb__DOT__tl_o[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                                                      >> 0x0000001eU)));
    vlSelfRef.gpio_tb__DOT__tl_o_d_data = ((vlSelfRef.gpio_tb__DOT__tl_o[1U] 
                                            << 0x00000010U) 
                                           | (vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                                              >> 0x00000010U));
    vlSelfRef.gpio_tb__DOT__tl_o_d_error = (1U & (vlSelfRef.gpio_tb__DOT__tl_o[0U] 
                                                  >> 1U));
    vlSelfRef.gpio_tb__DOT__tl_o_a_ready = (1U & vlSelfRef.gpio_tb__DOT__tl_o[0U]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4703]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4704]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req)))) {
        ++(vlSelf->__Vcoverage[4705]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)))) {
        ++(vlSelf->__Vcoverage[4706]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) {
        ++(vlSelf->__Vcoverage[4707]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req)))) {
        ++(vlSelf->__Vcoverage[4708]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4650, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__err_internal 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req) 
           & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req) 
           & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_valid) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 208, vlSelfRef.gpio_tb__DOT__tl_o_d_valid, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_valid 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_valid;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_opcode) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 210, vlSelfRef.gpio_tb__DOT__tl_o_d_opcode, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_opcode 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_opcode;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__tl_o_d_data 
                ^ vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 216, vlSelfRef.gpio_tb__DOT__tl_o_d_data, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_data 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_d_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 280, vlSelfRef.gpio_tb__DOT__tl_o_d_error, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_d_error 
            = vlSelfRef.gpio_tb__DOT__tl_o_d_error;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__tl_o_a_ready) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 282, vlSelfRef.gpio_tb__DOT__tl_o_a_ready, vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready);
        vlSelfRef.gpio_tb__DOT____Vtogcov__tl_o_a_ready 
            = vlSelfRef.gpio_tb__DOT__tl_o_a_ready;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4360, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__re_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__we_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2198, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) {
        ++(vlSelf->__Vcoverage[2434]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re) {
        ++(vlSelf->__Vcoverage[2435]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we))))) {
        ++(vlSelf->__Vcoverage[2436]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2200, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_tlul_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we;
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000180000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1743]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[1742]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1744]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1745]);
            }
            ++(vlSelf->__Vcoverage[1746]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1740, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o;
            }
        }
    }
    if ((0x0060000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5489]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5488]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5490]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5491]);
            }
            ++(vlSelf->__Vcoverage[5492]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5486, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5467, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq;
            }
        }
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5523]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5522]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5524]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5525]);
            }
            ++(vlSelf->__Vcoverage[5526]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5520, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5501, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq;
            }
        }
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__3
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1433]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1432]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1434]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1435]);
            }
            ++(vlSelf->__Vcoverage[1436]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1430, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1406, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0000000000060000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__4
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1532]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1531]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1533]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1534]);
            }
            ++(vlSelf->__Vcoverage[1535]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1529, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1507, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0000000001800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__5
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1631]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1630]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1632]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1633]);
            }
            ++(vlSelf->__Vcoverage[1634]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1628, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1606, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0000000060000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__6
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1730]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1729]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1731]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1732]);
            }
            ++(vlSelf->__Vcoverage[1733]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1727, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1705, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__7
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5478]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[5477]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5479]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5480]);
            }
            ++(vlSelf->__Vcoverage[5481]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5475, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5463, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1119, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1123, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1736, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__8
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1382]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1381]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1383]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1384]);
            }
            ++(vlSelf->__Vcoverage[1385]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1371]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1370]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1372]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1373]);
            }
            ++(vlSelf->__Vcoverage[1374]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1375]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1376]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1377]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1378]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1379]);
            }
            ++(vlSelf->__Vcoverage[1380]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1346, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1364, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000000006000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__9
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1483]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1482]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1484]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1485]);
            }
            ++(vlSelf->__Vcoverage[1486]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1472]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1471]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1473]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1474]);
            }
            ++(vlSelf->__Vcoverage[1475]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1476]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1477]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1478]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1479]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1480]);
            }
            ++(vlSelf->__Vcoverage[1481]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1447, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1463, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1465, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000000180000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__10
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1582]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1581]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1583]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1584]);
            }
            ++(vlSelf->__Vcoverage[1585]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1571]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1570]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1572]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1573]);
            }
            ++(vlSelf->__Vcoverage[1574]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1575]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1576]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1577]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1578]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1579]);
            }
            ++(vlSelf->__Vcoverage[1580]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1546, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1562, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1564, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000006000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__11
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1681]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1680]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1682]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1683]);
            }
            ++(vlSelf->__Vcoverage[1684]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1670]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1669]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1671]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1672]);
            }
            ++(vlSelf->__Vcoverage[1673]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1674]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1675]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1676]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1677]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1678]);
            }
            ++(vlSelf->__Vcoverage[1679]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1645, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1661, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1663, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000001800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__12
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[2911]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[2912]);
                }
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[2913]);
                }
                if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err)))) {
                    ++(vlSelf->__Vcoverage[2915]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2916]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2917]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2918]);
            }
            ++(vlSelf->__Vcoverage[2919]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
                ++(vlSelf->__Vcoverage[2920]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) {
                ++(vlSelf->__Vcoverage[2922]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q)) 
                       & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
                ++(vlSelf->__Vcoverage[2923]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2909, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o 
                = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) 
                   | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2679, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o;
            }
        }
    }
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__13
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5512]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[5511]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5513]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5514]);
            }
            ++(vlSelf->__Vcoverage[5515]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5509, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5497, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1117, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1760, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2439, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3671, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3691, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000600000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__14
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1754]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[1753]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1755]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1756]);
            }
            ++(vlSelf->__Vcoverage[1757]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1751, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1307, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1330, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1439, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1538, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1637, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1398, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1499, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1598, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1697, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1426, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1525, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1624, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1723, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
        }
    }
    if ((0x0006000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((0x0001800000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__16
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3856]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3857]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3858]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3859]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3860]);
            }
            ++(vlSelf->__Vcoverage[3861]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3822, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3876, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3838, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3894, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2939, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs;
            }
        }
    }
    if ((0x0000000000000060ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__17(vlSelf);
    }
    if ((0x0000000000000600ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__18
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1420]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1419]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1421]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1422]);
            }
            ++(vlSelf->__Vcoverage[1423]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1417, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1402, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1368, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000000000018000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__19
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1519]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1518]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1520]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1521]);
            }
            ++(vlSelf->__Vcoverage[1522]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1503, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1469, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__20
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1618]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1617]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1619]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1620]);
            }
            ++(vlSelf->__Vcoverage[1621]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1615, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1602, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1568, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000000018000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__21
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1717]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1716]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1718]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1719]);
            }
            ++(vlSelf->__Vcoverage[1720]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1714, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1701, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1667, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000006000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__22
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3204]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3205]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3206]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3207]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3208]);
            }
            ++(vlSelf->__Vcoverage[3209]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3170, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3224, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3186, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3212]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3213]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3210]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3211]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3249, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3049, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3178, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds;
            }
        }
    }
    if ((0x0000018000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__23
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3307]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3308]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3309]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3310]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3311]);
            }
            ++(vlSelf->__Vcoverage[3312]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3273, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3327, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3289, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3315]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3316]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3313]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3314]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3352, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3033, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3281, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds;
            }
        }
    }
    if ((0x0000060000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__24
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3410]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3411]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3412]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3413]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3414]);
            }
            ++(vlSelf->__Vcoverage[3415]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3376, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3430, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3392, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3418]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3419]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3416]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3417]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3017, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3384, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds;
            }
        }
    }
    if ((0x0000180000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__25
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3513]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3514]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3515]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3516]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3517]);
            }
            ++(vlSelf->__Vcoverage[3518]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3479, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3533, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3495, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3521]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3522]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3519]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3520]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3558, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3001, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3487, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds;
            }
        }
    }
    if ((0x0000600000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__26
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3616]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3617]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3618]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3619]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3620]);
            }
            ++(vlSelf->__Vcoverage[3621]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3582, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3636, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3598, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3624]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3625]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3622]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3623]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3661, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2985, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3590, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds;
            }
        }
    }
    if ((0x0060000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__27
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5473, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__28
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5507, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__29
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1749, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__30
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4000, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3808, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3148, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3259, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3465, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3568, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4889, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000180000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__31
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1309, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni;
            }
        }
    }
    if ((0x0000000600000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__32
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1413, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1512, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1611, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1710, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__33
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1415, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000000000000780ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1388]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1391]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1389]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1390]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q)));
                }
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1386]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1387]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1354, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1366, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x0000000000060000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__34
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1514, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x000000000001e000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__1
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1489]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1492]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1490]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1491]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q)));
                }
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1487]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1488]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1455, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1467, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x0000000001800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__35
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1613, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000000000780000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__2
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1588]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1591]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1589]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1590]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q)));
                }
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1586]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1587]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1554, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1566, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x0000000060000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__36
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1712, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x000000001e000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__3
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1687]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1690]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1688]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1689]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q)));
                }
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1685]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1686]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1653, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1665, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x00007fe000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__4(vlSelf);
    }
    if ((0x00007fe000000780ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__5
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1394]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1395]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1392]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1393]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1344, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x00007fe00001e000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__6
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1495]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1496]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1493]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1494]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1445, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x00007fe000780000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__7
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1594]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1595]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1592]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1593]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1544, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x00007fe01e000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__8
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1693]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1694]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1691]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1692]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1643, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x00007fe01e79e780ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__9
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d 
                = ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
                     << 3U) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
                               << 2U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
                                           << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o)));
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1243, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high 
                = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                   & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                      >> 8U));
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low 
                = (0x0000000fU & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d)) 
                                  & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                     >> 0x0000000cU)));
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1291, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1299, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low;
            }
        }
    }
    if ((0x00007fe01e79e7e0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__10(vlSelf);
    }
    if ((0x0001ffe01e79e7e0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__11(vlSelf);
    }
    if ((0x0007ffe01e79e7e0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__12(vlSelf);
    }
}
