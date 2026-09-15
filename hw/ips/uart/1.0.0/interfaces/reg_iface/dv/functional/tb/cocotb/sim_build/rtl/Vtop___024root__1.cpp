// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___act_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7ffeU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | (IData)((0U != (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))));
    if ((4U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2443]);
    }
    if ((2U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2444]);
    }
    if ((IData)((0U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2445]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7ffdU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)((0U != (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
              << 1U));
    if ((0x00000010U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2456]);
    }
    if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2457]);
    }
    if ((IData)((0U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2458]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7ffbU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)((0U != (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
              << 2U));
    if ((0x00000040U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2469]);
    }
    if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2470]);
    }
    if ((IData)((0U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2471]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7ff7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)((0U != (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
              << 3U));
    if ((0x00000100U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2482]);
    }
    if ((0x00000080U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2483]);
    }
    if ((IData)((0U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2484]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7fefU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)((0U != (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
              << 4U));
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2495]);
    }
    if ((0x00000200U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2496]);
    }
    if ((IData)((0U == (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2497]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7fdfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)((0U != (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
              << 5U));
    if ((0x00001000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2508]);
    }
    if ((0x00000800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2509]);
    }
    if ((IData)((0U == (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2510]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree 
        = ((0x7fbfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)) 
           | ((IData)((0U != (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree)))) 
              << 6U));
    if ((0x00004000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2521]);
    }
    if ((0x00002000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))) {
        ++(vlSelf->__Vcoverage[2522]);
    }
    if ((IData)((0U == (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree))))) {
        ++(vlSelf->__Vcoverage[2523]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 2353, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__or_tree 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree;
    }
}

void Vtop___024root___act_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7ffeU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                    >> 1U)));
    if ((2U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2447]);
    }
    if ((IData)((0U == (6U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2448]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 1U)))) {
        ++(vlSelf->__Vcoverage[2449]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7ffdU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (2U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                    >> 2U)));
    if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2460]);
    }
    if ((IData)((0U == (0x0018U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2461]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 3U)))) {
        ++(vlSelf->__Vcoverage[2462]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7ffbU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (4U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                    >> 3U)));
    if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2473]);
    }
    if ((IData)((0U == (0x0060U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2474]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 5U)))) {
        ++(vlSelf->__Vcoverage[2475]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7ff7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (8U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                    >> 4U)));
    if ((0x00000080U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2486]);
    }
    if ((IData)((0U == (0x0180U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2487]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 7U)))) {
        ++(vlSelf->__Vcoverage[2488]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7fefU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (0x00000010U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                             >> 5U)));
    if ((0x00000200U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2499]);
    }
    if ((IData)((0U == (0x0600U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2500]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 9U)))) {
        ++(vlSelf->__Vcoverage[2501]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7fdfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (0x00000020U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                             >> 6U)));
    if ((0x00000800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2512]);
    }
    if ((IData)((0U == (0x1800U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2513]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 0x0bU)))) {
        ++(vlSelf->__Vcoverage[2514]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree 
        = ((0x7fbfU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree)) 
           | (0x00000040U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                             >> 7U)));
    if ((0x00002000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))) {
        ++(vlSelf->__Vcoverage[2525]);
    }
    if ((IData)((0U == (0x6000U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree))))) {
        ++(vlSelf->__Vcoverage[2526]);
    }
    if ((1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                  >> 0x0dU)))) {
        ++(vlSelf->__Vcoverage[2527]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree)))) {
        VL_COV_TOGGLE_CHG_ST_I(15, vlSelf->__Vcoverage + 2383, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__and_tree 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree;
    }
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*3:0*/ __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) {
            ++(vlSelf->__Vcoverage[4985]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            ++(vlSelf->__Vcoverage[4984]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) {
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
            ++(vlSelf->__Vcoverage[4982]);
        } else {
            ++(vlSelf->__Vcoverage[4983]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4986]);
        __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4987]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4988]);
    }
    ++(vlSelf->__Vcoverage[4989]);
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) {
            ++(vlSelf->__Vcoverage[4993]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            ++(vlSelf->__Vcoverage[4992]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) {
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
            ++(vlSelf->__Vcoverage[4990]);
        } else {
            ++(vlSelf->__Vcoverage[4991]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4994]);
        __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4995]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4996]);
    }
    ++(vlSelf->__Vcoverage[4997]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4926, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 3U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o 
        = (7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4942, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 3U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o 
        = (7U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (8U ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4972]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4973]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4958, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (8U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                 << 3U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4902, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4974]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4975]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4960, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (8U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                 << 3U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4908, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4916, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4914, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4978]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 = 8U;
    } else {
        ++(vlSelf->__Vcoverage[4981]);
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
             == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb))) {
            ++(vlSelf->__Vcoverage[4979]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000000fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                                  - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
        } else {
            ++(vlSelf->__Vcoverage[4980]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000000fU & (((IData)(8U) - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)) 
                                  + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4976]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[4977]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4934, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4950, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4687, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4697, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4918, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4671, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4709, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifoempty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4673, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 3600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_depth 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth;
    }
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*4:0*/ __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) {
            ++(vlSelf->__Vcoverage[4612]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            ++(vlSelf->__Vcoverage[4611]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) {
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
            ++(vlSelf->__Vcoverage[4609]);
        } else {
            ++(vlSelf->__Vcoverage[4610]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4613]);
        __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4614]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4615]);
    }
    ++(vlSelf->__Vcoverage[4616]);
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) {
            ++(vlSelf->__Vcoverage[4620]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            ++(vlSelf->__Vcoverage[4619]);
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) {
            __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
            ++(vlSelf->__Vcoverage[4617]);
        } else {
            ++(vlSelf->__Vcoverage[4618]);
        }
    } else {
        ++(vlSelf->__Vcoverage[4621]);
        __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[4622]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[4623]);
    }
    ++(vlSelf->__Vcoverage[4624]);
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4545, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                 >> 4U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o 
        = (0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4565, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb 
        = (1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                 >> 4U));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o 
        = (0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (0x10U ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4599]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4600]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4585, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (0x00000010U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb)) 
                          << 4U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4515, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)))) {
        ++(vlSelf->__Vcoverage[4601]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) {
        ++(vlSelf->__Vcoverage[4602]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4587, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_msb 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (0x00000010U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb)) 
                          << 4U));
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4523, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4533, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__empty_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4531, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4605]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 = 0x10U;
    } else {
        ++(vlSelf->__Vcoverage[4608]);
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb) 
             == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb))) {
            ++(vlSelf->__Vcoverage[4606]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o) 
                                  - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
        } else {
            ++(vlSelf->__Vcoverage[4607]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0 
                = (0x0000001fU & (((IData)(0x10U) - (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)) 
                                  + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_0;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____VlemCond_1;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o) {
        ++(vlSelf->__Vcoverage[4603]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o)))) {
        ++(vlSelf->__Vcoverage[4604]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4555, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4575, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set_cnt 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4170, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4182, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_empty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4535, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4150, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__full_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4194, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifoempty 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 4152, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__depth_o 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth)))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSelf->__Vcoverage + 3608, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_depth 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth;
    }
}

void Vtop___024root___nba_sequent__TOP__18(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        ++(vlSelf->__Vcoverage[4869]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
            = (((~ (0x00000000000000ffULL << (0x0000003fU 
                                              & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                                                 << 3U)))) 
                & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage) 
               | ((QData)((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i)) 
                  << (0x0000003fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                                     << 3U))));
    } else {
        ++(vlSelf->__Vcoverage[4870]);
    }
    ++(vlSelf->__Vcoverage[4871]);
    if ((0U != (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage) 
                               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4725, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffffffff00ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | (IData)((IData)((0x000000ffU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage)))));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 8U)) ^ (IData)(
                                                          (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                           >> 8U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4741, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 8U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 8U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffffff00ffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 8U))))) 
                  << 8U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000010U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000010U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4757, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000010U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000010U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffffff00ffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000010U))))) 
                  << 0x00000010U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000018U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000018U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4773, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000018U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000018U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffffff00ffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000018U))))) 
                  << 0x00000018U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000020U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000020U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4789, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000020U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000020U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffffff00ffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000020U))))) 
                  << 0x00000020U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000028U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000028U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4805, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000028U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000028U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xffff00ffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000028U))))) 
                  << 0x00000028U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000030U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000030U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4821, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000030U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000030U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0xff00ffffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000030U))))) 
                  << 0x00000030U));
    }
    if ((0U != (0x000000ffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                        >> 0x00000038U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                          >> 0x00000038U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4837, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                                       >> 0x00000038U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
                                                                                >> 0x00000038U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage 
            = ((0x00ffffffffffffffULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage) 
               | ((QData)((IData)((0x000000ffU & (IData)(
                                                         (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                                          >> 0x00000038U))))) 
                  << 0x00000038U));
    }
}

void Vtop___024root___nba_sequent__TOP__19(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
             & (1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q)))) {
            ++(vlSelf->__Vcoverage[5152]);
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q 
            = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
               & (1U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q)));
        if ((1U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q))) {
            ++(vlSelf->__Vcoverage[5153]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q)))) {
            ++(vlSelf->__Vcoverage[5154]);
        }
        ++(vlSelf->__Vcoverage[5156]);
    } else {
        ++(vlSelf->__Vcoverage[5155]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5157]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5158]);
    }
    ++(vlSelf->__Vcoverage[5159]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5036, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q;
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5123]);
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
        ++(vlSelf->__Vcoverage[5122]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q = 1U;
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni)))) {
        ++(vlSelf->__Vcoverage[5124]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) {
        ++(vlSelf->__Vcoverage[5125]);
    }
    ++(vlSelf->__Vcoverage[5126]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5010, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3832, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_valid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5082, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5098, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5116, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q) 
         & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0aU)))) {
        ++(vlSelf->__Vcoverage[5164]);
    }
    if ((0x00000400U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q))) {
        ++(vlSelf->__Vcoverage[5165]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q)))) {
        ++(vlSelf->__Vcoverage[5166]);
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5038, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err 
        = ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
               >> 0x0000000aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5120, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_q 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5008, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5030, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5028, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3598, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_tick_baud 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3882, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_frame_err 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3840, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_uart_idle 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle;
    }
}

void Vtop___024root___nba_sequent__TOP__20(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__20\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        ++(vlSelf->__Vcoverage[4482]);
        VL_ASSIGNSEL_WI(128, 8, (0x0000007fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                                                << 3U)), vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i);
    } else {
        ++(vlSelf->__Vcoverage[4483]);
    }
    ++(vlSelf->__Vcoverage[4484]);
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U])))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4210, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[0U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[0U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4226, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4242, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4258, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4274, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[1U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[1U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4290, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4306, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4322, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4338, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[2U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[2U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4354, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4370, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4386, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4402, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage[3U], vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage[3U]);
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4418, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4434, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4450, 
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
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 1156, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1188, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1190, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1192, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1194, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1196, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1198, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1200, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1202, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1204, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1206, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1208, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1210, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1212, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1214, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1216, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1218, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1220, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1222, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1224, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1226, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1242, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1244, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1260, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1262, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1264, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1266, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1268, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg2hw));
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
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 822, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 854, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 856, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 858, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 860, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 862, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 864, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 866, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 868, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 870, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 872, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 874, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 876, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 878, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 880, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 882, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 884, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 886, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 888, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 890, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 892, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 908, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 910, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 926, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 928, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 930, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 932, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 934, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw;
    if ((0U != (0x0000ffffU & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                        >> 0x00000029U)) 
                               ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
                                          >> 0x00000029U)))))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 486, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 518, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 520, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 522, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 524, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 526, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 528, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 530, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 532, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 534, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 536, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 538, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 540, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 542, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 544, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 546, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 548, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 550, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 552, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 554, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 556, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 572, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 574, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 590, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 592, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 594, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 596, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 598, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw 
            = ((0x01fffffffffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg2hw) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw;
    if ((IData)((3ULL == (3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[3918]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[3919]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 1U))))) {
        ++(vlSelf->__Vcoverage[3920]);
    }
    if ((IData)((0x000000000000000cULL == (0x000000000000000cULL 
                                           & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw)))) {
        ++(vlSelf->__Vcoverage[3921]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 2U))))) {
        ++(vlSelf->__Vcoverage[3922]);
    }
    if ((1U & (~ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                          >> 3U))))) {
        ++(vlSelf->__Vcoverage[3923]);
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
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3370, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3402, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3404, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3406, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3408, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3410, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3412, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3414, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3416, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3418, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3420, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3422, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3424, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3426, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3428, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3430, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3432, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3434, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3436, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3438, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3440, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3456, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3458, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3474, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3476, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3478, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3480, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3482, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__reg2hw));
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wdata 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3784, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_rxrst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3786, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_fifo_txrst 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5175, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__parity_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3916, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wvalid 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_pop 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3778, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__sys_loopback 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5006, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_odd 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3782, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rxnf_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3780, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__line_loopback 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5004, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__parity_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3776, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4635, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wdata_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4108, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4629, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4631, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wvalid_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4132, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rready_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5171, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_enable 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4509, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4896, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__clr_i);
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
        ++(vlSelf->__Vcoverage[3926]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
        ++(vlSelf->__Vcoverage[3927]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) {
        ++(vlSelf->__Vcoverage[3928]);
    }
    if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
          & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)) 
         & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable))) {
        ++(vlSelf->__Vcoverage[3978]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[3979]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
        ++(vlSelf->__Vcoverage[3980]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle)))) {
        ++(vlSelf->__Vcoverage[3981]);
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
           & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3804, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rready);
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
        ++(vlSelf->__Vcoverage[4721]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
        ++(vlSelf->__Vcoverage[4722]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)))) {
        ++(vlSelf->__Vcoverage[4723]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o)))) {
        ++(vlSelf->__Vcoverage[4724]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4653, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rready_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
           & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5177, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr);
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
                ++(vlSelf->__Vcoverage[5290]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0 = 0x0bU;
            } else {
                ++(vlSelf->__Vcoverage[5291]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0 = 0x0aU;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5286]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[5287]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5288]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[5289]);
            }
            ++(vlSelf->__Vcoverage[5297]);
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
                ++(vlSelf->__Vcoverage[5292]);
            } else {
                ++(vlSelf->__Vcoverage[5293]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 & (0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q)))) {
                ++(vlSelf->__Vcoverage[5294]);
            }
            if ((0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q))) {
                ++(vlSelf->__Vcoverage[5295]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q)))) {
                ++(vlSelf->__Vcoverage[5296]);
            }
        }
        ++(vlSelf->__Vcoverage[5299]);
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d = 0x07ffU;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d = 1U;
        ++(vlSelf->__Vcoverage[5298]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable)))) {
        ++(vlSelf->__Vcoverage[5300]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
        ++(vlSelf->__Vcoverage[5301]);
    }
    ++(vlSelf->__Vcoverage[5302]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4695, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5219, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5249, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5273, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)))) {
        ++(vlSelf->__Vcoverage[4969]);
    }
    if ((7U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o))) {
        ++(vlSelf->__Vcoverage[4970]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i)))) {
        ++(vlSelf->__Vcoverage[4971]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
           & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4964, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3484, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3486, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3488, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3490, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3492, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3494, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3496, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3512, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3528, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 600, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 602, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 604, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 606, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 608, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 610, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 612, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 628, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 644, vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 936, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 938, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 940, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 942, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 944, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 946, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 948, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 964, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 980, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg 
            = ((0x3fffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__hw2reg) 
               | (0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg;
    if ((0x20000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1270, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001dU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001dU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x1fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x20000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x10000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1272, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001cU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001cU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x2fffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x10000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x08000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1274, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001bU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001bU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x37ffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x08000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x04000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1276, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x0000001aU), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x0000001aU));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3bffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x04000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x02000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1278, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 0x00000019U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                                  >> 0x00000019U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3dffffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x02000000U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0x01000000U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1280, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1282, 
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
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1298, 
                               (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                >> 8U), (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
                                         >> 8U));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg 
            = ((0x3fff00ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg) 
               | (0x0000ff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg));
    }
    if ((0U != (0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                               ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1314, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__hw2reg);
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2237, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2247, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2257, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2267, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2277, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2287, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2686, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2738, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2965, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2241, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2243, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2251, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2253, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2261, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2263, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2271, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2273, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2281, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2283, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2291, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2293, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2704, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2720, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2756, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2772, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs;
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2983, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__ds 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2999, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT____Vtogcov__qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs;
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1704, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxempty_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1702, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxidle_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1700, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txidle_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1698, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txempty_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1696, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_rxfull_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1694, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__status_txfull_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1766, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_rxlvl_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1750, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_status_txlvl_qs 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 1708, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rdata_qs);
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
        ++(vlSelf->__Vcoverage[1836]);
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
        ++(vlSelf->__Vcoverage[1837]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffffcfU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs) 
                   << 5U) | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs) 
                             << 4U)));
    } else if ((4U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs));
        ++(vlSelf->__Vcoverage[1838]);
    } else if ((8U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = (0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[1839]);
    } else if ((0x00000010U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = (0xfffffffcU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next);
        ++(vlSelf->__Vcoverage[1840]);
    } else if ((0x00000020U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xffffff00U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs));
        ++(vlSelf->__Vcoverage[1841]);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
            = ((0xff00ffffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next) 
               | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs) 
                  << 0x00000010U));
    } else {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next = 0xffffffffU;
        ++(vlSelf->__Vcoverage[1842]);
    }
    if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))))))) {
        if ((0U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: uart_reg_core.sv:663: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"uart_tb.u_uart.u_uart_reg.u_reg_core", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/rtl/uart_reg_core.sv", 663, "");
            }
        }
    }
    ++(vlSelf->__Vcoverage[1843]);
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1488, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata_next 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next;
    if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata 
                ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1418, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rdata);
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
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 1088, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1152, (IData)(
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
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1154, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 754, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 818, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 820, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 418, (IData)(
                                                                      (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                                                       >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 482, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 484, (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__reg_rsp_o = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o;
    if ((0U != ((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                         >> 2U)) ^ (IData)((vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                            >> 2U))))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 94, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                                      >> 2U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 2U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
            = ((3ULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                           >> 2U)))) 
                  << 2U));
    }
    if ((1U & ((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                        >> 1U)) ^ (IData)((vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                           >> 1U))))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 158, (IData)(
                                                                     (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                                      >> 1U)), (IData)(
                                                                                (vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
                                                                                >> 1U)));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffdULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o) 
               | ((QData)((IData)((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                 >> 1U))))) 
                  << 1U));
    }
    if ((1U & ((IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o) 
               ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o)))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 160, (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o), (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o));
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o 
            = ((0x00000003fffffffeULL & vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_o) 
               | (IData)((IData)((1U & (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o)))));
    }
    vlSelfRef.uart_tb__DOT__reg_rsp_ready = (1U & (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o));
    vlSelfRef.uart_tb__DOT__reg_rsp_error = (1U & (IData)(
                                                          (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                           >> 1U)));
    vlSelfRef.uart_tb__DOT__reg_rsp_rdata = (IData)(
                                                    (vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                                     >> 2U));
    if (((IData)(vlSelfRef.uart_tb__DOT__reg_rsp_ready) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 248, vlSelfRef.uart_tb__DOT__reg_rsp_ready, vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_ready);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_ready 
            = vlSelfRef.uart_tb__DOT__reg_rsp_ready;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__reg_rsp_error) 
         ^ (IData)(vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_error))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 250, vlSelfRef.uart_tb__DOT__reg_rsp_error, vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_error);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_error 
            = vlSelfRef.uart_tb__DOT__reg_rsp_error;
    }
    if ((0U != (vlSelfRef.uart_tb__DOT__reg_rsp_rdata 
                ^ vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_rdata))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 252, vlSelfRef.uart_tb__DOT__reg_rsp_rdata, vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_rdata);
        vlSelfRef.uart_tb__DOT____Vtogcov__reg_rsp_rdata 
            = vlSelfRef.uart_tb__DOT__reg_rsp_rdata;
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
        ++(vlSelf->__Vcoverage[5127]);
    } else {
        ++(vlSelf->__Vcoverage[5128]);
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d = 8U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d = 0U;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
            ++(vlSelf->__Vcoverage[5131]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0 = 0x0bU;
        } else {
            ++(vlSelf->__Vcoverage[5132]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0 = 0x0aU;
        }
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = 0U;
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_0;
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
            ++(vlSelf->__Vcoverage[5129]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)))) {
            ++(vlSelf->__Vcoverage[5130]);
        }
        ++(vlSelf->__Vcoverage[5143]);
    } else {
        if (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)) 
             & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q))) {
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                  == ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                       ? 0x0bU : 0x0aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx))) {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d = 1U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d = 0U;
                ++(vlSelf->__Vcoverage[5133]);
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
                ++(vlSelf->__Vcoverage[5134]);
            }
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                  == ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                       ? 0x0bU : 0x0aU)) & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx))) {
                ++(vlSelf->__Vcoverage[5135]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
                ++(vlSelf->__Vcoverage[5136]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q) 
                 != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)
                      ? 0x0bU : 0x0aU))) {
                ++(vlSelf->__Vcoverage[5137]);
            }
            ++(vlSelf->__Vcoverage[5138]);
        } else {
            ++(vlSelf->__Vcoverage[5139]);
        }
        if (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)) 
             & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q))) {
            ++(vlSelf->__Vcoverage[5140]);
        }
        if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q)))) {
            ++(vlSelf->__Vcoverage[5141]);
        }
        if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) {
            ++(vlSelf->__Vcoverage[5142]);
        }
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q) 
         & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx)))) {
        ++(vlSelf->__Vcoverage[5144]);
    }
    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) {
        ++(vlSelf->__Vcoverage[5145]);
    }
    if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q)))) {
        ++(vlSelf->__Vcoverage[5146]);
    }
    ++(vlSelf->__Vcoverage[5148]);
    ++(vlSelf->__Vcoverage[5150]);
    ++(vlSelf->__Vcoverage[5151]);
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5114, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5060, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__sreg_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5090, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__bit_cnt_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d;
    }
    if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d) 
                ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5106, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__baud_div_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d;
    }
    if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d) 
         ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5118, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d);
        vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__idle_d 
            = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d;
    }
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16) {
                    ++(vlSelf->__Vcoverage[5275]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q 
                        = (1U & (((IData)(1U) + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q)) 
                                 >> 4U));
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q)));
                } else {
                    ++(vlSelf->__Vcoverage[5276]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q = 0U;
                }
            } else {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q = 0U;
                ++(vlSelf->__Vcoverage[5277]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5278]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5279]);
            }
            ++(vlSelf->__Vcoverage[5280]);
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5282]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d;
            } else {
                ++(vlSelf->__Vcoverage[5281]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q = 0U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q = 0x07ffU;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5283]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5284]);
            }
            ++(vlSelf->__Vcoverage[5285]);
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5201, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__baud_div_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5209, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(11, vlSelf->__Vcoverage + 5227, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__sreg_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5271, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 5211, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__bit_cnt_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5199, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tx 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
            }
        }
    }
    if ((0x0000000480000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) {
                ++(vlSelf->__Vcoverage[4001]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
            } else {
                ++(vlSelf->__Vcoverage[4000]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1 = 1U;
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2 = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni)))) {
                ++(vlSelf->__Vcoverage[4002]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) {
                ++(vlSelf->__Vcoverage[4003]);
            }
            ++(vlSelf->__Vcoverage[4004]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3994, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q2 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3992, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync_q1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1;
            }
        }
    }
    if ((0x0000000180000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
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
                ++(vlSelf->__Vcoverage[3969]);
                ++(vlSelf->__Vcoverage[3971]);
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable) {
                    ++(vlSelf->__Vcoverage[3972]);
                }
            } else {
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q = 0U;
                ++(vlSelf->__Vcoverage[3974]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni)))) {
                ++(vlSelf->__Vcoverage[3975]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) {
                ++(vlSelf->__Vcoverage[3976]);
            }
            ++(vlSelf->__Vcoverage[3977]);
            if ((0U != (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                        ^ vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q))) {
                VL_COV_TOGGLE_CHG_ST_I(17, vlSelf->__Vcoverage + 3935, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__nco_sum_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16 
                = (1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q 
                         >> 0x00000010U));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3596, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tick_baud_x16 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5173, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__tick_baud_x16 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5002, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__tick_baud_x16 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16;
            }
        }
    }
    if ((0x0000600000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
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
                        ++(vlSelf->__Vcoverage[4186]);
                    }
                    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                        ++(vlSelf->__Vcoverage[4187]);
                    }
                    ++(vlSelf->__Vcoverage[4188]);
                } else {
                    ++(vlSelf->__Vcoverage[4189]);
                }
            } else {
                ++(vlSelf->__Vcoverage[4190]);
                __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4191]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4192]);
            }
            ++(vlSelf->__Vcoverage[4193]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = __Vinline_0__nba_sequent__TOP__3___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4184, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
            }
        }
    }
    if ((0x0006000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
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
                        ++(vlSelf->__Vcoverage[4701]);
                    }
                    if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                        ++(vlSelf->__Vcoverage[4702]);
                    }
                    ++(vlSelf->__Vcoverage[4703]);
                } else {
                    ++(vlSelf->__Vcoverage[4704]);
                }
            } else {
                ++(vlSelf->__Vcoverage[4705]);
                __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4706]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4707]);
            }
            ++(vlSelf->__Vcoverage[4708]);
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = __Vinline_0__nba_sequent__TOP__4___Vdly__uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4699, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifounder_rst 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
            }
        }
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x0001800000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x0000180000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__7
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4100]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[4099]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4101]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4102]);
            }
            ++(vlSelf->__Vcoverage[4103]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4097, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3892, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__timing_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni;
            }
        }
    }
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__8
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5337]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5336]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5338]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5339]);
            }
            ++(vlSelf->__Vcoverage[5340]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5334, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5315, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
            }
        }
    }
    if (((1ULL & vlSelfRef.__VnbaTriggered[1U]) | (0x8000000000000000ULL 
                                                   & vlSelfRef.__VnbaTriggered[0U]))) {
        {
            // Inlined CFunc: _nba_sequent__TOP__9
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5371]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[5370]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5372]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5373]);
            }
            ++(vlSelf->__Vcoverage[5374]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5368, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5349, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__intq 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
            }
        }
    }
    if ((0x0000006000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__10
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4065]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[4064]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4066]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4067]);
            }
            ++(vlSelf->__Vcoverage[4068]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4062, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4040, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__intq 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
            }
        }
    }
    if ((0x0000060000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__11
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4089]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[4088]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4090]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4091]);
            }
            ++(vlSelf->__Vcoverage[4092]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4086, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
            }
        }
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__12
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5326]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[5325]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5327]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5328]);
            }
            ++(vlSelf->__Vcoverage[5329]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5323, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5311, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 662, vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__core_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3368, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4084, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4095, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0000018000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__13
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4078]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o = 1U;
            } else {
                ++(vlSelf->__Vcoverage[4077]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4079]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4080]);
            }
            ++(vlSelf->__Vcoverage[4081]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4075, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3896, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4106, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4032, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4507, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4058, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni;
            }
        }
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__14
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[1570]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[1571]);
                }
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
                    ++(vlSelf->__Vcoverage[1572]);
                }
                if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err)))) {
                    ++(vlSelf->__Vcoverage[1574]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1575]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1576]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1577]);
            }
            ++(vlSelf->__Vcoverage[1578]);
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err) {
                ++(vlSelf->__Vcoverage[1579]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) {
                ++(vlSelf->__Vcoverage[1581]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err))))) {
                ++(vlSelf->__Vcoverage[1582]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1568, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__err_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q) 
                   | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1330, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__intg_err_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o;
            }
        }
    }
    if ((0x0000000280000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__15
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
                    ++(vlSelf->__Vcoverage[3986]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[3987]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
                }
            } else {
                ++(vlSelf->__Vcoverage[3988]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni)))) {
                ++(vlSelf->__Vcoverage[3989]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) {
                ++(vlSelf->__Vcoverage[3990]);
            }
            ++(vlSelf->__Vcoverage[3991]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3814, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
            }
        }
    }
    if ((0x6000000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__16
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5360]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[5359]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[5361]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[5362]);
            }
            ++(vlSelf->__Vcoverage[5363]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5357, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5345, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 660, vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__reg_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 666, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2297, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2329, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni;
            }
        }
    }
    if ((0x0000001800000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__17
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4052]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[4051]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[4053]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[4054]);
            }
            ++(vlSelf->__Vcoverage[4055]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4049, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4036, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3842, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_sync 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
            }
        }
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__18(vlSelf);
    }
    if ((0x0060000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__20(vlSelf);
    }
    if ((0x0000000000180000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__21
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2218]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[2217]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2219]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2220]);
            }
            ++(vlSelf->__Vcoverage[2221]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2215, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1786, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__fifo_ctrl_qe 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe;
            }
        }
    }
    if ((0x0000000000600000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__22
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2231]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i;
            } else {
                ++(vlSelf->__Vcoverage[2230]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2232]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2233]);
            }
            ++(vlSelf->__Vcoverage[2234]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2228, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__q_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1782, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__wdata_qe 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe;
            }
        }
    }
    if ((0x0000000018000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__23
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2878]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2879]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2880]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2881]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2882]);
            }
            ++(vlSelf->__Vcoverage[2883]);
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2812, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2906, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2844, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2886]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2887]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2884]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2885]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2947, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 2828, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds;
            }
        }
    }
    if ((0x0000000001800000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__24
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2590]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2591]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2592]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2593]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2594]);
            }
            ++(vlSelf->__Vcoverage[2595]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2580, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2604, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2584, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2598]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2599]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2596]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2597]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2617, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2582, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds;
            }
        }
    }
    if ((0x0000000006000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__25
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2639]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2640]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2641]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2642]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2643]);
            }
            ++(vlSelf->__Vcoverage[2644]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2629, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2653, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2633, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2647]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2648]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2645]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2646]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2666, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2631, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds;
            }
        }
    }
    if ((0x0000000000000060ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__26
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[1886]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[1887]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1888]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1889]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1890]);
            }
            ++(vlSelf->__Vcoverage[1891]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1876, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1900, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1880, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[1894]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[1895]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[1892]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[1893]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1913, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1624, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_odd_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1878, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds;
            }
        }
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__27
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[1935]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[1936]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1937]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1938]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1939]);
            }
            ++(vlSelf->__Vcoverage[1940]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1925, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1949, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1929, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[1943]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[1944]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[1941]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[1942]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1962, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1620, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_parity_en_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1927, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds;
            }
        }
    }
    if ((0x0000000000000600ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__28
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[1984]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[1985]);
                }
            } else {
                ++(vlSelf->__Vcoverage[1986]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[1987]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[1988]);
            }
            ++(vlSelf->__Vcoverage[1989]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1974, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1998, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1978, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[1992]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[1993]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[1990]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[1991]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2011, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1616, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_llpbk_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1976, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds;
            }
        }
    }
    if ((0x0000000000001800ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__29
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2033]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2034]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2035]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2036]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2037]);
            }
            ++(vlSelf->__Vcoverage[2038]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2023, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2047, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2027, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2041]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2042]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2039]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2040]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2060, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1612, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_slpbk_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2025, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds;
            }
        }
    }
    if ((0x0000000000006000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__30
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2082]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2083]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2084]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2085]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2086]);
            }
            ++(vlSelf->__Vcoverage[2087]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2072, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2096, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2076, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2090]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2091]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2088]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2089]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2109, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1608, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nf_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2074, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds;
            }
        }
    }
    if ((0x0000000000018000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__31
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2131]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2132]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2133]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2134]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2135]);
            }
            ++(vlSelf->__Vcoverage[2136]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2121, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2145, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2125, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2139]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2140]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2137]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2138]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2158, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1604, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_rx_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2123, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds;
            }
        }
    }
    if ((0x0000000000060000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__32
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[2180]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[2181]);
                }
            } else {
                ++(vlSelf->__Vcoverage[2182]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[2183]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[2184]);
            }
            ++(vlSelf->__Vcoverage[2185]);
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2170, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2194, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2174, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2188]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[2189]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[2186]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[2187]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2207, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1600, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_tx_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2172, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds;
            }
        }
    }
    if ((0x0000000060000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__33
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) {
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
                    ++(vlSelf->__Vcoverage[3217]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data;
                } else {
                    ++(vlSelf->__Vcoverage[3218]);
                }
            } else {
                ++(vlSelf->__Vcoverage[3219]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q = 0x4b7fU;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni)))) {
                ++(vlSelf->__Vcoverage[3220]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) {
                ++(vlSelf->__Vcoverage[3221]);
            }
            ++(vlSelf->__Vcoverage[3222]);
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3087, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3261, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3151, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3225]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data;
            } else {
                ++(vlSelf->__Vcoverage[3226]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en) {
                ++(vlSelf->__Vcoverage[3223]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en)))) {
                ++(vlSelf->__Vcoverage[3224]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3334, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT____Vtogcov__gen_wunused_q 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 1628, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT____Vtogcov__ctrl_nco_qs 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs;
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds)))) {
                VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 3119, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__ds 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds;
            }
        }
    }
    if ((0x001e000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[4711]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4712]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) {
                ++(vlSelf->__Vcoverage[4713]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[4714]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4715]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[4716]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty))));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4633, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__wready_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4651, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rvalid_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o;
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready)))) {
                ++(vlSelf->__Vcoverage[3933]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) {
                ++(vlSelf->__Vcoverage[3934]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3808, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_wready 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid)))) {
                ++(vlSelf->__Vcoverage[3929]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) {
                ++(vlSelf->__Vcoverage[3930]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3806, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_rvalid 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid;
            }
        }
    }
    if ((0x0001e00000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__1
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[4196]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4197]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) {
                ++(vlSelf->__Vcoverage[4198]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))))) {
                ++(vlSelf->__Vcoverage[4199]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4200]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[4201]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o 
                = (1U & (~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) 
                            | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty))));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4112, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wready_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4130, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rvalid_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o;
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready)))) {
                ++(vlSelf->__Vcoverage[3931]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) {
                ++(vlSelf->__Vcoverage[3932]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3838, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wready 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready;
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid)))) {
                ++(vlSelf->__Vcoverage[3924]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) {
                ++(vlSelf->__Vcoverage[3925]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3836, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_rvalid 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid;
            }
        }
    }
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__34
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5321, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0600000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__35
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4071, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni;
            }
        }
    }
    if ((0x0000060000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__36
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3894, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5169, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4627, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4894, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni;
            }
        }
    }
    if ((0x0180000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__37
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3812, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_out 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
            }
        }
    }
    if (((1ULL & vlSelfRef.__VnbaTriggered[1U]) | (0x8000000000000000ULL 
                                                   & vlSelfRef.__VnbaTriggered[0U]))) {
        {
            // Inlined CFunc: _nba_sequent__TOP__38
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5355, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000018000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__39
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni;
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4045, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5000, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni;
            }
        }
    }
    if ((0x0000006000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__40
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4047, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT____Vtogcov__d_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i;
            }
        }
    }
    if ((0x0000001c80000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__2
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                 & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
                ++(vlSelf->__Vcoverage[4005]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                 & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) {
                ++(vlSelf->__Vcoverage[4006]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                 & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))) {
                ++(vlSelf->__Vcoverage[4007]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[4008]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[4009]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                        & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[4010]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync))))) {
                ++(vlSelf->__Vcoverage[4011]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[4012]);
            }
            if ((1U & (((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                        & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
                ++(vlSelf->__Vcoverage[4013]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))))) {
                ++(vlSelf->__Vcoverage[4014]);
            }
            if ((1U & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync)) 
                       & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1))))) {
                ++(vlSelf->__Vcoverage[4015]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj 
                = (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync) 
                    & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                       | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2))) 
                   | ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3998, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_maj 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
            }
        }
    }
    if ((0x0018000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__41
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
                VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 4681, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
            }
        }
    }
    if ((0x001a000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__3
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata 
                = (0x000000ffU & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                          >> ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr) 
                                              << 3U))));
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4853, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4872, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifordata_int 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[4890]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[4891]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[4888]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty)))) {
                ++(vlSelf->__Vcoverage[4889]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4655, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__rdata_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3788, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_fifo_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5181, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data;
            }
        }
    }
    if ((0x0001800000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__42
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr)))) {
                VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 4162, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr;
            }
        }
    }
    if ((0x0001a00000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
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
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4466, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifostorage_rdata 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4485, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifordata_int 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[4503]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 = 0U;
            } else {
                ++(vlSelf->__Vcoverage[4504]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty) {
                ++(vlSelf->__Vcoverage[4501]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty)))) {
                ++(vlSelf->__Vcoverage[4502]);
            }
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4134, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__rdata_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3580, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__uart_rdata 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata;
            }
        }
    }
    if ((0x6000000000000000ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__43
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
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2211, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2224, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2790, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2572, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2621, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1866, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1917, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 1966, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2015, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2064, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2113, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2162, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3017, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT____Vtogcov__rst_ni 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni;
            }
        }
    }
    if ((0x000000007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x001a00007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__6
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity 
                = (1U & (VL_REDXOR_8(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data) 
                         ^ (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                    >> 0x00000028U))));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5179, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__wr_parity 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity;
            }
        }
    }
    if ((0x0000001cffffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__7
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) {
                ++(vlSelf->__Vcoverage[4018]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj;
            } else {
                ++(vlSelf->__Vcoverage[4019]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_1;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable) {
                ++(vlSelf->__Vcoverage[4016]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable)))) {
                ++(vlSelf->__Vcoverage[4017]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3996, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in_mx 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx;
            }
        }
    }
    if ((0x00000002ffffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__8
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
                ++(vlSelf->__Vcoverage[3984]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i;
            } else {
                ++(vlSelf->__Vcoverage[3985]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_0;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
                ++(vlSelf->__Vcoverage[3982]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback)))) {
                ++(vlSelf->__Vcoverage[3983]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3546, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_o 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 330, vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o, vlSelfRef.uart_tb__DOT__u_uart__DOT____Vtogcov__tx_o);
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
    if ((0x006000007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__9
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5162]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1 
                    = (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                      >> 1U));
            } else {
                ++(vlSelf->__Vcoverage[5163]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1 
                    = (0x000000ffU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q) 
                                      >> 2U));
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____VlemCond_1;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable) {
                ++(vlSelf->__Vcoverage[5160]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable)))) {
                ++(vlSelf->__Vcoverage[5161]);
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
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 5012, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5032, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx_parity_err 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err;
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 3816, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_data 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data;
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid) 
                  & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err))) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err)))) {
                ++(vlSelf->__Vcoverage[4026]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err) {
                ++(vlSelf->__Vcoverage[4027]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) {
                ++(vlSelf->__Vcoverage[4028]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid)))) {
                ++(vlSelf->__Vcoverage[4029]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3888, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__event_rx_parity_err 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid 
                = ((~ ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err) 
                       | (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err))) 
                   & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
            if ((0U != ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i) 
                        ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i)))) {
                VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 4114, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wdata_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i;
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3834, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_fifo_wvalid 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4110, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__wvalid_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i;
            }
        }
    }
    if ((0x001e00007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__10
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
                  & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                ++(vlSelf->__Vcoverage[4717]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4718]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)))) {
                ++(vlSelf->__Vcoverage[4719]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i)))) {
                ++(vlSelf->__Vcoverage[4720]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i) 
                   & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4693, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)))) {
                ++(vlSelf->__Vcoverage[4966]);
            }
            if ((7U != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o))) {
                ++(vlSelf->__Vcoverage[4967]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i)))) {
                ++(vlSelf->__Vcoverage[4968]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4898, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                   & (7U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4962, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
            }
        }
    }
    if ((0x0001e0007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__11
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
                  & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                ++(vlSelf->__Vcoverage[4206]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4207]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)))) {
                ++(vlSelf->__Vcoverage[4208]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o)))) {
                ++(vlSelf->__Vcoverage[4209]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o) 
                   & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4180, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_rptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
                 & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)))) {
                ++(vlSelf->__Vcoverage[4596]);
            }
            if ((0x0fU != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o))) {
                ++(vlSelf->__Vcoverage[4597]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i)))) {
                ++(vlSelf->__Vcoverage[4598]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4513, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_rptr_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i) 
                   & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4591, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__rptr_wrap_set 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
            }
        }
    }
    if ((0x018000007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__12
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
                ++(vlSelf->__Vcoverage[5305]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1 
                    = (0U == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q));
            } else {
                ++(vlSelf->__Vcoverage[5306]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1 = 1U;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____VlemCond_1;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable) {
                ++(vlSelf->__Vcoverage[5303]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable)))) {
                ++(vlSelf->__Vcoverage[5304]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5197, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT____Vtogcov__idle 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3810, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__tx_uart_idle 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle;
            }
        }
    }
    if ((0x0180001cffffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__13
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
                ++(vlSelf->__Vcoverage[4022]);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out;
            } else {
                ++(vlSelf->__Vcoverage[4025]);
                if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback) {
                    ++(vlSelf->__Vcoverage[4023]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 = 1U;
                } else {
                    ++(vlSelf->__Vcoverage[4024]);
                    vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2 
                        = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx;
                }
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____VlemCond_2;
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback) {
                ++(vlSelf->__Vcoverage[4020]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback)))) {
                ++(vlSelf->__Vcoverage[4021]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 3844, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT____Vtogcov__rx_in 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 5034, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT____Vtogcov__rx 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx;
            }
        }
    }
    if ((0x0061e0007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__14
            if ((((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
                  & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)) 
                 & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)))) {
                ++(vlSelf->__Vcoverage[4202]);
            }
            if (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
                ++(vlSelf->__Vcoverage[4203]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)))) {
                ++(vlSelf->__Vcoverage[4204]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i)))) {
                ++(vlSelf->__Vcoverage[4205]);
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i) 
                   & ((~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4178, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT____Vtogcov__gen_normal_fifofifo_incr_wptr 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i 
                = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)))) {
                ++(vlSelf->__Vcoverage[4593]);
            }
            if ((0x0fU != (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o))) {
                ++(vlSelf->__Vcoverage[4594]);
            }
            if ((1U & (~ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i)))) {
                ++(vlSelf->__Vcoverage[4595]);
            }
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4511, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__incr_wptr_i 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i;
            }
            vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
                = ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i) 
                   & (0x0fU == (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o)));
            if (((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) 
                 ^ (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set))) {
                VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4589, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set);
                vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT____Vtogcov__wptr_wrap_set 
                    = vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
            }
        }
    }
    if ((0x019e00007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__15(vlSelf);
    }
    if ((0x01ffe0007fffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__16(vlSelf);
    }
    if ((0x01e0001dffffffe0ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__17(vlSelf);
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
        {
            // Inlined CFunc: _eval_act
            if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__0(vlSelf);
            }
            if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__1(vlSelf);
            }
            if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
                Vtop___024root___act_sequent__TOP__2(vlSelf);
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
        VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
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
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/tmp/flexsoc-ip-v1-release-20260914/uart-reg_iface/runs/uart/release/dv/functional/tb/cocotb/uart_tb.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
