// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 2> &in) {
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
    } while ((2U > n));
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
        ++(vlSelf->__Vcoverage[3137]);
    }
    if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3138]);
    }
    if ((IData)((6U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3139]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 2U)) & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3140]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 1U)) & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3141]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7dU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (2U & ((IData)(((0U != (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x18U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 1U)));
    if ((0x00000010U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3150]);
    }
    if ((8U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3151]);
    }
    if ((IData)((0x18U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3152]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 4U)) & (0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3153]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 3U)) & (0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3154]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree 
        = ((0x7bU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)) 
           | (4U & ((IData)(((0U != (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) 
                             | (0x60U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) 
                    << 2U)));
    if ((0x00000040U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3163]);
    }
    if ((0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree))) {
        ++(vlSelf->__Vcoverage[3164]);
    }
    if ((IData)((0x60U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[3165]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 6U)) & (0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3166]);
    }
    if ((IData)(((~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                     >> 5U)) & (0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree)))))) {
        ++(vlSelf->__Vcoverage[3167]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3115, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__err_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree;
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__1
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
                = ((0x7eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
                   | (IData)((0U != (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))));
            if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3129]);
            }
            if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3130]);
            }
            if ((IData)((0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
                ++(vlSelf->__Vcoverage[3131]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
                = ((0x7dU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
                   | ((IData)((0U != (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
                      << 1U));
            if ((0x00000010U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3142]);
            }
            if ((8U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3143]);
            }
            if ((IData)((0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
                ++(vlSelf->__Vcoverage[3144]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
                = ((0x7bU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
                   | ((IData)((0U != (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
                      << 2U));
            if ((0x00000040U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3155]);
            }
            if ((0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
                ++(vlSelf->__Vcoverage[3156]);
            }
            if ((IData)((0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
                ++(vlSelf->__Vcoverage[3157]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
                VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3087, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
            }
        }
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        {
            // Inlined CFunc: _act_sequent__TOP__2
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
                = ((0x7eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
                   | (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                            >> 1U)));
            if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
                ++(vlSelf->__Vcoverage[3133]);
            }
            if ((IData)((0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
                ++(vlSelf->__Vcoverage[3134]);
            }
            if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                          >> 1U)))) {
                ++(vlSelf->__Vcoverage[3135]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
                = ((0x7dU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
                   | (2U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                            >> 2U)));
            if ((8U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
                ++(vlSelf->__Vcoverage[3146]);
            }
            if ((IData)((0U == (0x18U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
                ++(vlSelf->__Vcoverage[3147]);
            }
            if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                          >> 3U)))) {
                ++(vlSelf->__Vcoverage[3148]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
                = ((0x7bU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
                   | (4U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                            >> 3U)));
            if ((0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
                ++(vlSelf->__Vcoverage[3159]);
            }
            if ((IData)((0U == (0x60U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
                ++(vlSelf->__Vcoverage[3160]);
            }
            if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                          >> 5U)))) {
                ++(vlSelf->__Vcoverage[3161]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
                VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3101, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
            }
        }
    }
}

void Vtop___024root___nba_sequent__TOP__16(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[5218]);
        } else {
            ++(vlSelf->__Vcoverage[5217]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n;
        }
        if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock)))) {
            ++(vlSelf->__Vcoverage[5219]);
        }
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[5220]);
        }
    } else {
        ++(vlSelf->__Vcoverage[5221]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5222]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5223]);
    }
    ++(vlSelf->__Vcoverage[5224]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5211]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n;
        ++(vlSelf->__Vcoverage[5213]);
    } else {
        ++(vlSelf->__Vcoverage[5212]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5214]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5215]);
    }
    ++(vlSelf->__Vcoverage[5216]);
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5168, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q 
            = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q)));
    }
    if ((2U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5170, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_q)) 
               | (2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q)));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__write_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5154, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__write_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__read_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5150, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__read_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q) 
                 >> (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q)));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__status_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5160, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__status_cnt_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o 
        = (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o 
        = (2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__data_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5142, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__data_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__data_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__usage_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5136, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__usage_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__usage_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5134, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__empty_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__empty_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5132, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__full_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__full_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3901, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_out);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_out 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out) {
        ++(vlSelf->__Vcoverage[4120]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____VlemCond_0 = 2U;
    } else {
        ++(vlSelf->__Vcoverage[4121]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
        = ((0x0000019fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
           | ((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____VlemCond_0)) 
              << 0x00000025U));
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out) {
        ++(vlSelf->__Vcoverage[4118]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out)))) {
        ++(vlSelf->__Vcoverage[4119]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty)))) {
        ++(vlSelf->__Vcoverage[4116]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty) {
        ++(vlSelf->__Vcoverage[4117]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3897, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_empty);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_empty 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3895, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_full);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_full 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full;
    }
}

void Vtop___024root___nba_sequent__TOP__17(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[949]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d;
    } else {
        ++(vlSelf->__Vcoverage[948]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)))) {
        ++(vlSelf->__Vcoverage[950]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[951]);
    }
    ++(vlSelf->__Vcoverage[952]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        if ((0x00100000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)) {
            ++(vlSelf->__Vcoverage[936]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q 
                = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x00000015U));
        } else {
            ++(vlSelf->__Vcoverage[937]);
        }
    } else {
        ++(vlSelf->__Vcoverage[938]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)))) {
        ++(vlSelf->__Vcoverage[939]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[940]);
    }
    ++(vlSelf->__Vcoverage[941]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        if ((0x02000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)) {
            ++(vlSelf->__Vcoverage[942]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q 
                = (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x0000001aU));
        } else {
            ++(vlSelf->__Vcoverage[943]);
        }
    } else {
        ++(vlSelf->__Vcoverage[944]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni)))) {
        ++(vlSelf->__Vcoverage[945]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) {
        ++(vlSelf->__Vcoverage[946]);
    }
    ++(vlSelf->__Vcoverage[947]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 876, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 884, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_o_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 892, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__gpio_oe_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 844, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 852, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__cio_gpio_en_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 440, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__cio_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 448, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__cio_gpio_en_o);
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

void Vtop___024root___nba_sequent__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[4988]);
        } else {
            ++(vlSelf->__Vcoverage[4987]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U] 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U];
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U];
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[2U] 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U];
        }
        if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock)))) {
            ++(vlSelf->__Vcoverage[4989]);
        }
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[4990]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4991]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U] = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[2U] = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4992]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4993]);
    }
    ++(vlSelf->__Vcoverage[4994]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4981]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n;
        ++(vlSelf->__Vcoverage[4983]);
    } else {
        ++(vlSelf->__Vcoverage[4982]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4984]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4985]);
    }
    ++(vlSelf->__Vcoverage[4986]);
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
                  << 0x0000001fU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U] 
                                     >> 1U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
                                                 << 0x0000001fU) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U] 
                                                   >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4810, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U] 
                                 >> 1U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U] 
                                              >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U]) 
               | (0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4874, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[2U] 
                  << 0x0000001eU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
                                     >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[2U] 
                                                 << 0x0000001eU) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
                                                   >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4876, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[2U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[2U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
            = ((3U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U]) 
               | (0xfffffffcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[2U] 
            = (3U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[2U]);
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4940, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_q[1U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U]));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__write_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4668, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__write_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__read_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4664, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__read_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
        = (0x00000001ffffffffULL & ((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q
                                                      [
                                                      (((IData)(0x00000020U) 
                                                        + 
                                                        (0x0000007fU 
                                                         & ((IData)(0x00000021U) 
                                                            * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)))) 
                                                       >> 5U)])) 
                                      << ((0U == (0x0000001fU 
                                                  & ((IData)(0x00000021U) 
                                                     * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q))))
                                           ? 0x00000020U
                                           : ((IData)(0x00000040U) 
                                              - (0x0000001fU 
                                                 & ((IData)(0x00000021U) 
                                                    * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)))))) 
                                     | (((0U == (0x0000001fU 
                                                 & ((IData)(0x00000021U) 
                                                    * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q))))
                                          ? 0ULL : 
                                         ((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q
                                                          [
                                                          (((IData)(0x0000001fU) 
                                                            + 
                                                            (0x0000007fU 
                                                             & ((IData)(0x00000021U) 
                                                                * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)))) 
                                                           >> 5U)])) 
                                          << ((IData)(0x00000020U) 
                                              - (0x0000001fU 
                                                 & ((IData)(0x00000021U) 
                                                    * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)))))) 
                                        | ((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q
                                                           [
                                                           (3U 
                                                            & (((IData)(0x00000021U) 
                                                                * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)) 
                                                               >> 5U))])) 
                                           >> (0x0000001fU 
                                               & ((IData)(0x00000021U) 
                                                  * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)))))) 
                                    & (- (QData)((IData)(
                                                         (0x41U 
                                                          >= 
                                                          (0x0000007fU 
                                                           & ((IData)(0x00000021U) 
                                                              * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)))))))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__status_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4674, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__status_cnt_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o 
        = (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o 
        = (2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q));
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                         >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o 
                                            >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4592, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                                                                        >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o 
            = ((1ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                                           >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4656, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o 
            = ((0x00000001fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__usage_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4522, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__usage_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__usage_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4520, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__empty_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__empty_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4518, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__full_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__full_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o;
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                         >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out 
                                            >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4001, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                                                        >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out 
            = ((1ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                           >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4065, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out 
            = ((0x00000001fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_out) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out)))));
    }
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out))) {
        ++(vlSelf->__Vcoverage[4139]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____VlemCond_1 = 2U;
    } else {
        ++(vlSelf->__Vcoverage[4140]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____VlemCond_1 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
        = ((0x000001fffffffff9ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
           | ((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____VlemCond_1)) 
              << 1U));
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out))) {
        ++(vlSelf->__Vcoverage[4137]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out)))) {
        ++(vlSelf->__Vcoverage[4138]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty)))) {
        ++(vlSelf->__Vcoverage[4141]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty) {
        ++(vlSelf->__Vcoverage[4142]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3933, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_empty);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_empty 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
        = ((0x000001fffffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
           | (IData)((IData)((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty))))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3931, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_full);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_full 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full;
    }
}

void Vtop___024root___nba_sequent__TOP__28(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__28\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[5121]);
        } else {
            ++(vlSelf->__Vcoverage[5120]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n;
        }
        if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock)))) {
            ++(vlSelf->__Vcoverage[5122]);
        }
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[5123]);
        }
    } else {
        ++(vlSelf->__Vcoverage[5124]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5125]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5126]);
    }
    ++(vlSelf->__Vcoverage[5127]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5114]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n;
        ++(vlSelf->__Vcoverage[5116]);
    } else {
        ++(vlSelf->__Vcoverage[5115]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5117]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5118]);
    }
    ++(vlSelf->__Vcoverage[5119]);
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5059, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q 
            = ((0xf0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5067, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q 
            = ((0x0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_q)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q)));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__write_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5033, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__write_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__read_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5029, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__read_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o 
        = (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q) 
                          >> ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q) 
                              << 2U)));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__status_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5039, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__status_cnt_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o 
        = (2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o 
        = (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__data_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5015, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__data_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__data_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__usage_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5003, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__usage_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__usage_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4999, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__full_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__full_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5001, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__empty_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__empty_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_out)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3919, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_out);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_out 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out) 
           << 1U);
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full)))) {
        ++(vlSelf->__Vcoverage[4132]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full) {
        ++(vlSelf->__Vcoverage[4133]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3907, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_full);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_full 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3909, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_empty);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_empty 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4071, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4079, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_req)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req)));
    }
}

void Vtop___024root___nba_sequent__TOP__30(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__30\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni) {
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[5783]);
        } else {
            ++(vlSelf->__Vcoverage[5782]);
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U] 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U];
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U];
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U];
        }
        if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock)))) {
            ++(vlSelf->__Vcoverage[5784]);
        }
        if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock) {
            ++(vlSelf->__Vcoverage[5785]);
        }
    } else {
        ++(vlSelf->__Vcoverage[5786]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U] = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5787]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5788]);
    }
    ++(vlSelf->__Vcoverage[5789]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5776]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n;
        ++(vlSelf->__Vcoverage[5778]);
    } else {
        ++(vlSelf->__Vcoverage[5777]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5779]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5780]);
    }
    ++(vlSelf->__Vcoverage[5781]);
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 >> 4U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                             << 0x0000001cU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                               >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5577, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
            = ((0xffffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U]) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                  << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U] 
                                     >> 4U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                                 << 0x0000001cU) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U] 
                                                   >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5585, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U] 
            = ((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U]) 
               | (0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U]));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U] 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U])))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5649, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U] 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[0U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                                 >> 0x0000000cU)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
                                 >> 0x0000000cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5657, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                                 >> 0x0000000cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
                                 >> 0x0000000cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U]) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                  << 0x00000014U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                     >> 0x0000000cU)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
                    << 0x00000014U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                       >> 0x0000000cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5665, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 >> 0x0000000cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                 >> 0x0000000cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U]) 
               | (0xfffff000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U] 
            = ((0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[2U]) 
               | (0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 >> 8U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5729, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U] 
                                 >> 8U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
                                              >> 8U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U] 
            = ((0xfffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_q[1U]) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U]));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__write_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5407, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__write_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__write_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__read_pointer_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5403, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__read_pointer_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__read_pointer_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
        = (0x000000ffffffffffULL & ((((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q
                                                      [
                                                      (((IData)(0x00000027U) 
                                                        + 
                                                        (0x0000007fU 
                                                         & ((IData)(0x00000028U) 
                                                            * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)))) 
                                                       >> 5U)])) 
                                      << ((0U == (0x0000001fU 
                                                  & ((IData)(0x00000028U) 
                                                     * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q))))
                                           ? 0x00000020U
                                           : ((IData)(0x00000040U) 
                                              - (0x0000001fU 
                                                 & ((IData)(0x00000028U) 
                                                    * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)))))) 
                                     | (((0U == (0x0000001fU 
                                                 & ((IData)(0x00000028U) 
                                                    * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q))))
                                          ? 0ULL : 
                                         ((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q
                                                          [
                                                          (((IData)(0x0000001fU) 
                                                            + 
                                                            (0x0000007fU 
                                                             & ((IData)(0x00000028U) 
                                                                * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)))) 
                                                           >> 5U)])) 
                                          << ((IData)(0x00000020U) 
                                              - (0x0000001fU 
                                                 & ((IData)(0x00000028U) 
                                                    * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)))))) 
                                        | ((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q
                                                           [
                                                           (3U 
                                                            & (((IData)(0x00000028U) 
                                                                * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)) 
                                                               >> 5U))])) 
                                           >> (0x0000001fU 
                                               & ((IData)(0x00000028U) 
                                                  * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)))))) 
                                    & (- (QData)((IData)(
                                                         (0x4fU 
                                                          >= 
                                                          (0x0000007fU 
                                                           & ((IData)(0x00000028U) 
                                                              * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)))))))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__status_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5413, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__status_cnt_q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__status_cnt_q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o 
        = (2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o 
        = (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q));
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5317, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
            = ((0x0000000fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5325, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
            = ((0x000000f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5389, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o 
            = ((0x000000fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__data_o) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__usage_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5233, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__usage_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__usage_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5229, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__full_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__full_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5231, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__empty_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__empty_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o;
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3811, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
            = ((0x0000000fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3819, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
            = ((0x000000f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3883, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out 
            = ((0x000000fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_out) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req 
        = (1U | (0x0000001eU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                         >> 0x00000024U)) 
                                << 1U)));
    if ((IData)(((0x0000800000000400ULL == (0x0000800000000400ULL 
                                            & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i)) 
                 & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full))))) {
        ++(vlSelf->__Vcoverage[4109]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full) {
        ++(vlSelf->__Vcoverage[4110]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                          >> 0x0000000aU))))) {
        ++(vlSelf->__Vcoverage[4111]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                          >> 0x0000002fU))))) {
        ++(vlSelf->__Vcoverage[4112]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3727, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_full);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_full 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push 
        = (IData)(((0x0000800000000400ULL == (0x0000800000000400ULL 
                                              & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i)) 
                   & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3729, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_empty);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_empty 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4081, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4089, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_req)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req)));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_push))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3891, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_push);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_push 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
        = ((0x0000007fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
           | ((QData)((IData)((3U & (- (IData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push)))))) 
              << 0x00000027U));
    if (((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5737]);
    }
    if ((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5738]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5740]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__push_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5315, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__push_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__push_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i;
    }
}

void Vtop___024root___nba_comb__TOP__7(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__7\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
            << 5U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req));
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4160, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i 
            = ((0x03e1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4168, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i 
            = ((0x03feU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)) 
                               >> 6U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4170, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                >> 6U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i) 
                                         >> 6U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i 
            = ((0x003fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)) 
               | (0x000003c0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i)));
    }
    if ((0x00000020U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4178, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                >> 5U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i) 
                                         >> 5U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i 
            = ((0x03dfU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_data_i)) 
               | (0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4206, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i 
            = ((0x03e1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4214, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i 
            = ((0x03feU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)) 
                               >> 6U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4216, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                >> 6U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i) 
                                         >> 6U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i 
            = ((0x003fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)) 
               | (0x000003c0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i)));
    }
    if ((0x00000020U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4224, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                >> 5U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i) 
                                         >> 5U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i 
            = ((0x03dfU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_data_i)) 
               | (0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4262, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i 
            = ((0x03e1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4270, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i 
            = ((0x03feU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)) 
                               >> 6U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4272, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                >> 6U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i) 
                                         >> 6U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i 
            = ((0x003fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)) 
               | (0x000003c0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i)));
    }
    if ((0x00000020U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4280, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                >> 5U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i) 
                                         >> 5U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i 
            = ((0x03dfU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_i)) 
               | (0x00000020U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i)));
    }
}

void Vtop___024root___nba_comb__TOP__8(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                        >> 0x00000024U)) & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                    >> 9U))))) {
        ++(vlSelf->__Vcoverage[4126]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                          >> 9U))))) {
        ++(vlSelf->__Vcoverage[4127]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                          >> 0x00000024U))))) {
        ++(vlSelf->__Vcoverage[4128]);
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                        >> 0x00000023U)) & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                    >> 1U))))) {
        ++(vlSelf->__Vcoverage[4134]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                          >> 1U))))) {
        ++(vlSelf->__Vcoverage[4135]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                          >> 0x00000023U))))) {
        ++(vlSelf->__Vcoverage[4136]);
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
               & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i)))) {
        ++(vlSelf->__Vcoverage[4143]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i)))) {
        ++(vlSelf->__Vcoverage[4144]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o)))) {
        ++(vlSelf->__Vcoverage[4145]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
                 >> 0x00000028U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3492, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x000000ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3494, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 0x00000027U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x0000017fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                               >> 0x00000025U)) ^ (IData)(
                                                          (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                           >> 0x00000025U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 3496, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 0x00000025U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x0000019fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3500, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x000001efffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3502, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 0x00000023U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x000001f7ffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                         >> 3U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                            >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3504, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                        >> 3U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 3U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x000001f800000007ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 3U)))) 
                  << 3U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                               >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                  >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 3568, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x000001fffffffff9ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3572, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o 
            = ((0x000001fffffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__axi_lite_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop 
        = (1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                          >> 0x00000024U)) & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 9U))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push 
        = (1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                          >> 0x00000023U)) & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 1U))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
                 & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid) 
            << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3905, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_pop);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_pop 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_push))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3927, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_push);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_push 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4069, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_pop);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_pop 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop;
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
                 >> 0x00000028U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1497, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x000000ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1499, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                       >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000027U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x0000017fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                               >> 0x00000025U)) ^ (IData)(
                                                          (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                           >> 0x00000025U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1501, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                       >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000025U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x0000019fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1505, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x000001efffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1507, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                       >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000023U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x000001f7ffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                         >> 3U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                            >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1509, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                        >> 3U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 3U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x000001f800000007ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                           >> 3U)))) 
                  << 3U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                               >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                  >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 1573, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x000001fffffffff9ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1577, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o 
            = ((0x000001fffffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__axi_lite_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_valid_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4180, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_valid_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_valid_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__pop_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5144, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__pop_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__pop_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i;
    }
    if (((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5075]);
    }
    if ((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5076]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5078]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__push_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5013, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__push_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__push_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__pop_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4658, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__pop_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__pop_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i;
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
                 >> 0x00000028U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 574, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                      >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x000000ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 576, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                      >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000027U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x0000017fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                               >> 0x00000025U)) ^ (IData)(
                                                          (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                           >> 0x00000025U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 578, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                      >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000025U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x0000019fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 582, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                      >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x000001efffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 584, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                      >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000023U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x000001f7ffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                         >> 3U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                            >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 586, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 3U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x000001f800000007ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                           >> 3U)))) 
                  << 3U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                               >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                  >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 650, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x000001fffffffff9ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 654, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o 
            = ((0x000001fffffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__axi_lite_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o)))));
    }
    vlSelfRef.gpio_tb__DOT__axi_lite_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_valid_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4226, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_valid_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_valid_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i;
    vlSelfRef.gpio_tb__DOT__axi_aw_ready_o = (1U & (IData)(
                                                           (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                            >> 0x00000028U)));
    vlSelfRef.gpio_tb__DOT__axi_w_ready_o = (1U & (IData)(
                                                          (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                           >> 0x00000027U)));
    vlSelfRef.gpio_tb__DOT__axi_b_resp_o = (3U & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                          >> 0x00000025U)));
    vlSelfRef.gpio_tb__DOT__axi_b_valid_o = (1U & (IData)(
                                                          (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                           >> 0x00000024U)));
    vlSelfRef.gpio_tb__DOT__axi_ar_ready_o = (1U & (IData)(
                                                           (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                            >> 0x00000023U)));
    vlSelfRef.gpio_tb__DOT__axi_r_data_o = (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                    >> 3U));
    vlSelfRef.gpio_tb__DOT__axi_r_resp_o = (3U & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                          >> 1U)));
    vlSelfRef.gpio_tb__DOT__axi_r_valid_o = (1U & (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_o));
    if ((IData)(((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                  ^ vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
                 >> 0x00000028U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 146, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                      >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x000000ffffffffffULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                        >> 0x00000027U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000027U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 148, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                      >> 0x00000027U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000027U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x0000017fffffffffULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                 >> 0x00000027U))))) 
                  << 0x00000027U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                               >> 0x00000025U)) ^ (IData)(
                                                          (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                           >> 0x00000025U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 150, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                      >> 0x00000025U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000025U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x0000019fffffffffULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                 >> 0x00000025U))))) 
                  << 0x00000025U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                        >> 0x00000024U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000024U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 154, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                      >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x000001efffffffffULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                 >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                        >> 0x00000023U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                    >> 0x00000023U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 156, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                      >> 0x00000023U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 0x00000023U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x000001f7ffffffffULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                 >> 0x00000023U))))) 
                  << 0x00000023U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                         >> 3U)) ^ (IData)((vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                            >> 3U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 158, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                       >> 3U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 3U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x000001f800000007ULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                           >> 3U)))) 
                  << 3U));
    }
    if ((0U != (3U & ((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                               >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                  >> 1U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 222, (IData)(
                                                                     (vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x000001fffffffff9ULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | ((QData)((IData)((3U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__axi_lite_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 226, (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_o), (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o));
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o 
            = ((0x000001fffffffffeULL & vlSelfRef.gpio_tb__DOT____Vtogcov__axi_lite_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_o)))));
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__req_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4254, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__req_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__req_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__axi_aw_ready_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_aw_ready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 244, vlSelfRef.gpio_tb__DOT__axi_aw_ready_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_aw_ready_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_aw_ready_o 
            = vlSelfRef.gpio_tb__DOT__axi_aw_ready_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__axi_w_ready_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_w_ready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 320, vlSelfRef.gpio_tb__DOT__axi_w_ready_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_w_ready_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_w_ready_o 
            = vlSelfRef.gpio_tb__DOT__axi_w_ready_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__axi_b_resp_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_b_resp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 322, vlSelfRef.gpio_tb__DOT__axi_b_resp_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_b_resp_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_b_resp_o 
            = vlSelfRef.gpio_tb__DOT__axi_b_resp_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__axi_b_valid_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_b_valid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 326, vlSelfRef.gpio_tb__DOT__axi_b_valid_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_b_valid_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_b_valid_o 
            = vlSelfRef.gpio_tb__DOT__axi_b_valid_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__axi_ar_ready_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_ar_ready_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 346, vlSelfRef.gpio_tb__DOT__axi_ar_ready_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_ar_ready_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_ar_ready_o 
            = vlSelfRef.gpio_tb__DOT__axi_ar_ready_o;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__axi_r_data_o 
                ^ vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_data_o))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 348, vlSelfRef.gpio_tb__DOT__axi_r_data_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_data_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_data_o 
            = vlSelfRef.gpio_tb__DOT__axi_r_data_o;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__axi_r_resp_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_resp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 412, vlSelfRef.gpio_tb__DOT__axi_r_resp_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_resp_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_resp_o 
            = vlSelfRef.gpio_tb__DOT__axi_r_resp_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__axi_r_valid_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_valid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 416, vlSelfRef.gpio_tb__DOT__axi_r_valid_o, vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_valid_o);
        vlSelfRef.gpio_tb__DOT____Vtogcov__axi_r_valid_o 
            = vlSelfRef.gpio_tb__DOT__axi_r_valid_o;
    }
}

void Vtop___024root___nba_comb__TOP__9(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    // Body
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q) {
        ++(vlSelf->__Vcoverage[4335]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q;
    } else {
        ++(vlSelf->__Vcoverage[4336]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q) {
        ++(vlSelf->__Vcoverage[4333]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q)))) {
        ++(vlSelf->__Vcoverage[4334]);
    }
    if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d))) {
        ++(vlSelf->__Vcoverage[4403]);
    }
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d))) {
        ++(vlSelf->__Vcoverage[4404]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d)))) {
        ++(vlSelf->__Vcoverage[4405]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
          >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4406]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d)))) {
        ++(vlSelf->__Vcoverage[4407]);
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))))) {
        ++(vlSelf->__Vcoverage[4408]);
    }
    if ((IData)((1U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d)))) {
        ++(vlSelf->__Vcoverage[4409]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterreq_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4316, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterreq_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterreq_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask 
        = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask)) 
           | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d)));
    if ((1U <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4383]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_2 
            = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
                     >> 1U));
    } else {
        ++(vlSelf->__Vcoverage[4384]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_2 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask 
        = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask)) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_2) 
              << 1U));
    if ((1U <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4381]);
    }
    if ((1U > (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4382]);
    }
    if ((1U > (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4379]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_1 
            = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
                     >> 1U));
    } else {
        ++(vlSelf->__Vcoverage[4380]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_1 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask 
        = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask)) 
           | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_1) 
              << 1U));
    if ((1U > (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4377]);
    }
    if ((1U <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q))) {
        ++(vlSelf->__Vcoverage[4378]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes 
        = (0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel 
        = (1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d)) 
                 | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q) 
                    & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
                       >> 1U))));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arblower_mask)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4355, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arblower_mask);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arblower_mask 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_mask)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4351, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_mask);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_mask 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterreq_nodes))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4312, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterreq_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterreq_nodes 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET__sel))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4401, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET__sel);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET__sel 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel) {
        ++(vlSelf->__Vcoverage[4412]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_5 
            = (0x0000001fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                              >> 5U));
    } else {
        ++(vlSelf->__Vcoverage[4413]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_5 
            = (0x0000001fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_5;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel) {
        ++(vlSelf->__Vcoverage[4410]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)))) {
        ++(vlSelf->__Vcoverage[4411]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__in_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4424, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__in_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__in_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i = 0U;
    while ((2U > vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i)) {
        ++(vlSelf->__Vcoverage[4451]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp 
            = (((~ ((IData)(1U) << (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i))) 
                & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp)) 
               | (3U & ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i) 
                               >> (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i))) 
                        << (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i))));
        ++(vlSelf->__Vcoverage[4449]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i);
        ++(vlSelf->__Vcoverage[4452]);
    }
    ++(vlSelf->__Vcoverage[4453]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__in_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4469, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__in_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__in_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i = 0U;
    while ((2U > vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i)) {
        ++(vlSelf->__Vcoverage[4496]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp 
            = (((~ ((IData)(1U) << (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i))) 
                & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp)) 
               | (3U & ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i) 
                               >> (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i))) 
                        << (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i))));
        ++(vlSelf->__Vcoverage[4494]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__flip_vector__DOT__unnamedblk1__DOT__i);
        ++(vlSelf->__Vcoverage[4497]);
    }
    ++(vlSelf->__Vcoverage[4498]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__req_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4282, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__req_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__req_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes) 
         != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterindex_nodes))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4298, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterindex_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterindex_nodes 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4300, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4308, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterdata_nodes)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes;
    if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4454]);
    }
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4455]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp)))) {
        ++(vlSelf->__Vcoverage[4456]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcin_tmp)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4444, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcin_tmp);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcin_tmp 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes 
        = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes)) 
           | (0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp)));
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4459]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____VlemCond_0 
            = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_lut));
    } else {
        ++(vlSelf->__Vcoverage[4460]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____VlemCond_0 
            = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_lut) 
                     >> 1U));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes 
        = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes)) 
           | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____VlemCond_0));
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4457]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp)))) {
        ++(vlSelf->__Vcoverage[4458]);
    }
    if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4499]);
    }
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4500]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp)))) {
        ++(vlSelf->__Vcoverage[4501]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcin_tmp)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4489, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcin_tmp);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcin_tmp 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes 
        = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes)) 
           | (0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp)));
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4504]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____VlemCond_0 
            = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_lut));
    } else {
        ++(vlSelf->__Vcoverage[4505]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____VlemCond_0 
            = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_lut) 
                     >> 1U));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes 
        = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)) 
           | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____VlemCond_0));
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp))) {
        ++(vlSelf->__Vcoverage[4502]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp)))) {
        ++(vlSelf->__Vcoverage[4503]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_valid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4244, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_valid_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_valid_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__idx_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4296, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__idx_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__idx_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4286, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4294, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__data_o)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcsel_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4436, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcsel_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcsel_nodes 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o 
        = (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes)));
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4440, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes 
            = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes)));
    }
    if ((2U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4442, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__gen_lzcindex_nodes)) 
               | (2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcsel_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4481, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcsel_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcsel_nodes 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o 
        = (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes)));
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4485, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes 
            = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)));
    }
    if ((2U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4487, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__gen_lzcindex_nodes)) 
               | (2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_valid_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4198, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_valid_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_valid_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o;
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4234, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4242, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_data_o)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4430, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__empty_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__empty_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__cnt_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4428, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__cnt_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT____Vtogcov__cnt_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4475, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__empty_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__empty_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__cnt_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4473, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__cnt_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT____Vtogcov__cnt_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4188, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4196, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_data_o)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arblower_idx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4361, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arblower_idx);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arblower_idx 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4365, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_empty);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_empty 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_idx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4359, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_idx);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbupper_idx 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty) {
        ++(vlSelf->__Vcoverage[4387]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_3 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx;
    } else {
        ++(vlSelf->__Vcoverage[4388]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_3 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_3;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty) {
        ++(vlSelf->__Vcoverage[4385]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty)))) {
        ++(vlSelf->__Vcoverage[4386]);
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req)) 
                               >> 1U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4091, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req)) 
               | (0x0000001eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req)));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4099, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req 
            = ((0x1eU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__arb_req)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
        = (((QData)((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o)) 
            << 0x00000029U) | (((QData)((IData)((1U 
                                                 & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req)))) 
                                << 0x00000028U) | (
                                                   ((QData)((IData)(
                                                                    (0x0000000fU 
                                                                     & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                                                        >> 1U)))) 
                                                    << 0x00000024U) 
                                                   | (0x0000000fffffffffULL 
                                                      & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbnext_idx))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4363, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbnext_idx);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arbnext_idx 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx;
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3574, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                                                                >> 0x00000029U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
            = ((0x000001ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3576, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
            = ((0x000002ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3578, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
            = ((0x0000030fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3586, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
            = ((0x000003f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3650, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o 
            = ((0x000003fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_req_o) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o;
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1665, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                                       >> 0x00000029U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                                                                >> 0x00000029U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
            = ((0x000001ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                 >> 0x00000029U))))) 
                  << 0x00000029U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                        >> 0x00000028U)) ^ (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                                    >> 0x00000028U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1667, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                                                                >> 0x00000028U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
            = ((0x000002ffffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                 >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x0000000fU & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                        >> 0x00000024U)) 
                               ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                          >> 0x00000024U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1669, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                                       >> 0x00000024U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                                                                >> 0x00000024U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
            = ((0x0000030fffffffffULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req) 
               | ((QData)((IData)((0x0000000fU & (IData)(
                                                         (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                          >> 0x00000024U))))) 
                  << 0x00000024U));
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                         >> 4U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                            >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1677, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                                        >> 4U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
                                                                                >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
            = ((0x000003f00000000fULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                           >> 4U)))) 
                  << 4U));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1741, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req 
            = ((0x000003fffffffff0ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_req) 
               | (IData)((IData)((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req;
    if ((IData)((0x0000030000000000ULL == (0x0000030000000000ULL 
                                           & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[2304]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000028U))))) {
        ++(vlSelf->__Vcoverage[2306]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[2307]);
    }
    if ((IData)((0x0000020000000000ULL == (0x0000030000000000ULL 
                                           & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i)))) {
        ++(vlSelf->__Vcoverage[2308]);
    }
    if ((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                       >> 0x00000028U)))) {
        ++(vlSelf->__Vcoverage[2310]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[2311]);
    }
    if ((IData)(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                  ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i) 
                 >> 0x00000029U))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1821, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1823, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1825, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1833, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1897, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_req_i));
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
        = (3U == (3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                >> 0x00000028U))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr 
        = (0x0000000fU & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                  >> 0x00000024U)));
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2073, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_wdata);
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
        ++(vlSelf->__Vcoverage[2510]);
    }
    if ((IData)((0x0bU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2511]);
    }
    if ((IData)((0x0dU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2512]);
    }
    if ((IData)((1U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2513]);
    }
    if ((IData)((0x0eU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2514]);
    }
    if ((IData)((2U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2515]);
    }
    if ((IData)((4U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2516]);
    }
    if ((IData)((8U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2517]);
    }
    if ((IData)((0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2518]);
    }
    if ((IData)((3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2519]);
    }
    if ((IData)((5U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2520]);
    }
    if ((IData)((9U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2521]);
    }
    if ((IData)((6U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2522]);
    }
    if ((IData)((0x0aU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2523]);
    }
    if ((IData)((0x0cU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2524]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2525]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2137, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be 
        = (1U & VL_REDXOR_4(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2063, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2061, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2065, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_addr 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit 
        = (((8U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr)) 
            << 2U) | (((4U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr)) 
                       << 1U) | (0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2506, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_wdata 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2373, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2389, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2405, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2421, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2437, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2339, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2355, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2508, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__unused_be 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be;
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                           >> 2U)))) {
        ++(vlSelf->__Vcoverage[2467]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
                           >> 1U)))) {
        ++(vlSelf->__Vcoverage[2468]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 2U)) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2469]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
             >> 1U)) & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2473]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2477]);
    }
    if ((IData)((7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) {
        ++(vlSelf->__Vcoverage[2478]);
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
               & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                     >> 2U))))) {
        ++(vlSelf->__Vcoverage[2479]);
    }
    if ((IData)(((7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))) 
                 & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                       >> 1U))))) {
        ++(vlSelf->__Vcoverage[2480]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be) 
         & (0U == (6U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))) {
        ++(vlSelf->__Vcoverage[2481]);
    }
    if (((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)) 
         & (7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) {
        ++(vlSelf->__Vcoverage[2482]);
    }
    if ((IData)(((0U == (5U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) 
                 & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) {
        ++(vlSelf->__Vcoverage[2483]);
    }
    if ((IData)(((0U == (3U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) 
                 & (7U == (7U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))))) {
        ++(vlSelf->__Vcoverage[2484]);
    }
    if ((IData)((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit)))) {
        ++(vlSelf->__Vcoverage[2485]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[2486]);
    }
    ++(vlSelf->__Vcoverage[2487]);
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2454, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addr_hit 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) 
           & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
               & (0U != (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) 
              | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                   >> 2U) & (0U != (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be))))) 
                 | ((0U != (1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be)))) 
                    & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                       >> 1U)))));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) 
         | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we))) {
        ++(vlSelf->__Vcoverage[2464]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0 
            = (1U & (~ (0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))));
    } else {
        ++(vlSelf->__Vcoverage[2465]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we) {
        ++(vlSelf->__Vcoverage[2461]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re) {
        ++(vlSelf->__Vcoverage[2462]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we))))) {
        ++(vlSelf->__Vcoverage[2463]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2952, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2849, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2746, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2643, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2532, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3334, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3286, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2213, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__wr_err 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err) {
        ++(vlSelf->__Vcoverage[2315]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) {
        ++(vlSelf->__Vcoverage[2316]);
    }
    if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss)) 
               & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err))))) {
        ++(vlSelf->__Vcoverage[2317]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2211, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__addrmiss);
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3008, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2905, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2802, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2699, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2596, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wd 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3354, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3306, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__q 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3059, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__en_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i;
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[2488]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[2489]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)))) {
        ++(vlSelf->__Vcoverage[2490]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[2491]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 1U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[2492]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[2493]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[2494]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[2495]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
           >> 2U) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)))) {
        ++(vlSelf->__Vcoverage[2496]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) {
        ++(vlSelf->__Vcoverage[2497]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we)))) {
        ++(vlSelf->__Vcoverage[2498]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
                  >> 2U)))) {
        ++(vlSelf->__Vcoverage[2499]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2209, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_error 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re)));
    __VdfgRegularize_h6e95ff9d_0_6 = ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error)) 
                                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3083, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__en_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2327, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 2U) & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit) 
            >> 1U) & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3282, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3330, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__re 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2363, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_we);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2329, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_we);
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
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3304, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qre 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3352, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qre 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2530, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2641, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2744, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2847, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2950, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 2283, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_we_check 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3284, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3332, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2623]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2624]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2594, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2627]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2628]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2625]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2626]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2726]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2727]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2697, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2730]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2731]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2728]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2729]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2829]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2830]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2800, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2833]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2834]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2831]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2832]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2932]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2933]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2903, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2936]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[2937]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[2934]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[2935]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3035]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3036]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3006, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we;
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3039]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd;
    } else {
        ++(vlSelf->__Vcoverage[3040]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0 = 0U;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we) {
        ++(vlSelf->__Vcoverage[3037]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we)))) {
        ++(vlSelf->__Vcoverage[3038]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3053, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3302, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3350, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we 
        = (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe) 
            << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2614, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2612, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2717, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2715, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2820, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2818, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2923, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2921, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3026, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3024, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3168, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__in_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv 
        = (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i)));
    if ((IData)((3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we)))) {
        ++(vlSelf->__Vcoverage[2451]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[2452]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we)))) {
        ++(vlSelf->__Vcoverage[2453]);
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 2447, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_flds_we 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe 
        = (3U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2576, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2574, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2679, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2677, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2782, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2780, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2885, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2883, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2988, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2986, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3180, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__inv 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o 
        = (7U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv)));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2445, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2548, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2651, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2754, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2857, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2960, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3174, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT____Vtogcov__out_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3063, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__oh_buf 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 3073, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__oh_i);
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
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3087, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSelf->__Vcoverage + 3101, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    }
}

void Vtop___024root___nba_comb__TOP__15(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__15\n"); );
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1973, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1981, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1983, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1991, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1993, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2001, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2009, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2017, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2025, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1579, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1587, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1589, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1597, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1599, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1607, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1615, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1623, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1631, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 656, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 664, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 666, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 674, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 676, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 684, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 692, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 700, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 708, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw 
            = ((0x3ffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg2hw) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw;
    if ((0U != (0x0000000fU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
                               >> 0x0000001aU)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 750, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x0000001aU), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x0000001aU));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x03ffffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x3c000000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x02000000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 758, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 760, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 0x00000015U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                                  >> 0x00000015U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3e1fffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x01e00000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0x00100000U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                        ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 768, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 770, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 778, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 786, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 794, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                >> 4U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw 
            = ((0x3fffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 802, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__reg2hw);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 957, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1066, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1165, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1264, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__enable_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i;
    }
}

void Vtop___024root___nba_comb__TOP__21(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__21\n"); );
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 900, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_rise 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 908, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_fall);
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 810, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 818, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 820, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 828, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 860, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 716, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 724, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 726, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 734, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg 
            = ((0x1ff0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__hw2reg)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg)));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 456, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__intr_gpio_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    }
    vlSelfRef.gpio_tb__DOT__intr_gpio_o = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o;
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
                               >> 9U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1639, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1647, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1649, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1657, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__hw2reg);
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2033, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 9U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 9U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x01ffU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x00001e00U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0x00000100U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2041, 
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2043, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1f0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg)));
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2051, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
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
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3192, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3190, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3294, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3342, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3248, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3246, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__de 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3314, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3322, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3362, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3370, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT____Vtogcov__qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3266, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3264, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2347, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_oe_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2331, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__direct_gpio_o_qs 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3228, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_data 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3226, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__wr_en 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3200, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qe 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe;
    }
}

void Vtop___024root___nba_comb__TOP__22(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0U;
    if ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs));
        ++(vlSelf->__Vcoverage[2501]);
    } else if ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs) 
                   << 4U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs)));
        ++(vlSelf->__Vcoverage[2502]);
    } else if ((4U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffff0000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                    << 0x0000000cU) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                                       << 8U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                                                   << 4U) 
                                                  | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs))));
        ++(vlSelf->__Vcoverage[2503]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xfff0ffffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[2504]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: gpio_reg_core.sv:362: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"gpio_tb.u_gpio.u_gpio_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-axi_lite/runs/gpio/release/rtl/gpio_reg_core.sv", 362, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[2505]);
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3244]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
    } else {
        ++(vlSelf->__Vcoverage[3245]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____VlemCond_0;
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
        ++(vlSelf->__Vcoverage[3242]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en)))) {
        ++(vlSelf->__Vcoverage[3243]);
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2215, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3210, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__ds 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds;
    }
    if ((0U != (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 2145, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
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
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1905, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1969, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1971, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1749, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1813, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1815, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__flexsoc_axi_reg_rsp) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp;
    if ((IData)(((0x0000030000000000ULL == (0x0000030000000000ULL 
                                            & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o)) 
                 & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i))) {
        ++(vlSelf->__Vcoverage[4122]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                          >> 0x00000028U))))) {
        ++(vlSelf->__Vcoverage[4123]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i)))) {
        ++(vlSelf->__Vcoverage[4124]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[4125]);
    }
    if ((IData)(((0x0000020000000000ULL == (0x0000030000000000ULL 
                                            & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o)) 
                 & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i))) {
        ++(vlSelf->__Vcoverage[4146]);
    }
    if ((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                       >> 0x00000028U)))) {
        ++(vlSelf->__Vcoverage[4147]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i)))) {
        ++(vlSelf->__Vcoverage[4148]);
    }
    if ((1U & (~ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                          >> 0x00000029U))))) {
        ++(vlSelf->__Vcoverage[4149]);
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                         >> 2U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3658, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                                                        >> 2U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
                                                                                >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
            = ((3ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                        >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3722, (IData)(
                                                                      (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                                                       >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
            = ((0x00000003fffffffdULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3724, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i 
            = ((0x00000003fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__reg_rsp_i) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in 
        = (1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                         >> 1U)));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push 
        = (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                   & (0x0000030000000000ULL == (0x0000030000000000ULL 
                                                & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o))));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push 
        = (IData)(((0x0000020000000000ULL == (0x0000030000000000ULL 
                                              & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o)) 
                   & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
        = (0x00000001ffffffffULL & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                    >> 1U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3899, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_in);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_in 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_push))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3903, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_push);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_resp_fifo_push 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_push))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4067, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_push);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_push 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push;
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                         >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in 
                                            >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 3935, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                                                                        >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in 
            = ((1ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                                           >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3999, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in 
            = ((0x00000001fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_resp_fifo_in) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_ready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4200, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_ready_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__oup_ready_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__data_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5138, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__data_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__data_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i;
    }
    if (((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5172]);
    }
    if ((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5173]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5175]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__push_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5140, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__push_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__push_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q;
    ++(vlSelf->__Vcoverage[5179]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock = 1U;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n 
            = (((~ ((IData)(1U) << (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q))) 
                & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n)) 
               | (3U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i) 
                        << (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q))));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q)));
        ++(vlSelf->__Vcoverage[5181]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q)));
        ++(vlSelf->__Vcoverage[5182]);
    } else {
        ++(vlSelf->__Vcoverage[5183]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q)));
        ++(vlSelf->__Vcoverage[5188]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n 
            = (3U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q) 
                     - (IData)(1U)));
        ++(vlSelf->__Vcoverage[5189]);
    } else {
        ++(vlSelf->__Vcoverage[5190]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q;
        ++(vlSelf->__Vcoverage[5194]);
    } else {
        ++(vlSelf->__Vcoverage[5195]);
    }
    ++(vlSelf->__Vcoverage[5204]);
    ++(vlSelf->__Vcoverage[5177]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[5184]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o) {
        ++(vlSelf->__Vcoverage[5185]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5186]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[5191]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[5192]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[5193]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[5196]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[5197]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o) {
        ++(vlSelf->__Vcoverage[5198]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[5199]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5200]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5206]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5207]);
    }
    ++(vlSelf->__Vcoverage[5208]);
    ++(vlSelf->__Vcoverage[5209]);
    if (((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[4942]);
    }
    if ((0U == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[4943]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[4945]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__push_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4590, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__push_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__push_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i;
    }
    if ((0U != ((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                         >> 1U)) ^ (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i 
                                            >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4524, (IData)(
                                                                       (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                                                                        >> 1U)), (IData)(
                                                                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i 
                                                                                >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i 
            = ((1ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i) 
               | ((QData)((IData)((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                                           >> 1U)))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4588, (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i), (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i 
            = ((0x00000001fffffffeULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__data_i) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i)))));
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q;
    ++(vlSelf->__Vcoverage[4949]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock = 1U;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o)))) {
        if ((0x41U >= (0x0000007fU & ((IData)(0x00000021U) 
                                      * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q))))) {
            VL_ASSIGNSEL_WQ(66, 33, (0x0000007fU & 
                                     ((IData)(0x00000021U) 
                                      * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q))), vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i);
        }
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q)));
        ++(vlSelf->__Vcoverage[4951]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q)));
        ++(vlSelf->__Vcoverage[4952]);
    } else {
        ++(vlSelf->__Vcoverage[4953]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q)));
        ++(vlSelf->__Vcoverage[4958]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n 
            = (3U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q) 
                     - (IData)(1U)));
        ++(vlSelf->__Vcoverage[4959]);
    } else {
        ++(vlSelf->__Vcoverage[4960]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q;
        ++(vlSelf->__Vcoverage[4964]);
    } else {
        ++(vlSelf->__Vcoverage[4965]);
    }
    ++(vlSelf->__Vcoverage[4974]);
    ++(vlSelf->__Vcoverage[4947]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[4954]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4955]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[4956]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[4961]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[4962]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[4963]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[4966]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[4967]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4968]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[4969]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[4970]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[4976]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[4977]);
    }
    ++(vlSelf->__Vcoverage[4978]);
    ++(vlSelf->__Vcoverage[4979]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_ready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4246, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_ready_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__oup_ready_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__read_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5148, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__read_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__read_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__write_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5152, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__write_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__write_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__status_cnt_n)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5156, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__status_cnt_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__gate_clock))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5146, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__gate_clock);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__gate_clock 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock;
    }
    if ((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5164, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n 
            = ((2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n)) 
               | (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n)));
    }
    if ((2U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n) 
               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5166, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n) 
                                >> 1U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n) 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n 
            = ((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__mem_n)) 
               | (2U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n)));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__read_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4662, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__read_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__read_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__write_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4666, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__write_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__write_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__status_cnt_n)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4670, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__status_cnt_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__gate_clock))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4660, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__gate_clock);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__gate_clock 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock;
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                  << 0x0000001fU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
                                     >> 1U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
                                                 << 0x0000001fU) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U] 
                                                   >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4678, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
                                 >> 1U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
                                            << 0x0000001fU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U] 
                                              >> 1U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U] 
            = ((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U]) 
               | (0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U]));
    }
    if ((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4742, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U] 
            = ((0xfffffffeU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[0U]) 
               | (1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
                  << 0x0000001eU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                     >> 2U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[2U] 
                                                 << 0x0000001eU) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
                                                   >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 4744, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
                                 << 0x0000001eU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                 >> 2U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[2U] 
                                            << 0x0000001eU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
                                              >> 2U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
            = ((3U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U]) 
               | (0xfffffffcU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[2U] 
            = (3U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U]);
    }
    if ((2U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4808, 
                               (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                >> 1U), (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
                                         >> 1U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U] 
            = ((0xfffffffdU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__mem_n[1U]) 
               | (2U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U]));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i)))) {
        ++(vlSelf->__Vcoverage[4330]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i) {
        ++(vlSelf->__Vcoverage[4331]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o)))) {
        ++(vlSelf->__Vcoverage[4332]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gnt_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4284, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gnt_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gnt_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d 
        = ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i)) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o))) {
        ++(vlSelf->__Vcoverage[4392]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_4 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx;
    } else {
        ++(vlSelf->__Vcoverage[4393]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_4 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____VlemCond_4;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o))) {
        ++(vlSelf->__Vcoverage[4389]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o)))) {
        ++(vlSelf->__Vcoverage[4390]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i)))) {
        ++(vlSelf->__Vcoverage[4391]);
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_locklock_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4322, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_locklock_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_locklock_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rrrr_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4320, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rrrr_d);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rrrr_d 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d;
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes) 
          & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d)) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)))) {
        ++(vlSelf->__Vcoverage[4414]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)))) {
        ++(vlSelf->__Vcoverage[4415]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel) {
        ++(vlSelf->__Vcoverage[4416]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes)))) {
        ++(vlSelf->__Vcoverage[4418]);
    }
    if ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes) 
          & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d) 
             >> 1U)) & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel))) {
        ++(vlSelf->__Vcoverage[4419]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel))) {
        ++(vlSelf->__Vcoverage[4420]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)))) {
        ++(vlSelf->__Vcoverage[4421]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes)))) {
        ++(vlSelf->__Vcoverage[4423]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbitergnt_nodes))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4310, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbitergnt_nodes);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbitergnt_nodes 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o 
        = ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes) 
             & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)) 
            << 1U) | ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel)) 
                      & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes)));
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gnt_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4258, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gnt_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gnt_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_ready_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4230, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_ready_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__inp_ready_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o;
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_ready_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4184, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_ready_o);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__inp_ready_o 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready 
        = (1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o) 
                 >> 1U));
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready 
        = (1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready))) {
        ++(vlSelf->__Vcoverage[4129]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready)))) {
        ++(vlSelf->__Vcoverage[4130]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid)))) {
        ++(vlSelf->__Vcoverage[4131]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4105, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_ready);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_ready 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid) 
         & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready))) {
        ++(vlSelf->__Vcoverage[4113]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready)))) {
        ++(vlSelf->__Vcoverage[4114]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid)))) {
        ++(vlSelf->__Vcoverage[4115]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4107, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_ready);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_ready 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop 
        = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid));
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3929, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_pop);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_fifo_pop 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3893, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_pop);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_fifo_pop 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__pop_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5023, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__pop_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__pop_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q;
    ++(vlSelf->__Vcoverage[5082]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock = 1U;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n 
            = (((~ ((IData)(0x0fU) << (7U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q) 
                                             << 2U)))) 
                & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n)) 
               | (0x00ffU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_i) 
                             << (7U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q) 
                                       << 2U)))));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q)));
        ++(vlSelf->__Vcoverage[5084]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q)));
        ++(vlSelf->__Vcoverage[5085]);
    } else {
        ++(vlSelf->__Vcoverage[5086]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q)));
        ++(vlSelf->__Vcoverage[5091]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n 
            = (3U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q) 
                     - (IData)(1U)));
        ++(vlSelf->__Vcoverage[5092]);
    } else {
        ++(vlSelf->__Vcoverage[5093]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q;
        ++(vlSelf->__Vcoverage[5097]);
    } else {
        ++(vlSelf->__Vcoverage[5098]);
    }
    ++(vlSelf->__Vcoverage[5107]);
    ++(vlSelf->__Vcoverage[5080]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[5087]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o) {
        ++(vlSelf->__Vcoverage[5088]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5089]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[5094]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[5095]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[5096]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[5099]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[5100]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o) {
        ++(vlSelf->__Vcoverage[5101]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[5102]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5103]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5109]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5110]);
    }
    ++(vlSelf->__Vcoverage[5111]);
    ++(vlSelf->__Vcoverage[5112]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__pop_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5397, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__pop_i);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__pop_i 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i;
    }
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q;
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q;
    ++(vlSelf->__Vcoverage[5744]);
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[0U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[1U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q[2U];
    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock = 1U;
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o)))) {
        if ((0x4fU >= (0x0000007fU & ((IData)(0x00000028U) 
                                      * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q))))) {
            VL_ASSIGNSEL_WQ(80, 40, (0x0000007fU & 
                                     ((IData)(0x00000028U) 
                                      * (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q))), vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i);
        }
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock = 0U;
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q)));
        ++(vlSelf->__Vcoverage[5746]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q)));
        ++(vlSelf->__Vcoverage[5747]);
    } else {
        ++(vlSelf->__Vcoverage[5748]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n 
            = (1U & ((IData)(1U) + (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q)));
        ++(vlSelf->__Vcoverage[5753]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n 
            = (3U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q) 
                     - (IData)(1U)));
        ++(vlSelf->__Vcoverage[5754]);
    } else {
        ++(vlSelf->__Vcoverage[5755]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o)))) {
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q;
        ++(vlSelf->__Vcoverage[5759]);
    } else {
        ++(vlSelf->__Vcoverage[5760]);
    }
    ++(vlSelf->__Vcoverage[5769]);
    ++(vlSelf->__Vcoverage[5742]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[5749]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o) {
        ++(vlSelf->__Vcoverage[5750]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5751]);
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[5756]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[5757]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[5758]);
    }
    if (((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i) 
           & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i)) 
          & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o))) 
         & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o)))) {
        ++(vlSelf->__Vcoverage[5761]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o) {
        ++(vlSelf->__Vcoverage[5762]);
    }
    if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o) {
        ++(vlSelf->__Vcoverage[5763]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i)))) {
        ++(vlSelf->__Vcoverage[5764]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5765]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i)))) {
        ++(vlSelf->__Vcoverage[5771]);
    }
    if ((0U != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q))) {
        ++(vlSelf->__Vcoverage[5772]);
    }
    ++(vlSelf->__Vcoverage[5773]);
    ++(vlSelf->__Vcoverage[5774]);
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__read_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5027, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__read_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__read_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__write_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5031, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__write_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__write_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__status_cnt_n)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5035, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__status_cnt_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__gate_clock))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5025, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__gate_clock);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__gate_clock 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock;
    }
    if ((0U != (0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                               ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5043, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n 
            = ((0xf0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n)) 
               | (0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n)));
    }
    if ((0U != (0x0000000fU & (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n)) 
                               >> 4U)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5051, 
                               ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                                >> 4U), ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n) 
                                         >> 4U));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n 
            = ((0x0fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__mem_n)) 
               | (0x000000f0U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n)));
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__read_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5401, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__read_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__read_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__write_pointer_n))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5405, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__write_pointer_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__write_pointer_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n;
    }
    if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n) 
                ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__status_cnt_n)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 5409, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__status_cnt_n);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__status_cnt_n 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n;
    }
    if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock) 
         ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__gate_clock))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5399, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__gate_clock);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__gate_clock 
            = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock;
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 >> 4U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                             << 0x0000001cU) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                               >> 4U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5417, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
            = ((0xffffff0fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U]) 
               | (0x000000f0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                  << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                                     >> 4U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                                 << 0x0000001cU) 
                                                | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U] 
                                                   >> 4U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5425, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 << 0x0000001cU) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                                 >> 4U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                            << 0x0000001cU) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U] 
                                              >> 4U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U] 
            = ((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U]) 
               | (0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U]));
    }
    if ((0U != (0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                               ^ vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U])))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5489, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U], vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U]);
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U] 
            = ((0xfffffff0U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[0U]) 
               | (0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                 >> 0x0000000cU)) ^ 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
                                 >> 0x0000000cU)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5497, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                 >> 0x0000000cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
                                 >> 0x0000000cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U]) 
               | (0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U]));
    }
    if ((0U != (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                  << 0x00000014U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                     >> 0x0000000cU)) 
                ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
                    << 0x00000014U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                       >> 0x0000000cU))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 5505, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 >> 0x0000000cU)), 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
                                 << 0x00000014U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                 >> 0x0000000cU)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
            = ((0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U]) 
               | (0xfffff000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U]));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U] 
            = ((0x0000f000U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[2U]) 
               | (0x00000fffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U]));
    }
    if ((0U != (0x0000000fU & (((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 >> 8U)) ^ ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                             << 0x00000018U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                               >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5569, 
                               ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 << 0x00000018U) | 
                                (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                 >> 8U)), ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                            << 0x00000018U) 
                                           | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
                                              >> 8U)));
        vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U] 
            = ((0xfffff0ffU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__mem_n[1U]) 
               | (0x00000f00U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U]));
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000000060000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1368]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[1367]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1369]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1370]);
            }
            ++(vlSelf->__Vcoverage[1371]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1365, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o;
            }
        }
    }
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5820]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5819]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5821]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5822]);
            }
            ++(vlSelf->__Vcoverage[5823]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5817, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5798, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq;
            }
        }
    }
    if (((1ULL & vlSelfRef.__VnbaTriggered[1U]) | (0x8000000000000000ULL 
                                                   & vlSelfRef.__VnbaTriggered[0U]))) {
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5854]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5853]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5855]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5856]);
            }
            ++(vlSelf->__Vcoverage[5857]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5851, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5832, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq;
            }
        }
    }
    if ((0x0000000000000600ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__3
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1058]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1057]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1059]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1060]);
            }
            ++(vlSelf->__Vcoverage[1061]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1055, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1031, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0000000000018000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__4
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1157]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1156]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1158]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1159]);
            }
            ++(vlSelf->__Vcoverage[1160]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1154, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1132, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__5
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1256]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1255]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1257]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1258]);
            }
            ++(vlSelf->__Vcoverage[1259]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1253, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1231, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0000000018000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__6
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1355]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1354]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1356]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1357]);
            }
            ++(vlSelf->__Vcoverage[1358]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1352, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1330, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__intq 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            }
        }
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__7
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5809]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[5808]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5810]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5811]);
            }
            ++(vlSelf->__Vcoverage[5812]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5806, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5794, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 744, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__core_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 748, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1361, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000000000060ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__8
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1007]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1006]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1008]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1009]);
            }
            ++(vlSelf->__Vcoverage[1010]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[996]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[995]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[997]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[998]);
            }
            ++(vlSelf->__Vcoverage[999]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1000]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1001]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1002]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1003]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1004]);
            }
            ++(vlSelf->__Vcoverage[1005]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 971, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 987, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 989, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__9
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1108]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1107]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1109]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1110]);
            }
            ++(vlSelf->__Vcoverage[1111]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1097]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1096]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1098]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1099]);
            }
            ++(vlSelf->__Vcoverage[1100]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1101]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1102]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1103]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1104]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1105]);
            }
            ++(vlSelf->__Vcoverage[1106]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1072, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1088, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1090, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000000060000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__10
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1207]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1206]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1208]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1209]);
            }
            ++(vlSelf->__Vcoverage[1210]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1196]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1195]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1197]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1198]);
            }
            ++(vlSelf->__Vcoverage[1199]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1200]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1201]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1202]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1203]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1204]);
            }
            ++(vlSelf->__Vcoverage[1205]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1171, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1187, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1189, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000001800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__11
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1306]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d;
            } else {
                ++(vlSelf->__Vcoverage[1305]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1307]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1308]);
            }
            ++(vlSelf->__Vcoverage[1309]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1295]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
            } else {
                ++(vlSelf->__Vcoverage[1294]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1296]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1297]);
            }
            ++(vlSelf->__Vcoverage[1298]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value) {
                    ++(vlSelf->__Vcoverage[1299]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
                } else {
                    ++(vlSelf->__Vcoverage[1300]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1301]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1302]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1303]);
            }
            ++(vlSelf->__Vcoverage[1304]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1270, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1286, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1288, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__stored_value_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
            }
        }
    }
    if ((0x0000000600000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__12
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[2291]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[2292]);
                }
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[2293]);
                }
                if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err)))) {
                    ++(vlSelf->__Vcoverage[2295]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2296]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2297]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2298]);
            }
            ++(vlSelf->__Vcoverage[2299]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err) {
                ++(vlSelf->__Vcoverage[2300]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) {
                ++(vlSelf->__Vcoverage[2302]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q)) 
                       & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
                ++(vlSelf->__Vcoverage[2303]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2289, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o 
                = ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q) 
                   | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2059, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o;
            }
        }
    }
    if ((0x0000000180000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__13
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1379]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[1378]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1380]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1381]);
            }
            ++(vlSelf->__Vcoverage[1382]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1376, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 932, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__filter_rst_ni);
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
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 955, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1064, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1163, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1262, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1023, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1124, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1223, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1322, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1051, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1150, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1249, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1348, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni;
            }
        }
    }
    if ((0x6000000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__14
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5843]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[5842]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5844]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5845]);
            }
            ++(vlSelf->__Vcoverage[5846]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5840, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5828, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 742, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT____Vtogcov__reg_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1385, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3380, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1819, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4158, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3051, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4204, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3071, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
            }
        }
    }
    if ((0x0000600000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__15
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3236]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3237]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3238]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3239]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3240]);
            }
            ++(vlSelf->__Vcoverage[3241]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3202, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3256, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3218, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3274, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT____Vtogcov__gen_rounused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2319, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__data_in_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs;
            }
        }
    }
    if ((0x0060000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__16(vlSelf);
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__17(vlSelf);
    }
    if ((0x0006000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__19
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1045]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1044]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1046]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1047]);
            }
            ++(vlSelf->__Vcoverage[1048]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1042, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1027, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 993, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000000000006000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__20
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1144]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1143]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1145]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1146]);
            }
            ++(vlSelf->__Vcoverage[1147]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1141, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1128, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1094, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000000000180000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__21
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1243]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1242]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1244]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1245]);
            }
            ++(vlSelf->__Vcoverage[1246]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1240, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1227, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1193, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000000006000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__22
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1342]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[1341]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1343]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1344]);
            }
            ++(vlSelf->__Vcoverage[1345]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1339, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1326, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1292, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_synced 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
            }
        }
    }
    if ((0x0000001800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__23
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2584]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2585]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2586]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2587]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2588]);
            }
            ++(vlSelf->__Vcoverage[2589]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2550, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2604, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2566, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2629, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2429, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_input_filter_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs;
            }
        }
    }
    if ((0x0000006000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__24
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2687]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2688]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2689]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2690]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2691]);
            }
            ++(vlSelf->__Vcoverage[2692]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2653, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2707, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2669, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2732, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2413, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvllow_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs;
            }
        }
    }
    if ((0x0000018000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__25
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2790]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2791]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2792]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2793]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2794]);
            }
            ++(vlSelf->__Vcoverage[2795]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2756, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2810, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2772, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2835, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2397, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_lvlhigh_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs;
            }
        }
    }
    if ((0x0000060000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__26
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2893]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2894]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2895]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2896]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2897]);
            }
            ++(vlSelf->__Vcoverage[2898]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2859, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2913, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2875, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2938, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2381, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_falling_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs;
            }
        }
    }
    if ((0x0000180000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__27
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) {
                if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2996]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q 
                        = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2997]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2998]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2999]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3000]);
            }
            ++(vlSelf->__Vcoverage[3001]);
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2962, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3016, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2978, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3041, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2365, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT____Vtogcov__intr_ctrl_en_rising_qs 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs;
            }
        }
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__28(vlSelf);
    }
    if ((0x0001800000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__29
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4395]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d;
                ++(vlSelf->__Vcoverage[4397]);
            } else {
                ++(vlSelf->__Vcoverage[4396]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4398]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4399]);
            }
            ++(vlSelf->__Vcoverage[4400]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4338]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d;
                ++(vlSelf->__Vcoverage[4340]);
            } else {
                ++(vlSelf->__Vcoverage[4339]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4341]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4342]);
            }
            ++(vlSelf->__Vcoverage[4343]);
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4345]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d;
                ++(vlSelf->__Vcoverage[4347]);
            } else {
                ++(vlSelf->__Vcoverage[4346]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4348]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4349]);
            }
            ++(vlSelf->__Vcoverage[4350]);
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterrr_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4314, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterrr_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiterrr_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_locklock_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4324, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_locklock_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_locklock_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_lockreq_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 4326, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_lockreq_q);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__gen_arbiter__DOT__gen_int_rr__DOT__gen_lockreq_q 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q;
            }
        }
    }
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__30(vlSelf);
    }
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__31
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5804, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__32
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1374, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni;
            }
        }
    }
    if (((1ULL & vlSelfRef.__VnbaTriggered[1U]) | (0x8000000000000000ULL 
                                                   & vlSelfRef.__VnbaTriggered[0U]))) {
        {
            // Inlined CFunc: _nba_sequent__TOP__33
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5838, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x6000000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__34
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni;
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
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni;
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3188, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5130, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4516, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2528, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2639, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2742, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2845, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2948, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4997, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4250, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5227, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000060000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__35
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 934, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__state_rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni;
            }
        }
    }
    if ((0x0000000180000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__36
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
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1038, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1137, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1236, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1335, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000000000600ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__37
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1040, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x00000000000001e0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1013]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1016]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1014]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1015]);
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
                ++(vlSelf->__Vcoverage[1011]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1012]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 979, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 991, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x0000000000018000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__38
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1139, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000000000007800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__1
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1114]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1117]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1115]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1116]);
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
                ++(vlSelf->__Vcoverage[1112]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1113]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1080, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1092, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__39
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1238, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x00000000001e0000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__2
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1213]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1216]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1214]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1215]);
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
                ++(vlSelf->__Vcoverage[1211]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1212]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1179, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1191, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x0000000018000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__40
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq;
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1337, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000000007800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__3
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 != (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1312]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_1 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[1315]);
                if ((0x0fU <= (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q))) {
                    ++(vlSelf->__Vcoverage[1313]);
                    vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_0 = 0x0fU;
                } else {
                    ++(vlSelf->__Vcoverage[1314]);
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
                ++(vlSelf->__Vcoverage[1310]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced) 
                 == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q))) {
                ++(vlSelf->__Vcoverage[1311]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 1278, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__diff_ctr_d 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value 
                = (0x0fU == (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1290, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__update_stored_value 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value;
            }
        }
    }
    if ((0x007e000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__4
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                = ((0x000001e000000007ULL & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o) 
                   | (((QData)((IData)((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty))))) 
                       << 0x00000024U) | (((QData)((IData)(
                                                           (1U 
                                                            & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full))))) 
                                           << 0x00000023U) 
                                          | ((QData)((IData)(
                                                             (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                                              >> 1U))) 
                                             << 3U))));
        }
    }
    if ((0x001e000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__5
            if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty)) 
                       & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full))))) {
                ++(vlSelf->__Vcoverage[4150]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full) {
                ++(vlSelf->__Vcoverage[4151]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty) {
                ++(vlSelf->__Vcoverage[4152]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid 
                = (1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty) 
                            | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full))));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_valid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4101, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_valid);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__read_valid 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid;
            }
        }
    }
    if ((0x01e0000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__6
            if ((1U & ((~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty)) 
                       & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full))))) {
                ++(vlSelf->__Vcoverage[4153]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full) {
                ++(vlSelf->__Vcoverage[4154]);
            }
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty) {
                ++(vlSelf->__Vcoverage[4155]);
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid 
                = (1U & (~ ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty) 
                            | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full))));
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_valid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4103, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_valid);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT____Vtogcov__write_valid 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid;
            }
        }
    }
    if ((0x0198000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x01fe000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x01ff800000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__9(vlSelf);
    }
    if ((0x01ff801800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__10
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2592]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2593]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2590]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2591]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2558, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds;
            }
        }
    }
    if ((0x01ff806000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__11
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2695]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2696]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2693]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2694]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2661, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds;
            }
        }
    }
    if ((0x01ff818000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__12
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2798]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2799]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2796]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2797]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2764, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds;
            }
        }
    }
    if ((0x01ff860000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__13
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2901]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2902]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2899]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2900]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2867, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds;
            }
        }
    }
    if ((0x01ff980000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__14
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3004]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3005]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____VlemCond_0;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3002]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3003]);
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 2970, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT____Vtogcov__ds 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds;
            }
        }
    }
    if ((0x01ff9ff800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__15(vlSelf);
    }
    if ((0x01ff9ff8000001e0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__16
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1019]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1020]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1017]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1018]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 969, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x01ff9ff800007800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__17
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1120]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1121]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1118]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1119]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1070, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x01ff9ff8001e0000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__18
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1219]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1220]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1217]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1218]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1169, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x01ff9ff807800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__19
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1318]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q;
            } else {
                ++(vlSelf->__Vcoverage[1319]);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced;
            }
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o 
                = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____VlemCond_2;
            if (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i) {
                ++(vlSelf->__Vcoverage[1316]);
            }
            if ((1U & (~ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i)))) {
                ++(vlSelf->__Vcoverage[1317]);
            }
            if (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o) 
                 ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1268, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT____Vtogcov__filter_o 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o;
            }
        }
    }
    if ((0x01ff9ff8079e79e0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__20
            vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d 
                = ((((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o) 
                     << 3U) | ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o) 
                               << 2U)) | (((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o) 
                                           << 1U) | (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o)));
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 868, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__data_in_d);
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
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 916, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_high 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high;
            }
            if ((0U != ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low) 
                        ^ (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 924, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low);
                vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT____Vtogcov__event_low 
                    = vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low;
            }
        }
    }
    if ((0x01ff9ff8079e79f8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__21(vlSelf);
    }
    if ((0x01fffff8079e79f8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__22(vlSelf);
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
            if ((2ULL & vlSelfRef.__VactTriggered[1U])) {
                vlSelfRef.__VdlySched.resume();
            }
        }
        Vtop___024root___eval_act(vlSelf);
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
        VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-axi_lite/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
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
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-axi_lite/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-axi_lite/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-axi_lite/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/gpio-axi_lite/runs/gpio/release/dv/functional/tb/cocotb/gpio_tb.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
