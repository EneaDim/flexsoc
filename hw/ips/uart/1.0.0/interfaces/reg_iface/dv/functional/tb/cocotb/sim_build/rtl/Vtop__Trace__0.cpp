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
    bufp->chgBit(oldp+4,((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                        >> 0x0000002aU)))));
    bufp->chgBit(oldp+5,((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                        >> 0x00000029U)))));
    bufp->chgCData(oldp+6,((0x0000001fU & (IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                                   >> 0x00000024U)))),5);
    bufp->chgIData(oldp+7,((IData)((vlSelfRef.uart_tb__DOT__reg_req_i 
                                    >> 4U))),32);
    bufp->chgCData(oldp+8,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+9,((IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                    >> 2U))),32);
    bufp->chgBit(oldp+10,((1U & (IData)((vlSelfRef.uart_tb__DOT__reg_rsp_o 
                                         >> 1U)))));
    bufp->chgBit(oldp+11,((1U & (IData)(vlSelfRef.uart_tb__DOT__reg_rsp_o))));
    bufp->chgBit(oldp+12,(vlSelfRef.uart_tb__DOT__reg_req_valid));
    bufp->chgBit(oldp+13,(vlSelfRef.uart_tb__DOT__reg_req_write));
    bufp->chgCData(oldp+14,(vlSelfRef.uart_tb__DOT__reg_req_addr),5);
    bufp->chgIData(oldp+15,(vlSelfRef.uart_tb__DOT__reg_req_wdata),32);
    bufp->chgCData(oldp+16,(vlSelfRef.uart_tb__DOT__reg_req_wstrb),4);
    bufp->chgBit(oldp+17,(vlSelfRef.uart_tb__DOT__reg_rsp_ready));
    bufp->chgBit(oldp+18,(vlSelfRef.uart_tb__DOT__reg_rsp_error));
    bufp->chgIData(oldp+19,(vlSelfRef.uart_tb__DOT__reg_rsp_rdata),32);
    bufp->chgBit(oldp+20,(vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i));
    bufp->chgBit(oldp+21,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni));
    bufp->chgBit(oldp+22,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i));
    bufp->chgBit(oldp+23,(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o));
    bufp->chgBit(oldp+24,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                         >> 0x0000002aU)))));
    bufp->chgBit(oldp+25,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                         >> 0x00000029U)))));
    bufp->chgCData(oldp+26,((0x0000001fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                                    >> 0x00000024U)))),5);
    bufp->chgIData(oldp+27,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i 
                                     >> 4U))),32);
    bufp->chgCData(oldp+28,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+29,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                     >> 2U))),32);
    bufp->chgBit(oldp+30,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o 
                                         >> 1U)))));
    bufp->chgBit(oldp+31,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rsp_o))));
    bufp->chgSData(oldp+32,((0x0000ffffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 0x00000029U)))),16);
    bufp->chgBit(oldp+33,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+34,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000027U)))));
    bufp->chgBit(oldp+35,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000026U)))));
    bufp->chgBit(oldp+36,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000025U)))));
    bufp->chgBit(oldp+37,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000024U)))));
    bufp->chgBit(oldp+38,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000023U)))));
    bufp->chgBit(oldp+39,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000022U)))));
    bufp->chgBit(oldp+40,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000021U)))));
    bufp->chgBit(oldp+41,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000020U)))));
    bufp->chgBit(oldp+42,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001fU)))));
    bufp->chgBit(oldp+43,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001eU)))));
    bufp->chgBit(oldp+44,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001dU)))));
    bufp->chgBit(oldp+45,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001cU)))));
    bufp->chgBit(oldp+46,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001bU)))));
    bufp->chgBit(oldp+47,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000001aU)))));
    bufp->chgBit(oldp+48,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000019U)))));
    bufp->chgBit(oldp+49,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000018U)))));
    bufp->chgBit(oldp+50,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000017U)))));
    bufp->chgBit(oldp+51,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x00000016U)))));
    bufp->chgCData(oldp+52,((0x000000ffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+53,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 0x0000000dU)))));
    bufp->chgCData(oldp+54,((0x000000ffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                    >> 5U)))),8);
    bufp->chgBit(oldp+55,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 4U)))));
    bufp->chgBit(oldp+56,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 3U)))));
    bufp->chgBit(oldp+57,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 2U)))));
    bufp->chgBit(oldp+58,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                         >> 1U)))));
    bufp->chgBit(oldp+59,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw))));
    bufp->chgBit(oldp+60,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001dU))));
    bufp->chgBit(oldp+61,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001cU))));
    bufp->chgBit(oldp+62,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001bU))));
    bufp->chgBit(oldp+63,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x0000001aU))));
    bufp->chgBit(oldp+64,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x00000019U))));
    bufp->chgBit(oldp+65,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                 >> 0x00000018U))));
    bufp->chgCData(oldp+66,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                            >> 0x00000010U))),8);
    bufp->chgCData(oldp+67,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                            >> 8U))),8);
    bufp->chgCData(oldp+68,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg)),8);
    bufp->chgBit(oldp+69,(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni));
    bufp->chgBit(oldp+70,(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni));
    bufp->chgBit(oldp+71,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+72,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+73,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+74,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+75,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq));
    bufp->chgBit(oldp+76,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+77,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+78,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+79,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+80,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+81,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+82,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+83,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+84,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+85,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+86,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+87,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq));
    bufp->chgBit(oldp+88,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+89,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+90,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+91,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+92,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+93,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+94,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+95,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i));
    bufp->chgBit(oldp+96,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni));
    bufp->chgSData(oldp+97,((0x0000ffffU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                    >> 0x00000029U)))),16);
    bufp->chgBit(oldp+98,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                         >> 0x00000028U)))));
    bufp->chgBit(oldp+99,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                         >> 0x00000027U)))));
    bufp->chgBit(oldp+100,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+101,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+102,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+103,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+104,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+105,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+106,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+107,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+108,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+109,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+110,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+111,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+112,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+113,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+114,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+115,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+116,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+117,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+118,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+119,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+120,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+121,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+122,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+123,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+124,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw))));
    bufp->chgBit(oldp+125,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+126,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+127,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+128,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+129,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+130,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+131,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+132,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+133,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg)),8);
    bufp->chgBit(oldp+134,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i));
    bufp->chgBit(oldp+135,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o));
    bufp->chgSData(oldp+136,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q),16);
    bufp->chgCData(oldp+137,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata),8);
    bufp->chgBit(oldp+138,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16));
    bufp->chgBit(oldp+139,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud));
    bufp->chgCData(oldp+140,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth),4);
    bufp->chgCData(oldp+141,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth),5);
    bufp->chgCData(oldp+142,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q),5);
    bufp->chgIData(oldp+143,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d),24);
    bufp->chgIData(oldp+144,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q),24);
    bufp->chgIData(oldp+145,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val),24);
    bufp->chgBit(oldp+146,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed));
    bufp->chgBit(oldp+147,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en));
    bufp->chgBit(oldp+148,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable));
    bufp->chgBit(oldp+149,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback));
    bufp->chgBit(oldp+150,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback));
    bufp->chgBit(oldp+151,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable));
    bufp->chgBit(oldp+152,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst));
    bufp->chgBit(oldp+153,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst));
    bufp->chgCData(oldp+154,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data),8);
    bufp->chgBit(oldp+155,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready));
    bufp->chgBit(oldp+156,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid));
    bufp->chgBit(oldp+157,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready));
    bufp->chgBit(oldp+158,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle));
    bufp->chgBit(oldp+159,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out));
    bufp->chgBit(oldp+160,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q));
    bufp->chgCData(oldp+161,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data),8);
    bufp->chgBit(oldp+162,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
    bufp->chgBit(oldp+163,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid));
    bufp->chgBit(oldp+164,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid));
    bufp->chgBit(oldp+165,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready));
    bufp->chgBit(oldp+166,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle));
    bufp->chgBit(oldp+167,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync));
    bufp->chgBit(oldp+168,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in));
    bufp->chgBit(oldp+169,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err));
    bufp->chgCData(oldp+170,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d),5);
    bufp->chgCData(oldp+171,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q),5);
    bufp->chgBit(oldp+172,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err));
    bufp->chgBit(oldp+173,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char));
    bufp->chgBit(oldp+174,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark));
    bufp->chgBit(oldp+175,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty));
    bufp->chgBit(oldp+176,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark));
    bufp->chgBit(oldp+177,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done));
    bufp->chgBit(oldp+178,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow));
    bufp->chgBit(oldp+179,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err));
    bufp->chgBit(oldp+180,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err));
    bufp->chgBit(oldp+181,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout));
    bufp->chgBit(oldp+182,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err));
    bufp->chgBit(oldp+183,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q));
    bufp->chgBit(oldp+184,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni));
    bufp->chgBit(oldp+185,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni));
    bufp->chgBit(oldp+186,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni));
    bufp->chgBit(oldp+187,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop));
    bufp->chgCData(oldp+188,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata),8);
    bufp->chgBit(oldp+189,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid));
    bufp->chgIData(oldp+190,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q),17);
    bufp->chgBit(oldp+191,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1));
    bufp->chgBit(oldp+192,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2));
    bufp->chgBit(oldp+193,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx));
    bufp->chgBit(oldp+194,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj));
    bufp->chgBit(oldp+195,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i));
    bufp->chgBit(oldp+196,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni));
    bufp->chgBit(oldp+197,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i));
    bufp->chgBit(oldp+198,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o));
    bufp->chgBit(oldp+199,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o));
    bufp->chgBit(oldp+200,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq));
    bufp->chgBit(oldp+201,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+202,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+203,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+204,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+205,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+206,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+207,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+208,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+209,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+210,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+211,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+212,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+213,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+214,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+215,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+216,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+217,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+218,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i));
    bufp->chgBit(oldp+219,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni));
    bufp->chgBit(oldp+220,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i));
    bufp->chgBit(oldp+221,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i));
    bufp->chgBit(oldp+222,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o));
    bufp->chgCData(oldp+223,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i),8);
    bufp->chgBit(oldp+224,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o));
    bufp->chgBit(oldp+225,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i));
    bufp->chgCData(oldp+226,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o),8);
    bufp->chgBit(oldp+227,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o));
    bufp->chgCData(oldp+228,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o),5);
    bufp->chgCData(oldp+229,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),4);
    bufp->chgCData(oldp+230,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),4);
    bufp->chgBit(oldp+231,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+232,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+233,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->chgBit(oldp+234,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->chgBit(oldp+235,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 236, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->chgCData(oldp+252,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->chgCData(oldp+253,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->chgBit(oldp+254,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->chgBit(oldp+255,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->chgBit(oldp+256,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->chgBit(oldp+257,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->chgBit(oldp+258,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->chgCData(oldp+259,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),4);
    bufp->chgCData(oldp+260,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),4);
    bufp->chgBit(oldp+261,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->chgBit(oldp+262,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->chgCData(oldp+263,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),5);
    bufp->chgCData(oldp+264,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),5);
    bufp->chgCData(oldp+265,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),5);
    bufp->chgCData(oldp+266,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),5);
    bufp->chgCData(oldp+267,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),5);
    bufp->chgBit(oldp+268,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->chgBit(oldp+269,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->chgBit(oldp+270,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->chgBit(oldp+271,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->chgBit(oldp+272,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i));
    bufp->chgBit(oldp+273,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni));
    bufp->chgBit(oldp+274,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i));
    bufp->chgBit(oldp+275,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i));
    bufp->chgBit(oldp+276,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o));
    bufp->chgCData(oldp+277,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i),8);
    bufp->chgBit(oldp+278,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o));
    bufp->chgBit(oldp+279,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i));
    bufp->chgCData(oldp+280,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o),8);
    bufp->chgBit(oldp+281,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o));
    bufp->chgCData(oldp+282,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o),4);
    bufp->chgCData(oldp+283,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),3);
    bufp->chgCData(oldp+284,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),3);
    bufp->chgBit(oldp+285,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->chgBit(oldp+286,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->chgBit(oldp+287,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->chgBit(oldp+288,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->chgBit(oldp+289,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 290, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->chgCData(oldp+298,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->chgCData(oldp+299,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->chgBit(oldp+300,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->chgBit(oldp+301,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->chgBit(oldp+302,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->chgBit(oldp+303,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->chgBit(oldp+304,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->chgCData(oldp+305,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),3);
    bufp->chgCData(oldp+306,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),3);
    bufp->chgBit(oldp+307,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->chgBit(oldp+308,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->chgCData(oldp+309,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),4);
    bufp->chgCData(oldp+310,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),4);
    bufp->chgCData(oldp+311,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),4);
    bufp->chgCData(oldp+312,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),4);
    bufp->chgCData(oldp+313,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),4);
    bufp->chgBit(oldp+314,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->chgBit(oldp+315,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->chgBit(oldp+316,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->chgBit(oldp+317,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->chgBit(oldp+318,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i));
    bufp->chgBit(oldp+319,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni));
    bufp->chgBit(oldp+320,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16));
    bufp->chgBit(oldp+321,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable));
    bufp->chgBit(oldp+322,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd));
    bufp->chgBit(oldp+323,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud));
    bufp->chgBit(oldp+324,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid));
    bufp->chgCData(oldp+325,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data),8);
    bufp->chgBit(oldp+326,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle));
    bufp->chgBit(oldp+327,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err));
    bufp->chgBit(oldp+328,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err));
    bufp->chgBit(oldp+329,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx));
    bufp->chgBit(oldp+330,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    bufp->chgSData(oldp+331,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q),11);
    bufp->chgSData(oldp+332,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d),11);
    bufp->chgCData(oldp+333,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q),4);
    bufp->chgCData(oldp+334,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d),4);
    bufp->chgCData(oldp+335,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q),4);
    bufp->chgCData(oldp+336,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d),4);
    bufp->chgBit(oldp+337,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d));
    bufp->chgBit(oldp+338,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q));
    bufp->chgBit(oldp+339,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d));
    bufp->chgBit(oldp+340,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q));
    bufp->chgBit(oldp+341,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i));
    bufp->chgBit(oldp+342,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni));
    bufp->chgBit(oldp+343,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable));
    bufp->chgBit(oldp+344,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16));
    bufp->chgBit(oldp+345,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable));
    bufp->chgBit(oldp+346,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr));
    bufp->chgBit(oldp+347,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity));
    bufp->chgCData(oldp+348,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data),8);
    bufp->chgBit(oldp+349,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle));
    bufp->chgBit(oldp+350,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx));
    bufp->chgCData(oldp+351,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q),4);
    bufp->chgBit(oldp+352,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q));
    bufp->chgCData(oldp+353,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q),4);
    bufp->chgCData(oldp+354,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d),4);
    bufp->chgSData(oldp+355,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q),11);
    bufp->chgSData(oldp+356,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d),11);
    bufp->chgBit(oldp+357,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q));
    bufp->chgBit(oldp+358,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d));
    bufp->chgBit(oldp+359,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i));
    bufp->chgBit(oldp+360,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni));
    bufp->chgBit(oldp+361,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+362,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+363,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+364,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+365,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+366,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+367,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+368,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg_rsp_o))));
    bufp->chgSData(oldp+369,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+370,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+371,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+372,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+373,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+374,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+375,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+376,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+377,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+378,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+379,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+380,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+381,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+382,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+383,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+384,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+385,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+386,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+387,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+388,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+389,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+390,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+391,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+392,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+393,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+394,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+395,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+396,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw))));
    bufp->chgBit(oldp+397,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+398,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+399,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+400,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+401,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+402,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+403,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+404,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+405,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg)),8);
    bufp->chgBit(oldp+406,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->chgBit(oldp+407,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->chgBit(oldp+408,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x0000002aU)))));
    bufp->chgBit(oldp+409,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgCData(oldp+410,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                     >> 0x00000024U)))),5);
    bufp->chgIData(oldp+411,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+412,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+413,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+414,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+415,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->chgSData(oldp+416,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->chgBit(oldp+417,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->chgBit(oldp+418,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->chgBit(oldp+419,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->chgBit(oldp+420,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->chgBit(oldp+421,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->chgBit(oldp+422,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->chgBit(oldp+423,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->chgBit(oldp+424,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->chgBit(oldp+425,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->chgBit(oldp+426,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->chgBit(oldp+427,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->chgBit(oldp+428,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->chgBit(oldp+429,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->chgBit(oldp+430,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->chgBit(oldp+431,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->chgBit(oldp+432,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->chgBit(oldp+433,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->chgBit(oldp+434,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->chgBit(oldp+435,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->chgCData(oldp+436,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->chgBit(oldp+437,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->chgCData(oldp+438,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->chgBit(oldp+439,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 4U)))));
    bufp->chgBit(oldp+440,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 3U)))));
    bufp->chgBit(oldp+441,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 2U)))));
    bufp->chgBit(oldp+442,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                          >> 1U)))));
    bufp->chgBit(oldp+443,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw))));
    bufp->chgBit(oldp+444,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->chgBit(oldp+445,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->chgBit(oldp+446,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->chgBit(oldp+447,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->chgBit(oldp+448,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->chgBit(oldp+449,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->chgCData(oldp+450,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+451,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                             >> 8U))),8);
    bufp->chgCData(oldp+452,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg)),8);
    bufp->chgBit(oldp+453,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->chgBit(oldp+454,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->chgBit(oldp+455,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->chgCData(oldp+456,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr),5);
    bufp->chgIData(oldp+457,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->chgCData(oldp+458,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->chgIData(oldp+459,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->chgBit(oldp+460,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->chgBit(oldp+461,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->chgBit(oldp+462,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->chgIData(oldp+463,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+464,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->chgCData(oldp+465,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check),6);
    bufp->chgBit(oldp+466,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q));
    bufp->chgBit(oldp+467,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we));
    bufp->chgBit(oldp+468,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs));
    bufp->chgBit(oldp+469,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd));
    bufp->chgBit(oldp+470,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs));
    bufp->chgBit(oldp+471,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd));
    bufp->chgBit(oldp+472,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs));
    bufp->chgBit(oldp+473,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd));
    bufp->chgBit(oldp+474,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs));
    bufp->chgBit(oldp+475,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd));
    bufp->chgBit(oldp+476,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs));
    bufp->chgBit(oldp+477,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd));
    bufp->chgBit(oldp+478,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs));
    bufp->chgBit(oldp+479,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd));
    bufp->chgBit(oldp+480,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs));
    bufp->chgBit(oldp+481,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd));
    bufp->chgSData(oldp+482,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs),16);
    bufp->chgSData(oldp+483,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd),16);
    bufp->chgBit(oldp+484,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re));
    bufp->chgBit(oldp+485,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs));
    bufp->chgBit(oldp+486,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs));
    bufp->chgBit(oldp+487,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs));
    bufp->chgBit(oldp+488,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs));
    bufp->chgBit(oldp+489,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs));
    bufp->chgBit(oldp+490,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs));
    bufp->chgBit(oldp+491,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re));
    bufp->chgCData(oldp+492,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs),8);
    bufp->chgBit(oldp+493,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we));
    bufp->chgCData(oldp+494,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd),8);
    bufp->chgBit(oldp+495,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we));
    bufp->chgBit(oldp+496,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd));
    bufp->chgBit(oldp+497,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd));
    bufp->chgBit(oldp+498,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re));
    bufp->chgCData(oldp+499,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs),8);
    bufp->chgCData(oldp+500,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs),8);
    bufp->chgBit(oldp+501,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe));
    bufp->chgBit(oldp+502,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we));
    bufp->chgBit(oldp+503,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe));
    bufp->chgCData(oldp+504,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we),2);
    bufp->chgCData(oldp+505,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit),6);
    bufp->chgBit(oldp+506,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->chgBit(oldp+507,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->chgBit(oldp+508,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i));
    bufp->chgBit(oldp+509,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni));
    bufp->chgBit(oldp+510,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we));
    bufp->chgBit(oldp+511,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd));
    bufp->chgBit(oldp+512,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe));
    bufp->chgBit(oldp+513,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q));
    bufp->chgBit(oldp+514,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds));
    bufp->chgBit(oldp+515,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs));
    bufp->chgBit(oldp+516,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en));
    bufp->chgBit(oldp+517,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data));
    bufp->chgBit(oldp+518,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+519,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+520,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+521,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+522,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+523,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+524,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i));
    bufp->chgBit(oldp+525,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni));
    bufp->chgBit(oldp+526,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we));
    bufp->chgSData(oldp+527,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd),16);
    bufp->chgBit(oldp+528,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe));
    bufp->chgSData(oldp+529,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q),16);
    bufp->chgSData(oldp+530,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds),16);
    bufp->chgSData(oldp+531,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs),16);
    bufp->chgBit(oldp+532,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en));
    bufp->chgSData(oldp+533,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data),16);
    bufp->chgBit(oldp+534,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we));
    bufp->chgSData(oldp+535,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd),16);
    bufp->chgSData(oldp+536,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q),16);
    bufp->chgBit(oldp+537,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgSData(oldp+538,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data),16);
    bufp->chgSData(oldp+539,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),16);
    bufp->chgBit(oldp+540,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i));
    bufp->chgBit(oldp+541,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni));
    bufp->chgBit(oldp+542,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we));
    bufp->chgBit(oldp+543,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd));
    bufp->chgBit(oldp+544,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe));
    bufp->chgBit(oldp+545,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q));
    bufp->chgBit(oldp+546,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds));
    bufp->chgBit(oldp+547,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs));
    bufp->chgBit(oldp+548,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en));
    bufp->chgBit(oldp+549,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data));
    bufp->chgBit(oldp+550,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+551,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+552,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+553,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+554,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+555,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+556,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i));
    bufp->chgBit(oldp+557,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni));
    bufp->chgBit(oldp+558,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we));
    bufp->chgBit(oldp+559,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd));
    bufp->chgBit(oldp+560,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe));
    bufp->chgBit(oldp+561,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q));
    bufp->chgBit(oldp+562,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds));
    bufp->chgBit(oldp+563,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs));
    bufp->chgBit(oldp+564,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en));
    bufp->chgBit(oldp+565,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data));
    bufp->chgBit(oldp+566,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+567,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+568,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+569,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+570,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+571,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+572,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i));
    bufp->chgBit(oldp+573,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni));
    bufp->chgBit(oldp+574,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we));
    bufp->chgBit(oldp+575,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd));
    bufp->chgBit(oldp+576,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe));
    bufp->chgBit(oldp+577,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q));
    bufp->chgBit(oldp+578,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds));
    bufp->chgBit(oldp+579,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs));
    bufp->chgBit(oldp+580,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en));
    bufp->chgBit(oldp+581,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data));
    bufp->chgBit(oldp+582,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+583,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+584,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+585,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+586,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+587,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+588,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i));
    bufp->chgBit(oldp+589,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni));
    bufp->chgBit(oldp+590,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we));
    bufp->chgBit(oldp+591,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd));
    bufp->chgBit(oldp+592,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe));
    bufp->chgBit(oldp+593,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q));
    bufp->chgBit(oldp+594,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds));
    bufp->chgBit(oldp+595,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs));
    bufp->chgBit(oldp+596,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en));
    bufp->chgBit(oldp+597,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data));
    bufp->chgBit(oldp+598,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+599,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+600,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+601,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+602,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+603,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+604,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i));
    bufp->chgBit(oldp+605,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni));
    bufp->chgBit(oldp+606,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we));
    bufp->chgBit(oldp+607,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd));
    bufp->chgBit(oldp+608,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe));
    bufp->chgBit(oldp+609,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q));
    bufp->chgBit(oldp+610,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds));
    bufp->chgBit(oldp+611,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs));
    bufp->chgBit(oldp+612,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en));
    bufp->chgBit(oldp+613,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data));
    bufp->chgBit(oldp+614,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+615,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+616,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+617,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+618,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+619,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+620,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i));
    bufp->chgBit(oldp+621,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni));
    bufp->chgBit(oldp+622,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we));
    bufp->chgBit(oldp+623,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd));
    bufp->chgBit(oldp+624,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe));
    bufp->chgBit(oldp+625,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q));
    bufp->chgBit(oldp+626,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds));
    bufp->chgBit(oldp+627,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs));
    bufp->chgBit(oldp+628,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en));
    bufp->chgBit(oldp+629,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data));
    bufp->chgBit(oldp+630,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+631,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+632,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+633,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+634,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+635,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+636,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i));
    bufp->chgBit(oldp+637,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni));
    bufp->chgBit(oldp+638,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i));
    bufp->chgBit(oldp+639,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o));
    bufp->chgBit(oldp+640,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i));
    bufp->chgBit(oldp+641,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni));
    bufp->chgBit(oldp+642,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we));
    bufp->chgBit(oldp+643,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd));
    bufp->chgBit(oldp+644,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe));
    bufp->chgBit(oldp+645,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q));
    bufp->chgBit(oldp+646,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds));
    bufp->chgBit(oldp+647,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs));
    bufp->chgBit(oldp+648,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en));
    bufp->chgBit(oldp+649,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data));
    bufp->chgBit(oldp+650,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+651,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+652,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+653,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+654,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+655,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+656,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i));
    bufp->chgBit(oldp+657,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni));
    bufp->chgBit(oldp+658,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we));
    bufp->chgBit(oldp+659,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd));
    bufp->chgBit(oldp+660,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe));
    bufp->chgBit(oldp+661,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q));
    bufp->chgBit(oldp+662,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds));
    bufp->chgBit(oldp+663,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs));
    bufp->chgBit(oldp+664,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en));
    bufp->chgBit(oldp+665,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data));
    bufp->chgBit(oldp+666,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+667,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+668,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+669,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+670,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+671,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+672,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re));
    bufp->chgCData(oldp+673,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d),8);
    bufp->chgBit(oldp+674,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre));
    bufp->chgCData(oldp+675,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds),8);
    bufp->chgCData(oldp+676,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs),8);
    bufp->chgBit(oldp+677,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re));
    bufp->chgCData(oldp+678,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d),8);
    bufp->chgBit(oldp+679,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre));
    bufp->chgCData(oldp+680,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds),8);
    bufp->chgCData(oldp+681,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs),8);
    bufp->chgBit(oldp+682,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->chgBit(oldp+683,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->chgCData(oldp+684,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),6);
    bufp->chgBit(oldp+685,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->chgBit(oldp+686,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->chgCData(oldp+687,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),6);
    bufp->chgCData(oldp+688,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),6);
    bufp->chgCData(oldp+689,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),6);
    bufp->chgCData(oldp+690,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),6);
    bufp->chgBit(oldp+691,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->chgBit(oldp+692,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->chgCData(oldp+693,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),6);
    bufp->chgBit(oldp+694,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->chgBit(oldp+695,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->chgSData(oldp+696,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),15);
    bufp->chgSData(oldp+697,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),15);
    bufp->chgSData(oldp+698,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),15);
    bufp->chgBit(oldp+699,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re));
    bufp->chgCData(oldp+700,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d),8);
    bufp->chgBit(oldp+701,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre));
    bufp->chgCData(oldp+702,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds),8);
    bufp->chgCData(oldp+703,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs),8);
    bufp->chgBit(oldp+704,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re));
    bufp->chgBit(oldp+705,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d));
    bufp->chgBit(oldp+706,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre));
    bufp->chgBit(oldp+707,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds));
    bufp->chgBit(oldp+708,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs));
    bufp->chgBit(oldp+709,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re));
    bufp->chgBit(oldp+710,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d));
    bufp->chgBit(oldp+711,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre));
    bufp->chgBit(oldp+712,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds));
    bufp->chgBit(oldp+713,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs));
    bufp->chgBit(oldp+714,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re));
    bufp->chgBit(oldp+715,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d));
    bufp->chgBit(oldp+716,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre));
    bufp->chgBit(oldp+717,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds));
    bufp->chgBit(oldp+718,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs));
    bufp->chgBit(oldp+719,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re));
    bufp->chgBit(oldp+720,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d));
    bufp->chgBit(oldp+721,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre));
    bufp->chgBit(oldp+722,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds));
    bufp->chgBit(oldp+723,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs));
    bufp->chgBit(oldp+724,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re));
    bufp->chgBit(oldp+725,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d));
    bufp->chgBit(oldp+726,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre));
    bufp->chgBit(oldp+727,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds));
    bufp->chgBit(oldp+728,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs));
    bufp->chgBit(oldp+729,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re));
    bufp->chgBit(oldp+730,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d));
    bufp->chgBit(oldp+731,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre));
    bufp->chgBit(oldp+732,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds));
    bufp->chgBit(oldp+733,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs));
    bufp->chgBit(oldp+734,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i));
    bufp->chgBit(oldp+735,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni));
    bufp->chgBit(oldp+736,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we));
    bufp->chgCData(oldp+737,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd),8);
    bufp->chgBit(oldp+738,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe));
    bufp->chgCData(oldp+739,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q),8);
    bufp->chgCData(oldp+740,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds),8);
    bufp->chgCData(oldp+741,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs),8);
    bufp->chgBit(oldp+742,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en));
    bufp->chgCData(oldp+743,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data),8);
    bufp->chgBit(oldp+744,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+745,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->chgCData(oldp+746,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q),8);
    bufp->chgBit(oldp+747,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+748,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->chgCData(oldp+749,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->chgBit(oldp+750,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i));
    bufp->chgBit(oldp+751,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni));
    bufp->chgBit(oldp+752,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i));
    bufp->chgBit(oldp+753,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o));
    Vtop___024root__trace_chg_dtype____2(vlSelf, bufp, 754, vlSymsp->TOP__uart_reg_pkg.UART_PERMIT);
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
