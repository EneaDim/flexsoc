// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 1>& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 7>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.rv_timer_tb__DOT__clk_i));
    bufp->chgBit(oldp+1,(vlSelfRef.rv_timer_tb__DOT__rst_ni));
    bufp->chgCData(oldp+2,(vlSelfRef.rv_timer_tb__DOT__gpio_intr_i),2);
    bufp->chgBit(oldp+3,(vlSelfRef.rv_timer_tb__DOT__intr_timer_expired_hart0_timer0_o));
    bufp->chgBit(oldp+4,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_valid));
    bufp->chgCData(oldp+5,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_opcode),3);
    bufp->chgCData(oldp+6,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_param),3);
    bufp->chgCData(oldp+7,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_size),2);
    bufp->chgCData(oldp+8,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_source),8);
    bufp->chgIData(oldp+9,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_address),32);
    bufp->chgCData(oldp+10,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_mask),4);
    bufp->chgIData(oldp+11,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_data),32);
    bufp->chgBit(oldp+12,(vlSelfRef.rv_timer_tb__DOT__tl_i_d_ready));
    bufp->chgBit(oldp+13,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_valid));
    bufp->chgCData(oldp+14,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_opcode),3);
    bufp->chgIData(oldp+15,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_data),32);
    bufp->chgBit(oldp+16,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_error));
    bufp->chgBit(oldp+17,(vlSelfRef.rv_timer_tb__DOT__tl_o_a_ready));
    bufp->chgWData(oldp+18,(vlSelfRef.rv_timer_tb__DOT__tl_i),109);
    bufp->chgWData(oldp+22,(vlSelfRef.rv_timer_tb__DOT__tl_o),66);
    bufp->chgBit(oldp+25,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__clk_i));
    bufp->chgBit(oldp+26,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni));
    bufp->chgCData(oldp+27,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i),2);
    bufp->chgBit(oldp+28,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                 >> 0x0000000cU))));
    bufp->chgCData(oldp+29,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                   >> 9U))),3);
    bufp->chgCData(oldp+30,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                   >> 6U))),3);
    bufp->chgCData(oldp+31,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                   >> 4U))),2);
    bufp->chgCData(oldp+32,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+33,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[2U] 
                              << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[1U] 
                                        >> 0x0000001cU))),32);
    bufp->chgCData(oldp+34,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgIData(oldp+35,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[1U] 
                              << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+36,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                            >> 0x00000013U))),5);
    bufp->chgCData(oldp+37,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                            >> 0x0000000fU))),4);
    bufp->chgCData(oldp+38,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                            >> 8U))),7);
    bufp->chgCData(oldp+39,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                            >> 1U))),7);
    bufp->chgBit(oldp+40,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U])));
    bufp->chgBit(oldp+41,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                                 >> 1U))));
    bufp->chgCData(oldp+42,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                                    << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                              >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+43,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                   >> 0x0000001bU))),3);
    bufp->chgCData(oldp+44,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                   >> 0x00000019U))),2);
    bufp->chgCData(oldp+45,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                            >> 0x00000011U))),8);
    bufp->chgBit(oldp+46,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                 >> 0x00000010U))));
    bufp->chgIData(oldp+47,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                              << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                                 >> 0x00000010U))),32);
    bufp->chgCData(oldp+48,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                            >> 9U))),7);
    bufp->chgCData(oldp+49,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                            >> 2U))),7);
    bufp->chgBit(oldp+50,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                 >> 1U))));
    bufp->chgBit(oldp+51,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U])));
    bufp->chgBit(oldp+52,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o));
    bufp->chgBit(oldp+53,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x0000001bU))));
    bufp->chgBit(oldp+54,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x0000001aU))));
    bufp->chgBit(oldp+55,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x00000019U))));
    bufp->chgBit(oldp+56,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x00000018U))));
    bufp->chgBit(oldp+57,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x00000017U))));
    bufp->chgBit(oldp+58,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x00000016U))));
    bufp->chgBit(oldp+59,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                 >> 0x00000015U))));
    bufp->chgCData(oldp+60,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                            >> 0x0000000dU))),8);
    bufp->chgSData(oldp+61,((0x00000fffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                            >> 1U))),12);
    bufp->chgIData(oldp+62,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                              << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                                                 >> 1U))),32);
    bufp->chgIData(oldp+63,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                              << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
                                                 >> 1U))),32);
    bufp->chgBit(oldp+64,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U])));
    bufp->chgBit(oldp+65,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                         >> 0x00000022U)))));
    bufp->chgBit(oldp+66,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                         >> 0x00000021U)))));
    bufp->chgIData(oldp+67,((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                     >> 1U))),32);
    bufp->chgBit(oldp+68,((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg))));
    bufp->chgBit(oldp+69,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active));
    bufp->chgSData(oldp+70,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0]),12);
    bufp->chgCData(oldp+71,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0]),8);
    bufp->chgBit(oldp+72,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick));
    bufp->chgIData(oldp+73,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0]),32);
    bufp->chgIData(oldp+74,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0]),32);
    bufp->chgIData(oldp+75,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U]),32);
    bufp->chgBit(oldp+76,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]));
    bufp->chgBit(oldp+77,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set));
    bufp->chgBit(oldp+78,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en));
    bufp->chgBit(oldp+79,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q));
    bufp->chgBit(oldp+80,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe));
    bufp->chgBit(oldp+81,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q));
    bufp->chgBit(oldp+82,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de));
    bufp->chgBit(oldp+83,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d));
    bufp->chgBit(oldp+84,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out));
    bufp->chgBit(oldp+85,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0]));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 86, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q);
    bufp->chgBit(oldp+87,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0));
    bufp->chgBit(oldp+88,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1));
    bufp->chgBit(oldp+89,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__clk_i));
    bufp->chgBit(oldp+90,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni));
    bufp->chgBit(oldp+91,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active));
    bufp->chgSData(oldp+92,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler),12);
    bufp->chgCData(oldp+93,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step),8);
    bufp->chgBit(oldp+94,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick));
    bufp->chgIData(oldp+95,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d),32);
    bufp->chgIData(oldp+96,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime),32);
    bufp->chgIData(oldp+97,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0]),32);
    bufp->chgBit(oldp+98,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr));
    bufp->chgSData(oldp+99,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count),12);
    bufp->chgBit(oldp+100,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__clk_i));
    bufp->chgBit(oldp+101,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni));
    bufp->chgBit(oldp+102,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i));
    bufp->chgBit(oldp+103,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i));
    bufp->chgBit(oldp+104,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i));
    bufp->chgBit(oldp+105,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i));
    bufp->chgBit(oldp+106,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i));
    bufp->chgBit(oldp+107,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o));
    bufp->chgBit(oldp+108,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o));
    bufp->chgBit(oldp+109,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o));
    bufp->chgBit(oldp+110,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status));
    bufp->chgBit(oldp+111,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event));
    bufp->chgBit(oldp+112,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__clk_i));
    bufp->chgBit(oldp+113,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__rst_ni));
    bufp->chgBit(oldp+114,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+115,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+116,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+117,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+118,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+119,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+120,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+121,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+122,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+123,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+124,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+125,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+126,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U])));
    bufp->chgBit(oldp+127,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+128,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+129,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+130,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+131,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+132,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+133,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+134,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+135,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+136,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+137,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U])));
    bufp->chgBit(oldp+138,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+139,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+140,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+141,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x00000018U))));
    bufp->chgBit(oldp+142,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x00000017U))));
    bufp->chgBit(oldp+143,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x00000016U))));
    bufp->chgBit(oldp+144,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                  >> 0x00000015U))));
    bufp->chgCData(oldp+145,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                             >> 0x0000000dU))),8);
    bufp->chgSData(oldp+146,((0x00000fffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                             >> 1U))),12);
    bufp->chgIData(oldp+147,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                               << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                                                  >> 1U))),32);
    bufp->chgIData(oldp+148,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                               << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U] 
                                                  >> 1U))),32);
    bufp->chgBit(oldp+149,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U])));
    bufp->chgBit(oldp+150,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+151,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                          >> 0x00000021U)))));
    bufp->chgIData(oldp+152,((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                      >> 1U))),32);
    bufp->chgBit(oldp+153,((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg))));
    bufp->chgBit(oldp+154,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we));
    bufp->chgBit(oldp+155,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re));
    bufp->chgCData(oldp+156,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_addr),5);
    bufp->chgIData(oldp+157,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_wdata),32);
    bufp->chgCData(oldp+158,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be),4);
    bufp->chgIData(oldp+159,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata),32);
    bufp->chgBit(oldp+160,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error));
    bufp->chgBit(oldp+161,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss));
    bufp->chgBit(oldp+162,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err));
    bufp->chgIData(oldp+163,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+164,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+165,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+166,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+167,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+168,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                              << 4U) 
                                             | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+169,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[2U] 
                               << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+170,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+171,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[1U] 
                               << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+172,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+173,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+174,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+175,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+176,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U])));
    bufp->chgBit(oldp+177,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+178,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+179,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+180,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+181,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+182,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+183,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+184,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+185,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+186,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+187,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U])));
    bufp->chgBit(oldp+188,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+189,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+190,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+191,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+192,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+193,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+194,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+195,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+196,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+197,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+198,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U])));
    bufp->chgBit(oldp+199,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we));
    bufp->chgBit(oldp+200,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs));
    bufp->chgBit(oldp+201,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_wd));
    bufp->chgBit(oldp+202,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs));
    bufp->chgBit(oldp+203,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_wd));
    bufp->chgBit(oldp+204,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs));
    bufp->chgBit(oldp+205,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_wd));
    bufp->chgBit(oldp+206,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we));
    bufp->chgBit(oldp+207,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs));
    bufp->chgBit(oldp+208,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_wd));
    bufp->chgBit(oldp+209,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we));
    bufp->chgBit(oldp+210,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs));
    bufp->chgBit(oldp+211,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_wd));
    bufp->chgBit(oldp+212,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we));
    bufp->chgBit(oldp+213,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_wd));
    bufp->chgBit(oldp+214,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we));
    bufp->chgSData(oldp+215,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs),12);
    bufp->chgSData(oldp+216,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_wd),12);
    bufp->chgCData(oldp+217,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs),8);
    bufp->chgCData(oldp+218,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_wd),8);
    bufp->chgBit(oldp+219,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we));
    bufp->chgIData(oldp+220,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs),32);
    bufp->chgIData(oldp+221,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_wd),32);
    bufp->chgBit(oldp+222,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we));
    bufp->chgIData(oldp+223,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs),32);
    bufp->chgIData(oldp+224,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_wd),32);
    bufp->chgBit(oldp+225,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe));
    bufp->chgBit(oldp+226,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we));
    bufp->chgBit(oldp+227,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe));
    bufp->chgBit(oldp+228,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we));
    bufp->chgCData(oldp+229,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit),7);
    bufp->chgBit(oldp+230,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__unused_wdata));
    bufp->chgBit(oldp+231,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__unused_be));
    bufp->chgBit(oldp+232,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__clk_i));
    bufp->chgBit(oldp+233,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni));
    bufp->chgBit(oldp+234,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we));
    bufp->chgSData(oldp+235,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wd),12);
    bufp->chgBit(oldp+236,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qe));
    bufp->chgSData(oldp+237,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q),12);
    bufp->chgSData(oldp+238,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__ds),12);
    bufp->chgSData(oldp+239,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs),12);
    bufp->chgBit(oldp+240,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en));
    bufp->chgSData(oldp+241,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data),12);
    bufp->chgBit(oldp+242,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we));
    bufp->chgSData(oldp+243,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wd),12);
    bufp->chgSData(oldp+244,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q),12);
    bufp->chgBit(oldp+245,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgSData(oldp+246,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data),12);
    bufp->chgSData(oldp+247,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),12);
    bufp->chgBit(oldp+248,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__clk_i));
    bufp->chgBit(oldp+249,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni));
    bufp->chgBit(oldp+250,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we));
    bufp->chgCData(oldp+251,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wd),8);
    bufp->chgBit(oldp+252,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qe));
    bufp->chgCData(oldp+253,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q),8);
    bufp->chgCData(oldp+254,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__ds),8);
    bufp->chgCData(oldp+255,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs),8);
    bufp->chgBit(oldp+256,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en));
    bufp->chgCData(oldp+257,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data),8);
    bufp->chgBit(oldp+258,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+259,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->chgCData(oldp+260,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q),8);
    bufp->chgBit(oldp+261,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+262,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->chgCData(oldp+263,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->chgBit(oldp+264,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__clk_i));
    bufp->chgBit(oldp+265,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni));
    bufp->chgBit(oldp+266,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we));
    bufp->chgIData(oldp+267,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wd),32);
    bufp->chgBit(oldp+268,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe));
    bufp->chgIData(oldp+269,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q),32);
    bufp->chgIData(oldp+270,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__ds),32);
    bufp->chgIData(oldp+271,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs),32);
    bufp->chgBit(oldp+272,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en));
    bufp->chgIData(oldp+273,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data),32);
    bufp->chgBit(oldp+274,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgIData(oldp+275,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->chgIData(oldp+276,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q),32);
    bufp->chgBit(oldp+277,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgIData(oldp+278,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->chgIData(oldp+279,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->chgBit(oldp+280,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__clk_i));
    bufp->chgBit(oldp+281,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni));
    bufp->chgBit(oldp+282,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i));
    bufp->chgBit(oldp+283,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o));
    bufp->chgBit(oldp+284,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__clk_i));
    bufp->chgBit(oldp+285,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni));
    bufp->chgBit(oldp+286,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we));
    bufp->chgBit(oldp+287,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wd));
    bufp->chgBit(oldp+288,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qe));
    bufp->chgBit(oldp+289,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q));
    bufp->chgBit(oldp+290,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__ds));
    bufp->chgBit(oldp+291,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs));
    bufp->chgBit(oldp+292,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en));
    bufp->chgBit(oldp+293,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data));
    bufp->chgBit(oldp+294,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+295,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+296,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+297,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+298,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+299,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+300,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__clk_i));
    bufp->chgBit(oldp+301,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni));
    bufp->chgBit(oldp+302,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we));
    bufp->chgBit(oldp+303,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wd));
    bufp->chgBit(oldp+304,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qe));
    bufp->chgBit(oldp+305,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q));
    bufp->chgBit(oldp+306,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__ds));
    bufp->chgBit(oldp+307,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs));
    bufp->chgBit(oldp+308,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en));
    bufp->chgBit(oldp+309,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data));
    bufp->chgBit(oldp+310,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+311,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+312,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+313,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+314,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+315,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+316,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__clk_i));
    bufp->chgBit(oldp+317,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni));
    bufp->chgBit(oldp+318,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we));
    bufp->chgBit(oldp+319,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wd));
    bufp->chgBit(oldp+320,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qe));
    bufp->chgBit(oldp+321,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q));
    bufp->chgBit(oldp+322,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__ds));
    bufp->chgBit(oldp+323,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs));
    bufp->chgBit(oldp+324,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en));
    bufp->chgBit(oldp+325,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data));
    bufp->chgBit(oldp+326,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+327,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+328,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+329,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+330,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+331,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+332,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__clk_i));
    bufp->chgBit(oldp+333,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni));
    bufp->chgBit(oldp+334,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we));
    bufp->chgBit(oldp+335,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wd));
    bufp->chgBit(oldp+336,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qe));
    bufp->chgBit(oldp+337,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q));
    bufp->chgBit(oldp+338,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__ds));
    bufp->chgBit(oldp+339,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs));
    bufp->chgBit(oldp+340,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en));
    bufp->chgBit(oldp+341,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data));
    bufp->chgBit(oldp+342,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+343,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+344,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+345,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+346,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+347,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+348,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__clk_i));
    bufp->chgBit(oldp+349,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni));
    bufp->chgBit(oldp+350,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we));
    bufp->chgBit(oldp+351,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wd));
    bufp->chgBit(oldp+352,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de));
    bufp->chgBit(oldp+353,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d));
    bufp->chgBit(oldp+354,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qe));
    bufp->chgBit(oldp+355,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q));
    bufp->chgBit(oldp+356,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__ds));
    bufp->chgBit(oldp+357,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs));
    bufp->chgBit(oldp+358,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en));
    bufp->chgBit(oldp+359,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data));
    bufp->chgBit(oldp+360,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+361,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+362,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de));
    bufp->chgBit(oldp+363,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d));
    bufp->chgBit(oldp+364,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+365,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+366,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+367,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we));
    bufp->chgBit(oldp+368,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__wd));
    bufp->chgBit(oldp+369,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe));
    bufp->chgBit(oldp+370,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__q));
    bufp->chgBit(oldp+371,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__clk_i));
    bufp->chgBit(oldp+372,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni));
    bufp->chgBit(oldp+373,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+374,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+375,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+376,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+377,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+378,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+379,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+380,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+381,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+382,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+383,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+384,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+385,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U])));
    bufp->chgBit(oldp+386,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+387,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+388,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+389,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+390,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+391,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+392,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+393,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+394,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+395,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+396,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U])));
    bufp->chgBit(oldp+397,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o));
    bufp->chgBit(oldp+398,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o));
    bufp->chgCData(oldp+399,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_o),5);
    bufp->chgIData(oldp+400,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wdata_o),32);
    bufp->chgCData(oldp+401,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__be_o),4);
    bufp->chgIData(oldp+402,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i),32);
    bufp->chgBit(oldp+403,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i));
    bufp->chgBit(oldp+404,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q));
    bufp->chgBit(oldp+405,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack));
    bufp->chgBit(oldp+406,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack));
    bufp->chgIData(oldp+407,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata),32);
    bufp->chgIData(oldp+408,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q),32);
    bufp->chgBit(oldp+409,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q));
    bufp->chgBit(oldp+410,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error));
    bufp->chgBit(oldp+411,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal));
    bufp->chgBit(oldp+412,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__instr_error));
    bufp->chgBit(oldp+413,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err));
    bufp->chgBit(oldp+414,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__malformed_meta_err));
    bufp->chgBit(oldp+415,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_err));
    bufp->chgCData(oldp+416,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q),8);
    bufp->chgCData(oldp+417,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q),2);
    bufp->chgCData(oldp+418,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->chgBit(oldp+419,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req));
    bufp->chgBit(oldp+420,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req));
    bufp->chgBit(oldp+421,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+422,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+423,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+424,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+425,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+426,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+427,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+428,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+429,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+430,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+431,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U])));
    bufp->chgBit(oldp+432,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__clk_i));
    bufp->chgBit(oldp+433,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__rst_ni));
    bufp->chgBit(oldp+434,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+435,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+436,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+437,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+438,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+439,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+440,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+441,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+442,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+443,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+444,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+445,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+446,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U])));
    bufp->chgBit(oldp+447,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o));
    bufp->chgBit(oldp+448,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed));
    bufp->chgBit(oldp+449,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed));
    bufp->chgBit(oldp+450,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full));
    bufp->chgBit(oldp+451,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial));
    bufp->chgBit(oldp+452,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get));
    bufp->chgBit(oldp+453,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
    bufp->chgBit(oldp+454,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
    bufp->chgBit(oldp+455,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
    bufp->chgBit(oldp+456,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
    bufp->chgBit(oldp+457,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    bufp->chgCData(oldp+458,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__mask),4);
    bufp->chgBit(oldp+459,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+460,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+461,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+462,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+463,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+464,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+465,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+466,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+467,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+468,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+469,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->chgBit(oldp+470,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+471,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+472,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+473,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+474,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+475,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+476,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+477,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+478,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+479,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+480,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->chgBit(oldp+481,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->chgBit(oldp+482,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+483,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+484,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+485,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+486,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+487,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+488,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+489,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+490,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+491,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+492,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->chgBit(oldp+493,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+494,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+495,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+496,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+497,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+498,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+499,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+500,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+501,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+502,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+503,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->chgBit(oldp+504,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->chgBit(oldp+505,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__clk_i));
    bufp->chgBit(oldp+506,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni));
    bufp->chgBit(oldp+507,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we));
    bufp->chgIData(oldp+508,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wd),32);
    bufp->chgBit(oldp+509,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de));
    bufp->chgIData(oldp+510,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d),32);
    bufp->chgBit(oldp+511,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qe));
    bufp->chgIData(oldp+512,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q),32);
    bufp->chgIData(oldp+513,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__ds),32);
    bufp->chgIData(oldp+514,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs),32);
    bufp->chgBit(oldp+515,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en));
    bufp->chgIData(oldp+516,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data),32);
    bufp->chgBit(oldp+517,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we));
    bufp->chgIData(oldp+518,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->chgBit(oldp+519,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de));
    bufp->chgIData(oldp+520,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d),32);
    bufp->chgIData(oldp+521,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q),32);
    bufp->chgBit(oldp+522,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgIData(oldp+523,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->chgIData(oldp+524,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 525, vlSymsp->TOP__rv_timer_reg_pkg.RV_TIMER_PERMIT);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 1>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,(__VdtypeVar[0]));
}

void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 7>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[0]),4);
    bufp->chgCData(oldp+1,(__VdtypeVar[1]),4);
    bufp->chgCData(oldp+2,(__VdtypeVar[2]),4);
    bufp->chgCData(oldp+3,(__VdtypeVar[3]),4);
    bufp->chgCData(oldp+4,(__VdtypeVar[4]),4);
    bufp->chgCData(oldp+5,(__VdtypeVar[5]),4);
    bufp->chgCData(oldp+6,(__VdtypeVar[6]),4);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
