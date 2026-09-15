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

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.gpio_tb__DOT__clk_i));
    bufp->chgBit(oldp+1,(vlSelfRef.gpio_tb__DOT__rst_ni));
    bufp->chgCData(oldp+2,(vlSelfRef.gpio_tb__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+3,(vlSelfRef.gpio_tb__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+4,(vlSelfRef.gpio_tb__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+5,(vlSelfRef.gpio_tb__DOT__intr_gpio_o),4);
    bufp->chgBit(oldp+6,(vlSelfRef.gpio_tb__DOT__tl_i_a_valid));
    bufp->chgCData(oldp+7,(vlSelfRef.gpio_tb__DOT__tl_i_a_opcode),3);
    bufp->chgCData(oldp+8,(vlSelfRef.gpio_tb__DOT__tl_i_a_param),3);
    bufp->chgCData(oldp+9,(vlSelfRef.gpio_tb__DOT__tl_i_a_size),2);
    bufp->chgCData(oldp+10,(vlSelfRef.gpio_tb__DOT__tl_i_a_source),8);
    bufp->chgIData(oldp+11,(vlSelfRef.gpio_tb__DOT__tl_i_a_address),32);
    bufp->chgCData(oldp+12,(vlSelfRef.gpio_tb__DOT__tl_i_a_mask),4);
    bufp->chgIData(oldp+13,(vlSelfRef.gpio_tb__DOT__tl_i_a_data),32);
    bufp->chgBit(oldp+14,(vlSelfRef.gpio_tb__DOT__tl_i_d_ready));
    bufp->chgBit(oldp+15,(vlSelfRef.gpio_tb__DOT__tl_o_d_valid));
    bufp->chgCData(oldp+16,(vlSelfRef.gpio_tb__DOT__tl_o_d_opcode),3);
    bufp->chgIData(oldp+17,(vlSelfRef.gpio_tb__DOT__tl_o_d_data),32);
    bufp->chgBit(oldp+18,(vlSelfRef.gpio_tb__DOT__tl_o_d_error));
    bufp->chgBit(oldp+19,(vlSelfRef.gpio_tb__DOT__tl_o_a_ready));
    bufp->chgWData(oldp+20,(vlSelfRef.gpio_tb__DOT__tl_i),109);
    bufp->chgWData(oldp+24,(vlSelfRef.gpio_tb__DOT__tl_o),66);
    bufp->chgBit(oldp+27,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i));
    bufp->chgBit(oldp+28,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni));
    bufp->chgCData(oldp+29,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+30,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+31,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+32,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o),4);
    bufp->chgBit(oldp+33,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                 >> 0x0000000cU))));
    bufp->chgCData(oldp+34,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                   >> 9U))),3);
    bufp->chgCData(oldp+35,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                   >> 6U))),3);
    bufp->chgCData(oldp+36,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                   >> 4U))),2);
    bufp->chgCData(oldp+37,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+38,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                              << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                        >> 0x0000001cU))),32);
    bufp->chgCData(oldp+39,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgIData(oldp+40,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                              << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+41,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                            >> 0x00000013U))),5);
    bufp->chgCData(oldp+42,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                            >> 0x0000000fU))),4);
    bufp->chgCData(oldp+43,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                            >> 8U))),7);
    bufp->chgCData(oldp+44,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                            >> 1U))),7);
    bufp->chgBit(oldp+45,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U])));
    bufp->chgBit(oldp+46,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                 >> 1U))));
    bufp->chgCData(oldp+47,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                    << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                              >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+48,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                   >> 0x0000001bU))),3);
    bufp->chgCData(oldp+49,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                   >> 0x00000019U))),2);
    bufp->chgCData(oldp+50,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                            >> 0x00000011U))),8);
    bufp->chgBit(oldp+51,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                 >> 0x00000010U))));
    bufp->chgIData(oldp+52,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                              << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                                 >> 0x00000010U))),32);
    bufp->chgCData(oldp+53,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                            >> 9U))),7);
    bufp->chgCData(oldp+54,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                            >> 2U))),7);
    bufp->chgBit(oldp+55,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                 >> 1U))));
    bufp->chgBit(oldp+56,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U])));
    bufp->chgCData(oldp+57,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x0000001aU))),4);
    bufp->chgBit(oldp+58,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                 >> 0x00000019U))));
    bufp->chgCData(oldp+59,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x00000015U))),4);
    bufp->chgBit(oldp+60,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                 >> 0x00000014U))));
    bufp->chgCData(oldp+61,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x00000010U))),4);
    bufp->chgCData(oldp+62,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x0000000cU))),4);
    bufp->chgCData(oldp+63,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 8U))),4);
    bufp->chgCData(oldp+64,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 4U))),4);
    bufp->chgCData(oldp+65,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw)),4);
    bufp->chgCData(oldp+66,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                            >> 9U))),4);
    bufp->chgBit(oldp+67,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                 >> 8U))));
    bufp->chgCData(oldp+68,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                            >> 4U))),4);
    bufp->chgCData(oldp+69,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg))),4);
    bufp->chgBit(oldp+70,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni));
    bufp->chgBit(oldp+71,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni));
    bufp->chgBit(oldp+72,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+73,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+74,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+75,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+76,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq));
    bufp->chgBit(oldp+77,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+78,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+79,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+80,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+81,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+82,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+83,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+84,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i));
    bufp->chgBit(oldp+85,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni));
    bufp->chgCData(oldp+86,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x0000001aU))),4);
    bufp->chgBit(oldp+87,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                 >> 0x00000019U))));
    bufp->chgCData(oldp+88,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x00000015U))),4);
    bufp->chgBit(oldp+89,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                 >> 0x00000014U))));
    bufp->chgCData(oldp+90,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x00000010U))),4);
    bufp->chgCData(oldp+91,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x0000000cU))),4);
    bufp->chgCData(oldp+92,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 8U))),4);
    bufp->chgCData(oldp+93,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 4U))),4);
    bufp->chgCData(oldp+94,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)),4);
    bufp->chgCData(oldp+95,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                            >> 9U))),4);
    bufp->chgBit(oldp+96,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                 >> 8U))));
    bufp->chgCData(oldp+97,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                            >> 4U))),4);
    bufp->chgCData(oldp+98,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg))),4);
    bufp->chgCData(oldp+99,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+100,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+101,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+102,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o),4);
    bufp->chgCData(oldp+103,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d),4);
    bufp->chgCData(oldp+104,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q),4);
    bufp->chgCData(oldp+105,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q),4);
    bufp->chgCData(oldp+106,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q),4);
    bufp->chgCData(oldp+107,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise),4);
    bufp->chgCData(oldp+108,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall),4);
    bufp->chgCData(oldp+109,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high),4);
    bufp->chgCData(oldp+110,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low),4);
    bufp->chgBit(oldp+111,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni));
    bufp->chgBit(oldp+112,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni));
    bufp->chgBit(oldp+113,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+114,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+115,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+116,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+117,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+118,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+119,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+120,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+121,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+122,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+123,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+124,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+125,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+126,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+127,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+128,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+129,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+130,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+131,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+132,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+133,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+134,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+135,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+136,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+137,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+138,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+139,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+140,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+141,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+142,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+143,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+144,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+145,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+146,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+147,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+148,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+149,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+150,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+151,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+152,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+153,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+154,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+155,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+156,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+157,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+158,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+159,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+160,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+161,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+162,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+163,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+164,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+165,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+166,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+167,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+168,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+169,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+170,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+171,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+172,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+173,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+174,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+175,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+176,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+177,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+178,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+179,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+180,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+181,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+182,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+183,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+184,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+185,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+186,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+187,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+188,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+189,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+190,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+191,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+192,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+193,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+194,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+195,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+196,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+197,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+198,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+199,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+200,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+201,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+202,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+203,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+204,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+205,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+206,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+207,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+208,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+209,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+210,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+211,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+212,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+213,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+214,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+215,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+216,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+217,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+218,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+219,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i));
    bufp->chgBit(oldp+220,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni));
    bufp->chgBit(oldp+221,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+222,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+223,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+224,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+225,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+226,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+227,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+228,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+229,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+230,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+231,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+232,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+233,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U])));
    bufp->chgBit(oldp+234,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+235,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+236,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+237,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+238,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+239,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+240,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+241,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+242,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+243,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+244,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U])));
    bufp->chgCData(oldp+245,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->chgBit(oldp+246,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->chgCData(oldp+247,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+248,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+249,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+250,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+251,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+252,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+253,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw)),4);
    bufp->chgCData(oldp+254,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+255,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+256,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+257,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg))),4);
    bufp->chgBit(oldp+258,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re));
    bufp->chgBit(oldp+259,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we));
    bufp->chgCData(oldp+260,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr),4);
    bufp->chgIData(oldp+261,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata),32);
    bufp->chgCData(oldp+262,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be),4);
    bufp->chgBit(oldp+263,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+264,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+265,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+266,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                      >> 4U))),32);
    bufp->chgCData(oldp+267,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req))),4);
    bufp->chgIData(oldp+268,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                      >> 2U))),32);
    bufp->chgBit(oldp+269,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                          >> 1U)))));
    bufp->chgBit(oldp+270,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp))));
    bufp->chgBit(oldp+271,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i));
    bufp->chgBit(oldp+272,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni));
    bufp->chgBit(oldp+273,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+274,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+275,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+276,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+277,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+278,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+279,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+280,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+281,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+282,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+283,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+284,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+285,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U])));
    bufp->chgBit(oldp+286,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+287,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+288,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+289,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+290,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+291,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+292,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+293,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+294,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+295,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+296,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U])));
    bufp->chgBit(oldp+297,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o));
    bufp->chgBit(oldp+298,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o));
    bufp->chgCData(oldp+299,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o),4);
    bufp->chgIData(oldp+300,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o),32);
    bufp->chgCData(oldp+301,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o),4);
    bufp->chgBit(oldp+302,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i));
    bufp->chgIData(oldp+303,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i),32);
    bufp->chgBit(oldp+304,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i));
    bufp->chgBit(oldp+305,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q));
    bufp->chgBit(oldp+306,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack));
    bufp->chgBit(oldp+307,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack));
    bufp->chgIData(oldp+308,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata),32);
    bufp->chgIData(oldp+309,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q),32);
    bufp->chgBit(oldp+310,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q));
    bufp->chgBit(oldp+311,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error));
    bufp->chgBit(oldp+312,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal));
    bufp->chgBit(oldp+313,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error));
    bufp->chgBit(oldp+314,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err));
    bufp->chgBit(oldp+315,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err));
    bufp->chgBit(oldp+316,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err));
    bufp->chgCData(oldp+317,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q),8);
    bufp->chgCData(oldp+318,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q),2);
    bufp->chgCData(oldp+319,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q),3);
    bufp->chgBit(oldp+320,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req));
    bufp->chgBit(oldp+321,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req));
    bufp->chgBit(oldp+322,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+323,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                     << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+324,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+325,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+326,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+327,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+328,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                               << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+329,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+330,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+331,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+332,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U])));
    bufp->chgBit(oldp+333,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i));
    bufp->chgBit(oldp+334,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni));
    bufp->chgBit(oldp+335,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+336,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+337,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+338,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+339,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+340,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+341,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+342,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+343,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+344,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+345,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+346,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+347,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U])));
    bufp->chgBit(oldp+348,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o));
    bufp->chgBit(oldp+349,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed));
    bufp->chgBit(oldp+350,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed));
    bufp->chgBit(oldp+351,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full));
    bufp->chgBit(oldp+352,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial));
    bufp->chgBit(oldp+353,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get));
    bufp->chgBit(oldp+354,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err));
    bufp->chgBit(oldp+355,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err));
    bufp->chgBit(oldp+356,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk));
    bufp->chgBit(oldp+357,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk));
    bufp->chgBit(oldp+358,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk));
    bufp->chgCData(oldp+359,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask),4);
    bufp->chgBit(oldp+360,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+361,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                     << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+362,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+363,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+364,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+365,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+366,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                               << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+367,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+368,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+369,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+370,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->chgBit(oldp+371,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+372,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+373,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+374,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+375,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+376,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+377,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+378,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+379,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+380,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+381,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->chgBit(oldp+382,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->chgBit(oldp+383,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->chgBit(oldp+384,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->chgBit(oldp+385,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+386,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+387,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+388,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+389,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+390,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+391,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+392,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->chgCData(oldp+393,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->chgBit(oldp+394,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->chgCData(oldp+395,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+396,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+397,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+398,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+399,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+400,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+401,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw)),4);
    bufp->chgCData(oldp+402,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+403,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+404,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+405,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg))),4);
    bufp->chgBit(oldp+406,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->chgBit(oldp+407,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->chgBit(oldp+408,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->chgCData(oldp+409,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr),4);
    bufp->chgIData(oldp+410,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->chgCData(oldp+411,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->chgIData(oldp+412,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->chgBit(oldp+413,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->chgBit(oldp+414,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->chgBit(oldp+415,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->chgIData(oldp+416,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+417,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->chgCData(oldp+418,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check),3);
    bufp->chgBit(oldp+419,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q));
    bufp->chgCData(oldp+420,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs),4);
    bufp->chgBit(oldp+421,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re));
    bufp->chgBit(oldp+422,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we));
    bufp->chgCData(oldp+423,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs),4);
    bufp->chgCData(oldp+424,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd),4);
    bufp->chgCData(oldp+425,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs),4);
    bufp->chgCData(oldp+426,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd),4);
    bufp->chgBit(oldp+427,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we));
    bufp->chgCData(oldp+428,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs),4);
    bufp->chgCData(oldp+429,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd),4);
    bufp->chgCData(oldp+430,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs),4);
    bufp->chgCData(oldp+431,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd),4);
    bufp->chgCData(oldp+432,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs),4);
    bufp->chgCData(oldp+433,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd),4);
    bufp->chgCData(oldp+434,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs),4);
    bufp->chgCData(oldp+435,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd),4);
    bufp->chgCData(oldp+436,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs),4);
    bufp->chgCData(oldp+437,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd),4);
    bufp->chgBit(oldp+438,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe));
    bufp->chgCData(oldp+439,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we),2);
    bufp->chgCData(oldp+440,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit),3);
    bufp->chgBit(oldp+441,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->chgBit(oldp+442,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->chgBit(oldp+443,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i));
    bufp->chgBit(oldp+444,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni));
    bufp->chgBit(oldp+445,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de));
    bufp->chgCData(oldp+446,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d),4);
    bufp->chgBit(oldp+447,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe));
    bufp->chgCData(oldp+448,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q),4);
    bufp->chgCData(oldp+449,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds),4);
    bufp->chgCData(oldp+450,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs),4);
    bufp->chgBit(oldp+451,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en));
    bufp->chgCData(oldp+452,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data),4);
    bufp->chgBit(oldp+453,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de));
    bufp->chgCData(oldp+454,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d),4);
    bufp->chgCData(oldp+455,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+456,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+457,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+458,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q),4);
    bufp->chgBit(oldp+459,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re));
    bufp->chgBit(oldp+460,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we));
    bufp->chgCData(oldp+461,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd),4);
    bufp->chgCData(oldp+462,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d),4);
    bufp->chgBit(oldp+463,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    bufp->chgBit(oldp+464,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre));
    bufp->chgCData(oldp+465,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q),4);
    bufp->chgCData(oldp+466,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds),4);
    bufp->chgCData(oldp+467,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs),4);
    bufp->chgBit(oldp+468,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re));
    bufp->chgBit(oldp+469,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we));
    bufp->chgCData(oldp+470,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd),4);
    bufp->chgCData(oldp+471,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d),4);
    bufp->chgBit(oldp+472,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe));
    bufp->chgBit(oldp+473,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre));
    bufp->chgCData(oldp+474,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q),4);
    bufp->chgCData(oldp+475,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds),4);
    bufp->chgCData(oldp+476,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs),4);
    bufp->chgBit(oldp+477,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i));
    bufp->chgBit(oldp+478,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni));
    bufp->chgBit(oldp+479,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we));
    bufp->chgCData(oldp+480,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd),4);
    bufp->chgBit(oldp+481,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe));
    bufp->chgCData(oldp+482,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q),4);
    bufp->chgCData(oldp+483,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds),4);
    bufp->chgCData(oldp+484,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs),4);
    bufp->chgBit(oldp+485,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en));
    bufp->chgCData(oldp+486,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data),4);
    bufp->chgBit(oldp+487,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+488,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+489,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+490,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+491,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+492,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+493,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i));
    bufp->chgBit(oldp+494,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni));
    bufp->chgBit(oldp+495,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we));
    bufp->chgCData(oldp+496,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd),4);
    bufp->chgBit(oldp+497,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe));
    bufp->chgCData(oldp+498,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q),4);
    bufp->chgCData(oldp+499,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds),4);
    bufp->chgCData(oldp+500,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs),4);
    bufp->chgBit(oldp+501,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en));
    bufp->chgCData(oldp+502,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data),4);
    bufp->chgBit(oldp+503,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+504,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+505,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+506,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+507,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+508,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+509,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i));
    bufp->chgBit(oldp+510,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni));
    bufp->chgBit(oldp+511,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we));
    bufp->chgCData(oldp+512,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd),4);
    bufp->chgBit(oldp+513,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe));
    bufp->chgCData(oldp+514,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q),4);
    bufp->chgCData(oldp+515,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds),4);
    bufp->chgCData(oldp+516,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs),4);
    bufp->chgBit(oldp+517,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en));
    bufp->chgCData(oldp+518,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data),4);
    bufp->chgBit(oldp+519,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+520,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+521,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+522,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+523,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+524,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+525,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i));
    bufp->chgBit(oldp+526,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni));
    bufp->chgBit(oldp+527,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we));
    bufp->chgCData(oldp+528,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd),4);
    bufp->chgBit(oldp+529,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe));
    bufp->chgCData(oldp+530,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q),4);
    bufp->chgCData(oldp+531,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds),4);
    bufp->chgCData(oldp+532,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs),4);
    bufp->chgBit(oldp+533,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en));
    bufp->chgCData(oldp+534,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data),4);
    bufp->chgBit(oldp+535,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+536,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+537,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+538,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+539,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+540,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+541,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i));
    bufp->chgBit(oldp+542,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni));
    bufp->chgBit(oldp+543,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we));
    bufp->chgCData(oldp+544,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd),4);
    bufp->chgBit(oldp+545,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe));
    bufp->chgCData(oldp+546,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q),4);
    bufp->chgCData(oldp+547,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds),4);
    bufp->chgCData(oldp+548,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs),4);
    bufp->chgBit(oldp+549,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en));
    bufp->chgCData(oldp+550,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data),4);
    bufp->chgBit(oldp+551,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+552,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+553,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+554,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+555,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+556,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+557,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->chgBit(oldp+558,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->chgCData(oldp+559,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),3);
    bufp->chgBit(oldp+560,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->chgBit(oldp+561,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->chgCData(oldp+562,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),3);
    bufp->chgCData(oldp+563,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),3);
    bufp->chgCData(oldp+564,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),3);
    bufp->chgCData(oldp+565,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),3);
    bufp->chgBit(oldp+566,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->chgBit(oldp+567,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->chgCData(oldp+568,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),3);
    bufp->chgBit(oldp+569,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->chgBit(oldp+570,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->chgCData(oldp+571,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),7);
    bufp->chgCData(oldp+572,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),7);
    bufp->chgCData(oldp+573,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),7);
    bufp->chgBit(oldp+574,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+575,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+576,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+577,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+578,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq));
    bufp->chgBit(oldp+579,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+580,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+581,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+582,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+583,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+584,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+585,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 586, vlSymsp->TOP__gpio_reg_pkg.GPIO_PERMIT);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[0]),4);
    bufp->chgCData(oldp+1,(__VdtypeVar[1]),4);
    bufp->chgCData(oldp+2,(__VdtypeVar[2]),4);
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
