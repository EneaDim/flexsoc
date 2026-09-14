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

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<4>/*127:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const QData/*63:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 6>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.uart_tb__DOT__clk_i));
    bufp->chgBit(oldp+1,(vlSelfRef.uart_tb__DOT__rst_ni));
    bufp->chgBit(oldp+2,(vlSelfRef.uart_tb__DOT__rx_i));
    bufp->chgBit(oldp+3,(vlSelfRef.uart_tb__DOT__tx_o));
    bufp->chgBit(oldp+4,(vlSelfRef.uart_tb__DOT__tl_i_a_valid));
    bufp->chgCData(oldp+5,(vlSelfRef.uart_tb__DOT__tl_i_a_opcode),3);
    bufp->chgCData(oldp+6,(vlSelfRef.uart_tb__DOT__tl_i_a_param),3);
    bufp->chgCData(oldp+7,(vlSelfRef.uart_tb__DOT__tl_i_a_size),2);
    bufp->chgCData(oldp+8,(vlSelfRef.uart_tb__DOT__tl_i_a_source),8);
    bufp->chgIData(oldp+9,(vlSelfRef.uart_tb__DOT__tl_i_a_address),32);
    bufp->chgCData(oldp+10,(vlSelfRef.uart_tb__DOT__tl_i_a_mask),4);
    bufp->chgIData(oldp+11,(vlSelfRef.uart_tb__DOT__tl_i_a_data),32);
    bufp->chgBit(oldp+12,(vlSelfRef.uart_tb__DOT__tl_i_d_ready));
    bufp->chgBit(oldp+13,(vlSelfRef.uart_tb__DOT__tl_o_d_valid));
    bufp->chgCData(oldp+14,(vlSelfRef.uart_tb__DOT__tl_o_d_opcode),3);
    bufp->chgIData(oldp+15,(vlSelfRef.uart_tb__DOT__tl_o_d_data),32);
    bufp->chgBit(oldp+16,(vlSelfRef.uart_tb__DOT__tl_o_d_error));
    bufp->chgBit(oldp+17,(vlSelfRef.uart_tb__DOT__tl_o_a_ready));
    bufp->chgWData(oldp+18,(vlSelfRef.uart_tb__DOT__tl_i),109);
    bufp->chgWData(oldp+22,(vlSelfRef.uart_tb__DOT__tl_o),66);
    bufp->chgBit(oldp+25,(vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i));
    bufp->chgBit(oldp+26,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni));
    bufp->chgBit(oldp+27,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i));
    bufp->chgBit(oldp+28,(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o));
    bufp->chgBit(oldp+29,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                 >> 0x0000000cU))));
    bufp->chgCData(oldp+30,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                   >> 9U))),3);
    bufp->chgCData(oldp+31,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                   >> 6U))),3);
    bufp->chgCData(oldp+32,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                   >> 4U))),2);
    bufp->chgCData(oldp+33,((0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+34,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[2U] 
                              << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                        >> 0x0000001cU))),32);
    bufp->chgCData(oldp+35,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgIData(oldp+36,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[1U] 
                              << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+37,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                            >> 0x00000013U))),5);
    bufp->chgCData(oldp+38,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                            >> 0x0000000fU))),4);
    bufp->chgCData(oldp+39,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                            >> 8U))),7);
    bufp->chgCData(oldp+40,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U] 
                                            >> 1U))),7);
    bufp->chgBit(oldp+41,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_i[0U])));
    bufp->chgBit(oldp+42,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] 
                                 >> 1U))));
    bufp->chgCData(oldp+43,((7U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[2U] 
                                    << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                              >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+44,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                   >> 0x0000001bU))),3);
    bufp->chgCData(oldp+45,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                   >> 0x00000019U))),2);
    bufp->chgCData(oldp+46,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                            >> 0x00000011U))),8);
    bufp->chgBit(oldp+47,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                                 >> 0x00000010U))));
    bufp->chgIData(oldp+48,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[1U] 
                              << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                                 >> 0x00000010U))),32);
    bufp->chgCData(oldp+49,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                            >> 9U))),7);
    bufp->chgCData(oldp+50,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                            >> 2U))),7);
    bufp->chgBit(oldp+51,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U] 
                                 >> 1U))));
    bufp->chgBit(oldp+52,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__tl_o[0U])));
    bufp->chgSData(oldp+53,((0x0000ffffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 0x00000029U)))),16);
    bufp->chgBit(oldp+54,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+55,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000027U)))));
    bufp->chgBit(oldp+56,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000026U)))));
    bufp->chgBit(oldp+57,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000025U)))));
    bufp->chgBit(oldp+58,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+59,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000023U)))));
    bufp->chgBit(oldp+60,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000022U)))));
    bufp->chgBit(oldp+61,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000021U)))));
    bufp->chgBit(oldp+62,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000020U)))));
    bufp->chgBit(oldp+63,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001fU)))));
    bufp->chgBit(oldp+64,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001eU)))));
    bufp->chgBit(oldp+65,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001dU)))));
    bufp->chgBit(oldp+66,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001cU)))));
    bufp->chgBit(oldp+67,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001bU)))));
    bufp->chgBit(oldp+68,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001aU)))));
    bufp->chgBit(oldp+69,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000019U)))));
    bufp->chgBit(oldp+70,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000018U)))));
    bufp->chgBit(oldp+71,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000017U)))));
    bufp->chgBit(oldp+72,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000016U)))));
    bufp->chgCData(oldp+73,((0x000000ffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+74,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000000dU)))));
    bufp->chgCData(oldp+75,((0x000000ffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 5U)))),8);
    bufp->chgBit(oldp+76,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 4U)))));
    bufp->chgBit(oldp+77,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 3U)))));
    bufp->chgBit(oldp+78,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 2U)))));
    bufp->chgBit(oldp+79,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 1U)))));
    bufp->chgBit(oldp+80,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw))));
    bufp->chgBit(oldp+81,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001dU))));
    bufp->chgBit(oldp+82,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001cU))));
    bufp->chgBit(oldp+83,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001bU))));
    bufp->chgBit(oldp+84,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001aU))));
    bufp->chgBit(oldp+85,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x00000019U))));
    bufp->chgBit(oldp+86,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x00000018U))));
    bufp->chgCData(oldp+87,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                            >> 0x00000010U))),8);
    bufp->chgCData(oldp+88,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                            >> 8U))),8);
    bufp->chgCData(oldp+89,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg)),8);
    bufp->chgBit(oldp+90,(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni));
    bufp->chgBit(oldp+91,(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni));
    bufp->chgBit(oldp+92,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+93,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+94,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+95,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+96,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq));
    bufp->chgBit(oldp+97,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+98,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+99,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+100,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+101,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+102,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+103,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+104,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+105,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+106,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+107,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+108,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq));
    bufp->chgBit(oldp+109,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+110,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+111,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+112,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+113,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+114,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+115,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+116,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i));
    bufp->chgBit(oldp+117,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni));
    bufp->chgSData(oldp+118,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+119,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+120,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+121,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+122,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+123,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+124,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+125,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+126,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+127,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+128,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+129,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+130,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+131,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+132,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+133,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+134,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+135,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+136,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+137,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+138,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+139,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+140,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+141,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+142,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+143,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+144,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+145,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw))));
    bufp->chgBit(oldp+146,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+147,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+148,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+149,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+150,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+151,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+152,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+153,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+154,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg)),8);
    bufp->chgBit(oldp+155,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i));
    bufp->chgBit(oldp+156,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o));
    bufp->chgSData(oldp+157,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q),16);
    bufp->chgCData(oldp+158,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata),8);
    bufp->chgBit(oldp+159,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16));
    bufp->chgBit(oldp+160,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud));
    bufp->chgCData(oldp+161,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth),4);
    bufp->chgCData(oldp+162,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth),5);
    bufp->chgCData(oldp+163,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q),5);
    bufp->chgIData(oldp+164,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d),24);
    bufp->chgIData(oldp+165,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q),24);
    bufp->chgIData(oldp+166,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val),24);
    bufp->chgBit(oldp+167,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed));
    bufp->chgBit(oldp+168,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en));
    bufp->chgBit(oldp+169,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable));
    bufp->chgBit(oldp+170,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback));
    bufp->chgBit(oldp+171,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback));
    bufp->chgBit(oldp+172,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable));
    bufp->chgBit(oldp+173,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst));
    bufp->chgBit(oldp+174,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst));
    bufp->chgCData(oldp+175,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data),8);
    bufp->chgBit(oldp+176,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready));
    bufp->chgBit(oldp+177,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid));
    bufp->chgBit(oldp+178,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready));
    bufp->chgBit(oldp+179,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle));
    bufp->chgBit(oldp+180,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out));
    bufp->chgBit(oldp+181,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q));
    bufp->chgCData(oldp+182,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data),8);
    bufp->chgBit(oldp+183,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
    bufp->chgBit(oldp+184,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid));
    bufp->chgBit(oldp+185,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid));
    bufp->chgBit(oldp+186,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready));
    bufp->chgBit(oldp+187,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle));
    bufp->chgBit(oldp+188,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync));
    bufp->chgBit(oldp+189,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in));
    bufp->chgBit(oldp+190,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err));
    bufp->chgCData(oldp+191,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d),5);
    bufp->chgCData(oldp+192,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q),5);
    bufp->chgBit(oldp+193,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err));
    bufp->chgBit(oldp+194,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char));
    bufp->chgBit(oldp+195,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark));
    bufp->chgBit(oldp+196,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty));
    bufp->chgBit(oldp+197,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark));
    bufp->chgBit(oldp+198,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done));
    bufp->chgBit(oldp+199,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow));
    bufp->chgBit(oldp+200,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err));
    bufp->chgBit(oldp+201,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err));
    bufp->chgBit(oldp+202,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout));
    bufp->chgBit(oldp+203,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err));
    bufp->chgBit(oldp+204,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q));
    bufp->chgBit(oldp+205,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni));
    bufp->chgBit(oldp+206,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni));
    bufp->chgBit(oldp+207,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni));
    bufp->chgBit(oldp+208,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop));
    bufp->chgCData(oldp+209,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata),8);
    bufp->chgBit(oldp+210,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid));
    bufp->chgIData(oldp+211,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q),17);
    bufp->chgBit(oldp+212,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1));
    bufp->chgBit(oldp+213,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2));
    bufp->chgBit(oldp+214,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx));
    bufp->chgBit(oldp+215,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj));
    bufp->chgBit(oldp+216,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i));
    bufp->chgBit(oldp+217,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni));
    bufp->chgBit(oldp+218,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i));
    bufp->chgBit(oldp+219,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o));
    bufp->chgBit(oldp+220,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o));
    bufp->chgBit(oldp+221,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq));
    bufp->chgBit(oldp+222,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+223,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+224,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+225,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+226,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+227,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+228,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+229,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+230,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+231,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+232,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+233,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+234,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+235,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+236,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+237,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+238,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+239,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i));
    bufp->chgBit(oldp+240,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni));
    bufp->chgBit(oldp+241,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i));
    bufp->chgBit(oldp+242,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i));
    bufp->chgBit(oldp+243,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o));
    bufp->chgCData(oldp+244,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i),8);
    bufp->chgBit(oldp+245,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o));
    bufp->chgBit(oldp+246,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i));
    bufp->chgCData(oldp+247,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o),8);
    bufp->chgBit(oldp+248,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o));
    bufp->chgCData(oldp+249,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o),5);
    bufp->chgCData(oldp+250,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),4);
    bufp->chgCData(oldp+251,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),4);
    bufp->chgBit(oldp+252,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+253,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+254,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->chgBit(oldp+255,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->chgBit(oldp+256,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 257, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->chgCData(oldp+273,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->chgCData(oldp+274,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->chgBit(oldp+275,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->chgBit(oldp+276,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->chgBit(oldp+277,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->chgBit(oldp+278,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->chgBit(oldp+279,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->chgCData(oldp+280,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),4);
    bufp->chgCData(oldp+281,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),4);
    bufp->chgBit(oldp+282,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->chgBit(oldp+283,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->chgCData(oldp+284,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),5);
    bufp->chgCData(oldp+285,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),5);
    bufp->chgCData(oldp+286,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),5);
    bufp->chgCData(oldp+287,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),5);
    bufp->chgCData(oldp+288,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),5);
    bufp->chgBit(oldp+289,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->chgBit(oldp+290,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->chgBit(oldp+291,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->chgBit(oldp+292,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->chgBit(oldp+293,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i));
    bufp->chgBit(oldp+294,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni));
    bufp->chgBit(oldp+295,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i));
    bufp->chgBit(oldp+296,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i));
    bufp->chgBit(oldp+297,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o));
    bufp->chgCData(oldp+298,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i),8);
    bufp->chgBit(oldp+299,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o));
    bufp->chgBit(oldp+300,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i));
    bufp->chgCData(oldp+301,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o),8);
    bufp->chgBit(oldp+302,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o));
    bufp->chgCData(oldp+303,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o),4);
    bufp->chgCData(oldp+304,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),3);
    bufp->chgCData(oldp+305,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),3);
    bufp->chgBit(oldp+306,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+307,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+308,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->chgBit(oldp+309,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->chgBit(oldp+310,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 311, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->chgCData(oldp+319,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->chgCData(oldp+320,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->chgBit(oldp+321,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->chgBit(oldp+322,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->chgBit(oldp+323,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->chgBit(oldp+324,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->chgBit(oldp+325,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->chgCData(oldp+326,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),3);
    bufp->chgCData(oldp+327,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),3);
    bufp->chgBit(oldp+328,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->chgBit(oldp+329,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->chgCData(oldp+330,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),4);
    bufp->chgCData(oldp+331,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),4);
    bufp->chgCData(oldp+332,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),4);
    bufp->chgCData(oldp+333,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),4);
    bufp->chgCData(oldp+334,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),4);
    bufp->chgBit(oldp+335,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->chgBit(oldp+336,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->chgBit(oldp+337,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->chgBit(oldp+338,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->chgBit(oldp+339,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i));
    bufp->chgBit(oldp+340,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni));
    bufp->chgBit(oldp+341,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16));
    bufp->chgBit(oldp+342,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable));
    bufp->chgBit(oldp+343,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd));
    bufp->chgBit(oldp+344,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud));
    bufp->chgBit(oldp+345,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid));
    bufp->chgCData(oldp+346,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data),8);
    bufp->chgBit(oldp+347,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle));
    bufp->chgBit(oldp+348,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err));
    bufp->chgBit(oldp+349,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err));
    bufp->chgBit(oldp+350,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx));
    bufp->chgBit(oldp+351,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    bufp->chgSData(oldp+352,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q),11);
    bufp->chgSData(oldp+353,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d),11);
    bufp->chgCData(oldp+354,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q),4);
    bufp->chgCData(oldp+355,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d),4);
    bufp->chgCData(oldp+356,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q),4);
    bufp->chgCData(oldp+357,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d),4);
    bufp->chgBit(oldp+358,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d));
    bufp->chgBit(oldp+359,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q));
    bufp->chgBit(oldp+360,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d));
    bufp->chgBit(oldp+361,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q));
    bufp->chgBit(oldp+362,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i));
    bufp->chgBit(oldp+363,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni));
    bufp->chgBit(oldp+364,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable));
    bufp->chgBit(oldp+365,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16));
    bufp->chgBit(oldp+366,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable));
    bufp->chgBit(oldp+367,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr));
    bufp->chgBit(oldp+368,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity));
    bufp->chgCData(oldp+369,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data),8);
    bufp->chgBit(oldp+370,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle));
    bufp->chgBit(oldp+371,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx));
    bufp->chgCData(oldp+372,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q),4);
    bufp->chgBit(oldp+373,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q));
    bufp->chgCData(oldp+374,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q),4);
    bufp->chgCData(oldp+375,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d),4);
    bufp->chgSData(oldp+376,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q),11);
    bufp->chgSData(oldp+377,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d),11);
    bufp->chgBit(oldp+378,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q));
    bufp->chgBit(oldp+379,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d));
    bufp->chgBit(oldp+380,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i));
    bufp->chgBit(oldp+381,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni));
    bufp->chgBit(oldp+382,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+383,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+384,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+385,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+386,((0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+387,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+388,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+389,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+390,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+391,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+392,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+393,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+394,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_i[0U])));
    bufp->chgBit(oldp+395,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+396,((7U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+397,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+398,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+399,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+400,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+401,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+402,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+403,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+404,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+405,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__tl_o[0U])));
    bufp->chgSData(oldp+406,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+407,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+408,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+409,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+410,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+411,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+412,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+413,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+414,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+415,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+416,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+417,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+418,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+419,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+420,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+421,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+422,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+423,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+424,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+425,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+426,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+427,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+428,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+429,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+430,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+431,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+432,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+433,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw))));
    bufp->chgBit(oldp+434,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+435,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+436,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+437,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+438,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+439,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+440,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+441,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+442,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg)),8);
    bufp->chgBit(oldp+443,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_re));
    bufp->chgBit(oldp+444,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_we));
    bufp->chgCData(oldp+445,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_addr),5);
    bufp->chgIData(oldp+446,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_wdata),32);
    bufp->chgCData(oldp+447,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_be),4);
    bufp->chgBit(oldp+448,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_req 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+449,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_req 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+450,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_req 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+451,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_req 
                                      >> 4U))),32);
    bufp->chgCData(oldp+452,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_req))),4);
    bufp->chgIData(oldp+453,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                                      >> 2U))),32);
    bufp->chgBit(oldp+454,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp 
                                          >> 1U)))));
    bufp->chgBit(oldp+455,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_tlul_reg_rsp))));
    bufp->chgBit(oldp+456,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i));
    bufp->chgBit(oldp+457,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni));
    bufp->chgBit(oldp+458,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+459,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+460,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+461,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+462,((0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+463,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+464,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+465,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+466,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+467,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+468,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+469,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+470,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U])));
    bufp->chgBit(oldp+471,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+472,((7U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+473,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+474,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+475,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+476,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+477,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+478,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+479,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+480,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+481,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U])));
    bufp->chgBit(oldp+482,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o));
    bufp->chgBit(oldp+483,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o));
    bufp->chgCData(oldp+484,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o),5);
    bufp->chgIData(oldp+485,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o),32);
    bufp->chgCData(oldp+486,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o),4);
    bufp->chgBit(oldp+487,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i));
    bufp->chgIData(oldp+488,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i),32);
    bufp->chgBit(oldp+489,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i));
    bufp->chgBit(oldp+490,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q));
    bufp->chgBit(oldp+491,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack));
    bufp->chgBit(oldp+492,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack));
    bufp->chgIData(oldp+493,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata),32);
    bufp->chgIData(oldp+494,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q),32);
    bufp->chgBit(oldp+495,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q));
    bufp->chgBit(oldp+496,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error));
    bufp->chgBit(oldp+497,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal));
    bufp->chgBit(oldp+498,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error));
    bufp->chgBit(oldp+499,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err));
    bufp->chgBit(oldp+500,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err));
    bufp->chgBit(oldp+501,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err));
    bufp->chgCData(oldp+502,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q),8);
    bufp->chgCData(oldp+503,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q),2);
    bufp->chgCData(oldp+504,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q),3);
    bufp->chgBit(oldp+505,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req));
    bufp->chgBit(oldp+506,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req));
    bufp->chgBit(oldp+507,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+508,((7U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                     << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+509,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+510,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+511,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+512,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+513,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                               << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+514,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+515,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+516,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+517,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U])));
    bufp->chgBit(oldp+518,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i));
    bufp->chgBit(oldp+519,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni));
    bufp->chgBit(oldp+520,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+521,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+522,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+523,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+524,((0x000000ffU & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+525,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+526,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+527,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+528,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+529,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+530,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+531,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+532,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U])));
    bufp->chgBit(oldp+533,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o));
    bufp->chgBit(oldp+534,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed));
    bufp->chgBit(oldp+535,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed));
    bufp->chgBit(oldp+536,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full));
    bufp->chgBit(oldp+537,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial));
    bufp->chgBit(oldp+538,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get));
    bufp->chgBit(oldp+539,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err));
    bufp->chgBit(oldp+540,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err));
    bufp->chgBit(oldp+541,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk));
    bufp->chgBit(oldp+542,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk));
    bufp->chgBit(oldp+543,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk));
    bufp->chgCData(oldp+544,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask),4);
    bufp->chgBit(oldp+545,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+546,((7U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                     << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+547,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+548,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+549,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+550,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+551,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                               << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+552,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+553,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+554,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+555,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->chgBit(oldp+556,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+557,((7U & ((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+558,((7U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+559,((3U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+560,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+561,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+562,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+563,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+564,((0x0000007fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+565,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+566,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->chgBit(oldp+567,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->chgBit(oldp+568,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->chgBit(oldp+569,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->chgBit(oldp+570,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+571,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+572,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+573,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+574,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+575,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+576,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+577,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->chgSData(oldp+578,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+579,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+580,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+581,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+582,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+583,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+584,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+585,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+586,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+587,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+588,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+589,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+590,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+591,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+592,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+593,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+594,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+595,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+596,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+597,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+598,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+599,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+600,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+601,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+602,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+603,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+604,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+605,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw))));
    bufp->chgBit(oldp+606,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+607,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+608,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+609,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+610,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+611,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+612,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+613,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+614,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg)),8);
    bufp->chgBit(oldp+615,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->chgBit(oldp+616,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->chgBit(oldp+617,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->chgCData(oldp+618,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr),5);
    bufp->chgIData(oldp+619,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->chgCData(oldp+620,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->chgIData(oldp+621,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->chgBit(oldp+622,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->chgBit(oldp+623,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->chgBit(oldp+624,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->chgIData(oldp+625,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+626,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->chgCData(oldp+627,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check),6);
    bufp->chgBit(oldp+628,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q));
    bufp->chgBit(oldp+629,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we));
    bufp->chgBit(oldp+630,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs));
    bufp->chgBit(oldp+631,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd));
    bufp->chgBit(oldp+632,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs));
    bufp->chgBit(oldp+633,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd));
    bufp->chgBit(oldp+634,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs));
    bufp->chgBit(oldp+635,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd));
    bufp->chgBit(oldp+636,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs));
    bufp->chgBit(oldp+637,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd));
    bufp->chgBit(oldp+638,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs));
    bufp->chgBit(oldp+639,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd));
    bufp->chgBit(oldp+640,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs));
    bufp->chgBit(oldp+641,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd));
    bufp->chgBit(oldp+642,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs));
    bufp->chgBit(oldp+643,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd));
    bufp->chgSData(oldp+644,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs),16);
    bufp->chgSData(oldp+645,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd),16);
    bufp->chgBit(oldp+646,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re));
    bufp->chgBit(oldp+647,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs));
    bufp->chgBit(oldp+648,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs));
    bufp->chgBit(oldp+649,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs));
    bufp->chgBit(oldp+650,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs));
    bufp->chgBit(oldp+651,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs));
    bufp->chgBit(oldp+652,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs));
    bufp->chgBit(oldp+653,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re));
    bufp->chgCData(oldp+654,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs),8);
    bufp->chgBit(oldp+655,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we));
    bufp->chgCData(oldp+656,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd),8);
    bufp->chgBit(oldp+657,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we));
    bufp->chgBit(oldp+658,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd));
    bufp->chgBit(oldp+659,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd));
    bufp->chgBit(oldp+660,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re));
    bufp->chgCData(oldp+661,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs),8);
    bufp->chgCData(oldp+662,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs),8);
    bufp->chgBit(oldp+663,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe));
    bufp->chgBit(oldp+664,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we));
    bufp->chgBit(oldp+665,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe));
    bufp->chgCData(oldp+666,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we),2);
    bufp->chgCData(oldp+667,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit),6);
    bufp->chgBit(oldp+668,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->chgBit(oldp+669,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->chgBit(oldp+670,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i));
    bufp->chgBit(oldp+671,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni));
    bufp->chgBit(oldp+672,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we));
    bufp->chgBit(oldp+673,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd));
    bufp->chgBit(oldp+674,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe));
    bufp->chgBit(oldp+675,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q));
    bufp->chgBit(oldp+676,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds));
    bufp->chgBit(oldp+677,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs));
    bufp->chgBit(oldp+678,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en));
    bufp->chgBit(oldp+679,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data));
    bufp->chgBit(oldp+680,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+681,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+682,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+683,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+684,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+685,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+686,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i));
    bufp->chgBit(oldp+687,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni));
    bufp->chgBit(oldp+688,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we));
    bufp->chgSData(oldp+689,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd),16);
    bufp->chgBit(oldp+690,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe));
    bufp->chgSData(oldp+691,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q),16);
    bufp->chgSData(oldp+692,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds),16);
    bufp->chgSData(oldp+693,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs),16);
    bufp->chgBit(oldp+694,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en));
    bufp->chgSData(oldp+695,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data),16);
    bufp->chgBit(oldp+696,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we));
    bufp->chgSData(oldp+697,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd),16);
    bufp->chgSData(oldp+698,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q),16);
    bufp->chgBit(oldp+699,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgSData(oldp+700,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data),16);
    bufp->chgSData(oldp+701,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),16);
    bufp->chgBit(oldp+702,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i));
    bufp->chgBit(oldp+703,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni));
    bufp->chgBit(oldp+704,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we));
    bufp->chgBit(oldp+705,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd));
    bufp->chgBit(oldp+706,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe));
    bufp->chgBit(oldp+707,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q));
    bufp->chgBit(oldp+708,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds));
    bufp->chgBit(oldp+709,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs));
    bufp->chgBit(oldp+710,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en));
    bufp->chgBit(oldp+711,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data));
    bufp->chgBit(oldp+712,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+713,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+714,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+715,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+716,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+717,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+718,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i));
    bufp->chgBit(oldp+719,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni));
    bufp->chgBit(oldp+720,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we));
    bufp->chgBit(oldp+721,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd));
    bufp->chgBit(oldp+722,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe));
    bufp->chgBit(oldp+723,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q));
    bufp->chgBit(oldp+724,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds));
    bufp->chgBit(oldp+725,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs));
    bufp->chgBit(oldp+726,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en));
    bufp->chgBit(oldp+727,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data));
    bufp->chgBit(oldp+728,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+729,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+730,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+731,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+732,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+733,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+734,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i));
    bufp->chgBit(oldp+735,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni));
    bufp->chgBit(oldp+736,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we));
    bufp->chgBit(oldp+737,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd));
    bufp->chgBit(oldp+738,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe));
    bufp->chgBit(oldp+739,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q));
    bufp->chgBit(oldp+740,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds));
    bufp->chgBit(oldp+741,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs));
    bufp->chgBit(oldp+742,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en));
    bufp->chgBit(oldp+743,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data));
    bufp->chgBit(oldp+744,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+745,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+746,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+747,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+748,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+749,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+750,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i));
    bufp->chgBit(oldp+751,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni));
    bufp->chgBit(oldp+752,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we));
    bufp->chgBit(oldp+753,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd));
    bufp->chgBit(oldp+754,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe));
    bufp->chgBit(oldp+755,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q));
    bufp->chgBit(oldp+756,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds));
    bufp->chgBit(oldp+757,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs));
    bufp->chgBit(oldp+758,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en));
    bufp->chgBit(oldp+759,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data));
    bufp->chgBit(oldp+760,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+761,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+762,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+763,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+764,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+765,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+766,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i));
    bufp->chgBit(oldp+767,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni));
    bufp->chgBit(oldp+768,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we));
    bufp->chgBit(oldp+769,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd));
    bufp->chgBit(oldp+770,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe));
    bufp->chgBit(oldp+771,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q));
    bufp->chgBit(oldp+772,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds));
    bufp->chgBit(oldp+773,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs));
    bufp->chgBit(oldp+774,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en));
    bufp->chgBit(oldp+775,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data));
    bufp->chgBit(oldp+776,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+777,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+778,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+779,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+780,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+781,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+782,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i));
    bufp->chgBit(oldp+783,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni));
    bufp->chgBit(oldp+784,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we));
    bufp->chgBit(oldp+785,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd));
    bufp->chgBit(oldp+786,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe));
    bufp->chgBit(oldp+787,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q));
    bufp->chgBit(oldp+788,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds));
    bufp->chgBit(oldp+789,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs));
    bufp->chgBit(oldp+790,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en));
    bufp->chgBit(oldp+791,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data));
    bufp->chgBit(oldp+792,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+793,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+794,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+795,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+796,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+797,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+798,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i));
    bufp->chgBit(oldp+799,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni));
    bufp->chgBit(oldp+800,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i));
    bufp->chgBit(oldp+801,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o));
    bufp->chgBit(oldp+802,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i));
    bufp->chgBit(oldp+803,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni));
    bufp->chgBit(oldp+804,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we));
    bufp->chgBit(oldp+805,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd));
    bufp->chgBit(oldp+806,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe));
    bufp->chgBit(oldp+807,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q));
    bufp->chgBit(oldp+808,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds));
    bufp->chgBit(oldp+809,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs));
    bufp->chgBit(oldp+810,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en));
    bufp->chgBit(oldp+811,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data));
    bufp->chgBit(oldp+812,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+813,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+814,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+815,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+816,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+817,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+818,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i));
    bufp->chgBit(oldp+819,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni));
    bufp->chgBit(oldp+820,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we));
    bufp->chgBit(oldp+821,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd));
    bufp->chgBit(oldp+822,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe));
    bufp->chgBit(oldp+823,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q));
    bufp->chgBit(oldp+824,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds));
    bufp->chgBit(oldp+825,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs));
    bufp->chgBit(oldp+826,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en));
    bufp->chgBit(oldp+827,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data));
    bufp->chgBit(oldp+828,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+829,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+830,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+831,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+832,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+833,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+834,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re));
    bufp->chgCData(oldp+835,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d),8);
    bufp->chgBit(oldp+836,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre));
    bufp->chgCData(oldp+837,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds),8);
    bufp->chgCData(oldp+838,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs),8);
    bufp->chgBit(oldp+839,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re));
    bufp->chgCData(oldp+840,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d),8);
    bufp->chgBit(oldp+841,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre));
    bufp->chgCData(oldp+842,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds),8);
    bufp->chgCData(oldp+843,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs),8);
    bufp->chgBit(oldp+844,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->chgBit(oldp+845,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->chgCData(oldp+846,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),6);
    bufp->chgBit(oldp+847,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->chgBit(oldp+848,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->chgCData(oldp+849,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),6);
    bufp->chgCData(oldp+850,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),6);
    bufp->chgCData(oldp+851,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),6);
    bufp->chgCData(oldp+852,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),6);
    bufp->chgBit(oldp+853,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->chgBit(oldp+854,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->chgCData(oldp+855,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),6);
    bufp->chgBit(oldp+856,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->chgBit(oldp+857,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->chgSData(oldp+858,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),15);
    bufp->chgSData(oldp+859,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),15);
    bufp->chgSData(oldp+860,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),15);
    bufp->chgBit(oldp+861,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re));
    bufp->chgCData(oldp+862,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d),8);
    bufp->chgBit(oldp+863,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre));
    bufp->chgCData(oldp+864,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds),8);
    bufp->chgCData(oldp+865,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs),8);
    bufp->chgBit(oldp+866,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re));
    bufp->chgBit(oldp+867,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d));
    bufp->chgBit(oldp+868,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre));
    bufp->chgBit(oldp+869,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds));
    bufp->chgBit(oldp+870,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs));
    bufp->chgBit(oldp+871,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re));
    bufp->chgBit(oldp+872,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d));
    bufp->chgBit(oldp+873,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre));
    bufp->chgBit(oldp+874,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds));
    bufp->chgBit(oldp+875,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs));
    bufp->chgBit(oldp+876,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re));
    bufp->chgBit(oldp+877,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d));
    bufp->chgBit(oldp+878,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre));
    bufp->chgBit(oldp+879,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds));
    bufp->chgBit(oldp+880,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs));
    bufp->chgBit(oldp+881,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re));
    bufp->chgBit(oldp+882,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d));
    bufp->chgBit(oldp+883,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre));
    bufp->chgBit(oldp+884,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds));
    bufp->chgBit(oldp+885,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs));
    bufp->chgBit(oldp+886,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re));
    bufp->chgBit(oldp+887,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d));
    bufp->chgBit(oldp+888,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre));
    bufp->chgBit(oldp+889,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds));
    bufp->chgBit(oldp+890,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs));
    bufp->chgBit(oldp+891,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re));
    bufp->chgBit(oldp+892,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d));
    bufp->chgBit(oldp+893,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre));
    bufp->chgBit(oldp+894,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds));
    bufp->chgBit(oldp+895,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs));
    bufp->chgBit(oldp+896,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i));
    bufp->chgBit(oldp+897,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni));
    bufp->chgBit(oldp+898,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we));
    bufp->chgCData(oldp+899,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd),8);
    bufp->chgBit(oldp+900,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe));
    bufp->chgCData(oldp+901,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q),8);
    bufp->chgCData(oldp+902,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds),8);
    bufp->chgCData(oldp+903,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs),8);
    bufp->chgBit(oldp+904,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en));
    bufp->chgCData(oldp+905,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data),8);
    bufp->chgBit(oldp+906,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+907,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->chgCData(oldp+908,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q),8);
    bufp->chgBit(oldp+909,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+910,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->chgCData(oldp+911,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->chgBit(oldp+912,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i));
    bufp->chgBit(oldp+913,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni));
    bufp->chgBit(oldp+914,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i));
    bufp->chgBit(oldp+915,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o));
    Vtop___024root__trace_chg_dtype____2(vlSelf, bufp, 916, vlSymsp->TOP__uart_reg_pkg.UART_PERMIT);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<4>/*127:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000078U, 8))),8);
    bufp->chgCData(oldp+1,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000070U, 8))),8);
    bufp->chgCData(oldp+2,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000068U, 8))),8);
    bufp->chgCData(oldp+3,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000060U, 8))),8);
    bufp->chgCData(oldp+4,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000058U, 8))),8);
    bufp->chgCData(oldp+5,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000050U, 8))),8);
    bufp->chgCData(oldp+6,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000048U, 8))),8);
    bufp->chgCData(oldp+7,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000040U, 8))),8);
    bufp->chgCData(oldp+8,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000038U, 8))),8);
    bufp->chgCData(oldp+9,((0x000000ffU & VL_SEL_IWII(128, 
                                                      __VdtypeVar, 0x00000030U, 8))),8);
    bufp->chgCData(oldp+10,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000028U, 8))),8);
    bufp->chgCData(oldp+11,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000020U, 8))),8);
    bufp->chgCData(oldp+12,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000018U, 8))),8);
    bufp->chgCData(oldp+13,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000010U, 8))),8);
    bufp->chgCData(oldp+14,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 8U, 8))),8);
    bufp->chgCData(oldp+15,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0U, 8))),8);
}

void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const QData/*63:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 0x00000038U)))),8);
    bufp->chgCData(oldp+1,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 0x00000030U)))),8);
    bufp->chgCData(oldp+2,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 0x00000028U)))),8);
    bufp->chgCData(oldp+3,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 0x00000020U)))),8);
    bufp->chgCData(oldp+4,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 0x00000018U)))),8);
    bufp->chgCData(oldp+5,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 0x00000010U)))),8);
    bufp->chgCData(oldp+6,((0x000000ffU & (IData)((
                                                   __VdtypeVar 
                                                   >> 8U)))),8);
    bufp->chgCData(oldp+7,((0x000000ffU & (IData)(__VdtypeVar))),8);
}

void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 6>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____2\n"); );
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
