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
void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const SData/*9:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*81:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____5(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____6(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 6>& __VdtypeVar);

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
    bufp->chgCData(oldp+4,((0x0000001fU & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                                   >> 0x00000034U)))),5);
    bufp->chgCData(oldp+5,((7U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                          >> 0x00000031U)))),3);
    bufp->chgBit(oldp+6,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                        >> 0x00000030U)))));
    bufp->chgIData(oldp+7,((IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                    >> 0x00000010U))),32);
    bufp->chgCData(oldp+8,((0x0000000fU & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                                   >> 0x0000000cU)))),4);
    bufp->chgBit(oldp+9,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                        >> 0x0000000bU)))));
    bufp->chgBit(oldp+10,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                         >> 0x0000000aU)))));
    bufp->chgCData(oldp+11,((0x0000001fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__axi_lite_i 
                                                    >> 5U)))),5);
    bufp->chgCData(oldp+12,((7U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                           >> 2U)))),3);
    bufp->chgBit(oldp+13,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                         >> 1U)))));
    bufp->chgBit(oldp+14,((1U & (IData)(vlSelfRef.uart_tb__DOT__axi_lite_i))));
    bufp->chgBit(oldp+15,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+16,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                         >> 0x00000027U)))));
    bufp->chgCData(oldp+17,((3U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                           >> 0x00000025U)))),2);
    bufp->chgBit(oldp+18,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+19,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                         >> 0x00000023U)))));
    bufp->chgIData(oldp+20,((IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                     >> 3U))),32);
    bufp->chgCData(oldp+21,((3U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                           >> 1U)))),2);
    bufp->chgBit(oldp+22,((1U & (IData)(vlSelfRef.uart_tb__DOT__axi_lite_o))));
    bufp->chgCData(oldp+23,(vlSelfRef.uart_tb__DOT__axi_aw_addr_i),5);
    bufp->chgCData(oldp+24,(vlSelfRef.uart_tb__DOT__axi_aw_prot_i),3);
    bufp->chgBit(oldp+25,(vlSelfRef.uart_tb__DOT__axi_aw_valid_i));
    bufp->chgBit(oldp+26,(vlSelfRef.uart_tb__DOT__axi_aw_ready_o));
    bufp->chgIData(oldp+27,(vlSelfRef.uart_tb__DOT__axi_w_data_i),32);
    bufp->chgCData(oldp+28,(vlSelfRef.uart_tb__DOT__axi_w_strb_i),4);
    bufp->chgBit(oldp+29,(vlSelfRef.uart_tb__DOT__axi_w_valid_i));
    bufp->chgBit(oldp+30,(vlSelfRef.uart_tb__DOT__axi_w_ready_o));
    bufp->chgCData(oldp+31,(vlSelfRef.uart_tb__DOT__axi_b_resp_o),2);
    bufp->chgBit(oldp+32,(vlSelfRef.uart_tb__DOT__axi_b_valid_o));
    bufp->chgBit(oldp+33,(vlSelfRef.uart_tb__DOT__axi_b_ready_i));
    bufp->chgCData(oldp+34,(vlSelfRef.uart_tb__DOT__axi_ar_addr_i),5);
    bufp->chgCData(oldp+35,(vlSelfRef.uart_tb__DOT__axi_ar_prot_i),3);
    bufp->chgBit(oldp+36,(vlSelfRef.uart_tb__DOT__axi_ar_valid_i));
    bufp->chgBit(oldp+37,(vlSelfRef.uart_tb__DOT__axi_ar_ready_o));
    bufp->chgIData(oldp+38,(vlSelfRef.uart_tb__DOT__axi_r_data_o),32);
    bufp->chgCData(oldp+39,(vlSelfRef.uart_tb__DOT__axi_r_resp_o),2);
    bufp->chgBit(oldp+40,(vlSelfRef.uart_tb__DOT__axi_r_valid_o));
    bufp->chgBit(oldp+41,(vlSelfRef.uart_tb__DOT__axi_r_ready_i));
    bufp->chgBit(oldp+42,(vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i));
    bufp->chgBit(oldp+43,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni));
    bufp->chgBit(oldp+44,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i));
    bufp->chgBit(oldp+45,(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o));
    bufp->chgCData(oldp+46,((0x0000001fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                                    >> 0x00000034U)))),5);
    bufp->chgCData(oldp+47,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                           >> 0x00000031U)))),3);
    bufp->chgBit(oldp+48,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                         >> 0x00000030U)))));
    bufp->chgIData(oldp+49,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                     >> 0x00000010U))),32);
    bufp->chgCData(oldp+50,((0x0000000fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                                    >> 0x0000000cU)))),4);
    bufp->chgBit(oldp+51,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                         >> 0x0000000bU)))));
    bufp->chgBit(oldp+52,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                         >> 0x0000000aU)))));
    bufp->chgCData(oldp+53,((0x0000001fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                                    >> 5U)))),5);
    bufp->chgCData(oldp+54,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                           >> 2U)))),3);
    bufp->chgBit(oldp+55,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                         >> 1U)))));
    bufp->chgBit(oldp+56,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i))));
    bufp->chgBit(oldp+57,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+58,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                         >> 0x00000027U)))));
    bufp->chgCData(oldp+59,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                           >> 0x00000025U)))),2);
    bufp->chgBit(oldp+60,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+61,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                         >> 0x00000023U)))));
    bufp->chgIData(oldp+62,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                     >> 3U))),32);
    bufp->chgCData(oldp+63,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                           >> 1U)))),2);
    bufp->chgBit(oldp+64,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o))));
    bufp->chgSData(oldp+65,((0x0000ffffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 0x00000029U)))),16);
    bufp->chgBit(oldp+66,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+67,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000027U)))));
    bufp->chgBit(oldp+68,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000026U)))));
    bufp->chgBit(oldp+69,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000025U)))));
    bufp->chgBit(oldp+70,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+71,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000023U)))));
    bufp->chgBit(oldp+72,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000022U)))));
    bufp->chgBit(oldp+73,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000021U)))));
    bufp->chgBit(oldp+74,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000020U)))));
    bufp->chgBit(oldp+75,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001fU)))));
    bufp->chgBit(oldp+76,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001eU)))));
    bufp->chgBit(oldp+77,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001dU)))));
    bufp->chgBit(oldp+78,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001cU)))));
    bufp->chgBit(oldp+79,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001bU)))));
    bufp->chgBit(oldp+80,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001aU)))));
    bufp->chgBit(oldp+81,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000019U)))));
    bufp->chgBit(oldp+82,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000018U)))));
    bufp->chgBit(oldp+83,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000017U)))));
    bufp->chgBit(oldp+84,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000016U)))));
    bufp->chgCData(oldp+85,((0x000000ffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+86,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000000dU)))));
    bufp->chgCData(oldp+87,((0x000000ffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 5U)))),8);
    bufp->chgBit(oldp+88,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 4U)))));
    bufp->chgBit(oldp+89,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 3U)))));
    bufp->chgBit(oldp+90,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 2U)))));
    bufp->chgBit(oldp+91,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 1U)))));
    bufp->chgBit(oldp+92,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw))));
    bufp->chgBit(oldp+93,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001dU))));
    bufp->chgBit(oldp+94,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001cU))));
    bufp->chgBit(oldp+95,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001bU))));
    bufp->chgBit(oldp+96,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001aU))));
    bufp->chgBit(oldp+97,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x00000019U))));
    bufp->chgBit(oldp+98,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x00000018U))));
    bufp->chgCData(oldp+99,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                            >> 0x00000010U))),8);
    bufp->chgCData(oldp+100,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+101,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg)),8);
    bufp->chgBit(oldp+102,(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni));
    bufp->chgBit(oldp+103,(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni));
    bufp->chgBit(oldp+104,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+105,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+106,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+107,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+108,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq));
    bufp->chgBit(oldp+109,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+110,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+111,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+112,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+113,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+114,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+115,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+116,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+117,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+118,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+119,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+120,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq));
    bufp->chgBit(oldp+121,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+122,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+123,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+124,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+125,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+126,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+127,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+128,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i));
    bufp->chgBit(oldp+129,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni));
    bufp->chgSData(oldp+130,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+131,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+132,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+133,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+134,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+135,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+136,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+137,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+138,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+139,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+140,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+141,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+142,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+143,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+144,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+145,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+146,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+147,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+148,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+149,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+150,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+151,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+152,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+153,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+154,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+155,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+156,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+157,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw))));
    bufp->chgBit(oldp+158,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+159,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+160,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+161,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+162,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+163,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+164,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+165,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+166,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg)),8);
    bufp->chgBit(oldp+167,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i));
    bufp->chgBit(oldp+168,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o));
    bufp->chgSData(oldp+169,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q),16);
    bufp->chgCData(oldp+170,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata),8);
    bufp->chgBit(oldp+171,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16));
    bufp->chgBit(oldp+172,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud));
    bufp->chgCData(oldp+173,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth),4);
    bufp->chgCData(oldp+174,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth),5);
    bufp->chgCData(oldp+175,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q),5);
    bufp->chgIData(oldp+176,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d),24);
    bufp->chgIData(oldp+177,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q),24);
    bufp->chgIData(oldp+178,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val),24);
    bufp->chgBit(oldp+179,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed));
    bufp->chgBit(oldp+180,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en));
    bufp->chgBit(oldp+181,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable));
    bufp->chgBit(oldp+182,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback));
    bufp->chgBit(oldp+183,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback));
    bufp->chgBit(oldp+184,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable));
    bufp->chgBit(oldp+185,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst));
    bufp->chgBit(oldp+186,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst));
    bufp->chgCData(oldp+187,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data),8);
    bufp->chgBit(oldp+188,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready));
    bufp->chgBit(oldp+189,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid));
    bufp->chgBit(oldp+190,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready));
    bufp->chgBit(oldp+191,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle));
    bufp->chgBit(oldp+192,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out));
    bufp->chgBit(oldp+193,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q));
    bufp->chgCData(oldp+194,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data),8);
    bufp->chgBit(oldp+195,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
    bufp->chgBit(oldp+196,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid));
    bufp->chgBit(oldp+197,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid));
    bufp->chgBit(oldp+198,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready));
    bufp->chgBit(oldp+199,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle));
    bufp->chgBit(oldp+200,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync));
    bufp->chgBit(oldp+201,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in));
    bufp->chgBit(oldp+202,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err));
    bufp->chgCData(oldp+203,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d),5);
    bufp->chgCData(oldp+204,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q),5);
    bufp->chgBit(oldp+205,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err));
    bufp->chgBit(oldp+206,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char));
    bufp->chgBit(oldp+207,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark));
    bufp->chgBit(oldp+208,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty));
    bufp->chgBit(oldp+209,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark));
    bufp->chgBit(oldp+210,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done));
    bufp->chgBit(oldp+211,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow));
    bufp->chgBit(oldp+212,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err));
    bufp->chgBit(oldp+213,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err));
    bufp->chgBit(oldp+214,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout));
    bufp->chgBit(oldp+215,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err));
    bufp->chgBit(oldp+216,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q));
    bufp->chgBit(oldp+217,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni));
    bufp->chgBit(oldp+218,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni));
    bufp->chgBit(oldp+219,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni));
    bufp->chgBit(oldp+220,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop));
    bufp->chgCData(oldp+221,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata),8);
    bufp->chgBit(oldp+222,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid));
    bufp->chgIData(oldp+223,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q),17);
    bufp->chgBit(oldp+224,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1));
    bufp->chgBit(oldp+225,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2));
    bufp->chgBit(oldp+226,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx));
    bufp->chgBit(oldp+227,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj));
    bufp->chgBit(oldp+228,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i));
    bufp->chgBit(oldp+229,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni));
    bufp->chgBit(oldp+230,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i));
    bufp->chgBit(oldp+231,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o));
    bufp->chgBit(oldp+232,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o));
    bufp->chgBit(oldp+233,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq));
    bufp->chgBit(oldp+234,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+235,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+236,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+237,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+238,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+239,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+240,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+241,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+242,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+243,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+244,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+245,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+246,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+247,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+248,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+249,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+250,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+251,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i));
    bufp->chgBit(oldp+252,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni));
    bufp->chgBit(oldp+253,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i));
    bufp->chgBit(oldp+254,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i));
    bufp->chgBit(oldp+255,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o));
    bufp->chgCData(oldp+256,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i),8);
    bufp->chgBit(oldp+257,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o));
    bufp->chgBit(oldp+258,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i));
    bufp->chgCData(oldp+259,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o),8);
    bufp->chgBit(oldp+260,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o));
    bufp->chgCData(oldp+261,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o),5);
    bufp->chgCData(oldp+262,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),4);
    bufp->chgCData(oldp+263,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),4);
    bufp->chgBit(oldp+264,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+265,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+266,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->chgBit(oldp+267,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->chgBit(oldp+268,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 269, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->chgCData(oldp+285,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->chgCData(oldp+286,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->chgBit(oldp+287,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->chgBit(oldp+288,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->chgBit(oldp+289,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->chgBit(oldp+290,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->chgBit(oldp+291,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->chgCData(oldp+292,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),4);
    bufp->chgCData(oldp+293,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),4);
    bufp->chgBit(oldp+294,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->chgBit(oldp+295,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->chgCData(oldp+296,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),5);
    bufp->chgCData(oldp+297,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),5);
    bufp->chgCData(oldp+298,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),5);
    bufp->chgCData(oldp+299,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),5);
    bufp->chgCData(oldp+300,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),5);
    bufp->chgBit(oldp+301,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->chgBit(oldp+302,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->chgBit(oldp+303,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->chgBit(oldp+304,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->chgBit(oldp+305,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i));
    bufp->chgBit(oldp+306,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni));
    bufp->chgBit(oldp+307,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i));
    bufp->chgBit(oldp+308,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i));
    bufp->chgBit(oldp+309,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o));
    bufp->chgCData(oldp+310,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i),8);
    bufp->chgBit(oldp+311,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o));
    bufp->chgBit(oldp+312,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i));
    bufp->chgCData(oldp+313,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o),8);
    bufp->chgBit(oldp+314,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o));
    bufp->chgCData(oldp+315,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o),4);
    bufp->chgCData(oldp+316,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),3);
    bufp->chgCData(oldp+317,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),3);
    bufp->chgBit(oldp+318,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+319,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+320,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->chgBit(oldp+321,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->chgBit(oldp+322,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 323, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->chgCData(oldp+331,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->chgCData(oldp+332,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->chgBit(oldp+333,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->chgBit(oldp+334,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->chgBit(oldp+335,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->chgBit(oldp+336,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->chgBit(oldp+337,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->chgCData(oldp+338,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),3);
    bufp->chgCData(oldp+339,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),3);
    bufp->chgBit(oldp+340,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->chgBit(oldp+341,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->chgCData(oldp+342,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),4);
    bufp->chgCData(oldp+343,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),4);
    bufp->chgCData(oldp+344,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),4);
    bufp->chgCData(oldp+345,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),4);
    bufp->chgCData(oldp+346,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),4);
    bufp->chgBit(oldp+347,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->chgBit(oldp+348,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->chgBit(oldp+349,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->chgBit(oldp+350,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->chgBit(oldp+351,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i));
    bufp->chgBit(oldp+352,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni));
    bufp->chgBit(oldp+353,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16));
    bufp->chgBit(oldp+354,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable));
    bufp->chgBit(oldp+355,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd));
    bufp->chgBit(oldp+356,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud));
    bufp->chgBit(oldp+357,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid));
    bufp->chgCData(oldp+358,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data),8);
    bufp->chgBit(oldp+359,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle));
    bufp->chgBit(oldp+360,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err));
    bufp->chgBit(oldp+361,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err));
    bufp->chgBit(oldp+362,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx));
    bufp->chgBit(oldp+363,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    bufp->chgSData(oldp+364,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q),11);
    bufp->chgSData(oldp+365,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d),11);
    bufp->chgCData(oldp+366,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q),4);
    bufp->chgCData(oldp+367,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d),4);
    bufp->chgCData(oldp+368,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q),4);
    bufp->chgCData(oldp+369,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d),4);
    bufp->chgBit(oldp+370,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d));
    bufp->chgBit(oldp+371,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q));
    bufp->chgBit(oldp+372,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d));
    bufp->chgBit(oldp+373,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q));
    bufp->chgBit(oldp+374,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i));
    bufp->chgBit(oldp+375,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni));
    bufp->chgBit(oldp+376,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable));
    bufp->chgBit(oldp+377,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16));
    bufp->chgBit(oldp+378,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable));
    bufp->chgBit(oldp+379,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr));
    bufp->chgBit(oldp+380,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity));
    bufp->chgCData(oldp+381,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data),8);
    bufp->chgBit(oldp+382,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle));
    bufp->chgBit(oldp+383,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx));
    bufp->chgCData(oldp+384,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q),4);
    bufp->chgBit(oldp+385,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q));
    bufp->chgCData(oldp+386,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q),4);
    bufp->chgCData(oldp+387,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d),4);
    bufp->chgSData(oldp+388,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q),11);
    bufp->chgSData(oldp+389,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d),11);
    bufp->chgBit(oldp+390,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q));
    bufp->chgBit(oldp+391,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d));
    bufp->chgBit(oldp+392,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i));
    bufp->chgBit(oldp+393,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni));
    bufp->chgCData(oldp+394,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                                     >> 0x00000034U)))),5);
    bufp->chgCData(oldp+395,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                            >> 0x00000031U)))),3);
    bufp->chgBit(oldp+396,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                          >> 0x00000030U)))));
    bufp->chgIData(oldp+397,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                      >> 0x00000010U))),32);
    bufp->chgCData(oldp+398,((0x0000000fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                                     >> 0x0000000cU)))),4);
    bufp->chgBit(oldp+399,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                          >> 0x0000000bU)))));
    bufp->chgBit(oldp+400,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                          >> 0x0000000aU)))));
    bufp->chgCData(oldp+401,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                                     >> 5U)))),5);
    bufp->chgCData(oldp+402,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                            >> 2U)))),3);
    bufp->chgBit(oldp+403,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                          >> 1U)))));
    bufp->chgBit(oldp+404,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i))));
    bufp->chgBit(oldp+405,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+406,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                          >> 0x00000027U)))));
    bufp->chgCData(oldp+407,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                            >> 0x00000025U)))),2);
    bufp->chgBit(oldp+408,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+409,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                          >> 0x00000023U)))));
    bufp->chgIData(oldp+410,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                      >> 3U))),32);
    bufp->chgCData(oldp+411,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                            >> 1U)))),2);
    bufp->chgBit(oldp+412,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o))));
    bufp->chgSData(oldp+413,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+414,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+415,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+416,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+417,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+418,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+419,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+420,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+421,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+422,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+423,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+424,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+425,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+426,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+427,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+428,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+429,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+430,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+431,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+432,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+433,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+434,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+435,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+436,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+437,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+438,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+439,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+440,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw))));
    bufp->chgBit(oldp+441,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+442,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+443,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+444,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+445,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+446,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+447,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+448,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+449,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg)),8);
    bufp->chgBit(oldp+450,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+451,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+452,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+453,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                      >> 4U))),32);
    bufp->chgCData(oldp+454,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req))),4);
    bufp->chgIData(oldp+455,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_rsp 
                                      >> 2U))),32);
    bufp->chgBit(oldp+456,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_rsp 
                                          >> 1U)))));
    bufp->chgBit(oldp+457,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_rsp))));
    bufp->chgBit(oldp+458,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__clk_i));
    bufp->chgBit(oldp+459,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni));
    bufp->chgCData(oldp+460,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                     >> 0x00000034U)))),5);
    bufp->chgCData(oldp+461,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                            >> 0x00000031U)))),3);
    bufp->chgBit(oldp+462,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 0x00000030U)))));
    bufp->chgIData(oldp+463,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                      >> 0x00000010U))),32);
    bufp->chgCData(oldp+464,((0x0000000fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                     >> 0x0000000cU)))),4);
    bufp->chgBit(oldp+465,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 0x0000000bU)))));
    bufp->chgBit(oldp+466,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 0x0000000aU)))));
    bufp->chgCData(oldp+467,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                     >> 5U)))),5);
    bufp->chgCData(oldp+468,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                            >> 2U)))),3);
    bufp->chgBit(oldp+469,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                          >> 1U)))));
    bufp->chgBit(oldp+470,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i))));
    bufp->chgBit(oldp+471,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+472,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000027U)))));
    bufp->chgCData(oldp+473,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                            >> 0x00000025U)))),2);
    bufp->chgBit(oldp+474,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+475,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                          >> 0x00000023U)))));
    bufp->chgIData(oldp+476,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                      >> 3U))),32);
    bufp->chgCData(oldp+477,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                            >> 1U)))),2);
    bufp->chgBit(oldp+478,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o))));
    bufp->chgBit(oldp+479,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+480,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+481,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+482,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                      >> 4U))),32);
    bufp->chgCData(oldp+483,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o))),4);
    bufp->chgIData(oldp+484,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                      >> 2U))),32);
    bufp->chgBit(oldp+485,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                          >> 1U)))));
    bufp->chgBit(oldp+486,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i))));
    bufp->chgBit(oldp+487,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full));
    bufp->chgBit(oldp+488,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty));
    bufp->chgCData(oldp+489,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+490,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                      >> 4U))),32);
    bufp->chgCData(oldp+491,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in))),4);
    bufp->chgCData(oldp+492,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+493,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                      >> 4U))),32);
    bufp->chgCData(oldp+494,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out))),4);
    bufp->chgBit(oldp+495,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push));
    bufp->chgBit(oldp+496,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop));
    bufp->chgBit(oldp+497,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full));
    bufp->chgBit(oldp+498,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty));
    bufp->chgBit(oldp+499,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in));
    bufp->chgBit(oldp+500,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out));
    bufp->chgBit(oldp+501,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push));
    bufp->chgBit(oldp+502,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop));
    bufp->chgBit(oldp+503,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full));
    bufp->chgBit(oldp+504,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty));
    bufp->chgCData(oldp+505,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_in),5);
    bufp->chgCData(oldp+506,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out),5);
    bufp->chgBit(oldp+507,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push));
    bufp->chgBit(oldp+508,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop));
    bufp->chgBit(oldp+509,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full));
    bufp->chgBit(oldp+510,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty));
    bufp->chgIData(oldp+511,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                                      >> 1U))),32);
    bufp->chgBit(oldp+512,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in))));
    bufp->chgIData(oldp+513,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                      >> 1U))),32);
    bufp->chgBit(oldp+514,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out))));
    bufp->chgBit(oldp+515,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push));
    bufp->chgBit(oldp+516,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop));
    bufp->chgCData(oldp+517,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+518,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req))));
    bufp->chgCData(oldp+519,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+520,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req))));
    bufp->chgCData(oldp+521,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+522,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req))));
    bufp->chgBit(oldp+523,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid));
    bufp->chgBit(oldp+524,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid));
    bufp->chgBit(oldp+525,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready));
    bufp->chgBit(oldp+526,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready));
    bufp->chgBit(oldp+527,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__clk_i));
    bufp->chgBit(oldp+528,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni));
    bufp->chgBit(oldp+529,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o));
    bufp->chgBit(oldp+530,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o));
    bufp->chgBit(oldp+531,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o));
    bufp->chgCData(oldp+532,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_i),5);
    bufp->chgBit(oldp+533,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i));
    bufp->chgCData(oldp+534,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o),5);
    bufp->chgBit(oldp+535,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i));
    bufp->chgBit(oldp+536,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock));
    bufp->chgBit(oldp+537,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n));
    bufp->chgBit(oldp+538,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q));
    bufp->chgBit(oldp+539,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n));
    bufp->chgBit(oldp+540,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q));
    bufp->chgCData(oldp+541,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+542,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q),2);
    bufp->chgCData(oldp+543,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                                             >> 5U))),5);
    bufp->chgCData(oldp+544,((0x0000001fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n))),5);
    Vtop___024root__trace_chg_dtype____2(vlSelf, bufp, 545, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q);
    bufp->chgBit(oldp+547,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__clk_i));
    bufp->chgBit(oldp+548,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni));
    bufp->chgBit(oldp+549,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o));
    bufp->chgBit(oldp+550,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o));
    bufp->chgBit(oldp+551,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o));
    bufp->chgIData(oldp+552,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                                      >> 1U))),32);
    bufp->chgBit(oldp+553,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i))));
    bufp->chgBit(oldp+554,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i));
    bufp->chgIData(oldp+555,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                                      >> 1U))),32);
    bufp->chgBit(oldp+556,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o))));
    bufp->chgBit(oldp+557,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i));
    bufp->chgBit(oldp+558,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock));
    bufp->chgBit(oldp+559,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n));
    bufp->chgBit(oldp+560,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q));
    bufp->chgBit(oldp+561,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n));
    bufp->chgBit(oldp+562,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q));
    bufp->chgCData(oldp+563,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+564,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q),2);
    bufp->chgIData(oldp+565,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
                               << 0x0000001eU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                                  >> 2U))),32);
    bufp->chgBit(oldp+566,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                  >> 1U))));
    bufp->chgIData(oldp+567,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                               << 0x0000001fU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
                                                  >> 1U))),32);
    bufp->chgBit(oldp+568,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U])));
    Vtop___024root__trace_chg_dtype____3(vlSelf, bufp, 569, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q);
    bufp->chgBit(oldp+573,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__clk_i));
    bufp->chgBit(oldp+574,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni));
    bufp->chgBit(oldp+575,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o));
    bufp->chgBit(oldp+576,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o));
    bufp->chgBit(oldp+577,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o));
    bufp->chgCData(oldp+578,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+579,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+580,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i))),4);
    bufp->chgBit(oldp+581,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i));
    bufp->chgCData(oldp+582,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+583,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                      >> 4U))),32);
    bufp->chgCData(oldp+584,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o))),4);
    bufp->chgBit(oldp+585,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i));
    bufp->chgBit(oldp+586,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock));
    bufp->chgBit(oldp+587,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n));
    bufp->chgBit(oldp+588,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q));
    bufp->chgBit(oldp+589,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n));
    bufp->chgBit(oldp+590,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q));
    bufp->chgCData(oldp+591,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+592,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q),2);
    bufp->chgCData(oldp+593,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                             >> 0x0000000dU))),5);
    bufp->chgIData(oldp+594,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                               << 0x00000013U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                                  >> 0x0000000dU))),32);
    bufp->chgCData(oldp+595,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                             >> 9U))),4);
    bufp->chgCData(oldp+596,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                             >> 4U))),5);
    bufp->chgIData(oldp+597,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                               << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                                                  >> 4U))),32);
    bufp->chgCData(oldp+598,((0x0000000fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U])),4);
    Vtop___024root__trace_chg_dtype____4(vlSelf, bufp, 599, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q);
    bufp->chgBit(oldp+605,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__clk_i));
    bufp->chgBit(oldp+606,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni));
    bufp->chgBit(oldp+607,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o));
    bufp->chgBit(oldp+608,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o));
    bufp->chgBit(oldp+609,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o));
    bufp->chgBit(oldp+610,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i));
    bufp->chgBit(oldp+611,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i));
    bufp->chgBit(oldp+612,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o));
    bufp->chgBit(oldp+613,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i));
    bufp->chgBit(oldp+614,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock));
    bufp->chgBit(oldp+615,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n));
    bufp->chgBit(oldp+616,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q));
    bufp->chgBit(oldp+617,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n));
    bufp->chgBit(oldp+618,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q));
    bufp->chgCData(oldp+619,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n),2);
    bufp->chgCData(oldp+620,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q),2);
    bufp->chgCData(oldp+621,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n),2);
    bufp->chgCData(oldp+622,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q),2);
    bufp->chgBit(oldp+623,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__clk_i));
    bufp->chgBit(oldp+624,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni));
    bufp->chgCData(oldp+625,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                             >> 7U))),5);
    bufp->chgBit(oldp+626,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                  >> 6U))));
    bufp->chgCData(oldp+627,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+628,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i))));
    bufp->chgCData(oldp+629,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i),2);
    bufp->chgCData(oldp+630,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o),2);
    bufp->chgCData(oldp+631,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+632,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o))));
    bufp->chgBit(oldp+633,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o));
    bufp->chgBit(oldp+634,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i));
    bufp->chgBit(oldp+635,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__clk_i));
    bufp->chgBit(oldp+636,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni));
    bufp->chgCData(oldp+637,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                             >> 7U))),5);
    bufp->chgBit(oldp+638,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                  >> 6U))));
    bufp->chgCData(oldp+639,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+640,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i))));
    bufp->chgCData(oldp+641,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i),2);
    bufp->chgCData(oldp+642,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o),2);
    bufp->chgCData(oldp+643,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+644,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o))));
    bufp->chgBit(oldp+645,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o));
    bufp->chgBit(oldp+646,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i));
    bufp->chgBit(oldp+647,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__clk_i));
    bufp->chgBit(oldp+648,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni));
    bufp->chgCData(oldp+649,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i),2);
    bufp->chgCData(oldp+650,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o),2);
    bufp->chgCData(oldp+651,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                             >> 7U))),5);
    bufp->chgBit(oldp+652,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                  >> 6U))));
    bufp->chgCData(oldp+653,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+654,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i))));
    bufp->chgBit(oldp+655,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o));
    bufp->chgBit(oldp+656,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i));
    bufp->chgCData(oldp+657,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+658,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o))));
    bufp->chgBit(oldp+659,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o));
    bufp->chgBit(oldp+660,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes));
    bufp->chgCData(oldp+661,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
                                             >> 1U))),5);
    bufp->chgBit(oldp+662,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes))));
    bufp->chgBit(oldp+663,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes));
    bufp->chgBit(oldp+664,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes));
    bufp->chgBit(oldp+665,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q));
    bufp->chgCData(oldp+666,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d),2);
    bufp->chgBit(oldp+667,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d));
    bufp->chgCData(oldp+668,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),2);
    bufp->chgCData(oldp+669,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),2);
    bufp->chgBit(oldp+670,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx));
    bufp->chgBit(oldp+671,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx));
    bufp->chgBit(oldp+672,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx));
    bufp->chgBit(oldp+673,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty));
    bufp->chgBit(oldp+674,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_empty));
    bufp->chgCData(oldp+675,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i),2);
    bufp->chgBit(oldp+676,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o));
    bufp->chgBit(oldp+677,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o));
    Vtop___024root__trace_chg_dtype____5(vlSelf, bufp, 678, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_lut);
    bufp->chgCData(oldp+680,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->chgBit(oldp+681,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
                                  >> 1U))));
    bufp->chgBit(oldp+682,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))));
    bufp->chgCData(oldp+683,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->chgCData(oldp+684,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i),2);
    bufp->chgBit(oldp+685,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o));
    bufp->chgBit(oldp+686,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o));
    Vtop___024root__trace_chg_dtype____5(vlSelf, bufp, 687, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_lut);
    bufp->chgCData(oldp+689,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->chgBit(oldp+690,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
                                  >> 1U))));
    bufp->chgBit(oldp+691,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes))));
    bufp->chgCData(oldp+692,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->chgBit(oldp+693,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d));
    bufp->chgBit(oldp+694,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
    bufp->chgCData(oldp+695,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),2);
    bufp->chgBit(oldp+696,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
    bufp->chgBit(oldp+697,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->chgBit(oldp+698,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->chgBit(oldp+699,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+700,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+701,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+702,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+703,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+704,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+705,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+706,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->chgSData(oldp+707,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+708,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+709,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+710,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+711,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+712,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+713,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+714,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+715,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+716,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+717,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+718,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+719,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+720,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+721,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+722,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+723,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+724,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+725,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+726,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+727,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+728,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+729,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+730,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+731,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+732,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+733,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+734,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw))));
    bufp->chgBit(oldp+735,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+736,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+737,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+738,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+739,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+740,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+741,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+742,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+743,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg)),8);
    bufp->chgBit(oldp+744,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->chgBit(oldp+745,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->chgBit(oldp+746,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->chgCData(oldp+747,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr),5);
    bufp->chgIData(oldp+748,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->chgCData(oldp+749,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->chgIData(oldp+750,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->chgBit(oldp+751,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->chgBit(oldp+752,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->chgBit(oldp+753,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->chgIData(oldp+754,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+755,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->chgCData(oldp+756,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check),6);
    bufp->chgBit(oldp+757,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q));
    bufp->chgBit(oldp+758,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we));
    bufp->chgBit(oldp+759,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs));
    bufp->chgBit(oldp+760,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd));
    bufp->chgBit(oldp+761,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs));
    bufp->chgBit(oldp+762,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd));
    bufp->chgBit(oldp+763,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs));
    bufp->chgBit(oldp+764,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd));
    bufp->chgBit(oldp+765,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs));
    bufp->chgBit(oldp+766,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd));
    bufp->chgBit(oldp+767,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs));
    bufp->chgBit(oldp+768,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd));
    bufp->chgBit(oldp+769,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs));
    bufp->chgBit(oldp+770,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd));
    bufp->chgBit(oldp+771,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs));
    bufp->chgBit(oldp+772,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd));
    bufp->chgSData(oldp+773,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs),16);
    bufp->chgSData(oldp+774,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd),16);
    bufp->chgBit(oldp+775,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re));
    bufp->chgBit(oldp+776,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs));
    bufp->chgBit(oldp+777,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs));
    bufp->chgBit(oldp+778,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs));
    bufp->chgBit(oldp+779,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs));
    bufp->chgBit(oldp+780,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs));
    bufp->chgBit(oldp+781,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs));
    bufp->chgBit(oldp+782,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re));
    bufp->chgCData(oldp+783,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs),8);
    bufp->chgBit(oldp+784,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we));
    bufp->chgCData(oldp+785,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd),8);
    bufp->chgBit(oldp+786,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we));
    bufp->chgBit(oldp+787,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd));
    bufp->chgBit(oldp+788,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd));
    bufp->chgBit(oldp+789,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re));
    bufp->chgCData(oldp+790,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs),8);
    bufp->chgCData(oldp+791,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs),8);
    bufp->chgBit(oldp+792,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe));
    bufp->chgBit(oldp+793,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we));
    bufp->chgBit(oldp+794,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe));
    bufp->chgCData(oldp+795,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we),2);
    bufp->chgCData(oldp+796,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit),6);
    bufp->chgBit(oldp+797,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->chgBit(oldp+798,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->chgBit(oldp+799,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i));
    bufp->chgBit(oldp+800,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni));
    bufp->chgBit(oldp+801,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we));
    bufp->chgBit(oldp+802,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd));
    bufp->chgBit(oldp+803,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe));
    bufp->chgBit(oldp+804,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q));
    bufp->chgBit(oldp+805,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds));
    bufp->chgBit(oldp+806,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs));
    bufp->chgBit(oldp+807,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en));
    bufp->chgBit(oldp+808,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data));
    bufp->chgBit(oldp+809,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+810,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+811,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+812,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+813,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+814,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+815,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i));
    bufp->chgBit(oldp+816,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni));
    bufp->chgBit(oldp+817,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we));
    bufp->chgSData(oldp+818,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd),16);
    bufp->chgBit(oldp+819,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe));
    bufp->chgSData(oldp+820,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q),16);
    bufp->chgSData(oldp+821,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds),16);
    bufp->chgSData(oldp+822,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs),16);
    bufp->chgBit(oldp+823,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en));
    bufp->chgSData(oldp+824,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data),16);
    bufp->chgBit(oldp+825,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we));
    bufp->chgSData(oldp+826,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd),16);
    bufp->chgSData(oldp+827,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q),16);
    bufp->chgBit(oldp+828,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgSData(oldp+829,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data),16);
    bufp->chgSData(oldp+830,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),16);
    bufp->chgBit(oldp+831,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i));
    bufp->chgBit(oldp+832,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni));
    bufp->chgBit(oldp+833,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we));
    bufp->chgBit(oldp+834,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd));
    bufp->chgBit(oldp+835,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe));
    bufp->chgBit(oldp+836,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q));
    bufp->chgBit(oldp+837,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds));
    bufp->chgBit(oldp+838,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs));
    bufp->chgBit(oldp+839,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en));
    bufp->chgBit(oldp+840,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data));
    bufp->chgBit(oldp+841,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+842,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+843,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+844,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+845,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+846,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+847,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i));
    bufp->chgBit(oldp+848,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni));
    bufp->chgBit(oldp+849,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we));
    bufp->chgBit(oldp+850,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd));
    bufp->chgBit(oldp+851,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe));
    bufp->chgBit(oldp+852,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q));
    bufp->chgBit(oldp+853,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds));
    bufp->chgBit(oldp+854,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs));
    bufp->chgBit(oldp+855,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en));
    bufp->chgBit(oldp+856,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data));
    bufp->chgBit(oldp+857,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+858,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+859,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+860,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+861,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+862,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+863,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i));
    bufp->chgBit(oldp+864,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni));
    bufp->chgBit(oldp+865,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we));
    bufp->chgBit(oldp+866,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd));
    bufp->chgBit(oldp+867,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe));
    bufp->chgBit(oldp+868,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q));
    bufp->chgBit(oldp+869,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds));
    bufp->chgBit(oldp+870,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs));
    bufp->chgBit(oldp+871,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en));
    bufp->chgBit(oldp+872,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data));
    bufp->chgBit(oldp+873,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+874,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+875,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+876,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+877,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+878,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+879,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i));
    bufp->chgBit(oldp+880,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni));
    bufp->chgBit(oldp+881,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we));
    bufp->chgBit(oldp+882,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd));
    bufp->chgBit(oldp+883,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe));
    bufp->chgBit(oldp+884,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q));
    bufp->chgBit(oldp+885,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds));
    bufp->chgBit(oldp+886,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs));
    bufp->chgBit(oldp+887,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en));
    bufp->chgBit(oldp+888,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data));
    bufp->chgBit(oldp+889,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+890,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+891,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+892,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+893,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+894,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+895,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i));
    bufp->chgBit(oldp+896,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni));
    bufp->chgBit(oldp+897,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we));
    bufp->chgBit(oldp+898,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd));
    bufp->chgBit(oldp+899,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe));
    bufp->chgBit(oldp+900,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q));
    bufp->chgBit(oldp+901,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds));
    bufp->chgBit(oldp+902,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs));
    bufp->chgBit(oldp+903,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en));
    bufp->chgBit(oldp+904,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data));
    bufp->chgBit(oldp+905,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+906,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+907,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+908,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+909,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+910,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+911,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i));
    bufp->chgBit(oldp+912,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni));
    bufp->chgBit(oldp+913,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we));
    bufp->chgBit(oldp+914,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd));
    bufp->chgBit(oldp+915,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe));
    bufp->chgBit(oldp+916,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q));
    bufp->chgBit(oldp+917,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds));
    bufp->chgBit(oldp+918,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs));
    bufp->chgBit(oldp+919,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en));
    bufp->chgBit(oldp+920,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data));
    bufp->chgBit(oldp+921,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+922,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+923,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+924,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+925,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+926,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+927,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i));
    bufp->chgBit(oldp+928,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni));
    bufp->chgBit(oldp+929,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i));
    bufp->chgBit(oldp+930,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o));
    bufp->chgBit(oldp+931,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i));
    bufp->chgBit(oldp+932,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni));
    bufp->chgBit(oldp+933,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we));
    bufp->chgBit(oldp+934,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd));
    bufp->chgBit(oldp+935,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe));
    bufp->chgBit(oldp+936,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q));
    bufp->chgBit(oldp+937,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds));
    bufp->chgBit(oldp+938,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs));
    bufp->chgBit(oldp+939,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en));
    bufp->chgBit(oldp+940,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data));
    bufp->chgBit(oldp+941,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+942,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+943,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+944,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+945,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+946,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+947,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i));
    bufp->chgBit(oldp+948,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni));
    bufp->chgBit(oldp+949,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we));
    bufp->chgBit(oldp+950,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd));
    bufp->chgBit(oldp+951,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe));
    bufp->chgBit(oldp+952,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q));
    bufp->chgBit(oldp+953,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds));
    bufp->chgBit(oldp+954,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs));
    bufp->chgBit(oldp+955,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en));
    bufp->chgBit(oldp+956,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data));
    bufp->chgBit(oldp+957,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+958,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+959,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+960,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+961,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+962,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+963,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re));
    bufp->chgCData(oldp+964,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d),8);
    bufp->chgBit(oldp+965,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre));
    bufp->chgCData(oldp+966,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds),8);
    bufp->chgCData(oldp+967,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs),8);
    bufp->chgBit(oldp+968,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re));
    bufp->chgCData(oldp+969,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d),8);
    bufp->chgBit(oldp+970,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre));
    bufp->chgCData(oldp+971,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds),8);
    bufp->chgCData(oldp+972,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs),8);
    bufp->chgBit(oldp+973,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->chgBit(oldp+974,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->chgCData(oldp+975,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),6);
    bufp->chgBit(oldp+976,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->chgBit(oldp+977,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->chgCData(oldp+978,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),6);
    bufp->chgCData(oldp+979,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),6);
    bufp->chgCData(oldp+980,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),6);
    bufp->chgCData(oldp+981,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),6);
    bufp->chgBit(oldp+982,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->chgBit(oldp+983,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->chgCData(oldp+984,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),6);
    bufp->chgBit(oldp+985,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->chgBit(oldp+986,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->chgSData(oldp+987,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),15);
    bufp->chgSData(oldp+988,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),15);
    bufp->chgSData(oldp+989,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),15);
    bufp->chgBit(oldp+990,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re));
    bufp->chgCData(oldp+991,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d),8);
    bufp->chgBit(oldp+992,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre));
    bufp->chgCData(oldp+993,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds),8);
    bufp->chgCData(oldp+994,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs),8);
    bufp->chgBit(oldp+995,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re));
    bufp->chgBit(oldp+996,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d));
    bufp->chgBit(oldp+997,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre));
    bufp->chgBit(oldp+998,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds));
    bufp->chgBit(oldp+999,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs));
    bufp->chgBit(oldp+1000,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re));
    bufp->chgBit(oldp+1001,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d));
    bufp->chgBit(oldp+1002,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre));
    bufp->chgBit(oldp+1003,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds));
    bufp->chgBit(oldp+1004,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs));
    bufp->chgBit(oldp+1005,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re));
    bufp->chgBit(oldp+1006,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d));
    bufp->chgBit(oldp+1007,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre));
    bufp->chgBit(oldp+1008,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds));
    bufp->chgBit(oldp+1009,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs));
    bufp->chgBit(oldp+1010,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re));
    bufp->chgBit(oldp+1011,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d));
    bufp->chgBit(oldp+1012,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre));
    bufp->chgBit(oldp+1013,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds));
    bufp->chgBit(oldp+1014,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs));
    bufp->chgBit(oldp+1015,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re));
    bufp->chgBit(oldp+1016,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d));
    bufp->chgBit(oldp+1017,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre));
    bufp->chgBit(oldp+1018,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds));
    bufp->chgBit(oldp+1019,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs));
    bufp->chgBit(oldp+1020,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re));
    bufp->chgBit(oldp+1021,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d));
    bufp->chgBit(oldp+1022,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre));
    bufp->chgBit(oldp+1023,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds));
    bufp->chgBit(oldp+1024,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs));
    bufp->chgBit(oldp+1025,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i));
    bufp->chgBit(oldp+1026,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni));
    bufp->chgBit(oldp+1027,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we));
    bufp->chgCData(oldp+1028,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd),8);
    bufp->chgBit(oldp+1029,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe));
    bufp->chgCData(oldp+1030,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q),8);
    bufp->chgCData(oldp+1031,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds),8);
    bufp->chgCData(oldp+1032,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs),8);
    bufp->chgBit(oldp+1033,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en));
    bufp->chgCData(oldp+1034,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data),8);
    bufp->chgBit(oldp+1035,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+1036,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->chgCData(oldp+1037,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q),8);
    bufp->chgBit(oldp+1038,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+1039,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->chgCData(oldp+1040,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->chgBit(oldp+1041,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i));
    bufp->chgBit(oldp+1042,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni));
    bufp->chgBit(oldp+1043,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i));
    bufp->chgBit(oldp+1044,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o));
    Vtop___024root__trace_chg_dtype____6(vlSelf, bufp, 1045, vlSymsp->TOP__uart_reg_pkg.UART_PERMIT);
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

void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const SData/*9:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,((0x0000001fU & (__VdtypeVar 
                                           >> 5U))),5);
    bufp->chgCData(oldp+1,((0x0000001fU & __VdtypeVar)),5);
}

void Vtop___024root__trace_chg_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(VL_SEL_IWII(66, __VdtypeVar, 0x00000022U, 32)),32);
    bufp->chgBit(oldp+1,((1U & VL_BITSEL_IWII(66, __VdtypeVar, 0x00000021U))));
    bufp->chgIData(oldp+2,(VL_SEL_IWII(66, __VdtypeVar, 1U, 32)),32);
    bufp->chgBit(oldp+3,((1U & VL_BITSEL_IWII(66, __VdtypeVar, 0U))));
}

void Vtop___024root__trace_chg_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*81:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,((0x0000001fU & VL_SEL_IWII(82, 
                                                      __VdtypeVar, 0x0000004dU, 5))),5);
    bufp->chgIData(oldp+1,(VL_SEL_IWII(82, __VdtypeVar, 0x0000002dU, 32)),32);
    bufp->chgCData(oldp+2,((0x0000000fU & VL_SEL_IWII(82, 
                                                      __VdtypeVar, 0x00000029U, 4))),4);
    bufp->chgCData(oldp+3,((0x0000001fU & VL_SEL_IWII(82, 
                                                      __VdtypeVar, 0x00000024U, 5))),5);
    bufp->chgIData(oldp+4,(VL_SEL_IWII(82, __VdtypeVar, 4U, 32)),32);
    bufp->chgCData(oldp+5,((0x0000000fU & VL_SEL_IWII(82, 
                                                      __VdtypeVar, 0U, 4))),4);
}

void Vtop___024root__trace_chg_dtype____5(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,((1U & (__VdtypeVar >> 1U))));
    bufp->chgBit(oldp+1,((1U & __VdtypeVar)));
}

void Vtop___024root__trace_chg_dtype____6(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 6>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____6\n"); );
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
