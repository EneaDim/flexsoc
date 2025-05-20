// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb___024root.h"

VL_ATTR_COLD void Vspi_host_tb___024root___eval_initial__TOP(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_initial__TOP\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.sram2tlul__02Etl_o[2U] = (0xfffffffU 
                                        & vlSelfRef.sram2tlul__02Etl_o[2U]);
    vlSelfRef.sram2tlul__02Etl_o[3U] = (0x20U | (0x1fc0U 
                                                 & vlSelfRef.sram2tlul__02Etl_o[3U]));
    vlSelfRef.w_sram_wmask_o = 0xffffffffU;
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o = 0ULL;
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = (0x7effffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o);
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = ((0x7dffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o))))) 
              << 0x21U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = ((0x7bffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o))))) 
              << 0x22U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = ((0x77ffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o))))) 
              << 0x23U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = ((0x6fffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o))))) 
              << 0x24U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = ((0x5fffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o))))) 
              << 0x25U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = ((0x3fffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o))))) 
              << 0x26U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
        = (0x2a00000000ULL ^ vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o);
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o = 0xffffffffULL;
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = (0x7effffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o);
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = ((0x7dffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xdeba8050ULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o))))) 
              << 0x21U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = ((0x7bffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x413d89aaULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o))))) 
              << 0x22U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = ((0x77ffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x31234ed1ULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o))))) 
              << 0x23U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = ((0x6fffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0xc2c1323bULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o))))) 
              << 0x24U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = ((0x5fffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x2dcc624cULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o))))) 
              << 0x25U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = ((0x3fffffffffULL & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o) 
           | ((QData)((IData)((1U & VL_REDXOR_64((0x98505586ULL 
                                                  & vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o))))) 
              << 0x26U));
    vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
        = (0x2a00000000ULL ^ vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o);
    vlSelfRef.w_sram_write_o = 1U;
    vlSelfRef.r_sram_write_o = 0U;
    vlSelfRef.r_sram_wdata_o = 0U;
    vlSelfRef.r_sram_wmask_o = 0U;
    vlSelfRef.compound_txn_in_progress_o = 0U;
    vlSelfRef.intg_err_o = 0U;
    vlSelfRef.readback_error_o = 0U;
}

VL_ATTR_COLD void Vspi_host_tb___024root___eval_final(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_final\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host_tb___024root___dump_triggers__stl(Vspi_host_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vspi_host_tb___024root___eval_phase__stl(Vspi_host_tb___024root* vlSelf);

VL_ATTR_COLD void Vspi_host_tb___024root___eval_settle(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_settle\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vspi_host_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/spi_host.v", 311, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vspi_host_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host_tb___024root___dump_triggers__stl(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___dump_triggers__stl\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vspi_host_tb___024root___stl_sequent__TOP__0(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___stl_sequent__TOP__0\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp = 0;
    IData/*31:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout;
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val;
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__inp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in = 0;
    QData/*56:0*/ __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload;
    __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload = 0;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_11;
    VlWide<4>/*127:0*/ __Vtemp_12;
    VlWide<4>/*127:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<4>/*127:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<4>/*127:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_27;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<4>/*127:0*/ __Vtemp_33;
    // Body
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.tlul_adapter_sram__DOT__wmask_intg = 0U;
    vlSelfRef.tlul_adapter_sram__DOT__wdata_intg = 0U;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    vlSelfRef.dst_data_o = vlSelfRef.src_data_i;
    vlSelfRef.mem_rvalid_o = ((vlSelfRef.sram2tlul__02Etl_i[2U] 
                               >> 1U) & (1U == (7U 
                                                & ((vlSelfRef.sram2tlul__02Etl_i[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.sram2tlul__02Etl_i[1U] 
                                                      >> 0x1eU)))));
    vlSelfRef.mem_rdata_o = ((vlSelfRef.sram2tlul__02Etl_i[1U] 
                              << 0x10U) | (vlSelfRef.sram2tlul__02Etl_i[0U] 
                                           >> 0x10U));
    vlSelfRef.mem_error_o = (3U & (- (IData)((1U & 
                                              (vlSelfRef.sram2tlul__02Etl_i[0U] 
                                               >> 1U)))));
    vlSelfRef.prim_fifo_async_simple__02Erdata_o = vlSelfRef.prim_fifo_async_simple__DOT__data_q;
    vlSelfRef.tlul_adapter_host__02Erdata_o = ((vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                << 0x10U) 
                                               | (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                                  >> 0x10U));
    vlSelfRef.rdata_intg_o = (0x7fU & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                       >> 2U));
    vlSelfRef.err_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                             >> 1U));
    vlSelfRef.req_type_o = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                    >> 0xfU));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.intg_error_o = vlSelfRef.tlul_adapter_sram__DOT__intg_error_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni));
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0xeU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.sram2tlul__02Etl_o[0U] = (IData)((1ULL 
                                                | ((QData)((IData)(vlSelfRef.mem_wdata_i)) 
                                                   << 0x18U)));
    vlSelfRef.sram2tlul__02Etl_o[1U] = ((0xff000000U 
                                         & (0xf000000U 
                                            | ((IData)(vlSelfRef.mem_addr_i) 
                                               << 0x1eU))) 
                                        | (IData)((
                                                   (1ULL 
                                                    | ((QData)((IData)(vlSelfRef.mem_wdata_i)) 
                                                       << 0x18U)) 
                                                   >> 0x20U)));
    vlSelfRef.sram2tlul__02Etl_o[2U] = ((0xf0000000U 
                                         & vlSelfRef.sram2tlul__02Etl_o[2U]) 
                                        | (0xffffffU 
                                           & ((IData)(vlSelfRef.mem_addr_i) 
                                              >> 2U)));
    vlSelfRef.sram2tlul__02Etl_o[3U] = ((0x3fU & vlSelfRef.sram2tlul__02Etl_o[3U]) 
                                        | (0x1fc0U 
                                           & (((IData)(vlSelfRef.mem_req_i) 
                                               << 0xcU) 
                                              | (((IData)(vlSelfRef.mem_write_i)
                                                   ? 0U
                                                   : 4U) 
                                                 << 9U))));
    vlSelfRef.prim_filter__02Efilter_o = ((IData)(vlSelfRef.prim_filter__02Eenable_i)
                                           ? (IData)(vlSelfRef.prim_filter__DOT__stored_value_q)
                                           : (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_filter_ctr__02Efilter_o = ((IData)(vlSelfRef.prim_filter_ctr__02Eenable_i)
                                               ? (IData)(vlSelfRef.prim_filter_ctr__DOT__stored_value_q)
                                               : (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
    vlSelfRef.tlul_adapter_sram__DOT__wmask_int = 0U;
    vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d = (((IData)(vlSelfRef.prim_filter_ctr__02Efilter_i) 
                                                   == (IData)(vlSelfRef.prim_filter_ctr__DOT__filter_q))
                                                   ? 
                                                  (3U 
                                                   & (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q) 
                                                       >= (IData)(vlSelfRef.thresh_i))
                                                       ? (IData)(vlSelfRef.thresh_i)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q))))
                                                   : 0U);
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp 
        = (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp;
    vlSelfRef.w_sram_addr_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp;
    vlSelfRef.w_sram_wdata_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp 
        = (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp;
    vlSelfRef.r_sram_addr_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout;
    if ((0x1000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        vlSelfRef.tlul_adapter_sram__DOT__sv2v_autoblock_1__DOT__i = 4U;
        vlSelfRef.tlul_adapter_sram__DOT__wmask_intg = 0x7fU;
        vlSelfRef.tlul_adapter_sram__DOT__wdata_intg 
            = (0x7fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                        >> 1U));
        vlSelfRef.addr_o = (0xfffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                       << 2U) | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                 >> 0x1eU)));
        vlSelfRef.tlul_adapter_sram__DOT__wmask_int 
            = ((0xffff0000U & vlSelfRef.tlul_adapter_sram__DOT__wmask_int) 
               | ((0xff00U & ((- (IData)((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                >> 0x19U)))) 
                              << 8U)) | (0xffU & (- (IData)(
                                                            (1U 
                                                             & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                >> 0x18U)))))));
        vlSelfRef.tlul_adapter_sram__DOT__wmask_int 
            = ((0xffffU & vlSelfRef.tlul_adapter_sram__DOT__wmask_int) 
               | (((- (IData)((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                     >> 0x1bU)))) << 0x18U) 
                  | (0xff0000U & ((- (IData)((1U & 
                                              (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                               >> 0x1aU)))) 
                                  << 0x10U))));
    } else {
        vlSelfRef.addr_o = 0U;
    }
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__inp 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                               >> 0x18U));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__Vfuncout)) 
           << 1U);
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__inp 
        = (0xfU & (vlSelfRef.h2d[5U] >> 5U));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__124__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__inp 
        = (QData)((IData)(((vlSelfRef.h2d[5U] << 0x1bU) 
                           | (vlSelfRef.h2d[4U] >> 5U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__125__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__inp 
        = (QData)((IData)(((vlSelfRef.d2h[3U] << 0xeU) 
                           | (vlSelfRef.d2h[2U] >> 0x12U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__127__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__inp 
        = (0xfU & (vlSelfRef.h2d[1U] >> 0x18U));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__128__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__inp 
        = (QData)((IData)(((vlSelfRef.h2d[1U] << 8U) 
                           | (vlSelfRef.h2d[0U] >> 0x18U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__129__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__inp 
        = (QData)((IData)(((vlSelfRef.d2h[1U] << 0x10U) 
                           | (vlSelfRef.d2h[0U] >> 0x10U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__131__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__inp 
        = ((0x9ffU >= (0xfffU & ((IData)(0xaU) * (0xffU 
                                                  & (vlSelfRef.d2h[3U] 
                                                     >> 0x13U)))))
            ? (0xfU & (((0U == (0x1fU & ((IData)(0xaU) 
                                         * (0xffU & 
                                            (vlSelfRef.d2h[3U] 
                                             >> 0x13U)))))
                         ? 0U : (vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req[
                                 (((IData)(3U) + (0xfffU 
                                                  & ((IData)(0xaU) 
                                                     * 
                                                     (0xffU 
                                                      & (vlSelfRef.d2h[3U] 
                                                         >> 0x13U))))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.d2h[3U] 
                                                        >> 0x13U))))))) 
                       | (vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req[
                          (0x7fU & (((IData)(0xaU) 
                                     * (0xffU & (vlSelfRef.d2h[3U] 
                                                 >> 0x13U))) 
                                    >> 5U))] >> (0x1fU 
                                                 & ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.d2h[3U] 
                                                        >> 0x13U)))))))
            : 0U);
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__126__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__inp 
        = ((0x9ffU >= (0xfffU & ((IData)(0xaU) * (0xffU 
                                                  & (vlSelfRef.d2h[1U] 
                                                     >> 0x11U)))))
            ? (0xfU & (((0U == (0x1fU & ((IData)(0xaU) 
                                         * (0xffU & 
                                            (vlSelfRef.d2h[1U] 
                                             >> 0x11U)))))
                         ? 0U : (vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req[
                                 (((IData)(3U) + (0xfffU 
                                                  & ((IData)(0xaU) 
                                                     * 
                                                     (0xffU 
                                                      & (vlSelfRef.d2h[1U] 
                                                         >> 0x11U))))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.d2h[1U] 
                                                        >> 0x11U))))))) 
                       | (vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req[
                          (0x7fU & (((IData)(0xaU) 
                                     * (0xffU & (vlSelfRef.d2h[1U] 
                                                 >> 0x11U))) 
                                    >> 5U))] >> (0x1fU 
                                                 & ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.d2h[1U] 
                                                        >> 0x11U)))))))
            : 0U);
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__130__Vfuncout;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d 
        = ((IData)(vlSelfRef.r_sram_rvalid_i) ? vlSelfRef.r_sram_rdata_i
            : 0U);
    vlSelfRef.valid_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                               >> 1U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub 
        = (0x1fU & (((IData)(0x10U) - (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval))) 
                    - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in 
        = ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in 
        = (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout 
        = (0x1fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout) 
                    ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout 
        = ((0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout)) 
           | (0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub 
        = (0x1fU & (((IData)(0x10U) - (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval))) 
                    - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in 
        = ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in 
        = (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout 
        = (0x1fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout) 
                    ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout 
        = ((0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout)) 
           | (0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout;
    vlSelfRef.prim_fifo_async_simple__02Ewready_o = 
        ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
    vlSelfRef.gnt_o = (1U & vlSelfRef.tlul_adapter_host__02Etl_i[0U]);
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp = 0U;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp = 0U;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout;
    vlSelfRef.prim_fifo_async_simple__DOT__src_ack = 0U;
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.we_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                       >> 0xcU) & ((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                 >> 9U))) 
                                   | (1U == (7U & (
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 9U)))));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_req = 0U;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
           == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
           == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval 
        = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb = 0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp = 0U;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval) 
                 >> 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x17U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 3U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp) 
                  >> 3U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval) 
                            >> 2U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x1bU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 2U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp) 
                  >> 2U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval) 
                            >> 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x1dU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 1U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x1eU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | (IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub 
        = (0x1fU & (((IData)(0x10U) - (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
                    - (IData)(1U)));
    if ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval))) {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub;
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout 
            = (0x10U | (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout));
        __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub) 
                     >> 4U));
    } else {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp;
    }
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr 
        = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval 
        = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb = 0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp = 0U;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval) 
                 >> 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x17U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 3U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp) 
                  >> 3U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval) 
                            >> 2U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x1bU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 2U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp) 
                  >> 2U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval) 
                            >> 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x1dU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 1U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x1eU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | (IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub 
        = (0x1fU & (((IData)(0x10U) - (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
                    - (IData)(1U)));
    if ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval))) {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub;
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout 
            = (0x10U | (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout));
        __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub) 
                     >> 4U));
    } else {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp;
    }
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr 
        = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout;
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk 
        = ((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                              >> 4U))) 
                                || (1U & ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                     >> 4U)))
                                           ? (~ (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                 >> 0x1cU))
                                           : ((2U == 
                                               (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U))) 
                                              && (1U 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != 
                                                                (3U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                    >> 0x1cU)))))))))));
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk 
        = ((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                  >> 0xcU)) && (1U & ((0U == (3U & 
                                              (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                               >> 4U)))
                                       ? (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0xfU 
                                                      & (((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                           << 8U) 
                                                          | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                             >> 0x18U)) 
                                                         & (~ 
                                                            ((IData)(1U) 
                                                             << 
                                                             (3U 
                                                              & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                 >> 0x1cU)))))))))
                                       : ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                     >> 4U)))
                                           ? ((0x20000000U 
                                               & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                                               ? (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (3U 
                                                              & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                 >> 0x18U)))))
                                               : (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0xcU 
                                                              & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                 >> 0x18U))))))
                                           : (2U == 
                                              (3U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 4U)))))));
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk 
        = ((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                              >> 4U)))
                                 ? (0U != (0xfU & (
                                                   ((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                     << 8U) 
                                                    | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                       >> 0x18U)) 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                          >> 0x1cU))))))
                                 : ((1U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                  >> 4U)))
                                     ? ((0x20000000U 
                                         & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                                         ? (3U == (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x1aU)))
                                         : (3U == (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x18U))))
                                     : ((2U == (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U))) 
                                        && (0xfU == 
                                            (0xfU & 
                                             (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                              >> 0x18U)))))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout 
        = __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp;
    vlSelfRef.tlul_adapter_host__DOT__tl_source = __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout;
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
            = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack;
    }
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__dst_req 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__dst_req 
            = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req;
    }
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__Vfuncout)) 
           & ((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U)))));
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val 
        = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                   >> 0xfU));
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val)) 
                    | (9U == (IData)(__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp = 0U;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp = 0U;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout;
    vlSelfRef.tlul_adapter_sram__DOT__instr_error = 
        (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__Vfuncout)) 
         | (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                   >> 0xfU));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__Vfuncout)) 
            & ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__val 
                        = vlSelfRef.en_ifetch_i;
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__Vfuncout 
                        = (6U != (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__Vfuncout))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
        = (2U | ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]) 
                 | (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending)))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0xc000ffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (0xffff0000U & (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size) 
                              << 0x19U) | ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source) 
                                           << 0x11U))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0x3fffffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                ? 1U : 0U) << 0x1eU));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
                                 << 1U)) | (((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                                              ? 1U : 0U) 
                                            >> 2U)));
    VL_ASSIGNSEL_WI(66,32,0x10U, vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int, 
                    (([&]() {
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__val 
                        = vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type;
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__Vfuncout))
                      ? 0U : 0xffffffffU));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (0xfffeU & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffffU & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                                        >> 0x1eU))))
                ? ((vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                    << 0x10U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[0U] 
                                 >> 0x10U)) : 0U) << 0x10U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                                        >> 0x1eU))))
                ? ((vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                    << 0x10U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[0U] 
                                 >> 0x10U)) : 0U) >> 0x10U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffffU & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & vlSelfRef.tlul_socket_m1__02Etl_d_i[1U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & vlSelfRef.tlul_socket_m1__02Etl_d_i[2U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_9, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                        << 0x1dU) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xcU] 
                                     >> 3U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__inp 
                                    = (0xfU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xcU] 
                                                << 1U) 
                                               | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xbU] 
                                                  >> 0x1fU)));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xbU] 
                                            << 1U) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                              >> 0x1fU));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                                  >> 8U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                                                     >> 7U))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_10, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__inp 
                    = (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                >> 1U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__Vfuncout)), __Vtemp_9);
    VL_CONCAT_WIW(102,2,100, __Vtemp_11, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0xbU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__Vfuncout)), __Vtemp_10);
    VL_CONCAT_WIW(105,3,102, __Vtemp_12, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0xdU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__Vfuncout)), __Vtemp_11);
    VL_CONCAT_WIW(108,3,105, __Vtemp_13, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0x10U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__Vfuncout)), __Vtemp_12);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_13[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_13[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_13[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                       >> 7U)) | __Vtemp_13[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_14, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                        << 0xaU) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                    >> 0x16U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                               >> 0x12U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                            << 0xeU) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[7U] 
                                              >> 0x12U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__inp 
                                            = (0x7fffffU 
                                               & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[7U] 
                                                   << 5U) 
                                                  | (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                                     >> 0x1bU)));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                                                     >> 0x1aU))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_15, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__inp 
                    = (1U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                      >> 0x14U)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__Vfuncout)), __Vtemp_14);
    VL_CONCAT_WIW(102,2,100, __Vtemp_16, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__inp 
                    = (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                       >> 0x1eU);
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__Vfuncout)), __Vtemp_15);
    VL_CONCAT_WIW(105,3,102, __Vtemp_17, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__inp 
                    = (7U & vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU]);
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__Vfuncout)), __Vtemp_16);
    VL_CONCAT_WIW(108,3,105, __Vtemp_18, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                             >> 3U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__Vfuncout)), __Vtemp_17);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_18[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_18[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_18[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                       << 6U)) | __Vtemp_18[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_19, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                        << 0x17U) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                     >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                               >> 5U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                            << 0x1bU) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[4U] 
                                              >> 5U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__inp 
                                            = (0x7fffffU 
                                               & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[4U] 
                                                   << 0x12U) 
                                                  | (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                     >> 0xeU)));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                                     >> 0xdU))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_20, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__inp 
                    = (2U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                      >> 7U)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__Vfuncout)), __Vtemp_19);
    VL_CONCAT_WIW(102,2,100, __Vtemp_21, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x11U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__Vfuncout)), __Vtemp_20);
    VL_CONCAT_WIW(105,3,102, __Vtemp_22, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x13U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__Vfuncout)), __Vtemp_21);
    VL_CONCAT_WIW(108,3,105, __Vtemp_23, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x16U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__Vfuncout)), __Vtemp_22);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_23[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_23[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_23[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                       >> 0xdU)) | __Vtemp_23[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_24, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                        << 4U) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                  >> 0x1cU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                               >> 0x18U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                            << 8U) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0U] 
                                              >> 0x18U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0U] 
                                                  >> 1U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & vlSelfRef.tlul_socket_m1__02Etl_h_i[0U])))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_25, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__inp 
                    = (3U | (0xfcU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                       << 6U) | (0x3cU 
                                                 & (vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                                                    >> 0x1aU)))));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__Vfuncout)), __Vtemp_24);
    VL_CONCAT_WIW(102,2,100, __Vtemp_26, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 4U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__Vfuncout)), __Vtemp_25);
    VL_CONCAT_WIW(105,3,102, __Vtemp_27, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 6U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__Vfuncout)), __Vtemp_26);
    VL_CONCAT_WIW(108,3,105, __Vtemp_28, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__Vfuncout)), __Vtemp_27);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_28[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & vlSelfRef.tlul_socket_m1__02Etl_h_i[3U]) 
           | __Vtemp_28[3U]);
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U] 
        = ((0xfffffff8U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[0U] 
                           << 2U)) | (IData)(vlSelfRef.dev_select_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[0U] 
                              >> 0x1eU)) | (0xfffffff8U 
                                            & (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                                               << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                              >> 0x1eU)) | (0xfffffff8U 
                                            & (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                                               << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                              >> 0x1eU)) | (0x3ff8U 
                                            & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                                               << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.wmask_o = vlSelfRef.tlul_adapter_sram__DOT__wmask_int;
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    if (((IData)(vlSelfRef.req_i) & (IData)(vlSelfRef.gnt_o))) {
        vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
            = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q))));
    }
    vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d 
        = vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q;
    if ((((IData)(vlSelfRef.req_i) & (IData)(vlSelfRef.gnt_o)) 
         & (~ (IData)(vlSelfRef.valid_o)))) {
        vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q)));
    } else if (((~ ((IData)(vlSelfRef.req_i) & (IData)(vlSelfRef.gnt_o))) 
                & (IData)(vlSelfRef.valid_o))) {
        vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d 
            = (3U & ((IData)(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q) 
                     - (IData)(1U)));
    }
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    vlSelfRef.tlul_adapter_sram__DOT__wdata_int = 0U;
    if ((0x1000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xffffff00U & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | (((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                    >> 0x18U) & (IData)(vlSelfRef.we_o))
                   ? (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                      >> 0x18U) : 0U));
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xffff00ffU & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                     >> 0x19U) & (IData)(vlSelfRef.we_o))
                    ? (0xffU & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                    : 0U) << 8U));
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xff00ffffU & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                     >> 0x1aU) & (IData)(vlSelfRef.we_o))
                    ? (0xffU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                >> 8U)) : 0U) << 0x10U));
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xffffffU & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                     >> 0x1bU) & (IData)(vlSelfRef.we_o))
                    ? (0xffU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                >> 0x10U)) : 0U) << 0x18U));
    }
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    vlSelfRef.prim_fifo_async_simple__02Ervalid_o = vlSelfRef.prim_fifo_async_simple__DOT__dst_req;
    vlSelfRef.prim_fifo_async_simple__DOT__dst_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__src_req;
    }
    vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
            ? vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q
            : vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d);
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__119__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__119__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__119__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__119__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__120__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__120__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__120__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__120__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__123__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__123__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__123__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__123__Vfuncout))))));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0xcU));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__wdepth_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)
            ? 4U : (7U & (((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__136__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__136__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__136__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__136__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__137__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__137__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__137__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__137__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__139__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__139__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__139__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__139__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__140__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__140__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__140__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__140__Vfuncout))))));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__wdepth_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)
            ? 4U : (7U & (((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__159__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__159__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__159__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__159__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__160__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__160__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__160__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__160__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__162__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__162__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__162__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__162__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__163__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__163__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__163__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__163__Vfuncout))))));
    vlSelfRef.r_full_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr) 
                          == (0x10U ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr) 
           == (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr));
    vlSelfRef.rdepth_o = (((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr) 
                                  >> 4U)) == (1U & 
                                              ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                               >> 4U)))
                           ? ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__inp 
                    = (0x1fU & ((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr)) 
                                - (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__Vfuncout))
                           : ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__inp 
                    = (0x1fU & ((0x10U | (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))) 
                                - (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__Vfuncout)));
    vlSelfRef.wdepth_o = (((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                                  >> 4U)) == (1U & 
                                              ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr) 
                                               >> 4U)))
                           ? ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__inp 
                    = (0x1fU & ((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)) 
                                - (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__Vfuncout))
                           : ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__inp 
                    = (0x1fU & ((0x10U | (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q))) 
                                - (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__Vfuncout)));
    vlSelfRef.w_full_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                          == (0x10U ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__304__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__304__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__304__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__304__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__305__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__305__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__305__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__305__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__307__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__307__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__307__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__307__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__308__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__308__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__308__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__308__Vfuncout))))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__206__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__206__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__206__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__206__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__207__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__207__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__207__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__207__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__209__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__209__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__209__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__209__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__210__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__210__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__210__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__210__Vfuncout))))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    VL_CONCAT_WIQ(92,32,60, __Vtemp_32, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp 
                    = (0xfffffffcU & vlSelfRef.addr_i);
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp;
            }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp 
                                    = ((IData)(vlSelfRef.we_i)
                                        ? (IData)(vlSelfRef.be_i)
                                        : 0xfU);
                                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp 
                                        = vlSelfRef.tlul_adapter_host__02Ewdata_i;
                                    vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp;
                                }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              (1U 
                                                               | (([&]() {
                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp 
                                            = ((VL_EXTEND_II(9,4, 
                                                             ([&]() {
                                                            vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp 
                                                                = vlSelfRef.instr_type_i;
                                                            vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout 
                                                                = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp;
                                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout))) 
                                                << 0xeU) 
                                               | VL_EXTEND_II(14,7, 
                                                              ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp 
                                                            = vlSelfRef.wdata_intg_i;
                                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp;
                                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout))));
                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout) 
                                                                  << 1U)))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_33, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp 
                    = vlSelfRef.tlul_adapter_host__DOT__tl_source;
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout)), __Vtemp_32);
    vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] = 
        __Vtemp_33[0U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[1U] = 
        __Vtemp_33[1U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[2U] = 
        __Vtemp_33[2U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[3U] = 
        (0x20U | (((IData)(vlSelfRef.req_i) << 0xcU) 
                  | ((((IData)(vlSelfRef.we_i) ? ((0xfU 
                                                   == (IData)(vlSelfRef.be_i))
                                                   ? 0U
                                                   : 1U)
                        : 4U) << 9U) | __Vtemp_33[3U])));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
           == (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__rdepth_o 
        = (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
            == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))
            ? 4U : (7U & (((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__142__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__142__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__142__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__142__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__143__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__143__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__143__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__143__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__145__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__145__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__145__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__145__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__146__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__146__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__146__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__146__Vfuncout))))));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
           == (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__rdepth_o 
        = (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
            == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))
            ? 4U : (7U & (((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__165__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__165__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__165__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__165__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__166__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__166__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__166__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__166__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__168__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__168__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__168__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__168__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__169__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__169__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__169__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__169__Vfuncout))))));
    vlSelfRef.tlul_adapter_sram__DOT__error_det = (1U 
                                                   & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__instr_error) 
                                                      | ((~ 
                                                          (((0U 
                                                             == 
                                                             (7U 
                                                              & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                 >> 9U))) 
                                                            | ((1U 
                                                                == 
                                                                (7U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                    >> 9U))) 
                                                               | (4U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
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
                                                            | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err)))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][0U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][1U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][2U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U];
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__110__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__110__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__110__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__110__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__111__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__111__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__111__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__111__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__114__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__114__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__114__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__114__Vfuncout))))));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__101__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__101__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__101__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__101__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__102__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__102__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__102__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__102__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__105__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__105__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__105__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__105__Vfuncout))))));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__295__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__295__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__295__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__295__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__296__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__296__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__296__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__296__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__298__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__298__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__298__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__298__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__299__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__299__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__299__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__299__Vfuncout))))));
    vlSelfRef.tlul_socket_m1__DOT__arb_ready = (1U 
                                                & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o)) 
                                                   & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__215__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__215__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__215__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__215__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__216__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__216__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__216__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__216__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__218__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__218__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__218__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__218__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__219__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__219__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__219__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__219__Vfuncout))))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        }
    }
    vlSelfRef.wdata_o = vlSelfRef.tlul_adapter_sram__DOT__wdata_int;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.r_sram_req_o = 0U;
    vlSelfRef.r_sram_req_o = (1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
                                     ? ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))
                                     : ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                              ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))))));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = vlSelfRef.tlul_adapter_host__DOT__tl_out[0U];
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = vlSelfRef.tlul_adapter_host__DOT__tl_out[1U];
    vlSelfRef.tlul_adapter_host__02Etl_o[2U] = vlSelfRef.tlul_adapter_host__DOT__tl_out[2U];
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = vlSelfRef.tlul_adapter_host__DOT__tl_out[3U];
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = ((0xffffffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[0U]) 
                                                | (0xff000000U 
                                                   & vlSelfRef.tlul_adapter_host__DOT__tl_out[0U]));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0xff000000U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | (0xffffffU 
                                                   & vlSelfRef.tlul_adapter_host__DOT__tl_out[1U]));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = ((0xffff8001U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[0U]) 
                                                | (0x7ffeU 
                                                   & vlSelfRef.tlul_adapter_host__DOT__tl_out[0U]));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (1U 
                                                   & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk))));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[1U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                 >> 0x1fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[2U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                 >> 0x1fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0x1000U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x1fffU 
                                                   & ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                         ? 0U
                                                         : 
                                                        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                       >> 0x1fU) 
                                                      | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                           ? 0U
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][3U]) 
                                                         << 1U))));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0xfffU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x1000U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                                                      << 0xcU)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | (1U 
                                                   & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk))));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | ((IData)(
                                                           ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                             ? 0ULL
                                                             : 
                                                            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                            [
                                                            (3U 
                                                             & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[1U] = (((IData)(
                                                         ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                           ? 0ULL
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                 >> 0x1fU) 
                                                | ((IData)(
                                                           (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                              ? 0ULL
                                                              : 
                                                             vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                             [
                                                             (3U 
                                                              & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                            >> 0x20U)) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((2U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (3U 
                                                   & ((IData)(
                                                              (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                                 ? 0ULL
                                                                 : 
                                                                vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                                [
                                                                (3U 
                                                                 & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                               >> 0x20U)) 
                                                      >> 0x1fU)));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (2U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                                                      << 1U)));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__dst_ack;
    }
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata 
        = ((((4U != (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                           >> 9U))) ? 0U : 1U) << 0xfU) 
           | (((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
               << 0xeU) | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__inp 
                                = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                           >> 0xfU));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__Vfuncout)) 
                            << 0xaU) | ((([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__inp 
                                    = (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             >> 4U));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__Vfuncout)) 
                                         << 8U) | ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__inp 
                                = (0xffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                               >> 0x1cU)));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__Vfuncout))))));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                    & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask = 0U;
    vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask 
        = ((0xffff0000U & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask) 
           | ((0xff00U & ((- (IData)((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                            >> 2U)))) 
                          << 8U)) | (0xffU & (- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                                            >> 1U)))))));
    vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask 
        = ((0xffffU & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask) 
           | (((- (IData)((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                 >> 4U)))) << 0x18U) 
              | (0xff0000U & ((- (IData)((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                                >> 3U)))) 
                              << 0x10U))));
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                               >> 0xaU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__Vfuncout))
            ? 0U : 0xffffffffU);
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ 
        = (0x7fU & (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                   >> 0xaU));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__Vfuncout))
                     ? (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
                                >> 0x20U)) : (IData)(
                                                     (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
                                                      >> 0x20U))));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & (IData)(vlSelfRef.rvalid_i));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
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
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.we_o)) & ((IData)(vlSelfRef.req_o) 
                                           & (IData)(vlSelfRef.gnt_i))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata 
        = (((QData)((IData)((vlSelfRef.rdata_i & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__0__KET__ 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & (0U == (0x60000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__1__KET__ 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & (0x20000U == (0x60000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__2__KET__ 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & (0x40000U == (0x60000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__3__KET__ 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
           & (0x60000U == (0x60000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])));
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
        = (((IData)((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U)))) 
            << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__arb_ready));
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
    vlSelfRef.tlul_socket_1n__DOT__hold_all_requests 
        = ((0U != (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)) 
           & ((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]) 
              != (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding)));
    vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] = (((
                                                   vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                   << 0x1eU) 
                                                  | (0x3ffffffeU 
                                                     & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                                        >> 2U))) 
                                                 | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] = ((1U 
                                                  & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                     >> 2U)) 
                                                 | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                     << 0x1eU) 
                                                    | (0x3ffffffeU 
                                                       & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                          >> 2U))));
    vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U] = ((1U 
                                                  & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                     >> 2U)) 
                                                 | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                     << 0x1eU) 
                                                    | (0x3ffffffeU 
                                                       & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                          >> 2U))));
    vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U] = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                                  << 0xcU) 
                                                 | ((1U 
                                                     & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                        >> 2U)) 
                                                    | (0xffeU 
                                                       & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                                          >> 2U))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)
            ? 0ULL : (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                       & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                       ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                       : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select 
        = ((0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select 
        = ((1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select 
        = ((2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select 
        = ((3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0xe00U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x1c0U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x30U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][2U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0xfU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][2U]) | (0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (0xf000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0xe00U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x1c0U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x30U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][2U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0xfU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][2U]) | (0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (0xf000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0xe00U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x1c0U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x30U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][2U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0xfU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][2U]) | (0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (0xf000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0xe00U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x1c0U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x30U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][2U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0xfU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][2U]) | (0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (0xf000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0xe00U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x1c0U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x30U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][2U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0xfU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][2U]) | (0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xf000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (0xfffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x1000U & ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U] 
                                   & ((4U <= (7U & 
                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
                                      << 0xcU)) & (
                                                   (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
                                                   << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__blanked_auser = 
        ((([&]() {
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp 
                        = (0x1fU & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                    >> 0x13U));
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout)) 
          << 0x12U) | ((([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp 
                            = (0xfU & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0xfU));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout)) 
                        << 0xeU) | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[0U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[1U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[2U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[3U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U];
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
                                     << 7U) | ([&]() {
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
    vlSelfRef.tlul_adapter_sram__DOT__d_error = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                                 && (1U 
                                                     & ((1U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                             >> 0xfU)))
                                                         ? 
                                                        ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata) 
                                                         | (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                            >> 0xeU))
                                                         : 
                                                        (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                         >> 0xeU))));
    vlSelfRef.tlul_adapter_sram__DOT__d_valid = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                                 && (1U 
                                                     & (IData)(
                                                               ((0x8000U 
                                                                 != 
                                                                 (0x1c000U 
                                                                  & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                                                | (IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid)))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x1000U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x1000U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x1000U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x1000U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                         ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (0xfffffeU & (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                      ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : vlSelfRef.tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (0xfffffeU & (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                      ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : vlSelfRef.tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (0xfffffeU & (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                      ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : vlSelfRef.tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (0xfffffeU & (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                      ? ((vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : vlSelfRef.tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp = 
        ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
         & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
            & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
               & (0x8000U == (0x18000U & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)))));
    VL_CONCAT_WQI(66,64,2, vlSelfRef.tlul_adapter_sram__DOT__tl_o_int, 
                  (((QData)((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)) 
                    << 0x3fU) | (((QData)((IData)((
                                                   ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
                                                    & (1U 
                                                       != 
                                                       (3U 
                                                        & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                           >> 0xfU))))
                                                    ? 0U
                                                    : 1U))) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp 
                                                = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)
                                                    ? 
                                                   (3U 
                                                    & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                       >> 8U))
                                                    : 0U);
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp 
                                                    = 
                                                    ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)
                                                      : 0U);
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              (((QData)((IData)(
                                                                                ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp 
                                                            = 
                                                            (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                                                              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp))
                                                              ? (IData)(
                                                                        (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                         >> 8U))
                                                              : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data);
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout))) 
                                                                                << 0xeU) 
                                                                               | (QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp 
                                                        = 
                                                        VL_EXTEND_II(14,7, 
                                                                     ([&]() {
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp 
                                                                    = 
                                                                    (0x7fU 
                                                                     & (((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                         & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                                            >> 0xeU))
                                                                         ? (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ)
                                                                         : 
                                                                        ((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                          ? (IData)(
                                                                                (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                                >> 1U))
                                                                          : 0x2aU)));
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout 
                                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp;
                                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout)));
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout))))))))))), 
                  ((((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
                     & (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp 
                        = ((((IData)(vlSelfRef.gnt_i) 
                             | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
                            & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)) 
                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout))));
    vlSelfRef.tlul_adapter_sram__02Etl_o[0U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U];
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[1U];
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U];
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
             >> 0xcU) & vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready 
        = (IData)(((vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U] 
                    >> 1U) & vlSelfRef.tlul_adapter_sram__02Etl_i[0U]));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(((0x8000U == (0x1c000U & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                         & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_ATTR_COLD void Vspi_host_tb___024root___eval_triggers__stl(Vspi_host_tb___024root* vlSelf);
VL_ATTR_COLD void Vspi_host_tb___024root___eval_stl(Vspi_host_tb___024root* vlSelf);

VL_ATTR_COLD bool Vspi_host_tb___024root___eval_phase__stl(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___eval_phase__stl\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vspi_host_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vspi_host_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host_tb___024root___dump_triggers__ico(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___dump_triggers__ico\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((2ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 1 is active: Internal 'ico' trigger - virtual interface: tlul_if\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host_tb___024root___dump_triggers__act(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___dump_triggers__act\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: Internal 'act' trigger - virtual interface: tlul_if\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge prim_fifo_async_simple.clk_wr_i)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge prim_fifo_async_simple.rst_wr_ni)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge prim_fifo_async_simple.clk_rd_i)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge prim_fifo_async_simple.rst_rd_ni)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(negedge prim_fifo_async_simple.u_prim_sync_reqack.effective_rst_n)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(posedge prim_fifo_async_sram_adapter.clk_wr_i)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @(negedge prim_fifo_async_sram_adapter.rst_wr_ni)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @(posedge prim_fifo_async_sram_adapter.clk_rd_i)\n");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @(negedge prim_fifo_async_sram_adapter.rst_rd_ni)\n");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 10 is active: @(posedge prim_filter.clk_i)\n");
    }
    if ((0x800ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 11 is active: @(negedge prim_filter.rst_ni)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 12 is active: @(posedge prim_filter_ctr.clk_i)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 13 is active: @(negedge prim_filter_ctr.rst_ni)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 14 is active: @(posedge tlul_adapter_host.clk_i)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 15 is active: @(negedge tlul_adapter_host.rst_ni)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 16 is active: @(posedge tlul_adapter_sram.clk_i)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 17 is active: @(negedge tlul_adapter_sram.rst_ni)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 18 is active: @(negedge tlul_assert_multiple.clk_i)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 19 is active: @(negedge tlul_assert_multiple.rst_ni)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 20 is active: @(posedge tlul_assert_multiple.clk_i)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 21 is active: @(posedge clk_h_i)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 22 is active: @(negedge rst_h_ni)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 23 is active: @(posedge clk_d_i)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 24 is active: @(negedge rst_d_ni)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 25 is active: @(posedge tlul_socket_1n.clk_i)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 26 is active: @(negedge tlul_socket_1n.rst_ni)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 27 is active: @(posedge tlul_socket_m1.clk_i)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 28 is active: @(negedge tlul_socket_m1.rst_ni)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 29 is active: @(posedge spi_host_tb.clk_i)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 30 is active: @(negedge spi_host_tb.rst_ni)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 31 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 32 is active: @([true] __VdynSched.evaluate())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host_tb___024root___dump_triggers__nba(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___dump_triggers__nba\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: Internal 'nba' trigger - virtual interface: tlul_if\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge prim_fifo_async_simple.clk_wr_i)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge prim_fifo_async_simple.rst_wr_ni)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge prim_fifo_async_simple.clk_rd_i)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge prim_fifo_async_simple.rst_rd_ni)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(negedge prim_fifo_async_simple.u_prim_sync_reqack.effective_rst_n)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(posedge prim_fifo_async_sram_adapter.clk_wr_i)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @(negedge prim_fifo_async_sram_adapter.rst_wr_ni)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @(posedge prim_fifo_async_sram_adapter.clk_rd_i)\n");
    }
    if ((0x200ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @(negedge prim_fifo_async_sram_adapter.rst_rd_ni)\n");
    }
    if ((0x400ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 10 is active: @(posedge prim_filter.clk_i)\n");
    }
    if ((0x800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 11 is active: @(negedge prim_filter.rst_ni)\n");
    }
    if ((0x1000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 12 is active: @(posedge prim_filter_ctr.clk_i)\n");
    }
    if ((0x2000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 13 is active: @(negedge prim_filter_ctr.rst_ni)\n");
    }
    if ((0x4000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 14 is active: @(posedge tlul_adapter_host.clk_i)\n");
    }
    if ((0x8000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 15 is active: @(negedge tlul_adapter_host.rst_ni)\n");
    }
    if ((0x10000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 16 is active: @(posedge tlul_adapter_sram.clk_i)\n");
    }
    if ((0x20000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 17 is active: @(negedge tlul_adapter_sram.rst_ni)\n");
    }
    if ((0x40000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 18 is active: @(negedge tlul_assert_multiple.clk_i)\n");
    }
    if ((0x80000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 19 is active: @(negedge tlul_assert_multiple.rst_ni)\n");
    }
    if ((0x100000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 20 is active: @(posedge tlul_assert_multiple.clk_i)\n");
    }
    if ((0x200000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 21 is active: @(posedge clk_h_i)\n");
    }
    if ((0x400000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 22 is active: @(negedge rst_h_ni)\n");
    }
    if ((0x800000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 23 is active: @(posedge clk_d_i)\n");
    }
    if ((0x1000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 24 is active: @(negedge rst_d_ni)\n");
    }
    if ((0x2000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 25 is active: @(posedge tlul_socket_1n.clk_i)\n");
    }
    if ((0x4000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 26 is active: @(negedge tlul_socket_1n.rst_ni)\n");
    }
    if ((0x8000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 27 is active: @(posedge tlul_socket_m1.clk_i)\n");
    }
    if ((0x10000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 28 is active: @(negedge tlul_socket_m1.rst_ni)\n");
    }
    if ((0x20000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 29 is active: @(posedge spi_host_tb.clk_i)\n");
    }
    if ((0x40000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 30 is active: @(negedge spi_host_tb.rst_ni)\n");
    }
    if ((0x80000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 31 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x100000000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 32 is active: @([true] __VdynSched.evaluate())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vspi_host_tb___024root____Vm_traceActivitySetAll(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root____Vm_traceActivitySetAll\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
    vlSelfRef.__Vm_traceActivity[0xaU] = 1U;
    vlSelfRef.__Vm_traceActivity[0xbU] = 1U;
    vlSelfRef.__Vm_traceActivity[0xcU] = 1U;
    vlSelfRef.__Vm_traceActivity[0xdU] = 1U;
    vlSelfRef.__Vm_traceActivity[0xeU] = 1U;
    vlSelfRef.__Vm_traceActivity[0xfU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x10U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x11U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x12U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x13U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x14U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x15U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x16U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x17U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x18U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x19U] = 1U;
    vlSelfRef.__Vm_traceActivity[0x1aU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x1bU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x1cU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x1dU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x1eU] = 1U;
    vlSelfRef.__Vm_traceActivity[0x1fU] = 1U;
}

VL_ATTR_COLD void Vspi_host_tb___024root___ctor_var_reset(Vspi_host_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host_tb___024root___ctor_var_reset\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->prim_cdc_rand_delay__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->prim_cdc_rand_delay__02Erst_ni = VL_RAND_RESET_I(1);
    vlSelf->prev_data_i = VL_RAND_RESET_I(1);
    vlSelf->src_data_i = VL_RAND_RESET_I(1);
    vlSelf->dst_data_o = VL_RAND_RESET_I(1);
    vlSelf->sram2tlul__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->sram2tlul__02Erst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->sram2tlul__02Etl_o);
    VL_RAND_RESET_W(66, vlSelf->sram2tlul__02Etl_i);
    vlSelf->mem_req_i = VL_RAND_RESET_I(1);
    vlSelf->mem_write_i = VL_RAND_RESET_I(1);
    vlSelf->mem_addr_i = VL_RAND_RESET_I(12);
    vlSelf->mem_wdata_i = VL_RAND_RESET_I(32);
    vlSelf->mem_rvalid_o = VL_RAND_RESET_I(1);
    vlSelf->mem_rdata_o = VL_RAND_RESET_I(32);
    vlSelf->mem_error_o = VL_RAND_RESET_I(2);
    vlSelf->prim_fifo_async_simple__02Eclk_wr_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Erst_wr_ni = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Ewvalid_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Ewready_o = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Ewdata_i = VL_RAND_RESET_I(16);
    vlSelf->prim_fifo_async_simple__02Eclk_rd_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Erst_rd_ni = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Ervalid_o = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Erready_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__02Erdata_o = VL_RAND_RESET_I(16);
    vlSelf->prim_fifo_async_sram_adapter__02Eclk_wr_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Erst_wr_ni = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Ewvalid_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Ewready_o = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Ewdata_i = VL_RAND_RESET_I(32);
    vlSelf->wdepth_o = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__02Eclk_rd_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Erst_rd_ni = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Ervalid_o = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Erready_i = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__02Erdata_o = VL_RAND_RESET_I(32);
    vlSelf->rdepth_o = VL_RAND_RESET_I(5);
    vlSelf->r_full_o = VL_RAND_RESET_I(1);
    vlSelf->r_notempty_o = VL_RAND_RESET_I(1);
    vlSelf->w_full_o = VL_RAND_RESET_I(1);
    vlSelf->w_sram_req_o = VL_RAND_RESET_I(1);
    vlSelf->w_sram_gnt_i = VL_RAND_RESET_I(1);
    vlSelf->w_sram_write_o = VL_RAND_RESET_I(1);
    vlSelf->w_sram_addr_o = VL_RAND_RESET_I(16);
    vlSelf->w_sram_wdata_o = VL_RAND_RESET_I(32);
    vlSelf->w_sram_wmask_o = VL_RAND_RESET_I(32);
    vlSelf->w_sram_rvalid_i = VL_RAND_RESET_I(1);
    vlSelf->w_sram_rdata_i = VL_RAND_RESET_I(32);
    vlSelf->w_sram_rerror_i = VL_RAND_RESET_I(2);
    vlSelf->r_sram_req_o = VL_RAND_RESET_I(1);
    vlSelf->r_sram_gnt_i = VL_RAND_RESET_I(1);
    vlSelf->r_sram_write_o = VL_RAND_RESET_I(1);
    vlSelf->r_sram_addr_o = VL_RAND_RESET_I(16);
    vlSelf->r_sram_wdata_o = VL_RAND_RESET_I(32);
    vlSelf->r_sram_wmask_o = VL_RAND_RESET_I(32);
    vlSelf->r_sram_rvalid_i = VL_RAND_RESET_I(1);
    vlSelf->r_sram_rdata_i = VL_RAND_RESET_I(32);
    vlSelf->r_sram_rerror_i = VL_RAND_RESET_I(2);
    vlSelf->prim_filter__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->prim_filter__02Erst_ni = VL_RAND_RESET_I(1);
    vlSelf->prim_filter__02Eenable_i = VL_RAND_RESET_I(1);
    vlSelf->prim_filter__02Efilter_i = VL_RAND_RESET_I(1);
    vlSelf->prim_filter__02Efilter_o = VL_RAND_RESET_I(1);
    vlSelf->prim_filter_ctr__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->prim_filter_ctr__02Erst_ni = VL_RAND_RESET_I(1);
    vlSelf->prim_filter_ctr__02Eenable_i = VL_RAND_RESET_I(1);
    vlSelf->prim_filter_ctr__02Efilter_i = VL_RAND_RESET_I(1);
    vlSelf->thresh_i = VL_RAND_RESET_I(2);
    vlSelf->prim_filter_ctr__02Efilter_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_host__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_host__02Erst_ni = VL_RAND_RESET_I(1);
    vlSelf->req_i = VL_RAND_RESET_I(1);
    vlSelf->gnt_o = VL_RAND_RESET_I(1);
    vlSelf->addr_i = VL_RAND_RESET_I(32);
    vlSelf->we_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_host__02Ewdata_i = VL_RAND_RESET_I(32);
    vlSelf->wdata_intg_i = VL_RAND_RESET_I(7);
    vlSelf->be_i = VL_RAND_RESET_I(4);
    vlSelf->instr_type_i = VL_RAND_RESET_I(4);
    vlSelf->valid_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_host__02Erdata_o = VL_RAND_RESET_I(32);
    vlSelf->rdata_intg_o = VL_RAND_RESET_I(7);
    vlSelf->err_o = VL_RAND_RESET_I(1);
    vlSelf->intg_err_o = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tlul_adapter_host__02Etl_o);
    VL_RAND_RESET_W(66, vlSelf->tlul_adapter_host__02Etl_i);
    vlSelf->tlul_adapter_sram__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__02Erst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tlul_adapter_sram__02Etl_i);
    VL_RAND_RESET_W(66, vlSelf->tlul_adapter_sram__02Etl_o);
    vlSelf->en_ifetch_i = VL_RAND_RESET_I(4);
    vlSelf->req_o = VL_RAND_RESET_I(1);
    vlSelf->req_type_o = VL_RAND_RESET_I(4);
    vlSelf->gnt_i = VL_RAND_RESET_I(1);
    vlSelf->we_o = VL_RAND_RESET_I(1);
    vlSelf->addr_o = VL_RAND_RESET_I(12);
    vlSelf->wdata_o = VL_RAND_RESET_I(32);
    vlSelf->wmask_o = VL_RAND_RESET_I(32);
    vlSelf->intg_error_o = VL_RAND_RESET_I(1);
    vlSelf->rdata_i = VL_RAND_RESET_I(32);
    vlSelf->rvalid_i = VL_RAND_RESET_I(1);
    vlSelf->rerror_i = VL_RAND_RESET_I(2);
    vlSelf->compound_txn_in_progress_o = VL_RAND_RESET_I(1);
    vlSelf->readback_en_i = VL_RAND_RESET_I(4);
    vlSelf->readback_error_o = VL_RAND_RESET_I(1);
    vlSelf->wr_collision_i = VL_RAND_RESET_I(1);
    vlSelf->write_pending_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__02Erst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(218, vlSelf->h2d);
    VL_RAND_RESET_W(132, vlSelf->d2h);
    vlSelf->clk_h_i = VL_RAND_RESET_I(1);
    vlSelf->rst_h_ni = VL_RAND_RESET_I(1);
    vlSelf->clk_d_i = VL_RAND_RESET_I(1);
    vlSelf->rst_d_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tlul_fifo_async__02Etl_h_i);
    VL_RAND_RESET_W(66, vlSelf->tlul_fifo_async__02Etl_h_o);
    VL_RAND_RESET_W(109, vlSelf->tlul_fifo_async__02Etl_d_o);
    VL_RAND_RESET_W(66, vlSelf->tlul_fifo_async__02Etl_d_i);
    vlSelf->tlul_socket_1n__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__02Erst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_1n__02Etl_h_i);
    VL_RAND_RESET_W(66, vlSelf->tlul_socket_1n__02Etl_h_o);
    VL_RAND_RESET_W(436, vlSelf->tlul_socket_1n__02Etl_d_o);
    VL_RAND_RESET_W(264, vlSelf->tlul_socket_1n__02Etl_d_i);
    vlSelf->dev_select_i = VL_RAND_RESET_I(3);
    vlSelf->tlul_socket_m1__02Eclk_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__02Erst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(436, vlSelf->tlul_socket_m1__02Etl_h_i);
    VL_RAND_RESET_W(264, vlSelf->tlul_socket_m1__02Etl_h_o);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__02Etl_d_o);
    VL_RAND_RESET_W(66, vlSelf->tlul_socket_m1__02Etl_d_i);
    vlSelf->prim_fifo_async_simple__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__src_req = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__src_ack = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__pending_d = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__pending_q = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__not_in_reset_q = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__dst_req = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__dst_ack = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__data_q = VL_RAND_RESET_I(16);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_q = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_d = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_wptr_gray = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_wptr = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_q = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_d = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_rptr_gray = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_rptr = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__w_wptr_inc = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_rptr_inc = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__DOT__stored = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__DOT__rdata_q = VL_RAND_RESET_I(32);
    vlSelf->prim_fifo_async_sram_adapter__DOT__rdata_d = VL_RAND_RESET_I(32);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_sram_rptr = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__DOT__store_en = VL_RAND_RESET_I(1);
    vlSelf->prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq = VL_RAND_RESET_I(5);
    vlSelf->prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq = VL_RAND_RESET_I(5);
    vlSelf->prim_filter__DOT__stored_vector_q = VL_RAND_RESET_I(4);
    vlSelf->prim_filter__DOT__stored_vector_d = VL_RAND_RESET_I(4);
    vlSelf->prim_filter__DOT__stored_value_q = VL_RAND_RESET_I(1);
    vlSelf->prim_filter_ctr__DOT__diff_ctr_q = VL_RAND_RESET_I(2);
    vlSelf->prim_filter_ctr__DOT__diff_ctr_d = VL_RAND_RESET_I(2);
    vlSelf->prim_filter_ctr__DOT__filter_q = VL_RAND_RESET_I(1);
    vlSelf->prim_filter_ctr__DOT__stored_value_q = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_host__DOT__tl_source = VL_RAND_RESET_I(8);
    VL_RAND_RESET_W(109, vlSelf->tlul_adapter_host__DOT__tl_out);
    vlSelf->tlul_adapter_host__DOT__outstanding_reqs_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_host__DOT__outstanding_reqs_d = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__error_det = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__instr_error = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__intg_error_q = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(66, vlSelf->tlul_adapter_sram__DOT__tl_o_int);
    vlSelf->tlul_adapter_sram__DOT__reqfifo_wready = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__reqfifo_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__reqfifo_rready = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__reqfifo_wdata = VL_RAND_RESET_I(17);
    vlSelf->tlul_adapter_sram__DOT__reqfifo_rdata = VL_RAND_RESET_I(17);
    vlSelf->tlul_adapter_sram__DOT__sramreqfifo_wready = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__sramreqfifo_rready = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__sramreqfifo_wdata = VL_RAND_RESET_I(5);
    vlSelf->tlul_adapter_sram__DOT__sramreqfifo_rdata = VL_RAND_RESET_I(5);
    vlSelf->tlul_adapter_sram__DOT__rspfifo_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__rspfifo_wdata = VL_RAND_RESET_Q(40);
    vlSelf->tlul_adapter_sram__DOT__rspfifo_rdata = VL_RAND_RESET_Q(40);
    vlSelf->tlul_adapter_sram__DOT__d_valid = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__d_error = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__vld_rd_rsp = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__error_blanking_data = VL_RAND_RESET_I(32);
    vlSelf->tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o = VL_RAND_RESET_Q(39);
    vlSelf->tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o = VL_RAND_RESET_Q(39);
    vlSelf->tlul_adapter_sram__DOT__error_blanking_integ = VL_RAND_RESET_I(7);
    vlSelf->tlul_adapter_sram__DOT__missed_err_gnt_q = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__wmask_int = VL_RAND_RESET_I(32);
    vlSelf->tlul_adapter_sram__DOT__wdata_int = VL_RAND_RESET_I(32);
    vlSelf->tlul_adapter_sram__DOT__wmask_intg = VL_RAND_RESET_I(7);
    vlSelf->tlul_adapter_sram__DOT__wdata_intg = VL_RAND_RESET_I(7);
    vlSelf->tlul_adapter_sram__DOT__sv2v_autoblock_1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tlul_adapter_sram__DOT__gen_rmask__DOT__rmask = VL_RAND_RESET_I(32);
    vlSelf->tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_err__DOT__instr_type_err = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_err__DOT__mask_chk = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage = VL_RAND_RESET_I(17);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage = VL_RAND_RESET_I(5);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage = VL_RAND_RESET_Q(40);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(2560, vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_sva = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_d_error_sva = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_mask = VL_RAND_RESET_I(8);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask = VL_RAND_RESET_I(8);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_data = VL_RAND_RESET_Q(64);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_data = VL_RAND_RESET_Q(64);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h2f9dcced__0 = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h8d3db085__0 = VL_RAND_RESET_I(3);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h30376d23__0 = VL_RAND_RESET_I(2);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h6d84055b__0 = VL_RAND_RESET_I(4);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_ha603a01c__0 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(2560, vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_sva = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_d_error_sva = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_mask = VL_RAND_RESET_I(8);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask = VL_RAND_RESET_I(8);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_data = VL_RAND_RESET_Q(64);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_data = VL_RAND_RESET_Q(64);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h2f9dcced__0 = VL_RAND_RESET_I(1);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h8d3db085__0 = VL_RAND_RESET_I(3);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h30376d23__0 = VL_RAND_RESET_I(2);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h6d84055b__0 = VL_RAND_RESET_I(4);
    vlSelf->tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_ha603a01c__0 = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__wdepth_o = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__rdepth_o = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__full_wclk = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(107, vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__storage[__Vi0]);
    }
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__wdepth_o = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__rdepth_o = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__full_wclk = VL_RAND_RESET_I(1);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__storage[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq = VL_RAND_RESET_I(3);
    vlSelf->tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_1n__DOT__tl_t_o);
    vlSelf->tlul_socket_1n__DOT__num_req_outstanding = VL_RAND_RESET_I(9);
    vlSelf->tlul_socket_1n__DOT__dev_select_outstanding = VL_RAND_RESET_I(3);
    vlSelf->tlul_socket_1n__DOT__hold_all_requests = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__accept_t_req = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__accept_t_rsp = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_RAND_RESET_W(109, vlSelf->tlul_socket_1n__DOT__tl_u_o[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_RAND_RESET_W(66, vlSelf->tlul_socket_1n__DOT__tl_u_i[__Vi0]);
    }
    vlSelf->tlul_socket_1n__DOT__blanked_auser = VL_RAND_RESET_I(23);
    VL_RAND_RESET_W(66, vlSelf->tlul_socket_1n__DOT__tl_t_p);
    vlSelf->tlul_socket_1n__DOT__hfifo_reqready = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(110, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(110, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(110, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode = VL_RAND_RESET_I(3);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source = VL_RAND_RESET_I(8);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(66, vlSelf->tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int);
    VL_RAND_RESET_W(436, vlSelf->tlul_socket_m1__DOT__hreq_fifo_o);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_RAND_RESET_W(66, vlSelf->tlul_socket_m1__DOT__hrsp_fifo_i[__Vi0]);
    }
    vlSelf->tlul_socket_m1__DOT__hrequest = VL_RAND_RESET_I(4);
    vlSelf->tlul_socket_m1__DOT__hgrant = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__dreq_fifo_i);
    VL_RAND_RESET_W(66, vlSelf->tlul_socket_m1__DOT__drsp_fifo_o);
    vlSelf->tlul_socket_m1__DOT__arb_ready = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__arb_data);
    vlSelf->tlul_socket_m1__DOT__hfifo_rspvalid__BRA__3__KET__ = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__hfifo_rspvalid__BRA__2__KET__ = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__hfifo_rspvalid__BRA__1__KET__ = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__hfifo_rspvalid__BRA__0__KET__ = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i);
    VL_RAND_RESET_W(109, vlSelf->tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(108, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__depth_o = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set = VL_RAND_RESET_I(1);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__idx_o = VL_RAND_RESET_I(2);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req = VL_RAND_RESET_I(4);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out = VL_RAND_RESET_I(4);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req = VL_RAND_RESET_I(4);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask = VL_RAND_RESET_I(4);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner = VL_RAND_RESET_I(4);
    vlSelf->tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__sv2v_autoblock_3__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__inp = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__inp = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__inp = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__inp = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__101__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__101__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__102__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__102__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__104__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__105__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__105__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__110__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__110__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__111__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__111__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__113__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__114__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__114__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__119__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__119__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__120__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__120__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__122__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__123__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__123__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__136__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__136__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__137__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__137__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__139__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__139__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__140__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__140__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__142__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__142__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__143__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__143__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__145__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__145__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__146__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__146__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__159__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__159__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__160__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__160__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__162__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__162__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__163__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__163__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__165__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__165__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__166__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__166__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__168__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__168__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__169__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__169__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__inp = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__Vfuncout = VL_RAND_RESET_I(7);
    VL_RAND_RESET_W(109, vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__cmd_intg = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__Vfuncout = VL_RAND_RESET_I(7);
    VL_RAND_RESET_W(109, vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd_intg = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd = VL_RAND_RESET_Q(43);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__Vfuncout = VL_RAND_RESET_Q(43);
    VL_RAND_RESET_W(109, vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload = VL_RAND_RESET_Q(43);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__Vfuncout = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_i = VL_RAND_RESET_Q(57);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__Vfuncout = VL_RAND_RESET_Q(57);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__inp = VL_RAND_RESET_Q(57);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__Vfuncout = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__inp = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__Vfuncout = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_i = VL_RAND_RESET_Q(57);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__Vfuncout = VL_RAND_RESET_Q(57);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__inp = VL_RAND_RESET_Q(57);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__Vfuncout = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__inp = VL_RAND_RESET_Q(64);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__inp = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__data_intg = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__Vfuncout = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__data_intg = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__enc_data = VL_RAND_RESET_Q(39);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__Vfuncout = VL_RAND_RESET_Q(39);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o = VL_RAND_RESET_Q(39);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__206__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__206__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__207__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__207__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__209__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__209__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__210__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__210__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__215__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__215__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__216__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__216__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__218__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__218__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__219__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__219__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__val = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__Vfuncout = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__inp = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__Vfuncout = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__inp = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__Vfuncout = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__inp = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__Vfuncout = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__inp = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__255__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__256__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__257__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__258__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__259__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__Vfuncout = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__260__inp = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__261__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__Vfuncout = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__262__inp = VL_RAND_RESET_I(23);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__263__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__263__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__264__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__264__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__265__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__265__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__266__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__266__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__267__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__267__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__268__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__268__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__269__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__269__inp = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__270__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__270__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__271__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__271__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__272__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__272__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__273__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__273__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__274__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__274__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__275__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__275__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__276__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__276__inp = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__277__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__277__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__278__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__278__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__279__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__279__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__280__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__280__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__281__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__281__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__282__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__282__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__283__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__283__inp = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__284__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__284__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__285__Vfuncout = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__285__inp = VL_RAND_RESET_I(3);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__286__Vfuncout = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__286__inp = VL_RAND_RESET_I(2);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__287__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__287__inp = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__288__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_17D81__288__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__289__Vfuncout = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__289__inp = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__290__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__sv2v_cast_11E70__290__inp = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__295__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__295__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__296__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__296__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__298__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__298__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__299__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__299__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__304__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__304__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__305__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__305__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__307__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__307__inp = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__308__Vfuncout = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__308__inp = VL_RAND_RESET_I(1);
    vlSelf->__VvifTrigger_h100a9299__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_wr_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_wr_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Eclk_rd_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__02Erst_rd_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_wr_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_wr_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Eclk_rd_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_fifo_async_sram_adapter__02Erst_rd_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_filter__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_filter__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_filter_ctr__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__prim_filter_ctr__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_host__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_host__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_sram__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_adapter_sram__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_assert_multiple__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_assert_multiple__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk_h_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_h_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk_d_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_d_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_1n__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_1n__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_m1__02Eclk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tlul_socket_m1__02Erst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__spi_host_tb____PVT__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__spi_host_tb____PVT__rst_ni__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
