// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb___024root.h"

VL_ATTR_COLD void Vpwm_ramp_tb___024root___eval_initial__TOP(Vpwm_ramp_tb___024root* vlSelf);
VlCoroutine Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__0(Vpwm_ramp_tb___024root* vlSelf);
VlCoroutine Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__1(Vpwm_ramp_tb___024root* vlSelf);

void Vpwm_ramp_tb___024root___eval_initial(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_initial\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpwm_ramp_tb___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__0(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pwm_ramp_tb__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/pwm_ramp_tb.sv", 
                                             76);
        vlSelfRef.pwm_ramp_tb__DOT__clk_i = (1U & (~ (IData)(vlSelfRef.pwm_ramp_tb__DOT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__1(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__amplitude;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__amplitude = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__offset;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__offset = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__freq_hz;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__freq_hz = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__duration_us;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__duration_us = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__timestep_ns;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__timestep_ns = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__period_ns;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__period_ns = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__amplitude;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__amplitude = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__offset;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__offset = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__freq_hz;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__freq_hz = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__duration_us;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__duration_us = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__timestep_ns;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__timestep_ns = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns = 0;
    double __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__period_ns;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__period_ns = 0;
    // Body
    vlSelfRef.pwm_ramp_tb__DOT__rst_ni = 0U;
    vlSelfRef.pwm_ramp_tb__DOT__reverse_i = 0U;
    vlSelfRef.pwm_ramp_tb__DOT__enable_i = 0U;
    vlSelfRef.pwm_ramp_tb__DOT__step_i = 1U;
    vlSelfRef.pwm_ramp_tb__DOT__analog_input = 0.0;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         140);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.pwm_ramp_tb__DOT__rst_ni = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         142);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("\nRunning...\n\n",0);
    vlSelfRef.pwm_ramp_tb__DOT__enable_i = 1U;
    co_await vlSelfRef.__VdlySched.delay(0xf4240ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         148);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__timestep_ns = 10.0;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__duration_us = 3.00000000000000000e+03;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__freq_hz = 1.00000000000000000e+03;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__offset = 5.00000000000000000e-01;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__amplitude = 2.99999999999999989e-01;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns = 0;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__period_ns = 0;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__period_ns 
        = (1.00000000000000000e+09 / __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__freq_hz);
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns = 0.0;
    while ((__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns 
            < (1.00000000000000000e+03 * __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__duration_us))) {
        vlSelfRef.pwm_ramp_tb__DOT__analog_input = 
            (__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__offset 
             + (__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__amplitude 
                * sin(((6.28318530717799995e+00 * __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns) 
                       / __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__period_ns))));
        co_await vlSelfRef.__VdlySched.delay(VL_RTOIROUND_Q_D(
                                                              (1.00000000000000000e+03 
                                                               * __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__timestep_ns)), 
                                             nullptr, 
                                             "tb/pwm_ramp_tb.sv", 
                                             100);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns 
            = (__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__t_ns 
               + __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__367__timestep_ns);
    }
    co_await vlSelfRef.__VdlySched.delay(0xf4240ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         152);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.pwm_ramp_tb__DOT__rst_ni = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         156);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.pwm_ramp_tb__DOT__rst_ni = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x2710ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         158);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.pwm_ramp_tb__DOT__reverse_i = 1U;
    vlSelfRef.pwm_ramp_tb__DOT__enable_i = 1U;
    co_await vlSelfRef.__VdlySched.delay(0xf4240ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         165);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__timestep_ns = 10.0;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__duration_us = 3.00000000000000000e+03;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__freq_hz = 1.00000000000000000e+03;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__offset = 5.00000000000000000e-01;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__amplitude = 2.99999999999999989e-01;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns = 0;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__period_ns = 0;
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__period_ns 
        = (1.00000000000000000e+09 / __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__freq_hz);
    __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns = 0.0;
    while ((__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns 
            < (1.00000000000000000e+03 * __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__duration_us))) {
        vlSelfRef.pwm_ramp_tb__DOT__analog_input = 
            (__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__offset 
             + (__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__amplitude 
                * sin(((6.28318530717799995e+00 * __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns) 
                       / __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__period_ns))));
        co_await vlSelfRef.__VdlySched.delay(VL_RTOIROUND_Q_D(
                                                              (1.00000000000000000e+03 
                                                               * __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__timestep_ns)), 
                                             nullptr, 
                                             "tb/pwm_ramp_tb.sv", 
                                             100);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns 
            = (__Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__t_ns 
               + __Vtask_pwm_ramp_tb__DOT__drive_sine_wave__368__timestep_ns);
    }
    co_await vlSelfRef.__VdlySched.delay(0xf4240ULL, 
                                         nullptr, "tb/pwm_ramp_tb.sv", 
                                         169);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("Coverage: 100%%\n\nEnd.\n\n",0);
    VL_FINISH_MT("tb/pwm_ramp_tb.sv", 176, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___ico_sequent__TOP__0(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___ico_sequent__TOP__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__Vfuncout;
    __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__Vfuncout = 0;
    IData/*22:0*/ __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__user;
    __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__user = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__malformed_err;
    __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__malformed_err = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__Vfuncout;
    __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__val;
    __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__val = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__Vfuncout;
    __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__val;
    __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__val = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__Vfuncout;
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__val;
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__val = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__inp = 0;
    QData/*56:0*/ __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__unused_cmd_payload;
    __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__unused_cmd_payload = 0;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_11;
    VlWide<4>/*127:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<4>/*127:0*/ __Vtemp_14;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_27;
    // Body
    vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk 
        = ((1U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                              >> 4U))) 
                                || (1U & ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                     >> 4U)))
                                           ? (~ (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                 >> 0x1cU))
                                           : ((2U == 
                                               (3U 
                                                & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                   >> 4U))) 
                                              && (1U 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != 
                                                                (3U 
                                                                 & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                                    >> 0x1cU)))))))))));
    vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk 
        = ((1U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                  >> 0xcU)) && (1U & ((0U == (3U & 
                                              (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                               >> 4U)))
                                       ? (~ (IData)(
                                                    (0U 
                                                     != 
                                                     (0xfU 
                                                      & (((vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                           << 8U) 
                                                          | (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                             >> 0x18U)) 
                                                         & (~ 
                                                            ((IData)(1U) 
                                                             << 
                                                             (3U 
                                                              & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                                 >> 0x1cU)))))))))
                                       : ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                     >> 4U)))
                                           ? ((0x20000000U 
                                               & vlSelfRef.tlul_adapter_reg__02Etl_i[1U])
                                               ? (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (3U 
                                                              & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                                 >> 0x18U)))))
                                               : (~ (IData)(
                                                            (0U 
                                                             != 
                                                             (0xcU 
                                                              & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                                 >> 0x18U))))))
                                           : (2U == 
                                              (3U & 
                                               (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                >> 4U)))))));
    vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk 
        = ((1U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                              >> 4U)))
                                 ? (0U != (0xfU & (
                                                   ((vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                     << 8U) 
                                                    | (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                       >> 0x18U)) 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                          >> 0x1cU))))))
                                 : ((1U == (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                  >> 4U)))
                                     ? ((0x20000000U 
                                         & vlSelfRef.tlul_adapter_reg__02Etl_i[1U])
                                         ? (3U == (3U 
                                                   & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                      >> 0x1aU)))
                                         : (3U == (3U 
                                                   & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                      >> 0x18U))))
                                     : ((2U == (3U 
                                                & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                   >> 4U))) 
                                        && (0xfU == 
                                            (0xfU & 
                                             (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                              >> 0x18U)))))));
    vlSelfRef.tlul_adapter_sram__DOT__wmask_intg = 0U;
    vlSelfRef.tlul_adapter_sram__DOT__wdata_intg = 0U;
    vlSelfRef.dst_data_o = vlSelfRef.src_data_i;
    vlSelfRef.qre = vlSelfRef.re;
    vlSelfRef.prim_subreg_ext__02Eqe = vlSelfRef.prim_subreg_ext__02Ewe;
    vlSelfRef.prim_subreg_ext__02Eq = vlSelfRef.prim_subreg_ext__02Ewd;
    vlSelfRef.prim_subreg_ext__02Eds = vlSelfRef.prim_subreg_ext__02Ed;
    vlSelfRef.prim_subreg_ext__02Eqs = vlSelfRef.prim_subreg_ext__02Ed;
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
    vlSelfRef.tlul_adapter_host__02Erdata_o = ((vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                << 0x10U) 
                                               | (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                                  >> 0x10U));
    vlSelfRef.rdata_intg_o = (0x7fU & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                       >> 2U));
    vlSelfRef.err_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                             >> 1U));
    vlSelfRef.tlul_adapter_reg__02Eaddr_o = (0xfcU 
                                             & ((vlSelfRef.tlul_adapter_reg__02Etl_i[2U] 
                                                 << 4U) 
                                                | (0xcU 
                                                   & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                      >> 0x1cU))));
    vlSelfRef.tlul_adapter_reg__02Ewdata_o = ((vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                               << 8U) 
                                              | (vlSelfRef.tlul_adapter_reg__02Etl_i[0U] 
                                                 >> 0x18U));
    vlSelfRef.be_o = (0xfU & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                              >> 0x18U));
    vlSelfRef.req_type_o = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                    >> 0xfU));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0xeU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0xcU));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
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
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp;
    vlSelfRef.w_sram_wdata_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout;
    if ((0x1000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        vlSelfRef.tlul_adapter_sram__DOT__sv2v_autoblock_1__DOT__i = 4U;
        vlSelfRef.tlul_adapter_sram__DOT__wmask_intg = 0x7fU;
        vlSelfRef.tlul_adapter_sram__DOT__wdata_intg 
            = (0x7fU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                        >> 1U));
        vlSelfRef.tlul_adapter_sram__02Eaddr_o = (0xfffU 
                                                  & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                                      << 2U) 
                                                     | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
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
        vlSelfRef.tlul_adapter_sram__02Eaddr_o = 0U;
    }
    vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__80__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_reg__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__80__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__80__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__80__Vfuncout)) 
           & ((0U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                >> 9U)))));
    __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__val 
        = (0xfU & (vlSelfRef.tlul_adapter_reg__02Etl_i[0U] 
                   >> 0xfU));
    __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__val)) 
                    | (9U == (IData)(__Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__val)))));
    vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_tlul_adapter_reg__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__82__Vfuncout;
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__133__inp 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                               >> 0x18U));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__133__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__133__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__133__Vfuncout)) 
           << 1U);
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__inp 
        = (0xfU & (vlSelfRef.h2d[5U] >> 5U));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__182__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__inp 
        = (QData)((IData)(((vlSelfRef.h2d[5U] << 0x1bU) 
                           | (vlSelfRef.h2d[4U] >> 5U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__183__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__inp 
        = (QData)((IData)(((vlSelfRef.d2h[3U] << 0xeU) 
                           | (vlSelfRef.d2h[2U] >> 0x12U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_64__185__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__inp 
        = (0xfU & (vlSelfRef.h2d[1U] >> 0x18U));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__186__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__inp 
        = (QData)((IData)(((vlSelfRef.h2d[1U] << 8U) 
                           | (vlSelfRef.h2d[0U] >> 0x18U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__187__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__inp 
        = (QData)((IData)(((vlSelfRef.d2h[1U] << 0x10U) 
                           | (vlSelfRef.d2h[0U] >> 0x10U))));
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_data 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_64__189__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp 
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
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp 
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
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout;
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d 
        = ((IData)(vlSelfRef.r_sram_rvalid_i) ? vlSelfRef.r_sram_rdata_i
            : 0U);
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    vlSelfRef.prim_subreg__02Eqe = ((IData)(vlSelfRef.de) 
                                    | (IData)(vlSelfRef.prim_subreg__02Ewe));
    vlSelfRef.valid_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                               >> 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.prim_subreg__DOT__wr_data = ((IData)(vlSelfRef.prim_subreg__02Ewe)
                                            ? vlSelfRef.prim_subreg__02Ewd
                                            : vlSelfRef.prim_subreg__02Ed);
    __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__user 
        = (0x7fffffU & (vlSelfRef.tlul_adapter_reg__02Etl_i[0U] 
                        >> 1U));
    __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__val 
        = (0xfU & (__Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__user 
                   >> 0xeU));
    __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__val)) 
                    | (9U == (IData)(__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__val)))));
    __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__malformed_err 
        = __Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__65__Vfuncout;
    __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__Vfuncout 
        = __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__malformed_err;
    vlSelfRef.tlul_adapter_reg__DOT__malformed_meta_err 
        = __Vfunc_tlul_adapter_reg__DOT__tlul_pkg_tl_a_user_chk__64__Vfuncout;
    vlSelfRef.gnt_o = (1U & vlSelfRef.tlul_adapter_host__02Etl_i[0U]);
    vlSelfRef.tlul_adapter_reg__DOT__instr_error = 
        (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__45__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_reg__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__45__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__45__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__45__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_invalid__45__Vfuncout)) 
         | (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_true_strict__60__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_reg__02Etl_i[0U] 
                                   >> 0xfU));
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_true_strict__60__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_true_strict__60__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_true_strict__60__Vfuncout)) 
            & ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_false_loose__62__val 
                        = vlSelfRef.tlul_adapter_reg__02Een_ifetch_i;
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_false_loose__62__Vfuncout 
                        = (6U != (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_false_loose__62__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__prim_mubi_pkg_mubi4_test_false_loose__62__Vfuncout))));
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.tlul_adapter_sram__02Ewe_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             >> 0xcU) 
                                            & ((0U 
                                                == 
                                                (7U 
                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                    >> 9U))) 
                                               | (1U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                      >> 9U)))));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
    VL_CONCAT_WIQ(92,32,60, __Vtemp_3, ([&]() {
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
    VL_CONCAT_WIW(100,8,92, __Vtemp_4, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp 
                    = vlSelfRef.tlul_adapter_host__DOT__tl_source;
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout)), __Vtemp_3);
    vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[2U] = 
        __Vtemp_4[2U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[3U] = 
        (0x20U | (((IData)(vlSelfRef.req_i) << 0xcU) 
                  | ((((IData)(vlSelfRef.we_i) ? ((0xfU 
                                                   == (IData)(vlSelfRef.be_i))
                                                   ? 0U
                                                   : 1U)
                        : 4U) << 9U) | __Vtemp_4[3U])));
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
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__136__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__136__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__136__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__136__Vfuncout)) 
           & ((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U)))));
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__val 
        = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                   >> 0xfU));
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__val)) 
                    | (9U == (IData)(__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__val)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__138__Vfuncout;
    vlSelfRef.tlul_adapter_sram__DOT__instr_error = 
        (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__97__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__97__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__97__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__97__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__97__Vfuncout)) 
         | (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__112__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                   >> 0xfU));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__112__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__112__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__112__Vfuncout)) 
            & ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__114__val 
                        = vlSelfRef.tlul_adapter_sram__02Een_ifetch_i;
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__114__Vfuncout 
                        = (6U != (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__114__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__114__Vfuncout))));
    VL_CONCAT_WQI(66,64,2, vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre, 
                  (((QData)((IData)(vlSelfRef.tlul_adapter_reg__DOT__outstanding_q)) 
                    << 0x3fU) | (((QData)((IData)(vlSelfRef.tlul_adapter_reg__DOT__rspop_q)) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__inp 
                                                = vlSelfRef.tlul_adapter_reg__DOT__reqsz_q;
                                            vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__inp 
                                                    = vlSelfRef.tlul_adapter_reg__DOT__reqid_q;
                                                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              ((QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__inp 
                                                        = vlSelfRef.tlul_adapter_reg__DOT__rdata_q;
                                                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__inp;
                                                }(), vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__Vfuncout))) 
                                                                               << 0xeU))))))), 
                  (((IData)(vlSelfRef.tlul_adapter_reg__DOT__error_q) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__inp 
                        = (1U & (~ ((IData)(vlSelfRef.tlul_adapter_reg__DOT__outstanding_q) 
                                    | ((vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                        >> 0xcU) & (IData)(vlSelfRef.busy_i)))));
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__Vfuncout))));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata 
        = (((QData)((IData)((vlSelfRef.tlul_adapter_sram__02Erdata_i 
                             & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & (IData)(vlSelfRef.rvalid_i));
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
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    VL_CONCAT_WIQ(92,32,60, __Vtemp_8, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__285__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                        << 0x1dU) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xcU] 
                                     >> 3U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__285__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__285__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__285__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__286__inp 
                                    = (0xfU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xcU] 
                                                << 1U) 
                                               | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xbU] 
                                                  >> 0x1fU)));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__286__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__286__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__286__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__287__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xbU] 
                                            << 1U) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                              >> 0x1fU));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__287__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__287__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__287__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__288__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                                  >> 8U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__288__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__288__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__288__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                                                     >> 7U))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_9, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__284__inp 
                    = (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                >> 1U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__284__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__284__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__284__Vfuncout)), __Vtemp_8);
    VL_CONCAT_WIW(102,2,100, __Vtemp_10, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__283__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0xbU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__283__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__283__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__283__Vfuncout)), __Vtemp_9);
    VL_CONCAT_WIW(105,3,102, __Vtemp_11, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__282__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0xdU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__282__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__282__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__282__Vfuncout)), __Vtemp_10);
    VL_CONCAT_WIW(108,3,105, __Vtemp_12, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__281__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0x10U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__281__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__281__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__281__Vfuncout)), __Vtemp_11);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_12[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                       >> 7U)) | __Vtemp_12[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_13, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__293__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                        << 0xaU) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                    >> 0x16U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__293__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__293__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__293__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__294__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                               >> 0x12U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__294__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__294__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__294__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__295__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                            << 0xeU) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[7U] 
                                              >> 0x12U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__295__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__295__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__295__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__296__inp 
                                            = (0x7fffffU 
                                               & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[7U] 
                                                   << 5U) 
                                                  | (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                                     >> 0x1bU)));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__296__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__296__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__296__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                                                     >> 0x1aU))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_14, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__292__inp 
                    = (1U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                      >> 0x14U)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__292__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__292__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__292__Vfuncout)), __Vtemp_13);
    VL_CONCAT_WIW(102,2,100, __Vtemp_15, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__291__inp 
                    = (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                       >> 0x1eU);
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__291__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__291__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__291__Vfuncout)), __Vtemp_14);
    VL_CONCAT_WIW(105,3,102, __Vtemp_16, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__290__inp 
                    = (7U & vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU]);
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__290__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__290__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__290__Vfuncout)), __Vtemp_15);
    VL_CONCAT_WIW(108,3,105, __Vtemp_17, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__289__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                             >> 3U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__289__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__289__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__289__Vfuncout)), __Vtemp_16);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_17[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_17[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_17[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                       << 6U)) | __Vtemp_17[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_18, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__301__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                        << 0x17U) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                     >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__301__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__301__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__301__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__302__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                               >> 5U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__302__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__302__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__302__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__303__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                            << 0x1bU) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[4U] 
                                              >> 5U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__303__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__303__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__303__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__304__inp 
                                            = (0x7fffffU 
                                               & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[4U] 
                                                   << 0x12U) 
                                                  | (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                     >> 0xeU)));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__304__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__304__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__304__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                                     >> 0xdU))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_19, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__300__inp 
                    = (2U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                      >> 7U)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__300__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__300__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__300__Vfuncout)), __Vtemp_18);
    VL_CONCAT_WIW(102,2,100, __Vtemp_20, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__299__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x11U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__299__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__299__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__299__Vfuncout)), __Vtemp_19);
    VL_CONCAT_WIW(105,3,102, __Vtemp_21, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__298__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x13U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__298__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__298__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__298__Vfuncout)), __Vtemp_20);
    VL_CONCAT_WIW(108,3,105, __Vtemp_22, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__297__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x16U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__297__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__297__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__297__Vfuncout)), __Vtemp_21);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_22[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_22[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_22[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                       >> 0xdU)) | __Vtemp_22[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_23, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__309__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                        << 4U) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                  >> 0x1cU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__309__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__309__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__309__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__310__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                               >> 0x18U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__310__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__310__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__310__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__311__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                            << 8U) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0U] 
                                              >> 0x18U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__311__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__311__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__311__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__312__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0U] 
                                                  >> 1U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__312__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__312__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__312__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & vlSelfRef.tlul_socket_m1__02Etl_h_i[0U])))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_24, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__308__inp 
                    = (3U | (0xfcU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                       << 6U) | (0x3cU 
                                                 & (vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                                                    >> 0x1aU)))));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__308__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__308__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__308__Vfuncout)), __Vtemp_23);
    VL_CONCAT_WIW(102,2,100, __Vtemp_25, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__307__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 4U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__307__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__307__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__307__Vfuncout)), __Vtemp_24);
    VL_CONCAT_WIW(105,3,102, __Vtemp_26, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__306__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 6U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__306__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__306__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__306__Vfuncout)), __Vtemp_25);
    VL_CONCAT_WIW(108,3,105, __Vtemp_27, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__305__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__305__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__305__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__305__Vfuncout)), __Vtemp_26);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_27[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_27[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_27[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & vlSelfRef.tlul_socket_m1__02Etl_h_i[3U]) 
           | __Vtemp_27[3U]);
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
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.wmask_o = vlSelfRef.tlul_adapter_sram__DOT__wmask_int;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.prim_subreg__02Eds = ((IData)(vlSelfRef.prim_subreg__02Eqe)
                                     ? vlSelfRef.prim_subreg__DOT__wr_data
                                     : vlSelfRef.prim_subreg__02Eq);
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
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.tlul_adapter_sram__DOT__wdata_int = 0U;
    if ((0x1000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xffffff00U & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | (((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                    >> 0x18U) & (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o))
                   ? (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                      >> 0x18U) : 0U));
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xffff00ffU & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                     >> 0x19U) & (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o))
                    ? (0xffU & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                    : 0U) << 8U));
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xff00ffffU & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                     >> 0x1aU) & (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o))
                    ? (0xffU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                >> 8U)) : 0U) << 0x10U));
        vlSelfRef.tlul_adapter_sram__DOT__wdata_int 
            = ((0xffffffU & vlSelfRef.tlul_adapter_sram__DOT__wdata_int) 
               | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                     >> 0x1bU) & (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o))
                    ? (0xffU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                >> 0x10U)) : 0U) << 0x18U));
    }
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
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
    vlSelfRef.tlul_adapter_reg__02Etl_o[0U] = vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[0U];
    vlSelfRef.tlul_adapter_reg__02Etl_o[1U] = vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[1U];
    vlSelfRef.tlul_adapter_reg__02Etl_o[2U] = vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U];
    vlSelfRef.tlul_adapter_reg__DOT__a_ack = (IData)(
                                                     ((vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                       >> 0xcU) 
                                                      & vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[0U]));
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
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req)));
            if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__src_req;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        }
    }
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack)));
            if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__dst_ack;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
    vlSelfRef.tlul_adapter_sram__02Ewdata_o = vlSelfRef.tlul_adapter_sram__DOT__wdata_int;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.r_sram_req_o = 0U;
    if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) {
        vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q;
        vlSelfRef.r_sram_req_o = (1U & ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc)));
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d;
        vlSelfRef.r_sram_req_o = (1U & ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                              ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc)))));
    }
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata 
        = ((((4U != (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                           >> 9U))) ? 0U : 1U) << 0xfU) 
           | (((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
               << 0xeU) | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__130__inp 
                                = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                           >> 0xfU));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__130__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__130__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__130__Vfuncout)) 
                            << 0xaU) | ((([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__131__inp 
                                    = (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             >> 4U));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__131__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__131__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__131__Vfuncout)) 
                                         << 8U) | ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__132__inp 
                                = (0xffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                               >> 0x1cU)));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__132__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__132__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__132__Vfuncout))))));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                    & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    vlSelfRef.tlul_adapter_reg__DOT__rd_req = ((IData)(vlSelfRef.tlul_adapter_reg__DOT__a_ack) 
                                               & (0x800U 
                                                  == 
                                                  (0xe00U 
                                                   & vlSelfRef.tlul_adapter_reg__02Etl_i[3U])));
    vlSelfRef.tlul_adapter_reg__DOT__wr_req = ((IData)(vlSelfRef.tlul_adapter_reg__DOT__a_ack) 
                                               & ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                       >> 9U))) 
                                                  | (1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                         >> 9U)))));
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
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o)) 
            & ((IData)(vlSelfRef.req_o) & (IData)(vlSelfRef.gnt_i))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready)));
    vlSelfRef.tlul_adapter_reg__DOT__err_internal = 
        ((IData)(vlSelfRef.tlul_adapter_reg__DOT__wr_req) 
         & (0U != (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                         >> 0x1cU))));
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
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__236__inp 
                        = (0x1fU & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                    >> 0x13U));
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__236__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__236__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__236__Vfuncout)) 
          << 0x12U) | ((([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__237__inp 
                            = (0xfU & (vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0xfU));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__237__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__237__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__237__Vfuncout)) 
                        << 0xeU) | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[0U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[1U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[2U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[3U] 
                                = vlSelfRef.tlul_socket_1n__DOT__tl_t_o[3U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[0U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[1U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[2U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[3U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__tl[3U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[0U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[1U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[2U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[3U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__tl[3U];
                            vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__payload = VL_RAND_RESET_Q(43);
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__payload 
                                = ((0x78000000000ULL 
                                    & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__payload) 
                                   | (((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[2U] 
                                                         << 4U) 
                                                        | (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[1U] 
                                                           >> 0x1cU)))) 
                                       << 7U) | (QData)((IData)(
                                                                ((0x70U 
                                                                  & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[3U] 
                                                                     >> 5U)) 
                                                                 | (0xfU 
                                                                    & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[1U] 
                                                                       >> 0x18U)))))));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__payload 
                                = ((0x7fffffffffULL 
                                    & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__payload) 
                                   | ((QData)((IData)(
                                                      (0xfU 
                                                       & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__tl[0U] 
                                                          >> 0xfU)))) 
                                      << 0x27U));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__payload;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__cmd 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__241__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__cmd_intg 
                                = (0x7fU & (IData)(
                                                   (([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__243__inp 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__cmd;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__243__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__243__inp;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_i 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__243__Vfuncout;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__244__inp 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_i;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__244__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__244__inp;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__244__Vfuncout;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0xfdffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x39U));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0xfbffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x17c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x3aU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0xf7ffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x3bU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0xefffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x3cU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0xdfffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x3dU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0xbfffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x3eU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    ((0x7fffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o))))) 
                                                        << 0x3fU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o 
                                                    = 
                                                    (0x5400000000000000ULL 
                                                     ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o);
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__data_o;
                                            }(), vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__242__Vfuncout) 
                                                    >> 0x39U)));
                            __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__unused_cmd_payload 
                                = (0x1ffffffffffffffULL 
                                   & ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__246__inp 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__cmd;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__246__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__246__inp;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_i 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__246__Vfuncout;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__247__inp 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_i;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__247__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__247__inp;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__247__Vfuncout;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0xfdffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x39U));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0xfbffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x17c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x3aU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0xf7ffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x3bU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0xefffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x3cU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0xdfffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x3dU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0xbfffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x3eU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = ((0x7fffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o))))) 
                                                  << 0x3fU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o 
                                            = (0x5400000000000000ULL 
                                               ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o);
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__data_o;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__245__Vfuncout));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__cmd_intg;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__cmd_intg 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__240__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__Vfuncout 
                                = (0x7fU & (~ (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__cmd_intg)));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__238__inp 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__239__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__238__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__238__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__238__Vfuncout)) 
                                     << 7U) | ([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o = 0xffffffffULL;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = (0x7effffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o);
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = ((0x7dffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0xdeba8050ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o))))) 
                                  << 0x21U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = ((0x7bffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x413d89aaULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o))))) 
                                  << 0x22U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = ((0x77ffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x31234ed1ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o))))) 
                                  << 0x23U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = ((0x6fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0xc2c1323bULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o))))) 
                                  << 0x24U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = ((0x5fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x2dcc624cULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o))))) 
                                  << 0x25U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = ((0x3fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x98505586ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o))))) 
                                  << 0x26U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o 
                            = (0x2a00000000ULL ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o);
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__data_o;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__250__enc_data 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__251__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__250__data_intg 
                            = (0x7fU & (IData)((vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__250__enc_data 
                                                >> 0x20U)));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__250__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__250__data_intg;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__249__data_intg 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__250__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__249__Vfuncout 
                            = (0x7fU & (~ (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__249__data_intg)));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__248__inp 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__249__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__248__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__248__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__248__Vfuncout)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.re_o = ((~ (IData)(vlSelfRef.tlul_adapter_reg__DOT__err_internal)) 
                      & (IData)(vlSelfRef.tlul_adapter_reg__DOT__rd_req));
    vlSelfRef.tlul_adapter_reg__02Ewe_o = ((~ (IData)(vlSelfRef.tlul_adapter_reg__DOT__err_internal)) 
                                           & (IData)(vlSelfRef.tlul_adapter_reg__DOT__wr_req));
    vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp = 
        ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
         & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
            & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
               & (0x8000U == (0x18000U & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)))));
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
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__inp 
                                                = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)
                                                    ? 
                                                   (3U 
                                                    & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                       >> 8U))
                                                    : 0U);
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__inp 
                                                    = 
                                                    ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)
                                                      : 0U);
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              (((QData)((IData)(
                                                                                ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__inp 
                                                            = 
                                                            (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                                                              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp))
                                                              ? (IData)(
                                                                        (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                         >> 8U))
                                                              : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data);
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__Vfuncout))) 
                                                                                << 0xeU) 
                                                                               | (QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__inp 
                                                        = 
                                                        VL_EXTEND_II(14,7, 
                                                                     ([&]() {
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__inp 
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
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__Vfuncout 
                                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__inp;
                                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__Vfuncout)));
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__Vfuncout))))))))))), 
                  ((((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
                     & (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__inp 
                        = ((((IData)(vlSelfRef.gnt_i) 
                             | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
                            & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)) 
                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__Vfuncout))));
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

void Vpwm_ramp_tb___024root___eval_triggers__ico(Vpwm_ramp_tb___024root* vlSelf);
void Vpwm_ramp_tb___024root___eval_ico(Vpwm_ramp_tb___024root* vlSelf);

bool Vpwm_ramp_tb___024root___eval_phase__ico(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_phase__ico\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vpwm_ramp_tb___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vpwm_ramp_tb___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vpwm_ramp_tb___024root___eval_act(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_act\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__0(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n) {
        if (((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req) 
             & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag)))) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag = 1U;
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag = 0U;
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__1(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__1\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear = 0;
    CData/*5:0*/ __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter = 0;
    CData/*5:0*/ __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle = 0;
    CData/*1:0*/ __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q = 0;
    double __Vdly__pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev;
    __Vdly__pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev = 0;
    // Body
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear 
        = vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear;
    __Vdly__pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev 
        = vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter 
        = vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle 
        = vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle;
    __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q 
        = vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q;
    if (vlSelfRef.pwm_ramp_tb__DOT__rst_ni) {
        __Vdly__pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev 
            = ((7.00000000000000015e-03 * VL_ITOR_D_I(1, 
                                                      ((IData)(vlSelfRef.pwm_ramp_tb__DOT__reverse_i)
                                                        ? 
                                                       ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter) 
                                                        > (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle))
                                                        : 
                                                       ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter) 
                                                        < (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle))))) 
               + (9.92999999999999994e-01 * vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev));
        if (vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear) {
            __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter = 0U;
            __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle = 0U;
        } else if (vlSelfRef.pwm_ramp_tb__DOT__enable_i) {
            if ((0x3fU == (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter))) {
                __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle 
                    = (0x3fU & ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle) 
                                + (IData)(vlSelfRef.pwm_ramp_tb__DOT__step_i)));
                __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter = 0U;
            } else {
                __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter)));
            }
        }
        if (vlSelfRef.pwm_ramp_tb__DOT__enable_i) {
            if (((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__d_s) 
                 & (3U > (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q)))) {
                __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q)));
            } else if (((~ (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__d_s)) 
                        & (0U < (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q)))) {
                __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q 
                    = (3U & ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q) 
                             - (IData)(1U)));
            }
        }
        if (vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds_rise) {
            __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear = 1U;
            vlSelfRef.pwm_ramp_tb__DOT__adc_valid_o = 1U;
            vlSelfRef.pwm_ramp_tb__DOT__adc_value_o 
                = (0x3fU & ((IData)(vlSelfRef.pwm_ramp_tb__DOT__reverse_i)
                             ? ((IData)(0x3fU) - (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle))
                             : (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle)));
        } else if (vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear) {
            __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear = 0U;
            vlSelfRef.pwm_ramp_tb__DOT__adc_valid_o = 0U;
        }
        vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q 
            = vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds;
    } else {
        __Vdly__pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev = 0.0;
        __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter = 0U;
        __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle = 0U;
        __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q = 0U;
        __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear = 0U;
        vlSelfRef.pwm_ramp_tb__DOT__adc_valid_o = 0U;
        vlSelfRef.pwm_ramp_tb__DOT__adc_value_o = 0U;
        vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q = 0U;
    }
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter 
        = __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter;
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q 
        = __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q;
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear 
        = __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear;
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle 
        = __Vdly__pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle;
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds = 0U;
    if ((3U == (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q))) {
        vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds = 1U;
    } else if ((0U == (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q))) {
        vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds = 0U;
    }
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__d_s 
        = ((IData)(vlSelfRef.pwm_ramp_tb__DOT__rst_ni) 
           & (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds_rise 
        = ((~ (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q)) 
           & (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds));
    vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = ((IData)(vlSelfRef.pwm_ramp_tb__DOT__rst_ni) 
           & ((1.0 * vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev) 
              > vlSelfRef.pwm_ramp_tb__DOT__analog_input));
    vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev 
        = __Vdly__pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev;
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__2(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__2\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear = 0;
    CData/*7:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter = 0;
    CData/*7:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle = 0;
    CData/*1:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q = 0;
    CData/*0:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear = 0;
    CData/*7:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter = 0;
    CData/*7:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle = 0;
    CData/*1:0*/ __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q = 0;
    // Body
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q;
    __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q 
        = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q;
    if (vlSelfRef.multiple_pwm_ramp__02Erst_ni) {
        if (vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear) {
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter = 0U;
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle = 0U;
        } else if (vlSelfRef.multiple_pwm_ramp__02Eenable_i) {
            if ((0xffU == (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter))) {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle)));
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter = 0U;
            } else {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter)));
            }
        }
        if (vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear) {
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter = 0U;
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle = 0x7fU;
        } else if (vlSelfRef.multiple_pwm_ramp__02Eenable_i) {
            if ((0xffU == (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter))) {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle)));
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter = 0U;
            } else {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter)));
            }
        }
        if (vlSelfRef.multiple_pwm_ramp__02Eenable_i) {
            if (((IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__d_s) 
                 & (3U > (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q)))) {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q)));
            } else if (((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__d_s)) 
                        & (0U < (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q)))) {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q 
                    = (3U & ((IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q) 
                             - (IData)(1U)));
            }
            if (((IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__d_s) 
                 & (3U > (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q)))) {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q)));
            } else if (((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__d_s)) 
                        & (0U < (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q)))) {
                __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q 
                    = (3U & ((IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q) 
                             - (IData)(1U)));
            }
        }
        if (vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds_rise) {
            vlSelfRef.multiple_pwm_ramp__DOT__adc_value_0 
                = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle;
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear = 1U;
            vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_0 = 1U;
        } else if (vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear) {
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear = 0U;
            vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_0 = 0U;
        }
        if (vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds_rise) {
            vlSelfRef.multiple_pwm_ramp__DOT__adc_value_1 
                = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle;
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear = 1U;
            vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_1 = 1U;
        } else if (vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear) {
            __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear = 0U;
            vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_1 = 0U;
        }
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q 
            = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds;
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q 
            = vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds;
    } else {
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter = 0U;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle = 0U;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter = 0U;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle = 0x7fU;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q = 0U;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q = 0U;
        vlSelfRef.multiple_pwm_ramp__DOT__adc_value_0 = 0U;
        vlSelfRef.multiple_pwm_ramp__DOT__adc_value_1 = 0U;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear = 0U;
        vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_0 = 0U;
        __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear = 0U;
        vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_1 = 0U;
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q = 0U;
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q = 0U;
    }
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear 
        = __Vdly__multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear;
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds = 0U;
    if ((3U == (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q))) {
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds = 1U;
    } else if ((0U == (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q))) {
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds = 0U;
    }
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__d_s 
        = ((IData)(vlSelfRef.multiple_pwm_ramp__02Erst_ni) 
           & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds = 0U;
    if ((3U == (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q))) {
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds = 1U;
    } else if ((0U == (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q))) {
        vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds = 0U;
    }
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__d_s 
        = ((IData)(vlSelfRef.multiple_pwm_ramp__02Erst_ni) 
           & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    vlSelfRef.pwm_0_o = ((IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter) 
                         < (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle));
    vlSelfRef.pwm_1_o = ((IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter) 
                         < (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle));
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds_rise 
        = ((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q)) 
           & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds));
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds_rise 
        = ((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q)) 
           & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds));
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = ((IData)(vlSelfRef.multiple_pwm_ramp__02Erst_ni) 
           & (IData)(vlSelfRef.lvds_0_i));
    vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq 
        = ((IData)(vlSelfRef.multiple_pwm_ramp__02Erst_ni) 
           & (IData)(vlSelfRef.lvds_1_i));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__3(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__3\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni) {
        if (((IData)(vlSelfRef.r_sram_gnt_i) & (IData)(vlSelfRef.r_sram_req_o))) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr)));
        }
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 1U;
        } else if (((~ (IData)(vlSelfRef.r_sram_rvalid_i)) 
                    & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q = 0U;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 0U;
        }
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d;
        }
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q;
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq = 0U;
    }
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp 
        = (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp;
    vlSelfRef.r_sram_addr_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
            ? vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q
            : vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d);
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
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
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
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
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__4(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__4\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*106:0*/ __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    VL_ZERO_W(107, __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0);
    CData/*1:0*/ __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0;
    CData/*0:0*/ __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0;
    // Body
    __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0U;
    if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[0U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[0U] 
                             >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[1U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                             >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[2U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                             >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[3U] 
            = (0x7ffU & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                         >> 1U));
        __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 
            = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
        __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 1U;
    }
    if (__VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0) {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][0U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[0U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][1U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[1U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][2U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[2U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][3U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[3U];
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__5(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__5\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    CData/*0:0*/ __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    // Body
    __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0U;
    if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr) {
        __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 
            = (((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[2U])) 
                << 0x3fU) | (((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[1U])) 
                              << 0x1fU) | ((QData)((IData)(
                                                           vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])) 
                                           >> 1U)));
        __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 
            = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
        __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 1U;
    }
    if (__VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0) {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0] 
            = __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__6(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__6\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_adapter_sram__02Erst_ni) {
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni)))) {
        vlSelfRef.tlul_adapter_sram__DOT__intg_error_q = 0U;
    }
    vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q 
        = ((IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni) 
           & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
              & ((~ vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                    >> 0xcU))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__02Eintg_error_o = vlSelfRef.tlul_adapter_sram__DOT__intg_error_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__168__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__168__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__168__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__168__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__169__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__169__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__169__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__169__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__171__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__171__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__171__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__171__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__172__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__172__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__172__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__172__Vfuncout))))));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__177__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__177__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__177__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__177__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__178__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__178__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__178__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__178__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__180__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__180__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__180__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__180__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__181__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__181__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__181__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__181__Vfuncout))))));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__159__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__159__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__159__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__159__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__160__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__160__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__160__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__160__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__162__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__162__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__162__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__162__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__163__inp 
                                = (1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__163__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__163__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__163__Vfuncout))))));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                    & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & (IData)(vlSelfRef.rvalid_i));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__7(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__7\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vdly__tlul_socket_1n__DOT__num_req_outstanding;
    __Vdly__tlul_socket_1n__DOT__num_req_outstanding = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
        = vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.tlul_socket_1n__DOT__accept_t_req) {
            if ((1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp)))) {
                __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)));
            }
            vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding 
                = (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]);
        } else if (vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp) {
            __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
                = (0x1ffU & ((IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding) 
                             - (IData)(1U)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
             [4U][0U])) {
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 0U;
        } else if ((1U & ((vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [4U][3U] >> 0xcU) & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]))) {
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 1U;
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source 
                = (0xffU & ((vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                             [4U][3U] << 4U) | (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [4U][2U] 
                                                >> 0x1cU)));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode 
                = (7U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                         [4U][3U] >> 9U));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size 
                = (3U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                         [4U][3U] >> 4U));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type 
                = (0xfU & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [4U][0U] >> 0xfU));
        }
    } else {
        __Vdly__tlul_socket_1n__DOT__num_req_outstanding = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode = 4U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type = 9U;
        vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding = 0U;
    }
    vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding 
        = __Vdly__tlul_socket_1n__DOT__num_req_outstanding;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    VL_ASSIGNSEL_WI(66,32,0x10U, vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int, 
                    (([&]() {
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__279__val 
                        = vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type;
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__279__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__279__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__279__Vfuncout))
                      ? 0U : 0xffffffffU));
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
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__273__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__273__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__273__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__273__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__274__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__274__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__274__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__274__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__276__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__276__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__276__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__276__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__277__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__277__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__277__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__277__Vfuncout))))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__264__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__264__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__264__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__264__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__265__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__265__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__265__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__265__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__267__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__267__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__267__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__267__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__268__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__268__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__268__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__268__Vfuncout))))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][0U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][1U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][2U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U];
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__8(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__8\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest)) 
             & (IData)(vlSelfRef.tlul_socket_m1__DOT__arb_ready))) {
            vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask 
                = (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U));
        } else if (((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest)) 
                    & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__arb_ready)))) {
            vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask 
                = vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out;
        }
    } else {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask = 0U;
    }
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__353__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__353__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__353__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__353__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__354__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__354__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__354__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__354__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__356__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__356__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__356__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__356__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__357__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__357__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__357__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__357__Vfuncout))))));
    vlSelfRef.tlul_socket_m1__DOT__arb_ready = (1U 
                                                & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o)) 
                                                   & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__depth_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o) 
           || (1U & (((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                             >> 1U)) == (1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                               >> 1U)))
                      ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__362__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__362__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__362__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__362__Vfuncout)) 
                         - ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__363__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__363__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__363__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__363__Vfuncout)))
                      : (((IData)(1U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__365__inp 
                                    = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__365__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__365__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__365__Vfuncout))) 
                         + ([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__366__inp 
                                = (1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
                            vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__366__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__366__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__366__Vfuncout))))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__9(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__9\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ (IData)(vlSelfRef.tlul_assert_multiple__02Erst_ni)))) {
        vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_sva = 0U;
        vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_d_error_sva = 0U;
        vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_sva = 0U;
        vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_d_error_sva = 0U;
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__10(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__10\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_fifo_async_simple__DOT__wr_en) {
        vlSelfRef.prim_fifo_async_simple__DOT__data_q 
            = vlSelfRef.prim_fifo_async_simple__02Ewdata_i;
    }
    vlSelfRef.prim_fifo_async_simple__02Erdata_o = vlSelfRef.prim_fifo_async_simple__DOT__data_q;
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__11(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__11\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_filter__02Erst_ni) {
        vlSelfRef.prim_filter__DOT__stored_vector_q 
            = vlSelfRef.prim_filter__DOT__stored_vector_d;
        if (((0U == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)) 
             | (0xfU == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)))) {
            vlSelfRef.prim_filter__DOT__stored_value_q 
                = vlSelfRef.prim_filter__02Efilter_i;
        }
    } else {
        vlSelfRef.prim_filter__DOT__stored_vector_q = 0U;
        vlSelfRef.prim_filter__DOT__stored_value_q = 0U;
    }
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0xeU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_filter__02Efilter_o = ((IData)(vlSelfRef.prim_filter__02Eenable_i)
                                           ? (IData)(vlSelfRef.prim_filter__DOT__stored_value_q)
                                           : (IData)(vlSelfRef.prim_filter__02Efilter_i));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__12(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__12\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_filter_ctr__02Erst_ni) {
        vlSelfRef.prim_filter_ctr__DOT__filter_q = vlSelfRef.prim_filter_ctr__02Efilter_i;
        vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q 
            = vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d;
        if (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d) 
             == (IData)(vlSelfRef.thresh_i))) {
            vlSelfRef.prim_filter_ctr__DOT__stored_value_q 
                = vlSelfRef.prim_filter_ctr__02Efilter_i;
        }
    } else {
        vlSelfRef.prim_filter_ctr__DOT__filter_q = 0U;
        vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q = 0U;
        vlSelfRef.prim_filter_ctr__DOT__stored_value_q = 0U;
    }
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
    vlSelfRef.prim_filter_ctr__02Efilter_o = ((IData)(vlSelfRef.prim_filter_ctr__02Eenable_i)
                                               ? (IData)(vlSelfRef.prim_filter_ctr__DOT__stored_value_q)
                                               : (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__13(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__13\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    if (vlSelfRef.tlul_adapter_host__02Erst_ni) {
        vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q 
            = vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d;
        vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q 
            = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d;
    } else {
        vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q = 0U;
        vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q = 0U;
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
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    if (((IData)(vlSelfRef.req_i) & (IData)(vlSelfRef.gnt_o))) {
        vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
            = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q))));
    }
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout 
        = __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp;
    vlSelfRef.tlul_adapter_host__DOT__tl_source = __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout;
    VL_CONCAT_WIQ(92,32,60, __Vtemp_1, ([&]() {
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
    VL_CONCAT_WIW(100,8,92, __Vtemp_2, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp 
                    = vlSelfRef.tlul_adapter_host__DOT__tl_source;
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout)), __Vtemp_1);
    vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] = 
        __Vtemp_2[0U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[1U] = 
        __Vtemp_2[1U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[2U] = 
        __Vtemp_2[2U];
    vlSelfRef.tlul_adapter_host__DOT__tl_out[3U] = 
        (0x20U | (((IData)(vlSelfRef.req_i) << 0xcU) 
                  | ((((IData)(vlSelfRef.we_i) ? ((0xfU 
                                                   == (IData)(vlSelfRef.be_i))
                                                   ? 0U
                                                   : 1U)
                        : 4U) << 9U) | __Vtemp_2[3U])));
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
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__14(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__14\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q 
        = vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_d));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq));
    vlSelfRef.prim_fifo_async_simple__02Ewready_o = 
        ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.prim_fifo_async_simple__DOT__src_ack = 0U;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q));
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
            = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack;
    }
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
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
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__15(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__15\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_subreg__02Erst_ni) {
        if (vlSelfRef.prim_subreg__02Eqe) {
            vlSelfRef.prim_subreg__02Eq = vlSelfRef.prim_subreg__DOT__wr_data;
        }
    } else {
        vlSelfRef.prim_subreg__02Eq = 0U;
    }
    vlSelfRef.prim_subreg__02Eqs = vlSelfRef.prim_subreg__02Eq;
    vlSelfRef.prim_subreg__02Eds = ((IData)(vlSelfRef.prim_subreg__02Eqe)
                                     ? vlSelfRef.prim_subreg__DOT__wr_data
                                     : vlSelfRef.prim_subreg__02Eq);
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__16(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__16\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
    }
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    }
}

extern const VlWide<80>/*2559:0*/ Vpwm_ramp_tb__ConstPool__CONST_h0c307d38_0;

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__17(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__17\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp = 0;
    // Body
    if (vlSelfRef.tlul_assert_multiple__02Erst_ni) {
        if ((0x2000000U & vlSelfRef.h2d[6U])) {
            if ((4U & vlSelfRef.d2h[2U])) {
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h2f9dcced__0 = 1U;
                if ((0x9ffU >= (0xfffU & ((IData)(9U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & (vlSelfRef.h2d[6U] 
                                                   >> 9U))))))) {
                    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req[(0x7fU 
                                                                                & (((IData)(9U) 
                                                                                + 
                                                                                ((IData)(0xaU) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (vlSelfRef.h2d[6U] 
                                                                                >> 9U)))) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(9U) 
                                                   + 
                                                   ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.h2d[6U] 
                                                        >> 9U))))))) 
                            & vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req[
                            (0x7fU & (((IData)(9U) 
                                       + ((IData)(0xaU) 
                                          * (0xffU 
                                             & (vlSelfRef.h2d[6U] 
                                                >> 9U)))) 
                                      >> 5U))]) | ((IData)(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h2f9dcced__0) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       + 
                                                       ((IData)(0xaU) 
                                                        * 
                                                        (0xffU 
                                                         & (vlSelfRef.h2d[6U] 
                                                            >> 9U)))))));
                }
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h8d3db085__0 
                    = (7U & (vlSelfRef.h2d[6U] >> 0x16U));
                if ((0x9ffU >= (0xfffU & ((IData)(6U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & (vlSelfRef.h2d[6U] 
                                                   >> 9U))))))) {
                    VL_ASSIGNSEL_WI(2560,3,(0xfffU 
                                            & ((IData)(6U) 
                                               + ((IData)(0xaU) 
                                                  * 
                                                  (0xffU 
                                                   & (vlSelfRef.h2d[6U] 
                                                      >> 9U))))), vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req, vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h8d3db085__0);
                }
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h30376d23__0 
                    = (3U & (vlSelfRef.h2d[6U] >> 0x11U));
                if ((0x9ffU >= (0xfffU & ((IData)(4U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & (vlSelfRef.h2d[6U] 
                                                   >> 9U))))))) {
                    VL_ASSIGNSEL_WI(2560,2,(0xfffU 
                                            & ((IData)(4U) 
                                               + ((IData)(0xaU) 
                                                  * 
                                                  (0xffU 
                                                   & (vlSelfRef.h2d[6U] 
                                                      >> 9U))))), vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req, vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h30376d23__0);
                }
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h6d84055b__0 
                    = (0xfU & (vlSelfRef.h2d[5U] >> 5U));
                if ((0x9ffU >= (0xfffU & ((IData)(0xaU) 
                                          * (0xffU 
                                             & (vlSelfRef.h2d[6U] 
                                                >> 9U)))))) {
                    VL_ASSIGNSEL_WI(2560,4,(0xfffU 
                                            & ((IData)(0xaU) 
                                               * (0xffU 
                                                  & (vlSelfRef.h2d[6U] 
                                                     >> 9U)))), vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req, vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_h6d84055b__0);
                }
            }
        }
        if ((8U & vlSelfRef.d2h[4U])) {
            if ((0x2000U & vlSelfRef.h2d[3U])) {
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_ha603a01c__0 = 0U;
                if ((0x9ffU >= (0xfffU & ((IData)(9U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & (vlSelfRef.d2h[3U] 
                                                   >> 0x13U))))))) {
                    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req[(0x7fU 
                                                                                & (((IData)(9U) 
                                                                                + 
                                                                                ((IData)(0xaU) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (vlSelfRef.d2h[3U] 
                                                                                >> 0x13U)))) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(9U) 
                                                   + 
                                                   ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.d2h[3U] 
                                                        >> 0x13U))))))) 
                            & vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req[
                            (0x7fU & (((IData)(9U) 
                                       + ((IData)(0xaU) 
                                          * (0xffU 
                                             & (vlSelfRef.d2h[3U] 
                                                >> 0x13U)))) 
                                      >> 5U))]) | ((IData)(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT____Vlvbound_ha603a01c__0) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       + 
                                                       ((IData)(0xaU) 
                                                        * 
                                                        (0xffU 
                                                         & (vlSelfRef.d2h[3U] 
                                                            >> 0x13U)))))));
                }
            }
        }
        if ((0x1000U & vlSelfRef.h2d[3U])) {
            if ((1U & vlSelfRef.d2h[0U])) {
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h2f9dcced__0 = 1U;
                if ((0x9ffU >= (0xfffU & ((IData)(9U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & ((vlSelfRef.h2d[3U] 
                                                    << 4U) 
                                                   | (vlSelfRef.h2d[2U] 
                                                      >> 0x1cU)))))))) {
                    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req[(0x7fU 
                                                                                & (((IData)(9U) 
                                                                                + 
                                                                                ((IData)(0xaU) 
                                                                                * 
                                                                                (0xffU 
                                                                                & ((vlSelfRef.h2d[3U] 
                                                                                << 4U) 
                                                                                | (vlSelfRef.h2d[2U] 
                                                                                >> 0x1cU))))) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(9U) 
                                                   + 
                                                   ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & ((vlSelfRef.h2d[3U] 
                                                         << 4U) 
                                                        | (vlSelfRef.h2d[2U] 
                                                           >> 0x1cU)))))))) 
                            & vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req[
                            (0x7fU & (((IData)(9U) 
                                       + ((IData)(0xaU) 
                                          * (0xffU 
                                             & ((vlSelfRef.h2d[3U] 
                                                 << 4U) 
                                                | (vlSelfRef.h2d[2U] 
                                                   >> 0x1cU))))) 
                                      >> 5U))]) | ((IData)(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h2f9dcced__0) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       + 
                                                       ((IData)(0xaU) 
                                                        * 
                                                        (0xffU 
                                                         & ((vlSelfRef.h2d[3U] 
                                                             << 4U) 
                                                            | (vlSelfRef.h2d[2U] 
                                                               >> 0x1cU))))))));
                }
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h8d3db085__0 
                    = (7U & (vlSelfRef.h2d[3U] >> 9U));
                if ((0x9ffU >= (0xfffU & ((IData)(6U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & ((vlSelfRef.h2d[3U] 
                                                    << 4U) 
                                                   | (vlSelfRef.h2d[2U] 
                                                      >> 0x1cU)))))))) {
                    VL_ASSIGNSEL_WI(2560,3,(0xfffU 
                                            & ((IData)(6U) 
                                               + ((IData)(0xaU) 
                                                  * 
                                                  (0xffU 
                                                   & ((vlSelfRef.h2d[3U] 
                                                       << 4U) 
                                                      | (vlSelfRef.h2d[2U] 
                                                         >> 0x1cU)))))), vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req, vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h8d3db085__0);
                }
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h30376d23__0 
                    = (3U & (vlSelfRef.h2d[3U] >> 4U));
                if ((0x9ffU >= (0xfffU & ((IData)(4U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & ((vlSelfRef.h2d[3U] 
                                                    << 4U) 
                                                   | (vlSelfRef.h2d[2U] 
                                                      >> 0x1cU)))))))) {
                    VL_ASSIGNSEL_WI(2560,2,(0xfffU 
                                            & ((IData)(4U) 
                                               + ((IData)(0xaU) 
                                                  * 
                                                  (0xffU 
                                                   & ((vlSelfRef.h2d[3U] 
                                                       << 4U) 
                                                      | (vlSelfRef.h2d[2U] 
                                                         >> 0x1cU)))))), vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req, vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h30376d23__0);
                }
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h6d84055b__0 
                    = (0xfU & (vlSelfRef.h2d[1U] >> 0x18U));
                if ((0x9ffU >= (0xfffU & ((IData)(0xaU) 
                                          * (0xffU 
                                             & ((vlSelfRef.h2d[3U] 
                                                 << 4U) 
                                                | (vlSelfRef.h2d[2U] 
                                                   >> 0x1cU))))))) {
                    VL_ASSIGNSEL_WI(2560,4,(0xfffU 
                                            & ((IData)(0xaU) 
                                               * (0xffU 
                                                  & ((vlSelfRef.h2d[3U] 
                                                      << 4U) 
                                                     | (vlSelfRef.h2d[2U] 
                                                        >> 0x1cU))))), vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req, vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_h6d84055b__0);
                }
            }
        }
        if ((2U & vlSelfRef.d2h[2U])) {
            if ((1U & vlSelfRef.h2d[0U])) {
                vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_ha603a01c__0 = 0U;
                if ((0x9ffU >= (0xfffU & ((IData)(9U) 
                                          + ((IData)(0xaU) 
                                             * (0xffU 
                                                & (vlSelfRef.d2h[1U] 
                                                   >> 0x11U))))))) {
                    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req[(0x7fU 
                                                                                & (((IData)(9U) 
                                                                                + 
                                                                                ((IData)(0xaU) 
                                                                                * 
                                                                                (0xffU 
                                                                                & (vlSelfRef.d2h[1U] 
                                                                                >> 0x11U)))) 
                                                                                >> 5U))] 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & ((IData)(9U) 
                                                   + 
                                                   ((IData)(0xaU) 
                                                    * 
                                                    (0xffU 
                                                     & (vlSelfRef.d2h[1U] 
                                                        >> 0x11U))))))) 
                            & vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req[
                            (0x7fU & (((IData)(9U) 
                                       + ((IData)(0xaU) 
                                          * (0xffU 
                                             & (vlSelfRef.d2h[1U] 
                                                >> 0x11U)))) 
                                      >> 5U))]) | ((IData)(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT____Vlvbound_ha603a01c__0) 
                                                   << 
                                                   (0x1fU 
                                                    & ((IData)(9U) 
                                                       + 
                                                       ((IData)(0xaU) 
                                                        * 
                                                        (0xffU 
                                                         & (vlSelfRef.d2h[1U] 
                                                            >> 0x11U)))))));
                }
            }
        }
    } else {
        VL_ASSIGN_W(2560,vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req, Vpwm_ramp_tb__ConstPool__CONST_h0c307d38_0);
        VL_ASSIGN_W(2560,vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req, Vpwm_ramp_tb__ConstPool__CONST_h0c307d38_0);
    }
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp 
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
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__sv2v_cast_8__184__Vfuncout;
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp 
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
    __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__inp;
    vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask 
        = __Vfunc_tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__sv2v_cast_8__188__Vfuncout;
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__18(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__18\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_req = 0U;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__dst_req 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__dst_req 
            = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req;
    }
    vlSelfRef.prim_fifo_async_simple__02Ervalid_o = vlSelfRef.prim_fifo_async_simple__DOT__dst_req;
    vlSelfRef.prim_fifo_async_simple__DOT__dst_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q;
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack)));
            if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__dst_ack;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__19(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__19\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
    }
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__20(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__20\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in = 0;
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
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni) {
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d;
        }
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q;
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq = 0U;
    }
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp 
        = (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp;
    vlSelfRef.w_sram_addr_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout;
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
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__21(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__21\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__unused_decsub_msb = 0;
    // Body
    if (vlSelfRef.rst_h_ni) {
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq;
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q;
    } else {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp = 0U;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__205__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp = 0U;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__230__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
           == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q)));
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
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__223__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__223__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__223__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__223__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__224__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__224__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__224__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__224__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__226__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__226__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__226__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__226__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__227__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__227__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__227__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__227__Vfuncout))))));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__wdepth_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)
            ? 4U : (7U & (((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__194__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__194__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__194__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__194__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__195__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__195__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__195__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__195__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__197__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__197__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__197__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__197__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__198__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__198__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__198__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__198__Vfuncout))))));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__22(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__22\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in = 0;
    // Body
    if (vlSelfRef.rst_d_ni) {
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d;
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq;
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d;
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q;
    } else {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__209__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp = 0U;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__228__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp = 0U;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__207__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
           == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__234__Vfuncout;
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
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__200__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__200__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__200__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__200__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__201__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__201__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__201__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__201__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__203__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__203__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__203__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__203__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__204__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__204__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__204__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__sv2v_cast_2DA09__204__Vfuncout))))));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__wdepth_o 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)
            ? 4U : (7U & (((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
                                  >> 2U)) == (1U & 
                                              ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q) 
                                               >> 2U)))
                           ? (([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__217__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__217__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__217__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__217__Vfuncout)) 
                              - ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__218__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__218__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__218__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__218__Vfuncout)))
                           : (((IData)(4U) - ([&]() {
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__220__inp 
                                    = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q));
                                vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__220__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__220__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__220__Vfuncout))) 
                              + ([&]() {
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__221__inp 
                                = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
                            vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__221__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__221__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__sv2v_cast_2DA09__221__Vfuncout))))));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__23(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__23\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_adapter_reg__02Erst_ni) {
        if (vlSelfRef.tlul_adapter_reg__DOT__a_ack) {
            vlSelfRef.tlul_adapter_reg__DOT__reqid_q 
                = (0xffU & ((vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                             << 4U) | (vlSelfRef.tlul_adapter_reg__02Etl_i[2U] 
                                       >> 0x1cU)));
            vlSelfRef.tlul_adapter_reg__DOT__reqsz_q 
                = (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                         >> 4U));
            vlSelfRef.tlul_adapter_reg__DOT__rspop_q 
                = ((IData)(vlSelfRef.tlul_adapter_reg__DOT__rd_req)
                    ? 1U : 0U);
            vlSelfRef.tlul_adapter_reg__DOT__error_q 
                = ((IData)(vlSelfRef.error_i) | (IData)(vlSelfRef.tlul_adapter_reg__DOT__err_internal));
            vlSelfRef.tlul_adapter_reg__DOT__rdata_q 
                = ((((IData)(vlSelfRef.error_i) | (IData)(vlSelfRef.tlul_adapter_reg__DOT__err_internal)) 
                    | (IData)(vlSelfRef.tlul_adapter_reg__DOT__wr_req))
                    ? 0xffffffffU : vlSelfRef.tlul_adapter_reg__02Erdata_i);
            vlSelfRef.tlul_adapter_reg__DOT__outstanding_q = 1U;
        } else if ((IData)(((vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U] 
                             >> 1U) & vlSelfRef.tlul_adapter_reg__02Etl_i[0U]))) {
            vlSelfRef.tlul_adapter_reg__DOT__outstanding_q = 0U;
        }
    } else {
        vlSelfRef.tlul_adapter_reg__DOT__reqid_q = 0U;
        vlSelfRef.tlul_adapter_reg__DOT__reqsz_q = 0U;
        vlSelfRef.tlul_adapter_reg__DOT__rspop_q = 0U;
        vlSelfRef.tlul_adapter_reg__DOT__error_q = 0U;
        vlSelfRef.tlul_adapter_reg__DOT__rdata_q = 0U;
        vlSelfRef.tlul_adapter_reg__DOT__outstanding_q = 0U;
    }
    VL_CONCAT_WQI(66,64,2, vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre, 
                  (((QData)((IData)(vlSelfRef.tlul_adapter_reg__DOT__outstanding_q)) 
                    << 0x3fU) | (((QData)((IData)(vlSelfRef.tlul_adapter_reg__DOT__rspop_q)) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__inp 
                                                = vlSelfRef.tlul_adapter_reg__DOT__reqsz_q;
                                            vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_FDEB5__39__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__inp 
                                                    = vlSelfRef.tlul_adapter_reg__DOT__reqid_q;
                                                vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_15E34__40__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              ((QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__inp 
                                                        = vlSelfRef.tlul_adapter_reg__DOT__rdata_q;
                                                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__inp;
                                                }(), vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_9783B__42__Vfuncout))) 
                                                                               << 0xeU))))))), 
                  (((IData)(vlSelfRef.tlul_adapter_reg__DOT__error_q) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__inp 
                        = (1U & (~ ((IData)(vlSelfRef.tlul_adapter_reg__DOT__outstanding_q) 
                                    | ((vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                        >> 0xcU) & (IData)(vlSelfRef.busy_i)))));
                    vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_reg__DOT__sv2v_cast_1__44__Vfuncout))));
    vlSelfRef.tlul_adapter_reg__02Etl_o[0U] = vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[0U];
    vlSelfRef.tlul_adapter_reg__02Etl_o[1U] = vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[1U];
    vlSelfRef.tlul_adapter_reg__02Etl_o[2U] = vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U];
    vlSelfRef.tlul_adapter_reg__DOT__a_ack = (IData)(
                                                     ((vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                       >> 0xcU) 
                                                      & vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[0U]));
    vlSelfRef.tlul_adapter_reg__DOT__rd_req = ((IData)(vlSelfRef.tlul_adapter_reg__DOT__a_ack) 
                                               & (0x800U 
                                                  == 
                                                  (0xe00U 
                                                   & vlSelfRef.tlul_adapter_reg__02Etl_i[3U])));
    vlSelfRef.tlul_adapter_reg__DOT__wr_req = ((IData)(vlSelfRef.tlul_adapter_reg__DOT__a_ack) 
                                               & ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                       >> 9U))) 
                                                  | (1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                         >> 9U)))));
    vlSelfRef.tlul_adapter_reg__DOT__err_internal = 
        ((IData)(vlSelfRef.tlul_adapter_reg__DOT__wr_req) 
         & (0U != (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                         >> 0x1cU))));
    vlSelfRef.re_o = ((~ (IData)(vlSelfRef.tlul_adapter_reg__DOT__err_internal)) 
                      & (IData)(vlSelfRef.tlul_adapter_reg__DOT__rd_req));
    vlSelfRef.tlul_adapter_reg__02Ewe_o = ((~ (IData)(vlSelfRef.tlul_adapter_reg__DOT__err_internal)) 
                                           & (IData)(vlSelfRef.tlul_adapter_reg__DOT__wr_req));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__24(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__24\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata;
    }
    if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata;
    }
    if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata;
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__25(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__25\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__26(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__26\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q;
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__src_req;
    }
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__27(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__27\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__28(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__28\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni) {
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d;
        }
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q = 0U;
    }
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
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.r_sram_req_o = 0U;
    vlSelfRef.r_sram_req_o = (1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
                                     ? ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))
                                     : ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                              ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))))));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_comb__TOP__4(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_comb__TOP__4\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__29(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__29\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in = 0;
    // Body
    if (vlSelfRef.rst_h_ni) {
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d;
        }
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d;
        }
    } else {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__232__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0xcU));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__211__Vfuncout;
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_comb__TOP__5(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_comb__TOP__5\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_sequent__TOP__30(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_sequent__TOP__30\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o)) 
            & ((IData)(vlSelfRef.req_o) & (IData)(vlSelfRef.gnt_i))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vpwm_ramp_tb___024root___nba_comb__TOP__6(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___nba_comb__TOP__6\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage);
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
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__116__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                               >> 0xaU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__116__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__116__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__116__Vfuncout))
            ? 0U : 0xffffffffU);
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ 
        = (0x7fU & (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__120__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                   >> 0xaU));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__120__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__120__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__120__Vfuncout))
                     ? (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
                                >> 0x20U)) : (IData)(
                                                     (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
                                                      >> 0x20U))));
    vlSelfRef.tlul_adapter_sram__DOT__d_valid = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                                 && (1U 
                                                     & (IData)(
                                                               ((0x8000U 
                                                                 != 
                                                                 (0x1c000U 
                                                                  & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                                                | (IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid)))));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata 
        = (((QData)((IData)((vlSelfRef.tlul_adapter_sram__02Erdata_i 
                             & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp = 
        ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
         & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
            & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
               & (0x8000U == (0x18000U & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)))));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)
            ? 0ULL : (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                       & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                       ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                       : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage));
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
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__inp 
                                                = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)
                                                    ? 
                                                   (3U 
                                                    & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                       >> 8U))
                                                    : 0U);
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__122__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__inp 
                                                    = 
                                                    ((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)
                                                      : 0U);
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__123__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              (((QData)((IData)(
                                                                                ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__inp 
                                                            = 
                                                            (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                                                              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp))
                                                              ? (IData)(
                                                                        (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                         >> 8U))
                                                              : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data);
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__125__Vfuncout))) 
                                                                                << 0xeU) 
                                                                               | (QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__inp 
                                                        = 
                                                        VL_EXTEND_II(14,7, 
                                                                     ([&]() {
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__inp 
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
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__Vfuncout 
                                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__inp;
                                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__128__Vfuncout)));
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__126__Vfuncout))))))))))), 
                  ((((IData)(vlSelfRef.tlul_adapter_sram__DOT__d_valid) 
                     & (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__inp 
                        = ((((IData)(vlSelfRef.gnt_i) 
                             | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
                            & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)) 
                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__129__Vfuncout))));
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

void Vpwm_ramp_tb___024root___timing_resume(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___timing_resume\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x1000000000ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vpwm_ramp_tb___024root___eval_triggers__act(Vpwm_ramp_tb___024root* vlSelf);

bool Vpwm_ramp_tb___024root___eval_phase__act(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_phase__act\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<37> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpwm_ramp_tb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vpwm_ramp_tb___024root___timing_resume(vlSelf);
        Vpwm_ramp_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vpwm_ramp_tb___024root___eval_nba(Vpwm_ramp_tb___024root* vlSelf);

bool Vpwm_ramp_tb___024root___eval_phase__nba(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_phase__nba\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpwm_ramp_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpwm_ramp_tb___024root___dump_triggers__ico(Vpwm_ramp_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpwm_ramp_tb___024root___dump_triggers__nba(Vpwm_ramp_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpwm_ramp_tb___024root___dump_triggers__act(Vpwm_ramp_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vpwm_ramp_tb___024root___eval(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vpwm_ramp_tb___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/pwm_ramp.v", 311, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vpwm_ramp_tb___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vpwm_ramp_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/pwm_ramp.v", 311, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vpwm_ramp_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/pwm_ramp.v", 311, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vpwm_ramp_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vpwm_ramp_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpwm_ramp_tb___024root___eval_debug_assertions(Vpwm_ramp_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root___eval_debug_assertions\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prev_data_i & 0xfeU)))) {
        Verilated::overWidthError("prev_data_i");}
    if (VL_UNLIKELY(((vlSelfRef.src_data_i & 0xfeU)))) {
        Verilated::overWidthError("src_data_i");}
    if (VL_UNLIKELY(((vlSelfRef.re & 0xfeU)))) {
        Verilated::overWidthError("re");}
    if (VL_UNLIKELY(((vlSelfRef.prim_subreg_ext__02Ewe 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_subreg_ext.we");}
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("sram2tlul.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("sram2tlul.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Etl_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("sram2tlul.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.mem_req_i & 0xfeU)))) {
        Verilated::overWidthError("mem_req_i");}
    if (VL_UNLIKELY(((vlSelfRef.mem_write_i & 0xfeU)))) {
        Verilated::overWidthError("mem_write_i");}
    if (VL_UNLIKELY(((vlSelfRef.mem_addr_i & 0xf000U)))) {
        Verilated::overWidthError("mem_addr_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.clk_wr_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rst_wr_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.wvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.clk_rd_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rst_rd_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rready_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.clk_wr_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rst_wr_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.wvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.clk_rd_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rst_rd_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rready_i");}
    if (VL_UNLIKELY(((vlSelfRef.w_sram_gnt_i & 0xfeU)))) {
        Verilated::overWidthError("w_sram_gnt_i");}
    if (VL_UNLIKELY(((vlSelfRef.w_sram_rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("w_sram_rvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.w_sram_rerror_i & 0xfcU)))) {
        Verilated::overWidthError("w_sram_rerror_i");}
    if (VL_UNLIKELY(((vlSelfRef.r_sram_gnt_i & 0xfeU)))) {
        Verilated::overWidthError("r_sram_gnt_i");}
    if (VL_UNLIKELY(((vlSelfRef.r_sram_rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("r_sram_rvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.r_sram_rerror_i & 0xfcU)))) {
        Verilated::overWidthError("r_sram_rerror_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.enable_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Efilter_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.filter_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.enable_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Efilter_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.filter_i");}
    if (VL_UNLIKELY(((vlSelfRef.thresh_i & 0xfcU)))) {
        Verilated::overWidthError("thresh_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_subreg__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_subreg.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_subreg__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_subreg.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_subreg__02Ewe 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_subreg.we");}
    if (VL_UNLIKELY(((vlSelfRef.de & 0xfeU)))) {
        Verilated::overWidthError("de");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.req_i & 0xfeU)))) {
        Verilated::overWidthError("req_i");}
    if (VL_UNLIKELY(((vlSelfRef.we_i & 0xfeU)))) {
        Verilated::overWidthError("we_i");}
    if (VL_UNLIKELY(((vlSelfRef.wdata_intg_i & 0x80U)))) {
        Verilated::overWidthError("wdata_intg_i");}
    if (VL_UNLIKELY(((vlSelfRef.be_i & 0xf0U)))) {
        Verilated::overWidthError("be_i");}
    if (VL_UNLIKELY(((vlSelfRef.instr_type_i & 0xf0U)))) {
        Verilated::overWidthError("instr_type_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("tlul_adapter_host.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_reg__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_reg.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_reg__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_reg.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_adapter_reg.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_reg__02Een_ifetch_i 
                      & 0xf0U)))) {
        Verilated::overWidthError("tlul_adapter_reg.en_ifetch_i");}
    if (VL_UNLIKELY(((vlSelfRef.busy_i & 0xfeU)))) {
        Verilated::overWidthError("busy_i");}
    if (VL_UNLIKELY(((vlSelfRef.error_i & 0xfeU)))) {
        Verilated::overWidthError("error_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_sram.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_sram.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_adapter_sram.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Een_ifetch_i 
                      & 0xf0U)))) {
        Verilated::overWidthError("tlul_adapter_sram.en_ifetch_i");}
    if (VL_UNLIKELY(((vlSelfRef.gnt_i & 0xfeU)))) {
        Verilated::overWidthError("gnt_i");}
    if (VL_UNLIKELY(((vlSelfRef.rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("rvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.rerror_i & 0xfcU)))) {
        Verilated::overWidthError("rerror_i");}
    if (VL_UNLIKELY(((vlSelfRef.readback_en_i & 0xf0U)))) {
        Verilated::overWidthError("readback_en_i");}
    if (VL_UNLIKELY(((vlSelfRef.wr_collision_i & 0xfeU)))) {
        Verilated::overWidthError("wr_collision_i");}
    if (VL_UNLIKELY(((vlSelfRef.write_pending_i & 0xfeU)))) {
        Verilated::overWidthError("write_pending_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_assert_multiple__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_assert_multiple.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_assert_multiple__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_assert_multiple.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.h2d[6U] & 0xfc000000U)))) {
        Verilated::overWidthError("h2d");}
    if (VL_UNLIKELY(((vlSelfRef.d2h[4U] & 0xfffffff0U)))) {
        Verilated::overWidthError("d2h");}
    if (VL_UNLIKELY(((vlSelfRef.clk_h_i & 0xfeU)))) {
        Verilated::overWidthError("clk_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.rst_h_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_h_ni");}
    if (VL_UNLIKELY(((vlSelfRef.clk_d_i & 0xfeU)))) {
        Verilated::overWidthError("clk_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.rst_d_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_d_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_fifo_async.tl_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("tlul_fifo_async.tl_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_1n.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_1n.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_socket_1n.tl_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                      & 0xffffff00U)))) {
        Verilated::overWidthError("tlul_socket_1n.tl_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.dev_select_i & 0xf8U)))) {
        Verilated::overWidthError("dev_select_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_m1.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_m1.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                      & 0xfff00000U)))) {
        Verilated::overWidthError("tlul_socket_m1.tl_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("tlul_socket_m1.tl_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.multiple_pwm_ramp__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("multiple_pwm_ramp.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.multiple_pwm_ramp__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("multiple_pwm_ramp.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.multiple_pwm_ramp__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("multiple_pwm_ramp.enable_i");}
    if (VL_UNLIKELY(((vlSelfRef.lvds_0_i & 0xfeU)))) {
        Verilated::overWidthError("lvds_0_i");}
    if (VL_UNLIKELY(((vlSelfRef.lvds_1_i & 0xfeU)))) {
        Verilated::overWidthError("lvds_1_i");}
}
#endif  // VL_DEBUG
