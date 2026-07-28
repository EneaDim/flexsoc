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

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.cordic_tb__DOT__clk_i));
    bufp->chgBit(oldp+1,(vlSelfRef.cordic_tb__DOT__rst_ni));
    bufp->chgBit(oldp+2,(vlSelfRef.cordic_tb__DOT__tl_i_a_valid));
    bufp->chgCData(oldp+3,(vlSelfRef.cordic_tb__DOT__tl_i_a_opcode),3);
    bufp->chgCData(oldp+4,(vlSelfRef.cordic_tb__DOT__tl_i_a_param),3);
    bufp->chgCData(oldp+5,(vlSelfRef.cordic_tb__DOT__tl_i_a_size),2);
    bufp->chgCData(oldp+6,(vlSelfRef.cordic_tb__DOT__tl_i_a_source),8);
    bufp->chgIData(oldp+7,(vlSelfRef.cordic_tb__DOT__tl_i_a_address),32);
    bufp->chgCData(oldp+8,(vlSelfRef.cordic_tb__DOT__tl_i_a_mask),4);
    bufp->chgIData(oldp+9,(vlSelfRef.cordic_tb__DOT__tl_i_a_data),32);
    bufp->chgBit(oldp+10,(vlSelfRef.cordic_tb__DOT__tl_i_d_ready));
    bufp->chgBit(oldp+11,(vlSelfRef.cordic_tb__DOT__tl_o_d_valid));
    bufp->chgCData(oldp+12,(vlSelfRef.cordic_tb__DOT__tl_o_d_opcode),3);
    bufp->chgIData(oldp+13,(vlSelfRef.cordic_tb__DOT__tl_o_d_data),32);
    bufp->chgBit(oldp+14,(vlSelfRef.cordic_tb__DOT__tl_o_d_error));
    bufp->chgBit(oldp+15,(vlSelfRef.cordic_tb__DOT__tl_o_a_ready));
    bufp->chgBit(oldp+16,((1U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                 >> 0x0000000cU))));
    bufp->chgCData(oldp+17,((7U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                   >> 9U))),3);
    bufp->chgCData(oldp+18,((7U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                   >> 6U))),3);
    bufp->chgCData(oldp+19,((3U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                   >> 4U))),2);
    bufp->chgCData(oldp+20,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.cordic_tb__DOT__tl_i[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+21,(((vlSelfRef.cordic_tb__DOT__tl_i[2U] 
                              << 4U) | (vlSelfRef.cordic_tb__DOT__tl_i[1U] 
                                        >> 0x0000001cU))),32);
    bufp->chgCData(oldp+22,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__tl_i[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgIData(oldp+23,(((vlSelfRef.cordic_tb__DOT__tl_i[1U] 
                              << 8U) | (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+24,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                            >> 0x00000013U))),5);
    bufp->chgCData(oldp+25,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                            >> 0x0000000fU))),4);
    bufp->chgCData(oldp+26,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                            >> 8U))),7);
    bufp->chgCData(oldp+27,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                            >> 1U))),7);
    bufp->chgBit(oldp+28,((1U & vlSelfRef.cordic_tb__DOT__tl_i[0U])));
    bufp->chgBit(oldp+29,((1U & (vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                 >> 1U))));
    bufp->chgCData(oldp+30,((7U & ((vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                    << 2U) | (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                              >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+31,((7U & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                   >> 0x0000001bU))),3);
    bufp->chgCData(oldp+32,((3U & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                   >> 0x00000019U))),2);
    bufp->chgCData(oldp+33,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                            >> 0x00000011U))),8);
    bufp->chgBit(oldp+34,((1U & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                 >> 0x00000010U))));
    bufp->chgIData(oldp+35,(((vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                              << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                                 >> 0x00000010U))),32);
    bufp->chgCData(oldp+36,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                            >> 9U))),7);
    bufp->chgCData(oldp+37,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                            >> 2U))),7);
    bufp->chgBit(oldp+38,((1U & (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                 >> 1U))));
    bufp->chgBit(oldp+39,((1U & vlSelfRef.cordic_tb__DOT__tl_o[0U])));
    bufp->chgCData(oldp+40,(vlSelfRef.cordic_tb__DOT__cmd_intg_calc),7);
    bufp->chgCData(oldp+41,(vlSelfRef.cordic_tb__DOT__data_intg_calc),7);
    bufp->chgBit(oldp+42,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__clk_i));
    bufp->chgBit(oldp+43,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__rst_ni));
    bufp->chgBit(oldp+44,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                 >> 0x0000000cU))));
    bufp->chgCData(oldp+45,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                   >> 9U))),3);
    bufp->chgCData(oldp+46,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                   >> 6U))),3);
    bufp->chgCData(oldp+47,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                   >> 4U))),2);
    bufp->chgCData(oldp+48,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+49,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[2U] 
                              << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
                                        >> 0x0000001cU))),32);
    bufp->chgCData(oldp+50,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
                                            >> 0x00000018U))),4);
    bufp->chgIData(oldp+51,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
                              << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                        >> 0x00000018U))),32);
    bufp->chgCData(oldp+52,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                            >> 0x00000013U))),5);
    bufp->chgCData(oldp+53,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                            >> 0x0000000fU))),4);
    bufp->chgCData(oldp+54,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                            >> 8U))),7);
    bufp->chgCData(oldp+55,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                            >> 1U))),7);
    bufp->chgBit(oldp+56,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U])));
    bufp->chgBit(oldp+57,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U] 
                                 >> 1U))));
    bufp->chgCData(oldp+58,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U] 
                                    << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                              >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+59,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                   >> 0x0000001bU))),3);
    bufp->chgCData(oldp+60,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                   >> 0x00000019U))),2);
    bufp->chgCData(oldp+61,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                            >> 0x00000011U))),8);
    bufp->chgBit(oldp+62,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                 >> 0x00000010U))));
    bufp->chgIData(oldp+63,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                              << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                                 >> 0x00000010U))),32);
    bufp->chgCData(oldp+64,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                            >> 9U))),7);
    bufp->chgCData(oldp+65,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                            >> 2U))),7);
    bufp->chgBit(oldp+66,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                 >> 1U))));
    bufp->chgBit(oldp+67,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U])));
    bufp->chgSData(oldp+68,((0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[9U] 
                                             << 5U) 
                                            | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                               >> 0x0000001bU)))),16);
    bufp->chgCData(oldp+69,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                            >> 0x00000013U))),8);
    bufp->chgCData(oldp+70,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                            >> 0x0000000eU))),5);
    bufp->chgBit(oldp+71,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                 >> 0x0000000dU))));
    bufp->chgBit(oldp+72,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                 >> 0x0000000cU))));
    bufp->chgBit(oldp+73,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                 >> 0x0000000bU))));
    bufp->chgIData(oldp+74,((0x1fffffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                             << 0x00000012U) 
                                            | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                               >> 0x0000000eU)))),29);
    bufp->chgBit(oldp+75,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 0x0000000dU))));
    bufp->chgBit(oldp+76,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 0x0000000cU))));
    bufp->chgBit(oldp+77,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 0x0000000bU))));
    bufp->chgBit(oldp+78,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 0x0000000aU))));
    bufp->chgBit(oldp+79,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 9U))));
    bufp->chgBit(oldp+80,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 8U))));
    bufp->chgBit(oldp+81,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                 >> 7U))));
    bufp->chgIData(oldp+82,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                              << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U] 
                                                 >> 7U))),32);
    bufp->chgIData(oldp+83,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U] 
                              << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U] 
                                                 >> 7U))),32);
    bufp->chgIData(oldp+84,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U] 
                              << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U] 
                                                 >> 7U))),32);
    bufp->chgIData(oldp+85,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U] 
                              << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
                                                 >> 7U))),32);
    bufp->chgBit(oldp+86,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
                                 >> 6U))));
    bufp->chgIData(oldp+87,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
                              << 0x0000001aU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
                                                 >> 6U))),32);
    bufp->chgBit(oldp+88,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
                                 >> 5U))));
    bufp->chgIData(oldp+89,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
                              << 0x0000001bU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
                                                 >> 5U))),32);
    bufp->chgBit(oldp+90,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
                                 >> 4U))));
    bufp->chgCData(oldp+91,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
                                             << 4U) 
                                            | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                               >> 0x0000001cU)))),8);
    bufp->chgBit(oldp+92,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                 >> 0x0000001bU))));
    bufp->chgCData(oldp+93,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                            >> 0x00000013U))),8);
    bufp->chgBit(oldp+94,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                 >> 0x00000012U))));
    bufp->chgCData(oldp+95,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                            >> 0x0000000aU))),8);
    bufp->chgBit(oldp+96,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                 >> 9U))));
    bufp->chgCData(oldp+97,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                            >> 1U))),8);
    bufp->chgBit(oldp+98,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U])));
    bufp->chgBit(oldp+99,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
                           >> 0x0000001fU)));
    bufp->chgBit(oldp+100,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
                                  >> 0x0000001eU))));
    bufp->chgBit(oldp+101,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
                                  >> 0x0000001dU))));
    bufp->chgIData(oldp+102,((0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U])),29);
    bufp->chgIData(oldp+103,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[3U]),32);
    bufp->chgIData(oldp+104,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[2U]),32);
    bufp->chgIData(oldp+105,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[1U]),32);
    bufp->chgCData(oldp+106,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
                              >> 0x00000018U)),8);
    bufp->chgCData(oldp+107,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+108,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
                                             >> 8U))),8);
    bufp->chgCData(oldp+109,((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U])),8);
    bufp->chgBit(oldp+110,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i));
    bufp->chgBit(oldp+111,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni));
    bufp->chgSData(oldp+112,((0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[9U] 
                                              << 5U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                                >> 0x0000001bU)))),16);
    bufp->chgCData(oldp+113,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                             >> 0x00000013U))),8);
    bufp->chgCData(oldp+114,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                             >> 0x0000000eU))),5);
    bufp->chgBit(oldp+115,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                  >> 0x0000000dU))));
    bufp->chgBit(oldp+116,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                  >> 0x0000000cU))));
    bufp->chgBit(oldp+117,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                  >> 0x0000000bU))));
    bufp->chgIData(oldp+118,((0x1fffffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                              << 0x00000012U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                                >> 0x0000000eU)))),29);
    bufp->chgBit(oldp+119,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 0x0000000dU))));
    bufp->chgBit(oldp+120,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 0x0000000cU))));
    bufp->chgBit(oldp+121,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 0x0000000bU))));
    bufp->chgBit(oldp+122,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 0x0000000aU))));
    bufp->chgBit(oldp+123,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 9U))));
    bufp->chgBit(oldp+124,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 8U))));
    bufp->chgBit(oldp+125,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                  >> 7U))));
    bufp->chgIData(oldp+126,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
                                                  >> 7U))),32);
    bufp->chgIData(oldp+127,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
                                                  >> 7U))),32);
    bufp->chgIData(oldp+128,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
                                                  >> 7U))),32);
    bufp->chgIData(oldp+129,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
                                                  >> 7U))),32);
    bufp->chgBit(oldp+130,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
                                  >> 6U))));
    bufp->chgIData(oldp+131,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
                               << 0x0000001aU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
                                                  >> 6U))),32);
    bufp->chgBit(oldp+132,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
                                  >> 5U))));
    bufp->chgIData(oldp+133,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
                               << 0x0000001bU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
                                                  >> 5U))),32);
    bufp->chgBit(oldp+134,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
                                  >> 4U))));
    bufp->chgCData(oldp+135,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgBit(oldp+136,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                  >> 0x0000001bU))));
    bufp->chgCData(oldp+137,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                             >> 0x00000013U))),8);
    bufp->chgBit(oldp+138,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                  >> 0x00000012U))));
    bufp->chgCData(oldp+139,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                             >> 0x0000000aU))),8);
    bufp->chgBit(oldp+140,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                  >> 9U))));
    bufp->chgCData(oldp+141,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                             >> 1U))),8);
    bufp->chgBit(oldp+142,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U])));
    bufp->chgBit(oldp+143,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
                            >> 0x0000001fU)));
    bufp->chgBit(oldp+144,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
                                  >> 0x0000001eU))));
    bufp->chgBit(oldp+145,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
                                  >> 0x0000001dU))));
    bufp->chgIData(oldp+146,((0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U])),29);
    bufp->chgIData(oldp+147,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[3U]),32);
    bufp->chgIData(oldp+148,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[2U]),32);
    bufp->chgIData(oldp+149,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[1U]),32);
    bufp->chgCData(oldp+150,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
                              >> 0x00000018U)),8);
    bufp->chgCData(oldp+151,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+152,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
                                             >> 8U))),8);
    bufp->chgCData(oldp+153,((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U])),8);
    bufp->chgBit(oldp+154,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start));
    bufp->chgBit(oldp+155,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode));
    bufp->chgBit(oldp+156,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst));
    bufp->chgCData(oldp+157,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd),5);
    bufp->chgCData(oldp+158,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter),8);
    bufp->chgSData(oldp+159,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd2),16);
    bufp->chgBit(oldp+160,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy));
    bufp->chgBit(oldp+161,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid));
    bufp->chgBit(oldp+162,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error));
    bufp->chgIData(oldp+163,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_rsvd),29);
    bufp->chgIData(oldp+164,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value),32);
    bufp->chgIData(oldp+165,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value),32);
    bufp->chgIData(oldp+166,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value),32);
    bufp->chgIData(oldp+167,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value),32);
    bufp->chgIData(oldp+168,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value),32);
    bufp->chgIData(oldp+169,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value),32);
    bufp->chgCData(oldp+170,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width),8);
    bufp->chgCData(oldp+171,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width),8);
    bufp->chgCData(oldp+172,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter),8);
    bufp->chgCData(oldp+173,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd),8);
    bufp->chgBit(oldp+174,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q));
    bufp->chgBit(oldp+175,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d));
    bufp->chgIData(oldp+176,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q),19);
    bufp->chgIData(oldp+177,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d),19);
    bufp->chgIData(oldp+178,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q),19);
    bufp->chgIData(oldp+179,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d),19);
    bufp->chgSData(oldp+180,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q),16);
    bufp->chgSData(oldp+181,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d),16);
    bufp->chgCData(oldp+182,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q),5);
    bufp->chgCData(oldp+183,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d),5);
    bufp->chgCData(oldp+184,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q),8);
    bufp->chgCData(oldp+185,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d),8);
    bufp->chgBit(oldp+186,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q));
    bufp->chgBit(oldp+187,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d));
    bufp->chgBit(oldp+188,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d));
    bufp->chgBit(oldp+189,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d));
    bufp->chgBit(oldp+190,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise));
    bufp->chgBit(oldp+191,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_fall_unused));
    bufp->chgCData(oldp+192,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff),8);
    bufp->chgBit(oldp+193,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid));
    bufp->chgIData(oldp+194,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init),19);
    bufp->chgIData(oldp+195,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init),19);
    bufp->chgSData(oldp+196,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init),16);
    bufp->chgIData(oldp+197,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift),19);
    bufp->chgIData(oldp+198,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift),19);
    bufp->chgIData(oldp+199,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step),19);
    bufp->chgIData(oldp+200,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step),19);
    bufp->chgSData(oldp+201,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step),16);
    bufp->chgIData(oldp+202,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_next_32),32);
    bufp->chgIData(oldp+203,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_next_32),32);
    bufp->chgIData(oldp+204,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_next_32),32);
    bufp->chgBit(oldp+205,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__clk_i));
    bufp->chgBit(oldp+206,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__rst_ni));
    bufp->chgBit(oldp+207,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__en_i));
    bufp->chgBit(oldp+208,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i));
    bufp->chgBit(oldp+209,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o));
    bufp->chgBit(oldp+210,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o));
    bufp->chgBit(oldp+211,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q));
    bufp->chgBit(oldp+212,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+213,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+214,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+215,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__q_o));
    bufp->chgIData(oldp+216,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int),19);
    bufp->chgIData(oldp+217,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int),19);
    bufp->chgSData(oldp+218,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int),16);
    bufp->chgSData(oldp+219,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible),16);
    bufp->chgSData(oldp+220,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible),16);
    bufp->chgBit(oldp+221,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i));
    bufp->chgBit(oldp+222,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni));
    bufp->chgBit(oldp+223,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+224,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+225,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+226,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+227,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+228,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+229,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+230,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+231,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+232,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+233,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+234,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+235,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U])));
    bufp->chgBit(oldp+236,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+237,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+238,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+239,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+240,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+241,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+242,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+243,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+244,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+245,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+246,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U])));
    bufp->chgSData(oldp+247,((0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[9U] 
                                              << 5U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                                >> 0x0000001bU)))),16);
    bufp->chgCData(oldp+248,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                             >> 0x00000013U))),8);
    bufp->chgCData(oldp+249,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                             >> 0x0000000eU))),5);
    bufp->chgBit(oldp+250,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                  >> 0x0000000dU))));
    bufp->chgBit(oldp+251,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                  >> 0x0000000cU))));
    bufp->chgBit(oldp+252,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                  >> 0x0000000bU))));
    bufp->chgIData(oldp+253,((0x1fffffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                              << 0x00000012U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                                >> 0x0000000eU)))),29);
    bufp->chgBit(oldp+254,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 0x0000000dU))));
    bufp->chgBit(oldp+255,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 0x0000000cU))));
    bufp->chgBit(oldp+256,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 0x0000000bU))));
    bufp->chgBit(oldp+257,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 0x0000000aU))));
    bufp->chgBit(oldp+258,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 9U))));
    bufp->chgBit(oldp+259,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 8U))));
    bufp->chgBit(oldp+260,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                  >> 7U))));
    bufp->chgIData(oldp+261,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U] 
                                                  >> 7U))),32);
    bufp->chgIData(oldp+262,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U] 
                                                  >> 7U))),32);
    bufp->chgIData(oldp+263,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
                                                  >> 7U))),32);
    bufp->chgIData(oldp+264,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
                                                  >> 7U))),32);
    bufp->chgBit(oldp+265,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
                                  >> 6U))));
    bufp->chgIData(oldp+266,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
                               << 0x0000001aU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
                                                  >> 6U))),32);
    bufp->chgBit(oldp+267,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
                                  >> 5U))));
    bufp->chgIData(oldp+268,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
                               << 0x0000001bU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
                                                  >> 5U))),32);
    bufp->chgBit(oldp+269,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
                                  >> 4U))));
    bufp->chgCData(oldp+270,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgBit(oldp+271,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                  >> 0x0000001bU))));
    bufp->chgCData(oldp+272,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                             >> 0x00000013U))),8);
    bufp->chgBit(oldp+273,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                  >> 0x00000012U))));
    bufp->chgCData(oldp+274,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                             >> 0x0000000aU))),8);
    bufp->chgBit(oldp+275,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                  >> 9U))));
    bufp->chgCData(oldp+276,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                             >> 1U))),8);
    bufp->chgBit(oldp+277,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U])));
    bufp->chgBit(oldp+278,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                            >> 0x0000001fU)));
    bufp->chgBit(oldp+279,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                                  >> 0x0000001eU))));
    bufp->chgBit(oldp+280,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                                  >> 0x0000001dU))));
    bufp->chgIData(oldp+281,((0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U])),29);
    bufp->chgIData(oldp+282,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[3U]),32);
    bufp->chgIData(oldp+283,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[2U]),32);
    bufp->chgIData(oldp+284,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[1U]),32);
    bufp->chgCData(oldp+285,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                              >> 0x00000018U)),8);
    bufp->chgCData(oldp+286,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                                             >> 0x00000010U))),8);
    bufp->chgCData(oldp+287,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                                             >> 8U))),8);
    bufp->chgCData(oldp+288,((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U])),8);
    bufp->chgBit(oldp+289,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__devmode_i));
    bufp->chgBit(oldp+290,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we));
    bufp->chgBit(oldp+291,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re));
    bufp->chgCData(oldp+292,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr),6);
    bufp->chgIData(oldp+293,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata),32);
    bufp->chgCData(oldp+294,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be),4);
    bufp->chgIData(oldp+295,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata),32);
    bufp->chgBit(oldp+296,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error));
    bufp->chgBit(oldp+297,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss));
    bufp->chgBit(oldp+298,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err));
    bufp->chgIData(oldp+299,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+300,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_busy));
    bufp->chgBit(oldp+301,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+302,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+303,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+304,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+305,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+306,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+307,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+308,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+309,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+310,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+311,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+312,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+313,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U])));
    bufp->chgBit(oldp+314,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+315,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+316,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+317,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+318,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+319,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+320,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+321,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+322,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+323,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+324,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U])));
    bufp->chgBit(oldp+325,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+326,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+327,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+328,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+329,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+330,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+331,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+332,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+333,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+334,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+335,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U])));
    bufp->chgBit(oldp+336,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we));
    bufp->chgBit(oldp+337,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs));
    bufp->chgBit(oldp+338,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_wd));
    bufp->chgBit(oldp+339,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs));
    bufp->chgBit(oldp+340,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_wd));
    bufp->chgBit(oldp+341,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs));
    bufp->chgBit(oldp+342,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_wd));
    bufp->chgCData(oldp+343,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs),5);
    bufp->chgCData(oldp+344,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_wd),5);
    bufp->chgCData(oldp+345,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs),8);
    bufp->chgCData(oldp+346,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_wd),8);
    bufp->chgSData(oldp+347,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs),16);
    bufp->chgSData(oldp+348,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_wd),16);
    bufp->chgBit(oldp+349,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re));
    bufp->chgBit(oldp+350,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs));
    bufp->chgBit(oldp+351,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs));
    bufp->chgBit(oldp+352,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs));
    bufp->chgIData(oldp+353,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs),29);
    bufp->chgBit(oldp+354,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we));
    bufp->chgIData(oldp+355,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs),32);
    bufp->chgIData(oldp+356,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_wd),32);
    bufp->chgBit(oldp+357,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we));
    bufp->chgIData(oldp+358,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs),32);
    bufp->chgIData(oldp+359,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_wd),32);
    bufp->chgBit(oldp+360,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we));
    bufp->chgIData(oldp+361,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs),32);
    bufp->chgIData(oldp+362,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_wd),32);
    bufp->chgBit(oldp+363,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re));
    bufp->chgIData(oldp+364,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs),32);
    bufp->chgBit(oldp+365,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re));
    bufp->chgIData(oldp+366,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs),32);
    bufp->chgBit(oldp+367,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re));
    bufp->chgIData(oldp+368,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs),32);
    bufp->chgBit(oldp+369,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re));
    bufp->chgCData(oldp+370,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs),8);
    bufp->chgCData(oldp+371,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs),8);
    bufp->chgCData(oldp+372,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs),8);
    bufp->chgCData(oldp+373,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs),8);
    bufp->chgSData(oldp+374,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit),9);
    bufp->chgBit(oldp+375,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__shadow_busy));
    bufp->chgBit(oldp+376,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_wdata));
    bufp->chgBit(oldp+377,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_be));
    bufp->chgBit(oldp+378,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re));
    bufp->chgBit(oldp+379,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__we));
    bufp->chgCData(oldp+380,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__wd),8);
    bufp->chgCData(oldp+381,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d),8);
    bufp->chgBit(oldp+382,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qe));
    bufp->chgBit(oldp+383,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre));
    bufp->chgCData(oldp+384,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__q),8);
    bufp->chgCData(oldp+385,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__ds),8);
    bufp->chgCData(oldp+386,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs),8);
    bufp->chgBit(oldp+387,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re));
    bufp->chgBit(oldp+388,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__we));
    bufp->chgCData(oldp+389,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__wd),8);
    bufp->chgCData(oldp+390,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d),8);
    bufp->chgBit(oldp+391,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qe));
    bufp->chgBit(oldp+392,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre));
    bufp->chgCData(oldp+393,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__q),8);
    bufp->chgCData(oldp+394,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__ds),8);
    bufp->chgCData(oldp+395,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs),8);
    bufp->chgBit(oldp+396,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re));
    bufp->chgBit(oldp+397,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__we));
    bufp->chgCData(oldp+398,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__wd),8);
    bufp->chgCData(oldp+399,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d),8);
    bufp->chgBit(oldp+400,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qe));
    bufp->chgBit(oldp+401,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre));
    bufp->chgCData(oldp+402,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__q),8);
    bufp->chgCData(oldp+403,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__ds),8);
    bufp->chgCData(oldp+404,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs),8);
    bufp->chgBit(oldp+405,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re));
    bufp->chgBit(oldp+406,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__we));
    bufp->chgCData(oldp+407,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__wd),8);
    bufp->chgCData(oldp+408,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d),8);
    bufp->chgBit(oldp+409,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qe));
    bufp->chgBit(oldp+410,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre));
    bufp->chgCData(oldp+411,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q),8);
    bufp->chgCData(oldp+412,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__ds),8);
    bufp->chgCData(oldp+413,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs),8);
    bufp->chgBit(oldp+414,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i));
    bufp->chgBit(oldp+415,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni));
    bufp->chgBit(oldp+416,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we));
    bufp->chgBit(oldp+417,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wd));
    bufp->chgBit(oldp+418,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__de));
    bufp->chgBit(oldp+419,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__d));
    bufp->chgBit(oldp+420,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qe));
    bufp->chgBit(oldp+421,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q));
    bufp->chgBit(oldp+422,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__ds));
    bufp->chgBit(oldp+423,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs));
    bufp->chgBit(oldp+424,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en));
    bufp->chgBit(oldp+425,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data));
    bufp->chgBit(oldp+426,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+427,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+428,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__de));
    bufp->chgBit(oldp+429,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__d));
    bufp->chgBit(oldp+430,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+431,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+432,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+433,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+434,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i));
    bufp->chgBit(oldp+435,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni));
    bufp->chgBit(oldp+436,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we));
    bufp->chgCData(oldp+437,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wd),8);
    bufp->chgBit(oldp+438,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__de));
    bufp->chgCData(oldp+439,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__d),8);
    bufp->chgBit(oldp+440,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qe));
    bufp->chgCData(oldp+441,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q),8);
    bufp->chgCData(oldp+442,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__ds),8);
    bufp->chgCData(oldp+443,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs),8);
    bufp->chgBit(oldp+444,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en));
    bufp->chgCData(oldp+445,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data),8);
    bufp->chgBit(oldp+446,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+447,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->chgBit(oldp+448,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__de));
    bufp->chgCData(oldp+449,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__d),8);
    bufp->chgCData(oldp+450,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q),8);
    bufp->chgBit(oldp+451,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+452,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->chgCData(oldp+453,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->chgBit(oldp+454,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i));
    bufp->chgBit(oldp+455,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni));
    bufp->chgBit(oldp+456,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we));
    bufp->chgCData(oldp+457,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wd),5);
    bufp->chgBit(oldp+458,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__de));
    bufp->chgCData(oldp+459,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__d),5);
    bufp->chgBit(oldp+460,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qe));
    bufp->chgCData(oldp+461,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q),5);
    bufp->chgCData(oldp+462,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__ds),5);
    bufp->chgCData(oldp+463,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs),5);
    bufp->chgBit(oldp+464,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en));
    bufp->chgCData(oldp+465,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data),5);
    bufp->chgBit(oldp+466,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+467,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wd),5);
    bufp->chgBit(oldp+468,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__de));
    bufp->chgCData(oldp+469,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__d),5);
    bufp->chgCData(oldp+470,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q),5);
    bufp->chgBit(oldp+471,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+472,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data),5);
    bufp->chgCData(oldp+473,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),5);
    bufp->chgBit(oldp+474,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i));
    bufp->chgBit(oldp+475,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni));
    bufp->chgBit(oldp+476,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we));
    bufp->chgSData(oldp+477,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wd),16);
    bufp->chgBit(oldp+478,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__de));
    bufp->chgSData(oldp+479,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__d),16);
    bufp->chgBit(oldp+480,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qe));
    bufp->chgSData(oldp+481,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q),16);
    bufp->chgSData(oldp+482,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__ds),16);
    bufp->chgSData(oldp+483,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs),16);
    bufp->chgBit(oldp+484,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en));
    bufp->chgSData(oldp+485,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data),16);
    bufp->chgBit(oldp+486,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we));
    bufp->chgSData(oldp+487,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wd),16);
    bufp->chgBit(oldp+488,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__de));
    bufp->chgSData(oldp+489,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__d),16);
    bufp->chgSData(oldp+490,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q),16);
    bufp->chgBit(oldp+491,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgSData(oldp+492,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data),16);
    bufp->chgSData(oldp+493,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),16);
    bufp->chgBit(oldp+494,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i));
    bufp->chgBit(oldp+495,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni));
    bufp->chgBit(oldp+496,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we));
    bufp->chgBit(oldp+497,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wd));
    bufp->chgBit(oldp+498,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__de));
    bufp->chgBit(oldp+499,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__d));
    bufp->chgBit(oldp+500,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qe));
    bufp->chgBit(oldp+501,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q));
    bufp->chgBit(oldp+502,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__ds));
    bufp->chgBit(oldp+503,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs));
    bufp->chgBit(oldp+504,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en));
    bufp->chgBit(oldp+505,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data));
    bufp->chgBit(oldp+506,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+507,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+508,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__de));
    bufp->chgBit(oldp+509,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__d));
    bufp->chgBit(oldp+510,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+511,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+512,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+513,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+514,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i));
    bufp->chgBit(oldp+515,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni));
    bufp->chgBit(oldp+516,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we));
    bufp->chgBit(oldp+517,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wd));
    bufp->chgBit(oldp+518,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__de));
    bufp->chgBit(oldp+519,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__d));
    bufp->chgBit(oldp+520,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qe));
    bufp->chgBit(oldp+521,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q));
    bufp->chgBit(oldp+522,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__ds));
    bufp->chgBit(oldp+523,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs));
    bufp->chgBit(oldp+524,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en));
    bufp->chgBit(oldp+525,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data));
    bufp->chgBit(oldp+526,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we));
    bufp->chgBit(oldp+527,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wd));
    bufp->chgBit(oldp+528,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__de));
    bufp->chgBit(oldp+529,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__d));
    bufp->chgBit(oldp+530,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q));
    bufp->chgBit(oldp+531,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgBit(oldp+532,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->chgBit(oldp+533,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->chgBit(oldp+534,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i));
    bufp->chgBit(oldp+535,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni));
    bufp->chgBit(oldp+536,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+537,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+538,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+539,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+540,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+541,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+542,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+543,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+544,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+545,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+546,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+547,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+548,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U])));
    bufp->chgBit(oldp+549,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+550,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+551,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+552,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+553,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+554,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+555,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+556,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+557,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+558,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+559,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U])));
    bufp->chgCData(oldp+560,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__en_ifetch_i),4);
    bufp->chgBit(oldp+561,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error_o));
    bufp->chgBit(oldp+562,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o));
    bufp->chgBit(oldp+563,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o));
    bufp->chgCData(oldp+564,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_o),6);
    bufp->chgIData(oldp+565,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wdata_o),32);
    bufp->chgCData(oldp+566,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__be_o),4);
    bufp->chgBit(oldp+567,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i));
    bufp->chgIData(oldp+568,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_i),32);
    bufp->chgBit(oldp+569,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i));
    bufp->chgBit(oldp+570,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q));
    bufp->chgBit(oldp+571,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack));
    bufp->chgBit(oldp+572,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__d_ack));
    bufp->chgIData(oldp+573,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata),32);
    bufp->chgIData(oldp+574,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q),32);
    bufp->chgBit(oldp+575,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q));
    bufp->chgBit(oldp+576,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error));
    bufp->chgBit(oldp+577,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal));
    bufp->chgBit(oldp+578,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__instr_error));
    bufp->chgBit(oldp+579,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error));
    bufp->chgBit(oldp+580,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err));
    bufp->chgBit(oldp+581,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__malformed_meta_err));
    bufp->chgBit(oldp+582,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_err));
    bufp->chgCData(oldp+583,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q),8);
    bufp->chgCData(oldp+584,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q),2);
    bufp->chgCData(oldp+585,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->chgBit(oldp+586,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req));
    bufp->chgBit(oldp+587,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req));
    bufp->chgBit(oldp+588,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+589,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+590,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+591,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+592,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+593,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+594,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+595,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+596,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+597,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+598,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U])));
    bufp->chgBit(oldp+599,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__clk_i));
    bufp->chgBit(oldp+600,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__rst_ni));
    bufp->chgBit(oldp+601,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+602,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+603,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+604,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+605,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+606,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+607,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+608,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+609,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+610,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+611,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+612,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+613,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U])));
    bufp->chgBit(oldp+614,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o));
    bufp->chgBit(oldp+615,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed));
    bufp->chgBit(oldp+616,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed));
    bufp->chgBit(oldp+617,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full));
    bufp->chgBit(oldp+618,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial));
    bufp->chgBit(oldp+619,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get));
    bufp->chgBit(oldp+620,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
    bufp->chgBit(oldp+621,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
    bufp->chgBit(oldp+622,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
    bufp->chgBit(oldp+623,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
    bufp->chgBit(oldp+624,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    bufp->chgCData(oldp+625,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask),4);
    bufp->chgBit(oldp+626,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+627,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+628,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+629,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+630,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+631,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+632,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+633,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+634,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+635,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+636,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->chgBit(oldp+637,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+638,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+639,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+640,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+641,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+642,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+643,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+644,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+645,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+646,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+647,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->chgBit(oldp+648,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->chgBit(oldp+649,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+650,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+651,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+652,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+653,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+654,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+655,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+656,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+657,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+658,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+659,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->chgBit(oldp+660,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->chgCData(oldp+661,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->chgCData(oldp+662,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->chgCData(oldp+663,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->chgCData(oldp+664,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->chgBit(oldp+665,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->chgIData(oldp+666,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->chgCData(oldp+667,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->chgCData(oldp+668,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->chgBit(oldp+669,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->chgBit(oldp+670,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->chgBit(oldp+671,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->chgBit(oldp+672,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re));
    bufp->chgBit(oldp+673,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__we));
    bufp->chgBit(oldp+674,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__wd));
    bufp->chgBit(oldp+675,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d));
    bufp->chgBit(oldp+676,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qe));
    bufp->chgBit(oldp+677,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre));
    bufp->chgBit(oldp+678,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__q));
    bufp->chgBit(oldp+679,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__ds));
    bufp->chgBit(oldp+680,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs));
    bufp->chgBit(oldp+681,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re));
    bufp->chgBit(oldp+682,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__we));
    bufp->chgBit(oldp+683,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__wd));
    bufp->chgBit(oldp+684,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d));
    bufp->chgBit(oldp+685,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qe));
    bufp->chgBit(oldp+686,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre));
    bufp->chgBit(oldp+687,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__q));
    bufp->chgBit(oldp+688,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__ds));
    bufp->chgBit(oldp+689,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs));
    bufp->chgBit(oldp+690,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re));
    bufp->chgBit(oldp+691,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__we));
    bufp->chgIData(oldp+692,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__wd),29);
    bufp->chgIData(oldp+693,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d),29);
    bufp->chgBit(oldp+694,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qe));
    bufp->chgBit(oldp+695,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre));
    bufp->chgIData(oldp+696,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q),29);
    bufp->chgIData(oldp+697,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__ds),29);
    bufp->chgIData(oldp+698,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs),29);
    bufp->chgBit(oldp+699,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re));
    bufp->chgBit(oldp+700,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__we));
    bufp->chgBit(oldp+701,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__wd));
    bufp->chgBit(oldp+702,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d));
    bufp->chgBit(oldp+703,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qe));
    bufp->chgBit(oldp+704,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre));
    bufp->chgBit(oldp+705,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__q));
    bufp->chgBit(oldp+706,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__ds));
    bufp->chgBit(oldp+707,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs));
    bufp->chgBit(oldp+708,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i));
    bufp->chgBit(oldp+709,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni));
    bufp->chgBit(oldp+710,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we));
    bufp->chgIData(oldp+711,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wd),32);
    bufp->chgBit(oldp+712,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__de));
    bufp->chgIData(oldp+713,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__d),32);
    bufp->chgBit(oldp+714,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qe));
    bufp->chgIData(oldp+715,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q),32);
    bufp->chgIData(oldp+716,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__ds),32);
    bufp->chgIData(oldp+717,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs),32);
    bufp->chgBit(oldp+718,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en));
    bufp->chgIData(oldp+719,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data),32);
    bufp->chgBit(oldp+720,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we));
    bufp->chgIData(oldp+721,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->chgBit(oldp+722,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__de));
    bufp->chgIData(oldp+723,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__d),32);
    bufp->chgIData(oldp+724,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q),32);
    bufp->chgBit(oldp+725,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgIData(oldp+726,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->chgIData(oldp+727,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->chgBit(oldp+728,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re));
    bufp->chgBit(oldp+729,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__we));
    bufp->chgIData(oldp+730,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__wd),32);
    bufp->chgIData(oldp+731,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d),32);
    bufp->chgBit(oldp+732,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qe));
    bufp->chgBit(oldp+733,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre));
    bufp->chgIData(oldp+734,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q),32);
    bufp->chgIData(oldp+735,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__ds),32);
    bufp->chgIData(oldp+736,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs),32);
    bufp->chgBit(oldp+737,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i));
    bufp->chgBit(oldp+738,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni));
    bufp->chgBit(oldp+739,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we));
    bufp->chgIData(oldp+740,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wd),32);
    bufp->chgBit(oldp+741,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__de));
    bufp->chgIData(oldp+742,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__d),32);
    bufp->chgBit(oldp+743,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qe));
    bufp->chgIData(oldp+744,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q),32);
    bufp->chgIData(oldp+745,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__ds),32);
    bufp->chgIData(oldp+746,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs),32);
    bufp->chgBit(oldp+747,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en));
    bufp->chgIData(oldp+748,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data),32);
    bufp->chgBit(oldp+749,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we));
    bufp->chgIData(oldp+750,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->chgBit(oldp+751,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__de));
    bufp->chgIData(oldp+752,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__d),32);
    bufp->chgIData(oldp+753,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q),32);
    bufp->chgBit(oldp+754,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgIData(oldp+755,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->chgIData(oldp+756,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->chgBit(oldp+757,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re));
    bufp->chgBit(oldp+758,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__we));
    bufp->chgIData(oldp+759,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__wd),32);
    bufp->chgIData(oldp+760,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d),32);
    bufp->chgBit(oldp+761,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qe));
    bufp->chgBit(oldp+762,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre));
    bufp->chgIData(oldp+763,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q),32);
    bufp->chgIData(oldp+764,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__ds),32);
    bufp->chgIData(oldp+765,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs),32);
    bufp->chgBit(oldp+766,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i));
    bufp->chgBit(oldp+767,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni));
    bufp->chgBit(oldp+768,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we));
    bufp->chgIData(oldp+769,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wd),32);
    bufp->chgBit(oldp+770,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__de));
    bufp->chgIData(oldp+771,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__d),32);
    bufp->chgBit(oldp+772,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qe));
    bufp->chgIData(oldp+773,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q),32);
    bufp->chgIData(oldp+774,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__ds),32);
    bufp->chgIData(oldp+775,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs),32);
    bufp->chgBit(oldp+776,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en));
    bufp->chgIData(oldp+777,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data),32);
    bufp->chgBit(oldp+778,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we));
    bufp->chgIData(oldp+779,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->chgBit(oldp+780,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__de));
    bufp->chgIData(oldp+781,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__d),32);
    bufp->chgIData(oldp+782,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q),32);
    bufp->chgBit(oldp+783,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgIData(oldp+784,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->chgIData(oldp+785,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->chgBit(oldp+786,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re));
    bufp->chgBit(oldp+787,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__we));
    bufp->chgIData(oldp+788,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__wd),32);
    bufp->chgIData(oldp+789,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d),32);
    bufp->chgBit(oldp+790,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qe));
    bufp->chgBit(oldp+791,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre));
    bufp->chgIData(oldp+792,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q),32);
    bufp->chgIData(oldp+793,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__ds),32);
    bufp->chgIData(oldp+794,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs),32);
    bufp->chgBit(oldp+795,((1U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                  >> 0x0000000cU))));
    bufp->chgCData(oldp+796,((7U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                    >> 9U))),3);
    bufp->chgCData(oldp+797,((7U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                    >> 6U))),3);
    bufp->chgCData(oldp+798,((3U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                    >> 4U))),2);
    bufp->chgCData(oldp+799,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->chgIData(oldp+800,(((vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
                                         >> 0x0000001cU))),32);
    bufp->chgCData(oldp+801,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
                                             >> 0x00000018U))),4);
    bufp->chgIData(oldp+802,(((vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                         >> 0x00000018U))),32);
    bufp->chgCData(oldp+803,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                             >> 0x00000013U))),5);
    bufp->chgCData(oldp+804,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                             >> 0x0000000fU))),4);
    bufp->chgCData(oldp+805,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                             >> 8U))),7);
    bufp->chgCData(oldp+806,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                             >> 1U))),7);
    bufp->chgBit(oldp+807,((1U & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U])));
    bufp->chgSData(oldp+808,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[0]),16);
    bufp->chgSData(oldp+809,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[1]),16);
    bufp->chgSData(oldp+810,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[2]),16);
    bufp->chgSData(oldp+811,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[3]),16);
    bufp->chgSData(oldp+812,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[4]),16);
    bufp->chgSData(oldp+813,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[5]),16);
    bufp->chgSData(oldp+814,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[6]),16);
    bufp->chgSData(oldp+815,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[7]),16);
    bufp->chgSData(oldp+816,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[8]),16);
    bufp->chgSData(oldp+817,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[9]),16);
    bufp->chgSData(oldp+818,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[10]),16);
    bufp->chgSData(oldp+819,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[11]),16);
    bufp->chgSData(oldp+820,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[12]),16);
    bufp->chgSData(oldp+821,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[13]),16);
    bufp->chgSData(oldp+822,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[14]),16);
    bufp->chgSData(oldp+823,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[15]),16);
    bufp->chgCData(oldp+824,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[0]),4);
    bufp->chgCData(oldp+825,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[1]),4);
    bufp->chgCData(oldp+826,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[2]),4);
    bufp->chgCData(oldp+827,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[3]),4);
    bufp->chgCData(oldp+828,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[4]),4);
    bufp->chgCData(oldp+829,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[5]),4);
    bufp->chgCData(oldp+830,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[6]),4);
    bufp->chgCData(oldp+831,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[7]),4);
    bufp->chgCData(oldp+832,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[8]),4);
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
