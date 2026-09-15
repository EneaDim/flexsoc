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

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*7:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*79:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar);

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
    bufp->chgCData(oldp+6,((0x0000000fU & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                                   >> 0x00000033U)))),4);
    bufp->chgCData(oldp+7,((7U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                          >> 0x00000030U)))),3);
    bufp->chgBit(oldp+8,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                        >> 0x0000002fU)))));
    bufp->chgIData(oldp+9,((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                    >> 0x0000000fU))),32);
    bufp->chgCData(oldp+10,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                                    >> 0x0000000bU)))),4);
    bufp->chgBit(oldp+11,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                         >> 0x0000000aU)))));
    bufp->chgBit(oldp+12,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                         >> 9U)))));
    bufp->chgCData(oldp+13,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                                    >> 5U)))),4);
    bufp->chgCData(oldp+14,((7U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                           >> 2U)))),3);
    bufp->chgBit(oldp+15,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                         >> 1U)))));
    bufp->chgBit(oldp+16,((1U & (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_i))));
    bufp->chgBit(oldp+17,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+18,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                         >> 0x00000027U)))));
    bufp->chgCData(oldp+19,((3U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                           >> 0x00000025U)))),2);
    bufp->chgBit(oldp+20,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+21,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                         >> 0x00000023U)))));
    bufp->chgIData(oldp+22,((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                     >> 3U))),32);
    bufp->chgCData(oldp+23,((3U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                           >> 1U)))),2);
    bufp->chgBit(oldp+24,((1U & (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_o))));
    bufp->chgCData(oldp+25,(vlSelfRef.gpio_tb__DOT__axi_aw_addr_i),4);
    bufp->chgCData(oldp+26,(vlSelfRef.gpio_tb__DOT__axi_aw_prot_i),3);
    bufp->chgBit(oldp+27,(vlSelfRef.gpio_tb__DOT__axi_aw_valid_i));
    bufp->chgBit(oldp+28,(vlSelfRef.gpio_tb__DOT__axi_aw_ready_o));
    bufp->chgIData(oldp+29,(vlSelfRef.gpio_tb__DOT__axi_w_data_i),32);
    bufp->chgCData(oldp+30,(vlSelfRef.gpio_tb__DOT__axi_w_strb_i),4);
    bufp->chgBit(oldp+31,(vlSelfRef.gpio_tb__DOT__axi_w_valid_i));
    bufp->chgBit(oldp+32,(vlSelfRef.gpio_tb__DOT__axi_w_ready_o));
    bufp->chgCData(oldp+33,(vlSelfRef.gpio_tb__DOT__axi_b_resp_o),2);
    bufp->chgBit(oldp+34,(vlSelfRef.gpio_tb__DOT__axi_b_valid_o));
    bufp->chgBit(oldp+35,(vlSelfRef.gpio_tb__DOT__axi_b_ready_i));
    bufp->chgCData(oldp+36,(vlSelfRef.gpio_tb__DOT__axi_ar_addr_i),4);
    bufp->chgCData(oldp+37,(vlSelfRef.gpio_tb__DOT__axi_ar_prot_i),3);
    bufp->chgBit(oldp+38,(vlSelfRef.gpio_tb__DOT__axi_ar_valid_i));
    bufp->chgBit(oldp+39,(vlSelfRef.gpio_tb__DOT__axi_ar_ready_o));
    bufp->chgIData(oldp+40,(vlSelfRef.gpio_tb__DOT__axi_r_data_o),32);
    bufp->chgCData(oldp+41,(vlSelfRef.gpio_tb__DOT__axi_r_resp_o),2);
    bufp->chgBit(oldp+42,(vlSelfRef.gpio_tb__DOT__axi_r_valid_o));
    bufp->chgBit(oldp+43,(vlSelfRef.gpio_tb__DOT__axi_r_ready_i));
    bufp->chgBit(oldp+44,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i));
    bufp->chgBit(oldp+45,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni));
    bufp->chgCData(oldp+46,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+47,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+48,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+49,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o),4);
    bufp->chgCData(oldp+50,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                                    >> 0x00000033U)))),4);
    bufp->chgCData(oldp+51,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                           >> 0x00000030U)))),3);
    bufp->chgBit(oldp+52,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                         >> 0x0000002fU)))));
    bufp->chgIData(oldp+53,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                     >> 0x0000000fU))),32);
    bufp->chgCData(oldp+54,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                                    >> 0x0000000bU)))),4);
    bufp->chgBit(oldp+55,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                         >> 0x0000000aU)))));
    bufp->chgBit(oldp+56,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                         >> 9U)))));
    bufp->chgCData(oldp+57,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                                    >> 5U)))),4);
    bufp->chgCData(oldp+58,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                           >> 2U)))),3);
    bufp->chgBit(oldp+59,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                         >> 1U)))));
    bufp->chgBit(oldp+60,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i))));
    bufp->chgBit(oldp+61,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+62,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                         >> 0x00000027U)))));
    bufp->chgCData(oldp+63,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                           >> 0x00000025U)))),2);
    bufp->chgBit(oldp+64,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+65,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                         >> 0x00000023U)))));
    bufp->chgIData(oldp+66,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                     >> 3U))),32);
    bufp->chgCData(oldp+67,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                           >> 1U)))),2);
    bufp->chgBit(oldp+68,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o))));
    bufp->chgCData(oldp+69,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x0000001aU))),4);
    bufp->chgBit(oldp+70,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                 >> 0x00000019U))));
    bufp->chgCData(oldp+71,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x00000015U))),4);
    bufp->chgBit(oldp+72,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                 >> 0x00000014U))));
    bufp->chgCData(oldp+73,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x00000010U))),4);
    bufp->chgCData(oldp+74,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x0000000cU))),4);
    bufp->chgCData(oldp+75,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 8U))),4);
    bufp->chgCData(oldp+76,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 4U))),4);
    bufp->chgCData(oldp+77,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw)),4);
    bufp->chgCData(oldp+78,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                            >> 9U))),4);
    bufp->chgBit(oldp+79,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                 >> 8U))));
    bufp->chgCData(oldp+80,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                            >> 4U))),4);
    bufp->chgCData(oldp+81,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg))),4);
    bufp->chgBit(oldp+82,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni));
    bufp->chgBit(oldp+83,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni));
    bufp->chgBit(oldp+84,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+85,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+86,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+87,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+88,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq));
    bufp->chgBit(oldp+89,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+90,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+91,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+92,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+93,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+94,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+95,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+96,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i));
    bufp->chgBit(oldp+97,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni));
    bufp->chgCData(oldp+98,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x0000001aU))),4);
    bufp->chgBit(oldp+99,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                 >> 0x00000019U))));
    bufp->chgCData(oldp+100,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+101,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+102,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+103,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+104,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+105,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+106,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)),4);
    bufp->chgCData(oldp+107,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+108,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+109,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+110,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg))),4);
    bufp->chgCData(oldp+111,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+112,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+113,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+114,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o),4);
    bufp->chgCData(oldp+115,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d),4);
    bufp->chgCData(oldp+116,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q),4);
    bufp->chgCData(oldp+117,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q),4);
    bufp->chgCData(oldp+118,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q),4);
    bufp->chgCData(oldp+119,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise),4);
    bufp->chgCData(oldp+120,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall),4);
    bufp->chgCData(oldp+121,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high),4);
    bufp->chgCData(oldp+122,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low),4);
    bufp->chgBit(oldp+123,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni));
    bufp->chgBit(oldp+124,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni));
    bufp->chgBit(oldp+125,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+126,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+127,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+128,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+129,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+130,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+131,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+132,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+133,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+134,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+135,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+136,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+137,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+138,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+139,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+140,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+141,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+142,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+143,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+144,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+145,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+146,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+147,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+148,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+149,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+150,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+151,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+152,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+153,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+154,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+155,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+156,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+157,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+158,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+159,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+160,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+161,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+162,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+163,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+164,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+165,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+166,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+167,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+168,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+169,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+170,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+171,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+172,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+173,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+174,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+175,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+176,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+177,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+178,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+179,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+180,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+181,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+182,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+183,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+184,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+185,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+186,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+187,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+188,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+189,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+190,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+191,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+192,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+193,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+194,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+195,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+196,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+197,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+198,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+199,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+200,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+201,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+202,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+203,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+204,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+205,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+206,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+207,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+208,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+209,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+210,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+211,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+212,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+213,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+214,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+215,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+216,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+217,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+218,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+219,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+220,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+221,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+222,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+223,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+224,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+225,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+226,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+227,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+228,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+229,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+230,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+231,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i));
    bufp->chgBit(oldp+232,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni));
    bufp->chgCData(oldp+233,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                                     >> 0x00000033U)))),4);
    bufp->chgCData(oldp+234,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                            >> 0x00000030U)))),3);
    bufp->chgBit(oldp+235,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                          >> 0x0000002fU)))));
    bufp->chgIData(oldp+236,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                      >> 0x0000000fU))),32);
    bufp->chgCData(oldp+237,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                                     >> 0x0000000bU)))),4);
    bufp->chgBit(oldp+238,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                          >> 0x0000000aU)))));
    bufp->chgBit(oldp+239,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                          >> 9U)))));
    bufp->chgCData(oldp+240,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                                     >> 5U)))),4);
    bufp->chgCData(oldp+241,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                            >> 2U)))),3);
    bufp->chgBit(oldp+242,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                          >> 1U)))));
    bufp->chgBit(oldp+243,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i))));
    bufp->chgBit(oldp+244,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+245,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                          >> 0x00000027U)))));
    bufp->chgCData(oldp+246,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                            >> 0x00000025U)))),2);
    bufp->chgBit(oldp+247,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+248,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                          >> 0x00000023U)))));
    bufp->chgIData(oldp+249,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                      >> 3U))),32);
    bufp->chgCData(oldp+250,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                            >> 1U)))),2);
    bufp->chgBit(oldp+251,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o))));
    bufp->chgCData(oldp+252,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->chgBit(oldp+253,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->chgCData(oldp+254,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+255,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+256,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+257,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+258,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+259,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+260,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw)),4);
    bufp->chgCData(oldp+261,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+262,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+263,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+264,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg))),4);
    bufp->chgBit(oldp+265,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+266,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+267,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+268,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                      >> 4U))),32);
    bufp->chgCData(oldp+269,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req))),4);
    bufp->chgIData(oldp+270,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                      >> 2U))),32);
    bufp->chgBit(oldp+271,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                          >> 1U)))));
    bufp->chgBit(oldp+272,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp))));
    bufp->chgBit(oldp+273,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__clk_i));
    bufp->chgBit(oldp+274,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni));
    bufp->chgCData(oldp+275,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                     >> 0x00000033U)))),4);
    bufp->chgCData(oldp+276,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                            >> 0x00000030U)))),3);
    bufp->chgBit(oldp+277,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 0x0000002fU)))));
    bufp->chgIData(oldp+278,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                      >> 0x0000000fU))),32);
    bufp->chgCData(oldp+279,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                     >> 0x0000000bU)))),4);
    bufp->chgBit(oldp+280,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 0x0000000aU)))));
    bufp->chgBit(oldp+281,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 9U)))));
    bufp->chgCData(oldp+282,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                     >> 5U)))),4);
    bufp->chgCData(oldp+283,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                            >> 2U)))),3);
    bufp->chgBit(oldp+284,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 1U)))));
    bufp->chgBit(oldp+285,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i))));
    bufp->chgBit(oldp+286,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+287,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000027U)))));
    bufp->chgCData(oldp+288,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                            >> 0x00000025U)))),2);
    bufp->chgBit(oldp+289,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+290,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000023U)))));
    bufp->chgIData(oldp+291,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                      >> 3U))),32);
    bufp->chgCData(oldp+292,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                            >> 1U)))),2);
    bufp->chgBit(oldp+293,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o))));
    bufp->chgBit(oldp+294,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+295,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+296,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+297,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                      >> 4U))),32);
    bufp->chgCData(oldp+298,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o))),4);
    bufp->chgIData(oldp+299,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                      >> 2U))),32);
    bufp->chgBit(oldp+300,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                          >> 1U)))));
    bufp->chgBit(oldp+301,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i))));
    bufp->chgBit(oldp+302,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full));
    bufp->chgBit(oldp+303,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty));
    bufp->chgCData(oldp+304,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+305,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                      >> 4U))),32);
    bufp->chgCData(oldp+306,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in))),4);
    bufp->chgCData(oldp+307,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+308,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                      >> 4U))),32);
    bufp->chgCData(oldp+309,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out))),4);
    bufp->chgBit(oldp+310,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push));
    bufp->chgBit(oldp+311,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop));
    bufp->chgBit(oldp+312,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full));
    bufp->chgBit(oldp+313,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty));
    bufp->chgBit(oldp+314,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in));
    bufp->chgBit(oldp+315,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out));
    bufp->chgBit(oldp+316,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push));
    bufp->chgBit(oldp+317,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop));
    bufp->chgBit(oldp+318,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full));
    bufp->chgBit(oldp+319,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty));
    bufp->chgCData(oldp+320,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_in),4);
    bufp->chgCData(oldp+321,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out),4);
    bufp->chgBit(oldp+322,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push));
    bufp->chgBit(oldp+323,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop));
    bufp->chgBit(oldp+324,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full));
    bufp->chgBit(oldp+325,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty));
    bufp->chgIData(oldp+326,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                                      >> 1U))),32);
    bufp->chgBit(oldp+327,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in))));
    bufp->chgIData(oldp+328,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                      >> 1U))),32);
    bufp->chgBit(oldp+329,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out))));
    bufp->chgBit(oldp+330,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push));
    bufp->chgBit(oldp+331,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop));
    bufp->chgCData(oldp+332,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+333,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req))));
    bufp->chgCData(oldp+334,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+335,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req))));
    bufp->chgCData(oldp+336,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+337,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req))));
    bufp->chgBit(oldp+338,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid));
    bufp->chgBit(oldp+339,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid));
    bufp->chgBit(oldp+340,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready));
    bufp->chgBit(oldp+341,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready));
    bufp->chgBit(oldp+342,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__clk_i));
    bufp->chgBit(oldp+343,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni));
    bufp->chgBit(oldp+344,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o));
    bufp->chgBit(oldp+345,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o));
    bufp->chgBit(oldp+346,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o));
    bufp->chgCData(oldp+347,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_i),4);
    bufp->chgBit(oldp+348,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i));
    bufp->chgCData(oldp+349,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o),4);
    bufp->chgBit(oldp+350,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i));
    bufp->chgBit(oldp+351,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock));
    bufp->chgBit(oldp+352,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n));
    bufp->chgBit(oldp+353,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q));
    bufp->chgBit(oldp+354,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n));
    bufp->chgBit(oldp+355,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q));
    bufp->chgCData(oldp+356,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+357,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q),2);
    bufp->chgCData(oldp+358,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+359,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n))),4);
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 360, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q);
    bufp->chgBit(oldp+362,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__clk_i));
    bufp->chgBit(oldp+363,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni));
    bufp->chgBit(oldp+364,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o));
    bufp->chgBit(oldp+365,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o));
    bufp->chgBit(oldp+366,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o));
    bufp->chgIData(oldp+367,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                                      >> 1U))),32);
    bufp->chgBit(oldp+368,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i))));
    bufp->chgBit(oldp+369,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i));
    bufp->chgIData(oldp+370,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                                      >> 1U))),32);
    bufp->chgBit(oldp+371,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o))));
    bufp->chgBit(oldp+372,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i));
    bufp->chgBit(oldp+373,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock));
    bufp->chgBit(oldp+374,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n));
    bufp->chgBit(oldp+375,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q));
    bufp->chgBit(oldp+376,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n));
    bufp->chgBit(oldp+377,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q));
    bufp->chgCData(oldp+378,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+379,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q),2);
    bufp->chgIData(oldp+380,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
                               << 0x0000001eU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                                  >> 2U))),32);
    bufp->chgBit(oldp+381,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                  >> 1U))));
    bufp->chgIData(oldp+382,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                               << 0x0000001fU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
                                                  >> 1U))),32);
    bufp->chgBit(oldp+383,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U])));
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 384, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q);
    bufp->chgBit(oldp+388,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__clk_i));
    bufp->chgBit(oldp+389,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni));
    bufp->chgBit(oldp+390,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o));
    bufp->chgBit(oldp+391,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o));
    bufp->chgBit(oldp+392,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o));
    bufp->chgCData(oldp+393,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+394,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+395,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i))),4);
    bufp->chgBit(oldp+396,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i));
    bufp->chgCData(oldp+397,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+398,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                      >> 4U))),32);
    bufp->chgCData(oldp+399,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o))),4);
    bufp->chgBit(oldp+400,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i));
    bufp->chgBit(oldp+401,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock));
    bufp->chgBit(oldp+402,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n));
    bufp->chgBit(oldp+403,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q));
    bufp->chgBit(oldp+404,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n));
    bufp->chgBit(oldp+405,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q));
    bufp->chgCData(oldp+406,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+407,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q),2);
    bufp->chgCData(oldp+408,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                             >> 0x0000000cU))),4);
    bufp->chgIData(oldp+409,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                               << 0x00000014U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                                  >> 0x0000000cU))),32);
    bufp->chgCData(oldp+410,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                             >> 8U))),4);
    bufp->chgCData(oldp+411,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                             >> 4U))),4);
    bufp->chgIData(oldp+412,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                               << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                                                  >> 4U))),32);
    bufp->chgCData(oldp+413,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U])),4);
    Vtop___024root__trace_chg_dtype____2(vlSelf, bufp, 414, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q);
    bufp->chgBit(oldp+420,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__clk_i));
    bufp->chgBit(oldp+421,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni));
    bufp->chgBit(oldp+422,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o));
    bufp->chgBit(oldp+423,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o));
    bufp->chgBit(oldp+424,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o));
    bufp->chgBit(oldp+425,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i));
    bufp->chgBit(oldp+426,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i));
    bufp->chgBit(oldp+427,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o));
    bufp->chgBit(oldp+428,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i));
    bufp->chgBit(oldp+429,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock));
    bufp->chgBit(oldp+430,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n));
    bufp->chgBit(oldp+431,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q));
    bufp->chgBit(oldp+432,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n));
    bufp->chgBit(oldp+433,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q));
    bufp->chgCData(oldp+434,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+435,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q),2);
    bufp->chgCData(oldp+436,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n),2);
    bufp->chgCData(oldp+437,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q),2);
    bufp->chgBit(oldp+438,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__clk_i));
    bufp->chgBit(oldp+439,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni));
    bufp->chgCData(oldp+440,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                             >> 6U))),4);
    bufp->chgBit(oldp+441,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                  >> 5U))));
    bufp->chgCData(oldp+442,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+443,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i))));
    bufp->chgCData(oldp+444,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i),2);
    bufp->chgCData(oldp+445,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o),2);
    bufp->chgCData(oldp+446,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+447,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o))));
    bufp->chgBit(oldp+448,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o));
    bufp->chgBit(oldp+449,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i));
    bufp->chgBit(oldp+450,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__clk_i));
    bufp->chgBit(oldp+451,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni));
    bufp->chgCData(oldp+452,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                             >> 6U))),4);
    bufp->chgBit(oldp+453,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                  >> 5U))));
    bufp->chgCData(oldp+454,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+455,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i))));
    bufp->chgCData(oldp+456,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i),2);
    bufp->chgCData(oldp+457,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o),2);
    bufp->chgCData(oldp+458,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+459,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o))));
    bufp->chgBit(oldp+460,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o));
    bufp->chgBit(oldp+461,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i));
    bufp->chgBit(oldp+462,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__clk_i));
    bufp->chgBit(oldp+463,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni));
    bufp->chgCData(oldp+464,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i),2);
    bufp->chgCData(oldp+465,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o),2);
    bufp->chgCData(oldp+466,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                             >> 6U))),4);
    bufp->chgBit(oldp+467,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                  >> 5U))));
    bufp->chgCData(oldp+468,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+469,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i))));
    bufp->chgBit(oldp+470,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o));
    bufp->chgBit(oldp+471,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i));
    bufp->chgCData(oldp+472,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+473,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o))));
    bufp->chgBit(oldp+474,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o));
    bufp->chgBit(oldp+475,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes));
    bufp->chgCData(oldp+476,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
                                             >> 1U))),4);
    bufp->chgBit(oldp+477,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes))));
    bufp->chgBit(oldp+478,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes));
    bufp->chgBit(oldp+479,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes));
    bufp->chgBit(oldp+480,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q));
    bufp->chgCData(oldp+481,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d),2);
    bufp->chgBit(oldp+482,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d));
    bufp->chgCData(oldp+483,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),2);
    bufp->chgCData(oldp+484,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),2);
    bufp->chgBit(oldp+485,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx));
    bufp->chgBit(oldp+486,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx));
    bufp->chgBit(oldp+487,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx));
    bufp->chgBit(oldp+488,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty));
    bufp->chgBit(oldp+489,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_empty));
    bufp->chgCData(oldp+490,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i),2);
    bufp->chgBit(oldp+491,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o));
    bufp->chgBit(oldp+492,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o));
    Vtop___024root__trace_chg_dtype____3(vlSelf, bufp, 493, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_lut);
    bufp->chgCData(oldp+495,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->chgBit(oldp+496,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
                                  >> 1U))));
    bufp->chgBit(oldp+497,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))));
    bufp->chgCData(oldp+498,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->chgCData(oldp+499,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i),2);
    bufp->chgBit(oldp+500,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o));
    bufp->chgBit(oldp+501,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o));
    Vtop___024root__trace_chg_dtype____3(vlSelf, bufp, 502, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_lut);
    bufp->chgCData(oldp+504,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->chgBit(oldp+505,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
                                  >> 1U))));
    bufp->chgBit(oldp+506,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes))));
    bufp->chgCData(oldp+507,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->chgBit(oldp+508,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d));
    bufp->chgBit(oldp+509,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
    bufp->chgCData(oldp+510,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),2);
    bufp->chgBit(oldp+511,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
    bufp->chgBit(oldp+512,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->chgBit(oldp+513,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->chgBit(oldp+514,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+515,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+516,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+517,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+518,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+519,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+520,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+521,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->chgCData(oldp+522,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->chgBit(oldp+523,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->chgCData(oldp+524,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+525,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+526,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+527,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+528,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+529,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+530,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw)),4);
    bufp->chgCData(oldp+531,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+532,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+533,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+534,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg))),4);
    bufp->chgBit(oldp+535,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->chgBit(oldp+536,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->chgBit(oldp+537,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->chgCData(oldp+538,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr),4);
    bufp->chgIData(oldp+539,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->chgCData(oldp+540,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->chgIData(oldp+541,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->chgBit(oldp+542,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->chgBit(oldp+543,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->chgBit(oldp+544,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->chgIData(oldp+545,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+546,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->chgCData(oldp+547,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check),3);
    bufp->chgBit(oldp+548,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q));
    bufp->chgCData(oldp+549,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs),4);
    bufp->chgBit(oldp+550,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re));
    bufp->chgBit(oldp+551,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we));
    bufp->chgCData(oldp+552,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs),4);
    bufp->chgCData(oldp+553,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd),4);
    bufp->chgCData(oldp+554,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs),4);
    bufp->chgCData(oldp+555,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd),4);
    bufp->chgBit(oldp+556,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we));
    bufp->chgCData(oldp+557,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs),4);
    bufp->chgCData(oldp+558,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd),4);
    bufp->chgCData(oldp+559,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs),4);
    bufp->chgCData(oldp+560,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd),4);
    bufp->chgCData(oldp+561,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs),4);
    bufp->chgCData(oldp+562,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd),4);
    bufp->chgCData(oldp+563,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs),4);
    bufp->chgCData(oldp+564,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd),4);
    bufp->chgCData(oldp+565,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs),4);
    bufp->chgCData(oldp+566,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd),4);
    bufp->chgBit(oldp+567,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe));
    bufp->chgCData(oldp+568,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we),2);
    bufp->chgCData(oldp+569,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit),3);
    bufp->chgBit(oldp+570,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->chgBit(oldp+571,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->chgBit(oldp+572,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i));
    bufp->chgBit(oldp+573,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni));
    bufp->chgBit(oldp+574,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de));
    bufp->chgCData(oldp+575,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d),4);
    bufp->chgBit(oldp+576,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe));
    bufp->chgCData(oldp+577,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q),4);
    bufp->chgCData(oldp+578,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds),4);
    bufp->chgCData(oldp+579,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs),4);
    bufp->chgBit(oldp+580,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en));
    bufp->chgCData(oldp+581,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data),4);
    bufp->chgBit(oldp+582,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de));
    bufp->chgCData(oldp+583,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d),4);
    bufp->chgCData(oldp+584,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+585,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+586,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+587,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q),4);
    bufp->chgBit(oldp+588,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re));
    bufp->chgBit(oldp+589,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we));
    bufp->chgCData(oldp+590,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd),4);
    bufp->chgCData(oldp+591,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d),4);
    bufp->chgBit(oldp+592,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    bufp->chgBit(oldp+593,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre));
    bufp->chgCData(oldp+594,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q),4);
    bufp->chgCData(oldp+595,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds),4);
    bufp->chgCData(oldp+596,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs),4);
    bufp->chgBit(oldp+597,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re));
    bufp->chgBit(oldp+598,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we));
    bufp->chgCData(oldp+599,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd),4);
    bufp->chgCData(oldp+600,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d),4);
    bufp->chgBit(oldp+601,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe));
    bufp->chgBit(oldp+602,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre));
    bufp->chgCData(oldp+603,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q),4);
    bufp->chgCData(oldp+604,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds),4);
    bufp->chgCData(oldp+605,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs),4);
    bufp->chgBit(oldp+606,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i));
    bufp->chgBit(oldp+607,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni));
    bufp->chgBit(oldp+608,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we));
    bufp->chgCData(oldp+609,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd),4);
    bufp->chgBit(oldp+610,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe));
    bufp->chgCData(oldp+611,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q),4);
    bufp->chgCData(oldp+612,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds),4);
    bufp->chgCData(oldp+613,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs),4);
    bufp->chgBit(oldp+614,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en));
    bufp->chgCData(oldp+615,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data),4);
    bufp->chgBit(oldp+616,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+617,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+618,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+619,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+620,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+621,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+622,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i));
    bufp->chgBit(oldp+623,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni));
    bufp->chgBit(oldp+624,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we));
    bufp->chgCData(oldp+625,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd),4);
    bufp->chgBit(oldp+626,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe));
    bufp->chgCData(oldp+627,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q),4);
    bufp->chgCData(oldp+628,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds),4);
    bufp->chgCData(oldp+629,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs),4);
    bufp->chgBit(oldp+630,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en));
    bufp->chgCData(oldp+631,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data),4);
    bufp->chgBit(oldp+632,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+633,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+634,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+635,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+636,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+637,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+638,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i));
    bufp->chgBit(oldp+639,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni));
    bufp->chgBit(oldp+640,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we));
    bufp->chgCData(oldp+641,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd),4);
    bufp->chgBit(oldp+642,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe));
    bufp->chgCData(oldp+643,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q),4);
    bufp->chgCData(oldp+644,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds),4);
    bufp->chgCData(oldp+645,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs),4);
    bufp->chgBit(oldp+646,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en));
    bufp->chgCData(oldp+647,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data),4);
    bufp->chgBit(oldp+648,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+649,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+650,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+651,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+652,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+653,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+654,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i));
    bufp->chgBit(oldp+655,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni));
    bufp->chgBit(oldp+656,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we));
    bufp->chgCData(oldp+657,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd),4);
    bufp->chgBit(oldp+658,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe));
    bufp->chgCData(oldp+659,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q),4);
    bufp->chgCData(oldp+660,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds),4);
    bufp->chgCData(oldp+661,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs),4);
    bufp->chgBit(oldp+662,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en));
    bufp->chgCData(oldp+663,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data),4);
    bufp->chgBit(oldp+664,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+665,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+666,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+667,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+668,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+669,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+670,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i));
    bufp->chgBit(oldp+671,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni));
    bufp->chgBit(oldp+672,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we));
    bufp->chgCData(oldp+673,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd),4);
    bufp->chgBit(oldp+674,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe));
    bufp->chgCData(oldp+675,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q),4);
    bufp->chgCData(oldp+676,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds),4);
    bufp->chgCData(oldp+677,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs),4);
    bufp->chgBit(oldp+678,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en));
    bufp->chgCData(oldp+679,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data),4);
    bufp->chgBit(oldp+680,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+681,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+682,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+683,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+684,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+685,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+686,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->chgBit(oldp+687,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->chgCData(oldp+688,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),3);
    bufp->chgBit(oldp+689,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->chgBit(oldp+690,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->chgCData(oldp+691,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),3);
    bufp->chgCData(oldp+692,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),3);
    bufp->chgCData(oldp+693,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),3);
    bufp->chgCData(oldp+694,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),3);
    bufp->chgBit(oldp+695,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->chgBit(oldp+696,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->chgCData(oldp+697,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),3);
    bufp->chgBit(oldp+698,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->chgBit(oldp+699,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->chgCData(oldp+700,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),7);
    bufp->chgCData(oldp+701,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),7);
    bufp->chgCData(oldp+702,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),7);
    bufp->chgBit(oldp+703,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+704,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+705,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+706,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+707,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq));
    bufp->chgBit(oldp+708,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+709,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+710,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+711,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+712,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+713,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+714,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    Vtop___024root__trace_chg_dtype____4(vlSelf, bufp, 715, vlSymsp->TOP__gpio_reg_pkg.GPIO_PERMIT);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*7:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,((0x0000000fU & (__VdtypeVar 
                                           >> 4U))),4);
    bufp->chgCData(oldp+1,((0x0000000fU & __VdtypeVar)),4);
}

void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(VL_SEL_IWII(66, __VdtypeVar, 0x00000022U, 32)),32);
    bufp->chgBit(oldp+1,((1U & VL_BITSEL_IWII(66, __VdtypeVar, 0x00000021U))));
    bufp->chgIData(oldp+2,(VL_SEL_IWII(66, __VdtypeVar, 1U, 32)),32);
    bufp->chgBit(oldp+3,((1U & VL_BITSEL_IWII(66, __VdtypeVar, 0U))));
}

void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*79:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,((0x0000000fU & VL_SEL_IWII(80, 
                                                      __VdtypeVar, 0x0000004cU, 4))),4);
    bufp->chgIData(oldp+1,(VL_SEL_IWII(80, __VdtypeVar, 0x0000002cU, 32)),32);
    bufp->chgCData(oldp+2,((0x0000000fU & VL_SEL_IWII(80, 
                                                      __VdtypeVar, 0x00000028U, 4))),4);
    bufp->chgCData(oldp+3,((0x0000000fU & VL_SEL_IWII(80, 
                                                      __VdtypeVar, 0x00000024U, 4))),4);
    bufp->chgIData(oldp+4,(VL_SEL_IWII(80, __VdtypeVar, 4U, 32)),32);
    bufp->chgCData(oldp+5,((0x0000000fU & VL_SEL_IWII(80, 
                                                      __VdtypeVar, 0U, 4))),4);
}

void Vtop___024root__trace_chg_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,((1U & (__VdtypeVar >> 1U))));
    bufp->chgBit(oldp+1,((1U & __VdtypeVar)));
}

void Vtop___024root__trace_chg_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____4\n"); );
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
